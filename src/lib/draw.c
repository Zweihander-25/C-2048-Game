#include "draw.h"

SDL_Color take_tile_color(int val)
{
        SDL_Color color;
    switch (val)
    {
    case 0: color = (SDL_Color)  {2, 19, 52, 255}; break;

    case 2: color = (SDL_Color)   {167, 181, 254, 255}; break;

    case 4: color = (SDL_Color) {39, 90, 145, 255}; break;

    case 8: color = (SDL_Color) {100, 180, 220, 255}; break;

    case 16:color = (SDL_Color) {172, 135, 163 , 255}; break;

    case 32: color = (SDL_Color) {253, 199, 135, 255}; break;

    case 64: color = (SDL_Color) {79, 122, 130, 255}; break;

    case 128: color = (SDL_Color) {21, 90, 98, 255}; break;

    case 256: color = (SDL_Color) {141, 102, 124, 255}; break;

    case 512: color = (SDL_Color) {177, 102, 160, 255}; break;

    case 1024: color = (SDL_Color) {166, 83, 137, 255}; break;

    case 2048: color = (SDL_Color) {188, 127, 179, 255}; break;

    default: color = (SDL_Color)  {214, 161, 202, 255}; break;}
    return color;
}

void drawleaderboard(SDL_Renderer* renderer)
{
    
    SDL_RenderCopy(renderer, gBackgroundTextureTP, NULL, NULL);

    int rectX = (WINDOW_WIDTH - RECT_WIDTH) / 2;
    int rectY = (WINDOW_HEIGHT - RECT_HEIGHT) / 2;

    SDL_Rect rectRect = { rectX, rectY, RECT_WIDTH, RECT_HEIGHT };
    SDL_RenderCopy(renderer, gRectTexture, NULL, &rectRect);
}

void drawFstPAGE(SDL_Renderer* renderer)
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, FIRSTPAGETexture, NULL, NULL);
}

void draw_Menu(SDL_Renderer *renderer, int sound)
{

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, gBackgroundTexture, NULL, NULL);

    if (sound == 1)
    { musicONButton(renderer);
    }else if (sound == 0)
    {musicOFFButton(renderer);}

    SDL_Rect destRect;

    destRect.x = 475; 
    destRect.y = 100; 
    destRect.w = PLAYER_BUTTON_WIDTH;
    destRect.h = PLAYER_BUTTON_HEIGHT;
    SDL_RenderCopy(renderer, gMachineTexture, NULL, &destRect); 

    destRect.y = 210;
    SDL_RenderCopy(renderer, gPlayerTexture, NULL, &destRect);

    destRect.y = 320; 
    SDL_RenderCopy(renderer, gMachineVsPlayerTexture, NULL, &destRect);

    destRect.y = 430; 
    SDL_RenderCopy(renderer, gtopplayersTexture, NULL, &destRect);

    SDL_RenderPresent(renderer);

}

void draw_machinevsplayer(SDL_Renderer* renderer)
{

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, gBackgroundTexture, NULL, NULL);

    SDL_Rect sphereRect = { 10, WINDOW_HEIGHT - SPHERE_HEIGHT - 20, SPHERE_WIDTH, SPHERE_HEIGHT };
    SDL_RenderCopy(renderer, gplayericonTexture, NULL, &sphereRect);

    SDL_Rect sphere2Rect = { WINDOW_WIDTH - SPHERE2_WIDTH - 10, WINDOW_HEIGHT - SPHERE2_HEIGHT - 20, SPHERE2_WIDTH, SPHERE2_HEIGHT };
    SDL_RenderCopy(renderer, gmachineiconTexture, NULL, &sphere2Rect);

    SDL_Rect timeRect = { (WINDOW_WIDTH - TIME_WIDTH) / 2, 10, TIME_WIDTH, TIME_HEIGHT };
    SDL_RenderCopy(renderer, gtimeTexture, NULL, &timeRect);

}

void drawRectangle(SDL_Renderer *renderer, int x, int y, int width, int height, SDL_Color color, int thickness) {

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    for (int i = -thickness / 2; i <= thickness / 2; i++) {
        SDL_Rect rect = {x + i, y + i, width - 2 * i, height - 2 * i};
        SDL_RenderDrawRect(renderer, &rect);
    }
}

void drawGradientRect(SDL_Renderer *renderer, SDL_Rect rect, SDL_Color outerColor, SDL_Color innerColor, int thickness) {
    for (int i = 0; i < thickness; i++) {

        int r = outerColor.r + (innerColor.r - outerColor.r) * i / thickness;
        int g = outerColor.g + (innerColor.g - outerColor.g) * i / thickness;
        int b = outerColor.b + (innerColor.b - outerColor.b) * i / thickness;
        int a = outerColor.a;

        SDL_SetRenderDrawColor(renderer, r, g, b, a);
        SDL_Rect currentRect = {rect.x + i, rect.y + i, rect.w - 2 * i, rect.h - 2 * i};
        SDL_RenderDrawRect(renderer, &currentRect);
    }
}
//buttons
void drawPAUSEButton(SDL_Renderer* renderer)
{

    SDL_Rect PAUSEButtonRect = { 810 , 140, 70, 70 };
    SDL_RenderCopy(renderer, PAUSETexture, NULL, &PAUSEButtonRect);
}

void drawRESUMEButton(SDL_Renderer* renderer)
{
    SDL_Rect RESUMEButtonRect = { 810 , 140, 70, 70 };
    SDL_RenderCopy(renderer, RESUMETexture, NULL, &RESUMEButtonRect);
}

void drawUNDOButton(SDL_Renderer* renderer)
{
    SDL_Rect UNDOButtonRect = { 810 , 240, 70, 70 };
    SDL_RenderCopy(renderer, UNDOTexture, NULL, &UNDOButtonRect);
}
void drawREPLAYButton(SDL_Renderer* renderer)
{
    SDL_Rect REPLAYButtonRect = { 810 , 340, 70, 70 };
    SDL_RenderCopy(renderer, REPLAYTexture, NULL, &REPLAYButtonRect);
}

void drawM_REPLAYButton(SDL_Renderer* renderer)
{
    SDL_Rect REPLAYButtonRect = { 810 , 240, 70, 70 };
    SDL_RenderCopy(renderer, REPLAYTexture, NULL, &REPLAYButtonRect);
}

void draw_MvsP_REPLAYButton(SDL_Renderer* renderer)
{
    SDL_Rect REPLAYButtonRect = { 550 , 124, 90, 90 };
    SDL_RenderCopy(renderer, REPLAYTexture, NULL, &REPLAYButtonRect);
}

void draw_ARRET_Button(SDL_Renderer* renderer)
{
    SDL_Rect ARRETuttonRect = { 1110 , 550, 70, 70 };
    SDL_RenderCopy(renderer, ARRETTexture, NULL, &ARRETuttonRect);
}

void drawBackButton(SDL_Renderer* renderer)
{
    SDL_Rect backButtonRect = { 10, 10, BACKBUTTON_WIDTH, BACKBUTTON_HEIGHT };
    SDL_RenderCopy(renderer, gBackButtonTexture, NULL, &backButtonRect);
}

void musicONButton(SDL_Renderer* renderer)
{
    SDL_Rect musicONButton = { 10, 10, 70, 70 };
    SDL_RenderCopy(renderer, musicONTexture, NULL, &musicONButton);
}

void musicOFFButton(SDL_Renderer* renderer)
{
    SDL_Rect musicOFFButton = { 10, 10, 70, 70 };
    SDL_RenderCopy(renderer, musicOFFTexture, NULL, &musicOFFButton);
}

void drawUP(SDL_Renderer* renderer)
{
    SDL_Rect UPButtonRect = { 250 , 300, 60, 90 };
    SDL_RenderCopy(renderer, UPTexture, NULL, &UPButtonRect);
}

void drawDOWN(SDL_Renderer* renderer)
{
    SDL_Rect DOWNButtonRect = { 250 , 400, 60, 90 }; // Adjust the position as needed
    SDL_RenderCopy(renderer, DOWNTexture, NULL, &DOWNButtonRect);
}

void drawLEFT(SDL_Renderer* renderer)
{
    SDL_Rect LEFTButtonRect = { 180 , 365, 90, 60 }; // Adjust the position as needed
    SDL_RenderCopy(renderer, LEFTTexture, NULL, &LEFTButtonRect);
}

void drawRIGHT(SDL_Renderer* renderer)
{
    SDL_Rect RIGHTButtonRect = { 290 , 365, 90, 60 }; // Adjust the position as needed
    SDL_RenderCopy(renderer, RIGHTTexture, NULL, &RIGHTButtonRect);
}

void renderMatrix(SDL_Renderer *renderer, TTF_Font *font, int T[MATRIX_SIZE][MATRIX_SIZE]) {
    int padding_x = (WINDOW_WIDTH - (MATRIX_SIZE * CELL_SIZE)) / 2;
    int padding_y = (WINDOW_HEIGHT - (MATRIX_SIZE * CELL_SIZE)) / 2;

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            SDL_Rect cell = {padding_x + j * CELL_SIZE, padding_y + i * CELL_SIZE, CELL_SIZE, CELL_SIZE};

            SDL_Color tile_color = take_tile_color(T[i][j]);
            SDL_SetRenderDrawColor(renderer, tile_color.r, tile_color.g, tile_color.b, tile_color.a);
            SDL_RenderFillRect(renderer, &cell);

            if (T[i][j] != 0) {
                char numText[5];
                snprintf(numText, sizeof(numText), "%d", T[i][j]);

                SDL_Color textColor = {255, 255, 255, 255}; 

                SDL_Surface *textSurface = TTF_RenderText_Solid(font, numText, textColor);
                SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

                int textW, textH;
                SDL_QueryTexture(textTexture, NULL, NULL, &textW, &textH);
                SDL_Rect textRect = {
                    cell.x + (CELL_SIZE - textW) / 2,
                    cell.y + (CELL_SIZE - textH) / 2,
                    textW, textH
                };
                SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

                SDL_FreeSurface(textSurface);
                SDL_DestroyTexture(textTexture);
            }

            int borderThickness = 3; 
            for (int k = 0; k < borderThickness; k++) {
                SDL_Rect borderRect = {cell.x - k, cell.y - k, cell.w + 2 * k, cell.h + 2 * k};
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
                SDL_RenderDrawRect(renderer, &borderRect);
            }
        }
    }
}

void render_2_Matrix(SDL_Renderer *renderer, TTF_Font *font, int T[MATRIX_SIZE][MATRIX_SIZE], int M[MATRIX_SIZE][MATRIX_SIZE]) {

    int padding_x = 75;
    int padding_y = 110;

    int padding_Mx = 765;
    int padding_My = 110;

    int i, j;
    for ( i = 0; i < MATRIX_SIZE; i++) {
        for ( j = 0; j < MATRIX_SIZE; j++) {
 
            SDL_Rect cell = {padding_x + j * CELL_SIZE, padding_y + i * CELL_SIZE, CELL_SIZE, CELL_SIZE};

            SDL_Color tile_color = take_tile_color(T[i][j]);
            SDL_SetRenderDrawColor(renderer, tile_color.r, tile_color.g, tile_color.b, tile_color.a);
            SDL_RenderFillRect(renderer, &cell);

            if (T[i][j] != 0) {
                char numText[5];
                snprintf(numText, sizeof(numText), "%d", T[i][j]);

                SDL_Color textColor = {255, 255, 255, 255}; 

                SDL_Surface *textSurface = TTF_RenderText_Solid(font, numText, textColor);
                SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

                int textW, textH;
                SDL_QueryTexture(textTexture, NULL, NULL, &textW, &textH);
                SDL_Rect textRect = {
                    cell.x + (CELL_SIZE - textW) / 2,
                    cell.y + (CELL_SIZE - textH) / 2,
                    textW, textH
                };
                SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

                SDL_FreeSurface(textSurface);
                SDL_DestroyTexture(textTexture);
            }

            int borderThickness = 3; 
            for (int k = 0; k < borderThickness; k++) {
                SDL_Rect borderRect = {cell.x - k, cell.y - k, cell.w + 2 * k, cell.h + 2 * k};
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
                SDL_RenderDrawRect(renderer, &borderRect);
            }
        }
    }

    for ( i = 0; i < MATRIX_SIZE; i++) {
        for ( j = 0; j < MATRIX_SIZE; j++) {

            SDL_Rect cell = {padding_Mx + j * CELL_SIZE, padding_My + i * CELL_SIZE, CELL_SIZE, CELL_SIZE};

            SDL_Color tile_color = take_tile_color(M[i][j]);
            SDL_SetRenderDrawColor(renderer, tile_color.r, tile_color.g, tile_color.b, tile_color.a);
            SDL_RenderFillRect(renderer, &cell);

            if (M[i][j] != 0) {
                char numText[5];
                snprintf(numText, sizeof(numText), "%d", M[i][j]);

                SDL_Color textColor = {255, 255, 255, 255}; 
                SDL_Surface *textSurface = TTF_RenderText_Solid(font, numText, textColor);
                SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

                int textW, textH;
                SDL_QueryTexture(textTexture, NULL, NULL, &textW, &textH);
                SDL_Rect textRect = {
                    cell.x + (CELL_SIZE - textW) / 2,
                    cell.y + (CELL_SIZE - textH) / 2,
                    textW, textH
                };
                SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                SDL_FreeSurface(textSurface);
                SDL_DestroyTexture(textTexture);
            }
            int borderThickness = 3; 
            for (int k = 0; k < borderThickness; k++) {
                SDL_Rect borderRect = {cell.x - k, cell.y - k, cell.w + 2 * k, cell.h + 2 * k};
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
                SDL_RenderDrawRect(renderer, &borderRect);
            }
        }
    }

}

void drawText(SDL_Renderer *renderer, int x, int y, const char *texte, TTF_Font *police, SDL_Color couleur) {
    SDL_Surface *textSurface = TTF_RenderText_Solid(police, texte, couleur);
    if (!textSurface) {
        printf("Erreur de rendu du texte : %s\n", TTF_GetError());
        return;
    }
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (!textTexture) {
        printf("Erreur de création de texture : %s\n", SDL_GetError());
        SDL_FreeSurface(textSurface);
        return;
    }
    SDL_Rect textRect = {x, y, textSurface->w, textSurface->h};
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}