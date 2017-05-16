file(GLOB HEADERS processmodel_global.h */*.h)
file(GLOB SOURCES */*.cpp)

add_library(ProcessModel ${HEADERS} ${SOURCES})
target_link_libraries(ProcessModel ${ARMADILLO_LIBRARIES})
