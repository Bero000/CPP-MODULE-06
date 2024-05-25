#include "Base.hpp"

Base::~Base(){}

Base* generate(void)
{
	std::srand(std::time(nullptr));
    int a = std::rand() % 3;

    if (a == 0)
        return (new A());
    else if (a == 1)
        return (new B());
    return (new C());
}
void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
    {
        std::cout<< "It's class A!"<<std::endl;
        return ;
    }
    else if (dynamic_cast<B*>(p) != NULL)
    {
        std::cout<< "It's class B!"<<std::endl;
        return ;
    }
    else if (dynamic_cast<C*>(p) != NULL)
    {
        std::cout<< "It's class C!"<<std::endl;
        return ;
    }
    std::cout << "It's nothing mate:(("<< std::endl;
}
void identify(Base& p)
{
    try
    {
        A& AA = dynamic_cast<A&>(p);
        (void)AA;
        std::cout<< "It's class A!"<<std::endl;
        return ;
    }
    catch(...){ }
    try
    {
        B& BB = dynamic_cast<B&>(p);
        (void)BB;
        std::cout<< "It's class B!"<<std::endl;
        return ;
    }
    catch(...){ }
    try
    {
        C& CC = dynamic_cast<C&>(p);
        (void)CC;
        std::cout<< "It's class C!"<<std::endl;
        return ;
    }
    catch(...){ }
    std::cout << "It's nothing mate:(("<< std::endl;
}