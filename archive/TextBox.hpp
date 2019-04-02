#ifndef __GUARD_TEXBOX2
#define __GUARD_TEXBOX2

// header file for the TextBox class

#include <string>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

enum class Alignment { CENTRE, LEFT };

class TextBox 
{   
    public:

        // typedefs
        typedef std::vector<std::string>::const_iterator const_iterator;

        // constuctor and destructor
        TextBox(int, sf::Font&);
        ~TextBox();

        // getters
        sf::Vector2f shape() const;
        sf::Sprite getSprite() const;
        sf::Sprite getTextSprite() const;
        sf::Font& getFont() const { return *font_pointer; }

        // iterators for looking through the text vector
        const_iterator begin() const { return text_vec.begin(); }
        const_iterator end() const { return text_vec.end(); }

        //setters
        void setWidth(int new_width) { width = new_width; }
        void setHeight(int new_height) { height = new_height; height_set = true; }
        void unsetHeight() { height = 0; height_set = false; }
        void setPosition(sf::Vector2f new_pos) { position = new_pos; }
        // void setAlignment(Alignment new_alignment) { alignment = new_alignment; }
        void setFont(sf::Font&);
        void setFontSize(int new_font_size) { font_size = new_font_size; }
        void setPadding(int new_padding) { padding = new_padding; }
        void setText(std::istream&);
        void setTextColor(const sf::Color& in_color) { text_color = in_color; }
        void setBackgroundColor (const sf::Color& in_color) { background_color = in_color; }
        void setText(const std::string&);

        // activator to set the textures;
        void display() { setTextTexture(); setBoxTexture(); }

    private:

        std::vector<std::string> text_vec;
        int width;
        int height;
        bool height_set;
        sf::Vector2f position;
        Alignment alignment;
        sf::Font* font_pointer;
        int font_size;
        int padding;
        sf::Texture* text_texture;
        sf::Texture* box_texture;
        sf::Color text_color;
        sf::Color background_color;

        void setTextTexture();
        void setBoxTexture();
        void clearTextTexture();
        void clearBoxTexture();
};


#endif