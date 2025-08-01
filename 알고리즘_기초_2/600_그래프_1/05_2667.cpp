/*

2667. 단지번호붙이기

[문제]
정사각형 모양의 지도가 있다.
1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다.
철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다.
여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다.
대각선상에 집이 있는 경우는 연결된 것이 아니다.
지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

[입력]
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5 ≤ N ≤ 25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

[출력]
첫 번째 줄에는 총 단지수를 출력하시오.
그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool map[25][25];
int total;

int cnt;
vector<int> cnts;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int n, int x, int y)
{
    map[x][y] = false;
    ++cnt;

    for (int i = 0; i < 4; ++i)
    {
        int _x = x + dx[i];
        int _y = y + dy[i];

        if (_x >= 0 && _x < n && _y >= 0 && _y < n)
        {
            if (map[_x][_y])
                dfs(n, _x, _y);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < n; ++j)
            map[i][j] = tmp[j] - '0';
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (map[i][j])
            {
                ++total;
                cnt = 0;
                dfs(n, i, j);
                cnts.push_back(cnt);
            }
        }
    }

    sort(cnts.begin(), cnts.end());
    cout << total << '\n';
    for (int i = 0; i < cnts.size(); ++i)
        cout << cnts[i] << '\n';

    return 0;
}