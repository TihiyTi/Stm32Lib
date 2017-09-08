cmake_minimum_required(VERSION 3.7)
project(dacSample C ASM)

#add_library(DAC
#        ../../Library/dac/dac_driver.c)
##target_compile_definitions(DEF1 PRIVATE FUNC1)
#include_directories(../../Library/dac)

# Сборка программы DefTest1 с параметрами METH1 NUMBER=5
add_executable(DacTest1.elf dacTest1.c  ${LINKER_SCRIPT})
#target_compile_definitions(DacTest1.elf PRIVATE METH1 NUMBER=5)
target_link_libraries(DacTest1.elf SPL CMSIS TiLib)
create_binary(DacTest1.elf DacTest1)
