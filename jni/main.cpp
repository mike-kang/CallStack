#include <stdio.h>
#include <android/log.h>
#include "CallStack.h"

#define LOG_TAG "unwind"

extern void funcA();

int main(int argc, char* argv[])
{
    mapinfo* mi;
    __android_log_print(ANDROID_LOG_INFO, LOG_TAG,"Hello, World!!\n");

    funcA();

	return 0;
}
