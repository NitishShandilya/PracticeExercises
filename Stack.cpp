//
// Created by Nitish Mohan Shandilya on 6/29/20.
//

#include <exception>

#include "Node.hpp"

using namespace std;

class StackException : public exception {};

class StackOverFlow : public StackException {
public:
    const char* what() const noexcept {
        return "Stack Overflow!!";
    }
};

class StackUnderFlow : public StackException {
public:
    const char* what() const noexcept {
        return "Stack UnderFlow!!";
    }
};

template <typename dataType>
class Stack {
    Node<dataType>* top;
    const static int MAX_ELEMENTS = 5;
    int numberOfElements;

public:
    Stack() : top(nullptr), numberOfElements(0) {}
    void push(const dataType inputData);
    dataType pop();
    dataType peek();
};

template <typename dataType>
void Stack<dataType>::push(const dataType inputData) {
    if (numberOfElements >= MAX_ELEMENTS)
        throw StackOverFlow();

    Node<dataType>* newNode = new Node<dataType>(inputData);
    newNode->next = top;
    top = newNode;
    numberOfElements++;
}

template <typename dataType>
dataType Stack<dataType>::pop() {
    if (top == nullptr)
        throw StackUnderFlow();

    Node<dataType>* nodeToDelete = top;
    dataType nodeDataToReturn = nodeToDelete->data;
    top = top->next;
    delete nodeToDelete;
    return nodeDataToReturn;
}

template <typename dataType>
dataType Stack<dataType>::peek() {
    return top->data;
}

void testStack() {
    try {
        Stack<int> stack;
        stack.push(3);
        stack.push(4);
        stack.push(5);
        cout << stack.pop() << endl;
        cout << stack.pop() << endl;
        cout << stack.peek() << endl;
        cout << stack.pop() << endl;
        cout << stack.pop() << endl;

        stack.push(6);
        stack.push(7);
        stack.push(8);

    } catch(StackException& exception) {
        cout << exception.what() << endl;
    }
}