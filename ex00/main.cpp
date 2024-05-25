#include "ScalerConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try
        {
            if (av[1][0] == '\0')
            {
                throw ScalerConverter::nullValueException();
            }
            ScalerConverter::converter(av[1]);

        }
        catch(std::exception &e)
        {
            std::cout<< e.what() << std::endl;
        }
    }
    else
        std::cout<< "Only 2 arg need."<<std::endl;
}