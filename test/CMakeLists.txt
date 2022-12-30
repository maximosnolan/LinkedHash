add_executable(testOne testOne.cpp)
#target_include_directories(${TEST_EXE_NAME} PUBLIC ../src)
target_link_libraries(testOne LinkedHashMap)
add_test(NAME testOne COMMAND testOne)
