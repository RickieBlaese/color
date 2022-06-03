#include "color.h"

#include <iostream>
#include <random>
#include <string>

unsigned short randrgb() {
	static std::random_device rd;
	static std::default_random_engine rng(rd());
	static std::uniform_int_distribution<std::default_random_engine::result_type> distrgb(0, 255);
	return distrgb(rng);
}


int main() {
	std::string text;
	double outs;
	std::cout << "text: ";
	std::getline(std::cin, text);
	outs = text.size();

	std::vector<ssto::color::color24b_t> rainbow;
	ssto::color::generate_rainbow(outs, rainbow);

	for (int i = 0; i < outs; i++) {
		std::cout << ssto::color::out(rainbow[i], true) << text[i];
	}
	std::cout << ssto::color::reset << '\n';
	return 0;
}
