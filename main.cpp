// main file for the Jakorta card game

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameBoard.hpp"
#include "ResourceManager.hpp"

using namespace sf;

int main()
{
    // Render a window - sized to the background image
    RenderWindow window(VideoMode(1920, 1094), "Jakorta", Style::Resize);
    window.setFramerateLimit(100);

    // set up Resource Manager 
    ResourceManager resource_manager;

    // mouse position
    sf::Vector2i mousePosition;

    // test the GameBoard
    GameBoard gameBoard(resource_manager);
    gameBoard.m_JakortaDeck.shuffle();
    gameBoard.m_MainDeck.shuffle();

    gameBoard.m_PlayerHands[0].placeOnTop(gameBoard.m_MainDeck.removeTopCard());
    gameBoard.m_PlayerHands[0].placeOnTop(gameBoard.m_MainDeck.removeTopCard());

    gameBoard.m_RolePool.setSprites(Vector2f(200,500));



    // Set initial visible area for the main View
    FloatRect visibleArea(0.f, 0.f, 1920.f, 1094.f);
    View mainView(visibleArea);

    // Create background sprite
    Sprite spriteBackground;
    spriteBackground.setTexture(resource_manager.getTexture("background"));
    spriteBackground.setPosition(0, 0);

    // Main loop
    while(window.isOpen())
    {
        /*
        **********************************************
                        Handle Input
        **********************************************
        */

       // Event polling
       Event event;
       while(window.pollEvent(event))
       {
           // catch the resize events
           if (event.type == Event::Resized)
           {
               // update the main view to the new window size
               visibleArea.width = event.size.width;
               visibleArea.height = event.size.height;
           }

           if (event.type == Event::MouseButtonReleased)
           {
               gameBoard.m_CardInHand.addCard(gameBoard.m_MainDeck.returnTopCard());
           }
       }
        // Handle quitting
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        /*
        **********************************************
                        Update the scene
        **********************************************
        */

       mainView.reset(visibleArea);

       mousePosition = sf::Mouse::getPosition();

       gameBoard.m_RolePool.highlight(mousePosition);


        /*
        **********************************************
                        Draw the scene
        **********************************************
        */
        // clear everything fromt the last frame
        window.clear();

        // Draw the background
        window.setView(mainView);
        window.draw(spriteBackground);

        // Draw some other stuff
        gameBoard.m_JakortaDeck.draw(window, Vector2f(50, 50));
        gameBoard.m_RolePool.draw(window);
        gameBoard.m_PlayerHands[0].draw(window, Vector2f(0, 0), resource_manager);
            
        // Show everything drawn
        window.display();



    } // End game loop

    return 0;
}
