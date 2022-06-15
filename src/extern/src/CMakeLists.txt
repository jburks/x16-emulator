find_package(SDL2)

set(SRCS
    ym2151.c
)

set(HEADERS
    ym2151.h
)

add_library (ym2151
   STATIC
)

target_sources(ym2151
    PRIVATE
        ${SRCS}
        ${HEADERS}
)

target_include_directories(ym2151
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${SDL2_INCLUDE_DIR}
)

target_link_libraries(ym2151
    PRIVATE
        ${SDL2_LIBRARY}
)

set_target_properties(ym2151 PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/obj")
