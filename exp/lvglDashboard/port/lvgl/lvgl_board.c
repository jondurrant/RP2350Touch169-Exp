/*
 * lvgl_board.c
 *
 * LVGL Porting to the Waveshare RP2350 1.69inch Touch
 * Based on Waveshare code
 *
 *  Created on: 4 Aug 2025
 *      Author: jondurrant
 */


#include "lvgl_board.h"

// LVGL
static lv_disp_drv_t disp_drv;
static lv_disp_draw_buf_t disp_buf;
static lv_color_t buf0[DISP_HOR_RES * DISP_VER_RES/2];
static lv_color_t buf1[DISP_HOR_RES * DISP_VER_RES/2];

// Touch
static uint16_t ts_x;
static uint16_t ts_y;
static lv_indev_state_t ts_act;
static uint8_t gesture = 0;
static lv_indev_drv_t indev_ts;

// Timer
static struct repeating_timer lvgl_timer;

static void disp_flush_cb(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p);
static void touch_callback(uint gpio, uint32_t events);
static void ts_read_cb(lv_indev_drv_t * drv, lv_indev_data_t*data);
static void dma_handler(void);
static bool repeating_lvgl_timer_callback(struct repeating_timer *t);

/***
 * Initialise the Display Board
 * @return
 */
int Board_init(){
	 if (DEV_Module_Init() != 0)
	{
		return -1;
	}

	printf("LCD_1in69_LCGL_test Demo\r\n");
	/*Init LCD*/
	uint8_t Scan_dir = HORIZONTAL;
	LCD_1IN69_Init(Scan_dir);
	LCD_1IN69_Clear(WHITE);
	/*Init RTC*/
	PCF85063A_Init();
	/*Init touch screen*/
	CST816S_init(CST816S_ALL_Mode);
	/*Init IMU*/
	QMI8658_init();
	/*Init LVGL*/
	LVGL_Init(Scan_dir);
	DEV_SET_PWM(60);

	return 0;
}



/********************************************************************************
function:	Initializes LVGL and enbable timers IRQ and DMA IRQ
parameter:
********************************************************************************/
int LVGL_Init(uint8_t Scan_dir){
    /*1.Init Timer*/
    add_repeating_timer_ms(5,    repeating_lvgl_timer_callback,            NULL, &lvgl_timer);

    /*2.Init LVGL core*/
    lv_init();

    /*3.Init LVGL display*/
    lv_disp_draw_buf_init(&disp_buf, buf0, buf1, DISP_HOR_RES * DISP_VER_RES / 2);
    lv_disp_drv_init(&disp_drv);
    disp_drv.flush_cb = disp_flush_cb;
    disp_drv.draw_buf = &disp_buf;
    disp_drv.hor_res = DISP_HOR_RES;
    disp_drv.ver_res = DISP_VER_RES;
    if(Scan_dir == VERTICAL)
        disp_drv.rotated = LV_DISP_ROT_NONE;
    else
        disp_drv.rotated = LV_DISP_ROT_90;
    lv_disp_t *disp= lv_disp_drv_register(&disp_drv);

#if INPUTDEV_TS
    /*4.Init touch screen as input device*/
    lv_indev_drv_init(&indev_ts);
    indev_ts.type = LV_INDEV_TYPE_POINTER;
    indev_ts.read_cb = ts_read_cb;
    lv_indev_t * ts_indev = lv_indev_drv_register(&indev_ts);
    //Enable touch IRQ
    DEV_IRQ_SET(Touch_INT_PIN, GPIO_IRQ_EDGE_RISE, &touch_callback);
#endif

    /*5.Init DMA for transmit color data from memory to SPI*/
    dma_channel_set_irq0_enabled(dma_tx, true);
    irq_set_exclusive_handler(DMA_IRQ_0, dma_handler);
    irq_set_enabled(DMA_IRQ_0, true);

    return 0;
}

/********************************************************************************
function:	Refresh image by transferring the color data to the SPI bus by DMA
parameter:
********************************************************************************/
static void disp_flush_cb(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p){
    LCD_1IN69_SetWindows(area->x1, area->y1, area->x2+1 , area->y2+1);  // Set the LVGL interface display position
    DEV_Digital_Write(LCD_DC_PIN, 1);
    DEV_Digital_Write(LCD_CS_PIN, 0);
    dma_channel_configure(dma_tx,
                          &c,
                          &spi_get_hw(LCD_SPI_PORT)->dr,
                          color_p, // read address
                          ((area->x2 + 1 - area-> x1)*(area->y2 + 1 - area -> y1))*2,
                          true);// Start DMA transfer
}

/********************************************************************************
function:   Touch interrupt handler
parameter:
********************************************************************************/
static void touch_callback(uint gpio, uint32_t events){
    if (gpio == Touch_INT_PIN)
    {
        CST816S_Get_Point(); // Get coordinate data
        gesture = CST816S_Get_Gesture(); // Get gesture data
        ts_x = Touch_CTS816.x_point;
        ts_y = Touch_CTS816.y_point;
        ts_act = LV_INDEV_STATE_PRESSED;
    }
}

/********************************************************************************
function:   Update touch screen input device status
parameter:
********************************************************************************/
static void ts_read_cb(lv_indev_drv_t * drv, lv_indev_data_t*data){
    data->point.x = ts_x;
    data->point.y = ts_y;
    data->state = ts_act;
    ts_act = LV_INDEV_STATE_RELEASED;
}

/********************************************************************************
function:   Indicate ready with the flushing when DMA complete transmission
parameter:
********************************************************************************/
static void dma_handler(void){
    if (dma_channel_get_irq0_status(dma_tx))
    {
        dma_channel_acknowledge_irq0(dma_tx);
        DEV_Digital_Write(LCD_CS_PIN, 1);
        lv_disp_flush_ready(&disp_drv); // Indicate you are ready with the flushing
    }
}



/********************************************************************************
function:   Report the elapsed time to LVGL each 5ms
parameter:
********************************************************************************/
static bool repeating_lvgl_timer_callback(struct repeating_timer *t) {
    lv_tick_inc(5);
    return true;
}




