/*

1697. 숨바꼭질

[문제]
수빈이는 동생과 숨바꼭질을 하고 있다.
수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
수빈이는 걷거나 순간이동을 할 수 있다.
만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다.
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

[입력]
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다.
N과 K는 정수이다.

[출력]
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

*/

#include <iostream>
#include <queue>

using namespace std;

int map[100001];
bool visited[100001];

int dx[3] = {-1, 1, 0};

void bfs(int n, int k)
{
    queue<int> q;
    q.push(n);

    while (q.size() > 0)
    {
        int x = q.front();
        q.pop();
        visited[x] = true;

        for (int i = 0; i < 3; ++i)
        {
            int _x = x + dx[i];
            if (x == _x)
                _x *= 2;

            if (_x >= 0 && _x <= 100000)
            {
                if (visited[_x])
                    continue;

                map[_x] = map[x] + 1;
                q.push(_x);
                visited[_x] = true;

                if (_x == k)
                    return;
            }
        }
    }
}

int main()
{
    int n, k;
    cin >> n >>k;

    bfs(n, k);
    cout << map[k];

    return 0;
}