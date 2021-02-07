#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> ans(n);
    for(int i = 0; i < n - 1; i++){
        int a;
        cin >> a;
        ans[a - 1]++;
    }
    for(auto&& i : ans){
        cout << i << "\n";
    }
}