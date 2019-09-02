#include <iostream>

#include "AlgoParams.h"
#include "CrcHelper.h"
#include "CrcCalculator.h"
#include "tools.h"


int main () {
    //AlgoParams algo("CRC-32", 32, 0x04C11DB7L, 0xFFFFFFFFL, true, true, 0xFFFFFFFFL, 0xCBF43926L);
	AlgoParams algo("CRC-16/CCITT-FALSE", 16, 0x1021, 0xFFFF, false, false, 0x0, 0x29B1);
    CrcCalculator calculator(algo);

	std::vector<uint8_t> Bytes = {49,50,51,52,53,54,55,56,57};
	//uint8_t Bytes[] = {0xFC,0x06,0xC3,0x01}; //FC06C301
	long result = calculator.Calc(Bytes);


	intUnion iu;
    iu.i64[0] = result;
	std::vector<uint8_t> res(&iu.i8[0],&iu.i8[7]);
	std::reverse(res.begin(),res.end());
	std::cout<< result << " : " << HexToStr(res) << std::endl;

	return 0;
}
