cmake_minimum_required(VERSION 3.4...3.27)

# initialize pico-sdk from submodule
# note: this must happen before project()
include(import/pico-sdk/pico_sdk_init.cmake)

project("cc-keyboard" CXX C ASM)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_subdirectory(src)