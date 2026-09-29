class Solution {
public:
        vector<vector<int>> solution;
    void dfs(vector<int>& nums, int i, vector<int> currList, int total, int target) {
        if (total == target) {
            solution.push_back(currList);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            if (total + nums[j] > target) {
                return;
            }
            currList.push_back(nums[j]);
            dfs(nums, j, currList, total+nums[j], target);
            currList.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0, {}, 0, target);
        return solution;

    }
};
