#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string l;
    getline(cin, l);
    vector<string> mp(m);
    for(auto&& i : mp){
        getline(cin, i);
    }
    getline(cin, l);
    int now;
    for(int i = 0; i < n; i++){
        if(l[i * 2] == 'o'){
            now = i + 1;
            break;
        }
    }
    for(int i = m - 1; i >= 0; i--){
        if(now != 1 && mp[i][now * 2 - 3] == '-'){
            now--;
        }else if(now != n && mp[i][now * 2 - 1] == '-'){
            now++;
        }
    }
    cout << now << "\n";
}