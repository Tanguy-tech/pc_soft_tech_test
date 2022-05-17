#include "lexical_analyze.hpp"

int main()
{
    std::string                 input_sentence;
    std::vector<std::string>    vec_sentence;
    int                         option = -1;
    char                        delim = ' ';
    int                         err = -1;

    while (err != 0)
    {
        /* Prompt user to enter a sentence */
        std::cout << YELLOW << "Please enter a sentence : " << DEFAULT;
        getline(std::cin, input_sentence);

        /* Split sentence by spaces */
        std::stringstream sstream(input_sentence);
        std::string word;
        while (std::getline(sstream, word, delim)){
            vec_sentence.push_back(word);
        }
        /* clear current sentense if error is thrown to parse new sentence */
        if ((err = error_manager(vec_sentence)) == -1)
            vec_sentence.clear();
    }
    /* Loop while menu input is incorrect */
    while (option != 0)
    {
        std::cout << YELLOW << MENU_HEADER
            << GREEN << MENU_1
            << PINK << MENU_2
            << BLUE << MENU_3
            << RED << MENU_4
            << YELLOW << "\ninput your choise : ";
        std::cin >> option;
        if (std::cin.fail()) /* has a previous extraction failed? */
        {
            std::cin.clear(); /* put us back in 'normal' operation mode */
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); /* and remove the bad input */
        }
        option = menu(vec_sentence, input_sentence, option);
    }

    /* AFFICHER RESULTAT */

    return EXIT_SUCCESS;
}