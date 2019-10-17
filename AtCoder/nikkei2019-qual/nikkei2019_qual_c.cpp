#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> score(n);
    long long ans = 0;
    for(auto&& i : score){
        long long a, b;
        cin >> a >> b;
        ans -= b;
        i = a + b;
    }
    sort(rbegin(score), rend(score));
    for(int i = 0; i < n; i += 2){
        ans += score[i];
    }
    cout << ans << "\n";
}