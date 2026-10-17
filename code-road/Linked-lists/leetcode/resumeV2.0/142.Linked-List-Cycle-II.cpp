/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
        {
            return nullptr;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                ListNode *ptrFromHead = head;

                while (slow != ptrFromHead)
                {
                    slow = slow->next;
                    ptrFromHead = ptrFromHead->next;
                }

                return ptrFromHead;
            }
        }

        return nullptr;
    }
};