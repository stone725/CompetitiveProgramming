#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto&& i : a){
        cin >> i;
    }
    for(auto&& i : b){
        cin >> i;
    }
    vector<int> c(n);
    for(int i = 0; i < n; i++){
        c[i] = a[i] - b[i];
    }
    sort(begin(c), end(c));
    if(accumulate(begin(c), end(c), 0ll) < 0){
        cout << "-1\n";
        return 0;
    }
    c.push_back(0);
    int ans = 0, ep = n;
    for(int i = 0; c[i] < 0; i++){
        ans++;
        while(c[i] < 0){
            if(c[ep] == 0){
                ans++;
                ep--;
            }
            int addscore = min(-c[i], c[ep]);
            c[i] += addscore;
            c[ep] -= addscore;
        }
    }
    cout << ans << "\n";
}