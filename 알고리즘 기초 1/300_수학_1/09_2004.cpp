/*

2004. 조합 0의 개수

[문제]
nCm의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.

[입력]
첫째 줄에 정수 n, m (0 ≤ m ≤ n ≤ 2,000,000,000, n ≠ 0)이 들어온다.

[출력]
첫째 줄에 nCm의 끝자리 0의 개수를 출력한다.

*/

#include <iostream>

using namespace std;

int count(long long n, int factor)
{
    int cnt = 0;
    while (n >= factor)
    {
        cnt += n / factor;
        n /= factor;
    }
    return cnt;
}

int main()
{
    long long n, m;
    cin >> n >> m;

    int fives = count(n, 5) - count(m, 5) - count(n - m, 5);
    int twos = count(n, 2) - count(m, 2) - count(n - m, 2);

    if (fives > twos)
        cout << twos;
    else
        cout << fives;

    return 0;
}