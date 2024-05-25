#include "ScalerConverter.hpp"
#include <cstring>

ScalerConverter::ScalerConverter()
{
    std::cout<< ">> Default constructor called."<<std::endl;
}
ScalerConverter::~ScalerConverter()
{
    std::cout<< "<< Destructor called."<<std::endl;
}
ScalerConverter::ScalerConverter(const ScalerConverter& cpy)
{
    std::cout<< ">> Copy constructor called."<<std::endl;
    (void)cpy;
}
ScalerConverter& ScalerConverter::operator= (const ScalerConverter& value)
{
    std::cout<< ">> Copy assignment operator called."<<std::endl;
    (void)value;
    return *this;
}

const char* ScalerConverter::nullValueException::what() const throw()
{
    return ("There is no acceptable value.");
}

void ScalerConverter::converter(const std::string& value)
{
    int control_value = controller(value);
    switch (control_value)
    {
        case 1: char_to_other(value); break;
        case 2: int_to_other(value); break;
        case 3: float_to_other(value); break;
        case 4: double_to_other(value); break;
        case 5: print_infinity(value); break;
        default: 
            std::cout<<"It's invalid arg. Please enter valid value!" <<std::endl; break;
    }
};

int ScalerConverter::controller(const std::string& value)
{
    if (value.find('f') != std::string::npos && value[1] != '\0')
    {
        if (float_control(value) == true)
            return (3);
    }
    if (char_control(value) == true)
        return (1);
    if (int_control(value) == true)
        return (2);
    if (double_control(value) == true)
        return (4);
    if (infinity_control(value) == true)
        return (5);
    return(0);

}

bool ScalerConverter::char_control(const std::string& value)
{
    if (value.length() == 1 && std::isprint(value[0]))
        return true;
    return false;
}
bool ScalerConverter::int_control(const std::string& value)
{
    if (!(value[0] == '-' || std::isdigit(value[0])))
        return false;

    char* last_string_locationPTR;
    long int int_value = strtol(value.c_str(), &last_string_locationPTR, 10);
    if (value[0] == '-')
    {
        for (size_t i = 1; i < value.length(); i++)
        {
            if (!std::isdigit(value[i]))
                return false;
        }
    }
    if (std::isdigit(value[0]))
    {
        for (size_t i = 0; i < value.length(); i++)
        {
            if (!std::isdigit(value[i]))
                return false;
        }
    }
    if ((int_value == LONG_MIN || int_value == LONG_MAX) && (errno == ERANGE))
        return false;

    if (value.length() > 11 || value.length() < 0)
        return false;

    if (int_value < INT_MIN || int_value > INT_MAX)
        return false;
    return true;
}

bool ScalerConverter::float_multiplechars(const std::string& value)
{
    return (value.find_first_of('.') != value.find_last_of('.')
            || value.find_first_of('f') != value.find_last_of('f'));
}

bool ScalerConverter::float_control(const std::string& value)
{
    errno = 0;
    char* last_string_locationPTR;
    double float_value = strtod(value.c_str(), &last_string_locationPTR);

    if ( (errno == ERANGE || last_string_locationPTR == value.c_str()))
        return false;
    if ((float_value == HUGE_VAL || float_value == -HUGE_VAL) && errno == ERANGE)
        return false;
    if (float_multiplechars(value))
        return false;
    if (value.length() > 10 || value.length() < 0)
        return false;
    if (float_value < -FLT_MAX || float_value > FLT_MAX)
        return false;
    return (value.find_first_not_of("-+0123456789.f") == std::string::npos);
}

bool ScalerConverter::double_control(const std::string& value)
{
    errno = 0;
    char* last_string_locationPTR;
    double float_value = strtod(value.c_str(), &last_string_locationPTR);


    if (errno == ERANGE || last_string_locationPTR == value.c_str())
        return false;
    if ((float_value == HUGE_VAL || float_value == -HUGE_VAL) && errno == ERANGE)
        return false;
    if (value.find_first_of('.') != value.find_last_of('.'))
        return false;
    if (value.length() > 20 || value.length() <= 0)
        return false;
    if (float_value < -DBL_MAX || float_value > DBL_MAX)
        return false;
    if (value.find_first_not_of("-+0123456789.") != std::string::npos)
        return false;
    return true;
}

bool ScalerConverter::infinity_control(const std::string& value)
{
    if (inf_and_nan(value))
        return true;
    return false;
}


bool ScalerConverter::inf_and_nan(const std::string& value)
{
    return (value == "-inff" || value  == "-inf" || value  == "+inff" || value  == "+inf" || value  == "nan" || value  == "nanf" || value == "inf");
}

void ScalerConverter::char_to_other(const std::string& value)
{
    
    char c_char = static_cast<char>(value[0]);
    int i_int = static_cast<int>(c_char);
    float f_float = static_cast<float>(c_char);
    double d_double = static_cast<double>(c_char);
    if (c_char >= '0' && c_char <= '9')
    {
        i_int = c_char - '0'; 
        f_float = static_cast<float>(i_int);
        d_double = static_cast<double>(i_int);
    }
    else
    {
        i_int = static_cast<int>(c_char);
        f_float = static_cast<float>(c_char);
        d_double = static_cast<double>(c_char);
    }
    print_char(c_char, i_int);
    print_int(i_int);
    print_float(f_float);
    print_double(d_double);
}
void ScalerConverter::int_to_other(const std::string& value)
{
    int i_int = atoi(value.c_str());
    char c_char = static_cast<unsigned char>(i_int);
    float f_float = static_cast<float>(i_int);
    double d_double = static_cast<double>(i_int);
    print_char(c_char, i_int);
    print_int(i_int);
    print_float(f_float);
    print_double(d_double);
}
void ScalerConverter::float_to_other(const std::string& value)
{
    float f_float = atof(value.c_str());
    char c_char = static_cast<unsigned char>(f_float);
    int i_int = static_cast<int>(f_float);
    double d_double= static_cast<double>(f_float);
    print_char(c_char, i_int);
    print_int(i_int);
    print_float(f_float);
    print_double(d_double);

}
void ScalerConverter::double_to_other(const std::string& value)
{
    double d_double = atof(value.c_str());
    char c_char = static_cast<unsigned char>(d_double);
    int i_int = static_cast<int>(d_double);
    float f_float = static_cast<float>(d_double);
    print_char(c_char, i_int);
    print_int(i_int);
    print_float(f_float);
    print_double(d_double);
}
void ScalerConverter::print_infinity(const std::string& value)
{
    if (value == "inf")
    {
        std::cout<< "char : impossible" << std::endl;
        std::cout<< "int : impossible" << std::endl;
        std::cout<< "float : +inff" << std::endl;
        std::cout<< "double : +inf" << std::endl;
    }
    else if (value == "+inf")
    {
        std::cout<< "char : impossible" << std::endl;
        std::cout<< "int : impossible" << std::endl;
        std::cout<< "float : +inff" << std::endl;
        std::cout<< "double : +inf" << std::endl;
    }
    else if (value == "+inff")
    {
        std::cout<< "char : impossible" << std::endl;
        std::cout<< "int : impossible" << std::endl;
        std::cout<< "float : +inff" << std::endl;
        std::cout<< "double : +inf" << std::endl;
    }
    else if (value == "-inf")
    {
        std::cout<< "char : impossible" << std::endl;
        std::cout<< "int : impossible" << std::endl;
        std::cout<< "float : -inff" << std::endl;
        std::cout<< "double : -inf" << std::endl;
    }
    else if (value == "-inff")
    {
        std::cout<< "char : impossible" << std::endl;
        std::cout<< "int : impossible" << std::endl;
        std::cout<< "float : -inff" << std::endl;
        std::cout<< "double : -inf" << std::endl;
    }
    else if (value == "nan")
    {
        std::cout<< "char : impossible" << std::endl;
        std::cout<< "int : impossible" << std::endl;
        std::cout<< "float : nanf" << std::endl;
        std::cout<< "double : nan" << std::endl;
    }
    else if (value == "nanf")
    {
        std::cout<< "char : impossible" << std::endl;
        std::cout<< "int : impossible" << std::endl;
        std::cout<< "float : nanf" << std::endl;
        std::cout<< "double : nan" << std::endl;
    }
}


void ScalerConverter::print_char(char c_char, int i_int)
{
    if (i_int < 0 || i_int > 255)
        std::cout << "char : impossible" << std::endl;
    else if (isprint(c_char) && c_char != '0')
        std::cout << "char : " << c_char << std::endl;
    else
        std::cout << "char : Non displayable" << std::endl;
}

void ScalerConverter::print_int(int i_int)
{
    if (i_int > INT_MAX || i_int < INT_MIN)
        std::cout << "int : impossible" << std::endl;
    else
        std::cout << "int : " << i_int << std::endl;
}

void ScalerConverter::print_float(float f_float)
{
    if (f_float > FLT_MAX || f_float < -FLT_MAX)
        std::cout << "float : impossible"<< std::endl;
    else
        std::cout << "float : " << std::fixed << std::setprecision(1) << f_float << "f"<< std::endl;
}
void ScalerConverter::print_double(double d_double)
{
    if (d_double > DBL_MAX || d_double < -DBL_MAX)
        std::cout << "double : impossible"<< std::endl;
    else
        std::cout << "double : " << std::fixed << std::setprecision(1) << d_double << std::endl;
}