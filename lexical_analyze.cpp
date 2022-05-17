#include "lexical_analyze.hpp"

/* Reverse sentence */
int		reverse_sentence(std::vector<std::string> sentence)
{
	std::cout << GREEN << "You choose to reverse the sentence!\n";
	for (auto it = sentence.rbegin(); it != sentence.rend(); it++)
    {
        std::cout << DEFAULT << *it;
		if (it+1 != sentence.rend())
			std::cout << ' ';
    }
	return 1;
}

/* Convert string onto map object with key and values */
std::map<char, int>		map_conv(std::string sentence)
{
	std::map<char, int>	occ;
	/* loop and increment value for key found */
	for (char i : sentence)
		if (i != ' ')
            occ[i]++;
	return occ;
}

/* Display letter occurences */
int		letter_sorted_occurences(std::string sentence)
{
	std::cout << PINK << "You choose to display the letter occurences sorted by letters!\n";
	/* Display map object */
	std::multimap<char, int, std::less<char>> sorted;
	std::map<char, int> occ = map_conv(sentence);
	for (auto i : occ)
		sorted.insert(std::make_pair(i.first, i.second));
	for (auto i : sorted)
	{
		std::cout << DEFAULT << i.first << "=" << i.second;
		const auto &lastkey = sorted.rbegin()->first;
		if (i.first != lastkey)
			std::cout << ", ";
	}
	return 2;
}

/* Display letter occurences sorted by number */
int		number_sorted_occurences(std::string sentence)
{
	std::cout << BLUE << "You choose to display the letter occurences sorted by numbers!\n";
	std::map<char, int>							map = map_conv(sentence);
	/* Declaring the type of Predicate that accepts 2 pairs and return a bool */
	typedef std::function<bool(std::pair<char, int>, std::pair<char, int>)> Comparator;
	Comparator compFunctor = [](std::pair<char, int> elem1 ,std::pair<char, int> elem2) {return elem1.second < elem2.second;};

	std::set<std::pair<char, int>, Comparator> sorted(map.begin(), map.end(), compFunctor);
	for (auto elem : map)
	{
		if (elem.second == 1)
			std::cout << DEFAULT << elem.first << "=" << elem.second << ", ";
	}
	for (auto elem : sorted)
	{
		std::cout << DEFAULT << elem.first << "=" << elem.second;
		const auto &lastkey = sorted.rbegin()->first;
		if (elem.first != lastkey)
			std::cout << ", ";
	}
	return 3;
}

/* Menu */
int     menu(std::vector<std::string>   sentence, std::string input_sentence, int option)
{
    try
    {
		if (option != 1 && option != 2 && option != 3 && option != 4)
			throw Sentence::WrongMenuChoiseException();
		else if (option == 1)
			return reverse_sentence(sentence);
		else if (option == 2)
			return letter_sorted_occurences(input_sentence);
		else if (option == 3)
			return number_sorted_occurences(input_sentence);
		else if (option == 4)
			return 0;
    }
    catch(const Sentence::WrongMenuChoiseException& e)
    {
        std::cerr << RED << e.what() << '\n';
        return -1;
    }
    
    return 0;
}

/* Error manager */
int     error_manager(std::vector<std::string>   sentence)
{
    try
    {
        if (sentence.size() < 0 || sentence.size() > 10000)
            throw Sentence::SentenceLengthErrorException();
        else 
        {
            std::vector<std::string>::iterator  it = sentence.begin();
            std::vector<std::string>::iterator  ite = sentence.end();
            for (; it != ite; it++)
            {
                if (it->size() < 1 || it->size() > 50)
                    throw Sentence::WordLengthErrorException();
            }
        }
    }
    catch(const Sentence::SentenceLengthErrorException& e)
    {
        std::cerr << RED << e.what() << '\n';
        return -1;
    }
    catch(const Sentence::WordLengthErrorException& e)
    {
        std::cerr << RED << e.what() << '\n';
        return -1;
    }
    return 0;
    
}