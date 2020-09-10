//
// Created by Nitish Mohan Shandilya on 9/10/20.
//

// Largest Item association
// Given pairs of associations, provide the
// largest group. The group should be sorted in
// lexicographic order. If conflicts, output the
// lexicographically smaller one

struct PairString {
    string first;
    string second;

    PairString(string first, string second) {
        this->first = first;
        this->second = second;
    }
};
class Solution {

    struct Node {
        string val;
        Node* parent;
        int rank;

        Node(const string& iVal) : val(iVal), parent(nullptr), rank(0) {}
    };

    unordered_map<string, Node*> strToNodeMap;

    void makeSet(string str) {
        auto it = strToNodeMap.find(str);
        if (it == strToNodeMap.end()) {
            Node* newNode = new Node(str);
            newNode->parent = newNode;
            strToNodeMap.emplace(str, newNode);
        }
    }

    Node* findSet(Node* node) {
        Node* parent = node->parent;
        if (parent == node)
            return parent;
        node->parent = findSet(node->parent);
        return node->parent;
    }

    void unionSets(string str1, string str2) {
        if (str1.empty() && str2.empty())
            return;
        if (str1.empty()) {
            insertSingleIntoLargestAssoc(strToNodeMap[str2]);
        } else if (str2.empty()) {
            insertSingleIntoLargestAssoc(strToNodeMap[str1]);
        } else {
            Node* node1 = strToNodeMap[str1];
            Node* node2 = strToNodeMap[str2];

            Node* parent1 = findSet(node1);
            Node* parent2 = findSet(node2);

            if (parent1->val == parent2->val)
                return;

            if (parent1->rank >= parent2->rank) {
                parent1->rank = (parent1->rank == parent2->rank) ? parent1->rank+1 :
                    parent1->rank;
                parent2->parent = parent1;
                insertPairIntoLargestAssoc(parent1, node2);
            } else {
                parent1->parent = parent2;
                insertPairIntoLargestAssoc(parent2, node1);
            }
        }
    }

    void insertSingleIntoLargestAssoc(Node* node) {
        auto it = largestAssoc.find(node);
        if (it == largestAssoc.end()) {
            largestAssoc.emplace(node, initializer_list<Node*>{node});
            largestAssocCount = max(largestAssocCount, 1);
        }
    }

    void insertPairIntoLargestAssoc(Node* parent, Node* node) {
        auto it = largestAssoc.find(parent);
        if (it == largestAssoc.end()) {
            largestAssoc.emplace(parent, initializer_list<Node*>{parent, node});
            largestAssocCount = max(largestAssocCount, 2);
        } else {
            largestAssoc[parent].push_back(node);
            int largestSize = largestAssoc[parent].size();
            largestAssocCount = max(largestAssocCount, largestSize);
        }
    }

    int largestAssocCount = 0;
    unordered_map<Node*, vector<Node*>> largestAssoc;

public:
    vector<string> findLargestItemAssociation(vector<PairString>& input) {
        vector<string> result;
        if (input.empty()) return result;

        for (PairString& pairStr : input) {
            makeSet(pairStr.first);
            makeSet(pairStr.second);
        }

        for (PairString& pairStr : input) {
            unionSets(pairStr.first, pairStr.second);
        }

        vector<vector<string>> resultBuffer;
        vector<string> buffer;
        for (auto assoc : largestAssoc) {
            if (assoc.second.size() == largestAssocCount) {
                vector<Node*> values = assoc.second;
                for (Node* value : values) {
                    buffer.emplace_back(value->val);
                }
                sort(buffer.begin(), buffer.end());
                resultBuffer.emplace_back(buffer);
                buffer.clear();
            }
        }
        sort(resultBuffer.begin(), resultBuffer.end());
        result = resultBuffer[0];
        resultBuffer.clear();
        return result;
    }
};

int main() {
    vector<PairString> input = {PairString("item1", "item2"), PairString("item2","item1"),
                                PairString("item3", ""), PairString("item4", ""), PairString("", ""),
                                PairString("item3", "") };
    Solution s;
    vector<string> result = s.findLargestItemAssociation(input);
    for (string& s : result)
        cout << s << endl;
}

