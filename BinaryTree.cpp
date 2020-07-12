//
// Created by Nitish Mohan Shandilya on 7/3/20.
//

#include "NodeFactory.cpp"

BinaryTreeNode<int>* createTree()
{
    BinaryTreeNode<int>* const root =
        (BinaryTreeNode<int>*)NodeFactory<int>::createNode(3, TypeOfNode::BINARY_TREE_NODE);
    BinaryTreeNode<int>* const n1 =
        (BinaryTreeNode<int>*)NodeFactory<int>::createNode(4, TypeOfNode::BINARY_TREE_NODE);
    BinaryTreeNode<int>* const n2 =
        (BinaryTreeNode<int>*)NodeFactory<int>::createNode(5, TypeOfNode::BINARY_TREE_NODE);
    root->setLeftChild(n1);
    root->setRightChild(n2);

    BinaryTreeNode<int>* const n3 =
        (BinaryTreeNode<int>*)NodeFactory<int>::createNode(6, TypeOfNode::BINARY_TREE_NODE);
    BinaryTreeNode<int>* const n4 =
        (BinaryTreeNode<int>*)NodeFactory<int>::createNode(7, TypeOfNode::BINARY_TREE_NODE);
    BinaryTreeNode<int>* const n5 =
        (BinaryTreeNode<int>*)NodeFactory<int>::createNode(9, TypeOfNode::BINARY_TREE_NODE);
    n1->setLeftChild(n3);
    n3->setLeftChild(n4);
    n4->setLeftChild(n5);
    return root;
}

template <typename dataType>
void inorderTraversal(const BinaryTreeNode<dataType>* const root) {
    if (root != NULL) {
        inorderTraversal<dataType>(root->getLeftChild());
        cout << root->data << endl;
        inorderTraversal<dataType>(root->getRightChild());
    }
}

template <typename dataType>
void preOrderTraversal(const BinaryTreeNode<dataType>* const root) {
    if (root != NULL) {
        cout << root->data << endl;
        preOrderTraversal<dataType>(root->getLeftChild());
        preOrderTraversal<dataType>(root->getRightChild());
    }
}

template <typename dataType>
void postOrderTraversal(const BinaryTreeNode<dataType>* const root) {
    if (root != NULL) {
        postOrderTraversal<dataType>(root->getLeftChild());
        postOrderTraversal<dataType>(root->getRightChild());
        cout << root->data << endl;
    }
}

void testBinaryTree() {
    BinaryTreeNode<int>* root = createTree();

    inorderTraversal<int>(root);
    preOrderTraversal<int>(root);
    postOrderTraversal<int>(root);
}
