#ifndef MODS_H
#define MODS_H

#include "global.h"
#include "draw.h"
#include "logic.h"
#include "init.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <string.h>

GameState runPlayerMode(SDL_Renderer *renderer, TTF_Font *font,  GameData *gameData, int MOD);
GameState runMachineMode(SDL_Renderer *renderer, TTF_Font *font,  GameData *gameData);
GameState runMachinevsPlayerMode(SDL_Renderer *renderer, TTF_Font *font);
GameState topplayers(SDL_Renderer *renderer, TTF_Font *font, GameData *gameData);

GameState PLAY_MENU(SDL_Renderer *renderer, TTF_Font *font);// continue or new game

GameState run_entername(SDL_Renderer *renderer,GameData *DATA); //new game

GameState drawGameOverScreen(SDL_Renderer* renderer, TTF_Font *font,int score ,Uint32 time, GameData gameData);

int isRectangleClicked(SDL_Rect rect, int mouseX, int mouseY);

GameState drawYOUWIN(SDL_Renderer* renderer, TTF_Font *font,int score,Uint32 time, GameData gameData);
#endif