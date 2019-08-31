#include <iostream>

using namespace std;

int main(){
    int a, b, t;
    cin >> a >> b >> t;
    int num = b - a;
    while(b < t){
        b += num;
    }
    cout << b << "\n";
}