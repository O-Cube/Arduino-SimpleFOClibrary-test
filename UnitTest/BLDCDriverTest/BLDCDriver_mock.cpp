/*
 * @author Obed O.
 *
 * implementation of BLDCDriver_mock.h
 */
#include "BLDCDriver_mock.h"
/* initialize hardware */
int BLDCDriver_test::init()
{
  return (int)(bldcDriver_mock->init_mock());
}

