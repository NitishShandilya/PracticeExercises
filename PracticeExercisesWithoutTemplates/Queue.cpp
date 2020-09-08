//
// Created by Nitish Mohan Shandilya on 7/13/20.
//

namespace PracticeExercisesWithoutTemplates {

    // Queue class
    struct Queue {

        // Exceptions
        struct QueueEmptyException : public exception {
            const char* what() const noexcept {
                return "Queue is empty!!";
            }
        };

        // Supporting structures
        struct Node {
            int data;
            Node* next;
            Node(const int inputData) : data(inputData), next(nullptr) {}
        };

        // Data members
        Node* front;
        Node* back;

        // Member functions
        Queue() : front(nullptr), back(nullptr) {}
        void insert(const int inputData);
        int remove();
        int peek();
    };

    void Queue::insert(const int inputData) {
        Queue::Node* newNode = new Queue::Node(inputData);
        if (back != nullptr)
            back->next = newNode;
        back = newNode;
        if (front == nullptr)
            front = back;
    }

    int Queue::remove() {
        if (front == nullptr) throw QueueEmptyException();
        Queue::Node* temp = front;
        int dataToReturn = temp->data;
        front = front->next;
        delete temp;
        if (front == nullptr)
            back = nullptr;
    }

    int Queue::peek() {
        if (front == nullptr) throw Queue::QueueEmptyException();
        return front->data;
    }

    void testQueue() {
        try {
            Queue queue;
            queue.insert(3);
            queue.insert(4);
            cout << queue.peek() << endl;
            queue.remove();
            queue.remove();
            queue.remove();
        } catch (exception& e) {
            cout << e.what() << endl;
        }
    }
}
