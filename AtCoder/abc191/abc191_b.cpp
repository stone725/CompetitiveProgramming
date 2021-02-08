#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, x;
    vector<int> ans;
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a != x){
            ans.push_back(a);
        }
    }
    if(ans.empty()){
        cout << "\n";
        return 0;
    }
    cout << ans[0];
    for(int i = 1; i < ans.size(); i++){
        cout << " " << ans[i];
    }
    cout << "\n";
}