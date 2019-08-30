#include <iostream>

using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    for(int i = 0; i <= x; i += 3){
        if((y - (i / 3)) % 3 == 0 && (y - (i / 3)) / 3 == (x - i)){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}