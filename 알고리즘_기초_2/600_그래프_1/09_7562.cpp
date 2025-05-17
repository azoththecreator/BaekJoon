/*

7562. 나이트의 이동

[문제]
체스판 위에 한 나이트가 놓여져 있다.
나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다.
나이트가 이동하려고 하는 칸이 주어진다.
나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까?

[입력]
입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.

각 테스트 케이스는 세 줄로 이루어져 있다.
첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다.
체스판의 크기는 l × l이다.
체스판의 각 칸은 두 수의 쌍 {0, ..., l - 1} × {0, ..., l - 1}로 나타낼 수 있다.
둘째 줄과 셋째 줄에는 나이트가 현재는 칸, 나이트가 이동하려고 하는 칸이 주어진다.

[출력]
각 테스트 케이스마다 나이트가 최소 몇 번만에 이동할 수 있는지 출력한다.

*/

#include <iostream>
#include <queue>

using namespace std;

bool board[300][300];
int dist[300][300];

int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int cnt;

void bfs(int l, pair<int, int> start, pair<int, int> dest)
{
    queue<pair<int, int> > q;
    q.push(start);

    board[start.first][start.second] = true;

    while (q.size() > 0)
    {
        pair<int, int> curr = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i)
        {
            int _x = curr.first + dx[i];
            int _y = curr.second + dy[i];

            if (_x >= 0 && _x < l && _y >= 0 && _y < l)
            {
                if (!board[_x][_y])
                {
                    board[_x][_y] = true;
                    dist[_x][_y] = dist[curr.first][curr.second] + 1;

                    if (_x == dest.first && _y == dest.second)
                    {
                        cnt = dist[_x][_y];
                        return;
                    }

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
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int l;
        cin >> l;

        pair<int, int> start, dest;
        cin >> start.first >> start.second;
        cin >> dest.first >> dest.second;

        cnt = 0;
        for (int i = 0; i < l; ++i)
        {
            for (int j = 0; j < l; ++j)
            {
                board[i][j] = false;
                dist[i][j] = 0;
            }
        }

        bfs(l, start, dest);
        cout << cnt << '\n';
    }

    return 0;
}