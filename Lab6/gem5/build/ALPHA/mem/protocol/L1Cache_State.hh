/** \file L1Cache_State.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/src/mem/slicc/symbols/Type.py:442
 */

#ifndef __L1Cache_State_HH__
#define __L1Cache_State_HH__

#include <iostream>
#include <string>

#include "mem/protocol/AccessPermission.hh"

// Class definition
/** \enum L1Cache_State
 *  \brief Cache states
 */
enum L1Cache_State {
    L1Cache_State_FIRST,
    L1Cache_State_I = L1Cache_State_FIRST, /**< Not Present/Invalid */
    L1Cache_State_S, /**< Read Only */
    L1Cache_State_M, /**< Read and Write */
    L1Cache_State_IS_D, /**< Transient state from I to S waiting for data */
    L1Cache_State_IM_AD, /**< Transient state from I to M waiting for ACKs and data */
    L1Cache_State_IM_A, /**< Transient state from I to M waiting for ACKs */
    L1Cache_State_SM_AD, /**< Transient state from S to M waiting for ACKs and data */
    L1Cache_State_SM_A, /**< Transient state from S to M waiting for ACKs */
    L1Cache_State_MI_A, /**< Transient state from M to I waiting for ACKs */
    L1Cache_State_SI_A, /**< Transient state from S to I waiting for ACKs */
    L1Cache_State_II_A, /**< Transient state from S or M to I waiting for Put_Ack to complete transition to I */
    L1Cache_State_NUM
};

// Code to convert from a string to the enumeration
L1Cache_State string_to_L1Cache_State(const std::string& str);

// Code to convert state to a string
std::string L1Cache_State_to_string(const L1Cache_State& obj);

// Code to increment an enumeration type
L1Cache_State &operator++(L1Cache_State &e);

// Code to convert the current state to an access permission
AccessPermission L1Cache_State_to_permission(const L1Cache_State& obj);

std::ostream& operator<<(std::ostream& out, const L1Cache_State& obj);

#endif // __L1Cache_State_HH__
