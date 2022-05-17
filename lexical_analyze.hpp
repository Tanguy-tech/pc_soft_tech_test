#ifndef LEXICAL_ANALYZE_HPP
#define LEXICAL_ANALYZE_HPP

#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define DEFAULT "\033[0m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define PINK    "\033[35m"
#define WHITE   "\033[36m"

#define SENTENCE_LENGTH_ERROR "ERROR: The sentence must contains between 0 to 1000 words!"
#define WORD_LENGTH_ERROR "ERROR: Words must contains between 1 to 50 characters!"
#define WRONG_MENU_CHOISE "ERROR: Please choose option 1, 2 or 3 only!"

#define MENU_HEADER "\n\nChoose option 1,2 or 3:\n"
#define MENU_1  "1 - Reverse sentence\n"
#define MENU_2  "2 - Display number of occurences in sentece\n"
#define MENU_3  "3 - Display number of occurences in sentence, sorted by number\n"
#define MENU_4  "4 - QUIT\n"

class Sentence
{
    public:
        Sentence() {}                               /* Default constructor */
        ~Sentence();                                /* Destructor */

        class SentenceLengthErrorException: public std::exception      /* Exception for sentence's length */
        {
            public:
                const char* what() const throw()
                {
                    return SENTENCE_LENGTH_ERROR;
                }
        };

        class WordLengthErrorException: public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return WORD_LENGTH_ERROR;
                }
        };

        class WrongMenuChoiseException: public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return WRONG_MENU_CHOISE;
                }
        };

    private:
        Sentence(const Sentence &cpy);              /* Copy constructor */
        Sentence &operator=(const Sentence &rhs);   /* Assignation operator constructor */
};

std::ostream & operator<<(std::ostream & o, Sentence const & i);

std::map<char, int>		map_conv(std::string sentence);

int     reverse_sentence(std::vector<std::string> sentence);        /* Display the sentence in reverse */
int		letter_sorted_occurences(std::string sentence);             /* Display the number of occurences of each letters */
int		number_sorted_occurences(std::string sentence);             /* Display the number of occurences of each letters sorted by number of occurences */

int     menu(std::vector<std::string>   sentence, std::string input_sentence, int option);
int     error_manager(std::vector<std::string>   sentence);

#endif