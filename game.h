#pragma once

class Game
{
private:
    int debounce( int last, int buttonPin );
    void playNote( int note, int noteSpeed ) const;
    void flashLed( int led, int flashSpeed ) const;
    void initPins();

public:
    static const int RED_PIN;
    static const int BLUE_PIN;
    static const int GREEN_PIN;
    static const int YELLOW_PIN;
    static const int MICROPHONE_PIN;
    static const int RED_BUTTON_PIN;
    static const int BLUE_BUTTON_PIN;
    static const int GREEN_BUTTON_PIN;
    static const int YELLOW_BUTTON_PIN;
    static const int RED_TONE;
    static const int BLUE_TONE;
    static const int GREEN_TONE;
    static const int YELLOW_TONE;
    static const int GAMEOVER_TONE;

    int gameLevel[200];
    int gameSpeed;
    int lastButtonValue;
    int currentLevel;
    int gameIsOver;
    double gameDifficulty;
    enum color { YELLOW, GREEN, RED, BLUE };

public:
    Game();
    Game(int)
    ~Game();

    void playLevel();
    int userInput();
    int gameOver();
    int getNote( int note ) const;
    int pinToColorCode( int );
    int colorCodeToPinn( int );
    int readButton( int buttonPin );

};
