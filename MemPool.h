#ifndef __MEMPOOL_H__
#define __MEMPOOL_H__

class MemoryPool
{
	private:
	
	/* Definintion of the Memory Block - Free and allocated */
	// BASIC STRUCTURE OF LINKEDLIST 
	struct Node_unit 
	{
		struct Node_unit *pPrev, *pNext;
	};

	void* MemBlockaddress;  // Address of the Memory Pool - OVERALL CHUNK 
	
	// Defining the starting Point of Allocated and Free Pools 
	struct Node_unit* AllocattedMemBlock; 
	struct Node_unit* FreeMemBlock;

	unsigned long unitsize;
	unsigned long blocksize;

	public:
	// CONSTRUCTOR AND DESTRUCTOR 
	MemoryPool (unsigned long num_of_units = 50, unsigned long unit_size = 1024);
	~MemoryPool();

	// MEMBER FUNCTIONS 
	void* Allocate(unsigned long Size, bool UseMemPool = true);
	void Free(void *s1);
};

#endif //__MEMPOOL_H__

	
