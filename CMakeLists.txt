cmake_minimum_required(VERSION 3.27)
project(sorting_group_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(sorting_group_project src/main.cpp)

set_target_properties(sorting_group_project PROPERTIES OUTPUT_NAME "sgp")
set_target_properties(sorting_group_project PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

get_cmake_property(_variableNames VARIABLES)
list (SORT _variableNames)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()