# include<vector>
# include<unordered_set>
# include<iostream>
using namespace std;

class Solution {
public:
    // 暴力解法
    // vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     int size1 = nums1.size();
    //     int size2 = nums2.size();
    //     vector<int> inter;
    //     for (int i=0; i<size1; i++){
    //         int num1 = nums1[i];
    //         bool found = false;
    //         for (const int& item: inter){ // 遍历vector的方法
    //             if (item == num1){
    //                 found = true;
    //                 break;
    //             }
    //         }
    //         if (found==false){
    //             for (int j=0; j<size2; j++){
    //                 int num2 = nums2[j];
    //                 if (num1 == num2){
    //                      inter.push_back(num1); //向vector最后添加元素num1
    //                      break;
    //                 }
    //             }
    //         }
    //     }
    //     return inter;
    // }

    // 使用unordered_set
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 存放结果
        unordered_set<int> intersect_set{};
        unordered_set<int> numbers1(nums1.begin(), nums1.end());
        for (const int& num: nums2){
            if (numbers1.find(num) != numbers1.end()){ // 在nums1中找到了这个元素
                intersect_set.insert(num);
            }
        }
        vector<int> number(intersect_set.begin(), intersect_set.end());
        return number;
    }
};