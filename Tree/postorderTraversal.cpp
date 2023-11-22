# include<vector>
# include<stack>
# include<algorithm>
using namespace std;

// 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
// 左-》右-》中

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            result.push_back(cur->val);
            st.pop();
            if (cur->left) st.push(cur->left);
            if (cur->right) st.push(cur->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    vector<int> postorderTraversal(TreeNode* root){
        vector<int> result;
        stack<TreeNode*> st;
        if (root != nullptr) st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            if (node!=nullptr){
                // 入栈的顺序，中 右 左
                st.push(nullptr);
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
            }
            else{
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};