cmake_minimum_required(VERSION 3.7)
project(uartSample C ASM)

file(GLOB_RECURSE UART_SOURCE "src/*.c")

add_library(UART
        src/uart_logger.c
        src/uart_buffer.c
        src/uart_driver.c
        src/nextion_manager.c)
include_directories(inc)

add_definitions(-DLOG_SPEED=115200)
add_definitions(-DLOG_USART3)
add_definitions(-DLOG_DMA)
add_definitions(-DLOG_BUF)

add_definitions(-DBUFFER_UART4)

#Subproject TEST
add_executable(Test.elf test.c  ${UART_SOURCE} ${LINKER_SCRIPT})
target_link_libraries(Test.elf SPL CMSIS UART UTILS)
create_binary(Test.elf Test)

#Subproject UartTest
add_executable(UartTest.elf main.c ${UART_SOURCE} ${LINKER_SCRIPT})
target_link_libraries(UartTest.elf SPL CMSIS UART UTILS)
create_binary(UartTest.elf UartTest)

#add_executable(NextionTest.elf NextionTest.c src/nextion_manager.c ${LINKER_SCRIPT})
#target_link_libraries(NextionTest.elf SPL CMSIS UART UTILS NEXTION)
#create_binary(NextionTest.elf NextionTest)
