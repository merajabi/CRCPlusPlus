//package com.crccalc;
#ifndef _AlgoParams_H_
#define _AlgoParams_H_

/**
 * Created by anthony on 11.05.2017.
 */
    class AlgoParams
    {

    public:
	AlgoParams(std::string name, int hashSize, long poly, long init, bool refIn, bool refOut, long xorOut, long check)
    {
        Name = name;
        Check = check;
        Init = init;
        Poly = poly;
        RefIn = refIn;
        RefOut = refOut;
        XorOut = xorOut;
        HashSize = hashSize;
    }

    /// <summary>
    /// This field is not strictly part of the definition, and, in
    /// the event of an inconsistency between this field and the other
    /// field, the other fields take precedence.This field is a check
    /// value that can be used as a weak validator of implementations of
    /// the algorithm.The field contains the checksum obtained when the
    /// ASCII string "123456789" is fed through the specified algorithm
    /// (i.e. 313233... (hexadecimal)).
    /// </summary>
    long Check;

    /// <summary>
    /// This is hash size.
    /// </summary>
    int HashSize;

    /// <summary>
    /// This parameter specifies the initial value of the register
    /// when the algorithm starts.This is the value that is to be assigned
    /// to the register in the direct table algorithm. In the table
    /// algorithm, we may think of the register always commencing with the
    /// value zero, and this value being XORed into the register after the
    /// N'th bit iteration. This parameter should be specified as a
    /// hexadecimal number.
    /// </summary>
    long Init;

    /// <summary>
    /// This is a name given to the algorithm. A string value.
    /// </summary>
    std::string Name;

    /// <summary>
    /// This parameter is the poly. This is a binary value that
    /// should be specified as a hexadecimal number.The top bit of the
    /// poly should be omitted.For example, if the poly is 10110, you
    /// should specify 06. An important aspect of this parameter is that it
    /// represents the unreflected poly; the bottom bit of this parameter
    /// is always the LSB of the divisor during the division regardless of
    /// whether the algorithm being modelled is reflected.
    /// </summary>
    long Poly;

    /// <summary>
    /// This is a boolean parameter. If it is FALSE, input bytes are
    /// processed with bit 7 being treated as the most significant bit
    /// (MSB) and bit 0 being treated as the least significant bit.If this
    /// parameter is FALSE, each byte is reflected before being processed.
    /// </summary>
    bool RefIn;

    /// <summary>
    /// This is a boolean parameter. If it is set to FALSE, the
    /// final value in the register is fed into the XOROUT stage directly,
    /// otherwise, if this parameter is TRUE, the final register value is
    /// reflected first.
    /// </summary>
    bool RefOut;

    /// <summary>
    /// This is an W-bit value that should be specified as a
    /// hexadecimal number.It is XORed to the final register value (after
    /// the REFOUT) stage before the value is returned as the official
    /// checksum.
    /// </summary>
    long XorOut;
};

#endif //_AlgoParams_H_

