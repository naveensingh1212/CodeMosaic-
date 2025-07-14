class Solution {
private:
    int findmaxdiff(TreeNode* root, int minv, int maxv) {
        if (root == nullptr) {
            return abs(maxv - minv);
        }
        
        minv = min(minv, root->val);
        maxv = max(maxv, root->val);
        
        int l = findmaxdiff(root->left, minv, maxv);
        int r = findmaxdiff(root->right, minv, maxv);
        
        return max(l, r);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        return findmaxdiff(root, root->val, root->val);  // 🔥 key fix
    }
};
