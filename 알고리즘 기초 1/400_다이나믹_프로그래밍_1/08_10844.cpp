/*

10844. 쉬운 계단 수

[문제]
45656이란 수를 보자.

이 수는 인접한 모든 자리의 차이가 1이다.
이런 수를 계단 수라고 한다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구해보자.
0으로 시작하는 수는 계단수가 아니다.

[입력]
첫째 줄에 N이 주어진다.
N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

[출력]
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<long long> > dp(n + 1, vector<long long>(10, 0));
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    dp[1][4] = 1;
    dp[1][5] = 1;
    dp[1][6] = 1;
    dp[1][7] = 1;
    dp[1][8] = 1;
    dp[1][9] = 1;

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j <= 9; ++j)
        {
            if (j == 0)
                dp[i][j] = (dp[i - 1][1]) % 1000000000LL;
            else if (j == 9)
                dp[i][j] = (dp[i - 1][8]) % 1000000000LL;
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000LL;
        }
    }

    long long sum = 0;
    for (int i = 0; i <= 9; ++i)
        sum += dp[n][i];
    cout << sum % 1000000000LL;

    return 0;
}