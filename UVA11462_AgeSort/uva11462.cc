#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

constexpr size_t MAX_AGE = 100;

void noOp() {}
void spc() { cout << ' '; }

int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  using Total = unsigned long;
  array<Total, MAX_AGE+1> total;

  int ages;
  while( (cin >> ages) && (ages > 0) ) {
    fill(total.begin(), total.end(), 0);
    for( int a = 0; a < ages; ++a ) {
      int age;
      cin >> age;
      ++total[age];
    }
    auto showDelim = &noOp;
    for( int a = 1; a <= MAX_AGE; ++a ) {
      for( Total x = 0; x < total[a]; ++x ) {
        showDelim();
        cout << a;
        showDelim = &spc;
      }
    }
    cout << '\n';
  }
}
