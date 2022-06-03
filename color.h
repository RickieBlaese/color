#ifndef SSTO_COLOR_H_
#define SSTO_COLOR_H_

#include <stdint.h>

#include <string>
#include <vector>


namespace ssto {
	
	// WARNING: the bit-ness of each color_t is not indicative of their actual size
	namespace color {

		// useful constants
		static std::string esc = "\033[";
		static std::string reset = esc + "0m";


		// 4-bit colors
		struct color4b_t {
			unsigned short fg, bg;
		};

		// TODO: 8-bit shit (annoying because color cube)
		
		// RGB (24-bit)
		struct color24b_t {
			unsigned short r, g, b;
		};


		// color constants
		static constexpr color4b_t black4b{30, 40}, red4b{31, 41}, green4b{32, 42}, yellow4b{33, 43},
				 blue4b{34, 44}, magenta4b{35, 45}, cyan4b{36, 46}, white4b{37, 47};
		static constexpr color4b_t /* gray */ bright_black4b{90, 100}, bright_red4b{91, 101}, bright_green4b{92, 102}, bright_yellow4b{93, 103},
				 bright_blue4b{94, 104}, bright_magenta4b{95, 105}, bright_cyan4b{96, 106}, bright_white4b{97, 107};

		static constexpr color24b_t violet24b{148, 0, 211}, indigo24b{75, 0, 130}, blue24b{0, 0, 255}, 
				 green24b{0, 255, 0}, yellow24b{255, 255, 0}, orange24b{255, 127, 0}, red24b{255, 0, 0};

		
		// functions
		std::string out(const color4b_t& color, bool is_fg);
		
		std::string out(const color24b_t& color, bool is_fg);

		void gradient(color24b_t color1, color24b_t color2, unsigned int count, std::vector<color24b_t>& outvec);
		
		// generates a ROYGBIV rainbow across specified length
		void generate_rainbow(unsigned int length, std::vector<ssto::color::color24b_t>& outvec);

	} // namespace color

} // namespace ssto

#endif
