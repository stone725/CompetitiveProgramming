#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for(auto&& i : a){
        cin >> i;
    }
    for(auto&& i : b){
        cin >> i;
    }
    for(auto&& i : c){
        cin >> i;
    }
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    sort(begin(c), end(c));
    long long ans = 0;
    for(auto&& i : b){
        long long selectA = lower_bound(begin(a), end(a), i) - begin(a);
        long long selectC = end(c) - upper_bound(begin(c), end(c), i);
        ans += selectA * selectC;
    }
    cout << ans << "\n";
}