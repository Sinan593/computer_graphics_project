#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

extern int WINWIDTH;
extern int WINNHEIGHT;

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
    #include<GL/glut.h>
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

// My includes
#include "MyObjects.h"      // Game-specific objects
#include "config.h"         // Game configurations

class Breakout {

public:
    // Class Constructor/Destructor
    Breakout();
    ~Breakout();
    
    // Public functions (handle GLUT calls)
    void display(void);
    void init(void);
    void reshape(int width, int height);
    void mouseClick(int button, int state, int x, int y);
    void mouseMove(int x, int y);
    void keyStroke(unsigned char key, int x, int y);
    void specialKeyPos(int key, int x, int y);
    
private:
    // Game statistics
    int score;
    int level;
    int reward;
    int lifesCount;
    
    // Possible game mode
    enum State {INIT, START_PAGE, Menus, Gameplay, Scoreboard};
    Breakout::State gameState;
    
    // Balls
    std::vector <Ball> balls;
    
    // Paddle
    Paddle paddle;
    
    // Bricks
    std::vector<Brick> bricks;
    
    // Background music
    Mix_Music *backgroundMusic;
    
    // Private functions
    void drawBackground(void);
    void drawGame(void);
    void newBall(float x, float y);
    void drawBalls(void);
    void initPaddle(void);
    void drawPaddle(void);
    void initBricks(void);
    void bricksLevel1(void);
    void bricksLevel2(void);
    void bricksLevel3(void);
    void bricksLevel4(void);
    void bricksLevel5(void);
    void drawBricks(void);
    template <typename Iterator>
    int wallCollision(Iterator it);
    template <typename Iterator>
    bool brickCollision(Iterator it, Iterator br);
    template <typename Iterator>
    Iterator hitBrick(Iterator brick);
    void drawLife(float x, float y);
    void drawGameStats(void);
    void drawScore(void);
    void drawCoordinate(void);
    void drawStartPage(void);
};

#endif // BREAKOUT_H
