#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>

//Render Thread
//Not recommended on most cases and i am not going to use 
void Render(sf::RenderWindow* Window)
{
    //Need to activate the window in this thread
    Window->setActive(true);

    //Rendering Loop
    while (Window->isOpen())
    {
        //Clear the Window with black color
        Window->clear(sf::Color::Black);

        //Draw everything here
        //Window.draw(...);

        //Display the current frame
        Window->display();
    }
}


//Create shapes and fraw them 
void CreatAndDrawShapes(sf::RenderWindow* Window)
{
    sf::CircleShape Circle(20.f);
    Circle.setFillColor(sf::Color::Green);
    Window->draw(Circle);

}


int main()
{
    bool bIsSmallWindow = false;

    //Drawing the main screen window
    sf::RenderWindow Window(sf::VideoMode({ 800, 800 }), "SFML window");

    //Setting window max frame rate
    //dont use vsync and frame rate limit at the same time it makes things worse
    //Window.setFramerateLimit(60);

    //Setting window position
    Window.setPosition({ 0,0 });

    //Enabling Vsync
    //dont use vsync and frame rate limit at the same time it makes things worse
    Window.setVerticalSyncEnabled(true);

    //Getting Screen Size
    sf::Vector2u WindowSize = Window.getSize();

    /*
    * Not recommended in most cases
    //Drawing
    // Disable window because same window cant exist on multiple threads
    Window.setActive(false);
    //Use the render thread
    std::thread RenderThread(&Render, &Window);
    */


    //Main Loop
    while (Window.isOpen())
    {

        //Checking for events
        while (const std::optional event = Window.pollEvent())
        {
            //Windows close button clicked
            if (event->is<sf::Event::Closed>())
                Window.close();

            //Check if any key pressed during this loop

            else if (const sf::Event::KeyPressed* KeyPress = event->getIf<sf::Event::KeyPressed>())
            {
                //Close window if escape button pressed
                if (KeyPress->scancode == sf::Keyboard::Scancode::Escape)
                    Window.close();

                if (KeyPress->scancode == sf::Keyboard::Scancode::R)
                {
                    if (bIsSmallWindow)
                    {
                        Window.setSize(sf::Vector2u(100, 100));
                        bIsSmallWindow = !bIsSmallWindow;
                    }
                    else
                    {
                        Window.setSize(sf::Vector2u(800, 800));
                        bIsSmallWindow = !bIsSmallWindow;
                    }
                }

            }
        }


        //getting the mouse position every frame 
        //sf::Vector2i Mouseposition = sf::Mouse::getPosition();
        //std::cout << Mouseposition.x << "," << Mouseposition.y << "\n";

        //Render
        //Clear the Window with black color
        Window.clear(sf::Color::Black);

        //Draw everything here
        //Window.draw(...);
        CreatAndDrawShapes(&Window);

        //Display the current frame
        Window.display();

    }

    //RenderThread.join();
}