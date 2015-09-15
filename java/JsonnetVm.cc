#include "com_google_jsonnet_JsonnetVm.h"

void Java_com_google_jsonnet_JsonnetVm_setMaxStack(JNIEnv* env,
                                                   jobject object,
                                                   jint depth) {

}

void Java_com_google_jsonnet_JsonnetVm_setGcMinObjects(JNIEnv* env,
                                                       jobject object,
                                                       jint num_objects) {

}

void Java_com_google_jsonnet_JsonnetVm_setGcGrowthTrigger(JNIEnv* env,
                                                          jobject object,
                                                          jdouble growth) {

}

void Java_com_google_jsonnet_JsonnetVm_expectStringOutput(JNIEnv* env,
                                                          jobject object,
                                                          jboolean v) {

}

void Java_com_google_jsonnet_JsonnetVm_setExtVar(JNIEnv* env,
                                                 jobject object,
                                                 jstring key,
                                                 jstring value) {

}

void Java_com_google_jsonnet_JsonnetVm_setExtCodeVar(JNIEnv* env,
                                                     jobject object,
                                                     jstring key,
                                                     jstring value) {

}

void Java_com_google_jsonnet_JsonnetVm_setDebugAst(JNIEnv* env,
                                                   jobject object,
                                                   jboolean debug_ast) {

}

void Java_com_google_jsonnet_JsonnetVm_setMaxTrace(JNIEnv* env,
                                                   jobject object,
                                                   jint lines) {

}

jstring Java_com_google_jsonnet_JsonnetVm_evaluateFile(JNIEnv* env,
                                                       jobject object,
                                                       jstring filename) {

}

jstring Java_com_google_jsonnet_JsonnetVm_evaluateSnippet(JNIEnv* env,
                                                          jobject object,
                                                          jstring filename,
                                                          jstring snippet) {

}

jobjectArray Java_com_google_jsonnet_JsonnetVm_evaluateFileMulti(
    JNIEnv* env,
    jobject object,
    jstring filename) {
}

jobjectArray Java_com_google_jsonnet_JsonnetVm_evaluateSnippetMulti(
    JNIEnv* env,
    jobject object,
    jstring filename,
    jstring snippet) {

}
