#ifndef GLOBAL_H
#define GLOBAL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
    MAIN_MENU,
    PLAYER_MODE, //new game
    MACHINE_MODE,
    MACHINE_VS_PLAYER,
    TOP_PLAYERS,
    
    PLAYER_MENU,
    CONTINUE, //continue
    NAME_INPUT,

    ARRET,
    REPLAY,
    SAVE_QUIT,
    EXIT
} GameState;

typedef struct {
    char NAME[35];
    int highscore;
    Uint32 time;
} GameData;

typedef struct{
    char NAME[35];
    int T[4][4];
    int score;
    int highscore;
    Uint32 time;
}arretDATA;

typedef enum {
UP,
RIGHT,
LEFT,
DOWN,
NONE
} ARR_DIRECTION;

#define DIRECTIONS 4

#define WINDOW_WIDTH  1200
#define WINDOW_HEIGHT 650
#define MATRIX_SIZE   4
#define CELL_SIZE     90

#define PLAYER_BUTTON_WIDTH  250
#define PLAYER_BUTTON_HEIGHT  90

// Desired size for the rect image (numerical values)
#define RECT_WIDTH 950 // New width for rect.png
#define RECT_HEIGHT 500 // New height for rect.png

// Desired size for the backbutton image (numerical values)
#define BACKBUTTON_WIDTH 65 // New width for backbutton.png
#define BACKBUTTON_HEIGHT 50// New height for backbutton.png
 
//game over rects
#define GAMEOVERBUTTON_WIDTH 180
#define GAMEOVERBUTTON_HEIGHT 75

// machine vs player
#define SPHERE_WIDTH 330 // Width for sphere.png
#define SPHERE_HEIGHT 140 // Height for sphere.png

#define SPHERE2_WIDTH 330 // Width for sphere2.png
#define SPHERE2_HEIGHT 140 // Height for sphere2.png

#define TIME_WIDTH 269    // Width for time.png
#define TIME_HEIGHT 96    // Height for time.png

extern int directions[DIRECTIONS];

extern TTF_Font *fontMvP;
extern TTF_Font *fontTitle;
extern TTF_Font *fontInput;


extern Mix_Chunk* clickSound;
extern Mix_Chunk* keyboardclick;
extern Mix_Chunk* YOU_WINsound;
extern Mix_Chunk* GAME_OVERsound;
extern Mix_Chunk* PAUSEsound;
extern Mix_Chunk* MOVEsound;
extern Mix_Chunk* machineMOVEsound;

extern SDL_Texture* FIRSTPAGETexture;
// Textures for images
extern SDL_Texture* gBackgroundTexture;
extern SDL_Texture* gblurrBackgroundTexture;

extern SDL_Texture* gPlayerTexture;
extern SDL_Texture* gMachineTexture;
extern SDL_Texture* gMachineVsPlayerTexture;
extern SDL_Texture* gtopplayersTexture;

extern SDL_Texture* gBackgroundTextureTP; // Texture for top player BG
extern SDL_Texture* gRectTexture;       // Texture for rect.png
extern SDL_Texture* gBackButtonTexture; // Texture for backbutton.png

extern SDL_Texture* REPLAYTexture;  // replay 
extern SDL_Texture* UNDOTexture; //undo
extern SDL_Texture* PAUSETexture; //pause
extern SDL_Texture* ARRETTexture;
extern SDL_Texture* RESUMETexture;

extern SDL_Texture* musicONTexture;
extern SDL_Texture* musicOFFTexture;

//game over
extern SDL_Texture* gGOBackgroundTexture; // game over
extern SDL_Texture* YOUWINBackgroundTexture; //you win

//gameover and you win
extern SDL_Texture* gReplayTexture;       // Texture for replay.png
extern SDL_Texture* gExitTexture; 
extern SDL_Texture* continueTexture; 

// machine vs player
extern SDL_Texture* gtimeTexture;           //  time rect
extern SDL_Texture* gmachineiconTexture;    //  machine icon
extern SDL_Texture* gplayericonTexture;         //  player icon

// arrows
extern SDL_Texture* UPTexture;
extern SDL_Texture* RIGHTTexture;
extern SDL_Texture* LEFTTexture;
extern SDL_Texture* DOWNTexture;



extern SDL_Color white;
extern SDL_Color Blue;
extern SDL_Color Pink;








#endif