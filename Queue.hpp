//
// Created by Nitish Mohan Shandilya on 7/6/20.
//

#include <iostream>

#include "Node.hpp"

#ifndef PRACTICEEXERCISES_QUEUE_HPP
#define PRACTICEEXERCISES_QUEUE_HPP

template <typename dataType>
class Queue {
    Node<dataType>* front;
    Node<dataType>* back;

public:
    Queue() : front(nullptr), back(nullptr) {}
    void add(const dataType inputData);
    dataType remove();
    bool isEmpty() const;
};

#endif //PRACTICEEXERCISES_QUEUE_HPP
