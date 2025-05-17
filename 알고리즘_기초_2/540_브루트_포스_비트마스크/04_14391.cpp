/*

14391. 종이 조각

[문제]
영선이는 숫자가 쓰여 있는 직사각형 종이를 가지고 있다.
종이는 1×1 크기의 정사각형 칸으로 나누어져 있고, 숫자는 각 칸에 하나씩 쓰여 있다.
행은 위에서부터 아래까지 번호가 매겨져 있고, 열은 왼쪽부터 오른쪽까지 번호가 매겨져 있다.

영선이는 직사각형을 겹치지 않는 조각으로 자르려고 한다.
각 조각은 크기가 세로나 가로 크기가 1인 직사각형 모양이다.
길이가 N인 조각은 N자리 수로 나타낼 수 있다.
가로 조각은 왼쪽부터 오른쪽까지 수를 이어 붙인 것이고, 세로 조각은 위에서부터 아래까지 수를 이어붙인 것이다.

종이를 적절히 잘라서 조각의 합을 최대로 하는 프로그램을 작성하시오.

[입력]
첫째 줄에 종이 조각의 세로 크기 N과 가로 크기 M이 주어진다. (1 ≤ N, M ≤ 4)

둘째 줄부터 종이 조각이 주어진다.
각 칸에 쓰여 있는 숫자는 0부터 9까지 중 하나이다.

[출력]
영선이가 얻을 수 있는 점수의 최댓값을 출력한다.

*/

#include <iostream>
#include <string>

using namespace std;

int paper[5][5];

int main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; ++j)
        paper[i][j] = tmp[j] - '0';
    }

    int answer = 0;
    for (int mask = 0; mask < (1 << (n * m)); ++mask)
    {
        int sum = 0;

        for (int i = 0; i < n; ++i)
        {
            int hor_sum = 0;
            for (int j = 0; j < m; ++j)
            {
                int idx = i * m + j;
                if ((mask & (1 << idx)) == 0)
                    hor_sum = hor_sum * 10 + paper[i][j];
                else
                {
                    sum += hor_sum;
                    hor_sum = 0;
                }
            }
            sum += hor_sum;
        }

        for (int j = 0; j < m; ++j)
        {
            int ver_sum = 0;
            for (int i = 0; i < n; ++i)
            {
                int idx = i * m + j;
                if ((mask & (1 << idx)) != 0)
                    ver_sum = ver_sum * 10 + paper[i][j];
                else
                {
                    sum += ver_sum;
                    ver_sum = 0;
                }
            }
            sum += ver_sum;
        }

        answer = max(answer, sum);
    }
    cout << answer;

    return 0;
}