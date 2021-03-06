

//********************************************************************
// mnist_reader.cpp implement the class defined in mnist_reader.hpp
// Copyright (C) 2020 Quentin Putaud
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see http://www.gnu.org/licenses
//********************************************************************


/*!
*\file endianess.cpp
*\author Quentin Putaud
*\version 1.1
*\date 16/12/2020
*/

namespace qplib
{

Endianess getComputerEndianess(void)
{
    //create the short 11110000 in little endian and the short 00001111 in big endian
    union {unsigned short _full; char _bytes[2];} endianessTest={0x00FF};
    //if first byte nul then it s big endian
    if(endianessTest._bytes[0]==0)
        return Endianess::BigEndian;
    // else it s little endian
    return Endianess::LittleEndian;
}

template<typename T>
T changeEndianess(T var)
{
    //cp the var to an union to cut it into bytes
    union {T _full; char _bytes[sizeof(T)];} uvar={var};
    char temp;
    //do the inversion
    for(size_t i=0 ; i<sizeof(T)/2 ; ++i)
    {
        temp=uvar._bytes[sizeof(T)-1-i];
        uvar._bytes[sizeof(T)-1-i]=uvar._bytes[i];
        uvar._bytes[i]=temp;
    }
    return uvar._full;
}

} // end namespace
