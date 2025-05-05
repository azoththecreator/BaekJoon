/*

13398. 연속합 2

[문제]
n개의 정수로 이루어진 임의의 수열이 주어진다.
우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다.
단, 수는 한 개 이상 선택해야 한다.
또, 수열에서 수를 하나 제거할 수 있다. (제거하지 않아도 된다)

예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자.
여기서 수를 제거하지 않았을 때의 정답은 12+21인 33이 정답이 된다.

만약, -35를 제거한다면, 수열은 10, -4, 3, 1, 5, 6, 12, 21, -1이 되고, 여기서 정답은 10-4+3+1+5+6+12+21인 54가 된다.

[입력]
첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다.
수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

[출력]
첫째 줄에 답을 출력한다.

*/

#include <iostream>
#include <algorithm>

using namespace std;

enum Modified
{
    NONE,
    REMOVED,
};

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    if (n == 1)
    {
        cout << arr[0];
        return 0;
    }

    long long dp[n][2];
    dp[0][NONE] = arr[0];
    dp[0][REMOVED] = 0;

    long long dp_max = arr[0];
    for (int i = 1; i < n; ++i)
    {
        dp[i][NONE] = max(dp[i - 1][NONE] + arr[i], (long long)arr[i]);
        dp[i][REMOVED] = max(dp[i - 1][REMOVED] + arr[i], dp[i - 1][NONE]);
        dp_max = max({dp_max, dp[i][NONE], dp[i][REMOVED]});
    }
    cout << dp_max;

    return 0;
}