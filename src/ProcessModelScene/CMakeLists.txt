file(GLOB HEADERS *.h)
file(GLOB SOURCES *.cpp)
file(GLOB UI *.ui)
file(GLOB QRC *.qrc)

add_library(ProcessModelScene ${HEADERS} ${SOURCES} ${UI} ${QRC})
target_link_libraries(ProcessModelScene Qt5::Widgets ProcessModel)
