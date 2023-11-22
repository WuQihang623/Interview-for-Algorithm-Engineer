# include<vector>
# include<stack>
using namespace std;

// 给定一个二叉树的根节点 root ，使用迭代法返回 它的 中序 遍历 。
// 左-》中-》右

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root==nullptr) return result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur != nullptr){
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        while(!st.empty() || cur != nullptr){
            result.push_back(cur->val);
            if (cur->right != nullptr){
                cur = cur->right;
                st.push(cur);
                while(cur->left !=nullptr){
                    cur = cur->left;
                    st.push(cur);
                }
            }
            if (!st.empty()){
                cur = st.top();
                st.pop();
            }
            else break;
        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode* root){
        vector<int> result;
        stack<TreeNode*> st;
        if (root != nullptr) st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            if (node != nullptr){
                // 将该节点弹出
                st.pop();
                // 将右节点添加到栈中
                if (node->right) st.push(node->right);
                // 将中间节点放到栈中
                st.push(node);
                st.push(nullptr); // 虽然访问过中间节点，但是还没有处理，加入空节点进行标记
                // 将左节点放到栈中
                if(node->left) st.push(node->left);
            }
            else{
                // 只有遇到空节点时，才会将下一个节点放入结果中
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};