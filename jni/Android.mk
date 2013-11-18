LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := funcEx.cpp CallStack.cpp

LOCAL_MODULE := libfuncEx
LOCAL_LDLIBS := -llog

LOCAL_MODULE_TAGS := test

include $(BUILD_SHARED_LIBRARY)


include $(CLEAR_VARS)

LOCAL_SRC_FILES := main.cpp 

LOCAL_SHARED_LIBRARIES +=  \
	libfuncEx
	
LOCAL_LDLIBS := -llog

LOCAL_MODULE := test_callstack

LOCAL_MODULE_TAGS := test

include $(BUILD_EXECUTABLE)

