#include "global.h"
#include "draw.h"
#include "logic.h"
#include "mods.h"
#include "init.h"



int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }
    int mixer_flags = MIX_INIT_MP3;
    if ((Mix_Init(mixer_flags) & mixer_flags) != mixer_flags) {
    fprintf(stderr, "Mixer initialization failed: %s\n", Mix_GetError());
    SDL_Quit();
    return -1;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1048) < 0) {
    fprintf(stderr, "Failed to open audio: %s\n", Mix_GetError());
    Mix_Quit();
    SDL_Quit();
    return -1;
    }

    if (TTF_Init() == -1) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "TTF_Init failed: %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_HIDDEN);
    if (win == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        SDL_DestroyWindow(win);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    TTF_Font *font = TTF_OpenFont("assets/fonts/Ethnocentric Rg.otf", 24);
    if (font == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "TTF_OpenFont Error: %s", TTF_GetError());
        
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(win);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    fontTitle = TTF_OpenFont("assets/fonts/Ethnocentric Rg.otf", 30);
    if (fontTitle == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "TTF_OpenFont Error: %s", TTF_GetError());
        TTF_CloseFont(font);
        
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(win);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    fontInput = TTF_OpenFont("assets/fonts/Arial.ttf", 30);
    if (fontInput == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "TTF_OpenFont Error: %s", TTF_GetError());
        TTF_CloseFont(font);
        TTF_CloseFont(fontTitle);
        
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(win);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    fontMvP = TTF_OpenFont("assets/fonts/Ethnocentric Rg.otf", 26);
    if (fontMvP == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "TTF_OpenFont Error: %s", TTF_GetError());
        TTF_CloseFont(font);
        TTF_CloseFont(fontTitle);
        TTF_CloseFont(fontInput);
        
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(win);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
        {
            printf("IMG_Init Error: %s\n", IMG_GetError());
            TTF_CloseFont(font);
            TTF_CloseFont(fontTitle);
            TTF_CloseFont(fontInput);
            TTF_CloseFont(fontMvP);
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(win);
            TTF_Quit();
            SDL_Quit();
            return 1;
        }
    
    if (loadMedia(renderer) == 0)
    {   
    distroymediamenu();
    TTF_CloseFont(font);
    TTF_CloseFont(fontTitle);
    TTF_CloseFont(fontInput);
    TTF_CloseFont(fontMvP);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    return 1;
    }

    Mix_Music* bgMusic = loadMusic("assets/audio/music.mp3");
    if (bgMusic) {

        Mix_PlayMusic(bgMusic, -1); 
    }
    clickSound = Mix_LoadWAV("assets/audio/button_click.MP3");
    keyboardclick = Mix_LoadWAV("assets/audio/keyboard_clik.MP3");
    YOU_WINsound = Mix_LoadWAV("assets/audio/YOU_WIN.MP3");
    GAME_OVERsound = Mix_LoadWAV("assets/audio/GAME_OVER.MP3");
    PAUSEsound = Mix_LoadWAV("assets/audio/pause.MP3");
    MOVEsound = Mix_LoadWAV("assets/audio/MOUVEsound.mp3");
    machineMOVEsound = Mix_LoadWAV("assets/audio/machineMOVE.MP3");

    SDL_ShowWindow(win);

    int quit = 0;
    Uint32 lastToggle = SDL_GetTicks();
    int showMessage = 1;
    const Uint32 blinkInterval = 900; 

    const char* message = "PRESS ON THE SCREEN TO START THE GAME...";
    SDL_Color textColor = {255, 255, 255, 255}; 
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, message, textColor);
    int textWidth = textSurface->w;
    int textHeight = textSurface->h;
    SDL_FreeSurface(textSurface);
    int textX = (WINDOW_WIDTH - textWidth) / 2;
    int textY = WINDOW_HEIGHT - 200; 

    GameState currentState;

    while (!quit) {
        SDL_Event event;
        

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                currentState = EXIT;
                quit = 1;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                currentState = MAIN_MENU;
                quit = 1;
            }
        }
        Uint32 currentTime = SDL_GetTicks();
        if (currentTime - lastToggle > blinkInterval) {
            showMessage = !showMessage;
            lastToggle = currentTime;
        }

        SDL_RenderClear(renderer);
        
        drawFstPAGE(renderer);
        
        if (showMessage) {
            drawText(renderer, textX, textY+20, message, font, textColor);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(10); 
    }
    int sound = 1;

    GameData gameData;
    SDL_Event e;
    while (currentState != EXIT) {
        
        if(currentState == MAIN_MENU){
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    currentState = EXIT;
                } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                    int x = e.button.x;
                    int y = e.button.y;
                    if (x >= 490 && x <= 708 && y >= 120 && y <= 177) //if you click machine
                    {
                        Mix_PlayChannel(-1, clickSound, 0);
                        printf("PLAYER button clicked!\n");
                        currentState = PLAYER_MENU; 
                    } else if (x >= 490 && x <= 708 && y >= 230 && y <= 287) //if you click player
                    {
                        Mix_PlayChannel(-1, clickSound, 0);
                        printf("MACHINE button clicked!\n");
                        currentState = MACHINE_MODE;
                   
                    }else if(x >= 490 && x <= 708 && y >= 340 && y <= 395) //if you click top players
                    {
                        Mix_PlayChannel(-1, clickSound, 0);
                        printf("machine vs player button clicked!\n");
                        currentState = MACHINE_VS_PLAYER;
                    }else if(x >= 490 && x <= 708 && y >= 450 && y <= 508) //if you click machine vs player
                    {
                        Mix_PlayChannel(-1, clickSound, 0);
                        printf("top players button clicked!\n");
                        currentState = TOP_PLAYERS;
                    }else if(x >= 14 && x <= 76 && y >= 14 && y <= 76) //if you the mute or play sounds
                    {

                        toggleMute(clickSound);
                        if (sound == 1 ){sound = 0; 
                        }else if (sound == 0 ) {sound = 1;}
                    }
                }   
            }
        }
            switch (currentState) {
                    case MAIN_MENU:
                    draw_Menu(renderer, sound);

                    break;
                    case PLAYER_MENU:
                    
                    currentState = PLAY_MENU(renderer,font);
                    break;

                    case CONTINUE:
                    currentState = runPlayerMode(renderer, font, &gameData, 1);
                    break;
                    
                    case NAME_INPUT:
                    strcpy(gameData.NAME, "");
                     currentState = run_entername(renderer, &gameData);
                    break;

                    case PLAYER_MODE:
                    
                    gameData.time=0;
                    currentState = runPlayerMode(renderer, font, &gameData, 0);
                    break;
                    
                    case MACHINE_MODE:
                    
                    currentState = runMachineMode(renderer, font, &gameData);
                    break;
                    case MACHINE_VS_PLAYER:

                    currentState = runMachinevsPlayerMode(renderer,font);
                    break;
                    case TOP_PLAYERS:
                    
                    currentState = topplayers(renderer,font, &gameData);
                    break;
                    default:
                    break;
                }
    
    SDL_Delay(16);
    }
    
    distroymediamenu();
    TTF_CloseFont(font);
    TTF_CloseFont(fontTitle);
    TTF_CloseFont(fontInput);
    TTF_CloseFont(fontMvP);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    return 0;
}