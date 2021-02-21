#include <iostream>
#include <algorithm>
using namespace std;

struct Integer {
    int value;

    bool operator<(const Integer &integer) {
       //TODO: supraincarcati operatorul
      if (value < integer.value) {
        return false;
      }
      return true;
    }
};

int main()
{
    int n;
    cin >> n;

    Integer *array = new Integer[n];
    for (int i = 0; i < n; ++i) {
        cin >> array[i].value;
    }
    sort(array, array + n);

    for (int i = 0; i < n; ++i) {
        cout << array[i].value << " ";
    }
    return 0;
}

