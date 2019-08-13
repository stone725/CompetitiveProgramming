#include <bits/stdc++.h>

using namespace std;

struct NBAFinals {
  vector<int> scores;
  string team;
  int dubsAgain(vector<int> _scores, string _team) {
    scores = _scores, team = _team;
    int score = 0;
    for(int i = 0; i < scores.size(); i++){
        if(team[i] == '?'){
            if(scores[i] == 0){
                scores[i] = 4;
            }
            score += scores[i];
        }else if(team[i] == 'W'){
            if(scores[i] == 0){
                scores[i] = 4;
            }
            score += scores[i];
        }else{
            if(scores[i] == 0){
                scores[i] = 1;
            }
            score -= scores[i];
        }
    }
    if(0 < score) return 1;
    return 0;
  }
};

// CUT begin
using namespace std;
char do_test(vector<int>,string,int,int,bool);
//------------------------------------------------------------------------------

char run_testcase(int __no) {
 vector<int> scores;
 string team;
 int __expected = 0;
 bool __unknownAnswer = false;
     
 switch (__no) {
  case 0: {
    scores = { 2,2,3,3,2,4,2 };
    team = "RRWWRWR";
 
    __expected = 1;
    break;
  }
  case 1: {
    scores = { 2,2,3,3,2,3,3 };
    team = "RRWWRWR";
 
    __expected = 0;
    break;
  }
  case 2: {
    scores = { 0,3 };
    team = "WR";
 
    __expected = 1;
    break;
  }
  case 3: {
    scores = { 3,0,0 };
    team = "RWR";
 
    __expected = 0;
    break;
  }
  case 4: {
    scores = { 0,0,0,0 };
    team = "????";
 
    __expected = 1;
    break;
  }
  case 5: {
    scores = { 3,2,3,2 };
    team = "?WR?";
 
    __expected = 1;
    break;
  }
  case 6: {
    scores = { 0,1,2,3,4 };
    team = "R?W?R";
 
    __expected = 1;
    break;
  }
  /*case 7: { 
    // Your custom testcase goes here (don't forget to add to num/runTests below)
    scores = ;
    team = ;
      
    __unknownAnswer = true; 
    break;
  }*/
 
  default: return 'm';
 }
 return do_test(scores, team, __expected, __no, __unknownAnswer);
}
 
// Tests total:
int      numTests  = 7;
// Tests to run when there are no arguments:
set<int> runTests = { 0, 1, 2, 3, 4, 5, 6 };
 
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
 
char do_test(vector<int> scores, string team, int __expected, int __caseNo, bool __unknownAnswer) {
    setColor(COL_CYAN);
    cout << "Test " << __caseNo;
    setColor(COL_WHITE);
    cout << ": [" << scores << ","<< pretty_print(team)  << "]" << endl;
 
    NBAFinals *__instance = new NBAFinals();
    int __result = __instance->dubsAgain(scores, team);
    delete __instance;
 
    bool __correct = __unknownAnswer || (__result == __expected);
 
    if (! __correct) {
        cout << "Desired answer:" << endl;
        cout << "\t" <<  pretty_print(__expected)  << endl;
    }
    cout << "Your answer:" << endl;
 cout << "\t" <<  pretty_print(__result)  << endl; 
 
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
    cout << "NBAFinals: ";
    bool good = true;
    for (char ch: result) {
        good &= ( ch == '?' || ch == '+' );
        cout << colorTestResult(ch);
    }
 
    cout << endl;
    return 0;
}
// CUT end
