add_library (cpu
   STATIC
   fake6502.c
)

find_package(SDL2)

set(SRCS
    fake6502.c
)

set(HEADERS
    65c02.h
    fake6502.h
    instructions.h
    mnemonics.h
    modes.h
    support.h
    tables.h
)

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/tables.h ${CMAKE_CURRENT_SOURCE_DIR}/mnemonics.h
    DEPENDS 6502.opcodes 65c02.opcodes
    PRE_BUILD
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND python buildtables.py
)

target_include_directories(cpu
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${SDL2_INCLUDE_DIR}
)

target_sources(cpu
    PRIVATE
        ${SRCS}
        ${HEADERS}
)

target_link_libraries(cpu
    PRIVATE
        ${SDL2_LIBRARY}
)

set_target_properties(cpu PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/obj")
set_property(TARGET cpu PROPERTY CXX_STANDARD 17)