cmake_minimum_required(VERSION 3.7)
project(defSample C ASM)

# Единые исходники src/def_lib.c собираются в двух различных конфигурациях в зависимости от difine-ов FUNC1 и FUNC2
# Сборка библиотеки в конфигурации DEF1 при define FUNC1 для программы DefTest1
add_library(DEF1 src/def_lib.c)
target_compile_definitions(DEF1 PRIVATE FUNC1)
# Сборка библиотеки в конфигурации DEF2 при define FUNC2 для программы DefTest2
add_library(DEF2 src/def_lib.c)
target_compile_definitions(DEF2 PRIVATE FUNC2)

include_directories(inc)

# Сборка программы DefTest1 с параметрами METH1 NUMBER=5
add_executable(DefTest1.elf defTest.c  ${LINKER_SCRIPT})
target_compile_definitions(DefTest1.elf PRIVATE METH1 NUMBER=5)
target_link_libraries(DefTest1.elf SPL CMSIS DEF1)
create_binary(DefTest1.elf DefTest1)

# Сборка программы DefTest2 с параметрами METH2 NUMBER=6
add_executable(DefTest2.elf defTest.c  ${LINKER_SCRIPT})
target_compile_definitions(DefTest2.elf PRIVATE METH2 NUMBER=6)
target_link_libraries(DefTest2.elf SPL CMSIS DEF2)
create_binary(DefTest2.elf DefTest2)
