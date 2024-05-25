#include "Base.hpp"

int main()
{
    try
    {
        Base* MALi = generate();

        identify(MALi);
        identify(*MALi);

        delete MALi;

    }
    catch(std::exception& e)
    {
        std::cout<< e.what()<< std::endl;
    }
}