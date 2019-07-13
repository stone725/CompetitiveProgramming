#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int r0, w0, c, r;
    while(cin >> r0 >> w0 >> c >> r && r0 && w0 && c && r){
        int need = w0 * c - r0;
        if(need < 0){
            cout << 0 << "\n";
            continue;
        }
        cout << max(0, (need / r) + !!(need % r)) << "\n";
    }
}