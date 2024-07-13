#include "NativeCppTurboModule.h"


namespace facebook::react {
NativeCppTurboModule::NativeCppTurboModule(std::shared_ptr<CallInvoker> jsinvoker)
: NativeCppTurboCxxSpec(std::move(jsinvoker)) {}

std::string NativeCppTurboModule::reverseString(jsi::Runtime &rt, std::string str) {
    std::reverse(str.begin(), str.end());

    return str;
}

std::vector<int> NativeCppTurboModule::getNumbers(jsi::Runtime &rt) {
    std::vector<int> array {};

    for (std::size_t i = 0; i < 10; ++i) {
        array.push_back(static_cast<int>(i));
    }

    return array;
}

std::map<std::string, std::string> NativeCppTurboModule::getOBject(jsi::Runtime &rt) {
    std::map<std::string, std::string> map{};

map.insert(std::make_pair("result", "success"));

    return map;
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

