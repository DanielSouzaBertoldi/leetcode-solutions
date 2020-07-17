/******************************************************************************

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

- Results (as of 2020-07-17):

* Iterative
Runtime: 4 ms (beats 76.60% of C submissions)
Memory Usage: 6 MB (beats 59.09% of C submissions)

*******************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* reverseList(struct ListNode* head){
    // Iteratively
    struct ListNode *next = NULL, *previous = NULL, *current = head;
    while(current) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}
