/*

19598. 최소 회의실 개수

[문제]
서준이는 아빠로부터 N개의 회의를 모두 진행할 수 있는 최소 회의실 개수를 구하라는 미션을 받았다.
각 회의는 시작 시간과 끝나는 시간이 주어지고 한 회의실에서 동시에 두 개 이상의 회의가 진행될 수 없다.
단, 회의는 한번 시작되면 중간에 중단될 수 없으며 한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다.
회의의 시작 시간은 끝나는 시간보다 항상 작다.
N이 너무 커서 괴로워 하는 우리 서준이를 도와주자.

[입력]
첫째 줄에 배열의 크기 N(1 ≤ N ≤ 100,000)이 주어진다.
둘째 줄부터 N+1 줄까지 공백을 사이에 두고 회의의 시작시간과 끝나는 시간이 주어진다.
시작 시간과 끝나는 시간은 2^31−1보다 작거나 같은 자연수 또는 0이다.

[출력]
첫째 줄에 최소 회의실 개수를 출력한다.

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> meetings[100000];

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int start, end;
        cin >> start >> end;
        pair<int, int> tmp = {start, end};
        meetings[i] = tmp;
    }

    sort(meetings, meetings + n);

    vector<pair<int, int> > v;
    v.push_back(meetings[0]);
    for (int i = 1; i < n; ++i)
    {
        bool is_valid =false;
        for (int j = 0; j < v.size(); ++j)
        {
            if (v[j].second <= meetings[i].first)
            {
                is_valid = true;
                v[j] = meetings[i];
                break;
            }
        }

        if (!is_valid)
            v.push_back(meetings[i]);
    }

    cout << v.size();

    return 0;
}