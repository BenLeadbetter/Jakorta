// source file for TextBox.hpp header

#include "TextBox.hpp"
#include <vector>
#include <stdexcept>
#include <string>
#include <cctype>
#include <algorithm> 

using namespace sf;

// constructor
TextBox::TextBox(int in_width, Font& in_font)
{

    width = in_width;

    // the default option is for the height to be defined by the size of the text_texture
    height = 0;
    height_set = false;

    position = Vector2f(0, 0);

    alignment = Alignment::LEFT; 

    font_size = 70;

    padding = 10;

    text_color = Color::Black;

    background_color = sf::Color::White;

    font_pointer = &in_font;

    text_texture = new sf::Texture;
    box_texture = new sf::Texture;

}

TextBox::~TextBox()
{
    delete text_texture;
    delete box_texture;

}

// set font function
void TextBox::setFont(sf::Font& set_font)
{
    font_pointer = &set_font;
}

// splitting function for text input
bool space(char c)
{
	return isspace(c);
}
bool notspace(char c)
{
	return !isspace(c);
}

std::vector<std::string> split(const std::string& str)
{
	std::vector<std::string> ret;
	typedef std::string::const_iterator iter;
	iter i = str.begin();
	
	while(i != str.end())
	{
		//ignore leading blanks
		i = std::find_if(i, str.end(), notspace);
		
		//find end of the word, if any
		iter j = std::find_if(i, str.end(), space);
		
		//add word onto the end of the vector
		if(i != str.end())
			ret.push_back(std::string(i, j));
		i = j;
	}
	return ret;
}


// set text input stream function - 
void TextBox::setText(std::istream& input_stream)
{
    // clear any previously existing text
    text_vec.clear();

    // write new words to the text_vec
    std::string word;
    while(input_stream >> word)
        text_vec.push_back(word);
}

// set text from string
void TextBox::setText(const std::string& in_string)
{
    text_vec = split(in_string);
} 



// set the text texture
void TextBox::setTextTexture()
{
    // variable for formatting text
    std::string word;
    Text space;
    space.setFont(this->getFont());
    space.setCharacterSize(font_size);
    space.setOrigin(Vector2f(0, 0));
    space.setString(" ");
    int line_width = 0;
    int line_height = font_size;
    int line_count = 0;
    int space_width = space.getLocalBounds().width;

    // calculate how much height is needed    
    for(TextBox::const_iterator i = text_vec.begin(); i != text_vec.end(); ++i)
    {
        word = *i;
        Text word_text;
        word_text.setFont(this->getFont());
        word_text.setCharacterSize(font_size);
        word_text.setOrigin(Vector2f(0, 0));
        word_text.setString(word);
        if(word_text.getLocalBounds().width > width - 2 * padding)
        {
            std::cerr << "TextBox not wide enough for text" << std::endl;
            break;
        }

        if(line_width + word_text.getLocalBounds().width + space_width < width - 2 * padding)
        {
            // redefine line_width
            line_width += word_text.getLocalBounds().width;

            // add a space to the end of the line
            space.setPosition(Vector2f(line_width, line_height * line_count));

            // redefine line_width
            line_width += space_width;

        } else {
            // start a new line
            ++line_count;
            line_width = 0;

            // redefine line_width
            line_width += word_text.getLocalBounds().width;

            // add a space to the end of the line
            space.setPosition(Vector2f(line_width, line_height * line_count));

            // redefine line_width
            line_width += space_width;
        }
    }

    // we will write our text to this renderTexture
    RenderTexture rtexture;
    rtexture.create(width, (line_count + 1) * line_height + 2 * padding);

    // redefine a couple of variables 
    line_width = 0;
    line_count = 0;

    // write words to texture
    for(TextBox::const_iterator i = text_vec.begin(); i != text_vec.end(); ++i)
    {
        word = *i;
        Text word_text;
        word_text.setFont(this->getFont());
        word_text.setCharacterSize(font_size);
        word_text.setOrigin(Vector2f(0, 0));
        word_text.setFillColor(text_color);
        word_text.setString(word);

        if(line_width + word_text.getLocalBounds().width + space_width < width - 2 * padding)
        {
            // write the word to the texture
            word_text.setPosition(Vector2f(line_width, line_height * line_count));
            rtexture.draw(word_text);

            // redefine line_width
            line_width += word_text.getLocalBounds().width;

            // add a space to the end of the line
            space.setPosition(Vector2f(line_width, line_height * line_count));
            rtexture.draw(space);

            // redefine line_width
            line_width += space_width;

        } else {
            // start a new line
            ++line_count;
            line_width = 0;

            // Write word to new line
            word_text.setPosition(Vector2f(line_width, line_height * line_count));
            rtexture.draw(word_text);

            // redefine line_width
            line_width += word_text.getLocalBounds().width;

            // add a space to the end of the line
            space.setPosition(Vector2f(line_width, line_height * line_count));
            rtexture.draw(space);

            // redefine line_width
            line_width += space_width;
        }
    }

    rtexture.display();
    *text_texture = rtexture.getTexture();
}

// get sprite function
Sprite TextBox::getTextSprite() const
{   
    Sprite ret;

    ret.setTexture(*text_texture);

    ret.setPosition(Vector2f(padding, padding));

    return ret;
}

void TextBox::setBoxTexture()
{   
    setTextTexture();

    // we will write to a RenderTexture
    RenderTexture ret_texture;
    int box_height;
    if(height_set)
    {
        box_height = height;
    } else {
        box_height = (*text_texture).getSize().y + 2 * padding;
    }
    ret_texture.create(width, box_height);

    // set a background for the box
    RectangleShape background;
    background.setSize(Vector2f(width, box_height));
    background.setFillColor(background_color);

    // and write it to the texture
    ret_texture.draw(background);

    // write the text onto the texture
    ret_texture.draw(this->getTextSprite());
    
    // set to box_texture
    ret_texture.display();
    *box_texture = ret_texture.getTexture();
}

Sprite TextBox::getSprite() const
{
    
    // attach the texture to a sprite to return
    Sprite ret;
    ret.setTexture(*box_texture);
    ret.setPosition(position);

    return ret;
}

