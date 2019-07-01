#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str;
    cin >> str;
    int t;
    cin >> t;
    int x = count(begin(str), end(str), 'L') - count(begin(str), end(str), 'R');
    int y = count(begin(str), end(str), 'U') - count(begin(str), end(str), 'D');
    if(t == 1){
        cout << abs(x) + abs(y) + count(begin(str), end(str), '?') << "\n";
    }else{
        int change = count(begin(str), end(str), '?');
        if(abs(x) + abs(y) <= change){
            cout << (change - abs(x) - abs(y)) % 2 << "\n";
        }else{
            cout << abs(x) + abs(y) - change << "\n";
        }
    }
}