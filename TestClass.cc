#include "TestClass.h"
#include "MemPool.h"

extern MemoryPool m1_MemPool;
	

void *TestClass::operator new(unsigned int Size)
{
	return m1_MemPool.Allocate(Size);
}


void  TestClass::operator delete(void *p)
{
	m1_MemPool.Free(p);
}

