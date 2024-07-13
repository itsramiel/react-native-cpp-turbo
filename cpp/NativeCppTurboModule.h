#if __has_include(<React-Codegen/RNCppTurboSpecJSI.h>)
#include <React-Codegen/RNCppTurboSpecJSI.h>
#elif __has_include("RNCppTurboSpecJSI.h")
#include "RNCppTurboSpecJSI.h"
#endif


namespace facebook::react {
class NativeCppTurboModule: public NativeCppTurboCxxSpec<NativeCppTurboModule> {
public:
    NativeCppTurboModule(std::shared_ptr<CallInvoker> jsInvoker);

    std::string reverseString(jsi::Runtime &rt, std::string str);
    std::vector<int> getNumbers(jsi::Runtime &rt);
    std::map<std::string, std::string> getOBject(jsi::Runtime &rt);
    jsi::Value promiseNumber(jsi::Runtime &rt, double value);
    void callMeLater(jsi::Runtime &rt, jsi::Function successCB, jsi::Function failureCB);

};
}

