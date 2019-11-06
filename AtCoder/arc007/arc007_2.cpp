#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> c(n + 1);
    for(int i = 0; i < n + 1; i++){
        c[i] = i;
    }
    int before = 0;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        swap(c[a], c[before]);
        before = a;
    }
    vector<int> ans(n);
    for(int i = 0; i < n + 1; i++){
        if(c[i] == 0) continue;
        ans[c[i] - 1] = i;
    }
    for(auto&& i : ans){
        cout << i << "\n";
    }
}