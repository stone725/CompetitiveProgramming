#include <iostream>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    x *= 100;
    for(int i = 1; i <= n; i++){
        int v, p;
        cin >> v >> p;
        x -= v * p;
        if(x < 0){
            cout << i << "\n";
            return 0;
        }
    }
    cout << "-1\n";
}