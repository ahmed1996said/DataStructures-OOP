include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../lib)

add_executable(rectangleTests basic_rectangle_tests.cpp)
add_executable(hashTest hashTests.cpp)
add_executable(BSTests "(HW6)BSTree_test.cpp" graphtests.cpp)
add_executable(HeapTests "(HW6)IntMaxHeap_tests.cpp")
add_executable(graphtests graphtests.cpp)


target_link_libraries(rectangleTests gtest gtest_main)
target_link_libraries(rectangleTests ece309)

target_link_libraries(hashTest gtest gtest_main)
target_link_libraries(hashTest ece309)

target_link_libraries(BSTests gtest gtest_main)
target_link_libraries(BSTests ece309)

target_link_libraries(HeapTests gtest gtest_main)
target_link_libraries(HeapTests ece309)

target_link_libraries(graphtests gtest gtest_main)
target_link_libraries(graphtests ece309)