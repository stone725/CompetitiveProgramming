#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    string str;
    cin >> str;
    vector<int> point[26];
    for(int i = 0; i < n; i++){
        point[str[i] - 'a'].push_back(i + 1);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        string str2;
        cin >> str2;
        int ans = 0;
        sort(begin(str2), end(str2));
        for(auto&& j : str2){
            int cnt = upper_bound(begin(str2), end(str2), j) - lower_bound(begin(str2), end(str2), j);
            ans = max(ans, point[j - 'a'][cnt - 1]);
        }
        cout << ans << "\n";
    }
}