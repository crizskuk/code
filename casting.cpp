#include <iostream>
#include <stdint.h>

int main(void) {
	uint16_t edad = 8;
	int total = static_cast<uint16_t>(edad) + 5;
	std::cout << "edad total is: " << total << std::endl;
	return 0;
}