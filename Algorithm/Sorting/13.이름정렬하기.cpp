#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp(string left, string right)
{
    if (left.length() > right.length()) return false;
    if (left.length() < right.length()) return true;
    
    return left<right;
}
vector<string> v;
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < N; i++) {
        cout << v[i]<<'\n';
    }
    return 0;
}