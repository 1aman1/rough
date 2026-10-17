/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{

    ListNode *getOneNodeBeforeMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        fast = fast->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *Next = nullptr;

        while (curr)
        {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }

        return prev;
    }

    void interLeave(ListNode *head, ListNode *head2)
    {
        ListNode *trav1 = head;
        ListNode *trav2 = head2;

        while (trav1 && trav2)
        {
            ListNode *holdNextForList1 = trav1->next;
            ListNode *holdNextForList2 = trav2->next;

            trav2->next = trav1->next;
            trav1->next = trav2;

            trav1 = holdNextForList1;
            trav2 = holdNextForList2;
        }
    }

public:
    void reorderList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return;

        ListNode *preMiddle = getOneNodeBeforeMiddle(head);

        ListNode *middle = preMiddle->next;
        preMiddle->next = nullptr;

        ListNode *head2 = reverseList(middle);

        interLeave(head, head2);
    }
};