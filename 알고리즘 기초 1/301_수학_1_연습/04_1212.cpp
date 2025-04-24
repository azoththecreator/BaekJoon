/*

1212. 8진수 2진수

[문제]
8진수가 주어졌을 때, 2진수로 변환하는 프로그램을 작성하시오.

[입력]
첫째 줄에 8진수가 주어진다.
주어지는 수의 길이는 333,334을 넘지 않는다.

[출력]
첫째 줄에 주어진 수를 2진수로 변환하여 출력한다.
수가 0인 경우를 제외하고는 반드시 1로 시작해야 한다.

*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string o;
    cin >> o;

    string b;
    for (int i = 0; i < o.size(); ++i)
    {
        int tmp = o[i] - '0';
        if (tmp >= 4)
        {
            b += "1";
            tmp -= 4;
        }
        else
            b += "0";
        if (tmp >= 2)
        {
            b += "1";
            tmp -= 2;
        }
        else
            b += "0";
        if (tmp >= 1)
            b += "1";
        else
            b += "0";
    }

    while (b[0] == '0' && b.size() > 1)
        b = b.substr(1);

    cout << b;

    return 0;
}