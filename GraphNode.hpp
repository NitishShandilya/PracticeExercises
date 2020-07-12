//
// Created by Nitish Mohan Shandilya on 7/3/20.
//

#ifndef PRACTICEEXERCISES_GRAPHNODE_HPP
#define PRACTICEEXERCISES_GRAPHNODE_HPP

template <typename dataType>
class GraphNode {
public:
    dataType data;
    vector<const GraphNode*> children;
protected:
    GraphNode(const dataType inputData, const int numberOfChildren) : data(inputData) {
        children.reserve(numberOfChildren);
        for (int childIndex=0; childIndex< numberOfChildren; childIndex++)
            children[childIndex] = NULL;
    }
    GraphNode(const dataType inputData) : data(inputData) {
    }
public:
    virtual ~GraphNode() = default;
};

#endif //PRACTICEEXERCISES_GRAPHNODE_HPP
