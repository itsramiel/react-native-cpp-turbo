#include "NativeCppTurboModule.h"


namespace facebook::react {
NativeCppTurboModule::NativeCppTurboModule(std::shared_ptr<CallInvoker> jsinvoker)
: NativeCppTurboCxxSpec(std::move(jsinvoker)) {}

jsi::String NativeCppTurboModule::reverseString(jsi::Runtime &rt, jsi::String str) {
    std::string stdStr = str.utf8(rt);
    std::reverse(stdStr.begin(), stdStr.end());
    
    return jsi::String::createFromUtf8(rt, stdStr);
}

jsi::Array NativeCppTurboModule::getNumbers(jsi::Runtime &rt) {
    jsi::Array array = jsi::Array(rt, 10);
    
    for (std::size_t i = 0; i < 10; ++i) {
        array.setValueAtIndex(rt, i, jsi::Value(static_cast<int>(i)));
    }
    
    return array;
}

jsi::Object NativeCppTurboModule::getOBject(jsi::Runtime &rt) {
    jsi::Object obj = jsi::Object(rt);
    
    obj.setProperty(rt, "result", jsi::String::createFromUtf8(rt, "success"));
    
    return obj;
}

jsi::Value NativeCppTurboModule::promiseNumber(jsi::Runtime &rt, double number) {
    
    jsi::Function promiseConstructor = rt.global().getPropertyAsFunction(rt, "Promise");
    
    
    return promiseConstructor.callAsConstructor(rt,
                                                jsi::Function::createFromHostFunction(
                                                                                      rt,
                                                                                      jsi::PropNameID::forAscii(rt, "promiseArg"),
                                                                                      2,
                                                                                      [number](
                                                                                               jsi::Runtime& runtime,
                                                                                               const jsi::Value& thisValue,
                                                                                               const jsi::Value* arguments,
                                                                                               std::size_t count
                                                                                               ) -> jsi::Value {
                                                                                                   jsi::Function resolve = arguments[0].asObject(runtime).asFunction(runtime);
                                                                                                   resolve.call(runtime, number);
                                                                                                   return jsi::Value::undefined();
                                                                                               }
                                                                                      )
                                                
                                                );

}

void NativeCppTurboModule::callMeLater(jsi::Runtime &rt, jsi::Function successCB, jsi::Function failureCB) {
    bool callSuccess = std::rand() % 2;
    
    if(callSuccess) {
        successCB.call(rt);
    } else {
        failureCB.call(rt);
    }

}





}

