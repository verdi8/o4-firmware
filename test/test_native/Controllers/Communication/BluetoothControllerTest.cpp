#include <gtest/gtest.h>

#include "Controllers/Communication/BluetoothController.h"
#include "Hardware/HAL/Native/MockHAL.h"

class BluetoothControllerFixture : public ::testing::Test {

public:
	static constexpr PinNumber RX_PIN = 55;
	static constexpr PinNumber TX_PIN = 56;
	static constexpr unsigned int BUFFER_SIZE = 16;
	static constexpr const char* NAME = "DEVICE-NAME";
	static constexpr const char* PIN_CODE = "1234";

protected:

	BluetoothControllerFixture()
		: halMock(new MockHAL()),
		  systemMock(halMock->getMockHALSystem()),
		  softwareSerialMock(nullptr)
	{
	}

	void SetUp() override
	{
		ASSERT_NE(systemMock, nullptr);
		softwareSerialMock = static_cast<MockHALSoftwareSerial*>(halMock->newSoftwareSerial(RX_PIN, TX_PIN));
		ASSERT_NE(softwareSerialMock, nullptr);
		softwareSerialMock->reset();
		systemMock->setMillis(0);
		systemMock->setCurrentMillisIncrement(10);
		buffer[0] = '\0';
	}

	BluetoothController* createInitializedController()
	{
		softwareSerialMock->pushInputData("OKOK9600OKsetPIN");
		return new BluetoothController(halMock, RX_PIN, TX_PIN, NAME, PIN_CODE, buffer, BUFFER_SIZE);
	}

	MockHAL* halMock;
	MockHALSystem* systemMock;
	MockHALSoftwareSerial* softwareSerialMock;
	char buffer[BUFFER_SIZE];
};

TEST_F(BluetoothControllerFixture, IsNotDoneAfterSuccessfulInitialization)
{
	BluetoothController* controller = createInitializedController();

	EXPECT_FALSE(controller->isDone());
	EXPECT_EQ("AT+NAMEDEVICE-NAMEAT+BAUD4AT+PIN1234", softwareSerialMock->getOutputData());

	delete controller;
}

TEST_F(BluetoothControllerFixture, UpdateReadsUntilCompleteLine)
{
	BluetoothController* controller = createInitializedController();
	softwareSerialMock->pushInputData("HELLOOO WO");

	controller->update();

	EXPECT_FALSE(controller->isDone());
	EXPECT_STREQ("HELLOOO WO", buffer);

	softwareSerialMock->pushInputData("R");
	controller->update();
	EXPECT_FALSE(controller->isDone());
	EXPECT_STREQ("HELLOOO WOR", buffer);

	softwareSerialMock->pushInputData("LD\n");
	controller->update();
	EXPECT_TRUE(controller->isDone());
	EXPECT_STREQ("HELLOOO WORLD", buffer);

	delete controller;
}
