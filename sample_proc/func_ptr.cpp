// 函数指针示例
#include <stdio.h>

class C {
 public:
  int foo(int a){printf("foo\n");}
  int bar(int a){printf("bar\n");}
  void test() {
    int (C::*p)(int);
    p = &C::foo;
    p = &C::bar;
    (this->*p)(1);
  }
};

int main()
{
	C c;
	c.test();
	return 0;
}
