#include <iostream>

using namespace std;

int main(){
    long long x, y, z;
    cin >> x >> y >> z;
    long long ans = z;
    if(x <= z){
        ans--;
    }
    if(y <= z){
        ans--;
    }
    cout << ans << "\n";
}