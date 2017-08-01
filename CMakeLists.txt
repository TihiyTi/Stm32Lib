project(StmSample C ASM)
cmake_minimum_required(VERSION 3.7)

file(GLOB_RECURSE UART_DMA_SOURCE "uart_dma/src/*.c")
file(GLOB_RECURSE UART_SOURCE "uart/*.c")

add_library(SPL
        Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.c
        Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma.c
        Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_usart.c
        Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.c
        Drivers/STM32F4xx_StdPeriph_Driver/src/misc.c
        )
add_library(CMSIS
        Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc_ride7/startup_stm32f40xx.s
        Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c)

add_library(UART
        uart/src/uart_logger.c
        uart/src/uart_buffer.c)

add_library(UTILS
        utils/printf.c
        utils/queue.c)
#add_library(UART uart/src/*.c uart/src/uart_driver.c.c uart/src/uart_driver.c.h)

include_directories(uart_dma/inc)
include_directories(Drivers/CMSIS/Include)
include_directories(Drivers/CMSIS/Device/ST/STM32F4xx/Include)
include_directories(Drivers/STM32F4xx_StdPeriph_Driver/inc)

include_directories(uart/inc)
include_directories(utils)

add_definitions(-DDiscovery)
add_definitions(-DSTM32F40_41xxx)
#add_definitions(-DARM_MATH_CM4)

#Logger defines

add_definitions(-DLOG_SPEED=115200)
add_definitions(-DLOG_USART3)
add_definitions(-DLOG_DMA)
add_definitions(-DLOG_BUF)


add_definitions(-DBUFFER_UART3)




add_executable(UartDMA.elf ${UART_DMA_SOURCE} ${LINKER_SCRIPT})
add_executable(UartTest.elf ${UART_SOURCE} ${LINKER_SCRIPT})

target_link_libraries(UartDMA.elf SPL CMSIS)

target_link_libraries(UartTest.elf SPL CMSIS UART UTILS)


set(HEX_FILE ${PROJECT_SOURCE_DIR}/build/UartDMA.hex)
set(BIN_FILE ${PROJECT_SOURCE_DIR}/build/UartDMA.bin)
add_custom_command(TARGET UartDMA.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:UartDMA.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:UartDMA.elf> ${BIN_FILE}
        COMMENT "Building ${HEX_FILE} \nBuilding ${BIN_FILE}")

set(HEX_FILE ${PROJECT_SOURCE_DIR}/build/UartTest.hex)
set(BIN_FILE ${PROJECT_SOURCE_DIR}/build/UartTest.bin)
add_custom_command(TARGET UartTest.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:UartTest.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:UartTest.elf> ${BIN_FILE}
        COMMENT "Building ${HEX_FILE} \nBuilding ${BIN_FILE}")