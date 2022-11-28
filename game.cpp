#include "game.h"

/* Pin Settings */
/* Change accordingly for your platform / setup */
static const int Game::MICROPHONE_PIN       = 12;
static const int Game::BLUE_PIN             = 11;
static const int Game::RED_PIN              = 10;
static const int Game::GREEN_PIN            = 09;
static const int Game::YELLOW_PIN           = 08;
static const int Game::BLUE_BUTTON_PIN      = 07;
static const int Game::RED_BUTTON_PIN       = 06;
static const int Game::GREEN_BUTTON_PIN     = 05;
static const int Game::YELLOW_BUTTON_PIN    = 04;

/* Tone Frequencies */
static const int Game::RED_TONE             = 0200;
static const int Game::BLUE_TONE            = 0400;
static const int Game::YELLOW_TONE          = 0600;
static const int Game::GREEN_TONE           = 0800;
static const int Game::GAMEOVER_TONE        = 1000;

Game::Game( int difficulty )
    : gameSpeed( 1000 )
    , lastButtonValue( -1 )
    , currentLevel( 0 )
    , gameDifficulty( difficulty )
    , gameIsOver( 0 ) 
{
    initPins();
}

Game::Game()
    : gameSpeed( 1000 )
    , lastButtonValue( -1 )
    , currentLevel( 0 )
    , gameDifficulty( 10 )
    , gameIsOver( 0 ) 
{
    initPins();
}

void Game::initPins()
{
    pinMode(Game::MICROPHONE_PIN, OUTPUT);
    pinMode(Game::BLUE_PIN, OUTPUT);
    pinMode(Game::RED_PIN, OUTPUT);
    pinMode(Game::GREEN_PIN, OUTPUT);
    pinMode(Game::YELLOW_PIN, OUTPUT);
}

int Game::debounce(int last, int buttonPin)
{
    int current = digitalRead(buttonPin);
    if (last != current)
    {
        delay( 5 );
        current = digitalRead(buttonPin);
    }

    return current;
}



