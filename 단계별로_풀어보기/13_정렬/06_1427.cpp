/*

1427. 소트인사이드

[문제]
배열을 정렬하는 것은 쉽다.
수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.

[입력]
첫째 줄에 정렬하려고 하는 수 N이 주어진다.
N은 1,000,000,000보다 작거나 같은 자연수이다.

[출력]
첫째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다.

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int cnt = 0;
    int tmp = n;
    while (tmp > 0)
    {
        tmp /= 10;
        ++cnt;
    }

    int arr[cnt];
    tmp = n;
    int idx = 0;
    while (tmp > 0)
    {
        arr[idx] = tmp % 10;
        tmp /= 10;
        ++idx;
    }

    sort(&(arr[0]), &(arr[cnt]), [](int a, int b) -> bool { return a > b; });

    for (int i = 0; i < cnt; ++i)
        cout << arr[i];
 
    return 0;
}