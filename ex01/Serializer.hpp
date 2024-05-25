#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"
#include <stdexcept>
#include <iostream>

class Serializer
{
    public:
        Serializer();
        ~Serializer();
        Serializer(const Serializer& cpy);
        Serializer& operator= (const Serializer& value);


        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};


#endif