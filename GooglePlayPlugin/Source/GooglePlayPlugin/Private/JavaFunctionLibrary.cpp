// Fill out your copyright notice in the Description page of Project Settings.


#include "JavaFunctionLibrary.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"


	#define INIT_JAVA_METHOD(name, signature) \
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true)) { \
	name = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, #name, signature, false); \
	check(name != NULL); \
	} else { \
	check(0); \
	}

	#define DECLARE_JAVA_METHOD(name) \
	static jmethodID name = NULL;

	DECLARE_JAVA_METHOD(AndroidThunkJava_TryLogin);
	DECLARE_JAVA_METHOD(AndroidThunkJava_GetGooglePGSPlayerId);
	DECLARE_JAVA_METHOD(AndroidThunkJava_GetGoogleDisplayName);


	void UJavaFunctionLibrary::InitJavaFunctions()
	{
		INIT_JAVA_METHOD(AndroidThunkJava_TryLogin, "()V");
		INIT_JAVA_METHOD(AndroidThunkJava_GetGooglePGSPlayerId, "()Ljava/lang/String;");
		INIT_JAVA_METHOD(AndroidThunkJava_GetGoogleDisplayName, "()Ljava/lang/String;");
	}
	#undef DECLARE_JAVA_METHOD
	#undef INIT_JAVA_METHOD

#endif



void UJavaFunctionLibrary::TryLogin()
{

	#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_TryLogin);
	}
	#endif
}

FString UJavaFunctionLibrary::GetGooglePGSPlayerId()
{
	#if PLATFORM_ANDROID
			if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
			{
				jobject javaResult =  FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_GetGooglePGSPlayerId);
				jstring javaString = static_cast<jstring>(javaResult);
				const char* utfChars = Env->GetStringUTFChars(javaString, nullptr);
				FString ueString = UTF8_TO_TCHAR(utfChars);
				return ueString;
			}
	#endif
		return FString();
}

FString UJavaFunctionLibrary::GetGooglePGSDisplayName()
{
	#if PLATFORM_ANDROID
		if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
		{
			jobject javaResult =  FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_GetGoogleDisplayName);
			jstring javaString = static_cast<jstring>(javaResult);
			const char* utfChars = Env->GetStringUTFChars(javaString, nullptr);
			FString ueString = UTF8_TO_TCHAR(utfChars);
			return ueString;
		}
	#endif
		return FString();

}
