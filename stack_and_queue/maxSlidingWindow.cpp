# include<vector>
# include<queue>
# include<deque>
# include<map>
using namespace std;

// class Solution {
// public:
//     int findmaxKey(map<int, int> map){
//         auto lastPair = map.rbegin();
//         int max_num = lastPair->first;
//         return max_num;
//     }

//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         queue<int> que;
//         vector<int> result;
//         map<int, int> map;
//         for (int i=0; i<nums.size(); i++){
//             que.push(nums[i]);
//             auto got = map.find(nums[i]);
//             if (got == map.end()) map[nums[i]] = 1;
//             else map[nums[i]]++;
//             if (que.size() > k){
//                 int key = que.front();
//                 que.pop();
//                 map[key]--;
//                 if (map[key]==0) map.erase(key);
//             }
//             if (que.size() == k) result.push_back(findmaxKey(map));
//         }
//         return result;
//     }
// };

class Solution {
private:
    // 实现一个单调队列
    class monQue{
        deque<int> que;
        public:
            int front(){
                return que.front();
            }
            
            // 当pop时，如果要pop的value和队列头的一样，则进行pop
            void pop(int num){
                if(!que.empty() && que.front()==num){
                    que.pop_front();
                }
            }
            // 当push时，如果num>大于队列尾部一样时，将尾部pop掉，再push进去
            void push(int num){
                while(!que.empty() && que.back() < num){
                    que.pop_back();
                }
                que.push_back(num);
            }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        monQue que;
        vector<int> result;
        for (int i=0; i<k; i++){
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for (int i=k; i<nums.size(); i++){
            que.pop(nums[i-k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = {-7,-8,7,5,7,1,6,0};
    vector<int> v = s.maxSlidingWindow(nums, 4);
}