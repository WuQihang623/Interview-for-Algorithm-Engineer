# include<vector>
# include<stack>
using namespace std;

// 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result = {};
        stack<TreeNode*> st;
        if (root == nullptr) return result;
        st.push(root);
        while(! st.empty()){
            TreeNode* node = st.top();
            result.push_back(node->val);  // 将当前节点的值放入结果中 
            st.pop();
            if (node->right != nullptr) st.push(node->right); // 先压栈右边的，这样右边的后出
            if (node->left != nullptr) st.push(node->left);
        }
        return result;
    }
};