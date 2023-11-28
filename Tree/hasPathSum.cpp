// 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。
//判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。
//如果存在，返回 true ；否则，返回 false 。
# include<vector>
# include<stack>
# include<queue>
# include<string>
# include<algorithm>
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
    void traval(TreeNode* node, int pathSum, vector<int>& vec_sum){
        if (node->left == nullptr && node->right == nullptr){
            vec_sum.push_back(pathSum+node->val);
            return ;
        }
        if (node->left) traval(node->left, pathSum+node->val, vec_sum);
        if (node->right) traval(node->right, pathSum+node->val, vec_sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root==nullptr) return false;
        vector<int> res;
        traval(root, 0, res);
        for (int i=0; i<res.size(); i++){
            if (targetSum == res[i]) return true;
        }
        return false;
    }
};