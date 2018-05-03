#include <bsl_string.h>

namespace mylibrary {
using namespace BloombergLP;

class Hello {
	public:
		static void sayHello(const bslstl::StringRef& name);
};

}
