#include <iostream>

using namespace std;

int main(){
    int a, b, k;
    cin >> a >> b >> k;
    for(int i = 0; i < k; i++){
        if(i % 2){
            a += b /= 2;
        }else{
            b += a /= 2;            
        }
    }
    cout << a << " " << b << "\n";
}