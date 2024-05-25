#include "Data.hpp"

Data::Data():Raw(0){}
Data::~Data(){}

Data::Data(uintptr_t _Raw)
{
    setRaw(_Raw);
}
Data::Data(const Data& cpy)
{
    *this = cpy;
}
Data& Data::operator= (const Data& value)
{
    if (this != &value)
    {
        this->Raw = value.getRaw();
    }
    return *this;
}

void Data::setRaw(uintptr_t setV)
{
    this->Raw = setV;
}
uintptr_t Data::getRaw() const
{
    return this->Raw;
}