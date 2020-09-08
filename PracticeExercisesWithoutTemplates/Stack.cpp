//
// Created by Nitish Mohan Shandilya on 7/13/20.
//
namespace PracticeExercisesWithoutTemplates {

// Exceptions
struct StackEmptyException : public exception {
    const char* what() const noexcept {
        return "Stack is Empty!!";
    }
};

// Supporting classes
struct Node {
    int data;
    Node* next;
    Node(const int inputData) : data(inputData), next(nullptr) {}
};

// Stack class
struct Stack {
    Node* top;
    Stack() : top(nullptr) {}
    void push(int inputData);
    int pop();
    inline int peek();
};

void Stack::push(const int inputData) {
    Node* newNode = new Node(inputData);
    newNode->next = top;
    top = newNode;
}

int Stack::pop() {
    if (top == nullptr) throw StackEmptyException();
    Node* temp = top;
    int dataToReturn = temp->data;
    top = top->next;
    delete temp;
    return dataToReturn;
}

inline int Stack::peek() {
    if (top == nullptr) throw StackEmptyException();
    return top->data;
}

void testStack() {
    try {
        Stack stack;
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.pop();
        cout << stack.pop() << endl;
        stack.pop();
        stack.pop();
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}

} // end of namespace PracticeExercisesWithoutTemplates