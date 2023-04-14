cmake_minimum_required(VERSION 3.24)
project(Data_structure_and_algorithm_foundation)

set(CMAKE_CXX_STANDARD 17)

add_executable(Data_structure_and_algorithm_foundation Array/DynamicallyExpandingArray.cpp)
add_executable(Array Array/DynamicallyExpandingArray.cpp Array/ControllerOrderArray.cpp Array/MergingArrays.cpp)
add_executable(LinkedList LinkedList/LinkedList.cpp LinkedList/DoubleLinkedList.cpp LinkedList/CircularLinkedList.cpp
        LinkedList/MergeLinkedLists.cpp LinkedList/FindMidNode.cpp LinkedList/ReverseList.cpp)
add_executable(Stack Stack/SequentialStack.cpp Stack/LStack.cpp Stack/numerals.cpp)
add_executable(Queue Queue/SequentialQueues.cpp Queue/CircularQueues.cpp Queue/LQueues.cpp)
add_executable(Recursion Recursion/Recursion.cpp)
add_executable(Sort Sort/Sort.cpp)
add_executable(BinaryTree BinaryTree/BinaryTree.cpp)