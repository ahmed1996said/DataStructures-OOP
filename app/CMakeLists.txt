set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Werror")

include_directories(../lib)

add_executable(rectangle rectangle.cpp charstack_test.cpp pmatcher.cpp employeedir.cpp)
target_link_libraries(rectangle ece309)

add_executable(charstack_test charstack_test.cpp)
target_link_libraries(charstack_test ece309)

add_executable(pmatcher pmatcher.cpp)
target_link_libraries(pmatcher ece309)


add_executable(employeedir employeedir.cpp)
target_link_libraries(employeedir ece309)