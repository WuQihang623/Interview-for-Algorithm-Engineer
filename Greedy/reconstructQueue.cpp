# include<vector>
# include<algorithm>
using namespace std;

// 根据身高重建队列

class Solution {
public:
    // 按照身高从大到小排，如果身高相同，先排k较小的
    static bool cmp(vector<int>& a, vector<int>&b) {
        if (a[0]==b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin(), people.end(), cmp);
        for (int i=0; i<people.size(); i++) {
            int position = people[i][1];
            ans.insert(ans.begin()+position, people[i]);
        }
        return ans;
    }
};