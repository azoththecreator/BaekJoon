/*

11727. 2×n 타일링 2

[문제]
2×n 직사각형을 1×2, 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

[입력]
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

[출력]
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int dp[n + 1];
    dp[1] = 1;
    int offset = 1;
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = (dp[i - 1] * 2 + offset) % 10007;
        offset *= -1;
    }
    cout << dp[n];

    return 0;
}