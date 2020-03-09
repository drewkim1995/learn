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
        bool dfs(TreeNode* node, int sum)
        {
            sum -= node->val;

            if (sum == 0 && node->left == NULL && node->right == NULL)
                return true;
            if (node->left != NULL && dfs(node->left, sum))
                return true;
            if (node->right != NULL && dfs(node->right, sum))
                return true;
            return false;
        }
    public:
        bool hasPathSum(TreeNode* root, int sum)
        {
            if (root == NULL)
                return false;
            return dfs(root, sum);
        }
};