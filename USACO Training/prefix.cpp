#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include <fcntl.h>

using namespace std;

int sz;
#define MAX 200005
char input[MAX];
string example = "";
vector<string> words;
bool isCheck[MAX] = {false};

ifstream fin("prefix.in");
ofstream fout("prefix.out");

int main()
{
    string s;

    while (fin >> s && s != ".")
    {
        words.push_back(s);
    }

    while (fin >> s)
    {
        example += s;
    }

    for (int i = 0; i <= (int)example.size(); ++i)
    {
        for (int j = 0; j < words.size(); ++j)
        {
            int start = (i - words[j].length());

            if (start < 0)
            {
                continue;
            }

            if (example.substr(start, words[j].length()) != words[j])
            {
                continue;
            }

            if (start > 0 && !isCheck[start])
            {
                continue;
            }

            isCheck[i] = true;
            sz = i;
            break;

        }
    }

    fout << sz << endl;
}