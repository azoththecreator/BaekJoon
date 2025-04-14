/*

2444. 별 찍기 - 7

[문제]
예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

5 ->     *
        ***
       *****
      *******
     *********
      *******
       *****
        ***
         *

[입력]
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

[출력]
첫째 줄부터 2×N-1번째 줄까지 차례대로 별을 출력한다.

*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < n - i; ++j)
            cout << " ";
        for (int j = 0; j < i * 2 - 1; ++j)
            cout << "*";
        cout << endl;
    }
    for (int i = n - 1; i >= 1; --i)
    {
        for (int j = 0; j < n - i; ++j)
            cout << " ";
        for (int j = 0; j < i * 2 - 1; ++j)
            cout << "*";
        cout << endl;
    }

    return 0;
}