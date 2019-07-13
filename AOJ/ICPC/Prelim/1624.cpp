#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    vector<int> a;
    while(cin >> n && n){
        a.resize(n);
        for(auto&& i : a){
            cin >> i;
        }
        sort(rbegin(a), rend(a));
        double avg = accumulate(begin(a), end(a), 0.0) / n;
        for(int i = 0; i < n; i++){
            if(avg >= a[i]){
                cout << n - i << "\n";
                break;
            }
        }
    }
}