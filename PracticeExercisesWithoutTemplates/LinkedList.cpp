//
// Created by Nitish Mohan Shandilya on 7/13/20.
//

namespace PracticeExercisesWithoutTemplates {

// Exceptions
struct LinkedListEmptyException : exception {
    const char* what() const noexcept {
        return "Linked List is Empty!!";
    }
};

struct Node {
    int data;
    Node* next;
    Node(const int inputData) : data(inputData), next(nullptr) {}
};

struct LinkedList {
    Node* head;
    LinkedList() : head(nullptr) {}
    void add(const int inputData);
    bool removeByValue(const int inputData);
};

void LinkedList::add(const int inputData) {
    Node* newNode = new Node(inputData);
    if (head == nullptr) {
      head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

bool LinkedList::removeByValue(const int inputData) {
    if (head == nullptr) throw LinkedListEmptyException();
    if (head->data == inputData) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return true;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        if (temp->next->data == inputData) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void testLinkedList() {
    try {
        LinkedList* linkedList = new LinkedList();
        linkedList->add(2);
        linkedList->add(3);
        linkedList->removeByValue(2);
        linkedList->removeByValue(3);
        //linkedList->removeByValue(3);
        delete linkedList;
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}

}