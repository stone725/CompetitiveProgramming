#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    vector<char> caninput(k);
    for(auto&& i : caninput){
        cin >> i;
    }
    sort(begin(caninput), end(caninput));
    string inputstr;
    long long ans = 0;
    vector<long long> cnt(n + 1);
    for(int i = 0; i < n; i++){
        if(binary_search(begin(caninput), end(caninput), str[i])){
            cnt[i + 1] = cnt[i] + 1;
        }else{
            ans += cnt[i] * (cnt[i] + 1) / 2;
            cnt[i + 1] = 0;
        }
    }
    ans += cnt[n] * (cnt[n] + 1) / 2;
    cout << ans << "\n";
}