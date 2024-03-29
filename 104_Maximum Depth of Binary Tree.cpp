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
    int maxDepth(TreeNode* root) {
        maxDepth_rec(root, 0);
        
        return best;
    }
    
private:
    void maxDepth_rec(TreeNode* node, int depth)
    {
        if (node == nullptr)
        {
            if (depth > best)
            {
                best = depth;
            }
            
            return;
        }
        
        ++depth;
        
        maxDepth_rec(node->left, depth);
        maxDepth_rec(node->right, depth);
    }
    
private:
    int best = 0;
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        return maxDepth_rec(root, 0);
    }

private:
    int maxDepth_rec(TreeNode* node, int depth)
    {
        ++depth;

        if (node->left == nullptr && node->right == nullptr)
        {
            return depth;
        }

        int leftDepth = 0;

        if (node->left)
        {
            leftDepth = maxDepth_rec(node->left, depth);
        }

        int rightDepth = 0;

        if (node->right)
        {
            rightDepth = maxDepth_rec(node->right, depth);
        }

        return std::max(leftDepth, rightDepth);
    }
};