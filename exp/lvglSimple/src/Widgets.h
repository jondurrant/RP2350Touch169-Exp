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

class Widgets {
public:
	Widgets();
	virtual ~Widgets();

	void init();


private:

	void initTile1();

	lv_obj_t *xTV;
	lv_obj_t *xTile1;
	lv_style_t xStyleTile;


	lv_obj_t *xIconBat1;

};

#endif /* EXP_LVGLDASHBOARD_SRC_WIDGETS_H_ */
