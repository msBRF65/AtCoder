#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include <deque>
#include <map>
#include <queue>
#include <cmath>
#include <set>

typedef long long ll;

#define debug(x) cout << #x << '=' << x << endl;
#define debug_arr(a, n)        \
    for (ll i = 0; i < n; i++) \
    {                          \
        cout << a[i] << ' ';   \
    }                          \
    cout << endl;
#define inf 100000000000
#define loop(i, n) for (ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll, ll>

using namespace std;

int s[200][200];
int t[200][200];

struct Grid
{
    int width;
    int height;
    vector<vector<bool>> grid;
};

Grid minimum_grid(int *grid, int size)
{
    Grid minimum_grid;
    int min_x = 1000, min_y = 1000;
    int max_x = 0, max_y = 0;
    loop(y, size)
    {
        loop(x, size)
        {
            if (*(grid + x + y * 200) == 1)
            {
                min_x = min(min_x, int(x));
                max_x = max(max_x, int(x));
                min_y = min(min_y, int(y));
                max_y = max(max_y, int(y));
            }
        }
    }
    minimum_grid.width = max_x - min_x + 1;
    minimum_grid.height = max_y - min_y + 1;
    loop(y, max_y - min_y + 1)
    {
        vector<bool> tmp;
        loop(x, max_x - min_x + 1)
        {
            tmp.push_back(*(grid + min_x + x + (min_y + y) * 200));
        }
        minimum_grid.grid.push_back(tmp);
    }
    return minimum_grid;
}

bool is_same_grid(Grid a, Grid b)
{
    if (a.width == b.width && a.height == b.height)
    {
        bool is_same = true;
        loop(i, a.width)
        {
            loop(j, a.height)
            {
                if (a.grid[j][i] != b.grid[j][i])
                {
                    is_same = false;
                    break;
                }
            }
            if (!is_same)
                break;
        }
        if (is_same)
            return true;
        is_same = true;
        loop(i, a.width)
        {
            loop(j, a.height)
            {
                if (a.grid[j][i] != b.grid[a.height - 1 - j][a.width - 1 - i])
                {
                    is_same = false;
                    break;
                }
            }
            if (!is_same)
                break;
        }
        if (is_same)
            return true;
    }
    if (a.width == b.height && a.height == b.width)
    {
        bool is_same = true;
        loop(i, a.width)
        {
            loop(j, a.height)
            {
                if (a.grid[j][i] != b.grid[b.height - 1 - i][j])
                {
                    is_same = false;
                    break;
                }
            }
            if (!is_same)
                break;
        }
        if (is_same)
            return true;
        is_same = true;
        loop(i, b.width)
        {
            loop(j, b.height)
            {
                if (a.grid[a.height - 1 - i][j] != b.grid[j][i])
                {
                    is_same = false;
                    break;
                }
            }
            if (!is_same)
                break;
        }
        if (is_same)
            return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    string str;
    loop(i, n)
    {
        cin >> str;
        loop(j, n)
        {
            if (str[j] == '.')
            {
                s[i][j] = 0;
            }
            else
            {
                s[i][j] = 1;
            }
        }
    }
    loop(i, n)
    {
        cin >> str;
        loop(j, n)
        {
            if (str[j] == '.')
            {
                t[i][j] = 0;
            }
            else
            {
                t[i][j] = 1;
            }
        }
    }
    Grid s_min = minimum_grid(&(s[0][0]), n);
    Grid t_min = minimum_grid(&(t[0][0]), n);

    if (is_same_grid(s_min, t_min))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}