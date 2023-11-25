#include<iostream>
using namespace std;

class FLOAT
{
  float a;

public:
  FLOAT(float value) : a(value)
  {
    cout << "Object created with value: " << a << endl;
  }

  FLOAT operator+ (const FLOAT &obj)
  {
    FLOAT res(a + obj.a);
    cout << "Result of addition: " << res.a << endl;
    return res;
  }

  FLOAT operator- (const FLOAT &obj)
  {
    FLOAT res(a - obj.a);
    cout << "Result of subtraction: " << res.a << endl;
    return res;
  }

  FLOAT operator* (const FLOAT &obj)
  {
    FLOAT res(a * obj.a);
    cout << "Result of multiplication: " << res.a << endl;
    return res;
  }

  FLOAT operator/ (const FLOAT &obj)
  {
    if (obj.a != 0) {
      FLOAT res(a / obj.a);
      cout << "Result of division: " << res.a << endl;
      return res;
    } else {
      cerr << "Error: Division by zero" << endl;
      exit(EXIT_FAILURE);
    }
  }

  void dis ()
  {
    cout << "Value: " << a << endl;
  }
};

int main ()
{
  float f1_value = 10.5;
  float f2_value = 5.0;

  FLOAT f1(f1_value);
  FLOAT f2(f2_value);

  FLOAT f3 = f1 + f2;
  
  cout << "Final result: ";
  f3.dis();

  return 0;
}
