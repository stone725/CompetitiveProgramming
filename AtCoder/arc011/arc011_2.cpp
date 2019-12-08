#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    bool output = false;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        string ans = "";
        for(auto&& j : str){
            if(j == 'B' || j == 'b' || j == 'C' || j == 'c'){
                ans += '1';
            }
            if(j == 'D' || j == 'd' || j == 'W' || j == 'w'){
                ans += '2';
            }
            if(j == 'T' || j == 't' || j == 'J' || j == 'j'){
                ans += '3';
            }
            if(j == 'F' || j == 'f' || j == 'Q' || j == 'q'){
                ans += '4';
            }
            if(j == 'L' || j == 'l' || j == 'V' || j == 'v'){
                ans += '5';
            }
            if(j == 'S' || j == 's' || j == 'X' || j == 'x'){
                ans += '6';
            }
            if(j == 'P' || j == 'p' || j == 'M' || j == 'm'){
                ans += '7';
            }
            if(j == 'H' || j == 'h' || j == 'K' || j == 'k'){
                ans += '8';
            }
            if(j == 'N' || j == 'n' || j == 'G' || j == 'g'){
                ans += '9';
            }
            if(j == 'Z' || j == 'z' || j == 'R' || j == 'r'){
                ans += '0';
            }
        }
        if(output && ans != ""){
            cout << " " << ans;
        }else if(ans != ""){
            cout << ans;
            output = true;
        }
    }
    cout << "\n";
}