// 判断是否为对称二叉树，检查它是否轴对称
# include<vector>
# include<stack>
# include<queue>
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr) return true;
        else if(root->left == nullptr || root->right == nullptr) return false;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while(!que.empty()){
            int size = que.size();
            vector<int> result;
            for (int i=0; i<size; i++){
                if (que.front()==nullptr) result.push_back(101);
                else result.push_back(que.front()->val);
                if (que.front()!=nullptr){
                    TreeNode* node = que.front();
                    que.push(node->left);
                    que.push(node->right);
                }
                que.pop();
            }
            for (int j=0; j<(result.size()/2); j++){
                if (result[j] != result[result.size()-1-j]) return false;
            }
        }
        return true;
    }
};
