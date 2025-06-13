#ifndef INIT_H
#define INIT_H

#include "global.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


SDL_Texture* loadTexture(const char* path,  SDL_Renderer* renderer);
void distroymediamenu();
int loadMedia(SDL_Renderer* renderer);


int compareScores(const void *a, const void *b);
void saveGame(const char *filename, const char *playerName, int matrix[4][4], int score, int highscore, Uint32 gameTime);
void loadGame(const char *filename, char *playerName, int matrix[4][4], int *score, int *highscore, Uint32 *gameTime);
void saveGameData(const char *filename, GameData playerData);
Mix_Music* loadMusic(const char* filepath);
void toggleMute(Mix_Chunk* clickSound);

int getBestHighScore(const char *filename);


#endif