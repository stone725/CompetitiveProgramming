#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, t = 0, x = 0, y = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int nextT, nextX, nextY;
        cin >> nextT >> nextX >> nextY;
        if(nextT - t >= abs(nextX - x) + abs(nextY - y) && ((nextT - t) - abs(nextX - x) - abs(nextY - y)) % 2 == 0){
            x = nextX;
            y = nextY;
            t = nextT;
        }else{
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}