// github.com/andy489

// https://www.hackerrank.com/contests/test4-sda-/challenges/challenge-1692

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *leftNode;
    Node *rightNode;

    Node(int d) {
        data = d;
        leftNode = NULL;
        rightNode = NULL;
    }
};

class Solution {
public:
    Node *insert(Node *root, int data) {
        if (root == NULL)
            return new Node(data);
        else {
            Node *cur;
            if (data <= root->data) {
                cur = insert(root->leftNode, data);
                root->leftNode = cur;
            } else {
                cur = insert(root->rightNode, data);
                root->rightNode = cur;
            }
            return root;
        }
    }

    void leaves_odd(Node *root) {
        if (root->leftNode == nullptr && root->rightNode == nullptr) {
            if (root->data & 1)
                sum += root->data;
            return;
        }
        if (root->leftNode)
            leaves_odd(root->leftNode);
        if (root->rightNode)
            leaves_odd(root->rightNode);
    }

    void leaves(Node *root) {
        leaves_odd(root);
        cout << sum << '\n';
    }

private:
    int sum = 0;
}; //End of Solution

int main() {
    Solution myTree;
    Node *root = NULL;

    int t, data;
    cin >> t;

    while (t--) {
        cin >> data;
        root = myTree.insert(root, data);
    }
    return myTree.leaves(root), 0;
}
