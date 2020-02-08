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

std::vector<uint8_t> StrToHex( const std::string& in) {
	std::vector<uint8_t> hex;
	std::string val=(in.size()%2==0)?in:std::string("0")+in;

	for(size_t i=0; i < val.length(); i+=2){
		int num;
		std::stringstream(val.substr(i,2)) >> std::hex >> num;
		hex.push_back(static_cast<uint8_t>(num));
	}
	return hex;
}

