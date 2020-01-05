set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Werror")

add_library(ece309 Rectangle.cpp
                   CharStack.h
                   CharStack.cpp
                   ParenMatcher.cpp
                   ParenMatcher.h IntHashTable.h IntHashTable.cpp EmployeeDirectory.cpp EmployeeDirectory.h List.h List.cpp KVPair.h BSTree.h Stack.h IntMaxHeap.h IntMaxHeap.cpp Graph.h Graph.cpp IntegerSet.h IntegerSet.cpp Queue.h Queue.cpp Stack.cpp)



add_executable(charStack CharStack.cpp)

add_executable(test_paren ParenMatcher.cpp CharStack.cpp)
add_executable(graph Graph.cpp List.cpp)
