/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    ListNode *nxt = NULL, *prev = NULL, *curr = A;
    
    while( curr ) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        // doing curr->next as always would only end sol in d very beginning
        // next is stored in 'nxt'
        curr = nxt;
    }
    return prev;
}
