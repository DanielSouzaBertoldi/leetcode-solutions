/******************************************************************************

Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.

--Results (as of 2020-07-17) :

Runtime: 0 ms (beats 100% of C submissions)
Memory Usage: 5.4 MB (beats 91.75% of C submissions)
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

void append(ListNode **head, ListNode **tail, int data) {
    ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));

    if(!newNode) {
        printf("Unable to locate memory.");
        return;
    }

    newNode->val = data;
    newNode->next = NULL;

    if(!*head) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void printList(ListNode *head) {
    ListNode *temp = head;

    while(temp) {
        printf("%d - ", temp->val);
        temp = temp->next;
    }
}


/* The actual function from the Leet Code challenge. */
ListNode* swapPairs(ListNode *head) {
    if(head && head->next) {
        ListNode *temp = head->next;
        ListNode *temp2 = temp->next;
        temp->next = head;
        head->next = swapPairs(temp2);
        return temp;
    } else
        return head;
}

int main() {
    ListNode *head = NULL;
    ListNode *tail = NULL;
    
    append(&head, &tail, 1);
    append(&head, &tail, 2);
    append(&head, &tail, 3);
    append(&head, &tail, 4);

    // Before swapping pairs
    printList(head);
    printf("\n");
    swapPairs(head);
    printList(head); // After swapping pairs

    return 0;
}
