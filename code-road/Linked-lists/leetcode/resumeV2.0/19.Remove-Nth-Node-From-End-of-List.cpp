class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int k)
    {
        ListNode dummyHead(-1, head);
        ListNode *slow = &dummyHead;
        ListNode *fast = &dummyHead;

        while (k--)
        {
            fast = fast->next;
        }

        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *deletionCandidate = slow->next;
        slow->next = deletionCandidate->next;
        delete deletionCandidate;

        return dummyHead.next;
    }
};
