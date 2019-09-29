#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(begin(a), end(a));
    for(int i = 0; i < n - 1; i++){
        cout << a[i].second << " ";
    }
    cout << a[n - 1].second << "\n";
}