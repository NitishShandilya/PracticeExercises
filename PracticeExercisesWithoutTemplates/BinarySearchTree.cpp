//
// Created by Nitish Mohan Shandilya on 7/27/20.
//
// Insertion, Search, Delete, Inorder successor, Inorder Predecessor
// Balance -> AVL or RB tree

//[5,4,6,2,1,7,8]

namespace PracticeExercisesWithoutTemplates {

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(const int input) : data(input) {}
};

Node* insert(Node* root, const int input) {
    if (root == nullptr)
        return new Node(input);

    if (input < root->data)
        root->left = insert(root->left, input);
    else
        root->right = insert(root->right, input);

    return root;

}

Node* search(Node* root, const int input) {
    if (root == nullptr)
        return root;

    if (root->data == input)
        return root;

    if (input < root->data)
        return search(root->left, input);
    else
        return search(root->right, input);
}

unsigned int height(Node* root) {
    if (root == nullptr) return 0;
    return max(height(root->left), height(root->right)) + 1;

}

unsigned int size(Node* root) {
    if (root == nullptr) return 0;
    return size(root->left) + size(root->right) + 1;
}

Node* remove(Node* root, const int input) {
    if (root == nullptr) return root;

    if (input < root->data) {
        root->left = remove(root->left, input);
    } else if (input > root->data) {
        root->right = remove(root->right, input);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } else if (root->left == nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
        } else {
            Node* succ = root->right;
            while (succ->left != nullptr)
                succ = succ->left;
            root->data = succ->data;
            root->right = remove(root->right, succ->data);
        }
    }
    return root;
}

Node* inOrderSuccessor(Node* root, Node* input) {
    if (root == nullptr || input == nullptr) return nullptr;

    Node* succ = nullptr;
    while (root != nullptr && root->data != input->data) {
        if (input->data < root->data) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    if (root == nullptr) return nullptr;
    if (root->right == nullptr) return succ;

    succ = root->right;
    while (succ->left != nullptr)
        succ = succ->left;

    return succ;
}

Node* inOrderPredecessor(Node* root, Node* input) {
    if (root == nullptr || input == nullptr) return nullptr;

    Node* pred = nullptr;
    while (root != nullptr && root->data != input->data) {
        if (input->data < root->data) {
            root = root->left;
        } else {
            pred = root;
            root = root->right;
        }
    }
    if (root == nullptr) return nullptr;
    if (root->left == nullptr) return pred;

    pred = root->left;
    while (pred->right != nullptr)
        pred = pred->right;

    return pred;
}

void testBinarySearchTree() {
    Node* root = nullptr;
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 8);
    insert(root, 6);
    insert(root, 9);
    insert(root, -1);
    Node* iter = search(root, 2);

    remove(root, 5);

    if (iter != nullptr)
        cout << "Searched: " << iter->data << endl;
    iter = search(root, 10);
    if (iter != nullptr)
        cout << "Searched: " << iter->data << endl;
    cout << "Height: " << height(root) << endl;
    cout << "Size: " << size(root) << endl;

    Node* iter2 = new Node(2);
    iter2 = inOrderSuccessor(root, iter2);
    if (iter2 != nullptr)
        cout << "inOrderSuccessor: " << iter2->data << endl;
    Node* iter3 = new Node(10);
    iter3 = inOrderSuccessor(root, iter3);
    if (iter3 != nullptr)
        cout << "inOrderSuccessor: " << iter3->data << endl;

    Node* iter4 = new Node(9);
    iter4 = inOrderPredecessor(root, iter4);
    if (iter4 != nullptr)
        cout << "inOrderPredecessor: " << iter4->data << endl;

    Node* iter5 = new Node(10);
    iter5 = inOrderPredecessor(root, iter5);
    if (iter5 != nullptr)
        cout << "inOrderPredecessor: " << iter5->data << endl;
}

}
