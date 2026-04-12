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
    ListNode* swapPairs(ListNode* head) {
        // If list is empty or has only one node, nothing to swap
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (prev->next && prev->next->next) {
            // Nodes to be swapped
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Swapping
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move 'prev' pointer two nodes ahead for the next pair
            prev = first;
        }

        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return newHead;
    }
};