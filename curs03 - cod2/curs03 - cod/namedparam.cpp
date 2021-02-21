// http://www.parashift.com/c++-faq-lite/ctors.html#faq-10.18

#include <iostream>
using namespace std;

class myFunc
  {
  private:
    int _a, _b, _c;

  public:
    myFunc( int a = 1, int b = 2, int c = 3 ): _a( a ), _b( b ), _c( c ) { }
    inline myFunc& a( int value ) { _a = value; return *this; }
    inline myFunc& b( int value ) { _b = value; return *this; }
    inline myFunc& c( int value ) { _c = value; return *this; }
    operator int ()
      {
      return (_a * _b) + _c;
      }
  };

int main()
  {
  cout << myFunc()               << endl;  // prints (1 *  2) + 3 --> 5
  cout << myFunc().b( 10 )       << endl;  // prints (1 * 10) + 3 --> 13
  cout << myFunc( 5, 7 )         << endl;  // prints (5 *  7) + 3 --> 38
  cout << myFunc().a( 5 ).b( 7 ) << endl;  // same as last

  return 0;
  }
