#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<double> p(n);
    for(auto&& i : p){
        int a;
        cin >> a;
        i = 1. * a * (a + 1) / 2 / a;
    }
    vector<double> s(n + 1);
    partial_sum(begin(p), end(p), begin(s) + 1);
    double ans = 0;
    for(int i = 0; i + k <= n; i++){
        ans = max(ans, s[i + k] - s[i]);
    }
    cout << fixed << setprecision(10) << ans << "\n";
}