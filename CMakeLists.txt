cmake_minimum_required(VERSION 3.14)
project(cpp-kata)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# add each day's directory as a separate executable
file(GLOB children RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/kata/Day*)
foreach(child ${children})
  if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${child})
    file(GLOB SOURCES "${child}/*.cc")
    string(REPLACE "kata/" "" test_name ${child})
    message(STATUS "Test name: ${test_name}")
    add_executable(${test_name} ${SOURCES})
    target_link_libraries(${test_name} gtest gtest_main)
    add_test(NAME ${test_name} COMMAND ${test_name})
  endif()
endforeach()

