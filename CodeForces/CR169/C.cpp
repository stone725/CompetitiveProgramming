#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for(auto&& i : a){
        cin >> i;
    }
    sort(rbegin(a), rend(a));
    vector<int> b(n + 1);
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        b[l - 1]++;
        b[r]--;
    }
    partial_sum(begin(b), end(b), begin(b));
    sort(rbegin(b), rend(b));
    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans += b[i] * a[i];
    }
    cout << ans << "\n";
}