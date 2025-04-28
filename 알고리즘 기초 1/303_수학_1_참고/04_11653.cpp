/*

11653. 소인수분해

[문제]
정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.

[입력]
첫째 줄에 정수 N (1 ≤ N ≤ 10,000,000)이 주어진다.

[출력]
N의 소인수분해 결과를 한 줄에 하나씩 오름차순으로 출력한다.
N이 1인 경우 아무것도 출력하지 않는다.

*/

#include <iostream>

using namespace std;

bool is_prime(int n)
{
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    if (n == 1)
        return 0;

    while (n > 1)
    {
        for (int i = 2; i <= n; ++i)
        {
            if (n % i == 0 && is_prime(i))
            {
                cout << i << '\n';
                n /= i;
                break;
            }
        }
    }

    return 0;
}