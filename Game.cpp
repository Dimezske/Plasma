#include "Game.h"
#include "Tilemap.h"

sf::Event event;
//***************************************************************
// Player Texture & Sprite
    sf::Texture pTexture;
    sf::IntRect rectSourceSpriteDown(32, 0, 32, 32);
    sf::IntRect rectSourceSpriteLeft(32, 32, 32, 32);
    sf::IntRect rectSourceSpriteRight(32, 64, 32, 32);
    sf::IntRect rectSourceSpriteUp(32, 96, 32, 32);
    sf::Sprite playerImage(pTexture, rectSourceSpriteDown);
    sf::Sprite sprite1();
// Player Sounds
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;
    sf::SoundBuffer soundBuffer2;
    sf::Sound sound2;
//***************************************************************
// Inventory
    sf::RectangleShape inventoryScreen;
//***************************************************************

const int level[] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 7, 7, 7, 7, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 4, 4, 4, 7, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 5, 7, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 5, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

bool Game::levelSet(){
    /*sf::Texture background;
    sf::RectangleShape backgroundShape(sf::Vector2f(32, 32));
    background.loadFromFile("/home/aidan/Desktop/GUI/Images/Grass1.png");
    backgroundShape.setTexture(&background);
    window.draw(backgroundShape);*/
    TileMap map;
        if (!map.load("/home/aidan/Documents/Desktop/GUI/Images/tileSet1.png", sf::Vector2u(32, 32), level, 48, 48))
        {
            return -1;

        }
        window.draw(map);
        if (level[7] == level[7])
        {
            soundBuffer2.loadFromFile("/home/aidan/Documents/Desktop/GUI/Sounds/PlayerWalk3.wav");
            sound2.setBuffer(soundBuffer2);

        }
}

void Game::view(){


    sf::View view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
    view.reset(sf::FloatRect(0,0,WIDTH,HEIGHT));
    view.setViewport(sf::FloatRect(0,0,1.0f,1.0f));
    view.setCenter(sf::Vector2f(50,50));
    view.setCenter(playerImage.getPosition());
    window.setView(view);

}

Game::Game() : window(sf::VideoMode(WIDTH, HEIGHT), "Plazma")
{
    window.setFramerateLimit(60);
}



void Game::run()
{

    while (window.isOpen())
    {
        sf::Clock clock;
        sf::Time time = clock.getElapsedTime();
        processEvents();
        update(time.asMilliseconds());
        render();
    }
}

void Game::Player()
{
pTexture.loadFromFile("/home/aidan/Documents/Desktop/GUI/Images/chibi.png");
playerImage.setTexture(pTexture);
soundBuffer.loadFromFile("/home/aidan/Documents/Desktop/GUI/Sounds/PlayerWalk.wav");
sound.setBuffer(soundBuffer);

}

void Game::drawPlayer(sf::RenderWindow &window){
    window.draw(playerImage);

}

// Player Controlling

void Game::processEvents()
{

    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::Resized:
            cout << "Width: " << event.size.width << "Height: " << event.size.height << endl;
            break;

        case sf::Event::MouseButtonPressed:
                switch (event.key.code)
                {
                case sf::Mouse::Left:
                    cout << "Left Mouse button has been pressed" << endl;



                    break;
                case sf::Mouse::Right:
                    cout << "Right Mouse button has been pressed" << endl;
                    break;
                case sf::Mouse::Middle:
                    cout << "Middle Mouse button has been pressed" << endl;
                    break;
                }
                break;

        case sf::Event::MouseWheelScrolled:
            // Mouse Scolling
            if (event.mouseWheelScroll.delta >= 1)
            {
                cout << "Mouse Scrolled Up" << endl;
            }
            if (event.mouseWheelScroll.delta <= -1)
            {
                cout << "Mouse Scrolled Down" << endl;
            }
            break;

        case sf::Event::KeyPressed:
                // PlayerKeys
                if(event.key.code == sf::Keyboard::S){
                    pDirection = 1;
                    direction();
                    playerImage.move(0,5);
                    playerAnimation_WalkDown();
                    // isWalking Delta-Time
                    time2 = clock3.getElapsedTime();
                    if(clock3.getElapsedTime().asSeconds() >= .2f)
                    {
                        sound.play();
                        clock3.restart();
                    }
                    cout << "S" << endl;
                }

                if(event.key.code == sf::Keyboard::W){
                    pDirection = 4;
                    direction();
                    playerImage.move(0,-5);
                    playerAnimation_WalkUp();
                    // isWalking Delta-Time
                    time2 = clock3.getElapsedTime();
                    if(clock3.getElapsedTime().asSeconds() >= .2f)
                    {
                        sound.play();
                        clock3.restart();
                    }
                    cout << "W" << endl;
                }

                if(event.key.code == sf::Keyboard::D){
                    pDirection = 3;
                    direction();
                    playerImage.move(5,0);
                    playerAnimation_WalkRight();
                    // isWalking Delta-Time
                    time2 = clock3.getElapsedTime();
                    if(clock3.getElapsedTime().asSeconds() >= .2f)
                    {
                        sound.play();
                        clock3.restart();
                    }

                    cout << "D" << endl;
                }

                if (event.key.code == sf::Keyboard::A){
                    pDirection = 2;
                    direction();
                    playerImage.move(-5,0);
                    playerAnimation_WalkLeft();
                    // isWalking Delta-Time
                    time2 = clock3.getElapsedTime();
                    if(clock3.getElapsedTime().asSeconds() >= .2f)
                    {
                        sound.play();
                        clock3.restart();
                    }
                    cout << "A" << endl;
                }
                break;

            case::sf::Event::KeyReleased:
            cout << "A key has been released" << endl;

                if(event.key.code == sf::Keyboard::S){
                    stopWalking();
                    cout << "Released S" << endl;
                }

                if(event.key.code == sf::Keyboard::W){
                    stopWalking();
                    cout << "Released W" << endl;
                }

                if(event.key.code == sf::Keyboard::D){
                    stopWalking();
                    cout << "Released D" << endl;
                }

                if (event.key.code == sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    stopWalking();
                    cout << "Released A" << endl;
                }

        }
    }
}
int Game::direction(){

    if(pDirection == 1){
        playerImage.setTextureRect(sf::IntRect(32, 0, 32, 32));
        cout << "DOWN" << endl;
        cout << playerImage.getPosition().x << endl;
        cout << playerImage.getPosition().y << endl;
    }
    else if(pDirection == 2){
        playerImage.setTextureRect(sf::IntRect(32, 32, 32, 32));
        cout << "LEFT" << endl;
        cout << playerImage.getPosition().x << endl;
        cout << playerImage.getPosition().y << endl;
    }
    else if(pDirection == 3){
        playerImage.setTextureRect(sf::IntRect(32, 64, 32, 32));
        cout << "RIGHT" << endl;
        cout << playerImage.getPosition().x << endl;
        cout << playerImage.getPosition().y << endl;
    }
    else if(pDirection == 4){
        playerImage.setTextureRect(sf::IntRect(32, 96, 32, 32));
        cout << "UP" << endl;
        cout << playerImage.getPosition().x << endl;
        cout << playerImage.getPosition().y << endl;
    }
}
void Game::setPlayerDir(int direction)
{
    if(direction == 1){
        playerImage.setTextureRect(sf::IntRect(32, 0, 32, 32));
        cout << "DOWN" << endl;
        cout << playerImage.getPosition().x << endl;
        cout << playerImage.getPosition().y << endl;
    }
    else if(direction == 2){
        playerImage.setTextureRect(sf::IntRect(32, 32, 32, 32));
        cout << "LEFT" << endl;
        cout << playerImage.getPosition().x << endl;
        cout << playerImage.getPosition().y << endl;
    }
    else if(direction == 3){
        playerImage.setTextureRect(sf::IntRect(32, 64, 32, 32));
        cout << "RIGHT" << endl;
        cout << playerImage.getPosition().x << endl;
        cout << playerImage.getPosition().y << endl;
    }
    else if(direction == 4){
        playerImage.setTextureRect(sf::IntRect(32, 96, 32, 32));
        cout << "UP" << endl;
        cout << playerImage.getPosition().x << endl;
        cout << playerImage.getPosition().y << endl;
    }
}
void Game::playerAnimation_WalkDown()
{

        if(clock2.getElapsedTime().asSeconds() >0.1f && clock2.getElapsedTime().asSeconds() < 0.2f){
            rectSourceSpriteDown.left = 32;
            playerImage.setTextureRect(rectSourceSpriteDown);
        }
        else if(clock2.getElapsedTime().asSeconds() > 0.2f && clock2.getElapsedTime().asSeconds() < 0.3f){
            rectSourceSpriteDown.left = 64;
            playerImage.setTextureRect(rectSourceSpriteDown);
        }

        else if(clock2.getElapsedTime().asSeconds() > 0.3f && clock2.getElapsedTime().asSeconds() < 0.4f){
            rectSourceSpriteDown.left = 32;
            playerImage.setTextureRect(rectSourceSpriteDown);
        }
        else if(clock2.getElapsedTime().asSeconds() > 0.4f && clock2.getElapsedTime().asSeconds() < 0.5f){
            rectSourceSpriteDown.left = 0;
            playerImage.setTextureRect(rectSourceSpriteDown);
        }
        else if(clock2.getElapsedTime().asSeconds() > 0.5f){
            clock2.restart();
        }
    }
    void Game::playerAnimation_WalkLeft()
    {

            if(clock2.getElapsedTime().asSeconds() >0.1f && clock2.getElapsedTime().asSeconds() < 0.2f){
                rectSourceSpriteLeft.left = 32;
                playerImage.setTextureRect(rectSourceSpriteLeft);
            }
            else if(clock2.getElapsedTime().asSeconds() > 0.2f && clock2.getElapsedTime().asSeconds() < 0.3f){
                rectSourceSpriteLeft.left = 64;
                playerImage.setTextureRect(rectSourceSpriteLeft);
            }

            else if(clock2.getElapsedTime().asSeconds() > 0.3f && clock2.getElapsedTime().asSeconds() < 0.4f){
                rectSourceSpriteLeft.left = 32;
                playerImage.setTextureRect(rectSourceSpriteLeft);
            }
            else if(clock2.getElapsedTime().asSeconds() > 0.4f && clock2.getElapsedTime().asSeconds() < 0.5f){
                rectSourceSpriteLeft.left = 0;
                playerImage.setTextureRect(rectSourceSpriteLeft);
            }
            else if(clock2.getElapsedTime().asSeconds() > 0.5f){
                clock2.restart();
            }
        }
        void Game::playerAnimation_WalkRight()
        {

                if(clock2.getElapsedTime().asSeconds() >0.1f && clock2.getElapsedTime().asSeconds() < 0.2f){
                    rectSourceSpriteRight.left = 32;
                    playerImage.setTextureRect(rectSourceSpriteRight);
                }
                else if(clock2.getElapsedTime().asSeconds() > 0.2f && clock2.getElapsedTime().asSeconds() < 0.3f){
                    rectSourceSpriteRight.left = 64;
                    playerImage.setTextureRect(rectSourceSpriteRight);
                }

                else if(clock2.getElapsedTime().asSeconds() > 0.3f && clock2.getElapsedTime().asSeconds() < 0.4f){
                    rectSourceSpriteRight.left = 32;
                    playerImage.setTextureRect(rectSourceSpriteRight);
                }
                else if(clock2.getElapsedTime().asSeconds() > 0.4f && clock2.getElapsedTime().asSeconds() < 0.5f){
                    rectSourceSpriteRight.left = 0;
                    playerImage.setTextureRect(rectSourceSpriteRight);
                }
                else if(clock2.getElapsedTime().asSeconds() > 0.5f){
                    clock2.restart();
                }
            }
            void Game::playerAnimation_WalkUp()
            {

                    if(clock2.getElapsedTime().asSeconds() >0.1f && clock2.getElapsedTime().asSeconds() < 0.2f){
                        rectSourceSpriteUp.left = 32;
                        playerImage.setTextureRect(rectSourceSpriteUp);
                    }
                    else if(clock2.getElapsedTime().asSeconds() > 0.2f && clock2.getElapsedTime().asSeconds() < 0.3f){
                        rectSourceSpriteUp.left = 64;
                        playerImage.setTextureRect(rectSourceSpriteUp);
                    }

                    else if(clock2.getElapsedTime().asSeconds() > 0.3f && clock2.getElapsedTime().asSeconds() < 0.4f){
                        rectSourceSpriteUp.left = 32;
                        playerImage.setTextureRect(rectSourceSpriteUp);
                    }
                    else if(clock2.getElapsedTime().asSeconds() > 0.4f && clock2.getElapsedTime().asSeconds() < 0.5f){
                        rectSourceSpriteUp.left = 0;
                        playerImage.setTextureRect(rectSourceSpriteUp);
                    }
                    else if(clock2.getElapsedTime().asSeconds() > 0.5f){
                        clock2.restart();
                    }
                }

            void Game::stopWalking()
            {
                sound.stop();
            }
            // create a view with the rectangular area of the 2D world to show

            // create a view with its center and size
// Objects




void Game::Button1(){
    if(!texture.loadFromFile("/home/aidan/Documents/Desktop/GUI/Images/InventoryButton.png"))
    {
                cout << "Could not Load Button1" << endl;
    }
    sprite.setTexture(texture);
    if (event.mouseButton.button == sf::Mouse::Left) {
        if (sprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))) {
            cout << "ButtonPressed" << endl;
            if(!texture.loadFromFile("/home/aidan/Documents/Desktop/GUI/Images/pInv_Button.png"))
            {
                        cout << "Could not Load invButton1" << endl;
            }
                invScrDimesions();
        }
    }
    sprite.setPosition(sf::Vector2f(50, 3));
}



sf::RectangleShape box(sf::Vector2f(994, 30));
void Game::hudPos()
{
    box.setFillColor(sf::Color(125,125,125,125));
    box.setOutlineColor(sf::Color(185,185,185,185));
    box.setOutlineThickness(3.0);
    box.setPosition(3,3);
}

void Game::hudView()
{
    sf::View hudView;
    hudView.reset(sf::FloatRect(0,0,WIDTH,HEIGHT));
    hudPos();
    window.setView(hudView);
    window.draw(box);
}

void Game::hudViewButtons(){
    sf::View hudView_Buttons;
    hudView_Buttons.reset(sf::FloatRect(0,0,WIDTH,HEIGHT));
    Button1();
    window.setView(hudView_Buttons);
    window.draw(sprite);
}
void Game::invScrDimesions(){
    inventoryScreen.setSize(sf::Vector2f(500,500));
    inventoryScreen.setFillColor(sf::Color(125,125,125,125));
    inventoryScreen.setOutlineColor(sf::Color(125,125,125,255));
    inventoryScreen.setOutlineThickness(3);
    inventoryScreen.setPosition(100, 100);
    window.draw(inventoryScreen);
}
void Game::invView(){
    sf::View inventoryView;
    inventoryView.reset(sf::FloatRect(0,0,WIDTH,HEIGHT));
    invScrDimesions();
    window.setView(inventoryView);

}
void Game::invClose(){
    inventoryScreen.setSize(sf::Vector2f(0,0));
}
sf::Texture bush1Texure;
void Game::bushGenerator(){
    int i;
    if(!bush1Texure.loadFromFile("/home/aidan/Documents/Desktop/GUI/Images/Bush1.png"))
    {
                cout << "Could not Load Bush1" << endl;
    }
        std::vector<sf::Sprite> Bush1(5, sf::Sprite(bush1Texure));
        for(i=0; i<5; i++){
            Bush1[i].setPosition(10, 10);
            Bush1[1].setPosition(36, 49);
            Bush1[2].setPosition(156, 259);
            Bush1[3].setPosition(236, 229);
            Bush1[4].setPosition(156, 79);

            window.draw(Bush1[i]);
            sf::FloatRect boundingBoxBush1 = Bush1[i].getGlobalBounds();
            sf::FloatRect boundingBoxPLAYER = playerImage.getGlobalBounds();
            sf::Vector2f position;

            if(boundingBoxBush1.intersects(boundingBoxPLAYER) && pDirection == 1)
            {
            playerImage.move(-0,-1);
                if(position.x >= Bush1[i].getGlobalBounds().width)
                {

                }
            }
            if(boundingBoxBush1.intersects(boundingBoxPLAYER) && pDirection == 2)
            {
            playerImage.move(1,0);
                if(position.x >= Bush1[i].getGlobalBounds().width)
                {

                }
            }
            if(boundingBoxBush1.intersects(boundingBoxPLAYER) && pDirection == 3)
            {
            playerImage.move(-1,0);
                if(position.x >= Bush1[i].getGlobalBounds().width)
                {

                }
            }
            if(boundingBoxBush1.intersects(boundingBoxPLAYER) && pDirection == 4)
            {
            playerImage.move(-0,1);
                if(position.x >= Bush1[i].getGlobalBounds().width)
                {

                }
            }
    }
}

//Collision

void Game::update(float dt)
{

}

void Game::render()
{

        window.clear();
        // Level Creation
        levelSet();
        bushGenerator();
        // Camera,Menus & Huds
        hudView();
        hudViewButtons();
        view();

        // Create player to render
        Player();

        // Drawing
        drawPlayer(window);

        // Drawing Objects
        Button1();

        // Display Rendering
        window.display();
        window.clear();
}

/*
        void Game::Shape(){
            sf::RectangleShape rectangle;

            rectangle.setSize(sf::Vector2f(100, 50));
            rectangle.setOutlineColor(sf::Color::Red);
            rectangle.setOutlineThickness(5);
            rectangle.setPosition(10, 20);
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (rectangle.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))) {
                        cout << "ButtonPressed" << endl;
                }
            }
            window.draw(rectangle);
        }
*/
