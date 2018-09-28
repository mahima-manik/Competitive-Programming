#include<iostream>
using namespace std;

void mystery(int &b, int c, int &a)
{
  cout << a << " " << b << " " << c << endl;
	a++;
  b--;
  c += a;
cout << a << " " << b << " " << c << endl;
}

int main()
{
  int a = 5;
  int b = 2;
  int c = 8;
  mystery(c, a, b);
  cout << a << " " << b << " " << c << endl;
  return 0;
}
