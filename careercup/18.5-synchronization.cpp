#include <thread>
#include <string>
#include <vector>
#include <mutex>
#include <iostream>

using namespace std;

class Foo
{
  vector<thread> pool;
  mutex ma;
  mutex mb;
  mutex mc;
public:
  Foo() {
    ma.lock();
    mb.lock();
  }

  void A() {
    pool.push_back(
      thread([=]{
        mc.lock();
        func("A");
        mc.unlock();
        ma.unlock();
      }));
  }
  void B() {
    pool.push_back(
      thread([=]{
        ma.lock();
        func("B");
        ma.unlock();
        mb.unlock();
      }));
  }
  void C() {
    pool.push_back(
      thread([=]{
        mb.lock();
        mc.lock();
        func("C");
        mc.unlock();
        mb.unlock();
      }));
  }

  void func(const string &str) {
    cout << "Inside " << str << endl;
  }

  ~Foo() {
    for (auto &th : pool) {
      th.join();
    }
  }
};

int main(int argc, char const *argv[])
{
  Foo f;
  f.A();
  f.B();
  f.C();

  return 0;
}