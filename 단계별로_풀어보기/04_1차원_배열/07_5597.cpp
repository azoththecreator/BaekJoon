/*

5597. 과제 안 내신 분..?

[문제]
X대학 M교수님은 프로그래밍 수업을 맡고 있다.
교실엔 학생이 30명이 있는데, 학생 명부엔 각 학생별로 1번부터 30번까지 출석번호가 붙어 있다.

교수님이 내준 특별과제를 28명이 제출했는데, 그 중에서 제출 안 한 학생 2명의 출석번호를 구하는 프로그램을 작성하시오.

[입력]
입력은 총 28줄로 각 제출자(학생)의 출석번호 n(1 ≤ n ≤ 30)가 한 줄에 하나씩 주어진다.
출석번호에 중복은 없다.

[출력]
출력은 2줄이다.
1번째 줄엔 제출하지 않은 학생의 출석번호 중 가장 작은 것을 출력하고, 2번째 줄에선 그 다음 출석번호를 출력한다.

*/

#include <iostream>

using namespace std;

int main()
{
    bool students[30];
    for (int i = 0; i < 30; ++i)
        students[i] = false;

    for (int i = 0; i < 28; ++i)
    {
        int n;
        cin >> n;
        students[n - 1] = true;
    }

    for (int i = 0; i < 30; ++i)
    {
        if (students[i] == false)
            cout << i + 1 << " ";
    }

    return 0;
}