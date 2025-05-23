/*

1167. 트리의 지름

[문제]
트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다.
트리의 지름을 구하는 프로그램을 작성하시오.

[입력]
트리가 입력으로 주어진다.
먼저 첫 번째 줄에서는 트리의 정점의 개수 V가 주어지고 (2 ≤ V ≤ 100,000) 둘째 줄부터 V개의 줄에 걸쳐 간선의 정보가 다음과 같이 주어진다.
정점 번호는 1부터 V까지 매겨져 있다.

먼저 정점 번호가 주어지고, 이어서 연결된 간선의 정보를 의미하는 정수가 두 개씩 주어지는데, 하나는 정점번호, 다른 하나는 그 정점까지의 거리이다.
예를 들어 네 번째 줄의 경우 정점 3은 정점 1과 거리가 2인 간선으로 연결되어 있고, 정점 4와는 거리가 3인 간선으로 연결되어 있는 것을 보여준다.
각 줄의 마지막에는 -1이 입력으로 주어진다.
주어지는 거리는 모두 10,000 이하의 자연수이다.

[출력]
첫째 줄에 트리의 지름을 출력한다.

*/

#include <iostream>
#include <vector>

using namespace std;

enum Mode
{
    ONE,
    POLE
};

vector<pair<int, int> > tree[100001];

bool visited[100001];

int dist_from_1[100001];
int dist_from_pole[100001];

void dfs(int curr, Mode mode)
{
    for (int i = 0; i < tree[curr].size(); ++i)
    {
        int node = tree[curr][i].first;
        int dist = tree[curr][i].second;

        if (visited[node])
            continue;
        visited[node] = true;

        if (mode == ONE)
            dist_from_1[node] = dist_from_1[curr] + dist;
        else
            dist_from_pole[node] = dist_from_pole[curr] + dist;
        dfs(node, mode);
    }
}

int main()
{
    int v;
    cin >> v;
    
    for (int i = 0; i < v; ++i)
    {
        int parent;
        cin >> parent;

        while (true)
        {
            int node;
            cin >> node;
            if (node == -1)
                break;

            int dist;
            cin >> dist;
            
            tree[parent].push_back({node, dist});
        }
    }

    visited[1] = true;
    dfs(1, ONE);

    int pole = 0;
    for (int i = 1; i <= v; ++i)
    {
        visited[i] = false;
        if (dist_from_1[pole] < dist_from_1[i])
            pole = i;
    }
    
    visited[pole] = true;
    dfs(pole, POLE);

    int diameter = 0;
    for (int i = 1; i <= v; ++i)
        diameter = max(diameter, dist_from_pole[i]);
    cout << diameter;

    return 0;
}