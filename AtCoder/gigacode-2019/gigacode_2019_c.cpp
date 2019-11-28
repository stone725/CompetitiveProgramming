#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int d;
    cin >> d;
    vector<int> a(d);
    vector<long long> b(d);
    for(auto&& i : a){
        cin >> i;
    }
    for(auto&& i : b){
        cin >> i;
    }
    long long money = 0;
    long long ans = -1;
    for(int i = 0; i < d; i++){
        money += a[i];
        if(b[i] <= money){
            if(~ans){
                ans = min(ans, b[i]);
            }else{
                ans = b[i];
            }
        }
    }
    cout << ans << "\n";
}