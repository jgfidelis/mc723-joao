/**
 * @file      ac_tlm_mem.cpp
 * @author    Bruno de Carvalho Albertini
 *
 * @author    The ArchC Team
 *            http://www.archc.org/
 *
 *            Computer Systems Laboratory (LSC)
 *            IC-UNICAMP
 *            http://www.lsc.ic.unicamp.br/
 *
 * @version   0.1
 * @date      Sun, 02 Apr 2006 08:07:46 -0200
 *
 * @brief     Implements a ac_tlm memory.
 *
 * @attention Copyright (C) 2002-2005 --- The ArchC Team
 *
 *   This library is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU Lesser General Public
 *   License as published by the Free Software Foundation; either
 *   version 2.1 of the License, or (at your option) any later version.
 *
 *   This library is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *   Lesser General Public License for more details.
 *
 *
 */

//////////////////////////////////////////////////////////////////////////////
// Standard includes
// SystemC includes
// ArchC includes

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ac_tlm_peripheral.h"
#include <byteswap.h>

//////////////////////////////////////////////////////////////////////////////

/// Namespace to isolate peripheral from ArchC
using user::ac_tlm_peripheral;

/// Constructor
ac_tlm_peripheral::ac_tlm_peripheral( sc_module_name module_name , int k ) :
  sc_module( module_name ),
  target_export("iport")
{
    /// Binds target_export to the peripheral
    target_export( *this );
    valor = 0;
}

/// Destructor
ac_tlm_peripheral::~ac_tlm_peripheral() {
}

/** Internal Write
  * Note: Always write 32 bits
  * @param a is the address to write
  * @param d id the data being write
  * @returns A TLM response packet with SUCCESS
*/

ac_tlm_rsp_status ac_tlm_peripheral::writem( const uint32_t &a , const uint32_t &d )
{
//  cout << "addr: " <<  std::hex  << a << " data: " << d << endl;
  valor = d;
  return SUCCESS;
}

/** Internal Read
  * Note: Always read 32 bits
  * @param a is the address to read
  * @param d id the data that will be read
  * @returns A TLM response packet with SUCCESS and a modified d
*/
ac_tlm_rsp_status ac_tlm_peripheral::readm( const uint32_t &a , uint32_t &d )
{
  //d = 0;
  d = valor;
  valor = 1;
  return SUCCESS;
}


