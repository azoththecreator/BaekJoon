/*

14500. 테트로미노

[문제]
폴리오미노란 크기가 1×1인 정사각형을 여러 개 이어서 붙인 도형이며, 다음과 같은 조건을 만족해야 한다.

    - 정사각형은 서로 겹치면 안 된다.
    - 도형은 모두 연결되어 있어야 한다.
    - 정사각형의 변끼리 연결되어 있어야 한다. 즉, 꼭짓점과 꼭짓점만 맞닿아 있으면 안 된다.

정사각형 4개를 이어 붙인 폴리오미노는 테트로미노라고 한다.

아름이는 크기가 N×M인 종이 위에 테트로미노 하나를 놓으려고 한다.
종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 정수가 하나 쓰여 있다.

테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램을 작성하시오.

테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 하며, 회전이나 대칭을 시켜도 된다.

[입력]
첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)

둘째 줄부터 N개의 줄에 종이에 쓰여 있는 수가 주어진다.
i번째 줄의 j번째 수는 위에서부터 i번째 칸, 왼쪽에서부터 j번째 칸에 쓰여 있는 수이다.
입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.

[출력]
첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값을 출력한다.

*/

#include <iostream>
#include <algorithm>

using namespace std;

int sum = 0;
int paper[500][500];
bool visited[500][500];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void sum_t(int i, int j, int n, int m)
{
    if (i > 0 && j > 0 && j < m - 1)
        sum = max(sum, paper[i][j] + paper[i - 1][j] + paper[i][j - 1] + paper[i][j + 1]);
    if (i > 0 && i < n - 1 && j < m - 1)
        sum = max(sum, paper[i][j] + paper[i - 1][j] + paper[i + 1][j] + paper[i][j + 1]);
    if (j > 0 && i < n - 1 && j < m - 1)
        sum = max(sum, paper[i][j] + paper[i + 1][j] + paper[i][j - 1] + paper[i][j + 1]);
    if (i > 0 && j > 0 && i < n - 1)
        sum = max(sum, paper[i][j] + paper[i - 1][j] + paper[i][j - 1] + paper[i + 1][j]);
}

void dfs(int i, int j, int n, int m, int depth, int ret)
{
    if (depth == 3)
    {
        sum = max(sum, ret);
        return;
    }

    for (int k = 0; k < 4; ++k)
    {
        int tmp_j = j + dx[k];
        int tmp_i = i + dy[k];

        if (tmp_i < 0 || tmp_i >= n || tmp_j < 0 || tmp_j >= m)
            continue;
        if (visited[tmp_i][tmp_j])
            continue;

        visited[tmp_i][tmp_j] = true;
        dfs(tmp_i, tmp_j, n, m, depth + 1, ret + paper[tmp_i][tmp_j]);
        visited[tmp_i][tmp_j] = false;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cin >> paper[i][j];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            visited[i][j] = true;
            dfs(i, j, n, m, 0, paper[i][j]);
            sum_t(i, j, n, m);
            visited[i][j] = false;
        }
    }
    cout << sum;

    return 0;
}