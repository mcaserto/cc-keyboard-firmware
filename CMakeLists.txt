cmake_minimum_required(VERSION 3.4...3.27)

# initialize pico-sdk from submodule
# note: this must happen before project()
include(import/pico-sdk/pico_sdk_init.cmake)

project("cc-keyboard" CXX C ASM)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(cc_keyboard
    main.cpp
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(cc_keyboard pico_stdlib)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(cc_keyboard)