#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// struct ListNode* mergeTwoLists (struct ListNode* list1, struct ListNode* list2) {
//     struct ListNode dummy;
//     dummy.val = -1;
//     dummy.next = NULL;

//     struct ListNode* current = &dummy;

//     while(list1 != NULL && list2 != NULL) {
//         if (list1 -> val <= list2 -> val) {
//             current -> next = list1;
//             list1 = list1 -> next;
//         } else {
//             current -> next = list2;
//             list2 = list2 -> next;
//         }
//         current = current -> next;
//     }
//     current -> next = (list1 == NULL) ? list2 : list1;
//     return dummy.next;
// }

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* res;

    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    if(list1 -> val <= list2 -> val) {
        res = list1;
        res -> next = mergeTwoLists (list1 -> next, list2);
    } else {
        res = list2;
        res -> next = mergeTwoLists (list1, list2 -> next);
    }
    return res;
}

void printList (struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head -> val);
        head = head -> next;
    }
    printf("NULL\n");
}

struct ListNode* createNode (int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node -> val = val;
    node -> next = NULL;
    return node;
}

int main(void) {
    struct ListNode* list1 = createNode(1);
    list1 -> next = createNode(3);
    list1 -> next -> next = createNode(5);

    struct ListNode* list2 = createNode(2);
    list2 -> next = createNode(4);
    list2 -> next -> next = createNode(6);

    printf("List 1: ");
    printList(list1);
    printf("List2 :");
    printList(list2);

    struct ListNode* merged = mergeTwoLists(list1,list2);
    printf("Merged List: ");
    printList(merged);

    while (merged != NULL) {
        struct ListNode* temp = merged;
        merged = merged -> next;
        free(temp);
    }
    return 0;
}