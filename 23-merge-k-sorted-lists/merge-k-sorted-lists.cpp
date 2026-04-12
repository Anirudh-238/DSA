#include <queue>
#include <vector>

using namespace std;

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
    // Custom comparator for the priority queue to make it a Min-Heap
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        // Push the head of each non-empty list into the heap
        for (auto list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!minHeap.empty()) {
            // Get the smallest node
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            // Add it to our merged list
            tail->next = smallest;
            tail = tail->next;

            // If there's a next node in that list, push it to the heap
            if (smallest->next) {
                minHeap.push(smallest->next);
            }
        }

        return dummy->next;
    }
};