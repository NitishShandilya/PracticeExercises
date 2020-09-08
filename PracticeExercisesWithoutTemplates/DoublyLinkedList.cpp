//
// Created by Nitish Mohan Shandilya on 7/14/20.
//

namespace PracticeExercisesWithoutTemplates {

// Exceptions
struct DoublyLinkedListEmptyException : exception {
    const char* what() const noexcept {
        return "Doubly Linked List is empty!!";
    }
};

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int inputData) : data(inputData), prev(nullptr), next(nullptr) {}
};

struct DoublyLinkedList {
    Node* head;
    DoublyLinkedList() : head(nullptr) {}
    void add(const int inputData);
    bool removeByValue(const int inputData);
    bool removeAllByValue(const int inputData);
    void print();
};

void DoublyLinkedList::add(const int inputData) {
    Node* newNode = new Node(inputData);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

bool DoublyLinkedList::removeByValue(const int inputData) {
    if (head == nullptr) throw DoublyLinkedListEmptyException();
    bool deleted = false;
    while (head != nullptr && head->data == inputData) {
        Node* temp = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        delete temp;
        deleted = true;
    }
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == inputData) {
            Node *toDelete = temp;
            if (temp->next != nullptr)
                temp->next->prev = temp->prev;
            if (temp->prev != nullptr)
                temp->prev->next = temp->next;

            delete toDelete;
            deleted = true;
        }
        temp = temp->next;
    }
    return deleted;
}

void DoublyLinkedList::print() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void testDoublyLinkedList() {
    DoublyLinkedList doublyLinkedList;
    doublyLinkedList.add(3);
    doublyLinkedList.add(3);
    doublyLinkedList.add(3);
    doublyLinkedList.add(4);
    doublyLinkedList.add(5);
    doublyLinkedList.add(3);
    doublyLinkedList.add(3);
    doublyLinkedList.add(6);
    doublyLinkedList.add(7);
    doublyLinkedList.removeByValue(3);
    doublyLinkedList.print();
}

}