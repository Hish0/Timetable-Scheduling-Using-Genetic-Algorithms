cmake_minimum_required(VERSION 3.0.0)
project(hisham-project VERSION 1.0.0)

# Find Python and NumPy
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
find_package(Python3 COMPONENTS NumPy REQUIRED)

# Include directories
include_directories(${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS} include)


#Globing
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_executable(result_plot src/main.cpp ${SOURCE_FILES})



# Create executable
#add_executable(result_plot src/main.cpp)

# Set C++20 standard
set_property(TARGET result_plot PROPERTY CXX_STANDARD 20)

# Link libraries
target_link_libraries(result_plot Python3::Python Python3::NumPy)
target_include_directories(result_plot PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
