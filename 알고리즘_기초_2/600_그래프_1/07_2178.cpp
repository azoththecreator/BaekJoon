/*

2178. 미로 탐색

[문제]
N×M크기의 배열로 표현되는 미로가 있다.

미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다.
이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.
한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

[입력]
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다.
다음 N개의 줄에는 M개의 정수로 미로가 주어진다.
각각의 수들은 붙어서 입력으로 주어진다.

[출력]
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다.
항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool maze[100][100];
int dist[100][100];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int n, int m)
{
    pair<int, int> p;
    p.first = 0;
    p.second = 0;

    queue<pair<int, int> > q;
    q.push(p);

    while (q.size() > 0)
    {
        pair<int, int> curr_pos = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int _x = curr_pos.first + dx[i];
            int _y = curr_pos.second + dy[i];

            if (_x >= 0 && _x < n && _y >= 0 && _y < m)
            {
                if (maze[_x][_y])
                {
                    maze[_x][_y] = false;
                    dist[_x][_y] = dist[curr_pos.first][curr_pos.second] + 1;
                    
                    pair<int, int> p;
                    p.first = _x;
                    p.second = _y;
                    q.push(p);
                }
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; ++j)
            maze[i][j] = tmp[j] - '0';
    }

    maze[0][0] = false;
    dist[0][0] = 1;

    bfs(n, m);
    cout << dist[n - 1][m - 1];

    return 0;
}