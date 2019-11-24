#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for(auto&& i : a){
        cin >> i;
    }
    partial_sum(begin(a), end(a), begin(b));
    double d = (b.back() + 1) / 2;
    auto p = upper_bound(begin(b), end(b), d);
    long long ans;
    if(p != begin(b)){
        ans = min(abs(b.back() - *p * 2), abs(b.back() - *(p - 1) * 2));
    }else{
        ans = abs(b.back() - *p * 2);
    }
    cout << ans << "\n";
}