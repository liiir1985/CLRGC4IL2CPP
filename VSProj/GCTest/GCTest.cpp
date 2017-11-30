// GCTest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "..\..\externals\boehmgc\include\gc.h"

struct AAA
{
	void* object;
	int b;
	intptr_t ptr;
};

void SetValue(AAA* obj, int size);

int main()
{
	GC_INIT();
	AAA* lastObject;
	lastObject = (AAA*)GC_MALLOC(sizeof(AAA));
	lastObject->b = 0x12345678;
	lastObject->ptr = 0x98765321;
	GC_word pheap_size = 0, pfree_bytes = 0, punmapped_bytes = 0, pbytes_since_gc = 0, ptotal_bytes = 0;
	GC_get_heap_usage_safe(&pheap_size, &pfree_bytes, &punmapped_bytes, &pbytes_since_gc, &ptotal_bytes);
	printf("pheap_size=%d, pfree_bytes=%d, punmapped_bytes=%d, pbytes_since_gc=%d, ptotal_bytes=%d\n", pheap_size, pfree_bytes, punmapped_bytes, pbytes_since_gc, ptotal_bytes);
	lastObject->object = (AAA*)GC_MALLOC(sizeof(AAA));
	lastObject->object = (AAA*)GC_MALLOC(sizeof(AAA));
	lastObject->object = (AAA*)GC_MALLOC(sizeof(AAA));
	lastObject->object = (AAA*)GC_MALLOC(sizeof(AAA));
	lastObject->object = (AAA*)GC_MALLOC(sizeof(AAA));
	GC_stop_world_external();
	for (int i = 0; i < 100000; i++) 
	{
		lastObject->object = (AAA*)GC_MALLOC(sizeof(AAA));
	}
	SetValue(lastObject, sizeof(AAA));
	GC_get_heap_usage_safe(&pheap_size, &pfree_bytes, &punmapped_bytes, &pbytes_since_gc, &ptotal_bytes);
	printf("pheap_size=%d, pfree_bytes=%d, punmapped_bytes=%d, pbytes_since_gc=%d, ptotal_bytes=%d\n", pheap_size, pfree_bytes, punmapped_bytes, pbytes_since_gc, ptotal_bytes);
	return 0;
}

void SetValue(AAA* obj, int size) 
{
	volatile intptr_t sp;
	sp = (intptr_t)&sp;
	GC_stack_base sb;
	GC_get_stack_base(&sb);
	printf("AAA=%x\n", obj);
	for (int i = 0; i < 20; i++)
	{
		intptr_t cur = sp + sizeof(void*)*i;
		printf("cur=0x%x = 0x%x\n", cur, *((intptr_t*)cur));
	}
	bool val = size > 0;
	void* res = GC_MALLOC(size);

	obj->object = res;
}

