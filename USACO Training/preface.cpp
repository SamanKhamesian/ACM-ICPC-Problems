#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <fstream>

using namespace std;

ifstream fin("preface.in");
ofstream fout("preface.out");

int n, x;
string ans = "";
map<char, int> num;
vector< pair<int, string> > roman;

void initialize()
{
    roman.push_back({1   , "I"});
    roman.push_back({4   , "IV"});
    roman.push_back({5   , "V"});
    roman.push_back({9   , "IX"});
    roman.push_back({10  , "X"});
    roman.push_back({40  , "XL"});
    roman.push_back({50  , "L"});
    roman.push_back({90  , "XC"});
    roman.push_back({100 , "C"});
    roman.push_back({400 , "CD"});
    roman.push_back({500 , "D"});
    roman.push_back({900 , "CM"});
    roman.push_back({1000, "M"});
}

void cal(string s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        num[s[i]]++;
    }
}

void print()
{
    if (num['I'] != 0) fout << 'I' << " " << num['I'] << endl;
    if (num['V'] != 0) fout << 'V' << " " << num['V'] << endl;
    if (num['X'] != 0) fout << 'X' << " " << num['X'] << endl;
    if (num['L'] != 0) fout << 'L' << " " << num['L'] << endl;
    if (num['C'] != 0) fout << 'C' << " " << num['C'] << endl;
    if (num['D'] != 0) fout << 'D' << " " << num['D'] << endl;
    if (num['M'] != 0) fout << 'M' << " " << num['M'] << endl;
}

int main()
{
    fin >> x;

    initialize();

    for (int j = 1; j <= x ; j++)
    {
        n = j;

        ans = "";

        while (n != 0)
        {
            for (int i = (int) roman.size() - 1; i >= 0; i--)
            {
                if (n >= roman[i].first)
                {
                    n -= roman[i].first;
                    ans += roman[i].second;
                    break;
                }
            }
        }

        cal(ans);
    }

    print();
}