#include <stdio.h>
#include <unwind.h>
#include <unistd.h>
#include <stdlib.h> //strtoul
#include <android/log.h>

// 6f000000-6f01e000 rwxp 00000000 00:0c 16389419   /system/lib/libcomposer.so
// 012345678901234567890123456789012345678901234567890123456789
// 0         1         2         3         4         5

/* depends how the system includes define this */
extern "C"{
typedef struct _mapinfo {
    struct _mapinfo* next;
    uintptr_t start;
    uintptr_t end;
//    char is_readable;  don't need, for excutable -> readable
//    bool is_executable;
//    void* data; // arbitrary data associated with the map by the user, initially NULL
    char name[];
} mapinfo;

#ifdef HAVE_UNWIND_CONTEXT_STRUCT
	typedef struct _Unwind_Context __unwind_context;
#else
	typedef _Unwind_Context __unwind_context;
#endif
	typedef struct
	{
	    size_t count;
	    intptr_t* addrs;
	    const mapinfo* map_info_list;
	} stack_crawl_state_t;

}

class CallStack
{
#define BACKTRACE_SIZE      32

public:
	CallStack()
	{
		init();
	}
	void dump();

private:
	intptr_t backtrace[BACKTRACE_SIZE];
	mapinfo *mapinfohead;
	
	mapinfo *parse_maps_line(char *);
	void deinit_mapinfo();
	void print_mapinfo();
	int try_get_word(uintptr_t ptr, uint32_t* out_value);
	int try_get_half_word(uint32_t pc, uint16_t* out_value);
	uintptr_t rewind_pc_arch(uintptr_t pc);
	bool init_mapinfo(int pid);
	mapinfo* find_map_info(uintptr_t addr);
	void init();
	int get_backtrace(intptr_t* addrs, size_t max_entries);
};


