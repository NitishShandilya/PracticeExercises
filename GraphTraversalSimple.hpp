//
// Created by Nitish Mohan Shandilya on 7/6/20.
//

#ifndef PRACTICEEXERCISES_GRAPHTRAVERSALSIMPLE_HPP
#define PRACTICEEXERCISES_GRAPHTRAVERSALSIMPLE_HPP

#include "GraphNodeSimpleTraversal.hpp"

template <typename dataType>
class GraphTraversalSimple {
public:
    vector<GraphNodeSimpleTraversal<dataType>*> nodes;
    GraphNodeSimpleTraversal<dataType>* head;

    GraphTraversalSimple() : head(nullptr) {}
    virtual ~GraphTraversalSimple() = default;

    void populateGraph();

};

template <>
void GraphTraversalSimple<int>::populateGraph() {
    GraphNodeSimpleTraversal<int>* n1 = new GraphNodeSimpleTraversal<int>(1);
    GraphNodeSimpleTraversal<int>* n2 = new GraphNodeSimpleTraversal<int>(2);
    GraphNodeSimpleTraversal<int>* n3 = new GraphNodeSimpleTraversal<int>(3);
    GraphNodeSimpleTraversal<int>* n4 = new GraphNodeSimpleTraversal<int>(4);
    GraphNodeSimpleTraversal<int>* n5 = new GraphNodeSimpleTraversal<int>(5);
    GraphNodeSimpleTraversal<int>* n6 = new GraphNodeSimpleTraversal<int>(6);

    n1->children.push_back(n2);
    n1->children.push_back(n3);
    n1->children.push_back(n4);
    n2->children.push_back(n5);
    n5->children.push_back(n6);

    head = n1;
    vector<GraphNodeSimpleTraversal<int>*> tempVector =
        {n1, n2, n3, n4, n5, n6};
    nodes.insert(nodes.begin(), tempVector.begin(), tempVector.end());
}

#endif //PRACTICEEXERCISES_GRAPHTRAVERSALSIMPLE_HPP
