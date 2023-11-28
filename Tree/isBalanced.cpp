# include<vector>
# include<stack>
# include<queue>
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


 // 查看所有节点的左子树和右子树的高度差是否小于等于1
class Solution {
public:
    int height(TreeNode* node){
        if (node == nullptr) return 0;
        return 1 +max(height(node->left), height(node->right));
    }
    bool isBalanced(TreeNode* root) {
        if (root==nullptr) return true;
        return (abs(height(root->left) - height(root->right)) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
};