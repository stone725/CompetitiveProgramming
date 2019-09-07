#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n - 1);
    for(auto&& i : a){
        cin >> i;
    }
    for(auto&& i : b){
        cin >> i;
    }
    for(auto&& i : c){
        cin >> i;
    }
    int ans = accumulate(begin(b), end(b), 0);
    for(int i = 0; i < n - 1; i++){
        if(a[i + 1] - a[i] == 1){
            ans += c[a[i] - 1];
        }
    }
    cout << ans << "\n";
}