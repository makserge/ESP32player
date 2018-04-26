/*
 * encoder.h
 *
 *  Created on: Apr 26, 2018
 */
#ifndef MAIN_INCLUDE_ENCODER_H_
#define MAIN_INCLUDE_ENCODER_H_

#include "ClickEncoder.h"
#include "driver/timer.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "gpio.h"

#define msTimer	TIMER_0
#define TIMERGROUP1MS TIMER_GROUP_1
#define TIMERGROUP1mS TIMER_GROUP_1

void noInterrupt1Ms();
void interrupt1Ms();
void task_encoder(void *pvParams);

#endif /* MAIN_INCLUDE_ENCODER_H_ */
