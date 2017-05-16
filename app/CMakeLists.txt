file(GLOB HEADERS *.h)
file(GLOB SOURCES *.cpp)
file(GLOB UI *.ui)
file(GLOB QRC *.qrc)

add_executable(promodel ${HEADERS} ${SOURCES} ${UI} ${QRC})
target_link_libraries(promodel ProcessModelScene)
