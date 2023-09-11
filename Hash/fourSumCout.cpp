# include<iostream>
# include<vector>
using namespace std;

class Solution {
public:
    // 暴力解法
    // int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    //     int n = nums1.size();
    //     int count = 0;
    //     for (int i1=0; i1<n; i1++){
    //         int num1 = nums1[i1];
    //         for (int i2=0; i2<n; i2++){
    //             int num2 = nums2[i2];
    //             for (int i3=0; i3<n; i3++){
    //                 int num3 = nums3[i3];
    //                 for (int i4=0; i4<n; i4++){
    //                     int num4 = nums4[i4];
    //                     if (num1+num2+num3+num4==0) count++;
    //                 }
    //             }
    //         }
    //     }
    //     return count;
    // }
    
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // 首先可以使用unordered_set过滤掉重复的值
        
    }
};

int main(){
    vector<int> nums1{0};
    vector<int> nums2{0};
    vector<int> nums3{0};
    vector<int> nums4{0};
    Solution s;
    int count = s.fourSumCount(nums1, nums2, nums3, nums4);
    cout << count <<endl;
    return 0;
}