#include <SFML/Graphics.hpp>

int main() 
{    
    // create window
    constexpr unsigned int windowWidth{800};
    constexpr unsigned int windowHeight{600};
    sf::RenderWindow window(sf::VideoMode({windowWidth, windowHeight}), "Project01");

    constexpr unsigned int fps{30};
    window.setFramerateLimit(fps);

    // red square in the middle of the screen
    constexpr float tileSize{32.f};
    sf::RectangleShape redSquare({tileSize, tileSize});

    redSquare.setFillColor(sf::Color::Red);
    redSquare.setOrigin({tileSize/2, tileSize/2});
    // redSquare.setPosition({static_cast<float>(windowWidth)/2, static_cast<float>(windowHeight)/2}); => not very good for lisibility
    
    const sf::Vector2f windowCenter
    { 
        static_cast<float>(windowWidth)/2, 
        static_cast<float>(windowHeight)/2
    };
    redSquare.setPosition(windowCenter);
    
    // run the program as long as the window is open
    while(window.isOpen()) 
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while(const std::optional event = window.pollEvent()) 
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>()) 
            {
                window.close();
            }
        }
        // background color to green
        window.clear(sf::Color::Green); // clear the window with green color (important to clear before window.draw)
        
        // drawing is here

        window.draw(redSquare);

        // end the current frame
        window.display(); // have to call display() to take what was drew in the buffer and show it on screen
    }
}