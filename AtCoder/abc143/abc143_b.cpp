#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> d(n);
    for(auto&& i : d){
        cin >> i;
    }
    long long ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ans += d[i] * d[j];
        }
    }
    cout << ans << "\n";
}