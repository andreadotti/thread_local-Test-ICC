#include <memory>
#include <iostream>

namespace { 
  struct do_nothing_deleter {
    inline void operator() (void const* ) const {}
  };

  class A {};
  class B {};
  struct defaults {
    defaults(A& _a, B& _b) : theA(&_a, do_nothing_deleter() ) 
			   , theB(&_b, do_nothing_deleter() ) {}
    std::shared_ptr<A> theA;
    std::shared_ptr<B> theB;
    void printMe() const { std::cout<< "Just pring out something: "<<theA<<" "<<theB<<std::endl; }
  };


  defaults& theDefaults() {
    static thread_local A anA;
    static thread_local B aB;
    static thread_local defaults theDefaults(anA,aB);
    return theDefaults;
  }
}
 
#include "ClientAPI.hh"
ClientAPI::ClientAPI() {
    defaults dd = theDefaults();
    dd.printMe();
}

  
