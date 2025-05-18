/*

16947. 서울 지하철 2호선

[문제]
지하철 2호선에는 51개의 역이 있고, 역과 역 사이를 연결하는 구간이 51개 있다.
즉, 정점이 51개이고, 양방향 간선이 51개인 그래프로 나타낼 수 있다.
2호선은 순환선 1개와 2개의 지선으로 이루어져 있다.
한 역에서 출발해서 계속 가면 다시 출발한 역으로 돌아올 수 있는 노선을 순환선이라고 한다.
지선은 순환선에 속하는 한 역에서 시작하는 트리 형태의 노선이다.

두 역(정점) 사이의 거리는 지나야 하는 구간(간선)의 개수이다.
역 A와 순환선 사이의 거리는 A와 순환선에 속하는 역 사이의 거리 중 최솟값이다.

지하철 2호선과 같은 형태의 노선도가 주어졌을 때, 각 역과 순환선 사이의 거리를 구해보자.

[입력]
첫째 줄에 역의 개수 N(3 ≤ N ≤ 3,000)이 주어진다.
둘째 줄부터 N개의 줄에는 역과 역을 연결하는 구간의 정보가 주어진다.
같은 구간이 여러 번 주어지는 경우는 없고, 역은 1번부터 N번까지 번호가 매겨져 있다.
임의의 두 역 사이에 경로가 항상 존재하는 노선만 입력으로 주어진다.

[출력]
총 N개의 정수를 출력한다.
1번 역과 순환선 사이의 거리, 2번 역과 순환선 사이의 거리, ..., N번 역과 순환선 사이의 거리를 공백으로 구분해 출력한다.

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> metro[3001];

bool is_cycle[3001];
bool visited[3001];

int dist[3001];

void dfs(int n, int start, int curr, int depth)
{
    visited[curr] = true;

    for (int i = 0; i < metro[curr].size(); ++i)
    {
        int next = metro[curr][i];

        if (next == start && depth >= 2)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (visited[j])
                    is_cycle[j] = true;
            }
        }

        if (!visited[next])
            dfs(n, start, next, depth + 1);
    }
    visited[curr] = false;
}

void bfs(int n)
{
    queue<int> q;

    for (int i = 1; i <= n; ++i)
    {
        if (is_cycle[i])
        {
            q.push(i);
            visited[i] = true;
        }
        else
            visited[i] = false;
    }

    while (q.size() > 0)
    {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < metro[curr].size(); ++i)
        {
            int next = metro[curr][i];
            if (visited[next])
                continue;

            visited[next] = true;
            dist[next] = dist[curr] + 1;
            q.push(next);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;

        metro[a].push_back(b);
        metro[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
            dfs(n, i, i, 0);
    }

    bfs(n);

    for (int i = 1; i <= n; ++i)
        cout << dist[i] << ' ';

    return 0;
}