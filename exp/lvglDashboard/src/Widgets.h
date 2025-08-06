/*
 * Widgets.h
 *
 *  Created on: 4 Aug 2025
 *      Author: jondurrant
 */

#ifndef EXP_LVGLDASHBOARD_SRC_WIDGETS_H_
#define EXP_LVGLDASHBOARD_SRC_WIDGETS_H_

#include "lvgl.h"
#include "src/core/lv_obj.h"
#include "src/misc/lv_area.h"
#include "PowerState.h"
#include "StateObserver.h"

#ifndef WIDGET_BUFFER_LEN
#define WIDGET_BUFFER_LEN 1024
#endif

class Widgets : public StateObserver{
public:
	Widgets();
	virtual ~Widgets();


	void init();
	void setState(PowerState * state);

	static void clickEventCB(lv_event_t * event);
	void clickEventHandler(lv_event_t * event);


	/***
	 * Notification of a change of a state item with the State object.
	 * @param dirtyCode - Representation of item changed within state. Used to pull back delta
	 */
	virtual void notifyState(uint16_t dirtyCode);

private:
	void * batLvl(float f);

	PowerState * pState = NULL;

	void initTile1();
	void initTile2();
	void initTile3();

	lv_obj_t *xTV;
	lv_obj_t *xTile1;
	lv_obj_t *xTile2;
	lv_obj_t *xTile3;
	lv_style_t xStyleTile;
	lv_style_t xStyleTxt;

	lv_obj_t * xBat1CpuBtn;
	lv_obj_t * xBat2CpuBtn;
	lv_obj_t * xBat1DrvBtn;
	lv_obj_t * xBat2DrvBtn;
	lv_obj_t * xBat1ChargeBtn;
	lv_obj_t * xBat2ChargeBtn;
	lv_obj_t * xPlayBtn;
	lv_obj_t * xHaltBtn;
	lv_obj_t * xHaltSw;

	lv_obj_t *xIconBat1Cpu;
	lv_obj_t *xIconBat2Cpu;
	lv_obj_t *xIconBat1Drv;
	lv_obj_t *xIconBat2Drv;
	lv_obj_t *xIconBat1;
	lv_obj_t *xIconBat2;

	lv_obj_t * xLblBat1Per;
	lv_obj_t * xLblBat2Per;
	lv_obj_t * xLblBat1Volt;
	lv_obj_t * xLblBat2Volt;


	char xBuffer[WIDGET_BUFFER_LEN];


};

#endif /* EXP_LVGLDASHBOARD_SRC_WIDGETS_H_ */
