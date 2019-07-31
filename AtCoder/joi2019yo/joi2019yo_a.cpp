#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    while(0 < c){
        if(c <= a * 7){
            ans += c / a + !!(c % a);
            break;
        }
        else{
            ans += 7;
            c -= a * 7 + b;
        }
    }
    cout << ans << "\n";
}