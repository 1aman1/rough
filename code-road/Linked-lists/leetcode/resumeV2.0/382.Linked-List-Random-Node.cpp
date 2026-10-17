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
class Solution {
private:
    ListNode* head;
    
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int count = 0;
        int result = 0;
        
        for (ListNode* current = head; current != nullptr; current = current->next) {
            count++;
            
            // Reservoir Sampling: probability of selecting current node is 1/count
            int randomIndex = 1 + rand() % count;
            if (randomIndex == count) {
                result = current->val;
            }
        }
        
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */