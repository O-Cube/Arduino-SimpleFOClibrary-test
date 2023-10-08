/*
 * @author Obed Oyandut
 * BLDCMotorTest.h
 * Extends BLDCMotor class so that virtual functions can be stubbed/mocked
 */
#ifndef TEST_BLDCMOTOR_H
#define TEST_BLDCMOTOR_H

#include "BLDCMotor.h"

/*
 * BLDCMotor test class
 */
class BLDCMotorTest : public BLDCMotor
{
  public:
	BLDCMotorTest(int pp, float R = NOT_SET, float KV = NOT_SET, float L = NOT_SET); 
  void linkDriver(BLDCDriver *driver) override;
};
#endif
