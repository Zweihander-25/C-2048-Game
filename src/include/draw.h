#ifndef DRAW_H
#define DRAW_H

#include "global.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

//tiles colors

SDL_Color take_tile_color(int val);

//draw screens
void draw_machinevsplayer(SDL_Renderer* renderer);
void drawleaderboard(SDL_Renderer* renderer);
void draw_Menu(SDL_Renderer *renderer, int sound);

//draw rect
void drawRectangle(SDL_Renderer *renderer, int x, int y, int width, int height, SDL_Color color, int thickness);
void drawGradientRect(SDL_Renderer *renderer, SDL_Rect rect, SDL_Color outerColor, SDL_Color innerColor, int thickness);
//buttons
void drawBackButton(SDL_Renderer* renderer);
void drawPAUSEButton(SDL_Renderer* renderer);
void drawUNDOButton(SDL_Renderer* renderer);
void drawREPLAYButton(SDL_Renderer* renderer);
void draw_ARRET_Button(SDL_Renderer* renderer);
//+
void drawRESUMEButton(SDL_Renderer* renderer);

void draw_MvsP_REPLAYButton(SDL_Renderer* renderer);

void musicONButton(SDL_Renderer* renderer);
void musicOFFButton(SDL_Renderer* renderer);

//draw arrows
void drawUP(SDL_Renderer* renderer);
void drawDOWN(SDL_Renderer* renderer);
void drawRIGHT(SDL_Renderer* renderer);
void drawLEFT(SDL_Renderer* renderer);

//draw matrix
void renderMatrix(SDL_Renderer *renderer, TTF_Font *font, int T[MATRIX_SIZE][MATRIX_SIZE]);
void render_2_Matrix(SDL_Renderer *renderer, TTF_Font *font, int T[MATRIX_SIZE][MATRIX_SIZE], int M[MATRIX_SIZE][MATRIX_SIZE]);

//draw text
void drawText(SDL_Renderer *renderer, int x, int y, const char *texte, TTF_Font *police, SDL_Color couleur);




void drawFstPAGE(SDL_Renderer* renderer);



void drawM_REPLAYButton(SDL_Renderer* renderer);


#endif