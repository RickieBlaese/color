#include "color.h"

#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <algorithm>
#include <unistd.h>

unsigned short randrgb() {
	static std::random_device rd;
	static std::default_random_engine rng(rd());
	static std::uniform_int_distribution<std::default_random_engine::result_type> distrgb(0, 255);
	return distrgb(rng);
}


int main() {
	std::ios_base::sync_with_stdio(false);
	std::string text;
	double outs;
	std::cout << "text: ";
	std::getline(std::cin, text);
	outs = text.size();
	std::vector<char> vbacks = std::vector<char>(outs, '\b');
	std::string backs = std::string(vbacks.data());

	std::vector<ssto::color::color24b_t> rainbow;
	ssto::color::generate_rainbow(outs, rainbow);

	// buffered for cleaner output
	std::stringstream buf;
	while (true) {
		buf.clear();
		buf << backs;
		std::rotate(rainbow.begin(), rainbow.end() - 1, rainbow.end()); // shift for effect
		for (int i = 0; i < outs; i++) {
			buf << ssto::color::out(rainbow[i], true) << text[i];
		}
		std::cout << buf.rdbuf();
		usleep(20000.0f);
	}
	std::cout << ssto::color::reset << '\n';
	return 0;
}
