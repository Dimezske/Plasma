#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

using namespace std;

#define WIDTH 1000
#define HEIGHT 500



class Game
{
public:
    Game();
    void Player();
    void run();
    void drawPlayer(sf::RenderWindow &window);
    void setPlayerDir(int direction);
    void loadPlayer();
    void playerAnimation_WalkDown();
    void playerAnimation_WalkLeft();
    void playerAnimation_WalkRight();
    void playerAnimation_WalkUp();


private:
    void processEvents();
    void update(float dt);
    void render();
    sf::RenderWindow window;
    sf::Clock clock2;
    
};
