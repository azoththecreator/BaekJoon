/*

16953. A → B

[문제]
정수 A를 B로 바꾸려고 한다. 가능한 연산은 다음과 같은 두 가지이다.

    - 2를 곱한다.
    - 1을 수의 가장 오른쪽에 추가한다.

A를 B로 바꾸는데 필요한 연산의 최솟값을 구해보자.

[입력]
첫째 줄에 A, B (1 ≤ A < B ≤ 10^9)가 주어진다.

[출력]
A를 B로 바꾸는데 필요한 연산의 최솟값에 1을 더한 값을 출력한다.
만들 수 없는 경우에는 -1을 출력한다.

*/

#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int cnt = 1;
    while (b > a)
    {
        if (b % 2 == 0)
        {
            b /= 2;
            ++cnt;
        }
        else if (b % 10 == 1)
        {
            b = (b - 1) / 10;
            ++cnt;
        }
        else
            break;
    }

    if (b == a)
        cout << cnt;
    else
        cout << -1;

    return 0;
}