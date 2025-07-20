/*

3649. 로봇 프로젝트

[문제]
상근이와 선영이는 학교 숙제로 로봇을 만들고 있다.
로봇을 만들던 중에 구멍을 막을 두 레고 조각이 필요하다는 것을 깨달았다.

구멍의 너비는 x 센티미터이고, 구멍에 넣을 두 조각의 길이의 합은 구멍의 너비와 정확하게 일치해야 한다.
정확하게 일치하지 않으면, 프로젝트 시연을 할 때 로봇은 부수어질 것이고 상근이와 선영이는 F를 받게 된다.
구멍은 항상 두 조각으로 막아야 한다.

지난밤, 상근이와 선영이는 물리 실험실에 들어가서 레고 조각의 크기를 모두 정확하게 재고 돌아왔다.
구멍을 완벽하게 막을 수 있는 두 조각을 구하는 프로그램을 작성하시오.

[입력]
입력은 여러 개의 테스트 케이스로 이루어져 있다.

각 테스트 케이스의 첫째 줄에는 구멍의 너비 x (1 ≤ x ≤ 20, x는 정수)가 주어진다.
x의 단위는 센티미터이다.

다음 줄에는 물리 실험실에 있는 레고 조각의 수 n이 주어진다. (0 ≤ n ≤ 1000000)

다음 n개의 줄에는 레고 조각의 길이 ℓ이 주어진다.
ℓ은 양의 정수이며, 단위는 나노미터이다.
블록의 길이는 10 센티미터 (100000000 나노미터)를 넘지 않는다.

[출력]
각 테스트 케이스마다 한 줄에 하나씩, 구멍을 완벽하게 막을 수 있는 두 조각이 없다면 'danger'를 출력한다.
막을 수 있는 경우에는 'yes ℓ1 ℓ2'를 출력한다. (ℓ1 ≤ ℓ2)

정답이 여러 개인 경우에는 |ℓ1 - ℓ2|가 가장 큰 것을 출력한다.

*/

#include <iostream>
#include <algorithm>

using namespace std;

const int CONVERSION = 10000000;

int pieces[1000000];

int main()
{
    while (true)
    {
        int x, n;
        if (!(cin >> x >> n))
            break;

        for (int i = 0; i < n; ++i)
            cin >> pieces[i];

        if (n < 2)
        {
            cout << "danger\n";
            continue;
        }

        sort(pieces, pieces + n);

        int l1, l2;
        int sub = -1;

        int idx1 = 0, idx2 = n - 1;
        bool is_valid = false;
        while (idx1 < idx2)
        {
            long long sum = x * CONVERSION;
            int p1 = pieces[idx1];
            int p2 = pieces[idx2];
            if ((long long)(p1 + p2) == sum)
            {
                if (sub < p2 - p1)
                {
                    l1 = p1;
                    l2 = p2;
                    sub = l2 - l1;
                    is_valid = true;
                }
                ++idx1;
                --idx2;
            }
            else if ((long long)(p1 + p2) < sum)
                ++idx1;
            else
                --idx2;
        }

        if (!is_valid)
            cout << "danger\n";
        else
            cout << "yes " << l1 << ' ' << l2 << '\n';
    }

    return 0;
}