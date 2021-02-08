#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string c[9];
    int x, y;
    string w;
    cin >> y >> x >> w;
    x--;
    y--;
    int dx = 0, dy = 0;
    if(w.find('R') != string::npos){
        dy++;
    }
    if(w.find('L') != string::npos){
        dy--;
    }
    if(w.find('U') != string::npos){
        dx--;
    }
    if(w.find('D') != string::npos){
        dx++;
    }
    for(auto&& i : c){
        cin >> i;
    }
    for(int i = 0; i < 4; i++){
        cout << c[x][y];
        if((x == 0 && dx < 0) || (x == 8 && 0 < dx)){
            dx = -dx;
        }
        if((y == 0 && dy < 0) || (y == 8 && 0 < dy)){
            dy = -dy;
        }
        x += dx;
        y += dy;
    }
    cout << "\n";
}