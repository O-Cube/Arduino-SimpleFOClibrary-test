/*
 * Test the functionality of the BLDCMotor class
 * Obed Oyandut
 */

#include "gtest/gtest.h"
#include "BLDCMotor.h"
#include "test_BLDCMotor.h"

/*  Implementation of BLDCMotorTest class constructor */
BLDCMotorTest::BLDCMotorTest(int pp, float R, float kv, float L) : BLDCMotor(pp,R,kv,L) {}
/* Implementation linkDriver() */
void BLDCMotorTest::linkDriver(BLDCDriver *driver){}

/* define a test fixture */
class BLDCMotorTestFixture : public testing::Test {
protected:
	void SetUp() override {
	     motor = new BLDCMotorTest(10, 2.5, 3.3, 7.5);
        }
	void TearDown() override {}
BLDCMotorTest *motor;
};

/* Test constructor with four arguments */
TEST_F(BLDCMotorTestFixture, ConstructorWorks_1)
{  
  EXPECT_EQ(10, motor->pole_pairs);
  EXPECT_FLOAT_EQ(2.5, motor->phase_resistance);
  EXPECT_FLOAT_EQ((3.3*_SQRT2), motor->KV_rating);
  EXPECT_FLOAT_EQ(7.5, motor->phase_inductance);
}


/* Test constructor with single argument */
TEST(BLDCMotorTest, ConstructorWorks_2)
{ 
  BLDCMotorTest m1 = BLDCMotorTest(10); 
  EXPECT_EQ(10, m1.pole_pairs);
  EXPECT_FLOAT_EQ(NOT_SET, m1.phase_resistance);
  EXPECT_FLOAT_EQ(NOT_SET, m1.KV_rating);
  EXPECT_FLOAT_EQ(NOT_SET, m1.phase_inductance);
}

/* Test aligncurrentSense */
TEST_F(BLDCMotorTestFixture, MoveWorks)
{
  motor->move(10.0);
}
