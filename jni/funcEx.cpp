#include <stdio.h>
#include <android/log.h>
#include "CallStack.h"

#define LOG_TAG "unwind"

void funcC()
{
	int i;
	CallStack cs;
	cs.dump();
}

void funcB()
{
    funcC();
}
void funcA()
{
    funcB();
}
