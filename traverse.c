#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void traverse (struct TreeNode* root, int* arr, int*returnSize) {
    if(root->left) traverse(root->left, arr, returnSize);
    arr[(*returnSize)++] = root->val;
    if(root->right) traverse(root->right, arr, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int capacity = 100;
    int *arr = malloc(capacity * sizeof(int));
    if(!arr) {
        fprintf(stderr,"内存分配失败\n");
        exit(1);
    }
    *returnSize = 0;
    if(root) traverse(root, arr, returnSize);

    arr = realloc(arr, (*returnSize)*sizeof(int));
    return arr;
}

struct TreeNode* createNode(int v) {
    struct TreeNode* node = malloc(sizeof(*node));
    if (!node) {
        fprintf(stderr, "内存分配失败\n");
        exit(1);
    }
    node->val = v;
    node->left = node->right = NULL;
    return node;
}

// —— 释放整棵树的内存 ————————————————————————
void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// —— 主函数：构造测试树、调用遍历并打印 —————————
int main(void) {
    // 构造一棵测试二叉搜索树：
    //           4
    //         /   \
    //        2     6
    //       / \   / \
    //      1   3 5   7
    struct TreeNode* root = createNode(4);
    root->left  = createNode(2);
    root->right = createNode(6);
    root->left->left  = createNode(1);
    root->left->right = createNode(3);
    root->right->left  = createNode(5);
    root->right->right = createNode(7);

    // 调用中序遍历
    int size;
    int *result = inorderTraversal(root, &size);

    // 打印结果
    printf("中序遍历结果（升序输出）：");
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // 清理内存
    free(result);
    freeTree(root);

    return 0;
}