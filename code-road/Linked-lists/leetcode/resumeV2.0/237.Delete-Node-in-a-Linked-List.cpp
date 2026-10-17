/* Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *NextNode;
     ListNode(int x) : val(x), NextNode(NULL) {}
 };
//*/

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }
};