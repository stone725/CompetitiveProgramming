#include <bits/stdc++.h>

using namespace std;

struct BinaryDistance
{
    int N;
    int V;
    int maxDist(int _N, int _V)
    {
        N = _N, V = _V;
        int cnt = -1;
        set<int> s;
        bool check = false;
        for (int i = V; i > 1; i /= 2)
        {
            if (i == 2)
                check = true;
            cout << i << "\n";
            s.insert(i);
            cnt++;
        }
        for (int i = 1; i <= N; i *= 2)
        {
            cout << i << "\n";
            if (i == 2)
                i += check;
            if (N < i)
                break;
            ;
            cnt++;
        }
        return cnt;
    }
};

// CUT begin
using namespace std;
char do_test(int, int, int, int, bool);
//------------------------------------------------------------------------------

char run_testcase(int __no)
{
    int N;
    int V;
    int __expected = 0;
    bool __unknownAnswer = false;

    switch (__no)
    {
    case 0:
    {
        N = 6;
        V = 2;

        __expected = 3;
        break;
    }
    case 1:
    {
        N = 6;
        V = 6;

        __expected = 4;
        break;
    }
    case 2:
    {
        N = 5;
        V = 4;

        __expected = 3;
        break;
    }
    case 3:
    {
        N = 2;
        V = 2;

        __expected = 1;
        break;
    }
    case 4:
    {
        N = 1000000000;
        V = 1;

        __expected = 29;
        break;
    }
    case 5:
    {
        N = 20;
        V = 7;

        __expected = 6;
        break;
    }
    case 6:
    {
        N = 12;
        V = 4;

        __expected = 5;
        break;
    }
        /*case 7: { 
    // Your custom testcase goes here (don't forget to add to num/runTests below)
    N = ;
    V = ;
      
    __unknownAnswer = true; 
    break;
  }*/

    default:
        return 'm';
    }
    return do_test(N, V, __expected, __no, __unknownAnswer);
}

// Tests total:
int numTests = 7;
// Tests to run when there are no arguments:
set<int> runTests = {0, 1, 2, 3, 4, 5, 6};

//------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <ctime>
#include <windows.h>

#define COL_BLACK 0x00
#define COL_DARK_BLUE 0x01
#define COL_DARK_GREEN 0x02
#define COL_DARK_CYAN 0x03
#define COL_DARK_RED 0x04
#define COL_DARK_VIOLET0x05
#define COL_DARK_YELLOW 0x06
#define COL_GRAY 0x07
#define COL_LIGHT_GRAY 0x08
#define COL_BLUE 0x09
#define COL_GREEN 0x0a
#define COL_CYAN 0x0b
#define COL_RED 0x0c
#define COL_VIOLET 0x0d
#define COL_YELLOW 0x0e
#define COL_WHITE 0x0f
#define COL_INTENSITY 0x08
#define COL_RED_MASK 0x04
#define COL_GREEN_MASK 0x02
#define COL_BLUE_MASK 0x01

void setColor(int col)
{
    HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD attr = 0;
    if (col & COL_INTENSITY)
        attr |= FOREGROUND_INTENSITY;
    if (col & COL_RED_MASK)
        attr |= FOREGROUND_RED;
    if (col & COL_GREEN_MASK)
        attr |= FOREGROUND_GREEN;
    if (col & COL_BLUE_MASK)
        attr |= FOREGROUND_BLUE;
    SetConsoleTextAttribute(hCons, attr);
}

template <typename T>
string pretty_print(T t)
{
    stringstream s;
    typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t;
    return s.str();
}

string colorString(string s, int q)
{
    if (q == 0)
    {
        //neutral
        setColor(COL_WHITE);
        return s;
    }
    else if (q < -1)
    {
        //bad (score)
        setColor(COL_GREEN);
        return s;
    }
    else if (q < 0)
    {
        //bad (single result)
        setColor(COL_RED);
        return s;
    }
    else
    {
        //good
        setColor(COL_GREEN);
        return s;
    }
}

string colorTestResult(char r)
{
    string s = string(1, r);
    switch (r)
    {
    case '+':
        return colorString(s, 1);
    case '?':
        return colorString(s, 0);
    default:
        return colorString(s, -1);
    }
    return "";
}

char do_test(int N, int V, int __expected, int __caseNo, bool __unknownAnswer)
{
    setColor(COL_CYAN);
    cout << "Test " << __caseNo;
    setColor(COL_WHITE);
    cout << ": [" << pretty_print(N) << "," << pretty_print(V) << "]" << endl;

    BinaryDistance *__instance = new BinaryDistance();
    int __result = __instance->maxDist(N, V);
    delete __instance;

    bool __correct = __unknownAnswer || (__result == __expected);

    if (!__correct)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << pretty_print(__expected) << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << pretty_print(__result) << endl;

    char __res = '-';
    if (!__correct)
    {
        __res = 'X';
    }
    else if (__unknownAnswer)
    {
        __res = '?';
    }
    else
    {
        __res = '+';
    }
    cout << " " << colorTestResult(__res) << endl;

    cout << colorString("===============================================================", 0) << endl;
    return __res;
}

int main(int argc, char *argv[])
{
    string result;
    if (argc > 1)
    {
        runTests.clear();
        for (int i = 1; i < argc; ++i)
        {
            runTests.insert(atoi(argv[i]));
        }
    }
    int j = 0;
    for (int i : runTests)
    {
        while (j < i)
        {
            result += 'd';
            j++;
        }
        result += run_testcase(i);
        j = i + 1;
    }
    result += string(std::max(0, numTests - j), 'd');
    cout << "BinaryDistance: ";
    bool good = true;
    for (char ch : result)
    {
        good &= (ch == '?' || ch == '+');
        cout << colorTestResult(ch);
    }

    cout << endl;
    return 0;
}
// CUT end
