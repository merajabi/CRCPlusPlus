# CRCPlusPlus
This is header only library ported from java language to C++ 
the credit goes to original author Anton Isakov (https://github.com/meetanthony/crcjava)

## Sample Code
Choose any Algorithm from Crc8, Crc16, Crc32 or Crc64 in test folder

```cpp
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

		std::cout<< std::hex << result << ((result==algo.Check)?" Ok":" Not Ok!") <<std::endl;
	}
}
```
## compile & test
compile and run as follow

```sh
# g++ -Iinc test/test.cpp
# ./a.out
```
