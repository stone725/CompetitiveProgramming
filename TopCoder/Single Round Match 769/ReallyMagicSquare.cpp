#include <bits/stdc++.h>

using namespace std;

struct ReallyMagicSquare
{
    vector<int> topRow;
    vector<int> mainDiagonal;
    vector<int> reconstruct(vector<int> _topRow, vector<int> _mainDiagonal)
    {
        topRow = _topRow, mainDiagonal = _mainDiagonal;
        int n = topRow.size();
        long long sum = accumulate(begin(mainDiagonal), end(mainDiagonal), 0);
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            ans[0][i] = topRow[i];
            ans[i][i] = mainDiagonal[i];
        }
        for (int i = 1; i < n; i++)
        {
            ans[i][0] = sum;
            for (int j = 1; j < n; j++)
            {
                if (i == j)
                {
                    ans[i][0] -= ans[0][j];
                }
                else
                {
                    ans[i][0] -= ans[j][j];
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (i == j)
                    continue;
                ans[i][j] = sum;
                for (int k = 1; k < n; k++)
                {
                    if (i == k || j == k)
                        continue;
                    ans[i][j] -= ans[k][k];
                }
                ans[i][j] -= ans[0][i] + ans[j][0];
            }
        }
        vector<int> res;
        for (auto &&i : ans)
        {
            for (auto &&j : i)
            {
                res.push_back(j);
            }
        }
        return res;
    }
};

// CUT begin
using namespace std;
char do_test(vector<int>, vector<int>, vector<int>, int, bool);
//------------------------------------------------------------------------------

char run_testcase(int __no)
{
    vector<int> topRow;
    vector<int> mainDiagonal;
    vector<int> __expected = vector<int>();
    bool __unknownAnswer = false;

    switch (__no)
    {
    case 0:
    {
        topRow = {140, 80, 160, 60};
        mainDiagonal = {140, 30, 120, 50};

        __expected = {140, 80, 160, 60, 90, 30, 110, 10, 100, 40, 120, 20, 130, 70, 150, 50};
        break;
    }
    case 1:
    {
        topRow = {1, 7};
        mainDiagonal = {1, 4};

        __expected = {1, 7, -2, 4};
        break;
    }
    case 2:
    {
        topRow = {47, 47, 47, 47, 47};
        mainDiagonal = {47, 47, 47, 47, 47};

        __expected = {47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47};
        break;
    }
        /*case 3: { 
    // Your custom testcase goes here (don't forget to add to num/runTests below)
    topRow = ;
    mainDiagonal = ;
      
    __unknownAnswer = true; 
    break;
  }*/

    default:
        return 'm';
    }
    return do_test(topRow, mainDiagonal, __expected, __no, __unknownAnswer);
}

// Tests total:
int numTests = 3;
// Tests to run when there are no arguments:
set<int> runTests = {0, 1, 2};

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
// Vector print
template <typename T>
ostream &operator<<(ostream &out, vector<T> arr)
{
    out << "{";
    for (int i = 0; i < arr.size(); ++i)
        out << (i == 0 ? "" : ",") << pretty_print(arr[i]);
    out << "}";
    return out;
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

char do_test(vector<int> topRow, vector<int> mainDiagonal, vector<int> __expected, int __caseNo, bool __unknownAnswer)
{
    setColor(COL_CYAN);
    cout << "Test " << __caseNo;
    setColor(COL_WHITE);
    cout << ": [" << topRow << "," << mainDiagonal << "]" << endl;

    ReallyMagicSquare *__instance = new ReallyMagicSquare();
    vector<int> __result = __instance->reconstruct(topRow, mainDiagonal);
    delete __instance;

    bool __correct = __unknownAnswer || (__result == __expected);

    if (!__correct)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << __expected << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << __result << endl;

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
    cout << "ReallyMagicSquare: ";
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
