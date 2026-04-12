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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Check if there are at least k nodes left
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            if (!curr) return head; // Less than k nodes, leave as is
            curr = curr->next;
        }

        // Step 2: Reverse k nodes
        ListNode* prev = nullptr;
        ListNode* nextNode = nullptr;
        curr = head;
        for (int i = 0; i < k; i++) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Recurse for the next group
        // 'head' is now the tail of the reversed group
        // 'prev' is the new head of the reversed group
        if (nextNode != nullptr) {
            head->next = reverseKGroup(nextNode, k);
        }

        return prev;
    }
};