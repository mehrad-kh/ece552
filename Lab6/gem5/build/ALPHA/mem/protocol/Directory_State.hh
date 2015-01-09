/** \file Directory_State.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/src/mem/slicc/symbols/Type.py:442
 */

#ifndef __Directory_State_HH__
#define __Directory_State_HH__

#include <iostream>
#include <string>

#include "mem/protocol/AccessPermission.hh"

// Class definition
/** \enum Directory_State
 *  \brief Directory states
 */
enum Directory_State {
    Directory_State_FIRST,
    Directory_State_I = Directory_State_FIRST, /**< Not Present/Invalid */
    Directory_State_M, /**< Modified */
    Directory_State_S, /**< Shared */
    Directory_State_IS_MEM, /**< I to S, wainting for memory to get the data */
    Directory_State_IM_MEM, /**< I to M, wainting for memory to get the data */
    Directory_State_MS_D, /**< M to S, waiting to get the latest data from the previous owner */
    Directory_State_MI_MEM, /**< M to I, waiting to write the latest data to memory */
    Directory_State_MS_MEM, /**< M to S, waiting to write the latest data to memory */
    Directory_State_MS_MEMD, /**< M to I, waiting to receive data from owner and memory ack */
    Directory_State_NUM
};

// Code to convert from a string to the enumeration
Directory_State string_to_Directory_State(const std::string& str);

// Code to convert state to a string
std::string Directory_State_to_string(const Directory_State& obj);

// Code to increment an enumeration type
Directory_State &operator++(Directory_State &e);

// Code to convert the current state to an access permission
AccessPermission Directory_State_to_permission(const Directory_State& obj);

std::ostream& operator<<(std::ostream& out, const Directory_State& obj);

#endif // __Directory_State_HH__
