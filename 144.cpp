#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <cstdio>
 
using namespace std;
 
const int base = 1000 * 1000 * 1000;
 
void input(const string& s, deque <int>& a)
{
    for (int i = s.length(); i > 0; i -= 9)
    if (i < 9)
        a.push_back(atoi(s.substr(0, i).c_str()));
    else
        a.push_back(atoi(s.substr(i - 9, 9).c_str()));
}
 
deque <int> sum(deque <int>& c, deque <int>& b)
{
    deque <int> a(c);
    int carry = 0;
    for (size_t i = 0; i < max(a.size(), b.size()) || carry; ++i)
    {
        if (i == a.size())
            a.push_back(0);
        int curr = a[i] + carry;
        if (i < b.size())
            curr += b[i];
        carry = (curr >= base);
        if (carry)
            curr -= base;
        a[i] = curr;
    }
    return a;
}
 
deque <int> sub(deque <int>& c, deque<int>& b)
{
    deque <int> a(c);
    int carry = 0;
    for (size_t i = 0; i < b.size() || carry; ++i)
    {
        a[i] -= carry;
        if (i < b.size())
            a[i] -= b[i];
        carry = a[i] < 0;
        if (carry)
            a[i] += base;
    }
    return a;
}
 
void normalize(deque <int>& a, deque <int>& b)
{
    size_t num = max(a.size(), b.size());
    if ((num & 1))
        ++num;
    while (a.size() < num)
        a.push_back(0);
    while (b.size() < num)
        b.push_back(0);
}
 
deque <int> mul(deque <int>& c, deque <int>& b)
{
    deque <int> a(c.size() + b.size());
    for (size_t i = 0; i < c.size(); ++i)
    {
        int carry = 0;
        for (size_t j = 0; j < b.size() || carry; ++j)
        {
            long long curr = a[i + j] + carry;
            if (j < b.size())
                curr += c[i] * 1ll * b[j];
            a[i + j] = (int) (curr % base);
            carry = (int) (curr / base);
        }
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    return a;
}
 
void multiply_by_base(deque <int>& a, int k)
{
    for (int i = 0; i < k; ++i)
        a.push_front(0);
}
 
deque <int> fast_multiplication(deque <int>& x, deque <int>& y)
{
    normalize(x, y);
    if (x.size() <= 2 && y.size() <= 2)
        return mul(x, y);
 
    int middle = x.size() / 2;
    deque<int> a, b, c, d;
 
    for (int i = 0; i < middle; ++i)
    {
        b.push_back(x[i]);
        d.push_back(y[i]);
    }
    for (size_t i = middle; i < x.size(); ++i)
    {
        if (i < x.size())
            a.push_back(x[i]);
        if (i < y.size())
            c.push_back(y[i]);
    }
 
    deque <int> z0 = fast_multiplication(a, c),
        z2 = fast_multiplication(b, d),
        z1 = fast_multiplication(sum(a, b), sum(c, d));
    z1 = sub(sub(z1, z0), z2);
    multiply_by_base(z0, x.size());
    multiply_by_base(z1, middle);
    return sum(sum(z0, z1), z2);
}
 
void print(const deque <int>& a)
{
    cout << a.back();
    for (int i = (int)a.size() - 2; i >= 0; --i)
        printf("%09d", a[i]);
}
 
int main()
{
    freopen("INPUT.TXT", "r", stdin);
    freopen("OUTPUT.TXT", "w", stdout);
    deque <int> a, b;
    string s;
    cin >> s;
    input(s, a);
    cin >> s;
    input(s, b);
    if (a.size() < b.size())
        swap(a, b);
    deque <int> ans = fast_multiplication(a, b);
    while (ans.size() > 1 && ans.back() == 0)
        ans.pop_back();
    print(ans);
}