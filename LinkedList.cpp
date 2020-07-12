//
// Created by Nitish Mohan Shandilya on 6/29/20.
//

#include "Node.hpp"

template <typename T>
class LinkedList{
public:

    Node<T>* head;


    LinkedList():head(NULL){}
    void addNode(const T inputData);
    Node<T>* findNode();
    bool deleteNodeByValue(const T value);
    void print() const;
};

template <typename T>
void LinkedList<T>::addNode(const T inputData) {
    Node<T>* newNode = new Node<T>(inputData);
    if (head == NULL){
        head = newNode;
    } else {
        Node<T>* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

template <typename T>
bool LinkedList<T>::deleteNodeByValue(const T inputData) {
    if (head == NULL) return false;

    Node<T>* temp = head;
    if (temp->data == inputData){
        head = head->next;
        delete temp;
        return true;
    }
    while (temp->next != NULL) {
        if (temp->next->data == inputData){
            Node<T>* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <typename T>
void LinkedList<T>::print() const {
    Node<T>* temp = head;
    cout << "Start Printing\n";
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void testLinkedList()
{
    LinkedList<int> linkedList;
    linkedList.addNode(4);
    linkedList.addNode(5);
    linkedList.addNode(6);
    linkedList.print();
    linkedList.deleteNodeByValue(4);
    linkedList.print();
}