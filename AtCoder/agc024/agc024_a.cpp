#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    long long k;
    cin >> a >> b >> c >> k;
    int ans = a - b;
    if(k % 2){
        ans *= -1;
    }
    cout << ans << "\n";
}