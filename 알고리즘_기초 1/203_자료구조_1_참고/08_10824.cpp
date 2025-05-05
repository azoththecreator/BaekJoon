/*

10824. 네 수

[문제]
네 자연수 A, B, C, D가 주어진다.
이때, A와 B를 붙인 수와 C와 D를 붙인 수의 합을 구하는 프로그램을 작성하시오.

두 수 A와 B를 합치는 것은 A의 뒤에 B를 붙이는 것을 의미한다.
즉, 20과 30을 붙이면 2030이 된다.

[입력]
첫째 줄에 네 자연수 A, B, C, D가 주어진다. (1 ≤ A, B, C, D ≤ 1,000,000)

[출력]
A와 B를 붙인 수와 C와 D를 붙인 수의 합을 출력한다.

*/

#include <iostream>

using namespace std;

int main()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long long _b = b, _d = d;
    int cnt_b = 1, cnt_d = 1;
    while (_b > 0)
    {
        _b /= 10;
        cnt_b *= 10;
    }
    while (_d > 0)
    {
        _d /= 10;
        cnt_d *= 10;
    }
    a = a * cnt_b + b;
    c = c * cnt_d + d;

    cout << a + c;

    return 0;
}