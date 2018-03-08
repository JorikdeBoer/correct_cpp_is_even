#include <cassert>
#include <string>
#include <iostream>
#include <regex>

/// function to check if number is uneven
bool is_even(const std::string& str)
{
  return std::regex_match(str, std::regex("-?[[:digit:]]+(0|2|4|6|8)"));
}

/// function to check if input is number
bool is_number(const std::string& str)
{
  return std::regex_match(str, std::regex("-?[[:digit:]]+"));
}

/// is_even main function
int do_main(const std::vector<std::string>& args)
{
    /// Check if input is one number
    if (args.size() != 2)
    {
       std::cout << "No correct input, shame on you!\n";
       return 1;
    }

    /// Check if input is number
    const std::string input = args[1];
    bool is_outcome_number = is_number(input);
    if(!is_outcome_number)
    {
       std::cout << "Not a number, shame on you!\n";
       return 1;
    }

    ///Check if input is even
    bool is_even_number = is_even(input);
    if(is_even_number)
    {
       std::cout << "true\n";
       return 0;
    }

    /// Check uf input is uneven
    if(!is_even_number)
    {
       std::cout << "false\n";
       return 0;
    }
    return 0;
}

/// is_prime main function, that also tests its implementation
int main(int argc, char* argv[])
{
    assert(do_main( { "is_even" } ) == 1);
    assert(do_main( { "is_even", "4" } ) == 0);
    assert(do_main( { "is_even", "1" } ) == 0);
    assert(do_main( { "is_even", "12345678901234567891" } ) == 0);
    assert(do_main( { "is_even", "12345678901234567890" } ) == 0);
    assert(do_main( { "is_even", "nonsense" } ) == 1);
    assert(do_main( { "is_even", "7","42" } ) == 1);
    assert(do_main( { "is_even", "-4" } ) == 0);

    const std::vector<std::string> args (argv, argv + argc);
    return do_main(args);
}
