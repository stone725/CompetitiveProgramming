#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string str;
    cin >> str;
    int ans = str.size();
    stack<int> s;
    int g = 0;
    while(g < str.size()){
        if(str[g] == 'S'){
            s.push(g);
        }else{
            if(s.size() && str[s.top()]){
                s.pop();
                ans -= 2;
            }
        }
        g++;
    }
    cout << ans << "\n";
}