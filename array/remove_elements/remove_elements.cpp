#include<iostream>
#include<vector>
using namespace std;


class Solution{
public:
    // 双指针法
    int removeElement(vector<int>& nums, int val){
        int slowpointer = 0;
        int size = nums.size();
        for (int fastpointer = 0; fastpointer < size; fastpointer++){
            if (nums[fastpointer] != val){
                nums[slowpointer++] = nums[fastpointer];
            }
        }
        return slowpointer;
    }

    // // 暴力求解法
    // int removeElement(vector<int>& nums, int val){
    //     int size = nums.size();
    //     for (int i = 0; i < size; i++){
    //         if (nums[i] == val){
    //             for (int j=i+1; j < size; j++){
    //                 nums[j-1] = nums[j];
    //             }
    //             size--;
    //             i--;
    //         }
    //     }
    //     return size;
    // }
};


int main(){
    Solution obj{};
    vector<int> nums{1, 2, 3, 2, 3, 2};
    int target = 2;
    int size = obj.removeElement(nums, target);
    cout << size << endl;
    return 0;
}
