// 二叉树前中后序的递归遍历
# include<vector>
using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): value(v), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    void preorderTra(TreeNode* cur, vector<int>& vec){
        if (cur == nullptr) return;
        vec.push_back(cur->value);
        preorderTra(cur->left, vec);
        preorderTra(cur->right, vec);
    }

    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;
        preorderTra(root, result);
        return result;
    }

    void inorderTra(TreeNode* cur, vector<int>& vec){
        if (cur == nullptr) return;
        inorderTra(cur->left, vec);
        vec.push_back(cur->value);
        inorderTra(cur->right, vec);
    }

    vector<int> inorderTraversal(TreeNode* root){
        vector<int> result;
        inorderTra(root, result);
        return result;
    }

    void postorderTra(TreeNode* cur, vector<int>& vec){
        if (cur == nullptr) return;
        postorderTra(cur->left, vec);
        postorderTra(cur->right, vec);
        vec.push_back(cur->value);
    }

    vector<int> postorderTraversal(TreeNode* root){
        vector<int> result;
        postorderTra(root, result);
        return result;
    }
};