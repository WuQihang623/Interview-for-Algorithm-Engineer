# include<iostream>
# include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int list[2*n-1];
        int j = 1;
        list[0] = n;
        for (int i = n-1; i>0; i--){
            list[j++] = i;
            list[j++] = i;
        }
        int x_idx[n*n];
        int y_idx[n*n];
        int idx = 0;
        int start = 0;
        bool add = false;
        int direction = 1;
        for (int i=0; i<2*n-1; i++){
            int num = list[i];
            for (int j=0; j<num; j++){
                x_idx[idx++] = start;
                start += direction;
            }
            start-=direction;
            if (add == false && direction == -1) add = true;
            else if (add == true && direction == 1) add = false;
            if (add == false) direction--;
            else direction ++;
            start+=direction;
        }
        idx = 0;
        start = 0;
        add = true;
        direction = 0;
        for (int i=0; i<2*n-1; i++){
            int num = list[i];
            for (int j=0; j<num; j++){
                y_idx[idx++] = start;
                start += direction;
            }
            start -= direction;
            if (add == false && direction == -1) add = true;
            else if (add == true && direction == 1) add = false;
            if (add == false) direction--;
            else direction ++;
            start+=direction;
        }

        for (int i=0; i<n*n; i++){
            int x = x_idx[i];
            int y = y_idx[i];
            matrix[y][x] = (i+1);
        }
        return matrix;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = s.generateMatrix(3);
    cout << matrix[0][0] << endl;
    return 0;
}