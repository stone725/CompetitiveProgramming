#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int>> o(h), g(w);
    vector<pair<int, int>> jewel;
    for(int i = 0; i < h; i++){
        string str;
        cin >> str;
        for(int j = 0; j < w; j++){
            if(str[j] == 'J'){
                jewel.push_back(make_pair(i, j));
            }else if(str[j] == 'O'){
                o[i].push_back(j);
            }else{
                g[j].push_back(i);
            }
        }
    }
    long long ans = 0;
    for(auto&& i : jewel){
        int a = (end(o[i.first]) - lower_bound(begin(o[i.first]), end(o[i.first]), i.second)), b = (end(g[i.second]) - lower_bound(begin(g[i.second]), end(g[i.second]), i.first));
        ans += a * b;
    }
    cout << ans << "\n";
}