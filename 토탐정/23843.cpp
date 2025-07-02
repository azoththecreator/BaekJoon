/*

23843. 콘센트

[문제]
광재는 전자기기 대여사업을 시작했다.
퇴근하기 전에 다음날 손님들에게 빌려줄 N개의 전자기기를 충전하려 한다.
사용 가능한 콘센트는 M개가 있고, 성능은 모두 동일하다.

전자기기들은 한 번에 하나의 콘센트에서만 충전이 가능하고, 충전에 필요한 시간은 2^k(0 ≤ k ≤ 15, k는 정수) 형태이다.

광재의 빠른 퇴근을 위해 모든 전자기기를 충전하기 위한 최소 시간이 얼마인지 알려주자.

[입력]
첫째 줄에 전자기기의 개수 N과 콘센트의 개수 M이 주어진다. (1 ≤ N ≤ 10,000, 1 ≤ M ≤ 10)

둘째 줄에 충전에 필요한 시간 ti를 나타내는 N개의 정수가 주어진다. (2^0 ​≤ ti ≤ 2^15, ti = 2^k (0 ≤ k ≤ 15, k는 정수))

[출력]
충전에 필요한 최소 시간을 출력한다.

*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    m = min(n, m);

    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < m; ++i)
        pq.push(0);

    vector<int> t;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        t.push_back(tmp);
    }

    sort(t.begin(), t.end(), greater<>());

    int last_plug = 0;
    for (int i = 0; i < n; ++i)
    {
        int earliest_plug = pq.top() + t[i];
        pq.pop();
        pq.push(earliest_plug);

        last_plug = max(earliest_plug, last_plug);
    }

    cout << last_plug;

    return 0;
}