/*
 * display.h
 *
 *  Created on: Apr 26, 2018
 */

#ifndef MAIN_INCLUDE_DISPLAY_H_
#define MAIN_INCLUDE_DISPLAY_H_

#include <stdlib.h>
#include <stdio.h>
#include "driver/gpio.h"
#include "gpio.h"
#include "ucg.h"
#include "ucg_esp32_hal.h"
#include "convert_utf8_to_windows1251.h"

void display_init();
void display_test();

#endif /* MAIN_INCLUDE_DISPLAY_H_ */
