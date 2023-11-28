// 给你二叉树的根节点 root 和一个整数目标和 targetSum
// 找出所有从根节点到叶子节点 路径总和等于给定目标和的路径。

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
    void travel(TreeNode* node, int targetSum, int pathSum, vector<int>& path, vector<vector<int>>& res){
        path.emplace_back(node->val);
        pathSum += node->val;
        if (node->left==nullptr && node->right==nullptr){
            if (pathSum == targetSum) res.emplace_back(path);
            return ;
        }
        if (node->left){
            travel(node->left, targetSum, pathSum, path, res);
            path.pop_back();
        }
        if (node->right) {
            travel(node->right, targetSum, pathSum, path, res);
            path.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        if (root==nullptr) return result;
        travel(root, targetSum, 0, path, result);
        return result;
    }
};