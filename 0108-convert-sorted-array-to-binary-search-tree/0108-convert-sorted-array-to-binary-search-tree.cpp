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
    TreeNode* CreateNode(vector<int>& nums, int s, int e)
    {
        if (s > e)
            return nullptr;
        int m = (s + e) / 2;
        TreeNode* n = new TreeNode(nums[m], CreateNode(nums, s, m-1), CreateNode(nums, m+1, e));
        return n;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return CreateNode(nums, 0, nums.size() - 1);
    }
};