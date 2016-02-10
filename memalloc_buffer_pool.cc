#include <iostream>
using namespace std;

clock_t begin, end;
double time_spent;

char membuff[4100];

class MemPool
{
	char buff[4096];
	public:
	void *operator new(unsigned int size)
	{
		return (void*)membuff;
	}

	void operator delete(void *s1)
	{
	}
};

int main()
{
	begin = clock();

	for(unsigned int i =0; i<0x5fffff;i++)
	{
		MemPool *s1 = new MemPool;
		delete s1;
	}

	end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        cout<<time_spent<<endl;


	return 0;
}
