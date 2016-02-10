/* HEADER FILES */

#include <iostream>
#include <stdlib.h>

#include "MemPool.h"

using namespace std;

/* DEFINING Constructor & Destructor 
 * This is the file to define the Constructor and Destructor of the Base Class
 * Constructor : MemoryPool(unsigned long num_of_units = 50, unsigned long unit_size = 1024)
 * Destructor: ~MemoryPool();
 *
 */

MemoryPool::MemoryPool(unsigned long num_of_units, unsigned long unit_size):
	MemBlockaddress(NULL), AllocattedMemBlock(NULL), FreeMemBlock(NULL),
	blocksize(num_of_units * (unit_size + sizeof(struct Node_unit))),
	unitsize(unit_size) 
{
	MemBlockaddress = ::malloc(blocksize);
	
	if(NULL != MemBlockaddress)
	{
		for(unsigned long i=0; i< num_of_units; i++)
		{
			struct Node_unit *Currentunit = (struct Node_unit *)( (char *)MemBlockaddress + i*(unit_size+sizeof(struct Node_unit)) );
			
			Currentunit->pPrev = NULL;
			Currentunit->pNext = (Node_unit *) MemBlockaddress;  // INSERTING THE NEW UNIT IN THE HEAD

			if(NULL != FreeMemBlock)
			{
				FreeMemBlock->pPrev = Currentunit;
			}
			FreeMemBlock = Currentunit;
		}
	}
}

/* FREEES THE MEMORY BLOCK */

MemoryPool::~MemoryPool() 
{

	::free(MemBlockaddress);
}



/* ALLOCATE MEMORY FUNCTION  
 *
 * When we want to allocate a memory unit, if there is no space in the pool, we call out for 
 * A Memory unit will call out for a system function
 */


void* MemoryPool::Allocate(unsigned long Size, bool UseMemPool)
{

	if(Size > unitsize || false == UseMemPool ||
	   NULL == MemBlockaddress || NULL == FreeMemBlock)

	{
		return malloc(Size);
	}

	struct Node_unit *Currentunit = FreeMemBlock;
	FreeMemBlock = Currentunit->pNext;
	
	if( NULL!= FreeMemBlock)
	{
		FreeMemBlock->pPrev = NULL;
	}

	Currentunit->pNext = AllocattedMemBlock;
	
	if(NULL != AllocattedMemBlock)
	{
		AllocattedMemBlock->pPrev = Currentunit;
	}

	AllocattedMemBlock = Currentunit;
	
	return (void *)((char *)Currentunit + sizeof(struct Node_unit));
}

/* FREE MEMORY 
 * To free a memory unit we have to consider a Case
 * IF pointer of a parameter points to the memory unit ----> insert into the Free Linked List 
 * ELSE Call System Function Free
 *
 * What this does???  - Points to a memory unit and Frees it! 
 */


void MemoryPool::Free(void *s1)
{

	if(MemBlockaddress < s1 && s1 < (void *)((char*) MemBlockaddress + blocksize))
	{
		struct Node_unit* Currentunit = (struct Node_unit *)((char*)s1 - sizeof(struct Node_unit));
		AllocattedMemBlock = Currentunit->pNext;
		
		if(NULL != AllocattedMemBlock)
		{
			AllocattedMemBlock->pPrev = NULL;
		}
		Currentunit->pNext = FreeMemBlock;
		if(NULL != FreeMemBlock)
		{
			FreeMemBlock->pPrev = Currentunit;
		}

		FreeMemBlock = Currentunit;
	}

	else
	{
		free(s1);
	}
}
