// 从前序和中序遍历序列构造二叉树

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
    int pre_idx;
    unordered_map<int, int> inorder_map;
public:
    TreeNode* travel(int left_idx, int right_idx, vector<int>& preorder, vector<int>& inorder){
        if (left_idx > right_idx) return nullptr;
        int val = preorder[pre_idx];
        int val_idx = inorder_map[val];
        TreeNode* node = new TreeNode(val);
        pre_idx++;
        node->left = travel(left_idx, val_idx-1, preorder, inorder);
        node->right = travel(val_idx+1, right_idx, preorder, inorder);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre_idx = 0;
        int i = 0;
        for(int val: inorder) inorder_map[val] = i++;
        return travel(0, inorder.size()-1, preorder, inorder);
    }
};