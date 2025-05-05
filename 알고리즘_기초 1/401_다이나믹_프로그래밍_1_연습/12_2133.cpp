/*

2133. 타일 채우기

[문제]
3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.

[입력]
첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.

[출력]
첫째 줄에 경우의 수를 출력한다.

*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 0;

    for (int i = 2; i <= n; ++i)
    {
        dp[i] = 0;
        if (i % 2 == 0)
        {
            for (int j = 0; j < i; j += 2)
                dp[i] += dp[j] * 2;
            dp[i] += dp[i - 2];
        }
    }
    cout << dp[n];

    return 0;
}