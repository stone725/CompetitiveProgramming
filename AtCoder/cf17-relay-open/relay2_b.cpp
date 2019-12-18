#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        if(n == 1 || a == 1){
            cout << a << "\n";
            continue;
        }
        while(a != b){
            if(b < a){
                swap(a, b);
            }
            if(b % n <= 1){
                b /= n;
            }else{
                b /= n;
                b++;
            }
        }
        cout << a << "\n";
    }
}