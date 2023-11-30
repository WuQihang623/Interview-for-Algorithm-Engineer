// 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

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
    vector<int> res;
public:
    void inorderTravel(TreeNode* node){
        if (node==nullptr) return;
        inorderTravel(node->left);
        res.push_back(node->val);
        inorderTravel(node->right);
    }

    bool isValidBST(TreeNode* root) {
        inorderTravel(root);
        for (int i=0; i<res.size()-1; i++){
            if (res[i] >= res[i+1]) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root -> val <= lower || root -> val >= upper) {
            return false;
        }
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};
