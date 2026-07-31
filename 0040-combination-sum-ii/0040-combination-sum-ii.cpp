class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void solve(vector<int>& candidates, int target, int start) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicate numbers
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // No need to continue (array is sorted)
            if (candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            // Move to next index (cannot reuse same element)
            solve(candidates, target - candidates[i], i + 1);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        solve(candidates, target, 0);

        return ans;
    }
};  