// 给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value ，将值插入二叉搜索树。 
// 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。
# include<unordered_map>
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
// 解成一个只有右子树的二叉树
class Solution {
private:
    vector<int> vec;
    bool insert_flag = true;
public:
    void dfs(TreeNode* node, int val){
        if (node==nullptr) return;
        dfs(node->left, val);
        if (insert_flag && node->val > val){
            insert_flag = false;
            vec.push_back(val);
        }
        vec.push_back(node->val);
        dfs(node->right, val);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        dfs(root, val);
        if (insert_flag) vec.push_back(val);
        TreeNode* new_root = new TreeNode(vec[0]);
        TreeNode* node = new_root;
        for (int i=1; i<vec.size(); i++){
            node->right = new TreeNode(vec[i]);
            node = node->right;
        }
        return new_root;
    }
};

// 在叶子节点处添加
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = root;
        TreeNode* pre_node = nullptr;
        while(node!=nullptr){
            pre_node = node;
            if (node->val >val) node = node->left;
            else node = node->right;
        }
        if (pre_node->val < val) pre_node->right = new TreeNode(val);
        else pre_node->left = new TreeNode(val);
        return root;
    }
};

// 在空节点处添加
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = root;
        while(node!=nullptr){
            if (node->val > val){
                if (node->left == nullptr){
                    node->left = new TreeNode(val);
                    break;
                }
                node = node->left;
            }
            else{
                if (node->right == nullptr){
                    node->right = new TreeNode(val);
                    break;
                }
                node = node->right;
            }
        }

        return root;
    }
};