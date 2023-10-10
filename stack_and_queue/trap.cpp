# include<stack>
# include<vector>
using namespace std;

class Solution {
public:
    // 双指针法
    int trap(vector<int>& height) {
        int result = 0;
        for (int first=0; first<height.size()-2; ){
            // 如果左高右低说明此处可能是接雨水的地方
            if (height[first] > height[first+1]){
                // 寻找大于等于height[first]的索引，或者只要大于height[first+1]就行
                int tmp_ind = first+2;
                for (int second=first+2; second<height.size(); second++){
                    if (height[second] > height[first]){
                        tmp_ind = second;
                        break;
                    }
                    else if (height[second] > height[first+1]){
                        if (height[second] > height[tmp_ind]) tmp_ind = second;
                    }
                }
                // 
                if (height[tmp_ind] > height[first]){
                    int h = (height[first] > height[tmp_ind]) ? height[tmp_ind] : height[first];
                    for (int i=first+1; i<tmp_ind; i++) result += (h - height[i]);
                    first = tmp_ind;
                }
                else first++;
            }
            else first++;
        }
        return result;
    }
};