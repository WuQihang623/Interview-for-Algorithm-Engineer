# include<vector>
# include<unordered_map>
using namespace std;

// 柠檬水找零

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> changes = {{5, 0}, {10, 0}};
        for (int i=0; i<bills.size(); i++) {
            if (bills[i] == 5) {
                changes[5] += 1;
            }
            else {
                if (bills[i]==10) {
                    if (changes[5] <= 0) return false;
                    changes[5] -= 1;
                    changes[10] += 1;
                }
                else {
                    if (changes[10] > 0 && changes[5] > 0) {
                        changes[10] -= 1;
                        changes[5] -= 1;
                    }
                    else if (changes[5] >= 3) changes[5] -= 3;
                    else return false;
                }
            }
        }
        return true;
    }
};