/*

9465. 스티커

[문제]
상근이의 여동생 상냥이는 문방구에서 스티커 2n개를 구매했다.
스티커는 2행 n열로 배치되어 있다.
상냥이는 스티커를 이용해 책상을 꾸미려고 한다.

상냥이가 구매한 스티커의 품질은 매우 좋지 않다.
스티커 한 장을 떼면, 그 스티커와 변을 공유하는 스티커는 모두 찢어져서 사용할 수 없게 된다.
즉, 뗀 스티커의 왼쪽, 오른쪽, 위, 아래에 있는 스티커는 사용할 수 없게 된다.

모든 스티커를 붙일 수 없게된 상냥이는 각 스티커에 점수를 매기고, 점수의 합이 최대가 되게 스티커를 떼어내려고 한다.
상냥이가 뗄 수 있는 스티커의 점수의 최댓값을 구하는 프로그램을 작성하시오.
즉, 2n개의 스티커 중에서 점수의 합이 최대가 되면서 서로 변을 공유 하지 않는 스티커 집합을 구해야 한다.

[입력]
첫째 줄에 테스트 케이스의 개수 T가 주어진다.
각 테스트 케이스의 첫째 줄에는 n (1 ≤ n ≤ 100,000)이 주어진다.
다음 두 줄에는 n개의 정수가 주어지며, 각 정수는 그 위치에 해당하는 스티커의 점수이다.
연속하는 두 정수 사이에는 빈 칸이 하나 있다.
점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다. 

[출력]
각 테스트 케이스 마다, 2n개의 스티커 중에서 두 변을 공유하지 않는 스티커 점수의 최댓값을 출력한다.

*/

#include <iostream>
#include <algorithm>

using namespace std;

enum Line
{
    UPPER,
    BELOW,
};

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        
        int scores[n][2];
        for (int j = 0; j < n; ++j)
            cin >> scores[j][UPPER];
        for (int j = 0; j < n; ++j)
            cin >> scores[j][BELOW];

        long long dp[n][2];
        dp[0][UPPER] = scores[0][UPPER];
        dp[0][BELOW] = scores[0][BELOW];
        dp[1][UPPER] = dp[0][BELOW] + scores[1][UPPER];
        dp[1][BELOW] = dp[0][UPPER] + scores[1][BELOW];

        for (int j = 2; j < n; ++j)
        {
            dp[j][UPPER] = max(dp[j - 1][BELOW], max(dp[j - 2][UPPER], dp[j - 2][BELOW])) + scores[j][UPPER];
            dp[j][BELOW] = max(dp[j - 1][UPPER], max(dp[j - 2][UPPER], dp[j - 2][BELOW])) + scores[j][BELOW];
        }
        cout << max(dp[n - 1][UPPER], dp[n - 1][BELOW]) << '\n';
    }

    return 0;
}