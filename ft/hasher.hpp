#ifndef FT_HASHER_HPP
#define FT_HASHER_HPP

#include<string>
#include<ft/object.hpp>
namespace ft{

    enum class HashType {murmur};

    size_t hashf(HashType name,object const& o, size_t seed){
        return 100;
    }

} //name space ft

#endif