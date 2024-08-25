#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

string input()
{
    string s;
    getline(cin, s);
    return s;
}

int inputInt()
{
    return stoi(input());
}

vector<int> splitToInt(string s)
{
    vector<int> result;
    size_t pos = 0;
    while ((pos = s.find(' ')) != string::npos)
    {
        result.push_back(stoi(s.substr(0, pos)));
        s.erase(0, pos + 1);
    }
    result.push_back(stoi(s));
    return result;
}

vector<vector<int>> transpose(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> t(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            t[j][i] = mat[i][j];
        }
    }
    return t;
}

void sol()
{
    int n, m;
    vector<int> nm = splitToInt(input());
    n = nm[0];
    m = nm[1];
    vector<vector<int>> grid1(n);
    vector<vector<int>> grid2(n);
    for (int i = 0; i < n; i++)
    {
        grid1[i] = splitToInt(input());
    }
    for (int i = 0; i < n; i++)
    {
        grid2[i] = splitToInt(input());
    }

    auto checkEquivalence = [](vector<vector<int>> &g1, vector<vector<int>> &g2) -> bool {
        set<vector<int>> st1, st2;
        for (auto &v : g1)
        {
            vector<int> cur(v.begin(), v.end());
            sort(cur.begin(), cur.end());
            st1.insert(cur);
        }
        for (auto &v : g2)
        {
            vector<int> cur(v.begin(), v.end());
            sort(cur.begin(), cur.end());
            st2.insert(cur);
        }
        return st1 == st2;
    };

    if (checkEquivalence(grid1, grid2))
    {
        auto tgrid1 = transpose(grid1);
        auto tgrid2 = transpose(grid2);
        if (checkEquivalence(tgrid1, tgrid2))
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();  // Ignore newline character after integer input
    while (t--) sol();
    return 0;
}
