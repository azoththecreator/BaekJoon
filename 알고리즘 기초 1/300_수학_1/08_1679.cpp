/*

1676. 팩토리얼 0의 개수

[문제]
N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.

[입력]
첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)

[출력]
첫째 줄에 구한 0의 개수를 출력한다.

*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int zeros = 0;
    while (n >= 5)
    {
        zeros += n / 5;
        n /= 5;
    }
    cout << zeros;

    return 0;
}