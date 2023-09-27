# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result {};
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i=0; i<(size-3); i++){
            if (i>0 && nums[i-1]==nums[i]) continue;
            for (int j=i+1; j<(size-2); j++){
                if (j>i+1 && nums[j-1] == nums[j]) continue;
                int left = j+1;
                int right = size - 1;
                while(left<right){
                    if (left > j+1 && nums[left-1]==nums[left]){
                        left++;
                        continue;
                    }
                    if ((nums[i] + nums[j] + nums[left] + nums[right]) < target){
                        left++;
                    }
                    else if ((nums[i] + nums[j] + nums[left] + nums[right]) > target){
                        right--;
                    }
                    else{
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                    }
                }
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums{1000000000,1000000000,1000000000,1000000000};
    s.fourSum(nums, 0);
    return 0;
}