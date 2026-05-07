#include <gtest/gtest.h>
#include "Controllers/Body/Servo/AngleCalculator/LinearAngleCalculator.h"


TEST(LinearAngleCalculatorTest, BasicAssertions) {
    LinearAngleCalculator calculator;
    unsigned int currentAngle = 0;
    unsigned long currentTime = 0;

    // Test rotating to 90 degrees
    calculator.rotateTo(currentTime, 90);
    currentTime += 1000; // Simulate 1 second elapsed
    currentAngle = calculator.calculateNextAngle(currentAngle, currentTime);
    EXPECT_EQ(currentAngle, 90);
    EXPECT_TRUE(calculator.isDone(currentAngle, currentTime));

    // Test rotating to 180 degrees
    calculator.rotateTo(currentTime, 180);
    currentTime += 1000; // Simulate another second elapsed
    currentAngle = calculator.calculateNextAngle(currentAngle, currentTime);
    EXPECT_EQ(currentAngle, 180);
    EXPECT_TRUE(calculator.isDone(currentAngle, currentTime));

    // Test rotating back to 0 degrees
    calculator.rotateTo(currentTime, 0);
    currentTime += 2000; // Simulate two seconds elapsed
    currentAngle = calculator.calculateNextAngle(currentAngle, currentTime);
    EXPECT_EQ(currentAngle, 0);
    EXPECT_TRUE(calculator.isDone(currentAngle, currentTime));
}


