/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node handles the case where the head needs to be removed
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move fast pointer so there's a gap of n between fast and slow
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        // Move both until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Skip the nth node
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        
        // Clean up memory (optional in LeetCode, but good practice)
        delete toDelete;
        
        ListNode* newHead = dummy->next;
        delete dummy;
        
        return newHead;
    }
};