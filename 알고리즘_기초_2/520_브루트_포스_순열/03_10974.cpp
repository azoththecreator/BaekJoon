/*

10974. 모든 순열

[문제]
N이 주어졌을 때, 1부터 N까지의 수로 이루어진 순열을 사전순으로 출력하는 프로그램을 작성하시오.

[입력]
첫째 줄에 N(1 ≤ N ≤ 8)이 주어진다.

[출력]
첫째 줄부터 N!개의 줄에 걸쳐서 모든 순열을 사전순으로 출력한다.

*/

#include <iostream>

using namespace std;

int arr[8];
bool visited[9];

void backtrack(int n, int depth)
{
    if (depth == n)
    {
        for (int i = 0; i < n; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        arr[depth] = i;
        backtrack(n, depth + 1);
        visited[i] = false;
    }
}

int main()
{
    int n;
    cin >> n;

    backtrack(n, 0);

    return 0;
}