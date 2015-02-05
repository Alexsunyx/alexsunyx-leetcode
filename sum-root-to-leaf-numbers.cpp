/**
 *  Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *
 *  An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *
 *  Find the total sum of all root-to-leaf numbers.
 *
 *  For example,
 *
 *     1
 *    / \
 *   2   3
 *  The root-to-leaf path 1->2 represents the number 12.
 *  The root-to-leaf path 1->3 represents the number 13.
 *
 *  Return the sum = 12 + 13 = 25.
 */

 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int doSum(TreeNode *root, int value) {
        if(root == NULL)
            return 0;
        int result = value * 10 + root->val;
        int left = 0, right = 0;
        if(root->left == NULL && root->right == NULL)
            return result;
        if(root->left != NULL)
            left = doSum(root->left, result);
        if(root->right != NULL)
            right = doSum(root->right, result);
        return left + right;
    }

    int sumNumbers(TreeNode *root) {
        return doSum(root, 0);
    }
};