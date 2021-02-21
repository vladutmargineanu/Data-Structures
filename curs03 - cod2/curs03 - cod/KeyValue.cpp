#include <iostream>
using namespace std;

template<class T>
class KeyValue{
    T value;
    int key;
  public:
    KeyValue(int key){
      this->key = key;
    }

    ~KeyValue() {
    }

    T getValue() {
      return value;
    }

    void setValue(T value) {
      this->value = value;
    }
};



int main() {
  KeyValue<string> numar = KeyValue<string>(3);
  numar.setValue("trei");

  KeyValue<string> numere[] = {1,2,3};
  numere[0].setValue("unu");
  numere[0].setValue("doi");
  numere[0].setValue("trei");

  //KeyValue<Student> grupa[30];
  //grupa[0].setValue(Student());
}
