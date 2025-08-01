/*

4963. 섬의 개수

[문제]
정사각형으로 이루어져 있는 섬과 바다 지도가 주어진다.
섬의 개수를 세는 프로그램을 작성하시오.

한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다.

두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 수 있는 경로가 있어야 한다.
지도는 바다로 둘러싸여 있으며, 지도 밖으로 나갈 수 없다.

[입력]
입력은 여러 개의 테스트 케이스로 이루어져 있다.
각 테스트 케이스의 첫째 줄에는 지도의 너비 w와 높이 h가 주어진다.
w와 h는 50보다 작거나 같은 양의 정수이다.

둘째 줄부터 h개 줄에는 지도가 주어진다.
1은 땅, 0은 바다이다.

입력의 마지막 줄에는 0이 두 개 주어진다.

[출력]
각 테스트 케이스에 대해서, 섬의 개수를 출력한다.

*/

#include <iostream>

using namespace std;

bool map[50][50];

int d[3] = {-1, 0, 1};

void dfs(int w, int h, int x, int y)
{
    map[y][x] = false;

    for (int i = 0; i < 3; ++i)
    {
        int _y = y + d[i];
        for (int j = 0; j < 3; ++j)
        {
            int _x = x + d[j];

            if (_x >= 0 && _x < w && _y >= 0 && _y < h)
            {
                if (map[_y][_x])
                    dfs(w, h, _x, _y);
            }
        }
    }
}

int main()
{
    while (true)
    {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;

        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
                cin >> map[i][j];
        }

        int islands = 0;
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (map[i][j])
                {
                    ++islands;
                    dfs(w, h, j, i);
                }
            }
        }
        cout << islands << '\n';
    }

    return 0;
}