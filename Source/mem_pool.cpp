#include "os/Mutex.h"
#include "clrgc.h"

namespace clrgc
{
#define SEGMENT_SIZE (16 * 1024)
	struct MemSegmentInfo
	{
		void* segStart;
		void* curPos;
		void* segEnd;
		MemSegmentInfo* next;
	};

	MemSegmentInfo* memSegments = NULL;

	inline MemSegmentInfo* FindMemSegment(size_t size)
	{
		MemSegmentInfo* cur = memSegments;
		while (cur)
		{
			size_t remaining = (intptr_t)cur->segEnd - (intptr_t)cur->segStart;
			if (remaining >= size)
				return cur;
			cur = cur->next;
		}
		return NULL;
	}
	void* clrgc::AllocateInternal(size_t size)
	{
		MemSegmentInfo* seg = FindMemSegment(size);

		if (seg == NULL)
		{
			seg = (MemSegmentInfo*)malloc(sizeof(MemSegmentInfo));
			seg->segStart = malloc(SEGMENT_SIZE);
			memset(seg->segStart, 0, SEGMENT_SIZE);
			seg->curPos = seg->segStart;
			seg->segEnd = (void*)((intptr_t)seg->segStart + SEGMENT_SIZE);
			seg->next = memSegments;
			memSegments = seg;
		}

		void* res = seg->curPos;
		seg->curPos = (void*)((intptr_t)seg->curPos + size);

		return res;
	}

	bool clrgc::IsValidInternalMemory(void* ptr)
	{
		MemSegmentInfo* cur = memSegments;
		while (cur)
		{
			if (ptr >= cur->segStart && ptr < cur->segEnd)
				return true;
			cur = cur->next;
		}
		return false;
	}
}
