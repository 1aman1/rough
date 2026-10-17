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
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode resultHead(-1);
    ListNode *traverseResult = &resultHead;

    int carry = 0;

    while (l1 || l2 || carry)
    {
      int digit1 = l1 ? l1->val : 0;
      int digit2 = l2 ? l2->val : 0;

      int sum = digit1 + digit2 + carry;
      carry = (sum > 9) ? 1 : 0;

      traverseResult->next = new ListNode(sum % 10);
      traverseResult = traverseResult->next;

      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }

    return resultHead.next;
  }
};