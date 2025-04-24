/*

1373. 2진수 8진수

[문제]
2진수가 주어졌을 때, 8진수로 변환하는 프로그램을 작성하시오.

[입력]
첫째 줄에 2진수가 주어진다.
주어지는 수의 길이는 1,000,000을 넘지 않는다.

[출력]
첫째 줄에 주어진 수를 8진수로 변환하여 출력한다.

*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string b;
    cin >> b;

    if (b.size() % 3 != 0)
    {
        int padding = 3 - (b.size() % 3);
        b = string(padding, '0') + b;
    }

    string o;
    for (int i = 0; i < b.size(); i += 3)
    {
        int tmp = (b[i] - '0') * 4 + (b[i + 1] - '0') * 2 + (b[i + 2] - '0');
        o += string(1, tmp + '0');
    }

    while (o[0] == '0' && o.size() > 1)
        o = o.substr(1);

    cout << o;

    return 0;
}