/*

2571. 색종이 - 3

[문제]
가로, 세로의 크기가 각각 100인 정사각형 모양의 흰색 도화지가 있다.
이 도화지 위에 가로, 세로의 크기가 각각 10인 정사각형 모양의 검은색 색종이를 색종이의 변과 도화지의 변이 평행하도록 붙인다.
이러한 방식으로 색종이를 한 장 또는 여러 장 붙인 후 도화지에서 검은색 직사각형을 잘라내려고 한다.
직사각형 또한 그 변이 도화지의 변과 평행하도록 잘라내어야 한다.

검은색 색종이의 수와 각 색종이를 붙인 위치가 주어질 때 잘라낼 수 있는 검은색 직사각형의 최대 넓이를 구하는 프로그램을 작성하시오.

[입력]
첫째 줄에 색종이의 수가 주어진다.
이어 둘째 줄부터 한 줄에 하나씩 색종이를 붙인 위치가 주어진다.
색종이를 붙인 위치는 두 개의 자연수로 주어지는데 첫 번째 자연수는 색종이의 왼쪽 변과 도화지의 왼쪽 변 사이의 거리이고, 두 번째 자연수는 색종이의 아래쪽 변과 도화지의 아래쪽 변 사이의 거리이다.
색종이의 수는 100이하이며, 색종이가 도화지 밖으로 나가는 경우는 없다.

[출력]
첫째 줄에 잘라낼 수 있는 검은색 직사각형의 최대 넓이를 출력한다.

*/

#include <iostream>

using namespace std;

bool paper[100][100];
int sums[101][101];

int main()
{
    int num_papers;
    cin >> num_papers;

    int min_x = 100, min_y = 100;
    int max_x = 0, max_y = 0;
    for (int i = 0; i < num_papers; ++i)
    {
        int x, y;
        cin >> x >> y;

        min_x = min(min_x, x);
        min_y = min(min_y, y);
        max_x = max(max_x, x + 10);
        max_y = max(max_y, y + 10);

        for (int dy = y; dy < y + 10; ++dy)
        {
            for (int dx = x; dx < x + 10; ++dx)
                paper[dy][dx] = true;
        }
    }

    for (int j = 1; j <= 100; ++j)
    {
        for (int i = 1; i <= 100; ++i)
            sums[j][i] = paper[j - 1][i - 1] + sums[j - 1][i] + sums[j][i - 1] - sums[j - 1][i - 1];
    }

    int sum = 0;
    for (int y1 = min_y; y1 < max_y; ++y1)
    {
        for (int x1 = min_x; x1 < max_x; ++x1)
        {
            for (int y2 = y1 + 1; y2 <= max_y; ++y2)
            {
                for (int x2 = x1 + 1; x2 <= max_x; ++x2)
                {
                    int tmp = sums[y2][x2] - sums[y1][x2] - sums[y2][x1] + sums[y1][x1];
                    if (tmp == (x2 - x1) * (y2 - y1))
                        sum = max(sum, tmp);
                }
            }
        }
    }
    cout << sum;

    return 0;
}