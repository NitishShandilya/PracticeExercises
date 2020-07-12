//
// Created by Nitish Mohan Shandilya on 7/6/20.
//

#include "GraphTraversalSimple.hpp"

template <typename dataType>
class Dfs : public GraphTraversalSimple<dataType> {
public:
    void printTraversal();
    void printTraversal(GraphNodeSimpleTraversal<dataType>* head);
};

template <typename dataType>
void Dfs<dataType>::printTraversal() {
    printTraversal(this->head);
}

template <typename dataType>
void Dfs<dataType>::printTraversal(GraphNodeSimpleTraversal<dataType>* head) {

    if (head!= nullptr) {
        cout << head->data << endl;
        head->visited = true;
        for (const GraphNode<dataType>* child : head->children) {
            GraphNodeSimpleTraversal<dataType>* childSimpleTraversal =
                dynamic_cast<GraphNodeSimpleTraversal<dataType>*>(
                    const_cast<GraphNode<dataType>*> (child));
            if (!childSimpleTraversal->visited)
                printTraversal(childSimpleTraversal);
        }
    }
}

void testDfs() {
    Dfs<int> dfs;
    dfs.populateGraph();
    dfs.printTraversal();
}