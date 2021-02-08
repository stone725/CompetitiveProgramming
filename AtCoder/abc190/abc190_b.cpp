#include <iostream>

using namespace std;

int main(){
    int n, s, d;
    cin >> n >> s >> d;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if(x < s && d < y){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}