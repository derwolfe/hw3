#include <exception>
#include <string>

using namespace std;

class empty_list_exception : public runtime_error {
  public:
    empty_list_exception ( const string & message="" ) : exception ( message.c_str() );
    {}
};


