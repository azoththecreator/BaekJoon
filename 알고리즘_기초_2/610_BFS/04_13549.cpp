/*

13549. 숨바꼭질 3

[문제]
수빈이는 동생과 숨바꼭질을 하고 있다.
수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
수빈이는 걷거나 순간이동을 할 수 있다.
만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다.
순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동하게 된다.

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

void bfs(int n, int k)
{
    for (int i = 0; i <= 100000; ++i)
    {
        if (i != n)
            map[i] = 2147483647;
    }

    queue<pair<int, int> > q;
    q.push({n, 0});

    while (q.size() > 0)
    {
        pair<int, int> curr = q.front();
        q.pop();

        int x = curr.first;
        int sec = curr.second;

        if (x == k)
            return;

        int move_left = x - 1;
        int move_right = x + 1;
        int teleport = x * 2;

        if((move_left >= 0 && move_left <= 100000) && map[move_left] > sec)
        {
            map[move_left] = sec + 1;
            q.push({move_left, sec + 1});
        }

        if((move_right >= 0 && move_right <= 100000) && map[move_right] > sec)
        {
            map[move_right] = sec + 1;
            q.push({move_right, sec + 1});
        }

        if((teleport >= 0 && teleport <= 100000) && map[teleport] > sec)
        {
            map[teleport] = sec;
            q.push({teleport, sec});
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