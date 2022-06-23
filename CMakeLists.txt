cmake_minimum_required(VERSION 3.0.0)
project(edge-art-generator VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${src_dir})
include_directories(${glfw3_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})


add_executable(edge-art-generator main.cpp edgeDetection.cpp)

target_link_libraries(edge-art-generator ${OpenCV_LIBS})
target_link_libraries(edge-art-generator PUBLIC ${glfw3_LIBRARIES} ${CMAKE_DL_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
