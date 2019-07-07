#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    int ans = 0;
    for(int i = 1; i < n; i++){
        string f = str.substr(0, i);
        string s = str.substr(i);
        set<char> cnt;
        for(auto&& i : f){
            if(count(begin(s), end(s), i)){
                cnt.insert(i);
            }
        }
        ans = max<int>(ans, cnt.size());
    }
    cout << ans << "\n";
}