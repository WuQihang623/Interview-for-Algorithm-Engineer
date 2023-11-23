// 获取二叉树的最小深度
# include<vector>
# include<stack>
# include<queue>
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
    int get_depth(TreeNode* node){
        if (node == nullptr) return 0;
        if(node->left == nullptr && node->right == nullptr) return 1;
        int depth_left = get_depth(node->left);
        int depth_right = get_depth(node->right);
        if (depth_left == 0) return 1 + depth_right;
        if (depth_right == 0) return 1 + depth_left;
        return 1 + min(depth_left, depth_right);
    }
    int minDepth(TreeNode* root) {
        return get_depth(root);
    }
};