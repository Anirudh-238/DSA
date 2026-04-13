#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        // Edge case: if the array is empty
        if (nums.empty()) return 0;

        int i = 0; // Pointer for the last unique element

        for (int j = 1; j < nums.size(); j++) {
            // If we find a new unique element
            if (nums[j] != nums[i]) {
                i++; // Move the unique pointer forward
                nums[i] = nums[j]; // Update the next unique position
            }
        }

        // Return the count of unique elements (index + 1)
        return i + 1;
    }
};
