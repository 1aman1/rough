

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1 || !list2)
            return list1 ? list1 : list2;

        ListNode *current1 = list1;
        ListNode *current2 = list2;

        ListNode *newHead = nullptr;
        ListNode *tail = nullptr;

        if (list1->val < list2->val)
        {
            newHead = current1;
            current1 = current1->next;
        }
        else
        {
            newHead = current2;
            current2 = current2->next;
        }

        tail = newHead;

        while (current1 && current2)
        {
            if (current1->val < current2->val)
            {
                tail->next = current1;
                current1 = current1->next;
            }
            else
            {
                tail->next = current2;
                current2 = current2->next;
            }
            tail = tail->next;
        }
        if (current1)
            tail->next = current1;
        if (current2)
            tail->next = current2;

        return newHead;
    }
};