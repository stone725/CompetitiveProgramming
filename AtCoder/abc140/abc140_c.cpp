#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> b(n - 1);
    for(auto&& i : b){
        cin >> i;
    }
    b.push_back(1e9 + 7);
    int ans = b[0];
    for(int i = 1; i < b.size(); i++){
        ans += min(b[i], b[i - 1]);
    }
    cout << ans << "\n";
}