#include "Game.h"

// Player
sf::Texture pTexture;

sf::IntRect rectSourceSpriteDown(32, 0, 32, 32);
sf::IntRect rectSourceSpriteLeft(32, 32, 32, 32);
sf::IntRect rectSourceSpriteRight(32, 64, 32, 32);
sf::IntRect rectSourceSpriteUp(32, 96, 32, 32);
sf::Sprite playerImage(pTexture, rectSourceSpriteDown);
sf::SoundBuffer soundBuffer;
sf::Sound sound;



Game::Game() : window(sf::VideoMode(WIDTH, HEIGHT), "Royal Slots")
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
pTexture.loadFromFile("/home/aidan/Desktop/GUI/Images/chibi.png");
playerImage.setTexture(pTexture);
soundBuffer.loadFromFile("/home/aidan/Desktop/GUI/Sounds/PlayerWalk.wav");
sound.setBuffer(soundBuffer);

}

void Game::drawPlayer(sf::RenderWindow &window){

    window.draw(playerImage);

}
void Game::loadPlayer()
{
    playerImage.setPosition(sf::Vector2f(100, 100));
}
void Game::setPlayerDir(int direction)
{


    if(direction == 1){
        playerImage.setTextureRect(sf::IntRect(32, 0, 32, 32));
        cout << "DOWN" << endl;
    }
    else if(direction == 2){
        playerImage.setTextureRect(sf::IntRect(32, 32, 32, 32));
        cout << "LEFT" << endl;
    }
    else if(direction == 3){
        playerImage.setTextureRect(sf::IntRect(32, 64, 32, 32));
        cout << "RIGHT" << endl;
    }
    else if(direction == 4){
        playerImage.setTextureRect(sf::IntRect(32, 96, 32, 32));
        cout << "UP" << endl;
    }
}
void Game::processEvents()
{
    sf::Event event;
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

                if(event.key.code == sf::Keyboard::S){
                    setPlayerDir(1);
                    playerImage.move(0,5);
                    playerAnimation_WalkDown();
                    sound.play();
                    sound.setLoop(true);
                    
                    cout << "S" << endl;

                }

                if(event.key.code == sf::Keyboard::W){
                    setPlayerDir(4);
                    playerImage.move(0,-5);
                    playerAnimation_WalkUp();
                    sound.play();
                    sound.setLoop(true);

                    cout << "W" << endl;
                }

                if(event.key.code == sf::Keyboard::D){
                    setPlayerDir(3);
                    playerImage.move(5,0);
                    playerAnimation_WalkRight();
                    sound.play();
                    sound.setLoop(true);

                    cout << "D" << endl;
                }

                if (event.key.code == sf::Keyboard::A){
                    setPlayerDir(2);
                    playerImage.move(-5,0);
                    playerAnimation_WalkLeft();
                    sound.play();
                    sound.setLoop(true);
                    cout << "A" << endl;

                }
                break;

            case::sf::Event::KeyReleased:
            cout << "A key has been released" << endl;

            if(event.key.code == sf::Keyboard::S){
                sound.stop();
                cout << "Released S" << endl;
            }

            if(event.key.code == sf::Keyboard::W){
                sound.stop();
                cout << "Released W" << endl;
            }

            if(event.key.code == sf::Keyboard::D){
                sound.stop();
                cout << "Released D" << endl;
            }

            if (event.key.code == sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                sound.stop();
                cout << "Released A" << endl;
            }

         }
    }
}

void Game::update(float dt)
{

}

void Game::render()
{
    window.clear();
    // Create player to render
    Player();



    //draw()
    drawPlayer(window);
    window.display();
    window.clear();
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
