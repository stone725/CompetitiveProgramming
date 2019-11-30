#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    if(x < y){
        int add = min(y - x, z);
        x += add;
        z -= add;
    }else if(y < x){
        int add = min(x - y, z);
        y += add;
        z -= add;
    }
    cout << min(x, y) + z / 2 << "\n";
}