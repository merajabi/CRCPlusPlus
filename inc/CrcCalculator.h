//package com.crccalc;
#ifndef _CrcCalculator_H_
#define _CrcCalculator_H_
#include <iostream>
#include <vector>
#include <cstdlib>
/**
 * Created by anthony on 11.05.2017.
 */
class CrcCalculator {
    uint64_t _mask = 0xFFFFFFFFFFFFFFFFL;
    std::vector<long> _table;
    AlgoParams Parameters;
    uint8_t HashSize;

	public:
    CrcCalculator(const AlgoParams& params):Parameters(params),HashSize(8) {
		_table.resize(256);
        HashSize = (uint8_t) Parameters.HashSize;
        if (HashSize < 64)
        {
            _mask = (1L << HashSize) - 1;
        }
        CreateTable();
    }

    long Calc(const std::vector<uint8_t>& data, int offset=0, size_t length=0)
    {
		length = (length<=0)?data.size():length;
        long init = (Parameters.RefOut) ? CrcHelper::ReverseBits(Parameters.Init, HashSize) : Parameters.Init;
        long hash = ComputeCrc(init, data, offset, length);
        return (hash ^ Parameters.XorOut) & _mask;
    }

	private:

    long ComputeCrc(long init, const std::vector<uint8_t>& data, int offset, size_t length) {
        long crc = init;

        if (Parameters.RefOut)
        {
            for (int i = offset; i < offset + length; i++)
            {
				long absCRC = labs(crc);
                crc = (_table[(int)((crc ^ data[i]) & 0xFF)] ^ (absCRC >> 8)); // crc = (_table[(int)((crc ^ data[i]) & 0xFF)] ^ (absCRC >>> 8));
                crc &= _mask;
            }
        }
        else
        {
            int toRight = (HashSize - 8);
            toRight = toRight < 0 ? 0 : toRight;
            for (int i = offset; i < offset + length; i++)
            {
                crc = (_table[(int)(((crc >> toRight) ^ data[i]) & 0xFF)] ^ (crc << 8));
                crc &= _mask;
            }
        }

        return crc;
    }

    void CreateTable()
    {
        for (int i = 0; i < _table.size(); i++){
            _table[i] = CreateTableEntry(i);
		}
    }

    long CreateTableEntry(int index)
    {
        long r = (long)index;
        if (Parameters.RefIn) {
            r = CrcHelper::ReverseBits(r, HashSize);
        } else if (HashSize > 8) {
            r <<= (HashSize - 8);
		}
        long lastBit = (1L << (HashSize - 1));

        for (int i = 0; i < 8; i++)
        {
            if ((r & lastBit) != 0) {
                r = ((r << 1) ^ Parameters.Poly);
            } else {
                r <<= 1;
			}
        }
        if (Parameters.RefOut) {
            r = CrcHelper::ReverseBits(r, HashSize);
		}
        return r & _mask;
    }

};

#endif //_CrcCalculator_H_

