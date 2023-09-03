# 这是一个使用教程
## 这是二级标题
这是正文
换了一行

换了一段
**加粗了**

1. 列表1
2. 列表2
   1. 二级列表

### 插入图片
![Alt text](image.png)
*图片标题*

#### 公式
$$
\lim_{x \to \infin}\frac{sin(t)}{x}=1
$$
可以插入inline的公式$ \lim_{x \to \infin}f(x)$

## 表格

| 阿慧 | 阿航 |
| ---- | ---- |
| 1.5  | 1.4  |

## 鏈接
這是一個鏈接[鏈接](https://www.bilibili.com/video/BV1si4y1472o/?spm_id_from=333.337.search-card.all.click&vd_source=eb279884147ea6af954701f64897506a)

## 代碼
"""C++

    class Solution {
    public:
        // 暴力求解
        // int minSubArrayLen(int target, vector<int>& nums) {
        //     int minLen = nums.size() + 1;
        //     int size = nums.size();
        //     for (int i = 0; i < size; i++){
        //         int val = 0;
        //         for (int j = i; j < size; j++){
        //             val += nums[j];
        //             if (val >= target){
        //                 if (minLen > (j-i+1)) minLen = (j-i+1);
        //                 break;
        //             }
        //         }
        //     }
        //     if (minLen == size+1) return 0;
        //     return minLen;
        // }
    
        // 滑动窗口
        int minSubArrayLen(int target, vector<int>& nums){
            int i = 0; // 记录起始位置
            int minLen = INT32_MAX;
            int val = 0;
            for (int j=0; j<nums.size(); j++){ // j是终点位置
                val += nums[j];
                // 移动起点位置
                while(val >= target){
                    minLen = (j-i+1) < minLen ? (j-i+1) : minLen;
                    val -= nums[i++];
                }
            }
            minLen = minLen == INT32_MAX ? 0: minLen;
            return minLen;
        }
    };
    
    
    int main(){
        Solution solution;
        vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8};
        int target = 10;
        int minLen = solution.minSubArrayLen(target, nums);
        cout << minLen << endl;
        return 0;
    }
"""