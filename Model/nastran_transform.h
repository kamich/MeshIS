#pragma
#ifndef NASTRAN_TRANSFORM_H_
#define NASTRAN_TRANSFORM_H_
#include <algorithm>
#include <array>

using std::array;
using std::transform;
using std::begin;
using std::end;

namespace chrom 
{
    template<class T>
    T decrement(T x) {
        return --x;
    }

    template<class T, size_t size>
    void decrement_values(array<T, size> & arr) {
        transform(begin(arr), end(arr), begin(arr), &chrom::decrement<T>);
    }
}

#endif // !NASTRAN_TRANSFORM_H_