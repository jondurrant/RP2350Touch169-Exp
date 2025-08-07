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
    	if ((c != PICO_ERROR_TIMEOUT) && (c > 0)){
    		if ((c == '\n') || (c== '\r')){
    			buf[ind] = 0;
    			if (ind > 0){
    				printf("%s\n", buf);
    				json_t const* json = json_create( buf, jmem, sizeof jmem / sizeof *jmem );
    				if (json != NULL ){
    					//printf("Processing JSON\n");
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
    }




    return 0;
}


