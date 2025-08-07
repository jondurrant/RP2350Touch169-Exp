if (DEFINED LIB_PATH)
	message("Using Given LIB_PATH '${LIB_PATH}')")
else ()
	set(LIB_PATH "${CMAKE_CURRENT_LIST_DIR}lib/")
    message("Using local LIB_PATH '${LIB_PATH}')")
endif ()

add_library(touch169 STATIC)

target_sources(touch169 PUBLIC
	${LIB_PATH}/Config/DEV_Config.c
    ${LIB_PATH}/LCD/LCD_1in69.c
    ${LIB_PATH}/PCF85063A/PCF85063A.c
    ${LIB_PATH}/QMI8658/QMI8658.c
    ${LIB_PATH}/Touch/CST816S.c
)

# Add include directory
target_include_directories(touch169 PUBLIC 
    ${LIB_PATH}/Config/
    ${LIB_PATH}/LCD/
    ${LIB_PATH}/PCF85063A/
    ${LIB_PATH}/QMI8658/
    ${LIB_PATH}/Touch/
)


target_link_libraries(touch169 PUBLIC 
    pico_stdlib 
    hardware_spi 
    hardware_i2c 
    hardware_pwm 
    hardware_adc 
    hardware_dma
    hardware_irq
    )