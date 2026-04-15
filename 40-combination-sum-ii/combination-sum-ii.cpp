#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void backtrack(int index, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            // Pruning: if the current number is greater than target, 
            // no need to check further numbers (since they are sorted)
            if (candidates[i] > target) break;

            // Skip duplicate elements to ensure unique combinations
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            current.push_back(candidates[i]);
            // Move to i + 1 because each number can only be used once
            backtrack(i + 1, target - candidates[i], candidates, current, result);
            current.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, target, candidates, current, result);
        return result;
    }
};