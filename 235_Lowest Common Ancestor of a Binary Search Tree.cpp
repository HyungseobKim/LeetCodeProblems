/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val)
        {
            std::swap(p, q);
        }
        
        return LCA_rec(root, p, q);
    }
    
private:
    TreeNode* LCA_rec(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        
        const int val = node->val;
        
        if (val < p->val)
        {
            return LCA_rec(node->right, p, q);
        }
        
        if (val > q->val)
        {
            return LCA_rec(node->left, p, q);
        }
        
        return node;
    }
};