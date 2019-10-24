#include <iostream>

using namespace std;

int main(){
    int n, t, e;
    cin >> n >> t >> e;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(t - e <= (t + e) / x * x){
            cout << i << "\n";
            return 0;
        }
    }
    cout << "-1\n";
}