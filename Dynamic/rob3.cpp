# include<vector> 
# include<unordered_map>
using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 如果抢该节点，则不抢子节点，如果抢子节点则不抢该节点
// 考虑后序遍历
class Solution {
public:
    
    int rob(TreeNode* root) {
        if (root==nullptr) return 0;
        if (root->left==nullptr && root->right==nullptr) return root->val;

        // 偷父节点
        int val1 = root->val;
        if (root->left) val1 += rob(root->left->left) + rob(root->left->right);
        if (root->right) val1 += rob(root->right->left) + rob(root->right->right);

        // 偷子节点
        int val2 = rob(root->left) + rob(root->right);
        return max(val1, val2);
    }
};

//我们计算了root的四个孙子（左右孩子的孩子）为头结点的子树的情况
// 又计算了root的左右孩子为头结点的子树的情况
// 计算左右孩子的时候其实又把孙子计算了一遍

// 记忆化递归
class Solution {
public:
    unordered_map<TreeNode* , int> umap; // 记录计算过的结果
    int rob(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return root->val;
        if (umap[root]) return umap[root]; // 如果umap里已经有记录则直接返回
        // 偷父节点
        int val1 = root->val;
        if (root->left) val1 += rob(root->left->left) + rob(root->left->right); // 跳过root->left
        if (root->right) val1 += rob(root->right->left) + rob(root->right->right); // 跳过root->right
        // 不偷父节点
        int val2 = rob(root->left) + rob(root->right); // 考虑root的左右孩子
        umap[root] = max(val1, val2); // umap记录一下结果
        return max(val1, val2);
    }
};