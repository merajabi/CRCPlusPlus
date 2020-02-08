#include <iostream>

#include "AlgoParams.h"
#include "CrcHelper.h"
#include "CrcCalculator.h"
#include "tools.h"


int main () {
	// Choose any Algorithm from Crc8, Crc16, Crc32 or Crc64 in test folder
	{
		AlgoParams algo("CRC-16/CCITT-FALSE", 16, 0x1021, 0xFFFF, false, false, 0x0, 0x29B1);
		CrcCalculator calculator(algo);

		std::vector<uint8_t> bytes = {49,50,51,52,53,54,55,56,57};
		long result = calculator.Calc(bytes);
		std::stringstream ss;
		ss << std::hex << result;
		std::cout<< ss.str() << ((result==algo.Check)?" Ok":" Not Ok!") <<std::endl;
	}
	{
		AlgoParams algo("CRC-64",64, 0x42F0E1EBA9EA3693L, 0x00000000L, false, false, 0x00000000L, 0x6C40DF5F0B497347L);
		CrcCalculator calculator(algo);

		std::vector<uint8_t> bytes = {49,50,51,52,53,54,55,56,57};
		long result = calculator.Calc(bytes);

		std::cout<< std::hex << result << ((result==algo.Check)?" Ok":" Not Ok!") <<std::endl;
	}
	return 0;
}
