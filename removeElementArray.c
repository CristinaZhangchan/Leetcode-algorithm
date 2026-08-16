#include <stdio.h>
#include <stdlib.h>

struct  ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* temp = head;

    while(temp && temp->next){
        if(temp->next->val == temp->val){
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
    return head;
}
struct ListNode* createNode(int v) {
    struct ListNode* node = malloc(sizeof(*node));
    node->val = v;
    node->next = NULL;
    return node;
}

// Utility: append a value to the end of the list; returns head
struct ListNode* append(struct ListNode* head, int v) {
    struct ListNode* node = createNode(v);
    if (!head) return node;
    struct ListNode* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
    return head;
}

// Utility: print all values in the list
void printList(struct ListNode* head) {
    struct ListNode* cur = head;
    while (cur) {
        printf("%d", cur->val);
        if (cur->next) printf(" -> ");
        cur = cur->next;
    }
    printf("\n");
}

// Utility: free all nodes in the list
void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* nxt = head->next;
        free(head);
        head = nxt;
    }
}

int main(void) {
    // Build a test list: 1 -> 1 -> 2 -> 3 -> 3 -> 4
    int values[] = {1, 1, 2, 3, 3, 4};
    int n = sizeof(values) / sizeof(values[0]);
    struct ListNode* head = NULL;
    for (int i = 0; i < n; i++) {
        head = append(head, values[i]);
    }

    printf("Original list: ");
    printList(head);

    head = deleteDuplicates(head);

    printf("After deleteDuplicates: ");
    printList(head);

    freeList(head);
    return 0;
}