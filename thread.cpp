#include <iostream>
#include <vector>
#include <stdint.h>
#include <thread>
#include <Windows.h>
#include <atomic>

//static uint64_t suma_t = 0;
std::atomic<uint64_t> suma_t(0);

void suma(const uint16_t x[5]) {
	for (uint16_t i = 0; i < 5; ++i) {
		suma_t += x[i];
	}
}

void func(uint16_t x[5]) {
	Sleep(5000);
	for (uint16_t i = 0; i < 5; ++i) {
		x[i] = rand();
	}
}

int main(void) {
	uint16_t edades[5];
	std::thread t1(func, edades);
	std::thread t2(suma, edades);
	std::cout << "esperando que termine thread\n";
	std::cout << "esperando que termine thread 2\n";
	t1.join();
	t2.join();
	uint16_t d = 0;
	for (uint16_t i : edades) {
		Sleep(1000);
		d += 1;
		std::cout << "data[" << d <<"] " << i << std::endl;
	}
	std::cout << "la suma total fue: " << suma_t << std::endl;
	return 0;
}