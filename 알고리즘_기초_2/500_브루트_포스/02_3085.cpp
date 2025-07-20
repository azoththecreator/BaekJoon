/*

3085. 사탕 게임

[문제]
상근이는 어렸을 적에 "봄보니 (Bomboni)" 게임을 즐겨했다.

가장 처음에 N×N크기에 사탕을 채워 놓는다.
사탕의 색은 모두 같지 않을 수도 있다.
상근이는 사탕의 색이 다른 인접한 두 칸을 고른다.
그 다음 고른 칸에 들어있는 사탕을 서로 교환한다.
이제, 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 그 사탕을 모두 먹는다.

사탕이 채워진 상태가 주어졌을 때, 상근이가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램을 작성하시오.

[입력]
첫째 줄에 보드의 크기 N이 주어진다. (3 ≤ N ≤ 50)

다음 N개 줄에는 보드에 채워져 있는 사탕의 색상이 주어진다.
빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y로 주어진다.

사탕의 색이 다른 인접한 두 칸이 존재하는 입력만 주어진다.

[출력]
첫째 줄에 상근이가 먹을 수 있는 사탕의 최대 개수를 출력한다.

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count_longest(vector<vector<char> > board, int n)
{
    int max = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int length = 1;
            int idx = j + 1;
            while (idx < n && board[i][j] == board[i][idx])
            {
                ++length;
                ++idx;
            }
            if (length > max)
                max = length;

            length = 1;
            idx = i + 1;
            while (idx < n && board[i][j] == board[idx][j])
            {
                ++length;
                ++idx;
            }
            if (length > max)
                max = length;
        }
        if (max == n)
            return max;
    }
    return max;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<char> > board;
    for (int i = 0; i < n; ++i)
    {
        string tmp_s;
        cin >> tmp_s;

        vector<char> tmp_v;
        for (int j = 0; j < n; ++j)
            tmp_v.push_back(tmp_s[j]);
        board.push_back(tmp_v);
    }

    int max = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int length;
            char tmp;

            if (j < n - 1)
            {
                vector<vector<char> > swap_horizontal;
                swap_horizontal = board;

                tmp = swap_horizontal[i][j];
                swap_horizontal[i][j] = swap_horizontal[i][j + 1];
                swap_horizontal[i][j + 1] = tmp;
                length = count_longest(swap_horizontal, n);

                if (length > max)
                    max = length;
            }

            if (i < n - 1)
            {
                vector<vector<char> > swap_vertical;
                swap_vertical = board;

                tmp = swap_vertical[i][j];
                swap_vertical[i][j] = swap_vertical[i + 1][j];
                swap_vertical[i + 1][j] = tmp;
                length = count_longest(swap_vertical, n);

                if (length > max)
                    max = length;
            }

            if (max == n)
            {
                cout << max;
                return 0;
            }
        }
    }
    cout << max;

    return 0;
}