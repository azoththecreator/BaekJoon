/*

11724. 연결 요소의 개수

[문제]
방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

[입력]
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N × (N - 1) / 2)
둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v)
같은 간선은 한 번만 주어진다.

[출력]
첫째 줄에 연결 요소의 개수를 출력한다.

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int i)
{
    visited[i] = true;

    for (int j = 0; j < graph[i].size(); ++j)
    {
        if (!visited[graph[i][j]])
            dfs(graph[i][j]);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            dfs(i);
            ++answer;
        }
    }
    cout << answer;

    return 0;
}