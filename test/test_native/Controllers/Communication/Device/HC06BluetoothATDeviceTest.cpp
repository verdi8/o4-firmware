#include <gtest/gtest.h>

#include <string>

#include "Controllers/Communication/Device/HC06BluetoothATDevice.h"
#include "Hardware/HAL/Native/MockHAL.h"

class HC06BluetoothATDeviceFixture : public ::testing::Test {

public:
	static constexpr PinNumber RX_PIN = 55;
	static constexpr PinNumber TX_PIN = 56;
	
protected:

	HC06BluetoothATDeviceFixture()
		: halMock(new MockHAL()),
          hc06BluetoothATDevice(new HC06BluetoothATDevice(halMock, RX_PIN, TX_PIN)),
          systemMock(halMock->getMockHALSystem()),
          softwareSerialMock(halMock->getMockHALSoftwareSerial(RX_PIN, TX_PIN))
	{
	}

	void SetUp() override
	{
		ASSERT_NE(systemMock, nullptr);
		ASSERT_NE(softwareSerialMock, nullptr);
		softwareSerialMock->reset();
		systemMock->setMillis(0);
		systemMock->setCurrentMillisIncrement(10); // Increment millis by 10 ms on each call to simulate time passing
	}

	MockHAL* halMock;
	HC06BluetoothATDevice* hc06BluetoothATDevice;
	MockHALSystem* systemMock;
	MockHALSoftwareSerial* softwareSerialMock;
};

TEST_F(HC06BluetoothATDeviceFixture, SoftwareSerialIsInitializedWithCorrectPinsAndBaudRate)
{
	EXPECT_EQ(softwareSerialMock, hc06BluetoothATDevice->getSoftwareSerial());
	EXPECT_EQ(RX_PIN, softwareSerialMock->getRxPin());
	EXPECT_EQ(TX_PIN, softwareSerialMock->getTxPin());
	EXPECT_EQ(9600UL, softwareSerialMock->getBaudRate());
}


TEST_F(HC06BluetoothATDeviceFixture, SetNameSendsCorrectCommandAndReceivesExpectedResponse)
{
    softwareSerialMock->pushInputData("OK");
    EXPECT_TRUE(hc06BluetoothATDevice->setName("DEVICE-NAME"));
    EXPECT_EQ("AT+NAMEDEVICE-NAME", softwareSerialMock->getOutputData());
}

TEST_F(HC06BluetoothATDeviceFixture, SetBaudrateSendsCorrectCommandAndReceivesExpectedResponse)
{
	softwareSerialMock->pushInputData("OK9600");
	EXPECT_TRUE(hc06BluetoothATDevice->setBaudrate(9600));
	EXPECT_EQ("AT+BAUD4", softwareSerialMock->getOutputData());
}

TEST_F(HC06BluetoothATDeviceFixture, SetPinCodeSendsCorrectCommandAndReceivesExpectedResponse)
{
	softwareSerialMock->pushInputData("OKsetPIN");
	EXPECT_TRUE(hc06BluetoothATDevice->setPinCode("1234"));
	EXPECT_EQ("AT+PIN1234", softwareSerialMock->getOutputData());
}

// --- Tests for bad responses from the module ---

TEST_F(HC06BluetoothATDeviceFixture, SetNameReturnsFalseIfNoExpectedResponse)
{
	softwareSerialMock->pushInputData("ERROR");
	EXPECT_FALSE(hc06BluetoothATDevice->setName("DEVICE-NAME"));
}

TEST_F(HC06BluetoothATDeviceFixture, SetBaudrateReturnsFalseIfNoExpectedResponse)
{
	softwareSerialMock->pushInputData("ERROR");
	EXPECT_FALSE(hc06BluetoothATDevice->setBaudrate(9600));
}

TEST_F(HC06BluetoothATDeviceFixture, SetPinCodeReturnsFalseIfNoExpectedResponse)
{
	softwareSerialMock->pushInputData("ERROR");
	EXPECT_FALSE(hc06BluetoothATDevice->setPinCode("1234"));
}

// --- Tests for invalid input parameters ---

TEST_F(HC06BluetoothATDeviceFixture, SetBaudrateReturnsFalseIfInvalidBaudRate)
{
	EXPECT_FALSE(hc06BluetoothATDevice->setBaudrate(12345)); // Invalid baud rate
}

// --- Tests for no response received within timeout ---


TEST_F(HC06BluetoothATDeviceFixture, SetNameReturnsFalseIfResponseNotReceivedWithinTimeout)
{
	EXPECT_FALSE(hc06BluetoothATDevice->setName("DEVICE-NAME"));
}

TEST_F(HC06BluetoothATDeviceFixture, SetBaudrateReturnsFalseIfResponseNotReceivedWithinTimeout)
{
	EXPECT_FALSE(hc06BluetoothATDevice->setBaudrate(9600));
}

TEST_F(HC06BluetoothATDeviceFixture, SetPinCodeReturnsFalseIfResponseNotReceivedWithinTimeout)
{
	EXPECT_FALSE(hc06BluetoothATDevice->setPinCode("1234"));
}

