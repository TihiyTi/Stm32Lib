project(StmSample C ASM)
cmake_minimum_required(VERSION 3.7)

file(GLOB_RECURSE UART_DMA_SOURCE "uart_dma/src/*.c")

add_library(SPL
        Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.c
        Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma.c
        Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_usart.c
        Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.c
        Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dac.c
        Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_tim.c
        Drivers/STM32F4xx_StdPeriph_Driver/src/misc.c)
add_library(CMSIS
        Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc_ride7/startup_stm32f40_41xxx.s
        Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c)
add_library(RTT
        Drivers/RTT/Syscalls/RTT_Syscalls_GCC.c
        Drivers/RTT/RTT/SEGGER_RTT.c
        Drivers/RTT/RTT/SEGGER_RTT_printf.c)
add_library(SSV
        Drivers/SSV/SEGGER_SYSVIEW_Config.c
        Drivers/SSV/SEGGER/SEGGER_SYSVIEW.c
        Drivers/SSV/SEGGER/SEGGER_RTT.c
        Drivers/RTT/RTT/SEGGER_RTT_printf.c)
add_library(TiLib
        TiStmLib/rcc/rcc_driver.c
        TiStmLib/gpio/gpio_driver.c
        TiStmLib/tim/tim_driver.c
        TiStmLib/dac/dac_driver.c
        TiStmLib/uart/uart_driver.c
        TiStmLib/uart/uart_buffer.c
        )
add_library(UTILS
        utils/printf.c
        utils/queue.c)
add_library(NEXTION TiStmLib/uart/nextion_manager.c)
#add_library(DEF def/def.c)

include_directories(utils)
include_directories(uart_dma/inc)
include_directories(nextion/inc)
#include_directories(def)
include_directories(Drivers/CMSIS/Include)
include_directories(Drivers/CMSIS/Device/ST/STM32F4xx/Include)
include_directories(Drivers/STM32F4xx_StdPeriph_Driver/inc)
include_directories(Drivers/RTT/RTT)
include_directories(Drivers/SSV/Config)
include_directories(Drivers/SSV/SEGGER)
include_directories(TiStmLib/rcc)
include_directories(TiStmLib/gpio)
include_directories(TiStmLib/tim)
include_directories(TiStmLib/dac)
include_directories(TiStmLib/uart)



add_definitions(-DDiscovery)
#add_definitions(-DSTM32F40_41xxx)
#add_definitions(-DARM_MATH_CM4)

macro(create_binary target name)
    set(HEX_FILE ${PROJECT_SOURCE_DIR}/build/${name}.hex)
    set(BIN_FILE ${PROJECT_SOURCE_DIR}/build/${name}.bin)
    add_custom_command(
            TARGET ${target} POST_BUILD
            COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${target}> ${HEX_FILE}
            COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${target}> ${BIN_FILE}
            COMMENT "Building ${HEX_FILE} \nBuilding ${BIN_FILE}")
endmacro()

#add_subdirectory( uart)
#add_subdirectory( nextion)

# Модуль для примера использования define-ов при использовании  CMake
#add_subdirectory(def)
#add_subdirectory(Library)
add_subdirectory(Examples)
#add_subdirectory(uart)
#add_subdirectory(Examples/dac)


#add_executable(NextionTest.elf uart/NextionTest.c nextion/src/nextion_manager.c ${LINKER_SCRIPT})
#target_link_libraries(NextionTest.elf SPL CMSIS UART UTILS NEXTION)
#create_binary(NextionTest.elf NextionTest)
#create_binary(UartDMA.elf)
