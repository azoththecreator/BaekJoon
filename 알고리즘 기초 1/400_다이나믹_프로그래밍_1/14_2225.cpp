/*

2225. 합분해

[문제]
0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 프로그램을 작성하시오.

덧셈의 순서가 바뀐 경우는 다른 경우로 센다(1+2와 2+1은 서로 다른 경우).
또한 한 개의 수를 여러 번 쓸 수도 있다.

[입력]
첫째 줄에 두 정수 N(1 ≤ N ≤ 200), K(1 ≤ K ≤ 200)가 주어진다.

[출력]
첫째 줄에 답을 1,000,000,000으로 나눈 나머지를 출력한다.

*/

#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    long long dp[n + 1][k + 1];
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
            dp[i][j] = 0;
    }
    
    for (int j = 0; j <= k; ++j)
        dp[0][j] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            for (int l = 0; l <= i; ++l)
                dp[i][j] = (dp[i][j] + dp[i - l][j - 1]) % 1000000000LL;
        }
    }
    cout << dp[n][k];

    return 0;
}