class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void dfs(TreeNode* root) {
        if (!root) return;

        if (root->left) {
            parent[root->left] = root;
            dfs(root->left);
        }

        if (root->right) {
            parent[root->right] = root;
            dfs(root->right);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        parent[root] = nullptr;   // Root has no parent
        dfs(root);

        unordered_set<TreeNode*> ancestors;

        while (p) {
            ancestors.insert(p);
            p = parent[p];
        }

        while (q) {
            if (ancestors.count(q))
                return q;
            q = parent[q];
        }

        return nullptr;
    }
};