add_subdirectory(cpu)
add_subdirectory(extern/src)

find_package(SDL2)

set(SRCS
    audio.c
    debugger.c
    disasm.c
    i2c.c
    icon.c
    ieee.c
    javascript_interface.c
    joystick.c
    keyboard.c
    main.c
    memory.c
    rendertext.c
    rtc.c
    sdcard.c
    serial.c
    smc.c
    testbench.c
    timing.c
    vera_pcm.c
    vera_psg.c
    vera_spi.c
    via.c
    video.c
    wav_recorder.c
)

set(HEADERS
    audio.h
    debugger.h
    disasm.h
    glue.h
    i2c.h
    icon.h
    ieee.h
    joystick.h
    keyboard.h
    memory.h
    rendertext.h
    rom_symbols.h
    rtc.h
    sdcard.h
    serial.h
    smc.h
    timing.h
    testbench.h
    utf8.h
    utf8_encode.h
    vera_pcm.h
    vera_psg.h
    vera_spi.h
    version.h
    via.h
    video.h
    wav_recorder.h
)

add_executable(x16emu ${SRCS} ${HEADERS})

target_sources(x16emu
    PRIVATE
        ${SRCS}
        ${HEADERS}
)

set_target_properties(x16emu PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

target_include_directories(x16emu
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/extern/include
        ${CMAKE_CURRENT_SOURCE_DIR}/extern/src
        ${SDL2_INCLUDE_DIR}
)

target_link_libraries(x16emu
   PRIVATE
   cpu
   ym2151
   ${SDL2_LIBRARY}
)
