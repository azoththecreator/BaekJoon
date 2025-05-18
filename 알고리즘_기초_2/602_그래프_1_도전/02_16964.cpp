/*

16964. DFS 스페셜 저지

[문제]
BOJ에서 정답이 여러가지인 경우에는 스페셜 저지를 사용한다.
스페셜 저지는 유저가 출력한 답을 검증하는 코드를 통해서 정답 유무를 결정하는 방식이다.
오늘은 스페셜 저지 코드를 하나 만들어보려고 한다.

정점의 개수가 N이고, 정점에 1부터 N까지 번호가 매겨져있는 양방향 그래프가 있을 때, DFS 알고리즘은 다음과 같은 형태로 이루어져 있다.

    void dfs(int x) {
        if (check[x] == true) {
            return;
        }
        check[x] = true;
        // x를 방문
        for (int y : x와 인접한 정점) {
            if (check[y] == false) {
                dfs(y);
            }
        }
    }

이 문제에서 시작 정점은 1이기 때문에 가장 처음에 호출하는 함수는 dfs(1)이다.
DFS 방문 순서는 dfs함수에서 x를 방문이라고 적힌 곳에 도착한 정점 번호를 순서대로 나열한 것이다.

트리가 주어졌을 때, 올바른 DFS 방문 순서인지 구해보자.

[입력]
첫째 줄에 정점의 수 N(2 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N-1개의 줄에는 트리의 간선 정보가 주어진다.
마지막 줄에는 DFS 방문 순서가 주어진다.
DFS 방문 순서는 항상 N개의 정수로 이루어져 있으며, 1부터 N까지 자연수가 한 번씩 등장한다.

[출력]
입력으로 주어진 DFS 방문 순서가 올바른 순서면 1, 아니면 0을 출력한다.

*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
bool visited[100001];

int seq[100001];

map<int, int> map_seq;
vector<int> graph_seq;

void dfs(int x)
{
    if (visited[x] == true)
        return;

    graph_seq.push_back(x);
    visited[x] = true;
    
    for (int i = 0; i < graph[x].size(); ++i)
    {
        int y = graph[x][i];

        if (visited[y] == false)
            dfs(y);
    }
}

bool graph_sort(int a, int b)
{
    return map_seq[a] < map_seq[b];
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int priority = 0;
    for (int i = 1; i <= n; ++i)
    {
        int tmp;
        cin >> tmp;

        seq[i] = tmp;

        map_seq[tmp] = priority;
        ++priority;
    }

    for (int i = 1; i <= n; ++i)
        sort(graph[i].begin(), graph[i].end(), graph_sort);

    graph_seq.push_back(0);
    dfs(1);

    for (int i = 1; i <= n; ++i)
    {
        if (seq[i] != graph_seq[i])
        {
            cout << 0;
            return 0;
        }
    }
    cout << 1;

    return 0;
}