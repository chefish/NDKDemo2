#include <jni.h>
#include <string>
#include "Cow.h"

extern "C" JNIEXPORT jstring

JNICALL
Java_com_fish_ndkdemo2_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from PA ++";
    Cow* cow = new Cow();
    cow->readProcStat();
//    char* ppp = cow->readProcStat();
    return env->NewStringUTF(hello.c_str());
}
