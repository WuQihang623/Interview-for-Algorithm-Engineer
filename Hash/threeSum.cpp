# include<iostream>
# include<vector>
# include<algorithm>
# include<unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i=0; i<(size-2); i++){
            // 确保这一次的a与上一次的a不一样
            if (i>0 && nums[i]==nums[i-1]){
                continue;
            }
            if (nums[i] > 0) break;
            int left = i+1;
            int right = size-1;
            int a = nums[i];
            while(left < right){
                // 只要确保上一次的c和这一次的不一样
                if (right < (size-1) && nums[right] == nums[right+1]){
                    right--;
                    continue;
                }
                int b = nums[left];
                int c = nums[right];
                if ((a+b+c)>0){
                    right--;
                }
                else if ((a+b+c)<0){
                    left++;
                }
                else{
                    result.push_back({a, b, c});
                    right--;
                }
            }
        }
        return result;
    }
};