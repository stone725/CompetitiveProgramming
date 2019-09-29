#include <iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int h;
        cin >> h;
        ans += k <= h;
    }
    cout << ans << "\n";
}