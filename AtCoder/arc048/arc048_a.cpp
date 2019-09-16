#include <iostream>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int ans = b - a - (a < 0 && 0 < b);
    cout << ans << "\n";
}