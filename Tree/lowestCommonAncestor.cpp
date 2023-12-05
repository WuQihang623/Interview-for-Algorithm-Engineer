// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先
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

class Solution {
private:
    unordered_map<int, TreeNode*> fath_map; // 存储节点的父节点
public:
    void dfs(TreeNode* node, TreeNode* fath){
        if (node==nullptr) return;
        fath_map[node->val] = fath;
        fath = node;
        dfs(node->left, fath);
        dfs(node->right, fath);
    }
    void get_path(vector<TreeNode*>& path, TreeNode* node){
        path.push_back(node);
        while(fath_map[node->val]!=nullptr){
            path.push_back(fath_map[node->val]);
            node = fath_map[node->val];
        }
        return ;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, nullptr);
        vector<TreeNode*> path_p, path_q;
        get_path(path_p, p);
        get_path(path_q,q);
        for (TreeNode* ances_p: path_p){
            for (TreeNode* ances_q: path_q){
                if (ances_p == ances_q) return ances_p;
            }
        }
        return nullptr;
    }
};

// 父节点的另一种寻找方式
class Solution {
private:
    unordered_map<int, TreeNode*> fath_map; // 存储节点的父节点
    unordered_map<int, bool> path_map; // 存储其中一个路径
public:
    void dfs(TreeNode* node, TreeNode* fath){
        if (node==nullptr) return;
        fath_map[node->val] = fath;
        fath = node;
        dfs(node->left, fath);
        dfs(node->right, fath);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, nullptr);
        vector<TreeNode*> path_p, path_q;
        while(p!=nullptr){
            path_map[p->val] = true;
            p = fath_map[p->val];
        }
        while(q!=nullptr){
            if (path_map[q->val]) return q;
            q = fath_map[q->val];
        }
        return nullptr;
    }
};