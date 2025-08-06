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

#include "PowerState.h"
#include "tiny-json.h"






int main(void)
{
	char buf[1024];
	int ind=0;
	json_t jmem[32];


	stdio_init_all();
	sleep_ms(2000);
	printf("GO\n");

	PowerState power;

	Board_init();

	Widgets widgets;


	widgets.init();

	widgets.setState(&power);

	int count = 0;

    for (;;){
    	lv_task_handler();

    	int c = stdio_getchar_timeout_us (0);
    	if (c != PICO_ERROR_TIMEOUT){
    		if ((c == '\n') || (c== '\r')){
    			buf[ind] = 0;
    			if (ind > 0){
    				printf("%s\n", buf);
    				json_t const* json = json_create( buf, jmem, sizeof jmem / sizeof *jmem );
    				if (json != NULL ){
						power.startTransaction();
						power.updateFromJson(json);
						power.commitTransaction();
    				} else {
    					printf("JSON did not parse\n %s\n", buf);
    				}
    			}
    			ind = 0;
    		} else {
    			buf[ind++] = c;
    		}
    		if (ind > 1023){
    			ind = 0;
    		}
    	}


    	/*
    	//printf("%d\n", count);

    	switch(count){
    	case 100000:
    		power.startTransaction();
    		power.setBat1CPU(true);
    		power.setBat2CPU(false);
    		power.setBat1Drive(false);
    		power.setBat2Drive(true);
    		power.setBat1Charge(false);
    		power.setBat2Charge(false);
    		power.setBat1Volt(13.05);
    		power.setBat2Volt(12.00);
    		power.setBat1Per(100.0);
    		power.setBat2Per(76.0);
    		power.setChgVolt(0.0);
    		power.setChgTime(0);
    		power.setChgRemain(0);
    		power.setChargeAvl(false);
    		power.commitTransaction();
    		break;
    	case 200000:
    		power.startTransaction();
			power.setBat1CPU(false);
			power.setBat2CPU(true);
			power.setBat1Drive(true);
			power.setBat2Drive(false);
			power.setBat1Charge(false);
			power.setBat2Charge(false);
			power.setBat1Volt(11.00);
			power.setBat2Volt(12.00);
			power.setBat1Per(50.0);
			power.setBat2Per(76.0);
			power.setChgVolt(0.0);
			power.setChgTime(0);
			power.setChgRemain(0);
			power.setChargeAvl(true);
			power.commitTransaction();
			break;
    	case 300000:
    		power.startTransaction();
			power.setBat1CPU(false);
			power.setBat2CPU(true);
			power.setBat1Drive(false);
			power.setBat2Drive(false);
			power.setBat1Charge(false);
			power.setBat2Charge(true);
			power.setBat1Volt(10.50);
			power.setBat2Volt(11.00);
			power.setBat1Per(25.0);
			power.setBat2Per(50.0);
			power.setChgVolt(12.0);
			power.setChgTime(30);
			power.setChgRemain(180);
			power.setChargeAvl(true);
			power.commitTransaction();
			break;
    	case 400000:
    		power.startTransaction();
			power.setBat1CPU(false);
			power.setBat2CPU(true);
			power.setBat1Drive(false);
			power.setBat2Drive(false);
			power.setBat1Charge(true);
			power.setBat2Charge(false);
			power.setBat1Volt(10.50);
			power.setBat2Volt(13.50);
			power.setBat1Per(50.0);
			power.setBat2Per(100.0);
			power.setChgVolt(12.5);
			power.setChgTime(60);
			power.setChgRemain(120);
			power.setChargeAvl(true);
			power.commitTransaction();
			break;
    	}
    	if (count > 500000){
    		count = 0;
    	}
    	count++;
    	sleep_ms(1);
    	*/
    }




    return 0;
}


