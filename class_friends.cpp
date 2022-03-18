#include <iostream>
#include <stdint.h>

class base_b;

class base_a {
public:
	friend uint16_t suma_class(base_a a1, base_b b1);
	uint16_t x = 10;
	friend class base_b;
	void msg(void) {
		std::cout << "hola soy base_a::msg" << std::endl;
	}
};

class base_b {
public:
	friend uint16_t suma_class(base_a a1, base_b b1);
	uint16_t x = 5;
	int add(void) {
		base_b a1;
		a1.msg();
		return 0;
	}

	void msg(void) {
		std::cout << "soy base_b::msg" << std::endl;
	}
};	

uint16_t suma_class(base_a a1, base_b b1) {
	return (a1.x + b1.x);
}

int main(void) {
	base_b b1;
	base_a a1;
	b1.add();
	std::cout << "la suma de los objetos son: " << suma_class(a1, b1) << std::endl;
	return 0;
}