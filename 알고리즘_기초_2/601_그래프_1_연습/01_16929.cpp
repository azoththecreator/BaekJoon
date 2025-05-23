/*

16929. Two Dots

[문제]
Two Dots는 Playdots, Inc.에서 만든 게임이다.
게임의 기초 단계는 크기가 N×M인 게임판 위에서 진행된다.

각각의 칸은 색이 칠해진 공이 하나씩 있다.
이 게임의 핵심은 같은 색으로 이루어진 사이클을 찾는 것이다.

점 k개 d1, d2, ..., dk로 이루어진 사이클의 정의는 아래와 같다.

    - 모든 k개의 점은 서로 다르다.
    - k는 4보다 크거나 같다.
    - 모든 점의 색은 같다.
    - 모든 1 ≤ i ≤ k-1에 대해서, di와 di+1은 인접하다. 또, dk와 d1도 인접해야 한다. 두 점이 인접하다는 것은 각각의 점이 들어있는 칸이 변을 공유한다는 의미이다.

게임판의 상태가 주어졌을 때, 사이클이 존재하는지 아닌지 구해보자.

[입력]
첫째 줄에 게임판의 크기 N, M이 주어진다.
둘째 줄부터 N개의 줄에 게임판의 상태가 주어진다.
게임판은 모두 점으로 가득차 있고, 게임판의 상태는 점의 색을 의미한다.
점의 색은 알파벳 대문자 한 글자이다.

[출력]
사이클이 존재하는 경우에는 "Yes", 없는 경우에는 "No"를 출력한다.

[제한]
- 2 ≤ N, M ≤ 50

*/

#include <iostream>
#include <string>

using namespace std;

char board[50][50];
bool visited[50][50];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool is_cycle = false;

void dfs(int n, int m, int x, int y, int prev_x, int prev_y, int depth)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; ++i)
    {
        int _x = x + dx[i];
        int _y = y + dy[i];

        if (_x >= 0 && _x < n && _y >= 0 && _y < m)
        {
            if (!(_x == prev_x && _y == prev_y) && visited[_x][_y] && depth >= 4)
            {
                is_cycle = true;
                return;
            }

            if (!visited[_x][_y] && board[_x][_y] == board[x][y])
                dfs(n, m, _x, _y, x, y, depth + 1);
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
            board[i][j] = tmp[j];
    }

    for (int i = 0; i < n; ++i)
    {
        if (is_cycle)
            break;
        for (int j = 0; j < m; ++j)
        {
            if (is_cycle)
                break;

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                    visited[i][j] = false;
            }
            dfs(n, m, i, j, -1, -1, 1);
        }
    }
    cout << (is_cycle ? "Yes" : "No");

    return 0;
}