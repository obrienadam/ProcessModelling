file(GLOB HEADERS *.h)
file(GLOB SOURCES *.cpp)
file(GLOB UI *.ui)

add_library(ProcessModelScene ${HEADERS} ${SOURCES} ${UI})
target_link_libraries(ProcessModelScene Qt5::Widgets ProcessModel)
