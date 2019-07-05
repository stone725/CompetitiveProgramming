#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, ans = 1e9 + 7;
    cin >> n;
    for(int i = 1; i * i <= n; i++){
        ans = min(ans, n / i - i + n % i);
    }
    cout << ans << "\n";
}