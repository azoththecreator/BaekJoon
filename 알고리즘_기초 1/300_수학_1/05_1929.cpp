/*

1929. 소수 구하기

[문제]
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

[입력]
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000)
M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

[출력]
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.

*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    for (int i = m; i <= n; ++i)
    {
        if (i == 1)
            continue;

        int sq = sqrt(i);
        bool is_prime = true;
        for (int j = 2; j < sq + 1; ++j)
        {
            if (i % j == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            cout << i << '\n';
    }

    return 0;
}