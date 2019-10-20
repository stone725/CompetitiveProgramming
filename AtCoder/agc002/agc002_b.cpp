#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> many(n, 1);
    vector<bool> red(n, false);
    red[0] = true;
    while(m--){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(red[a]){
            red[b] = true;
        }
        many[a]--;
        many[b]++;
        if(!many[a]){
            red[a] = false;
        }
    }
    int ans = 0;
    for(auto&& i : red){
        ans += i;
    }
    cout << ans << "\n";
}