//
// Created by Nitish Mohan Shandilya on 7/6/20.
//

#include "GraphNode.hpp"

#ifndef PRACTICEEXERCISES_GRAPHNODESIMPLETRAVERSAL_HPP
#define PRACTICEEXERCISES_GRAPHNODESIMPLETRAVERSAL_HPP

template <typename dataType>
class GraphNodeSimpleTraversal : public GraphNode<dataType> {
public:
    bool visited;

    GraphNodeSimpleTraversal(const dataType inputData) :
        GraphNode<dataType>(inputData), visited(false)
    {}
};

#endif //PRACTICEEXERCISES_GRAPHNODESIMPLETRAVERSAL_HPP
