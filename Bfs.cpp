//
// Created by Nitish Mohan Shandilya on 7/6/20.
//

#include "GraphTraversalSimple.hpp"
#include "Queue.hpp"

template <typename dataType>
class Bfs : public GraphTraversalSimple<dataType> {
public:
    void printTraversal();
    void printTraversal(GraphNodeSimpleTraversal<dataType>* head);
};

template <typename dataType>
void Bfs<dataType>::printTraversal() {
    printTraversal(this->head);
}

template <typename dataType>
void Bfs<dataType>::printTraversal(GraphNodeSimpleTraversal<dataType>* head) {
    Queue<GraphNodeSimpleTraversal<dataType>*> queue;

    cout << head->data << endl;
    head->visited = true;
    queue.add(head);

    while (!queue.isEmpty()) {
        GraphNodeSimpleTraversal<dataType>* entry = queue.remove();
        for (const GraphNode<dataType>* child : entry->children) {
            GraphNodeSimpleTraversal<dataType>* derivedChild =
                dynamic_cast<GraphNodeSimpleTraversal<dataType>*> (
                    const_cast<GraphNode<dataType>* > (child));
            if (!derivedChild->visited) {
                cout << derivedChild->data << endl;
                queue.add(derivedChild);
            }
        }
    }
}

void testBfs() {
    Bfs<int> bfs;
    bfs.populateGraph();
    bfs.printTraversal();
}