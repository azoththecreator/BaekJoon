/*

10872. 팩토리얼

[문제]
0보다 크거나 같은 정수 N이 주어진다.
이때, N!을 출력하는 프로그램을 작성하시오.

[입력]
첫째 줄에 정수 N(0 ≤ N ≤ 12)이 주어진다.

[출력]
첫째 줄에 N!을 출력한다.

*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n <= 1)
    {
        cout << 1;
        return 0;
    }

    int fact = 1;
    for (int i = 2; i <= n; ++i)
        fact *= i;
    cout << fact;

    return 0;
}