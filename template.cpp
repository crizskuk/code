#include <iostream>
#include <stdint.h>


template <class T, class X, class Z = std::string&>
class idol {
public:
	idol() {
		std::cout << "gracias por usar esta clase\n";
	}
	idol(T) {
		std::cout << "jeje\n";
		return T;
	}

	T suma(T x) {
		std::cout << "gracias por usar suma\n";
		return x + 5;
	}

	T info(T p);

	void displayname(Z name) {
		std::cout << "hola: " << name << std::endl;
	}
};

template <class T, class X, class Z>
T idol<T, X, Z>::info(T) {
	std::cout << "info info info\n";	
	return 1;
}

int main(void) {
	std::string name(500, '\x41');
	uint16_t edad = 21;
	idol<uint16_t, uint16_t, std::string> v1;
	std::cout << "la suma is: " << v1.suma(edad) << std::endl;
	v1.info(edad);
	v1.displayname(name);
	return 0;
}