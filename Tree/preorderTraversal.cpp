# include<vector>
# include<stack>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        while(!st.empty() || cur != nullptr){
            result.push_back(cur->val);
            st.push(cur);
            cur = cur->left;
            while(cur==nullptr && !st.empty()){
                cur = st.top();
                st.pop();
                cur = cur->right;
            }
        }
        return result;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();
            result.push_back(cur->val);
            if (cur->right != nullptr) st.push(cur->right);
            if (cur->left != nullptr) st.push(cur->left);
        }
        return result;
    }

    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;
        stack<TreeNode*> st;
        if (root != nullptr) st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            if (node != nullptr){
                st.pop(); // 删除该节点，再最后加上
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
                st.push(node);
                st.push(nullptr);
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