#include <iostream>
#include <thread>
#include <stdint.h>
#include <vector>
#include <atomic>

std::atomic<uint64_t> suma_total(0);
uint64_t suma_t = 0;

void func(const std::vector<uint16_t>& d, uint16_t star) {
	uint16_t end = d.size();
	for (uint16_t i = star; i < end; ++i) {
		suma_total += d[i];
	}
}

int main(void) {
	std::vector<uint16_t> datos;
	for (uint32_t i = 0; i < 10000; ++i) {
		datos.push_back(rand());
		suma_t += datos[i];
	}
	std::thread t1(func,datos, 0);
	std::cout << "thread id: " << t1.get_id() << std::endl;
	//std::thread t2(func, datos);
	std::cout << "esperando que termina thread 1\n";
	t1.join();
	std::cout << "la suma total is: " << suma_total << std::endl;
	std::cout << "la suma total is: " << suma_t << std::endl;
	return 0;
}