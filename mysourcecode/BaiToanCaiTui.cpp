#include <bits/stdc++.h>
using namespace std;
#define NMAX 1000001

int n, b;
int a[NMAX], c[NMAX]; // 2 mang luu gia tri ai, ci
int c_max;      // tong gia tri lon nhat dc cho vào trong túi
int c_now;      // tong giá tri hien tai trong túi
int a_now;      // tong khoi luong hien tai
// void solution()
//{
// }

void Try(int k) {
  for (k = 1; k <= n; k++) {
    if (a_now + a[k] < b) {
      a_now += a[k];
      c_now += c[k];
      if (c_now > c_max)
        c_max = c_now;
      Try(k + 1);
      a_now -= a[k];
      c_now -= c[k];
    }
  }
}

int main() {
  cin >> n >> b;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cin >> c[i];
  }
  a_now = 0;
  c_now = 0;
  c_max = 0;
  Try(1);
  cout << c_max;
}
