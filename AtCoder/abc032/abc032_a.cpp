#include <iostream>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    int a, b, n;
    cin >> a;
    cin >> b;
    cin >> n;
    int lcm = a * b / gcd(a, b);
    if(n % lcm == 0){
        cout << n << "\n";
        return 0;
    }
    cout << lcm * (n / lcm + 1) << "\n";
}