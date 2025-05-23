/*

11725. 트리의 부모 찾기

[문제]
루트 없는 트리가 주어진다.
이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.

[입력]
첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다.
둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.

[출력]
첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> tree[100001];
int parents[100001];
bool visited[100001];

void bfs()
{
    queue<int> q;

    for (int i = 0; i < tree[1].size(); ++i)
    {
        q.push(tree[1][i]);
        parents[tree[1][i]] = 1;
    }

    while (q.size() > 0)
    {
        int curr = q.front();
        q.pop();

        if (visited[curr])
            continue;
        visited[curr] = true;

        for (int i = 0; i < tree[curr].size(); ++i)
        {
            q.push(tree[curr][i]);
            if (parents[tree[curr][i]] == 0)
                parents[tree[curr][i]] = curr;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    bfs();
    for (int i = 2; i <= n; ++i)
        cout << parents[i] << '\n';

    return 0;
}