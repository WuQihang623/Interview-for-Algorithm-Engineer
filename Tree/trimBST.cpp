// 给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。
// 通过修剪二叉搜索树，使得所有节点的值在[low, high]中。
// 修剪树 不应该 改变保留在树中的元素的相对结构 (即，如果没有被移除，原有的父代子代关系都应当保留)。 
// 可以证明，存在 唯一的答案 。
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
    unordered_map<int, TreeNode*> fath_map;
public:
    void dfs(TreeNode* node, int low, int high, TreeNode* father, bool left){
        if (node==nullptr) return;
        if (node->val == low) node->left = nullptr;
        else if (node->val == high) node->right = nullptr;
        dfs(node->left, low, high, node, true);
        dfs(node->right, low, high, node, false);
        if (node->val < low){
            // 将右节点连接给上一个节点
            if (left)father->left = node->right;
            else father->right = node->right;
        }
        else if (node->val > high){
            // 将左节点连接给上一个节点
            if (!left) father->right = node->left;
            else father->left = node->left;
        }
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // 找到根节点
        while (root->val < low || root->val > high){
            if (root->val < low) root = root->right;
            else root = root->left;
            if (root==nullptr) return nullptr;
        }
        dfs(root, low, high, nullptr, true);
        return root;
    }
};

class Solution{
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return nullptr;
        if (root->val < low){
            return trimBST(root->right, low, high);
        }
        else if(root->val > high) {
            return trimBST(root->left, low, high);
        }
        else{
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }
    }
};