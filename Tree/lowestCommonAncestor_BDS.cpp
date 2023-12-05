// 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
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

// 两次遍历
class Solution {
private: 
    vector<TreeNode*> path_p, path_q;
public:
    void travel(TreeNode* node, TreeNode* end, vector<TreeNode*>& path){
        while(node->val != end->val){
            path.push_back(node);
            if (node->val > end->val) node = node->left;
            else node=node->right;
        }
        path.push_back(end);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        travel(root, p, path_p);
        travel(root, q, path_q);
        for (auto ances_p = path_p.rbegin(); ances_p != path_p.rend(); ++ances_p){
            for (auto ances_q = path_q.rbegin(); ances_q != path_q.rend(); ++ances_q){
                if ((*ances_p)->val==(*ances_q)->val) return *ances_p;
            }
        }
        return nullptr;
    }
};
// 一次遍历
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = root;
        while(true){
            if (ans->val > p->val && ans->val > q->val) ans = ans->left;
            else if (ans->val < q->val && ans->val < p->val) ans = ans->right;
            else break;
        }
        return ans;
    }
};