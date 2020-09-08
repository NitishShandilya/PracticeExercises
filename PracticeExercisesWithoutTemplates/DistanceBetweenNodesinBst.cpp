//
// Created by Nitish Mohan Shandilya on 9/2/20.
// https://leetcode.com/discuss/interview-question/376375/
// Find LCA and return the distances between them

using namespace std;

class BST {
    struct Node {
        int val;
        Node* left;
        Node* right;
        Node(int iVal) : val(iVal), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;

    Node* insertIntoBST(int value, Node* root) {
        if (!root)
            return new Node(value);
        if (value < root->val)
            root->left = insertIntoBST(value, root->left);
        else
            root->right = insertIntoBST(value, root->right);
        return root;
    }

    Node* findLcaRec(Node* root, int val1, int val2) {
        if (root->val < val1 && root->val < val2)
            return findLcaRec(root->right, val1, val2);
        else if (root->val > val1 && root->val > val2)
            return findLcaRec(root->left, val1, val2);
        else
            return root;
    }

    Node* findLca(int val1, int val2) {
        return findLcaRec(root, val1, val2);
    }

    int findDistance(Node* lca, int value) {
        if (!lca) return -1;
        int distance = 0;
        while (lca) {
            if (lca->val < value) {
                ++distance;
                lca = lca->right;
            }
            else if (lca->val > value) {
                ++distance;
                lca = lca->left;
            } else {
                break;
            }
        }
        return distance;
    }

public:
    void makeBST(vector<int>& values) {
        for (int value : values)
            root = insertIntoBST(value, root);
    }

    int findDistance(int val1, int val2) {
        Node* lca = findLca(val1, val2);
        return findDistance(lca, val1) + findDistance(lca, val2);
    }
};
int main() {
    vector<int> values = {5,7,3,6,4,8,1};
    BST bst;
    bst.makeBST(values);
    int val1 = 4, val2 = 8;
    cout << bst.findDistance(val1, val2);
}
