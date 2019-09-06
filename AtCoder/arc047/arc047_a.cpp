#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, l;
    cin >> n >> l;
    string str;
    cin >> str;
    int tab = 1, ans = 0;
    for(auto&& i : str){
        if(i == '+'){
            tab++;
            if(l < tab){
                ans++;
                tab = 1;
            }
        }else{
            tab--;
        }
    }
    cout << ans << "\n";
}