#include<iostream>
using namespace std;
struct TNode {
    int data;
    TNode* left;
    TNode* right;
};


bool isLeaf(TNode* node) {
    return !node->left && !node->right;
}

int isSumTreeUtil(TNode* node) {
   
    if (node == NULL) return 0;
    if (isLeaf(node)) return node->data;

    int leftSum = isSumTreeUtil(node->left);
    int rightSum = isSumTreeUtil(node->right);

    if (leftSum == -1 || rightSum == -1) return -1; 

    
    if (node->data == leftSum + rightSum) {
       
        return node->data + leftSum + rightSum;
    }
    else {
       
        return -1;
    }
}


bool isSumTree(TNode* root) {
    return isSumTreeUtil(root) != -1;
}


int main() {
   
    TNode* root = new TNode{ 44, new TNode{9, new TNode{5, nullptr, nullptr}, new TNode{4, nullptr, nullptr}},
                                new TNode{13, new TNode{6, nullptr, nullptr}, new TNode{7, nullptr, nullptr}} };

    cout << "The tree is " << (isSumTree(root) ? "a sum tree." : "not a sum tree.") <<endl;

    
 

    return 0;
}
