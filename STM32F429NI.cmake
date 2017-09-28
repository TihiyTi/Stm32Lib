SET(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_SYSTEM_VERSION 1)

# specify the cross compiler
SET(CMAKE_C_COMPILER_WORKS 1)
SET(CMAKE_C_COMPILER arm-none-eabi-gcc)
SET(CMAKE_CXX_COMPILER arm-none-eabi-g++)

SET(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/STM32F429NI_FLASH.ld)
SET(COMMON_FLAGS "-mcpu=cortex-m4 -mthumb -Wall -ffunction-sections -g -O0 -flto -fno-builtin -DSTM32F407VG -DSTM32F4XX -DUSE_STDPERIPH_DRIVER -D__ASSEMBLY__ -I.")

SET(CMAKE_CXX_FLAGS_INIT "${COMMON_FLAGS} -std=c++11")
SET(CMAKE_C_FLAGS_INIT "${COMMON_FLAGS} -std=gnu99")
SET(CMAKE_EXE_LINKER_FLAGS_INIT "-Wl,-gc-sections,-M=binary.map -T ${LINKER_SCRIPT}")

#MCU dependend definition
add_definitions(-DSTM32F429_439xx)
