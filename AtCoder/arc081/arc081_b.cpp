#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    string str[2];
    for(auto&& i : str){
        cin >> i;
    }
    long long ans = 1;
    static const int INF = 1e9 + 7;
    bool before;
    for(int x = 0; x < n; x++){
        if(str[0][x] == str[1][x]){
            if(x == 0){
                ans *= 3;
            }else{
                if(before){
                    ans *= 2;
                }
            }
            before = true;
        }else{
            if(x == 0){
                ans *= 6;
            }else{
                if(before){
                    ans *= 2;
                }else{
                    ans *= 3;
                }
            }
            x++;
            before = false;
        }
        ans %= INF;
    }
    cout << ans << "\n";
}