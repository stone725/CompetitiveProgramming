#include <iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int p = 0;
    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        p += a;
        if(n < p){
            p = n - p % n;
        }
        if(n == p){
            break;
        }
    }
    cout << p << "\n";
}