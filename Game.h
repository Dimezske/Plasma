#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <unistd.h>

using namespace std;

#define WIDTH 1000
#define HEIGHT 500



class Game
{
public:
// Process Game
    Game();
    void run();
// Cameras
    void view();

// Hud Display
    void hud();
    void hudView();
    void hudViewButtons();
    void hudPos();
    void invScrDimesions();
    void invView();
    void invClose();
// Tileset
    bool levelSet();
    void Player();
    void drawPlayer(sf::RenderWindow &window);
    void setPlayerDir(int direction);
    int direction();
    void playerAnimation_WalkDown();
    void playerAnimation_WalkLeft();
    void playerAnimation_WalkRight();
    void playerAnimation_WalkUp();
    void stopWalking();

    // Objects
    void statsBar();
    void Button1();
    void Shape();
    // Environment
    void bushGenerator();

private:
    void processEvents();
    void update(float dt);
    void render();
    sf::RenderWindow window;
    sf::Clock clock2;
    sf::Clock clock3;
    sf::Time time2;
    sf::Texture background;
    sf::Sprite bg;

    int pDirection;
    // Inventory
    sf::Clock invClock;
    sf::Time invTime;
    // Button
    sf::Sprite sprite;
    sf::Texture texture;
};
