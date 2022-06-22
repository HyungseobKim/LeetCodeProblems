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
        if (root == nullptr)
        {
            return nullptr;
        }
        
        if (root == p)
        {
            pFound = true;
            
            if (qFound == false)
            {
                if (lowestCommonAncestor(root->left, p, q) == q)
                {
                    return root;
                }
                
                if (lowestCommonAncestor(root->right, p, q) == q)
                {
                    return root;
                }
            }
            
            return p;
        }
        
        if (root == q)
        {
            qFound = true;
            
            if (pFound == false)
            {
                if (lowestCommonAncestor(root->left, p, q) == p)
                {
                    return root;
                }
                
                if (lowestCommonAncestor(root->right, p, q) == p)
                {
                    return root;
                }
            }
            
            return q;
        }
        
        TreeNode* leftResult = lowestCommonAncestor(root->left, p, q);
        
        if (leftResult && leftResult != p && leftResult != q)
        {
            return leftResult;
        }
        
        if (leftResult == p)
        {
            if (qFound == false)
            {
                if (lowestCommonAncestor(root->right, p, q) == q)
                {
                    return root;
                }
            }
            
            return p;
        }
        
        if (leftResult == q)
        {
            if (pFound == false)
            {
                if (lowestCommonAncestor(root->right, p, q) == p)
                {
                    return root;
                }
            }
            
            return q;
        }
        
        return lowestCommonAncestor(root->right, p, q);
    }
    
private:
    bool pFound = false;
    bool qFound = false;
};