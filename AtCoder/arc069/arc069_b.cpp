#include <iostream>
#include <string>

using namespace std;

int n;
string str;

string check(int now, char c, char last, char before, char start){
    if(now == n - 1){
        if(c != last){
            return "";
        }
        if(str[now] == 'o'){
            if((before == start && c == 'S') || (before != start && c == 'W')){
                return string(1, c);
            }else{
                return "";
            }
        }else{
            if((before != start && c == 'S') || (before == start && c == 'W')){
                return string(1, c);
            }else{
                return "";
            }
        }
    }
    if(now == 0){
        string res = "";
        if(str[now] == 'o'){
            if(c == 'S'){
                res = c + check(now + 1, 'S', 'S', c, start);
                if(res.size() < n){
                    res = c + check(now + 1, 'W', 'W', c, start);
                }
            }else{
                res = c + check(now + 1, 'W', 'S', c, start);
                if(res.size() < n){
                    res = c + check(now + 1, 'S', 'W', c, start);
                }
            }
        }else{
            if(c == 'W'){
                res = c + check(now + 1, 'S', 'S', c, start);
                if(res.size() < n){
                    res = c + check(now + 1, 'W', 'W', c, start);
                }
            }else{
                res = c + check(now + 1, 'W', 'S', c, start);
                if(res.size() < n){
                    res = c + check(now + 1, 'S', 'W', c, start);
                }
            } 
        }
        return res;
    }
    if(str[now] == 'o'){
        if(c == 'S'){
            return c + check(now + 1, before, last, c, start);
        }else if(before == 'S'){
            return c + check(now + 1, 'W', last, c, start);
        }else{
            return c + check(now + 1, 'S', last, c, start);
        }
    }else{
        if(c == 'W'){
            return c + check(now + 1, before, last, c, start);
        }else if(before == 'S'){
            return c + check(now + 1, 'W', last, c, start);
        }else{
            return c + check(now + 1, 'S', last, c, start);
        }
    }
}

int main(){
    cin >> n;
    cin >> str;
    string s = check(0, 'S', '_', '_', 'S');
    if(s.size() < n){
        s = check(0, 'W', '_', '_', 'W');
        if(s.size() < n){
            cout << "-1\n";
            return 0;
        }
    }
    cout << s << "\n";
}