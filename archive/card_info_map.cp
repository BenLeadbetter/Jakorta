// source file for the card_info_map header

#include "card_info_map.hpp"
#include <string>

using namespace std;

// decides whether a word is bracketed
bool bracketed(const std::string& in_string)
{
    if(*(in_string.begin()) != '<')
        return false;
    
    if(*(--in_string.end()) != '>')
        return false;
    
    return true;
}

// function to 'unbracket' a word
string unbracket(const string& bracketed_word)
{
    string ret(++bracketed_word.begin(), --bracketed_word.end());

    return ret;
}

// function to take an input stream and generate a card_info_map
map<string, string> cardInfoMap(istream& i_stream)
{
    map<string, string> ret;
    string word;
    string following_words;
    while(!i_stream.eof())
    {
        // find the first bracketed word
        while(!bracketed(word)) 
            i_stream >> word;

        // the following words will be stored as a descriptor
        
        string descriptor = "";

        while(i_stream >> following_words && !bracketed(following_words))
        {
            descriptor += " ";
            descriptor += following_words;
        }

        // set up the map entry
        ret[unbracket(word)] = descriptor;

        // if we found a bracketed word, write it to word
        word = following_words;

    }

    return ret;
}