#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> umap;
    umap[0] = 1;
    umap[0]--;
    cout << umap.count(0) << endl;
    return 0;
}