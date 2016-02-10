#ifndef __TESTCLASS_H__
#define __TESTCLASS_H__

class TestClass
{
	public:
	void *operator new(unsigned int Size);
	void  operator delete(void *p);
	
	private:
	char buffer[1000];
	
};
#endif //__TESTCLASS_H__
