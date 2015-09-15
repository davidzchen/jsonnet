/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_google_jsonnet_JsonnetVm */

#ifndef _Included_com_google_jsonnet_JsonnetVm
#define _Included_com_google_jsonnet_JsonnetVm
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_google_jsonnet_JsonnetVm
 * Method:    setMaxStack
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_google_jsonnet_JsonnetVm_setMaxStack
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_google_jsonnet_JsonnetVm
 * Method:    setGcMinObjects
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_google_jsonnet_JsonnetVm_setGcMinObjects
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_google_jsonnet_JsonnetVm
 * Method:    setGcGrowthTrigger
 * Signature: (D)V
 */
JNIEXPORT void JNICALL Java_com_google_jsonnet_JsonnetVm_setGcGrowthTrigger
  (JNIEnv *, jobject, jdouble);

/*
 * Class:     com_google_jsonnet_JsonnetVm
 * Method:    expectStringOutput
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_com_google_jsonnet_JsonnetVm_expectStringOutput
  (JNIEnv *, jobject, jboolean);

/*
 * Class:     com_google_jsonnet_JsonnetVm
 * Method:    setExtVar
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_google_jsonnet_JsonnetVm_setExtVar
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_google_jsonnet_JsonnetVm
 * Method:    setExtCodeVar
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_google_jsonnet_JsonnetVm_setExtCodeVar
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_google_jsonnet_JsonnetVm
 * Method:    setDebugAst
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_com_google_jsonnet_JsonnetVm_setDebugAst
  (JNIEnv *, jobject, jboolean);

/*
 * Class:     com_google_jsonnet_JsonnetVm
 * Method:    setMaxTrace
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_google_jsonnet_JsonnetVm_setMaxTrace
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_google_jsonnet_JsonnetVm
 * Method:    evaluateFile
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_google_jsonnet_JsonnetVm_evaluateFile
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_google_jsonnet_JsonnetVm
 * Method:    evaluateSnippet
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_google_jsonnet_JsonnetVm_evaluateSnippet
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_google_jsonnet_JsonnetVm
 * Method:    evaluateFileMulti
 * Signature: (Ljava/lang/String;)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_com_google_jsonnet_JsonnetVm_evaluateFileMulti
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_google_jsonnet_JsonnetVm
 * Method:    evaluateSnippetMulti
 * Signature: (Ljava/lang/String;Ljava/lang/String;)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_com_google_jsonnet_JsonnetVm_evaluateSnippetMulti
  (JNIEnv *, jobject, jstring, jstring);

#ifdef __cplusplus
}
#endif
#endif
