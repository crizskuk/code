#include <iostream>
#include <stdint.h>

class base {
public:
	uint16_t password = 0xfff;
	base() {std::cout << "base constructor" << std::endl;}
	~base() {std::cout << "base destructor\n" << std::endl;}
	virtual void msg(void) { std::cout << "msg base\n" << std::endl; }
};

class derived : public base {
public:
	derived() { std::cout << "derived constructor" << std::endl; datas = new uint16_t[5]; }
	~derived() { std::cout << "derived  destructor\n" << std::endl; }
	//void msg(void) { std::cout << "msg derived\n" << std::endl; delete datas; }
private:
	uint16_t *datas;
};

class lost : public derived {
public:
	lost() { std::cout << "lost  constructor" << std::endl; }
	~lost() { std::cout << "lost   destructor\n" << std::endl; }
	void msg(void) { std::cout << "msg lost \n" << std::endl; }
};

int main(void*) {

	derived* l1 = new lost();
	l1->msg();
	//delete l1;
	std::cout << l1->password << std::endl;
	return 0;
}