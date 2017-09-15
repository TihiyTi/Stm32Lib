cmake_minimum_required(VERSION 3.7)
project(sample C ASM)

add_library(TiLib
        ../Library/rcc/rcc_driver.c
        ../Library/gpio/gpio_driver.c
        ../Library/tim/tim_driver.c
        ../Library/dac/dac_driver.c)
#target_compile_definitions(DEF1 PRIVATE FUNC1)
include_directories(../Library/rcc)
include_directories(../Library/gpio)
include_directories(../Library/tim)
include_directories(../Library/dac)


#todo вынести пример в отдельную папку
#Example for GPIO
add_executable(Sample1.elf sample1.c  ${LINKER_SCRIPT})
target_link_libraries(Sample1.elf SPL CMSIS TiLib)
create_binary(Sample1.elf Sample1)

#Example for TIM
add_executable(Sample2.elf sample2.c  ${LINKER_SCRIPT})
target_link_libraries(Sample2.elf SPL CMSIS TiLib)
create_binary(Sample2.elf Sample2)

#Example for TIM
add_executable(Sample3.elf sample3.c  ${LINKER_SCRIPT})
target_link_libraries(Sample3.elf SPL CMSIS TiLib)
create_binary(Sample3.elf Sample3)
