//
// Created by Nitish Mohan Shandilya on 7/4/20.
//

#include "GraphNode.hpp"
#include "BinaryTreeNode.hpp"

enum class TypeOfNode {BINARY_TREE_NODE, TERNARY_TREE_NODE};

template <typename dataType>
class NodeFactory {
public:
    static GraphNode<dataType>* createNode(
        const dataType inputData, TypeOfNode typeOfNode) {
        //if (numberOfChildren <=0)
            //throwParameterIllegalException -> Also look for Uint
        if (typeOfNode == TypeOfNode::BINARY_TREE_NODE)
            return new BinaryTreeNode<dataType>(inputData);
    }
};
