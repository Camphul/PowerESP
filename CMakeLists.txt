# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
# This cmake is built on an arch linux machine. Windows might require an other cmake.
cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(EXTRA_COMPONENT_DIRS main application)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
set(USER_HOME "$ENV{HOME}")
# replace with your ESP-IDF version.
set(VERSION_ESP_IDF "esp-2021r1-8.4.0")
set(XTENSA_DIR_BIN "$ENV{USER_HOME}/.espressif/tools/xtensa-esp32-elf/${VERSION_ESP_IDF}/xtensa-esp32-elf/bin/")
set(CMAKE_FIND_ROOT_PATH "${USER_HOME}/.espressif/tools/xtensa-esp32-elf/${VERSION_ESP_IDF}/xtensa-esp32-elf/")
set(CMAKE_C_COMPILER "${XTENSA_DIR_BIN}/xtensa-esp32-elf-gcc")
set(CMAKE_CXX_COMPILER "${XTENSA_DIR_BIN}/xtensa-esp32-elf-g++")
set(CMAKE_ASM_COMPILER "${XTENSA_DIR_BIN}/xtensa-esp32-elf-gcc")
project(PowerESP)
