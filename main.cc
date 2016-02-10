/* MAIN IMPLPEMENTATION 
 */

#include <iostream>
using namespace std;
#include "MemPool.h"
#include "TestClass.h"
#include "TestClass2.h"
#define LOOP_TIMES 100000*Testcount

clock_t begin, end;
double time_spent;

MemoryPool m1_MemPool[10];

int main()
{
	
	for(int Testcount=1; Testcount<=10; Testcount++)
	{
		unsigned int i;
		begin = clock();
		for(i=0;i<= LOOP_TIMES; i++)
		{
			// USING MEMORY POOL
			TestClass2 *s2 = new TestClass2;
			delete s2;
		}
		end = clock();
        	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

		cout<< "[Repeat" << LOOP_TIMES << "Times]"<<"Using Memory Pool Interval ="<<time_spent<<"ms";
		cout<<endl;
	}	


 	return 0;
}
