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
        return env->NewStringUTF(hello.c_str());
    }

    JNIEXPORT jstring JNICALL Java_com_fish_ndkdemo2_MainActivity_track(
            JNIEnv *env,
            jobject thiz) {
        std::string hello = "Hello from PA ++";

//        jmethodID notification_method = env->GetMethodID(env->GetObjectClass(thiz),"showMessage2","()V");
        //注意要加分号
        jmethodID notification_method2 = env->GetMethodID(env->GetObjectClass(thiz),"showMessage","()Ljava/lang/String;");
        jstring ret = static_cast<jstring>(env->CallObjectMethod(thiz, notification_method2));

        return env->NewStringUTF(hello.c_str());
    }

    JNIEXPORT jstring JNICALL Java_com_fish_ndkdemo2_MainActivity_track2(
            JNIEnv *env,
            jobject thiz) {

        Cow *cow = new Cow();
        int x =  cow->callJniMethod();
        std::string hello = "Hello from PA ++";

//        jmethodID notification_method = env->GetMethodID(env->GetObjectClass(thiz),"showMessage","()V");
//        env->CallVoidMethod(thiz,notification_method);

        return env->NewStringUTF(hello.c_str());
    }

}

