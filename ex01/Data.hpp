#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <cstdint>

struct Data
{
    Data();
    ~Data();
    Data(uintptr_t _Raw);
    Data(const Data& cpy);
    Data& operator= (const Data& value);

    void setRaw(uintptr_t setV);
    uintptr_t getRaw() const;
    private:
        uintptr_t Raw;
};

#endif