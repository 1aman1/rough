class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode dummyHead(0, head);

        ListNode *slow = &dummyHead;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->next;
    }
};