#include <React-Codegen/RNCppTurboSpecJSI.h>


namespace facebook::react {
class NativeCppTurboModule: public NativeCppTurboCxxSpec<NativeCppTurboModule> {
public:
    NativeCppTurboModule(std::shared_ptr<CallInvoker> jsInvoker);
    
    jsi::String reverseString(jsi::Runtime &rt, jsi::String str);
    jsi::Array getNumbers(jsi::Runtime &rt);
    jsi::Object getOBject(jsi::Runtime &rt);
    jsi::Value promiseNumber(jsi::Runtime &rt, double value);
    void callMeLater(jsi::Runtime &rt, jsi::Function successCB, jsi::Function failureCB);

};
}

