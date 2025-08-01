/*

10808. 알파벳 개수

[문제]
알파벳 소문자로만 이루어진 단어 S가 주어진다.
각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는 프로그램을 작성하시오.

[입력]
첫째 줄에 단어 S가 주어진다.
단어의 길이는 100을 넘지 않으며, 알파벳 소문자로만 이루어져 있다.

[출력]
단어에 포함되어 있는 a의 개수, b의 개수, …, z의 개수를 공백으로 구분해서 출력한다.

*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<char, int> um;
    for (int i = 0; i < 26; ++i)
        um['a' + i] = 0;

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); ++i)
    {
        ++um[s[i]];
    }

    for (int i = 0; i < 26; ++i)
        cout << um['a' + i] << ' ';

    return 0;
}