# include<vector>
# include<string>
# include<unordered_set>
using namespace std;

// 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。

// 回溯算法爆搜
class Solution {
public:
    bool backtrack(int startIdx, const string& s, const unordered_set<string>& wordSet) {
        if (startIdx>=s.size()) return true;
        for (int i=startIdx; i<s.size(); i++) {
            string sub_str = s.substr(startIdx, i-startIdx+1);
            if (wordSet.find(sub_str)!=wordSet.end() && backtrack(i+1, s, wordSet)) return true;
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return backtrack(0, s, wordSet);
    }
};

// 记忆化递归
class Solution {
private:
    bool backtracking (const string& s,
            const unordered_set<string>& wordSet,
            vector<bool>& memory,
            int startIndex) {
        if (startIndex >= s.size()) {
            return true;
        }
        // 如果memory[startIndex]不是初始值了，直接使用memory[startIndex]的结果
        if (!memory[startIndex]) return memory[startIndex];
        for (int i = startIndex; i < s.size(); i++) {
            string word = s.substr(startIndex, i - startIndex + 1);
            if (wordSet.find(word) != wordSet.end() && backtracking(s, wordSet, memory, i + 1)) {
                return true;
            }
        }
        memory[startIndex] = false; // 记录以startIndex开始的子串是不可以被拆分的
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> memory(s.size(), 1); // -1 表示初始化状态
        return backtracking(s, wordSet, memory, 0);
    }
};

// 动态规划
// 完全背包的全排列问题
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet (wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        // 先遍历背包，再遍历物品，这里遍历物品并不是说遍历wordDict
        for (int i=1; i<=s.size(); i++) {
            for (int j=0; j<i; j++) {
                string sub_str = s.substr(j, i-j);
                if (wordSet.find(sub_str)!=wordSet.end() && dp[j]) dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};