// 获取二叉树的最大深度
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
        if (node==nullptr) return 0;
        int depth_left = get_depth(node->left);
        int depth_right = get_depth(node->right);
        return 1 + max(depth_left, depth_right);
    }
    int maxDepth(TreeNode* root) {
        
        return get_depth(root);
    }
};