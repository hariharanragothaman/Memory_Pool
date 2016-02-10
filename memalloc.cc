#include <iostream>
using namespace std;

clock_t begin, end;
double time_spent; 

class TestClass
{
	char temp[5000];
};

int main()
{
	begin = clock();

	for(unsigned int i=0;i<0x5fffff;i++)
	{
		TestClass *s1 = new TestClass;
		delete s1;
	}

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	cout<<time_spent<<endl;

	return 0;
}
