ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* head = A;
 
    while(A -> next ) {
        if(A -> val == A -> next -> val) {
            ListNode* tmp = A -> next;
            while(tmp -> val == A -> val && tmp -> next != NULL) {
                tmp = tmp -> next;
            }
            // if the ptr couldnt move anyfurther with same adjacent values
            if(tmp -> val == A -> val) {
                A -> next = NULL;
                break;
            //otherwise update A's ptr with skipped nodes
            } else {
                A -> next = tmp;
            }
        }
        A = A -> next;
    }
    return head;
}
