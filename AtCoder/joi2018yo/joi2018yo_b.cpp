#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0, ans = 1;
    for(auto&& i : a){
        cin >> i;
        if(i){
            cnt++;
            ans = max(ans, cnt + 1);
        }else{
            cnt = 0;
        }
    }
    cout << ans << "\n";
}