# include<unordered_map>
# include<vector>
# include<algorithm>
# include<queue>
using namespace std;

class Solution {
public:
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     vector<int> result;
    //     unordered_map<int, int> dict;
    //     for (int i=0; i<nums.size(); i++){
    //         auto item = dict.find(nums[i]);
    //         if (item == dict.end()) dict[nums[i]] = 1;
    //         else dict[nums[i]] ++;
    //     }
    //     vector<int> frequent;
    //     for(auto it=dict.begin(); it!=dict.end(); ++it){
    //         frequent.push_back(it->second);
    //     }
    //     sort(frequent.begin(), frequent.end());
    //     reverse(frequent.begin(), frequent.end());
    //     int min_frequent = frequent[k-1];
    //     for(auto it=dict.begin(); it!=dict.end(); ++it){
    //         if (it->second >= min_frequent) result.push_back(it->first);
    //     }
    //     return result;
    // }

    class My_Element{
        pair<int, int> a;
        public:
            My_Element(pair<int, int> x): a(x) {}
            // 创建最小堆
            bool operator< (const My_Element& b) const{  // 第二个const：这个const出现在函数声明的末尾，
            //表示该成员函数是一个常量成员函数，并且不会修改调用它的对象的状态。这个const是函数签名的一部分，
            // 它告诉编译器该函数在调用时可以用于常量对象。如果您尝试在常量对象上调用非常量成员函数，编译器会发出错误。
                return this->second() > b.second();
            }
            int first() const {
                return a.first;
            }
            int second() const {
                return a.second;
            }
    };

    vector<int> topKFrequent(vector<int>& nums, int k){
        vector<int> result;
        unordered_map<int, int> dict;
        for (int i=0; i<nums.size(); i++){
            auto item = dict.find(nums[i]);
            if (item == dict.end()) dict[nums[i]] = 1;
            else dict[nums[i]] ++;
        }
        priority_queue<My_Element> que;
        for(auto it = dict.begin(); it!=dict.end(); ++it){
            que.push(My_Element(pair<int,int> {it->first, it->second}));
            if (que.size() > k) que.pop();
        }
        while(!que.empty()) {
            My_Element x = que.top();
            result.push_back(x.first());
            que.pop();
        }
        return result;
    }
};

int main(){
    vector<int> nums {1, 1, 1, 2, 2, 3};
    Solution s;
    s.topKFrequent(nums, 2);
}