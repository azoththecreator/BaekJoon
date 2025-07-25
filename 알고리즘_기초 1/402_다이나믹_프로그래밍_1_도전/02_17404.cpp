/*

17404. RGB거리 2

[문제]
RGB거리에는 집이 N개 있다.
거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.

집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다.
각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

    - 1번 집의 색은 2번, N번 집의 색과 같지 않아야 한다.
    - N번 집의 색은 N-1번, 1번 집의 색과 같지 않아야 한다.
    - i(2 ≤ i ≤ N-1)번 집의 색은 i-1, i+1번 집의 색과 같지 않아야 한다.

[입력]
첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다.
둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다.
집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

[출력]
첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.

*/

#include <iostream>
#include <algorithm>

using namespace std;

enum Colors
{
    RED,
    GREEN,
    BLUE,
};

int main()
{
    int n;
    cin >> n;

    int colors[n][3];
    for (int i = 0; i < n; ++i)
        cin >> colors[i][RED] >> colors[i][GREEN] >> colors[i][BLUE];

    long long cost = 1000000;
    for (int rgb = 0; rgb < 3; ++rgb)
    {
        long long dp[n][3];
        for (int i = 0; i < 3; ++i)
        {
            if (i == rgb)
                dp[0][i] = colors[0][i];
            else
                dp[0][i] = 1000000;
        }

        for (int i = 1; i < n; ++i)
        {
            dp[i][RED] = min(dp[i - 1][GREEN], dp[i - 1][BLUE]) + colors[i][RED];
            dp[i][GREEN] = min(dp[i - 1][RED], dp[i - 1][BLUE]) + colors[i][GREEN];
            dp[i][BLUE] = min(dp[i - 1][RED], dp[i - 1][GREEN]) + colors[i][BLUE];
        }

        for (int i = 0; i < 3; ++i)
        {
            if (i == rgb)
                continue;
            else
                cost = min(cost, dp[n - 1][i]);
        }
    }

    cout << cost;

    return 0;
}