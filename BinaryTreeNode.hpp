//
// Created by Nitish Mohan Shandilya on 7/4/20.
//

#include "GraphNode.hpp"

#ifndef PRACTICEEXERCISES_BINARYTREENODE_HPP
#define PRACTICEEXERCISES_BINARYTREENODE_HPP

template <typename dataType>
class BinaryTreeNode : public GraphNode<dataType> {
    const static int NUMBER_OF_CHILDREN = 2;
    const static int LEFT_CHILD_INDEX = 0;
    const static int RIGHT_CHILD_INDEX = 1;
public:
    BinaryTreeNode(const dataType inputData) :
        GraphNode<dataType> (inputData, NUMBER_OF_CHILDREN){
    }
    const BinaryTreeNode<dataType>* const getLeftChild() const {
        return (BinaryTreeNode<dataType>*)this->children[LEFT_CHILD_INDEX];
    }
    void setLeftChild(const BinaryTreeNode<dataType>* const leftChild) {
        this->children[LEFT_CHILD_INDEX] = leftChild;
    }
    const BinaryTreeNode<dataType>* const getRightChild() const {
        return (BinaryTreeNode<dataType>*)this->children[RIGHT_CHILD_INDEX];
    }
    void setRightChild(const BinaryTreeNode<dataType>* const rightChild) {
        this->children[RIGHT_CHILD_INDEX] = rightChild;
    }
};

#endif //PRACTICEEXERCISES_BINARYTREENODE_HPP
