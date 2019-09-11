#include <bits/stdc++.h>

using namespace std;

int d;
vector<int> r;
vector<int> c;

bool comp(int left, int right){
      return r[left] < r[right];
}

struct QueenMeetup {
  

  vector<int> move(int _d, vector<int> _r, vector<int> _c) {
    d = _d, r = _r, c = _c;
    map<int, vector<int>> check;
    vector<int> ans;
    for(int i = 0; i < r.size(); i++){
        check[c[i]].push_back(i);
    }
    int cnt = 0;
    for(auto&& i : check){
        sort(begin(i.second), end(i.second), comp);
        for(int j = 0; j < i.second.size(); j++){
            if(r[i.second[j]] == j){
                continue;
            }
            ans.push_back(i.second[j]);
            ans.push_back(j);
            ans.push_back(i.first);
            r[i.second[j]] = j;
        }
        if(i.first != cnt){
            for(int j = 0; j < i.second.size(); j++){
                ans.push_back(i.second[j]);
                ans.push_back(j);
                ans.push_back(cnt);
                c[i.second[j]] = cnt;
            }
        }
        cnt++;
    }
    return ans;
  }
};

// CUT begin
using namespace std;
char do_test(int,vector<int>,vector<int>,vector<int>,int,bool);
//------------------------------------------------------------------------------

char run_testcase(int __no) {
 int d;
 vector<int> r;
 vector<int> c;
 vector<int> __expected = vector<int>();
 bool __unknownAnswer = false;
     
 switch (__no) {
  case 0: {
    d = 5;
    r = { 0,1,3 };
    c = { 0,1,3 };
 
    __expected = { 0, 2, 0, 0, 2, 2 };
    break;
  }
  case 1: {
    d = 5;
    r = { 0,0,4,4 };
    c = { 0,4,4,0 };
 
    __expected = { 2, 1, 1, 3, 2, 0, 1, 0, 1 };
    break;
  }
  case 2: {
    d = 1000;
    r = { 42 };
    c = { 47 };
 
    __expected = { };
    break;
  }
  case 3: {
    d = 1234567;
    r = { 123456,123457,123456 };
    c = { 654321,654322,654323 };
 
    __expected = { };
    break;
  }
  case 4: {
    d = 100;
    r = { 4,2,10,5,1,3,9,17 };
    c = { 0,1,2,3,4,5,6,7 };
 
    __expected = { 0, 0, 0, 1, 0, 1, 2, 0, 2, 3, 0, 3, 4, 0, 4, 5, 0, 5, 6, 0, 6, 7, 0, 7 };
    break;
  }
  case 5: {
    d = 6;
    r = { 0,1,3 };
    c = { 0,1,3 };
 
    __expected = { 2, 2, 2 };
    break;
  }
  /*case 6: { 
    // Your custom testcase goes here (don't forget to add to num/runTests below)
    d = ;
    r = ;
    c = ;
      
    __unknownAnswer = true; 
    break;
  }*/
 
  default: return 'm';
 }
 return do_test(d, r, c, __expected, __no, __unknownAnswer);
}
 
// Tests total:
int      numTests  = 6;
// Tests to run when there are no arguments:
set<int> runTests = { 0, 1, 2, 3, 4, 5 };
 
//------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <ctime>
#include <windows.h>

#define     COL_BLACK   0x00
#define     COL_DARK_BLUE       0x01
#define     COL_DARK_GREEN 0x02
#define     COL_DARK_CYAN       0x03
#define     COL_DARK_RED     0x04
#define     COL_DARK_VIOLET0x05
#define     COL_DARK_YELLOW   0x06
#define     COL_GRAY 0x07
#define     COL_LIGHT_GRAY      0x08
#define     COL_BLUE     0x09
#define     COL_GREEN   0x0a
#define     COL_CYAN     0x0b
#define     COL_RED      0x0c
#define     COL_VIOLET  0x0d
#define     COL_YELLOW 0x0e
#define     COL_WHITE   0x0f
#define     COL_INTENSITY     0x08
#define     COL_RED_MASK     0x04
#define     COL_GREEN_MASK 0x02
#define     COL_BLUE_MASK   0x01

void setColor(int col)
{
    HANDLE hCons = GetStdHandle( STD_OUTPUT_HANDLE );
    WORD attr = 0;
    if( col & COL_INTENSITY )
        attr |= FOREGROUND_INTENSITY;
    if( col & COL_RED_MASK )
        attr |= FOREGROUND_RED;
    if( col & COL_GREEN_MASK )
        attr |= FOREGROUND_GREEN;
    if( col & COL_BLUE_MASK )
        attr |= FOREGROUND_BLUE;
    SetConsoleTextAttribute(hCons, attr);
}

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }
// Vector print
template <typename T> ostream &operator << (ostream &out, vector<T> arr) {
    out << "{";
    for (int i = 0; i < arr.size(); ++i) out << (i == 0 ? "" : ",") << pretty_print(arr[i]);
    out << "}";
    return out;
}
 
string colorString(string s, int q)
{
    if (q == 0) {
        //neutral
        setColor(COL_WHITE);
        return s;
    } else if (q < -1) {
        //bad (score)
        setColor(COL_GREEN);
        return s;
    } else if (q < 0) {
        //bad (single result)
        setColor(COL_RED);
        return s;
    } else {
        //good
        setColor(COL_GREEN);
        return s;
    }
}
 
string colorTestResult(char r)
{
    string s = string(1, r);
    switch(r) {
        case '+' :
            return colorString(s, 1);
        case '?':
            return colorString(s, 0);
        default :
            return colorString(s, -1);
    }
    return "";
}
 
char do_test(int d, vector<int> r, vector<int> c, vector<int> __expected, int __caseNo, bool __unknownAnswer) {
    setColor(COL_CYAN);
    cout << "Test " << __caseNo;
    setColor(COL_WHITE);
    cout << ": [" << pretty_print(d) << ","<< r << ","<< c  << "]" << endl;
 
    QueenMeetup *__instance = new QueenMeetup();
    vector<int> __result = __instance->move(d, r, c);
    delete __instance;
 
    bool __correct = __unknownAnswer || (__result == __expected);
 
    if (! __correct) {
        cout << "Desired answer:" << endl;
        cout << "\t" <<  __expected  << endl;
    }
    cout << "Your answer:" << endl;
 cout << "\t" <<  __result  << endl; 
 
    char __res = '-';
    if (! __correct) {
        __res = 'X';
    } else if (__unknownAnswer) {
        __res = '?';
    } else {
        __res = '+';
    }
    cout << " "<<colorTestResult(__res)<<endl;
     
    cout << colorString("===============================================================", 0) << endl;
    return __res;
}
 
int main(int argc, char *argv[]) {
    string result;
    if (argc > 1) {
        runTests.clear();
        for (int i = 1; i < argc; ++i) {
            runTests.insert(atoi(argv[i])); 
        }
    }
    int j = 0;
    for (int i: runTests) {
        while (j < i) {
            result += 'd';
            j++;
        }
        result += run_testcase(i);
        j = i + 1;
    }
    result += string( std::max(0, numTests - j), 'd' );
    cout << "QueenMeetup: ";
    bool good = true;
    for (char ch: result) {
        good &= ( ch == '?' || ch == '+' );
        cout << colorTestResult(ch);
    }
 
    cout << endl;
    return 0;
}
// CUT end
