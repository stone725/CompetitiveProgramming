#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        edge[a - 1].push_back(b - 1);
        edge[b - 1].push_back(a - 1);
    }
    for(auto&& i : edge[0]){
        for(auto&& j : edge[i]){
            if(j == n - 1){
                cout << "POSSIBLE\n";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}