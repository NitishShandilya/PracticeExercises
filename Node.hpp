//
// Created by Nitish Mohan Shandilya on 7/5/20.
//

#ifndef PRACTICEEXERCISES_NODE_HPP
#define PRACTICEEXERCISES_NODE_HPP

template <typename T>
class Node{
public:
    T data;
    Node<T>* next;

    Node (const T inputData) : data(inputData), next(nullptr) {}
};

#endif //PRACTICEEXERCISES_NODE_HPP
