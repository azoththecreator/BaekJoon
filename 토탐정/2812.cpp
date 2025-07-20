/*

2812. 크게 만들기

[문제]
N자리 숫자가 주어졌을 때, 여기서 숫자 K개를 지워서 얻을 수 있는 가장 큰 수를 구하는 프로그램을 작성하시오.

[입력]
첫째 줄에 N과 K가 주어진다. (1 ≤ K < N ≤ 500,000)

둘째 줄에 N자리 숫자가 주어진다. 이 수는 0으로 시작하지 않는다.

[출력]
입력으로 주어진 숫자에서 K개를 지웠을 때 얻을 수 있는 가장 큰 수를 출력한다.

*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    string num;
    cin >> num;

    stack<char> s;
    int idx = 0;
    while (k > 0)
    {
        if (idx >= num.length())
        {
            s.pop();
            --k;
            continue;
        }

        char c = num[idx];
        while (s.size() > 0 && c > s.top() && k > 0)
        {
            s.pop();
            --k;
        }

        s.push(c);
        ++idx;
    }
    while (idx < num.length())
    {
        s.push(num[idx]);
        ++idx;
    }

    stack<char> reversed;
    while (s.size() > 0)
    {
        reversed.push(s.top());
        s.pop();
    }

    while (reversed.size() > 0)
    {
        cout << reversed.top();
        reversed.pop();
    }

    return 0;
}