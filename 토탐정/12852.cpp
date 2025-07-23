/*

12852. 1로 만들기 2

[문제]
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

    1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
    2. X가 2로 나누어 떨어지면, 2로 나눈다.
    3. 1을 뺀다.

정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다.
연산을 사용하는 횟수의 최솟값을 출력하시오.

[입력]
첫째 줄에 1보다 크거나 같고, 10^6보다 작거나 같은 자연수 N이 주어진다.

[출력]
첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

둘째 줄에는 N을 1로 만드는 방법에 포함되어 있는 수를 공백으로 구분해서 순서대로 출력한다.
정답이 여러 가지인 경우에는 아무거나 출력한다.

*/

#include <iostream>
#include <algorithm>

using namespace std;

#define COUNT 0
#define PREV 1

int dp[1000001][2];

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i)
    {
        dp[i][COUNT] = dp[i - 1][COUNT] + 1;
        dp[i][PREV] = i - 1;

        if (i % 2 == 0 && dp[i / 2][COUNT] + 1 < dp[i][COUNT])
        {
            dp[i][COUNT] = dp[i / 2][COUNT] + 1;
            dp[i][PREV] = i / 2;
        }
        if (i % 3 == 0 && dp[i / 3][COUNT] + 1 < dp[i][COUNT])
        {
            dp[i][COUNT] = dp[i / 3][COUNT] + 1;
            dp[i][PREV] = i / 3;
        }
    }

    cout << dp[n][COUNT] << '\n' << n << ' ';

    while(dp[n][COUNT] > 0)
    {
        cout << dp[n][PREV] << ' ';
        n = dp[n][PREV];
    }

    return 0;
}