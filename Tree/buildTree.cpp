// 从中序与后序遍历序列构造二叉树

# include<vector>
# include<stack>
# include<queue>
# include<string>
# include<algorithm>
# include<unordered_map>
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
private:
    unordered_map<int, int> inorder_map;
    int post_idx;
public:
    TreeNode* traval(int left_idx, int right_idx, vector<int>& inorder, vector<int>& postorder){
        if (left_idx > right_idx) return nullptr;
        int val = postorder[post_idx];
        post_idx--;
        TreeNode* node = new TreeNode(val);
        int node_idx = inorder_map[val];
        node->right = traval(node_idx+1, right_idx, inorder, postorder);
        node->left = traval(left_idx, node_idx-1, inorder, postorder);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        post_idx = postorder.size() - 1;
        int i = 0;
        for (int val : inorder){
            inorder_map[val] = i++;
        }
        TreeNode* root = traval(0, post_idx, inorder, postorder);
        return root;
    }
};
