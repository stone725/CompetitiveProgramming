#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int a, b, c, ac, bc, cc;
        cin >> a >> b >> c;
        ac = a;
        bc = b;
        cc = c;
        int ans = 0;
        while(c >= 2 && b){
            ans += 3;
            c -= 2;
            b--;
        }
        while(b >= 2 && a){
            ans += 3;
            b -= 2;
            a--;
        }
        int cnt = 0;
        while(bc >= 2 && ac){
            cnt += 3;
            bc -= 2;
            ac--;
        }
        while(cc >= 2 && bc){
            cnt += 3;
            cc -= 2;
            bc--;
        }
        ans = max(ans, cnt);
        cout << ans << "\n";
    }
}