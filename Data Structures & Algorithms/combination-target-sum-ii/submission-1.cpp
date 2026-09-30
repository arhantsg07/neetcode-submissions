class Solution {
public:
    vector<vector<int>> cst;
    void dfs(vector<int>& candidates, int idx, vector<int> curr, int total, int target) {
        if (total == target) {
            cst.push_back(curr);
            return;
        }
        int n = candidates.size()-1;
        if (idx > n || total > target) {
            return;
        }
        curr.push_back(candidates[idx]);
        dfs(candidates, idx+1, curr, total+candidates[idx], target);
        curr.pop_back();

        while (idx + 1 < candidates.size()&& candidates[idx] == candidates[idx+1]) {
            idx++;
        }
        dfs(candidates, idx+1, curr, total, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, {}, 0, target);
        return cst;
    }
};
