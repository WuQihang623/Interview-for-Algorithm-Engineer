// 反转二叉树
// 交换左节点与右节点

# include<vector>
# include<stack>
# include<queue>
using namespace std;

// 给你二叉树的根节点 root ，使用迭代法返回它节点值的 前序 遍历。

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
    void inver(TreeNode* node){
        TreeNode* node_left = node->left;
        node->left = node->right;
        node->right = node_left;
        if (node->left) inver(node->left);
        if (node->right) inver(node->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        inver(root);
        return root;
    }
};

int main(){
    TreeNode* node = nullptr;
}