#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

union intUnion {
	uint8_t i8[8];
	uint16_t i16[4];
	uint32_t i32[2];
	uint64_t i64[1];
};

std::string HexToStr( const std::vector<uint8_t>& in) {
	std::stringstream str;
	for(size_t i=0;i<in.size();i++)	{
		str << std::hex << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(in[i]);
	}
	return str.str();
}
std::string HexToStr( const uint8_t* in, int len) {
    std::stringstream str;
    for(size_t i=0;i<len;i++)	{
        str << std::hex << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(in[i]);
    }
    return str.str();
}


