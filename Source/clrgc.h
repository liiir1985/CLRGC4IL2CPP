#pragma once

namespace clrgc
{
	void* AllocateFixed(size_t size);

	void FreeFixed(void* addr);
}