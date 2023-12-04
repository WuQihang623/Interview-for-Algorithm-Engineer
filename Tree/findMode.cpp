// 给一个含重复值的二叉搜索树，找出并返回BST中所有众数

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

// class Solution {
// public:
//     void dfs(TreeNode* node, unordered_map<int, int>& map){
//         if (node==nullptr) return;
//         dfs(node->left, map);
//         map[node->val]++;
//         dfs(node->right, map);
//     }
//     vector<int> findMode(TreeNode* root) {
//         vector<int> res;
//         if (root==nullptr) return res;
//         unordered_map<int, int> map;
//         dfs(root, map);
//         int max = 0;
//         for (auto it = map.begin(); it != map.end(); it++){
//             if (max < it->second){
//                 max = it->second;
//                 res.clear();
//                 res.push_back(it->first);
//             }
//             else if(max == it->second){
//                 res.push_back(it->first);
//             }
//         }
//         return res;
//     }
// };

class Solution {
private:
    int base;
    int count;
    int max_count=0;
    vector<int> ans;
public:
    void dfs(TreeNode* node){
        if (node==nullptr) return;
        dfs(node->left);
        // 如果值不相同，则更新base和count
        if (node->val != base){
            base = node->val;
            count = 1;
        }
        else count++;

        // 如果count大于max_count
        if (count > max_count){
            max_count = count;
            ans.clear();
            ans.push_back(base);
        }
        else if (count == max_count) ans.push_back(base);

        dfs(node->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
};