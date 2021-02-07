#include <bits/stdc++.h>

using namespace std;

struct Alibi
{
    string murderRoom;
    int murderTime;
    vector<int> eventTime;
    vector<string> eventPerson;
    vector<string> eventRoom;
    string findMurderer(string _murderRoom, int _murderTime, vector<int> _eventTime, vector<string> _eventPerson, vector<string> _eventRoom)
    {
        murderRoom = _murderRoom, murderTime = _murderTime, eventTime = _eventTime, eventPerson = _eventPerson, eventRoom = _eventRoom;
        set<string> s;
        if (murderRoom == "Hall")
        {
            s.insert("White");
            s.insert("Green");
            s.insert("Peacock");
            s.insert("Plum");
            s.insert("Scarlett");
            s.insert("Mustard");
        }
        for (int i = 0; i < eventTime.size(); i++)
        {
            if (eventTime[i] <= murderTime)
            {
                if (eventRoom[i] == murderRoom)
                {
                    s.insert(eventPerson[i]);
                }
                else
                {
                    s.erase(eventPerson[i]);
                }
            }
        }
        if (s.size() == 1)
        {
            return *begin(s);
        }
        return "";
    }
};

// CUT begin
using namespace std;
char do_test(string, int, vector<int>, vector<string>, vector<string>, string, int, bool);
//------------------------------------------------------------------------------

char run_testcase(int __no)
{
    string murderRoom;
    int murderTime;
    vector<int> eventTime;
    vector<string> eventPerson;
    vector<string> eventRoom;
    string __expected = "";
    bool __unknownAnswer = false;

    switch (__no)
    {
    case 0:
    {
        murderRoom = "Library";
        murderTime = 10;
        eventTime = {5, 7, 9};
        eventPerson = {"Plum", "Scarlett", "Plum"};
        eventRoom = {"Library", "Library", "Cellar"};

        __expected = "Scarlett";
        break;
    }
    case 1:
    {
        murderRoom = "Library";
        murderTime = 10;
        eventTime = {};
        eventPerson = {};
        eventRoom = {};

        __expected = "";
        break;
    }
    case 2:
    {
        murderRoom = "Library";
        murderTime = 8;
        eventTime = {5, 7, 9};
        eventPerson = {"Plum", "Scarlett", "Plum"};
        eventRoom = {"Library", "Library", "Cellar"};

        __expected = "";
        break;
    }
    case 3:
    {
        murderRoom = "Hall";
        murderTime = 11;
        eventTime = {2, 4, 6, 8, 10, 12};
        eventPerson = {"White", "Green", "Peacock", "Plum", "Scarlett", "Mustard"};
        eventRoom = {"Kitchen", "Ballroom", "Conservatory", "Library", "Lounge", "Study"};

        __expected = "Mustard";
        break;
    }
    case 4:
    {
        murderRoom = "Library";
        murderTime = 10;
        eventTime = {3, 7};
        eventPerson = {"Plum", "Plum"};
        eventRoom = {"Library", "Library"};

        __expected = "Plum";
        break;
    }
        /*case 5: { 
    // Your custom testcase goes here (don't forget to add to num/runTests below)
    murderRoom = ;
    murderTime = ;
    eventTime = ;
    eventPerson = ;
    eventRoom = ;
      
    __unknownAnswer = true; 
    break;
  }*/

    default:
        return 'm';
    }
    return do_test(murderRoom, murderTime, eventTime, eventPerson, eventRoom, __expected, __no, __unknownAnswer);
}

// Tests total:
int numTests = 5;
// Tests to run when there are no arguments:
set<int> runTests = {0, 1, 2, 3, 4};

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

char do_test(string murderRoom, int murderTime, vector<int> eventTime, vector<string> eventPerson, vector<string> eventRoom, string __expected, int __caseNo, bool __unknownAnswer)
{
    setColor(COL_CYAN);
    cout << "Test " << __caseNo;
    setColor(COL_WHITE);
    cout << ": [" << pretty_print(murderRoom) << "," << pretty_print(murderTime) << "," << eventTime << "," << eventPerson << "," << eventRoom << "]" << endl;

    Alibi *__instance = new Alibi();
    string __result = __instance->findMurderer(murderRoom, murderTime, eventTime, eventPerson, eventRoom);
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
    cout << "Alibi: ";
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
