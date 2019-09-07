#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        ans += str[i] == str[i + 1];
    }
    int diffp = n - 1 - ans;
    for(int i = 0; i < k; i++){
        if(diffp <= 0) continue;
        ans += min(2, diffp);
        diffp -= 2;
    }
    cout << ans << "\n";
}