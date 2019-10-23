#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto&& i : a){
        cin >> i;
    }
    sort(begin(a), end(a));
    vector<pair<long long, long long>> ans;
    int i = 1;
    for(; i < n - 1 && a[i] <= 0; i++){
        ans.push_back(make_pair(a[n - 1], a[i]));
        a[n - 1] -= a[i];
    }
    for(; i < n - 1; i++){
        ans.push_back(make_pair(a[0], a[i]));
        a[0] -= a[i];
    }
    cout << a[n - 1] - a[0] << "\n";
    for(auto&& i : ans){
        cout << i.first << " " << i.second << "\n";
    }
    cout << a[n - 1] << " " << a[0] << "\n";
}