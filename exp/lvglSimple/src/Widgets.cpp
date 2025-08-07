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
}



void Widgets::initTile1() {

	/*Tile1: */
	xTile1 = lv_tileview_add_tile(xTV, 0, 0,  LV_DIR_ALL);


	lv_style_init(&xStyleTile);
	lv_style_set_bg_color(&xStyleTile, lv_color_hex(0x000000));
	lv_style_set_bg_opa(&xStyleTile, LV_OPA_COVER);
	lv_obj_add_style(xTile1, &xStyleTile, 0);

	LV_IMG_DECLARE(battery100);

	xIconBat1 = lv_img_create(xTile1);
	lv_img_set_src(xIconBat1, &battery100);
	lv_obj_align(xIconBat1, LV_ALIGN_TOP_LEFT, 80, 0);

}

