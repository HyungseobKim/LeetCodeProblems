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
        if (q->val < p->val)
        {
            return LCA_rec(root, q, p);
        }
        return LCA_rec(root, p, q);
    }

private:
    TreeNode* LCA_rec(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if (q->val < node->val)
        {
            return LCA_rec(node->left, p, q);
        }

        if (p->val > node->val)
        {
            return LCA_rec(node->right, p, q);
        }

        return node;
    }
};

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
        bool b1 = false;
        bool b2 = false;
        return LCA_rec(root, p, q, b1, b2);
    }
// General solution for Binary Tree (not Binary search tree).
private:
    TreeNode* LCA_rec(TreeNode* node, TreeNode* p, TreeNode* q, bool& pFound, bool& qFound)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (pFound)
        {
            // q is found. We can finish the search.
            if (node == q)
            {
                qFound = true;
            }
            else
            {
                LCA_rec(node->left, p, q, pFound, qFound);

                // If q was found in the left subtree, we don't need to go into the right.
                if (qFound == false)
                {
                    LCA_rec(node->right, p, q, pFound, qFound);
                }
            }
            
            // No matter we succeeded finding q, we don't know where p was found, so return nullptr.
            return nullptr;
        }

        if (qFound)
        {
            // p is found. We can finish the search.
            if (node == p)
            {
                pFound = true;
            }
            else
            {
                LCA_rec(node->left, p, q, pFound, qFound);

                // If p was found in the left subtree, we don't need to go into the right.
                if (pFound == false)
                {
                    LCA_rec(node->right, p, q, pFound, qFound);
                }
            }

            // No matter we succeeded finding p, we don't know where p was found, so return nullptr.
            return nullptr;
        }

        // We couldn't find any of p and q before this node.

        // Case 1: "node" is p
        if (node == p)
        {
            pFound = true;

            // Case 1-1: q was under "node" = "node" is LCA
            LCA_rec(node->left, p, q, pFound, qFound);

            if (qFound)
            {
                return node;
            }

            LCA_rec(node->right, p, q, pFound, qFound);

            if (qFound)
            {
                return node;
            }

            // Case 1-2: "node"'s sibilings or their subtrees have q
            return nullptr;
        }

        // Case 2: "node" is q
        if (node == q)
        {
            qFound = true;

            // Case 2-1: p was under "node" = "node" is LCA
            LCA_rec(node->left, p, q, pFound, qFound);

            if (pFound)
            {
                return node;
            }

            LCA_rec(node->right, p, q, pFound, qFound);

            if (pFound)
            {
                return node;
            }

            // Case 2-2: "node"'s sibilings or their subtrees have p
            return nullptr;
        }

        // Case 3: one of left and right of this node has both p and q = result is LCA
        TreeNode* result = LCA_rec(node->left, p, q, pFound, qFound);

        if (result)
        {
            return result;
        }

        result = LCA_rec(node->right, p, q, pFound, qFound);

        if (result)
        {
            return result;
        }

        // Case 4: both p and q are found but LCA wasn't specified
        // = left has one of p and q and right has the other
        // = this node is LCA
        if (pFound && qFound)
        {
            return node;
        }

        // We got nothing here.
        return nullptr;
    }
};


/*
	The soultion for general binary trees. (not binary search tree).
*/
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
            return root;
        }

        if (root == p)
        {
            found_p = true;
            if (found_q)
            {
                return root;
            }

            lowestCommonAncestor(root->left, p, q);
            if (found_q)
            {
                ancestor = root;
                return root;
            }

            lowestCommonAncestor(root->right, p, q);
            if (found_q)
            {
                ancestor = root;
                return root;
            }

            return root;
        }

        if (root == q)
        {
            found_q = true;
            if (found_p)
            {
                return root;
            }

            lowestCommonAncestor(root->left, p, q);
            if (found_p)
            {
                ancestor = root;
                return root;
            }

            lowestCommonAncestor(root->right, p, q);
            if (found_p)
            {
                ancestor = root;
                return root;
            }

            return root;
        }

        const bool previously_found_one = found_p || found_q;

        lowestCommonAncestor(root->left, p, q);
        if (ancestor)
        {
            return ancestor;
        }

        lowestCommonAncestor(root->right, p, q);
        if (ancestor)
        {
            return ancestor;
        }

        if (previously_found_one == false && (found_p && found_q))
        {
            ancestor = root;
        }

        return root;
    }
private:
    bool found_p = false;
    bool found_q = false;
    TreeNode* ancestor = nullptr;
};