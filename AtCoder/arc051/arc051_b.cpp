#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int k;
    cin >> k;
    long long a = 1, b = 1;
    for(int i = 0; i < k; i++){
        swap(a, b);
        a += b;
    }
    cout << a << " " << b << "\n";
}