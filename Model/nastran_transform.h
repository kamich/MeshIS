#ifndef NASTRAN_TRANSFORM_H_
#define NASTRAN_TRANSFORM_H_

#include <algorithm>
#include <array>
#include <string>
#include <locale>

using std::array;
using std::transform;
using std::begin;
using std::end;
using std::string;

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
	
	inline void erase_all_spaces(string & field) {
        field.erase(remove_if(field.begin(), field.end(), [](char ch) {
            return std::isspace<char>(ch, std::locale::classic());
        }), field.end());
    }
}

#endif // !NASTRAN_TRANSFORM_H_