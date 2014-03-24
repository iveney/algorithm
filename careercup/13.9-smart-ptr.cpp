#include <iostream>
using namespace std;

template <typename T>
class smart_ptr {
public:
  smart_ptr(T *ptr) : ptr_(ptr){
    cout << "Initing " << this->ptr_ << endl;
    refcount_ = new unsigned int {1};
  }

  smart_ptr(const smart_ptr<T> &sp) : ptr_(sp.ptr_), refcount_(sp.refcount_) {
    this->ptr_ = sp.ptr_;
    this->refcount_ = sp.refcount_;
    ++(*refcount_);
    cout << "Copying " << sp.ptr_;
    cout << ". Refcount = " << *refcount_ << endl;
  }

  smart_ptr& operator = (const smart_ptr<T> &sp) {
    // point to the same object, does nothing
    if (sp.ptr_  == ptr_)
      return *this;

    this->decrement_count();
    this->ptr_ = sp.ptr_;
    this->refcount_ = sp.refcount_;
    ++(*refcount_);
    return *this;
  }

  ~smart_ptr() {
    cout << this->ptr_ << " : ref count = " << *this->refcount_ << ". Decrement one." << endl;
    decrement_count();
  }

  T val() const {return *ptr_;}
  T& ref() {return *ptr_;}
  // T& val() {return *ptr_;}

private:
  void decrement_count() {
    --(*refcount_);
    if (*refcount_ == 0) {
      cout << "Destroying object..." << endl;
      delete ptr_;
      delete refcount_;
    }
  }

  unsigned int *refcount_ {0};
  T *ptr_ {NULL};
};

int main(int argc, char const *argv[])
{
  smart_ptr<int> ptr(new int{3});
  smart_ptr<int> p2 = ptr;
  smart_ptr<int> p3(new int{5});
  p2.ref() = 20;
  cout << p2.val() << endl;
  ptr = p2;
  ptr = p3;
  return 0;
}