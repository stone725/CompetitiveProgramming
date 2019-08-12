#include <iostream>
#include <map>

using namespace std;

long long g(int p){
    if(p == 1000) return 1789997546303;
    long long res = g(p + 1);
    if(res % 2 == 0) return res / 2;
    return res * 3 + 1;
}

int main(){
    int p;
    cin >> p;
    cout << g(p) << "\n";
}