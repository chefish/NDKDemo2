#include <jni.h>
#include <string>
#include "Cow.h"

extern "C" {

    JNIEXPORT jstring JNICALL Java_com_fish_ndkdemo2_MainActivity_stringFromJNI(
            JNIEnv *env,
            jobject /* this */) {
        std::string hello = "Hello from PA ++";
        Cow *cow = new Cow();
        cow->readProcStat();
    //    char* ppp = cow->readProcStat();
        return env->NewStringUTF(hello.c_str());
    }

    JNIEXPORT jstring JNICALL Java_com_fish_ndkdemo2_MainActivity_track(
            JNIEnv *env,
            jobject thiz) {
        std::string hello = "Hello from PA ++";

        jmethodID notification_method = env->GetMethodID(env->GetObjectClass(thiz),"showMessage","()V");
        env->CallVoidMethod(thiz,notification_method);

        return env->NewStringUTF(hello.c_str());
    }

}

