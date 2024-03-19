/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root)
        {
            invertTree_rec(root);
        }
        
        return root;
    }
    
private:
    void invertTree_rec(TreeNode* node)
    {
        std::swap(node->left, node->right);
        
        if (node->left)
        {
            invertTree(node->left);
        }
        
        if (node->right)
        {
            invertTree(node->right);
        }
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        invertTree_rec(root);
        return root;
    }

private:
    void invertTree_rec(TreeNode* node)
    {
        if (node == nullptr)
        {
            return;
        }

        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;

        invertTree_rec(node->left);
        invertTree_rec(node->right);
    }
};