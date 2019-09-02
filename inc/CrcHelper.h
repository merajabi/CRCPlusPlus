//package com.crccalc;
#ifndef _CrcHelper_H_
#define _CrcHelper_H_

/**
 * Created by anthony on 13.05.2017.
 */
class CrcHelper {
	public:
    static long ReverseBits(long ul, int valueLength)
    {
        long newValue = 0;

        for (int i = valueLength - 1; i >= 0; i--)
        {
            newValue |= (ul & 1) << i;
            ul >>= 1;
        }

        return newValue;
    }
};

#endif //_CrcHelper_H_
