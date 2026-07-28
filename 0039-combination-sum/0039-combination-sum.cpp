class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void solve(vector<int>& candidates, int target, int index) {

        // Found a valid combination
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        // Invalid path
        if (target < 0 || index == candidates.size())
            return;

        // Take current candidate
        curr.push_back(candidates[index]);
        solve(candidates, target - candidates[index], index);

        // Backtrack
        curr.pop_back();

        // Skip current candidate
        solve(candidates, target, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        solve(candidates, target, 0);
        return ans;
    }
};