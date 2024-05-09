add_executable(cc_keyboard
    main.cpp
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(cc_keyboard pico_stdlib)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(cc_keyboard)

add_subdirectory(usb)