#include <iostream>
#include <string>

class Toy
{
  std::string name;
public:
  Toy() : name("someToy")
  {
    std::cout << "New toy: " << name << std::endl;
  }
  Toy(std::string inName) : name(inName) {
    std::cout << "New toy: " << name << std::endl;
  }
  Toy(const Toy& toy) : name(toy.name) {
    std::cout << "New toy: " << name << std::endl;
  }
  ~Toy()
  {
    std::cout << "Deleting toy: " << name << std::endl;
  }
};

class shared_toy_ptr
{
  Toy *obj;
  int *counter;
public:
  shared_toy_ptr()
  {
    obj = new Toy("someName");
    counter = new int(1);
    std::cout << "New shared_toy_ptr: " << obj << ": " << counter << ": " << *counter << std::endl;
  }
  shared_toy_ptr(const std::string name)
  {
    obj = new Toy(name);
    counter = new int(1);
    std::cout << "New shared_toy_ptr: " << obj << ": " << counter << ": " << *counter << std::endl;
  }
  shared_toy_ptr(const shared_toy_ptr& inPtr)
  {
    obj = inPtr.obj;
    counter = inPtr.counter;
    (*counter)++;
    std::cout << "New shared_toy_ptr: " << obj << ": " << counter << ": " << *counter << std::endl;
  }
  ~shared_toy_ptr()
  {
    std::cout << "Deleting shared_toy_ptr: " << obj << ": " << counter << ": " << *counter << std::endl;
    if(0 == --(*counter))
    {
      delete this->obj;
      delete this->counter;
    }
  }
  shared_toy_ptr& operator=(const shared_toy_ptr& inPtr)
  {
    if (&inPtr == this)
      return *this;
    if (nullptr != this->obj)
    {
      if(0 == --(*counter))
      {
        delete this->obj;
        delete this->counter;
      }
    }
    obj = inPtr.obj;
    counter = inPtr.counter;
    (*counter)++;
    std::cout << "Assignment shared_toy_ptr: " << obj << ": " << counter << ": " << *counter << std::endl;
    return *this;
  }
};

shared_toy_ptr* make_shared_toy(const std::string name)
{
  return new shared_toy_ptr(name);
}

shared_toy_ptr* make_shared_toy(const shared_toy_ptr& inPtr)
{
  return new shared_toy_ptr(inPtr);
}

int main()
{
  shared_toy_ptr a("Toy_a");
  shared_toy_ptr* pb = make_shared_toy(a);
  shared_toy_ptr* pc = make_shared_toy("toy_c");
  shared_toy_ptr d = a;
  *pb = *pc;
  delete pc;
  a = *pb;
  d = a;
  delete pb;

  return 0;
}
