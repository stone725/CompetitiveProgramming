#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        ans += min(a / 2, b);
    }
    cout << ans << "\n";
}