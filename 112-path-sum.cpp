// https://leetcode.com/problems/path-sum/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * Found better solution online:
class Solution
{
    public:
        bool hasPathSum(TreeNode* root, int sum)
        {
            if(root == NULL){
                return false;
            }
            int newsum = sum - root->val;
            if(root->left == NULL && root->right == NULL){
                return newsum == 0;
            }
            return hasPathSum(root->left, newsum) || hasPathSum(root->right, newsum);
        }
};
*/

class Solution
{
    private:
        int target = 0;
        bool findPathSum(TreeNode* root, int current)
        {
            bool ret = false;
            current += root->val;

            if (root->left == NULL && root->right == NULL)
                return current == target;

            if (root->left != NULL)
                ret = findPathSum(root->left, current);
            if (root->right != NULL)
                ret = ret ? ret : findPathSum(root->right, current);

            return ret;
        }

    public:
        bool hasPathSum(TreeNode* root, int sum)
        {
            if (root == NULL)
                return false;

            target = sum;

            return findPathSum(root, 0);
        }
};