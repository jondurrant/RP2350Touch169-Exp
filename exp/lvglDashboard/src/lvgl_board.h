/*
 * lvgl_board.h
 *
 * LVGL Porting to the Waveshare RP2350 1.69inch Touch
 * Based on Waveshare code
 *
 *  Created on: 4 Aug 2025
 *      Author: jondurrant
 */

#ifndef EXP_LVGLDASHBOARD_SRC_LVGL_BOARD_H_
#define EXP_LVGLDASHBOARD_SRC_LVGL_BOARD_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/util/datetime.h"
#include "DEV_Config.h"
#include "LCD_1in69.h"
#include "CST816S.h"
#include "QMI8658.h"
#include "PCF85063A.h"
#include "lvgl.h"

#define DISP_HOR_RES 240
#define DISP_VER_RES 280

#define INPUTDEV_TS  1

int Board_init();
int LVGL_Init(uint8_t Scan_dir);


#ifdef __cplusplus
}
#endif

#endif /* EXP_LVGLDASHBOARD_SRC_LVGL_BOARD_H_ */
