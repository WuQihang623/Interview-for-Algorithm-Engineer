# include<vector>
# include<stack>
using namespace std;

// 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
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
        vector<int> result = {};
        if (root == nullptr) return result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(! st.empty() || cur != nullptr){
            // 先访问到根节点
            while(cur != nullptr){
                st.push(cur);
                cur = cur->left;
            }
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            cur = node->right;
        }
        return result;
    }
};