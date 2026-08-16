#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p -> val != q -> val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right,  q->right);
}

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node -> val = val;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

int main() {
    struct TreeNode* tree1 = newNode(1);
    tree1->left = newNode(2);
    tree1->right = newNode(3);

    struct TreeNode* tree2 = newNode(1);
    tree2->left = newNode(2);
    tree2->right = newNode(3);

    if (isSameTree(tree1, tree2)) {
        printf("The trees are the same.\n");
    } else {
        printf("The trees are different.\n");
    }

    free(tree1->left);
    free(tree1->right);
    free(tree1);
    free(tree2->left);
    free(tree2->right);
    free(tree2);
    return 0;
}