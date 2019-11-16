#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(auto&& i : h){
        cin >> i;
    }
    int ans = 1;
    int s = 0, t = 0;
    for(int i = 1; i < n; i++){
        if(h[i - 1] < h[i]){
            if(t == 0){
                s = i - 1;
            }
            t = i;
        }else{
            t = 0;
        }
        ans = max(ans, i - s + 1);
    }
    cout << ans << "\n";
}