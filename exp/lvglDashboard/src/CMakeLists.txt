
add_executable(${NAME}
        main.cpp
        Widgets.cpp
        
        State.cpp
        StateObserver.cpp
        PowerState.cpp
        
        imgs/cpuOn.c
        imgs/cpuOff.c
        imgs/driveOn.c
        imgs/driveOff.c
        imgs/chargeOn.c
        imgs/chargeOff.c
        
        imgs/battery0.c
        imgs/battery25.c
        imgs/battery50.c
        imgs/battery75.c
        imgs/battery100.c
        imgs/batteryC.c
        
        imgs/play.c
        imgs/halt.c
        
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(${NAME} 
	 pico_stdlib
	 touch169
     lvgl
     json_maker
     tiny_json
     
	)

   
# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})

# enable usb output, disable uart output
pico_enable_stdio_usb(${NAME} 1)
pico_enable_stdio_uart(${NAME} 0)
