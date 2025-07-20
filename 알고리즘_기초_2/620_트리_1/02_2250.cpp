/*

2550. 트리의 높이와 너비

[문제]
이진트리를 다음의 규칙에 따라 행과 열에 번호가 붙어있는 격자 모양의 틀 속에 그리려고 한다.
이때 다음의 규칙에 따라 그리려고 한다.

    1. 이진트리에서 같은 레벨(level)에 있는 노드는 같은 행에 위치한다.
    2. 한 열에는 한 노드만 존재한다.
    3. 임의의 노드의 왼쪽 부트리(left subtree)에 있는 노드들은 해당 노드보다 왼쪽의 열에 위치하고, 오른쪽 부트리(right subtree)에 있는 노드들은 해당 노드보다 오른쪽의 열에 위치한다.
    4. 노드가 배치된 가장 왼쪽 열과 오른쪽 열 사이엔 아무 노드도 없이 비어있는 열은 없다.

이와 같은 규칙에 따라 이진트리를 그릴 때 각 레벨의 너비는 그 레벨에 할당된 노드 중 가장 오른쪽에 위치한 노드의 열 번호에서 가장 왼쪽에 위치한 노드의 열 번호를 뺀 값 더하기 1로 정의한다.
트리의 레벨은 가장 위쪽에 있는 루트 노드가 1이고 아래로 1씩 증가한다.

임의의 이진트리가 입력으로 주어질 때 너비가 가장 넓은 레벨과 그 레벨의 너비를 출력하는 프로그램을 작성하시오

[입력]
첫째 줄에 노드의 개수를 나타내는 정수 N(1 ≤ N ≤ 10,000)이 주어진다.
다음 N개의 줄에는 각 줄마다 노드 번호와 해당 노드의 왼쪽 자식 노드와 오른쪽 자식 노드의 번호가 순서대로 주어진다.
노드들의 번호는 1부터 N까지이며, 자식이 없는 경우에는 자식 노드의 번호에 -1이 주어진다.

[출력]
첫째 줄에 너비가 가장 넓은 레벨과 그 레벨의 너비를 순서대로 출력한다.
너비가 가장 넓은 레벨이 두 개 이상 있을 때에는 번호가 작은 레벨을 출력한다.

*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

enum Dir
{
    LEFT,
    RIGHT
};

vector<pair<int, int> > tree[10001];

int idx = 1;
pair<int, int> grid[10001];

void inorder(int curr, int level)
{
    int left = -1;
    int right = -1;
    for (int i = 0; i < tree[curr].size(); ++i)
    {
        if (tree[curr][i].second == LEFT)
            left = tree[curr][i].first;
        else
            right = tree[curr][i].first;
    }
    if (left > 0)
        inorder(left, level + 1);

    grid[level] = {max(grid[level].first, idx), min(grid[level].second, idx)};
    ++idx;

    if (right > 0)
        inorder(right, level + 1);
}

int main()
{
    int n;
    cin >> n;

    set<int> all, children;
    for (int i = 0; i < n; ++i)
    {
        int node;
        cin >> node;
        all.insert(node);

        int left, right;
        cin >> left >> right;
        if (left != -1)
        {
            tree[node].push_back({left, LEFT});
            children.insert(left);
        }
        if (right != -1)
        {
            tree[node].push_back({right, RIGHT});
            children.insert(right);
        }
    }

    int root = 0;
    for (auto i = all.begin(); i != all.end(); ++i)
    {
        if (children.find(*i) == children.end())
        {
            root = *i;
            break;
        }
    }

    for (int i = 1; i <= n; ++i)
        grid[i] = {-2147483648, 2147483647};
    inorder(root, 1);

    int level = 0;
    int width = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (grid[i].first == 2147483647)
            break;

        if (grid[i].first - grid[i].second + 1 > width)
        {
            width = grid[i].first - grid[i].second + 1;
            level = i;
        }
    }
    cout << level << ' ' << width;

    return 0;
}