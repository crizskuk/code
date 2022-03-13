#include <iostream>
#include <stdint.h>
#include <vector>

uint16_t Edad(uint16_t x) {
	return x + 5;
}

void PrintEdades(uint16_t x) {
	std::cout << "edad: " << x << std::endl;
}

void BucleForEach(std::vector<uint16_t>& e, void(*func)(uint16_t)) {
	for (auto& x : e) {
		func(x);
	}
}

int main(void) {
	uint16_t(*funct)(uint16_t) = Edad;
	std::cout << "edad is: " << funct(5) << std::endl;
	std::vector<uint16_t> v1 = { 2,4,8,16,32,64 };
	void(*punt)(uint16_t) = PrintEdades;
	BucleForEach(v1,punt);
	BucleForEach(v1, [](uint16_t x) 
		{
			std::cout << "valor: " << x << std::endl; });
	return 0;
}