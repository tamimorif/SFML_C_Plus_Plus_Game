#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

class Game
{
    // Local variable: variableName;
    // Global variable: mVariableName;
    // CONSTANT variable: MAX_ENEMIES
    const int WINDOW_HEIGH = 1000;
    const int WINDOW_WIDTH = 1500;

private:
    // Ceriables
    // Window
    sf::VideoMode mVideoMode;
    sf::RenderWindow *mWindow;
    sf::Event mEvent;

    // Mouse Position
    sf::Vector2i mMousePosWindow;
    sf::Vector2f mMousePosView;

    // Resources
    sf::Font mFont;

    // Text
    sf::Text mUiText;

    // Game Logic
    unsigned int mPoints;
    int mHealth;
    float mEnemySpawnTimer;
    float mEnemySpawnTimerMax;
    const int MAX_ENEMIES = 30;
    bool mMouseHeld;
    bool mEndGame;

    // Game object
    std::vector<sf::RectangleShape> mEnemies;
    sf::RectangleShape mEnemy;

    // Privet Functions
    void initWindow();
    void initFonts();
    void initEnemies();
    void initText();

public:
    // Constructors
    Game();
    virtual ~Game();

    // accessors
    const bool running() const;
    const bool getEndGame() const;

    // functions
    void spawnEnemy();

    void updateEnemies();
    void renderEnemies();

    void update();
    void render();

    void pollEvent();

    void updateMousePositions();
    void renderCounter();

    void updateText();
    void renderText();
};