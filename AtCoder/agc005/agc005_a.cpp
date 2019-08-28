#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string str;
    cin >> str;
    stack<int> s;
    int g = 0;
    while(g < str.size()){
        if(str[g] == 'S'){
            s.push(g);
        }else{
            if(s.size() && str[s.top()] == 'S'){
                s.pop();
            }
            else{
                s.push(g);
            }
        }
        g++;
    }
    cout << s.size() << "\n";
}