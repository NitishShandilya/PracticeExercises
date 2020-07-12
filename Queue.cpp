//
// Created by Nitish Mohan Shandilya on 6/29/20.
//

#include "Queue.hpp"

using namespace std;

template <typename dataType>
void Queue<dataType>::add(const dataType inputData) {
    Node<dataType>* newNode = new Node<dataType>(inputData);
    if (back != nullptr)
        back->next = newNode;
    back = newNode;
    if (front == nullptr)
        front = back;
}

template <typename dataType>
dataType Queue<dataType>::remove() {
    //if (front == nullptr) return nullptr;
    Node<dataType>* nodeToDelete = front;
    const dataType data = nodeToDelete->data;
    front = front->next;
    delete nodeToDelete;

    if (front == nullptr)
        back = nullptr;

    return data;
}

template <typename dataType>
bool Queue<dataType>::isEmpty() const {
    return front == nullptr;
}

void testQueue() {
    Queue<int> queue;
    queue.add(3);
    queue.add(4);
    queue.add(5);
    cout << queue.remove() << endl;
    cout << queue.remove() << endl;
    cout << queue.remove() << endl;
    //cout << queue.remove() << endl;
}