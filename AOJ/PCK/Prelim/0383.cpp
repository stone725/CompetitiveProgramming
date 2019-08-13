#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a, b, x;
    cin >> a >> b >> x;
    b = min(a, b);
    a = min(a, b * 2);
    cout << (x / 1000) * a + min(((x % 1000) / 500) * b + !!(x % 500) * b, !!(x % 1000) * a) << "\n";
}