#ifndef MYSPACE_H
#define MYSPACE_H
#include <iostream>
#include <sstream>
#include <bitset>
#include <stdint.h>
#include <limits>
#include <cmath>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;

/** \mainpage
 *
 * \section intro_sec Lab4
 *
 * - \subpage mySpace
 * This is the functions page.
 *
 */

/** \namespace mySpace
 * Full pack of used functions.
*/

namespace mySpace {

const int bytesize = 8; /**< Size of byte */

/*! \brief print numbers and strings as strings.
 *  \tparam line Line to print.
*/
template<typename T>
void printString(T line)
{
    std::ostringstream ss;
    ss << line;
    cout << ss.str();
}

/*! \brief prints bytes, starts from highest.
 *  @param[out] res  	  Where dotten bit string will be placed.
 *  @param[in]  size 	  Bitset string size.
 *  @param[in]  bitString The string representation of bitset
*/
void dotted(const string &bitString, int size, string &res)
{
    size -= bytesize;

    if (size <= 0) {
        const int sz = bytesize + size;
        printString(bitset<bytesize> { bitString.substr(0, sz) }.to_ulong());
        return;
    }

    dotted(bitString, size, res);

    cout << ".";
    printString(bitset<bytesize> { bitString.substr(size, bytesize) }.to_ulong());
}

/*! \brief prints bytes from list or vector, starts from highest.
 *  @tparam container Container to print. Place dot after each cell.
*/
template<template<typename, typename> typename Container, typename Type, typename Allocator = allocator<Type>,
     typename = enable_if_t<is_same_v<Container<Type, Allocator>,
                      vector<Type, Allocator>> || is_same_v<Container<Type, Allocator>, list<Type, Allocator>>>>
void printIP(const Container<Type, Allocator> &container)
{
    for (auto it = container.cbegin(), end = container.cend(), lastItem = prev(container.cend()); it != end; ++it) {
        printString(*it);
        cout << ((it == lastItem) ? "\n" : ".");
    }
}

/*!  \brief prints basic_string.
 *  @tparam s String to print. Prints as is.
*/
template<template<typename, typename, typename> typename bString, typename CharT,
     typename Traits = std::char_traits<CharT>, typename Allocator = std::allocator<CharT>,
     typename = enable_if_t<is_same_v<bString<CharT, Traits, Allocator>, basic_string<CharT, Traits, Allocator>>>>
void printIP(const bString<CharT, Traits, Allocator> &s)
{
    printString(s);
    cout << endl;
}

/*!  \brief prints bytes, starts from highest.
 *  @tparam num Number to print. Convers number to bitset and print.
*/
template<typename Type, typename = enable_if_t<is_integral_v<Type> && !is_same_v<bool, Type>>>
void printIP(const Type &num)
{
    bitset<numeric_limits<Type>::digits + 1> b(num);
    const string bitString(b.to_string());
    string res;
    dotted(bitString, bitString.size(), res);
    printString(res);
    cout << endl;

//    auto bytes = reinterpret_cast<const unsigned char*>(&num);
//    auto end = bytes + sizeof(Type);
//    copy(
//        make_reverse_iterator(end),
//        make_reverse_iterator(bytes + 1),
//        ostream_iterator<unsigned>(std::cout, ".")
//    );
//    std::cout << unsigned(*bytes) << std::endl;
}

} // namespace mySpace

#endif // MYSPACE_H
