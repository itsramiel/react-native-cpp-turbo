#include <jni.h>
#include "react-native-cpp-turbo.h"

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_cppturbo_CppTurboModule_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b) {
    return cppturbo::multiply(a, b);
}
