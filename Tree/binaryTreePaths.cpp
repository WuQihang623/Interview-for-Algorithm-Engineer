// 回所有从根节点到叶子节点的路径

# include<vector>
# include<stack>
# include<queue>
# include<string>
# include<algorithm>
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
public:
    void preorderTraval(TreeNode* node, string& s, vector<string>& result){
        if (node->left == nullptr && node->right == nullptr){
            result.push_back(s);
            return ;
        }
        s += to_string(node->val);
        if (node->left) {
            preorderTraval(node->left, s, result);
            s = s.substr(0, s.size()-1);
        }
        if (node->right){
            preorderTraval(node->right, s, result);
            s = s.substr(0, s.size()-1);
        }

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root==nullptr) return result;
        string s;
        preorderTraval(root, s, result);
        return result;
    }
};