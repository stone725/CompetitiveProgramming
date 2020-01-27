#include <iostream>

using namespace std;

int main(){
    long long h;
    cin >> h;
    long long ans = 1;
    long long now = 1;
    long long add = 1;
    while(now < h){
        add *= 2;
        ans += add;
        h /= 2;
    }
    cout << ans << "\n";
}