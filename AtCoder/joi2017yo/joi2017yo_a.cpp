#include <iostream>

using namespace std;

int main(){
    int a, b, c, d, e;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    int ans = 0;
    if(a < 0){
        ans += -a * c + d;
        a = 0;
    }
    ans += (b - a) * e;
    cout << ans << "\n";
}