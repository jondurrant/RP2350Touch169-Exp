/***
 * LGL Dashboard Experiments
 *
 * Jon Durrant - 4-Aug-2025
 */


#include "pico/stdlib.h"
#include "stdio.h"

#include "LCD.h"
#include "lvgl_board.h"
#include "Widgets.h"

#include <stdio.h>


int main(void)
{

	stdio_init_all();
	sleep_ms(2000);
	printf("GO\n");

	Board_init();

	Widgets widgets;

	widgets.init();


    for (;;){
    	lv_task_handler();
    }

    return 0;
}


