/*
 * @author Obed O.
 *
 * Extends the BLDCDriver class and mock methods
 */
#ifndef BLDCDRIVERMOCK_H
#define BLDCDRIVERMOCK_H

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "BLDCDriver.h"
/*
 * BLDCDriver_test class 
 */
class BLDCDriver_test : public BLDCDriver
{
 public:
  /* initialize hardware */
  int init() override;
  /* enable hardware */
  void enable() override;
  /* disable hardware */
  void disable() override;

  /*
   * set phase voltages to the hardware
   *
   * @param Ua - phase A voltage
   * @param Ub - phase B voltage
   * @param Uc - phase C voltage
   */
   void setPwm(float Ua, float Ub, float Uc) override;


  /*
   * set phase state enable/disable
   *
   * @param sc - phase A state : active / disabled ( high impedance )
   * @param sb - phase B state : active / disabled ( high impedance )
   * @param sa - phase C state : active / disabled ( high impedance )
   */
   void setPhaseState(PhaseState sa, PhaseState sb, PhaseState sc) override;
}

/*
 * BLDCDriver_mock class
 */
class BLDCDriver_mock
{
  /* init() mock */
  MOCK_METHOD(int, init_mock, (), (override));
  /* enable() mock */
  MOCK_METHOD(void, enable_mock, (), (override));
  /* disable() mock */
  MOCK_METHOD(void, disable_mock, (), (override));
  /* setPwm() mock */
  MOCK_METHOD(void, setPwm_mock, (float Ua, float Ub, float Uc), (override));
  /* setPhaseState() mock */
  MOCK_METHOD(void, setPhaseState_mock, (PhaseState sa, PhaseState sb, PhaseState sc), (override));
}

/* mock pointer */
BLDCDriver_mock *bldcDriver_mock;

#endif /* BLDCDRIVER_H */

