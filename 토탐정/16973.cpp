/*

16973. 직사각형 탈출

[문제]
크기가 N×M인 격자판에 크기가 H×W인 직사각형이 놓여 있다.
격자판은 크기가 1×1인 칸으로 나누어져 있다.
격자판의 가장 왼쪽 위 칸은 (1, 1), 가장 오른쪽 아래 칸은 (N, M)이다.
직사각형의 가장 왼쪽 위칸은 (Sr, Sc)에 있을 때, 이 직사각형의 가장 왼쪽 위칸을 (Fr, Fc)로 이동시키기 위한 최소 이동 횟수를 구해보자.

격자판의 각 칸에는 빈 칸 또는 벽이 있다.
직사각형은 벽이 있는 칸에 있을 수 없다.
또한, 직사각형은 격자판을 벗어날 수 없다.

직사각형은 한 번에 왼쪽, 오른쪽, 위, 아래 중 한 방향으로 한 칸 이동시킬 수 있다.

[입력]
첫째 줄에 격자판의 크기 N, M이 주어진다.
둘째 줄부터 N개의 줄에 격자판의 각 칸의 정보가 주어진다.
0은 빈 칸, 1은 벽이다.

마지막 줄에는 직사각형의 크기 H, W, 시작 좌표 Sr, Sc, 도착 좌표 Fr, Fc가 주어진다.

격자판의 좌표는 (r, c) 형태이고, r은 행, c는 열이다.
1 ≤ r ≤ N, 1 ≤ c ≤ M을 만족한다.

[출력]
첫째 줄에 최소 이동 횟수를 출력한다.
이동할 수 없는 경우에는 -1을 출력한다.

[제한]
- 2 ≤ N, M ≤ 1,000
- 1 ≤ H ≤ N
- 1 ≤ W ≤ M
- 1 ≤ Sr ≤ N-H+1
- 1 ≤ Sc ≤ M-W+1
- 1 ≤ Fr ≤ N-H+1
- 1 ≤ Fc ≤ M-W+1
- 입력으로 주어진 직사각형은 격자판을 벗어나지 않고, 직사각형이 놓여 있는 칸에는 벽이 없다.

*/

#include <iostream>
#include <queue>

using namespace std;

bool board[1001][1001];
int dist[1001][1001];
int prefix_sum[1001][1001];

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

bool is_rectangle_movable(int n, int m, int h, int w, int nx, int ny)
{
    int nx2 = nx + w - 1;
    int ny2 = ny + h - 1;
    if (nx < 1 || nx2 > m || ny < 1 || ny2 > n)
        return false;

    int sum = prefix_sum[ny2][nx2] - prefix_sum[ny - 1][nx2] - prefix_sum[ny2][nx - 1] + prefix_sum[ny - 1][nx - 1];
    return sum == 0;
}

void bfs(int n, int m, int h, int w, int sr, int sc, int fr, int fc)
{
    queue<pair<int, int> > q;
    q.push({sr, sc});

    while(q.size() > 0)
    {
        pair<int, int> pos = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = pos.second + dx[i];
            int ny = pos.first + dy[i];

            if (nx >= 1 && nx <= m && ny >= 1 && ny <= n && dist[ny][nx] == -1)
            {
                if (is_rectangle_movable(n, m, h, w, nx, ny))
                {
                    if (ny == fr && nx == fc)
                    {
                        dist[ny][nx] = dist[pos.first][pos.second] + 1;
                        return;
                    }

                    q.push({ny, nx});
                    dist[ny][nx] = dist[pos.first][pos.second] + 1;
                }
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cin >> board[i][j];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            prefix_sum[i][j] = board[i][j] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
        }
    }

    int h, w, sr, sc, fr, fc;
    cin >> h >> w >> sr >> sc >> fr >> fc;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            dist[i][j] = -1;
    }
    dist[sr][sc] = 0;

    bfs(n, m, h, w, sr, sc, fr, fc);

    cout << dist[fr][fc];

    return 0;
}