/*

1947. 선물 전달

[문제]
이번 ACM-ICPC 대회에 참가한 모든 사람들은 선물을 하나씩 준비했다.

대회가 끝나고 난 후에 각자 선물을 전달하려고 할 때, 선물을 나누는 경우의 수를 구하는 프로그램을 작성하시오.

모든 사람은 선물을 하나씩 받으며, 자기의 선물을 자기가 받는 경우는 없다.

[입력]
첫째 줄에 ACM-ICPC 대회에 참가한 학생의 수 N(1 ≤ N ≤ 1,000,000)이 주어진다.

[출력]
경우의 수를 1,000,000,000으로 나눈 나머지를 첫째 줄에 출력한다.

*/

#include <iostream>

using namespace std;

const long long MOD = 1000000000LL;

long long dp[1000001];

int main()
{
    int n;
    cin >> n;

    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; ++i)
        dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2])) % MOD;

    cout << dp[n];

    return 0;
}