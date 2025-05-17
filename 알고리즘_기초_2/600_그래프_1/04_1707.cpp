/*

1707. 이분 그래프

[문제]
그래프의 정점의 집합을 둘로 분할하여, 각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할할 수 있을 때, 그러한 그래프를 특별히 이분 그래프 (Bipartite Graph) 라 부른다.

그래프가 입력으로 주어졌을 때, 이 그래프가 이분 그래프인지 아닌지 판별하는 프로그램을 작성하시오.

[입력]
입력은 여러 개의 테스트 케이스로 구성되어 있는데, 첫째 줄에 테스트 케이스의 개수 K가 주어진다.
각 테스트 케이스의 첫째 줄에는 그래프의 정점의 개수 V와 간선의 개수 E가 빈 칸을 사이에 두고 순서대로 주어진다.
각 정점에는 1부터 V까지 차례로 번호가 붙어 있다.
이어서 둘째 줄부터 E개의 줄에 걸쳐 간선에 대한 정보가 주어지는데, 각 줄에 인접한 두 정점의 번호 u, v (u ≠ v)가 빈 칸을 사이에 두고 주어진다.

[출력]
K개의 줄에 걸쳐 입력으로 주어진 그래프가 이분 그래프이면 YES, 아니면 NO를 순서대로 출력한다.

[제한]
- 2 ≤ K ≤ 5
- 1 ≤ V ≤ 20,000
- 1 ≤ E ≤ 200,000

*/

#include <iostream>
#include <vector>

using namespace std;

enum Color
{
    RED = 1,
    BLUE = 2
};

vector<int> graph[20001];
int visited[20001];

void dfs(int i)
{
    if (visited[i] == 0)
        visited[i] = RED;

    for (int j = 0; j < graph[i].size(); ++j)
    {
        if (!visited[graph[i][j]])
        {
            if (visited[i] == RED)
                visited[graph[i][j]] = BLUE;
            else if (visited[i] == BLUE)
                visited[graph[i][j]] = RED;

            dfs(graph[i][j]);
        }
    }
}

bool is_bipartite(int v)
{
    for (int i = 1; i <= v; ++i)
    {
        for (int j = 0; j < graph[i].size(); ++j)
        {
            if (visited[i] == visited[graph[i][j]])
                return false;
        }
    }
    return true;
}

int main()
{
    int k;
    cin >> k;

    for (int i = 0; i < k; ++i)
    {
        int v, e;
        cin >> v >> e;

        for (int j = 1; j <= v; ++j)
        {
            graph[j].clear();
            visited[j] = false;
        }

        for (int j = 0; j < e; ++j)
        {
            int u, w;
            cin >> u >> w;

            graph[u].push_back(w);
            graph[w].push_back(u);
        }

        for (int j = 1; j <= v; ++j)
        {
            if (!visited[j])
                dfs(j);
        }
        cout << (is_bipartite(v) ? "YES\n" : "NO\n");
    }

    return 0;
}