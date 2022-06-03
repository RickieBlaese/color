#include "color.h"


namespace ssto {

	namespace color {

		std::string out(const color4b_t& color, bool is_fg) {
			return esc + std::to_string(is_fg ? color.fg : color.bg) + 'm';
		}

		std::string out(const color24b_t& color, bool is_fg) {
			return esc + std::string(is_fg ? "38;2;" : "48;2;") + std::to_string(color.r) + ';' + std::to_string(color.g) + ';' + std::to_string(color.b) + 'm';
		}

		void gradient(color24b_t color1, color24b_t color2, unsigned int count, std::vector<color24b_t>& outvec) {
			float c = count;
			float rc = (color2.r - color1.r) / c;
			float bc = (color2.b - color1.b) / c;
			float gc = (color2.g - color1.g) / c;
			for (int i = 0; i < count; i++)
				outvec.push_back(color24b_t{static_cast<unsigned short>(color1.r + rc * i), static_cast<unsigned short>(color1.g + gc * i), static_cast<unsigned short>(color1.b + bc * i)});
		}

		
		void generate_rainbow(unsigned int length, std::vector<color24b_t>& outvec) {
			unsigned int starting_vector_length = outvec.size();
			gradient(red24b, orange24b, length / 7.0f, outvec);
			gradient(orange24b, yellow24b, length / 7.0f, outvec);
			gradient(yellow24b, green24b, length / 7.0f, outvec);
			gradient(green24b, blue24b, length / 6.0f, outvec); // more weight to blue
			gradient(blue24b, indigo24b, length / 8.0f, outvec); // less weight to indigo
			gradient(indigo24b, violet24b, length / 7.0f, outvec);
			gradient(violet24b, red24b, length - (outvec.size() - starting_vector_length), outvec); // fill the rest with violet back to red
		}

	} // namespace color

} // namespace ssto
