// 给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree）
// 使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。
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
    queue<int> que;
    int sum=0;
public:
    void dfs(TreeNode* node){
        if (node==nullptr) return ;
        dfs(node->left);
        que.push(node->val);
        sum += node->val;
        dfs(node->right);
    }
    void change_val(TreeNode* node){
        if (node==nullptr) return;
        change_val(node->left);
        int val = que.front();
        que.pop();
        sum -= val;
        node->val = sum;
        change_val(node->right);
    }

    TreeNode* convertBST(TreeNode* root) {
        que.push(0);
        dfs(root);
        change_val(root);
        return root;
    }
};
