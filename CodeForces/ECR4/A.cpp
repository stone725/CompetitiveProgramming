#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n, p, q;
    cin >> n >> p >> q;
    string str;
    cin >> str;
    vector<string> ans;

    if(q < p){
        swap(p, q);
    }

    for(int i = 0; i <= n / p; i++){
        if((n - i * p) % q) continue;
        for(int j = 0; j < i; j++){
            ans.push_back(str.substr(j * p, p));
        }
        for(int j = 0; j < (n - i * p) / q; j++){
            ans.push_back(str.substr(i * p + j * q, q));
        }
        break;
    }
    
    if(ans.empty()){
        cout << "-1\n";
        return 0;
    }

    cout << ans.size() << "\n";
    for(auto&& i : ans){
        cout << i << "\n";
    }
}