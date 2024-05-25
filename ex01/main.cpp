#include "Serializer.hpp"

int main()
{
    Data *ptr = 0;
    Data *ptr2 = 0;

    uintptr_t raw_value = 0;

    try
    {
        ptr = new Data(33);
        raw_value = Serializer::serialize(ptr);
        ptr2 = Serializer::deserialize(raw_value);

        std::cout << ptr->getRaw() << std::endl;
        std::cout << raw_value << std::endl;
        std::cout << ptr2->getRaw() << std::endl;
        std::cout << Serializer::serialize(ptr2) << std::endl;
        delete ptr;
    }
    catch(std::exception& e)
    {
        std::cout<< e.what() << std::endl;
    }
}