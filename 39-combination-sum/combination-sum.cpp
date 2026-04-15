#include <vector>

using namespace std;

class Solution {
public:
    void backtrack(int index, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
        // Base Case: Success
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        // Base Case: Failure
        if (target < 0 || index >= candidates.size()) {
            return;
        }

        // Decision 1: Include candidates[index]
        current.push_back(candidates[index]);
        // Note: we stay at 'index' because we can reuse the same number
        backtrack(index, target - candidates[index], candidates, current, result);
        
        // Backtrack: Remove the number before trying the next decision
        current.pop_back();

        // Decision 2: Skip candidates[index] and move to the next
        backtrack(index + 1, target, candidates, current, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, target, candidates, current, result);
        return result;
    }
};
