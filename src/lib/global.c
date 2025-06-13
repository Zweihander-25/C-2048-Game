#include "global.h"

int directions[DIRECTIONS] = {0, 1, 2, 3};

Mix_Chunk* clickSound = NULL;
Mix_Chunk* keyboardclick = NULL;
Mix_Chunk* YOU_WINsound = NULL;
Mix_Chunk* GAME_OVERsound = NULL;
Mix_Chunk* PAUSEsound = NULL;
Mix_Chunk* MOVEsound = NULL;
Mix_Chunk* machineMOVEsound = NULL;

SDL_Texture* FIRSTPAGETexture = NULL;

SDL_Texture* gBackgroundTexture = NULL;
SDL_Texture* gblurrBackgroundTexture = NULL;

SDL_Texture* gPlayerTexture = NULL;
SDL_Texture* gMachineTexture = NULL;
SDL_Texture* gMachineVsPlayerTexture = NULL;
SDL_Texture* gtopplayersTexture = NULL;


SDL_Texture* gBackgroundTextureTP = NULL;
SDL_Texture* gRectTexture = NULL;       // Texture for rect.png
SDL_Texture* gBackButtonTexture = NULL; // Texture for backbutton.png
SDL_Texture* REPLAYTexture = NULL;
SDL_Texture* UNDOTexture = NULL;


//gameover texture
SDL_Texture* gGOBackgroundTexture = NULL; 
SDL_Texture* YOUWINBackgroundTexture = NULL; // you win


SDL_Texture* gReplayTexture = NULL;       // Texture for replay.png
SDL_Texture* gExitTexture = NULL; 
SDL_Texture* continueTexture = NULL; 
//player vs machine
SDL_Texture* gtimeTexture = NULL;           //  time rect
SDL_Texture* gmachineiconTexture = NULL;    //  machine icon
SDL_Texture* gplayericonTexture = NULL;         //  player icon
SDL_Texture* PAUSETexture = NULL;
SDL_Texture* ARRETTexture = NULL;
SDL_Texture* RESUMETexture = NULL;

SDL_Texture* musicONTexture = NULL;
SDL_Texture* musicOFFTexture = NULL;
// arrows
SDL_Texture* UPTexture = NULL;
SDL_Texture* RIGHTTexture = NULL;
SDL_Texture* LEFTTexture = NULL;
SDL_Texture* DOWNTexture = NULL;

TTF_Font *fontTitle = NULL;
TTF_Font *fontInput= NULL;
TTF_Font *fontMvP = NULL;

SDL_Color Blue = {0, 128, 128, 255}; 
SDL_Color Pink = {128, 0, 128, 255}; 
SDL_Color white = {255, 255, 255, 255};