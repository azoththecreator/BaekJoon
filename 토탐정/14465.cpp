/*

14465. 소가 길을 건너간 이유 5

[문제]
농부 존의 농장에 원형 길이 있다고 했지만, 길은 그뿐만이 아니다.
그 옆에 일자형 길이 있는데, 1번부터 N번까지의 번호가 붙은 횡단보도 N (1 ≤ N ≤ 100,000)개로 이루어져 있다.
교통사고를 방지하기 위해 존은 각 횡단보도에 신호등을 설치해 놓았다.
그러던 어느 날, 강력한 뇌우로 인해 몇몇 신호등이 망가졌다.
존은 연속한 K개의 신호등이 존재하도록 신호등을 수리하고 싶다.
이번에도 우리가 존을 도와주자.

[입력]
첫 줄에 N, K, B (1 ≤ B,K ≤ N)가 주어진다.
그 다음 B줄에는 고장난 신호등의 번호가 하나씩 주어진다.

[출력]
정상적으로 작동하는 연속 K개의 신호등이 존재하려면 최소 몇 개의 신호등을 수리해야 하는지 출력한다.

*/

#include <iostream>

using namespace std;

bool lights[100001];
int prefix_sum[100001];

int main()
{
    int n, k, b;
    cin >> n >> k >> b;

    for (int i = 0; i < b; ++i)
    {
        int tmp;
        cin >> tmp;
        lights[tmp] = true;
    }

    for (int i = 1; i <= k; ++i)
        prefix_sum[k] += lights[i];

    int min_fix = prefix_sum[k];
    for (int i = k + 1; i <= n; ++i)
    {
        prefix_sum[i] = prefix_sum[i - 1] - lights[i - k] + lights[i];
        min_fix = min(min_fix, prefix_sum[i]);
    }

    cout << min_fix;

    return 0;
}