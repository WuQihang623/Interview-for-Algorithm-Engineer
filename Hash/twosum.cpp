# include <unordered_map>
# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    // 暴力解法
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     int i = 0;
    //     for(const int& num: nums){
    //         int num1 = target - num;
    //         i++;
    //         for (int j=i; j<nums.size(); j++){
    //             if (nums[j] == num1) return vector<int> {--i, j};
    //         }
    //     }
    //     return {};
    // }

    //unordered_map
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i=0; i<nums.size(); i++){
            int num1 = nums[i];
            int num2 = target - num1;
            auto iter = map.find(num2);
            if (iter==map.end()){ // 没找到这个元素
                map.insert(pair<int, int> {num1, i});
            }
            else{
                return {i, iter->second};
            }
        }
        return {};
    }
};

int main(){
    vector<int> nums{1, 2, 3 ,4};
    Solution s;
    vector<int> indices = s.twoSum(nums, 3);
    for (const int& num: indices) cout << num << endl;
    return 0;
}