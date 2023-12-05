// 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。

# include<unordered_map>
# include<vector>
# include<stack>
# include<queue>
# include<string>
# include<algorithm>
# include<unordered_map>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    TreeNode* buildBST(vector<int>& nums, int left, int right){
        if (left > right) return nullptr;
        int middle = (left + right) / 2; 
        TreeNode* node = new TreeNode(nums[middle]);
        node->left = buildBST(nums, left, middle-1);
        node->right = buildBST(nums, middle+1, right);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        int root_idx = nums.size() / 2;
        TreeNode* root = buildBST(nums, 0, nums.size()-1);
        return root;
    }
};