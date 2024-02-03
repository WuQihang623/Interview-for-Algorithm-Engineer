# include<vector>
using namespace std;

// 摆动序列
// 如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。
// 第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans = 2;
        if (nums.size() == 1) return 1;
        vector<int> vec;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i]-nums[i-1]!=0) vec.push_back(nums[i]-nums[i-1]);
        }
        if (vec.size()==0) return 1;
        if (vec.size()==1) return 2;
        for (int i=1; i<vec.size(); i++) {
            if (vec[i]*vec[i-1] < 0) ans += 1;
        }
        return ans;
    }
};