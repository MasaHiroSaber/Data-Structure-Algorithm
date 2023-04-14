cmake_minimum_required(VERSION 3.24)
project(Data_structure_and_algorithm_foundation)

set(CMAKE_CXX_STANDARD 17)

add_executable(Data_structure_and_algorithm_foundation Array/DynamicallyExpandingArray.cpp)
add_executable(Array Array/DynamicallyExpandingArray.cpp Array/ControllerOrderArray.cpp Array/MergingArrays.cpp)
add_executable(LinkedList LinkedList/LinkedList.cpp LinkedList/DoubleLinkedList.cpp LinkedList/CircularLinkedList.cpp
        LinkedList/MergeLinkedLists.cpp)