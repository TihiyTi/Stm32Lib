cmake_minimum_required(VERSION 3.7)
project(nextionSample C ASM)

add_executable(nextionSample.elf nextionSample.c ${LINKER_SCRIPT})
target_link_libraries(nextionSample.elf SPL CMSIS TiLib UTILS)
create_binary(nextionSample.elf nextionSample)
