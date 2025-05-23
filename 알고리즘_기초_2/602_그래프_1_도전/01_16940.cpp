/*

16940. BFS 스페셜 저지

[문제]
BOJ에서 정답이 여러가지인 경우에는 스페셜 저지를 사용한다.
스페셜 저지는 유저가 출력한 답을 검증하는 코드를 통해서 정답 유무를 결정하는 방식이다.
오늘은 스페셜 저지 코드를 하나 만들어보려고 한다.

정점의 개수가 N이고, 정점에 1부터 N까지 번호가 매겨져있는 양방향 그래프가 있을 때, BFS 알고리즘은 다음과 같은 형태로 이루어져 있다.

    1. 큐에 시작 정점을 넣는다. 이 문제에서 시작 정점은 1이다. 1을 방문했다고 처리한다.
    2. 큐가 비어 있지 않은 동안 다음을 반복한다.
        1. 큐에 들어있는 첫 정점을 큐에서 꺼낸다. 이 정점을 x라고 하자.
        2. x와 연결되어 있으면, 아직 방문하지 않은 정점 y를 모두 큐에 넣는다. 모든 y를 방문했다고 처리한다.

2-2 단계에서 방문하지 않은 정점을 방문하는 순서는 중요하지 않다.
따라서, BFS의 결과는 여러가지가 나올 수 있다.

트리가 주어졌을 때, 올바른 BFS 방문 순서인지 구해보자.

[입력]
첫째 줄에 정점의 수 N(2 ≤ N ≤ 100,000)이 주어진다.
둘째 줄부터 N-1개의 줄에는 트리의 간선 정보가 주어진다.
마지막 줄에는 BFS 방문 순서가 주어진다.
BFS 방문 순서는 항상 N개의 정수로 이루어져 있으며, 1부터 N까지 자연수가 한 번씩 등장한다.

[출력]
입력으로 주어진 BFS 방문 순서가 올바른 순서면 1, 아니면 0을 출력한다.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<int> graph[100001];
bool visited[100001];

queue<int> seq;

bool bfs()
{
    queue<int> q;
    q.push(1);
    visited[1] = true;

    if (seq.front() != 1)
        return false;
    seq.pop();

    while (q.size() > 0)
    {
        int x = q.front();
        q.pop();

        set<int> connected;
        for (int i = 0; i < graph[x].size(); ++i)
        {
            int y = graph[x][i];

            if (!visited[y])
            {
                visited[y] = true;
                connected.insert(y);
            }
        }

        for (int i = 0; i < connected.size(); ++i)
        {
            int next = seq.front();
            seq.pop();

            if (connected.find(next) == connected.end())
                return false;

            q.push(next);
        }
    }
    return true;
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
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;

        seq.push(tmp);
    }

    cout << bfs();

    return 0;
}