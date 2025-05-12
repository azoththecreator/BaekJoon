/*

10819. 차이를 최대로

[문제]
N개의 정수로 이루어진 배열 A가 주어진다.
이때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 다음 식의 최댓값을 구하는 프로그램을 작성하시오.

    - |A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|

[입력]
첫째 줄에 N (3 ≤ N ≤ 8)이 주어진다.
둘째 줄에는 배열 A에 들어있는 정수가 주어진다.
배열에 들어있는 정수는 -100보다 크거나 같고, 100보다 작거나 같다.

[출력]
첫째 줄에 배열에 들어있는 수의 순서를 적절히 바꿔서 얻을 수 있는 식의 최댓값을 출력한다.

*/

#include <iostream>
#include <cmath>

using namespace std;

int a[8];
int arr[8];
bool visited[9];

int answer;

void backtrack(int n, int depth)
{
    if (depth == n)
    {
        int tmp = 0;
        for (int i = 0; i < n - 1; ++i)
            tmp += abs(arr[i] - arr[i + 1]);
        answer = max(answer, tmp);
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        arr[depth] = a[i];
        backtrack(n, depth + 1);
        visited[i] = false;
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    backtrack(n, 0);

    cout << answer;

    return 0;
}