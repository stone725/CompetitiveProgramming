#include <iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int ans = 0;
    while(n){
        ans++;
        n /= k;
    }
    cout << ans << "\n";
}