#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int k = 0; // Pointer for the next position of a non-target element
        
        for (int i = 0; i < nums.size(); i++) {
            // If current element is NOT the value we want to remove
            if (nums[i] != val) {
                nums[k] = nums[i]; // Move it to the 'k-th' position
                k++; // Increment k to prepare for the next non-target element
            }
        }
        
        // k represents the number of elements not equal to val
        return k;
    }
};