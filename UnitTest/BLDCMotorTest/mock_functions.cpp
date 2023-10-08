/*
 * stubs and mocks of functions in BLDCMotor class
 */
#include "FOCMotor.h"
#include "SimpleFOCDebug.h"
#include "pid.h"
#include "CurrentSense.h"
#include "time_utils.h"

/* functions in FOCMotor.h */
FOCMotor::FOCMotor() {

}

float FOCMotor::electricalAngle() {
	return 1.1;
}

float FOCMotor::shaftAngle() {
	return 1.1;
}

float FOCMotor::shaftVelocity() {
	return 1.1;
}

/* functions in SimpleFOCDebug.h */
static void SimpleFOCDebug::println(const __FlashStringHelper* msg) {
	return;
}

static void SimpleFOCDebug::println(const __FlashStringHelper* msg, int val) {
	return;
}

static void SimpleFOCDebug::println(const __FlashStringHelper* msg, float val) {
	return;
}

/* functions in lowpass_filter */
LowPassFilter::LowPassFilter(float time_constant) {

}

float LowPassFilter::operator() (float x) {
	return x;
}

/* functions in pid.h */
PIDController::PIDController(float P, float I, float D, float ramp, float limit) {

}

float PIDController::operator() (float error) {
	return 1.1;
}

/* functions in CurrentSense.h */
DQCurrent_s CurrentSense::getFOCCurrents(float angle_el) {
	DQCurrent_s return_current = {0.1, 0.2};
	return return_current;
}

/* functions in time-utils.h */
unsigned long _micros() {
	return 1.1;
}

/* miscellaneous functions */
void _delay(unsigned long ms) {
	return;
}

__attribute__((weak)) float _normalizeAngle(float angle) {
	return 1.1;
}

__attribute__((weak)) void _sincos(float a, float* s, float* c) {
	return;
}

__attribute__((weak)) float _sqrtApprox(float number) {
	return 1.1;
}

__attribute__((weak)) float _sin(float a) {
	return 1.1;
}

float _electricalAngle(float shaft_angle, int pole_pairs) {
	return shaft_angle * pole_pairs;
}
