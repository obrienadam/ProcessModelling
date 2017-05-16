file(GLOB HEADERS *.h)
file(GLOB SOURCES *.cpp)
file(GLOB UI *.ui)

add_executable(promodel ${HEADERS} ${SOURCES} ${UI})
target_link_libraries(promodel ProcessModelScene)
