#include <iostream>

using namespace std;

int main(){
    int l, h;
    cin >> l >> h;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(h < a){
            cout << -1 << "\n";
        }else if(l <= a){
            cout << 0 << "\n";
        }else{
            cout << l - a << "\n";
        }
    }
}