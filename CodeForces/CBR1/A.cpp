#include <iostream>

using namespace std;

int main(){
    long long n, m, r;
    cin >> n >> m >> r;
    cout << (n / r + !!(n % r)) * (m / r + !!(m % r)) << "\n";
}