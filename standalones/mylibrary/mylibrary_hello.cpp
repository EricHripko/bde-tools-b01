#include <mylibrary_hello.h>
#include <bsl_iostream.h>

namespace mylibrary {

void Hello::sayHello(const bslstl::StringRef& name)
{
	bsl::cout << "Hello, " << name << bsl::endl;
}

}
