#ifndef SCALERCONVERTER_HPP
# define SCALERCONVERTER_HPP

#include <iostream>
#include <string>
#include <cfloat>
#include <cmath>
#include <limits>
# include <iomanip>

class ScalerConverter
{
    public:
        ScalerConverter();
        ~ScalerConverter();
        ScalerConverter(const ScalerConverter& cpy);
        ScalerConverter& operator= (const ScalerConverter& value);

        class nullValueException:public std::exception
        {
            const char* what() const throw();
        };

        static void converter(const std::string& value);
        static int controller(const std::string& value);

        static bool char_control(const std::string& value);
        static bool int_control(const std::string& value);
        static bool float_control(const std::string& value);
            static bool float_multiplechars(const std::string& value);
        static bool double_control(const std::string& value);
        static bool infinity_control(const std::string& value);
            static bool inf_and_nan(const std::string& value);

        static void char_to_other(const std::string& value);
        static void int_to_other(const std::string& value);
        static void float_to_other(const std::string& value);
        static void double_to_other(const std::string& value);
        static void print_infinity(const std::string& value);

        static void print_char(char c_char, int i_int);
        static void print_int(int i_int);
        static void print_float(float f_float);
        static void print_double(double d_double);
};

#endif