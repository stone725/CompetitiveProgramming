#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> l(n);
    for(auto&& i : l){
        cin >> i;
    }
    long long ans = 0;
    sort(begin(l), end(l));
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ans += lower_bound(begin(l), end(l), l[i] + l[j]) - begin(l) - j - 1;
        }
    }
    cout << ans << "\n";
}