// 给你一个二叉搜索树的根节点 root ，返回树中任意两不同节点值之间的最小差值 。
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
private:
    int ans = INT_MAX;
    int pre = -1;
public:
    void dfs(TreeNode* node){
        if (node==nullptr) return;
        dfs(node->left);
        if (pre!=-1){
            ans = min(abs(node->val - pre), ans);
        }
        pre = node->val;
        dfs(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return ans;
    }
};