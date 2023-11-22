// 二叉树的层序遍历
// 层序遍历依赖队列完成

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

 class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while(!que.empty()){
            vector<int> sub_result;
            // 获取当前层中有几个节点
            int size = que.size();
            for (int i=0; i<size; i++){
                TreeNode* node = que.front();
                sub_result.push_back(node->val);
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(sub_result);
        }
    return result;
    }
 };