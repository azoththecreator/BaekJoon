/*

2146. 다리 만들기

여러 섬으로 이루어진 나라가 있다.
이 나라의 대통령은 섬을 잇는 다리를 만들겠다는 공약으로 인기몰이를 해 당선될 수 있었다.
하지만 막상 대통령에 취임하자, 다리를 놓는다는 것이 아깝다는 생각을 하게 되었다.
그래서 그는, 생색내는 식으로 한 섬과 다른 섬을 잇는 다리 하나만을 만들기로 하였고, 그 또한 다리를 가장 짧게 하여 돈을 아끼려 하였다.

이 나라는 N×N크기의 이차원 평면상에 존재한다.
이 나라는 여러 섬으로 이루어져 있으며, 섬이란 동서남북으로 육지가 붙어있는 덩어리를 말한다.

지도가 주어질 때, 가장 짧은 다리 하나를 놓아 두 대륙을 연결하는 방법을 찾으시오.

[입력]
첫 줄에는 지도의 크기 N(100이하의 자연수)가 주어진다.
그 다음 N줄에는 N개의 숫자가 빈칸을 사이에 두고 주어지며, 0은 바다, 1은 육지를 나타낸다.
항상 두 개 이상의 섬이 있는 데이터만 입력으로 주어진다.

[출력]
첫째 줄에 가장 짧은 다리의 길이를 출력한다.

*/

#include <iostream>
#include <queue>

using namespace std;

int map[100][100];
bool visited[100][100];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int shortest = 2147483647;
int dist[100][100];

void dfs(int n, int x, int y, int islands)
{
    visited[x][y] = true;
    map[x][y] = islands;

    for (int i = 0; i < 4; ++i)
    {
        int _x = x + dx[i];
        int _y = y + dy[i];

        if (_x >= 0 && _x < n && _y >= 0 && _y < n)
        {
            if (!visited[_x][_y] && map[_x][_y] == 1)
                dfs(n, _x, _y, islands);
        }
    }
}

void bfs(int n, int island)
{
    queue<pair<int, int> > q;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            dist[i][j] = 0;

            if (map[i][j] == island)
            {
                q.push({i, j});
                visited[i][j] = true;
            }
            else
                visited[i][j] = false;
        }
    }

    while (q.size() > 0)
    {
        pair<int, int> curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;
        for (int k = 0; k < 4; ++k)
        {
            int _x = x + dx[k];
            int _y = y + dy[k];

            if (_x >= 0 && _x < n && _y >= 0 && _y < n)
            {
                if (visited[_x][_y])
                    continue;

                if (map[_x][_y] == 0)
                {
                    dist[_x][_y] = dist[x][y] + 1;
                    visited[_x][_y] = true;
                    q.push({_x, _y});
                }
                else if (map[_x][_y] != island)
                {
                    shortest = min(shortest, dist[x][y]);
                    return;
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> map[i][j];
    }

    int islands = 2;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!visited[i][j] && map[i][j] == 1)
            {
                dfs(n, i, j, islands);
                ++islands;
            }
        }
    }

    for (int i = 2; i < islands; ++i)
        bfs(n, i);

    cout << shortest;

    return 0;
}