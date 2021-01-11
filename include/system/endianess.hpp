

//********************************************************************
// endianess.hpp gives few fonctions to handle endianess in C++
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
*\file endianess.hpp
*\author Quentin Putaud
*\version 1.1
*\date 16/12/2020
*/

#ifndef ENDIANESS_HPP_INCLUDED
#define ENDIANESS_HPP_INCLUDED

/*!
*\namespace qplib Namespace of my personal lib
*/
namespace qplib
{

/*!
*\enum Endianess
*\brief An enum class to handle the types of endianess.
*Possible values are Endianess::LittleEndian of Endianess::BigEndian.
*/
enum class Endianess {LittleEndian,BigEndian};

/*!
*\brief Find and return the endianess of the computer.
*\return Endianess : the endianess of the computer.
*/
Endianess getComputerEndianess(void);

/*!
*\brief Change variable var to the opposit endianess.
*\param[in] var T : input variable.
*\return T : the variable var in the opposit endianess.
*/
template<typename T>
T changeEndianess(T var);

} // end namespace

#include "endianess.cpp"

#endif // ENDIANESS_HPP_INCLUDED
