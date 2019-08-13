#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto&& i : a){
        cin >> i;
    }
    vector<bool> check(n, false);
    check[0] = true;
    int cnt = 1;
    for(int i = 1; i < n; i++){
        check[i] = a[i - 1] <= a[i];
        cnt += check[i];
    }
    if(cnt == n){
        cout << 0 << "\n";
        return 0;
    }
    int q;
    cin >> q;
    for(int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        if(y < x) swap(x, y);
        swap(a[x - 1], a[y - 1]);
        if(1 < x){
            if(check[x - 1]) cnt--;
            cnt += check[x - 1] = a[x - 2] <= a[x - 1];
        }
        if(check[x]) cnt--;
        cnt += check[x] = a[x - 1] <= a[x];
        if(check[y - 1]) cnt--;
        cnt += check[y - 1] = a[y - 2] <= a[y - 1];
        if(y < n){
            if(check[y]) cnt--;
            cnt += check[y] = a[y - 1] <= a[y];
        }
        if(cnt == n){
            cout << i << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
}