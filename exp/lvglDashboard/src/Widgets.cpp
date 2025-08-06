/*
 * Widgets.cpp
 *
 *  Created on: 4 Aug 2025
 *      Author: jondurrant
 */

#include "Widgets.h"
#include <cstdio>

//extern lv_img_dsc_t cpuOn ;



Widgets::Widgets() {
	// TODO Auto-generated constructor stub

}

Widgets::~Widgets() {
	// TODO Auto-generated destructor stub
}



void Widgets::init() {

	 /*Create tileview*/
	xTV = lv_tileview_create(lv_scr_act());
	lv_obj_set_scrollbar_mode(xTV,  LV_SCROLLBAR_MODE_OFF);

	initTile1();

	initTile2();

	initTile3();

}


void Widgets::initTile3() {
	xTile3 = lv_tileview_add_tile(xTV, 2, 0, LV_DIR_ALL);
	lv_obj_add_style(xTile3, &xStyleTile, 0);

	LV_IMG_DECLARE(halt);


	//Halt Btn
	xHaltBtn = lv_imgbtn_create(xTile3);
	lv_imgbtn_set_src(
			xHaltBtn,
			LV_IMGBTN_STATE_RELEASED,
			NULL,
			&halt,
			NULL);
	lv_obj_set_width(xHaltBtn, 250);
	lv_obj_set_height(xHaltBtn, 250);
	lv_obj_align(xHaltBtn, LV_ALIGN_TOP_LEFT, 60, 0);
	lv_obj_add_event_cb(xHaltBtn, clickEventCB, LV_EVENT_CLICKED, this);


	xHaltSw = lv_switch_create(xTile3);
	//lv_obj_add_state(xHaltSw, LV_STATE_CHECKED);
	lv_obj_align(xHaltSw, LV_ALIGN_TOP_LEFT, 0, 50);
}

void Widgets::initTile2() {
	/*Tile2: */
	xTile2 = lv_tileview_add_tile(xTV, 1, 0, LV_DIR_ALL);
	lv_obj_add_style(xTile2, &xStyleTile, 0);

	LV_IMG_DECLARE(cpuOn);
	LV_IMG_DECLARE(cpuOff);
	LV_IMG_DECLARE(driveOn);
	LV_IMG_DECLARE(driveOff);
	LV_IMG_DECLARE(chargeOn);
	LV_IMG_DECLARE(chargeOff);
	LV_IMG_DECLARE(play);

	// Button CPU
	xBat1CpuBtn = lv_imgbtn_create(xTile2);
	lv_imgbtn_set_src(
		xBat1CpuBtn,
		LV_IMGBTN_STATE_RELEASED,
		NULL,
		&cpuOff,
		NULL);
	lv_imgbtn_set_src(
		xBat1CpuBtn,
		LV_IMGBTN_STATE_CHECKED_RELEASED,
		NULL,
		&cpuOn,
		NULL);
	lv_obj_set_width(xBat1CpuBtn, 80);
	lv_obj_set_height(xBat1CpuBtn, 80);
	lv_obj_align(xBat1CpuBtn, LV_ALIGN_TOP_LEFT, 0, 0);
	lv_obj_add_event_cb(xBat1CpuBtn, clickEventCB, LV_EVENT_CLICKED, this);
	lv_obj_add_flag(xBat1CpuBtn, LV_OBJ_FLAG_CHECKABLE);

	xBat2CpuBtn = lv_imgbtn_create(xTile2);
	lv_imgbtn_set_src(
			xBat2CpuBtn,
			LV_IMGBTN_STATE_RELEASED,
			NULL,
			&cpuOff,
			NULL);
	lv_imgbtn_set_src(
			xBat2CpuBtn,
			LV_IMGBTN_STATE_CHECKED_RELEASED,
			NULL,
			&cpuOn,
			NULL);
	lv_obj_set_width(xBat2CpuBtn, 80);
	lv_obj_set_height(xBat2CpuBtn, 80);
	lv_obj_align(xBat2CpuBtn, LV_ALIGN_TOP_LEFT, 200, 0);
	lv_obj_add_event_cb(xBat2CpuBtn, clickEventCB, LV_EVENT_CLICKED, this);
	lv_obj_add_flag(xBat2CpuBtn, LV_OBJ_FLAG_CHECKABLE);

	// Button Drive
	xBat1DrvBtn = lv_imgbtn_create(xTile2);
	lv_imgbtn_set_src(
			xBat1DrvBtn,
			LV_IMGBTN_STATE_RELEASED,
			NULL,
			&driveOff,
			NULL);
	lv_imgbtn_set_src(
			xBat1DrvBtn,
			LV_IMGBTN_STATE_CHECKED_RELEASED,
			NULL,
			&driveOn,
			NULL);
	lv_obj_set_width(xBat1DrvBtn, 80);
	lv_obj_set_height(xBat1DrvBtn, 80);
	lv_obj_align(xBat1DrvBtn, LV_ALIGN_TOP_LEFT, 0, 80);
	lv_obj_add_event_cb(xBat1DrvBtn, clickEventCB, LV_EVENT_CLICKED, this);
	lv_obj_add_flag(xBat1DrvBtn, LV_OBJ_FLAG_CHECKABLE);

	xBat2DrvBtn = lv_imgbtn_create(xTile2);
	lv_imgbtn_set_src(
			xBat2DrvBtn,
			LV_IMGBTN_STATE_RELEASED,
			NULL,
			&driveOff,
			NULL);
	lv_imgbtn_set_src(
			xBat2DrvBtn,
			LV_IMGBTN_STATE_CHECKED_RELEASED,
			NULL,
			&driveOn,
			NULL);
	lv_obj_set_width(xBat2DrvBtn, 80);
	lv_obj_set_height(xBat2DrvBtn, 80);
	lv_obj_align(xBat2DrvBtn, LV_ALIGN_TOP_LEFT, 200, 80);
	lv_obj_add_event_cb(xBat2DrvBtn, clickEventCB, LV_EVENT_CLICKED, this);
	lv_obj_add_flag(xBat2DrvBtn, LV_OBJ_FLAG_CHECKABLE);


	// Button Charge
	xBat1ChargeBtn = lv_imgbtn_create(xTile2);
	lv_imgbtn_set_src(
			xBat1ChargeBtn,
			LV_IMGBTN_STATE_RELEASED,
			NULL,
			&chargeOff,
			NULL);
	lv_imgbtn_set_src(
			xBat1ChargeBtn,
			LV_IMGBTN_STATE_CHECKED_RELEASED,
			NULL,
			&chargeOn,
			NULL);
	lv_obj_set_width(xBat1ChargeBtn, 80);
	lv_obj_set_height(xBat1ChargeBtn, 80);
	lv_obj_align(xBat1ChargeBtn, LV_ALIGN_TOP_LEFT, 0, 160);
	lv_obj_add_event_cb(xBat1ChargeBtn, clickEventCB, LV_EVENT_CLICKED, this);
	lv_obj_add_flag(xBat1ChargeBtn, LV_OBJ_FLAG_CHECKABLE);

	xBat2ChargeBtn = lv_imgbtn_create(xTile2);
	lv_imgbtn_set_src(
			xBat2ChargeBtn,
			LV_IMGBTN_STATE_RELEASED,
			NULL,
			&chargeOff,
			NULL);
	lv_imgbtn_set_src(
			xBat2ChargeBtn,
			LV_IMGBTN_STATE_CHECKED_RELEASED,
			NULL,
			&chargeOn,
			NULL);
	lv_obj_set_width(xBat2ChargeBtn, 80);
	lv_obj_set_height(xBat2ChargeBtn, 80);
	lv_obj_align(xBat2ChargeBtn, LV_ALIGN_TOP_LEFT, 200, 160);
	lv_obj_add_event_cb(xBat2ChargeBtn, clickEventCB, LV_EVENT_CLICKED, this);
	lv_obj_add_flag(xBat2ChargeBtn, LV_OBJ_FLAG_CHECKABLE);

			//lv_obj_add_flag(xBat2ChargeBtn, LV_OBJ_FLAG_HIDDEN);


	//Play Btn
	xPlayBtn = lv_imgbtn_create(xTile2);
	lv_imgbtn_set_src(
			xPlayBtn,
			LV_IMGBTN_STATE_RELEASED,
			NULL,
			&play,
			NULL);
	lv_obj_set_width(xPlayBtn, 120);
	lv_obj_set_height(xPlayBtn, 120);
	lv_obj_align(xPlayBtn, LV_ALIGN_TOP_LEFT, 80, 50);
	lv_obj_add_event_cb(xPlayBtn, clickEventCB, LV_EVENT_CLICKED, this);

}


void Widgets::initTile1() {

	/*Tile1: */
	xTile1 = lv_tileview_add_tile(xTV, 0, 0,  LV_DIR_ALL);


	lv_style_init(&xStyleTile);
	lv_style_set_bg_color(&xStyleTile, lv_color_hex(0x000000));
	lv_style_set_bg_opa(&xStyleTile, LV_OPA_COVER);
	lv_obj_add_style(xTile1, &xStyleTile, 0);




	LV_IMG_DECLARE(cpuOff);
	LV_IMG_DECLARE(cpuOn);

	xIconBat1Cpu = lv_img_create(xTile1);
	lv_img_set_src(xIconBat1Cpu, &cpuOff);
	lv_obj_align(xIconBat1Cpu, LV_ALIGN_TOP_LEFT, 0, 0);
	xIconBat2Cpu = lv_img_create(xTile1);
	lv_img_set_src(xIconBat2Cpu, &cpuOn);
	lv_obj_align(xIconBat2Cpu, LV_ALIGN_TOP_LEFT, 200,0);

	LV_IMG_DECLARE(driveOn);
	LV_IMG_DECLARE(driveOff);

	xIconBat1Drv = lv_img_create(xTile1);
	lv_img_set_src(xIconBat1Drv, &driveOn);
	lv_obj_align(xIconBat1Drv, LV_ALIGN_TOP_LEFT, 0, 80);

	xIconBat2Drv = lv_img_create(xTile1);
	lv_img_set_src(xIconBat2Drv, &driveOff);
	lv_obj_align(xIconBat2Drv, LV_ALIGN_TOP_LEFT, 200,80);

	LV_IMG_DECLARE(battery0);
	LV_IMG_DECLARE(battery25);
	LV_IMG_DECLARE(battery50);
	LV_IMG_DECLARE(battery75);
	LV_IMG_DECLARE(battery100);
	LV_IMG_DECLARE(batteryC);


	xIconBat1 = lv_img_create(xTile1);
	lv_img_set_src(xIconBat1, &battery25);
	lv_obj_align(xIconBat1, LV_ALIGN_TOP_LEFT, 80, 0);

	xIconBat2 = lv_img_create(xTile1);
	lv_img_set_src(xIconBat2, &battery75);
	lv_obj_align(xIconBat2, LV_ALIGN_TOP_LEFT, 140, 0);


	//Label
	lv_style_init(&xStyleTxt);
	lv_style_set_text_font(&xStyleTxt, &lv_font_montserrat_28);
	lv_style_set_text_color(
			&xStyleTxt,
			lv_color_make(0xFF, 0xFF, 0xFF));


	xLblBat1Per = lv_label_create(xTile1);
	lv_label_set_long_mode(xLblBat1Per, LV_LABEL_LONG_WRAP);
	lv_label_set_text(xLblBat1Per, "60%");
	lv_obj_set_width(xLblBat1Per, 140);
	lv_obj_set_style_text_align(xLblBat1Per, LV_TEXT_ALIGN_LEFT, 0);
	lv_obj_align(xLblBat1Per, LV_ALIGN_TOP_LEFT, 5, 160);
	lv_obj_add_style(xLblBat1Per , &xStyleTxt,  LV_PART_MAIN);

	xLblBat2Per = lv_label_create(xTile1);
	lv_label_set_long_mode(xLblBat2Per, LV_LABEL_LONG_WRAP);
	lv_label_set_text(xLblBat2Per, "62%");
	lv_obj_set_width(xLblBat2Per, 140);
	lv_obj_set_style_text_align(xLblBat2Per, LV_TEXT_ALIGN_LEFT, 0);
	lv_obj_align(xLblBat2Per, LV_ALIGN_TOP_LEFT, 145, 160);
	lv_obj_add_style(xLblBat2Per , &xStyleTxt,  LV_PART_MAIN);

	xLblBat1Volt = lv_label_create(xTile1);
	lv_label_set_long_mode(xLblBat1Volt, LV_LABEL_LONG_WRAP);
	lv_label_set_text(xLblBat1Volt, "12.50V");
	lv_obj_set_width(xLblBat1Volt, 140);
	lv_obj_set_style_text_align(xLblBat1Volt, LV_TEXT_ALIGN_LEFT, 0);
	lv_obj_align(xLblBat1Volt, LV_ALIGN_TOP_LEFT, 5, 200);
	lv_obj_add_style(xLblBat1Volt , &xStyleTxt,  LV_PART_MAIN);

	xLblBat2Volt = lv_label_create(xTile1);
	lv_label_set_long_mode(xLblBat2Volt, LV_LABEL_LONG_WRAP);
	lv_label_set_text(xLblBat2Volt, "10.01V");
	lv_obj_set_width(xLblBat2Volt, 140);
	lv_obj_set_style_text_align(xLblBat2Volt, LV_TEXT_ALIGN_LEFT, 0);
	lv_obj_align(xLblBat2Volt, LV_ALIGN_TOP_LEFT, 145, 200);
	lv_obj_add_style(xLblBat2Volt , &xStyleTxt,  LV_PART_MAIN);

}


void Widgets::clickEventHandler(lv_event_t * e){

	if (e->target == xHaltBtn){
		printf("Halt pressed\n");
		lv_state_t st =  lv_obj_get_state(xHaltSw);
		if (st == LV_STATE_CHECKED){
			lv_obj_clear_state(xHaltSw, LV_STATE_CHECKED);
			printf("HALTING NOW\n");
		}
	}

	if (e->target == xPlayBtn){
		PowerState req;
		req.startTransaction();
		req.setBat1CPU(lv_obj_has_state(xBat1CpuBtn, LV_IMGBTN_STATE_CHECKED_RELEASED));
		req.setBat2CPU(lv_obj_has_state(xBat2CpuBtn, LV_IMGBTN_STATE_CHECKED_RELEASED));
		req.setBat1Drive(lv_obj_has_state(xBat1DrvBtn, LV_IMGBTN_STATE_CHECKED_RELEASED));
		req.setBat2Drive(lv_obj_has_state(xBat2DrvBtn, LV_IMGBTN_STATE_CHECKED_RELEASED));
		req.setBat1Charge(lv_obj_has_state(xBat1ChargeBtn, LV_IMGBTN_STATE_CHECKED_RELEASED));
		req.setBat2Charge(lv_obj_has_state(xBat2ChargeBtn, LV_IMGBTN_STATE_CHECKED_RELEASED));
		req.delta(xBuffer,  WIDGET_BUFFER_LEN) ;
		printf("%s\n", xBuffer);
	}


}

void Widgets::clickEventCB(lv_event_t * e){

	printf("Clicked\n");

	Widgets * obj = (Widgets *) e->user_data;

	obj->clickEventHandler(e);



	/*
	lv_obj_t * img = lv_event_get_target(e);
	LV_IMG_DECLARE(cpuOn);
	lv_img_set_src(img, &cpuOn);
	*/
}



void Widgets::setState(PowerState * state){
	pState = state;
	if (pState != NULL){
		pState->attach(this);
		notifyState(0xFFFF);
	}
}

void Widgets::notifyState(uint16_t dirtyCode){
	printf("Notify called \n");

	char txt[10];

	LV_IMG_DECLARE(cpuOff);
	LV_IMG_DECLARE(cpuOn);
	LV_IMG_DECLARE(driveOn);
	LV_IMG_DECLARE(driveOff);
	LV_IMG_DECLARE(batteryC);

	if (pState->getBat1CPU()){
		lv_imgbtn_set_state(xBat1CpuBtn, LV_IMGBTN_STATE_CHECKED_RELEASED);
		lv_img_set_src(xIconBat1Cpu, &cpuOn);
	} else {
		lv_imgbtn_set_state(xBat1CpuBtn, LV_IMGBTN_STATE_RELEASED);
		lv_img_set_src(xIconBat1Cpu, &cpuOff);
	}

	if (pState->getBat2CPU()){
		lv_img_set_src(xIconBat2Cpu, &cpuOn);
		lv_imgbtn_set_state(xBat2CpuBtn, LV_IMGBTN_STATE_CHECKED_RELEASED);
	} else {
		lv_img_set_src(xIconBat2Cpu, &cpuOff);
		lv_imgbtn_set_state(xBat2CpuBtn, LV_IMGBTN_STATE_RELEASED);
	}

	if (pState->getBat1Drive()){
		lv_imgbtn_set_state(xBat1DrvBtn, LV_IMGBTN_STATE_CHECKED_RELEASED);
		lv_img_set_src(xIconBat1Drv, &driveOn);
	} else {
		lv_imgbtn_set_state(xBat1DrvBtn, LV_IMGBTN_STATE_RELEASED);
		lv_img_set_src(xIconBat1Drv, &driveOff);
	}

	if (pState->getBat2Drive()){
		lv_imgbtn_set_state(xBat2DrvBtn, LV_IMGBTN_STATE_CHECKED_RELEASED);
		lv_img_set_src(xIconBat2Drv, &driveOn);
	} else {
		lv_imgbtn_set_state(xBat2DrvBtn, LV_IMGBTN_STATE_RELEASED);
		lv_img_set_src(xIconBat2Drv, &driveOff);
	}

	if (pState->getBat1Charge()){
		lv_imgbtn_set_state(xBat1ChargeBtn, LV_IMGBTN_STATE_CHECKED_RELEASED);
		lv_img_set_src(xIconBat1, &batteryC);
		float f =  pState->getChgVolt();
		sprintf(txt, "%.2fv", f);
		lv_label_set_text(xLblBat1Volt, txt);
		uint t = pState->getChgRemain();
		sprintf(txt, "%uMin", t);
		lv_label_set_text(xLblBat1Per, txt);
	} else {
		lv_imgbtn_set_state(xBat1ChargeBtn, LV_IMGBTN_STATE_RELEASED);
		float f = pState->getBat1Per();
		sprintf(txt, "%.2f%%", f);
		lv_label_set_text(xLblBat1Per, txt);
		lv_img_set_src(xIconBat1, batLvl(f));

		f =  pState->getBat1Volt();
		sprintf(txt, "%.2fv", f);
		lv_label_set_text(xLblBat1Volt, txt);
	}

	if (pState->getBat2Charge()){
		lv_imgbtn_set_state(xBat2ChargeBtn, LV_IMGBTN_STATE_CHECKED_RELEASED);
		lv_img_set_src(xIconBat2, &batteryC);
		float f =  pState->getChgVolt();
		sprintf(txt, "%.2fv", f);
		lv_label_set_text(xLblBat2Volt, txt);
		uint t = pState->getChgRemain();
		sprintf(txt, "%uMin", t);
		lv_label_set_text(xLblBat2Per, txt);
	} else {
		lv_imgbtn_set_state(xBat2ChargeBtn, LV_IMGBTN_STATE_RELEASED);
		float f = pState->getBat2Per();
		sprintf(txt, "%.2f%%", f);
			lv_label_set_text(xLblBat2Per, txt);
		lv_img_set_src(xIconBat2, batLvl(f));

		f =  pState->getBat2Volt();
		sprintf(txt, "%.2fv", f);
		lv_label_set_text(xLblBat2Volt, txt);
	}

	if (pState->getChargeAvl()){
		lv_obj_clear_flag(xBat1ChargeBtn, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(xBat2ChargeBtn, LV_OBJ_FLAG_HIDDEN);
	} else {
		lv_obj_add_flag(xBat1ChargeBtn, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(xBat2ChargeBtn, LV_OBJ_FLAG_HIDDEN);
	}


}

void * Widgets::batLvl(float f){
	LV_IMG_DECLARE(battery0);
	LV_IMG_DECLARE(battery25);
	LV_IMG_DECLARE(battery50);
	LV_IMG_DECLARE(battery75);
	LV_IMG_DECLARE(battery100);

	if (f < 5.0){
		return (void *)&battery0;
	}
	if ( f < 26.0){
		return (void *)&battery25;
	}
	if (f < 51.0){
		return (void *)&battery50;
	}
	if (f < 76.0){
		return (void *)& battery75;
	}
	return (void *)&battery100;
}

