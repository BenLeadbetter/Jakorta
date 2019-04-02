#ifndef __GUARD_CARD_INFO_MAP
#define __GUARD_CARD_INFO_MAP
// header file for card_info_map function

#include <map>
#include <istream>

// decides whether a word is bracketed
bool bracketed(const std::string&);

// function to 'unbracket' a word
std::string unbracket(const std::string&);

// function to take an input stream and generate a card_info_map
std::map<std::string, std::string> cardInfoMap(std::istream&);



#endif