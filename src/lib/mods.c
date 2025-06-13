#include "mods.h"

GameState runPlayerMode(SDL_Renderer *renderer, TTF_Font *font,  GameData *DATA,int MOD) {
    GameState gamover;
    SDL_RenderClear(renderer);
    srand(time(NULL));
    int prevT[MATRIX_SIZE][MATRIX_SIZE] = {{0}};
    int T[MATRIX_SIZE][MATRIX_SIZE] = {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
    };
    place_2_aleatoire(T);
    place_2_aleatoire(T);
    SDL_Rect backButtonRect = { 10, 10, BACKBUTTON_WIDTH, BACKBUTTON_HEIGHT };
    SDL_Rect PAUSEButtonRect = { 810 , 140, 70, 70 };
    SDL_Rect UNDOButtonRect = { 810 , 240, 70, 70 };
    SDL_Rect REPLAYButtonRect = { 810 , 340, 70, 70 };
    int score = 0, prevscore = 0, moved = 0, lose = 0, won = 0, dejawon = 0, undo_available = 0;
    int running = 1, pause = 0, highscore = 0;
    int best_score = getBestHighScore("game_data.txt");
    // for time
    Uint32 startTime = SDL_GetTicks(); // Track when the game starts
    Uint32 elapsedTime = 0 ;            // Total elapsed time in milliseconds
    Uint32 pauseTime = 0;              // Time when the game was paused
    Uint32 savedTime;
    if (MOD == 1){
        loadGame("savegame.dat", DATA->NAME,T,&score,&DATA->highscore,&savedTime);
        startTime = SDL_GetTicks() - savedTime;
        elapsedTime = savedTime;
    }
    SDL_Event eventkey;
    while (running) { 
        while (SDL_PollEvent(&eventkey)) {
            if (eventkey.type == SDL_QUIT) {
                
                return EXIT; 
            } else if (eventkey.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = eventkey.button.x;
                int mouseY = eventkey.button.y;
                if (mouseX >= 1114 && mouseX <= 1176 && mouseY >= 554 && mouseY <= 615) //arret
                    {
                        Mix_PlayChannel(-1, PAUSEsound, 0);
                        saveGameData("game_data.txt", *DATA);
                        saveGame("savegame.dat", DATA->NAME,T,score,DATA->highscore,elapsedTime);
                        return EXIT;
                    }
                if (isRectangleClicked(backButtonRect, mouseX, mouseY)) {
                    
                    Mix_PlayChannel(-1, clickSound, 0);
                    saveGameData("game_data.txt", *DATA);
                    saveGame("savegame.dat", DATA->NAME,T,score,DATA->highscore,elapsedTime);
                    return MAIN_MENU;
                }
                if (isRectangleClicked(PAUSEButtonRect, mouseX, mouseY)) {
                    Mix_PlayChannel(-1, PAUSEsound, 0);
                    if (!pause) {
                        pause = 1;
                        pauseTime = SDL_GetTicks(); 
                    } else {
                        pause = 0;
                        startTime += SDL_GetTicks() - pauseTime; 
                    }
                }
                if (isRectangleClicked(REPLAYButtonRect, mouseX, mouseY)) {
                    Mix_PlayChannel(-1, PAUSEsound, 0);
                    empty_matrix(T);
                    place_2_aleatoire(T);
                    place_2_aleatoire(T);
                    empty_matrix(prevT);
                    score = 0;
                    prevscore = 0;
                    won = 0;
                    dejawon = 0;
                    lose = 0;
                    undo_available = 0;
                    startTime = SDL_GetTicks();
                    elapsedTime = 0;
                }
                if (undo_available) {
                    if (isRectangleClicked(UNDOButtonRect, mouseX, mouseY)) {
                        Mix_PlayChannel(-1, PAUSEsound, 0);
                        printf("Undo pressed\n");
                        undo(T, prevT, &score, prevscore, &undo_available);
                        continue;
                    }
                }
                if(!pause){
                    moved = 0;
                if (mouseX >= 265 && mouseX <= 295 && mouseY >= 308 && mouseY <= 383) {
                    //UP
                    Mix_PlayChannel(-1, MOVEsound, 0);
                    move_up(T, &moved, &score, prevT, &prevscore, &won, &lose, &dejawon);
                } else if (mouseX >= 297 && mouseX <= 372 && mouseY >= 380 && mouseY <= 410) {
                    //RIGHT
                    Mix_PlayChannel(-1, MOVEsound, 0);
                    move_right(T, &moved, &score, prevT, &prevscore, &won, &lose, &dejawon);
                } else if (mouseX >= 188 && mouseX <= 263 && mouseY >= 380 && mouseY <= 410) {
                    //LEFT
                    Mix_PlayChannel(-1, MOVEsound, 0);
                    move_left(T, &moved, &score, prevT, &prevscore, &won, &lose, &dejawon);
                } else if (mouseX >= 265 && mouseX <= 295 && mouseY >= 407 && mouseY <= 482) {
                    //DOWN
                    Mix_PlayChannel(-1, MOVEsound, 0);
                    move_down(T, &moved, &score, prevT, &prevscore, &won, &lose, &dejawon);
                }
                if (moved) {
                    place_2_aleatoire(T);
                    undo_available = 1;
                }
                }
                if (if_moves_left(T) == 0) {
                lose = 1;
                }
                }else if (eventkey.type == SDL_KEYDOWN) {
                //continue
                if (won) {
                    
                    if (eventkey.key.keysym.sym == SDLK_ESCAPE) {
                        
                        return MAIN_MENU; 
                    } else if (eventkey.key.keysym.sym == SDLK_c) {
                        won = 0;
                    }
                    continue;
                }
            if(!pause){
                moved = 0;
                switch (eventkey.key.keysym.sym) {
                    case SDLK_UP:
                        Mix_PlayChannel(-1, MOVEsound, 0);
                        move_up(T, &moved, &score, prevT, &prevscore, &won, &lose, &dejawon);
                        break;
                    case SDLK_DOWN:
                        Mix_PlayChannel(-1, MOVEsound, 0);
                        move_down(T, &moved, &score, prevT, &prevscore, &won, &lose, &dejawon);
                        break;
                    case SDLK_LEFT:
                        Mix_PlayChannel(-1, MOVEsound, 0);
                        move_left(T, &moved, &score, prevT, &prevscore, &won, &lose, &dejawon);
                        break;
                    case SDLK_RIGHT:
                        Mix_PlayChannel(-1, MOVEsound, 0);
                        move_right(T, &moved, &score, prevT, &prevscore, &won, &lose, &dejawon);
                        break;
                    default:
                        break;
                }
                if (moved) {
                    place_2_aleatoire(T);
                    undo_available = 1;
                }
            }
                if (if_moves_left(T) == 0) {
                lose = 1;
                }
            }
        }
        if (!pause && !won) {
        elapsedTime = SDL_GetTicks() - startTime; // Update elapsed time
        }
        
        if (score > DATA->highscore)
        {
            DATA->highscore = score;
            highscore = score;
            DATA->time = elapsedTime;
        }

        if (score > best_score)
        {
            best_score = score;
        }

        if (lose == 1) {
                    Mix_PlayChannel(-1, GAME_OVERsound, 0);
                    gamover = drawGameOverScreen(renderer, font,score,elapsedTime, *DATA);
                    if(gamover == EXIT){
                    return EXIT;
                    }else if (gamover == REPLAY)
                    {
                        empty_matrix(T);
                        place_2_aleatoire(T);
                        place_2_aleatoire(T);
                        empty_matrix(prevT);
                        score = 0;
                        prevscore = 0;
                        won = 0;
                        dejawon = 0;
                        lose = 0;
                        undo_available = 0;
                        
                        // Reset the timer
                        startTime = SDL_GetTicks();
                        elapsedTime = 0;
                    }else if (gamover == SAVE_QUIT){
                        saveGameData("game_data.txt", *DATA);
                        saveGame("savegame.dat", DATA->NAME,T,score,DATA->highscore,elapsedTime);
                        return MAIN_MENU;
                    }else if(gamover == ARRET){
                        saveGameData("game_data.txt", *DATA);
                        saveGame("savegame.dat", DATA->NAME,T,score,DATA->highscore,elapsedTime);
                        return EXIT;
                    }
                }
        if (won == 1) {
                    Mix_PlayChannel(-1, YOU_WINsound, 0);
                    gamover = drawYOUWIN(renderer, font,score,elapsedTime, *DATA);
                    if(gamover == EXIT){
                    return EXIT;
                    }else if (gamover == CONTINUE)
                    {
                        won = 0;
                        startTime = SDL_GetTicks() - elapsedTime;
                    }else if (gamover == SAVE_QUIT){
                        saveGameData("game_data.txt", *DATA);
                        saveGame("savegame.dat", DATA->NAME,T,score,DATA->highscore,elapsedTime);
                        return MAIN_MENU;
                    }else if(gamover == ARRET){
                        saveGameData("game_data.txt", *DATA);
                        saveGame("savegame.dat", DATA->NAME,T,score,DATA->highscore,elapsedTime);
                        return EXIT;
                    }
                }           
        SDL_RenderCopy(renderer, gBackgroundTexture, NULL, NULL);
        SDL_Rect timeRect = { (WINDOW_WIDTH - TIME_WIDTH) / 2, 10, TIME_WIDTH, TIME_HEIGHT };
        SDL_RenderCopy(renderer, gtimeTexture, NULL, &timeRect); 
        renderMatrix(renderer,font, T);
        drawBackButton(renderer);
        if(!pause){
        drawPAUSEButton(renderer);
        } else {
        drawRESUMEButton(renderer);}
        
        drawREPLAYButton(renderer);
        drawUNDOButton(renderer);
        draw_ARRET_Button(renderer);

        drawUP(renderer);
        drawRIGHT(renderer);
        drawLEFT(renderer);
        drawDOWN(renderer);
        // Draw the timer
        char timerText[20];
        snprintf(timerText, sizeof(timerText), "%02d:%02d", elapsedTime / 60000, (elapsedTime / 1000) % 60);
        drawText(renderer, 560, 35, timerText, fontMvP, white);
        // Draw the name
        char NAME[35];
        snprintf(NAME, sizeof(NAME), "NAME : %s", DATA->NAME);
        drawText(renderer, 50, 100, NAME, font, white);    
        // Draw the score
        char scoreText[20];
        snprintf(scoreText, sizeof(scoreText), "Score : %d", score);
        drawText(renderer, 50, 150, scoreText, font, white);
        // Draw the highscore
        char highscoreText[20];
        snprintf(highscoreText, sizeof(highscoreText), "HighScore : %d", DATA->highscore);
        drawText(renderer, 50, 200, highscoreText, font, white);
        // Draw best score
        char bestscoreText[20];
        snprintf(scoreText, sizeof(scoreText), "BEST SCORE : %d", best_score);
        drawText(renderer, 850, 100, scoreText, font, white);

        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }
    return EXIT; 
}

GameState run_entername(SDL_Renderer *renderer,GameData *DATA) {

    SDL_Rect backButtonRect = { 10, 10, BACKBUTTON_WIDTH, BACKBUTTON_HEIGHT };

    int rectWidth = 800, rectHeight = 300; 
    int rectX = (1200 - rectWidth) / 2; 
    int rectY = (650 - rectHeight) / 2;
    int inputRectWidth = 600, inputRectHeight = 70; 
    int inputRectX = rectX + (rectWidth - inputRectWidth) / 2; 
    int inputRectY = rectY + 130; 

    SDL_Rect GameRect = {rectX, rectY, rectWidth, rectHeight};

    char inputText[35] = ""; 
    int cursorPosition = 0; 
    int showError = 0; 

    int showCursor = 1;
    Uint32 cursorTimer = SDL_GetTicks();

    int textHeight = 0;
    TTF_SizeText(fontInput, "A", NULL, &textHeight); 

    int running = 1;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return EXIT;
            } else if (event.type == SDL_TEXTINPUT) {
                if (strlen(inputText) < 34) {
                    Mix_PlayChannel(-1, keyboardclick, 0);
                    memmove(&inputText[cursorPosition + 1], &inputText[cursorPosition], strlen(inputText) - cursorPosition + 1);
                    inputText[cursorPosition] = event.text.text[0];
                    cursorPosition++;
                    showError = 0; 
                } else {
                    showError = 1; 
                }
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_BACKSPACE && cursorPosition > 0) {
                    Mix_PlayChannel(-1, keyboardclick, 0);
                    memmove(&inputText[cursorPosition - 1], &inputText[cursorPosition], strlen(inputText) - cursorPosition + 1);
                    cursorPosition--;

                    if (strlen(inputText) <= 34) {
                        showError = 0;
                    }
                } else if (event.key.keysym.sym == SDLK_LEFT && cursorPosition > 0) {
                    cursorPosition--;
                } else if (event.key.keysym.sym == SDLK_RIGHT && cursorPosition < strlen(inputText)) {
                    cursorPosition++;
                }else if (event.key.keysym.sym == SDLK_RETURN) {
                    Mix_PlayChannel(-1, clickSound, 0);
                    strncpy(DATA->NAME, inputText, 34);
                    DATA->NAME[35] = '\0'; //kant 35
                
                
                FILE *file = fopen("game_data.txt", "r"); 
                if (file != NULL) {
                    char line[256];
                    int found = 0;
                    while (fgets(line, sizeof(line), file)) {
                        char name[35];
                        int highscore;
                        Uint32 time;
                        if (sscanf(line, "%34[^,],%d,%u", name, &highscore, &time) == 3) {
                            if (strcmp(name, DATA->NAME) == 0) {
                                DATA->highscore = highscore; 
                                found = 1;
                                break;
                            }
                        }
                    }
                    fclose(file);
                    if (found == 0) {
                        DATA->highscore = 0; 
                    }
                } else {
                    DATA->highscore = 0; 
                }                   
                    DATA->time = 0;
                    return PLAYER_MODE;
                }
            }else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = event.button.x;
                int mouseY = event.button.y;

                if (isRectangleClicked(backButtonRect, mouseX, mouseY)) {
                    Mix_PlayChannel(-1, clickSound, 0);
                    return MAIN_MENU;
                }
            }
        }

        if (SDL_GetTicks() - cursorTimer > 500) {
            showCursor = !showCursor;
            cursorTimer = SDL_GetTicks();
        }

        SDL_RenderClear(renderer);

        
        SDL_RenderCopy(renderer, gblurrBackgroundTexture, NULL, NULL);
        
        drawBackButton(renderer);

        drawGradientRect(renderer, GameRect, Blue, Pink, 4);

        SDL_Surface *textSurface = TTF_RenderText_Solid(fontTitle, "Enter your name:", white);
        if (textSurface) {
            SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            if (textTexture) {
                SDL_Rect textRect = {rectX + (rectWidth - textSurface->w) / 2, rectY + 60, textSurface->w, textSurface->h}; // Déplacer le texte vers le haut
                SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                SDL_DestroyTexture(textTexture);
            }
            SDL_FreeSurface(textSurface);
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); 
        SDL_Rect inputRect = {inputRectX, inputRectY, inputRectWidth, inputRectHeight};
        SDL_RenderDrawRect(renderer, &inputRect);

        if (strlen(inputText) > 0) {
            SDL_Surface *inputSurface = TTF_RenderText_Solid(fontInput, inputText, white);
            if (inputSurface) {
                SDL_Texture *inputTexture = SDL_CreateTextureFromSurface(renderer, inputSurface);
                if (inputTexture) {
                    if (inputSurface->w > inputRectWidth - 20) { 
                        inputSurface->w = inputRectWidth - 20;

                    }
                    int textX = inputRectX + 10;
                    int textY = inputRectY + (inputRectHeight - inputSurface->h) / 2;
                    SDL_Rect inputTextRect = {textX, textY, inputSurface->w, inputSurface->h};
                    SDL_RenderCopy(renderer, inputTexture, NULL, &inputTextRect);
                    SDL_DestroyTexture(inputTexture);
                }
                SDL_FreeSurface(inputSurface);
            }
        }

        if (showCursor) {
            char cursorText[35];
            strncpy(cursorText, inputText, cursorPosition);
            cursorText[cursorPosition] = '\0';

            int textWidth = 0;
            TTF_SizeText(fontInput, cursorText, &textWidth, NULL);

            int cursorX = inputRectX + 10 + textWidth;
            
            int cursorY = inputRectY + (inputRectHeight - textHeight) / 2;

            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_Rect cursorRect = {cursorX, cursorY, 2, textHeight};
            SDL_RenderFillRect(renderer, &cursorRect);
        }

        if (showError) {
            SDL_Surface *errorSurface = TTF_RenderText_Solid(fontInput, "Username is too long!", white);
            if (errorSurface) {
                SDL_Texture *errorTexture = SDL_CreateTextureFromSurface(renderer, errorSurface);
                if (errorTexture) {
                    SDL_Rect errorRect = {inputRectX + 130, inputRectY + inputRectHeight + 10, errorSurface->w, errorSurface->h};
                    SDL_RenderCopy(renderer, errorTexture, NULL, &errorRect);
                    SDL_DestroyTexture(errorTexture);
                }
                SDL_FreeSurface(errorSurface);
            }
        }

        SDL_RenderPresent(renderer);
    }
    return EXIT;
}

GameState drawGameOverScreen(SDL_Renderer* renderer, TTF_Font *font,int score,Uint32 time, GameData gameData)
{

    SDL_RenderClear(renderer);
    int running = 1;
    SDL_Event event;

    SDL_Rect gGOBackgroundRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
    SDL_RenderCopy(renderer, gGOBackgroundTexture, NULL, &gGOBackgroundRect);

        // Draw the score
        char scoreText[20];
        snprintf(scoreText, sizeof(scoreText), "%d", score);
        drawText(renderer, 180, 72, scoreText, font, white);

        // Draw the timer
        char timerText[20];
        snprintf(timerText, sizeof(timerText), "%02d:%02d", time/ 60000, (time / 1000) % 60);
        drawText(renderer, 965, 30, timerText, font, white);

        // Draw the highscore
        char highscoreText[20];
        snprintf(highscoreText, sizeof(highscoreText), "%d", gameData.highscore);
        drawText(renderer, 275, 25, highscoreText, font, white);

    SDL_Rect replayRect = { (WINDOW_WIDTH - GAMEOVERBUTTON_WIDTH) / 2, (WINDOW_HEIGHT - GAMEOVERBUTTON_HEIGHT) / 2 - 20, GAMEOVERBUTTON_WIDTH, GAMEOVERBUTTON_HEIGHT };
    SDL_RenderCopy(renderer, gReplayTexture, NULL, &replayRect);

    SDL_Rect exitRect = { (WINDOW_WIDTH - GAMEOVERBUTTON_WIDTH) / 2, (WINDOW_HEIGHT - GAMEOVERBUTTON_HEIGHT) / 2 + 58, GAMEOVERBUTTON_WIDTH, GAMEOVERBUTTON_HEIGHT };
    SDL_RenderCopy(renderer, gExitTexture, NULL, &exitRect);
    SDL_RenderPresent(renderer);
    while (running)
    {

        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                SDL_RenderClear(renderer);
                return EXIT;
            }else if (event.type == SDL_MOUSEBUTTONDOWN) {
                    int x = event.button.x;
                    int y = event.button.y;
                    if (isRectangleClicked(replayRect, x, y)) //if you click replay
                    {
                        Mix_PlayChannel(-1, clickSound, 0);
                        SDL_RenderClear(renderer);
                        return REPLAY;
                    } else if (isRectangleClicked(exitRect, x, y)) //if you click exit
                    {
                        Mix_PlayChannel(-1, clickSound, 0);
                        SDL_RenderClear(renderer);
                        return SAVE_QUIT;
                    }
                }   
        }
    }
    SDL_RenderClear(renderer);
    return EXIT;
}

GameState drawYOUWIN(SDL_Renderer* renderer, TTF_Font *font,int score,Uint32 time, GameData gameData)
{
    SDL_RenderClear(renderer);
    int running = 1;
    SDL_Event event;
    SDL_Rect YOUWINRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
    SDL_RenderCopy(renderer, YOUWINBackgroundTexture, NULL, &YOUWINRect);
        char scoreText[20];
        snprintf(scoreText, sizeof(scoreText), "%d", score);
        drawText(renderer, 180, 72, scoreText, font, white);

        // Draw the timer
        char timerText[20];
        snprintf(timerText, sizeof(timerText), "%02d:%02d", time/ 60000, (time / 1000) % 60);
        drawText(renderer, 965, 30, timerText, font, white);

        // Draw the highscore
        char highscoreText[20];
        snprintf(highscoreText, sizeof(highscoreText), "%d", gameData.highscore);
        drawText(renderer, 275, 25, highscoreText, font, white);

    SDL_Rect continueRect = { (WINDOW_WIDTH - GAMEOVERBUTTON_WIDTH) / 2, (WINDOW_HEIGHT - GAMEOVERBUTTON_HEIGHT) / 2 - 20, GAMEOVERBUTTON_WIDTH, GAMEOVERBUTTON_HEIGHT };
    SDL_RenderCopy(renderer, continueTexture, NULL, &continueRect);

    SDL_Rect exitRect = { (WINDOW_WIDTH - GAMEOVERBUTTON_WIDTH) / 2, (WINDOW_HEIGHT - GAMEOVERBUTTON_HEIGHT) / 2 + 58, GAMEOVERBUTTON_WIDTH, GAMEOVERBUTTON_HEIGHT };
    SDL_RenderCopy(renderer, gExitTexture, NULL, &exitRect);

    SDL_RenderPresent(renderer);
    
    while (running)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                SDL_RenderClear(renderer);
                return EXIT;
            }else if (event.type == SDL_MOUSEBUTTONDOWN) {
                    int x = event.button.x;
                    int y = event.button.y;
                    if (isRectangleClicked(continueRect, x, y)) //if you click continue
                    {
                        Mix_PlayChannel(-1, clickSound, 0);
                        SDL_RenderClear(renderer);
                        return CONTINUE;
                    } else if (isRectangleClicked(exitRect, x, y)) //if you click exit
                    {
                        Mix_PlayChannel(-1, clickSound, 0);
                        SDL_RenderClear(renderer);
                        return SAVE_QUIT;
                    }
                }   
        }
    }
    SDL_RenderClear(renderer);
    return EXIT;
}

GameState runMachineMode(SDL_Renderer *renderer, TTF_Font *font,  GameData *gameData) {
    SDL_RenderClear(renderer);
    srand(time(NULL));
    int T[4][4] = {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
    };
    place_2_aleatoire(T);
    place_2_aleatoire(T);
    
    SDL_Rect PAUSEButtonRect = { 810 , 140, 70, 70 };
    SDL_Rect REPLAYButtonRect = { 810 , 240, 70, 70 };

    SDL_Rect backButtonRect = { 10, 10, BACKBUTTON_WIDTH, BACKBUTTON_HEIGHT };
    ARR_DIRECTION Direction = NONE;
    int running = 1;
    SDL_Event event;
    int score = 0, pause = 0, gameover = 0;

    Uint32 lastMoveTime = SDL_GetTicks(); // Track the time of the last move
    Uint32 moveInterval = 1000; // Interval between moves in milliseconds (0.5 seconds)

    Uint32 startTime = SDL_GetTicks();
    Uint32 elapsedTime = 0;

    Uint32 pauseTime = 0;              // Time when the game was paused
    Uint32 lastArrowDrawTime = SDL_GetTicks(); // Tracks when the arrows were last displayed
    int showArrows = 1; // Boolean flag to determine if arrows should be shown

    while (running) {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) {
                
                return EXIT;
            }else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = event.button.x;
                int mouseY = event.button.y;

                if (isRectangleClicked(backButtonRect, mouseX, mouseY)) {
                    Mix_PlayChannel(-1, clickSound, 0);
                    return MAIN_MENU;
                }
                if (isRectangleClicked(PAUSEButtonRect, mouseX, mouseY)) {
                    Mix_PlayChannel(-1, PAUSEsound, 0);
                    if (!pause) {
                        pause = 1;
                        pauseTime = SDL_GetTicks(); 
                    } else {
                        pause = 0;
                        startTime += SDL_GetTicks() - pauseTime; 
                    }
                }
                if (isRectangleClicked(REPLAYButtonRect, mouseX, mouseY)) {
                    Mix_PlayChannel(-1, PAUSEsound, 0);
                    empty_matrix(T);
                    place_2_aleatoire(T);
                    place_2_aleatoire(T);
                    score = 0;
                    startTime = SDL_GetTicks();
                    elapsedTime = 0;
                }
            }
        }
        
        if(!pause){
        int has_2048 = 0;
        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0; j < MATRIX_SIZE; j++) {
                if (T[i][j] == 2048) {
                    has_2048 = 1;
                    break;
                }
            }
        }

        if (elapsedTime - lastMoveTime >= moveInterval) {
        lastMoveTime = elapsedTime;  // Update the last move time
        // Machine makes a move
        int best_move = machine_move(T, score);
        int move_made = 0;
        switch (best_move) {
            case 0: // Up
                Mix_PlayChannel(-1, machineMOVEsound, 0);
                move_upM(T, &move_made, &score);
                Direction = UP;
                break;
            case 1: // Right
                Mix_PlayChannel(-1, machineMOVEsound, 0);
                move_rightM(T, &move_made, &score);
                Direction = RIGHT;
                break;
            case 2: // Down
                Mix_PlayChannel(-1, machineMOVEsound, 0);
                move_downM(T, &move_made, &score);
                Direction = DOWN;
                break;
            case 3: // Left
                Mix_PlayChannel(-1, machineMOVEsound, 0);
                move_leftM(T, &move_made, &score);
                Direction = LEFT;
                break;
        }
        
        place_2_aleatoire(T);
        lastArrowDrawTime = SDL_GetTicks();
        showArrows = 1;
        }
        elapsedTime = SDL_GetTicks() - startTime;
        }
        
        SDL_RenderCopy(renderer, gBackgroundTexture, NULL, NULL);

        SDL_Rect timeRect = { (WINDOW_WIDTH - TIME_WIDTH) / 2, 10, TIME_WIDTH, TIME_HEIGHT };
        SDL_RenderCopy(renderer, gtimeTexture, NULL, &timeRect);

        // Draw the timer
        char timerText[20];
        snprintf(timerText, sizeof(timerText), "%02d:%02d", elapsedTime / 60000, (elapsedTime / 1000) % 60);
        drawText(renderer, 560, 35, timerText, fontMvP, white);

        drawBackButton(renderer);
        renderMatrix(renderer,font, T);
        if (if_moves_left(T)) {
        if (showArrows && SDL_GetTicks() - lastArrowDrawTime < 500) {
            switch (Direction)
            {
            case UP:
                drawUP(renderer);
                break;
            case RIGHT:
                drawRIGHT(renderer);
                break;
            case LEFT:
                drawLEFT(renderer);
                break;
            case DOWN:
                drawDOWN(renderer);
                break;
            default:
                break;
            }
        }else {
        showArrows = 0; // Stop showing arrows after 0.5 seconds
        }
        }
        
        if(!pause){
        drawPAUSEButton(renderer);
        } else {
        drawRESUMEButton(renderer);;}

        drawM_REPLAYButton(renderer);
        // Draw the score
        char scoreText[20];
        snprintf(scoreText, sizeof(scoreText), "Score : %d", score);
        drawText(renderer, 50, 100, scoreText, font, white);

        SDL_RenderPresent(renderer);

        SDL_RenderClear(renderer);
        
    }
    
    return MAIN_MENU;
}

GameState runMachinevsPlayerMode(SDL_Renderer *renderer, TTF_Font *font){
    SDL_RenderClear(renderer);
    srand(time(NULL));
    int T[4][4] = {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
    };
    int M[4][4] = {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
    };
    place_2_aleatoire(T);
    place_2_aleatoire(T);
    place_2_aleatoire(M);
    place_2_aleatoire(M);
    
    //react for the back button
    SDL_Rect backButtonRect = { 10, 10, BACKBUTTON_WIDTH, BACKBUTTON_HEIGHT };
    SDL_Rect REPLAYRect = { 550 , 124, 90, 90 };
    int player_won = 0, machine_won = 0, gameOver = 0;

    char message[20];
    int running = 1;
    SDL_Event event;
    int moved;
    int score = 0;
    int Machinescore = 0;
    Uint32 startTime = SDL_GetTicks();
    Uint32 elapsedTime = 0;

    Uint32 lastMoveTime = SDL_GetTicks(); // Track the time of the last move
    Uint32 moveInterval = 1000; // Interval between moves in milliseconds (1 seconds)

    while (running) {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) {
                
                return EXIT;
            }else if (event.type == SDL_KEYDOWN) { 

                if(!gameOver){
                moved = 0;
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        Mix_PlayChannel(-1, MOVEsound, 0);
                        move_upM(T, &moved, &score);
                        break;
                    case SDLK_DOWN:
                        Mix_PlayChannel(-1, MOVEsound, 0);
                        move_downM(T, &moved, &score);
                        break;
                    case SDLK_LEFT:
                        Mix_PlayChannel(-1, MOVEsound, 0);
                        move_leftM(T, &moved, &score);
                        break;
                    case SDLK_RIGHT:
                        Mix_PlayChannel(-1, MOVEsound, 0);
                        move_rightM(T, &moved, &score);
                        break;
                    default:
                        break;
                }
                if (moved) {
                    place_2_aleatoire(T);
                }
                }        
            }else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = event.button.x;
                int mouseY = event.button.y;

                if (isRectangleClicked(backButtonRect, mouseX, mouseY)) {
                    Mix_PlayChannel(-1, clickSound, 0);
                    return MAIN_MENU;
                }
                if (isRectangleClicked(REPLAYRect, mouseX, mouseY)) {
                    Mix_PlayChannel(-1, PAUSEsound, 0);
                    empty_matrix(T);
                    place_2_aleatoire(T);
                    place_2_aleatoire(T);
                    empty_matrix(M);
                    place_2_aleatoire(M);
                    place_2_aleatoire(M);
                    score = 0;
                    Machinescore = 0;
                    player_won = 0;
                    machine_won = 0;
                    gameOver = 0;
                    // Reset the timer
                    startTime = SDL_GetTicks();
                    elapsedTime = 0;
                }
            }

        }

        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0; j < MATRIX_SIZE; j++) {
                if (T[i][j] == 2048) {
                    player_won = 1;
                    gameOver = 1;
                    break;
                }
            }
        }

        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0; j < MATRIX_SIZE; j++) {
                if (M[i][j] == 2048) {
                    machine_won = 1;
                    gameOver = 1;
                    break;
                }
            }
        }

        if (player_won) {
            snprintf(message, sizeof(message), "%s", "YOU WIN!");
        }
        if (machine_won) {
            snprintf(message, sizeof(message), "%s", "YOU LOST!");
        }

        if (!if_moves_left(T) && !if_moves_left(M)) {
            gameOver = 1; // Stop the timer
            if(player_won == 0 && machine_won == 0){
                if (Machinescore > score)
                {
                    snprintf(message, sizeof(message), "%s", "YOU LOST!");
                }else{
                    snprintf(message, sizeof(message), "%s", "YOU WIN!");
                }
            }
        }

        if(!gameOver){
        if (elapsedTime - lastMoveTime >= moveInterval) {
        lastMoveTime = elapsedTime; // Update the last move time
        if(if_moves_left(M)){
         // Machine makes a move
        int best_move = machine_move(M, Machinescore);
                // Apply the best move for machine
        int move_made = 0;
        switch (best_move) {
            case 0: // Up
                Mix_PlayChannel(-1, machineMOVEsound, 0);
                move_upM(M, &move_made, &Machinescore);
                break;
            case 1: // Right
                Mix_PlayChannel(-1, machineMOVEsound, 0);
                move_rightM(M, &move_made, &Machinescore);
                break;
            case 2: // Down
                Mix_PlayChannel(-1, machineMOVEsound, 0);
                move_downM(M, &move_made, &Machinescore);
                break;
            case 3: // Left
                Mix_PlayChannel(-1, machineMOVEsound, 0);
                move_leftM(M, &move_made, &Machinescore);
                break;
        }
            place_2_aleatoire(M);
        }
        }
        elapsedTime = SDL_GetTicks() - startTime;
        }
        
        draw_machinevsplayer(renderer); 
        render_2_Matrix(renderer, font, T, M); 
        drawBackButton(renderer);
        
        // Draw the timer
        char timerText[20];
        snprintf(timerText, sizeof(timerText), "%02d:%02d", elapsedTime / 60000, (elapsedTime / 1000) % 60);
        drawText(renderer, 560, 35, timerText, fontMvP, white);

        // Draw the score
        char scoreText[20];
        snprintf(scoreText, sizeof(scoreText), "%d", score);
        drawText(renderer, 150, 535, scoreText, fontMvP, white);

        draw_MvsP_REPLAYButton(renderer);
        // Draw the score
        char machinescoreText[20];
        snprintf(machinescoreText, sizeof(machinescoreText), "%d", Machinescore);
        drawText(renderer, 900, 535, machinescoreText, fontMvP, white);

        if (gameOver)
        {
            drawText(renderer, 510, 500, message, fontMvP, white);
        }
    
        SDL_RenderPresent(renderer);
    }
}

GameState PLAY_MENU(SDL_Renderer *renderer, TTF_Font *font) {
    
    SDL_Rect backButtonRect = { 10, 10, BACKBUTTON_WIDTH, BACKBUTTON_HEIGHT };
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_RenderCopy(renderer, gblurrBackgroundTexture, NULL, NULL);
    
    SDL_Rect newGameRect = {400, 200, 400, 100};
    SDL_Rect continueRect = {400, 350, 400, 100};

    drawGradientRect(renderer, newGameRect, Blue, Pink, 4);
    drawGradientRect(renderer, continueRect, Blue, Pink, 4);

    drawBackButton(renderer);

    SDL_Color textColor = {255, 255, 255, 255}; 

    drawText(renderer,510,237,"NEW GAME", font, textColor);
    drawText(renderer,518,387,"CONTINUE", font, textColor);

    SDL_RenderPresent(renderer);
    SDL_Event e;
    int running=1;
while (running)
{
    while (SDL_WaitEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    return EXIT;
                } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                    int x = e.button.x;
                    int y = e.button.y;
                    if (x >= newGameRect.x && x <= newGameRect.x + newGameRect.w &&
                    y >= newGameRect.y && y <= newGameRect.y + newGameRect.h) {
                    Mix_PlayChannel(-1, clickSound, 0);
                    return NAME_INPUT; // New Game pressed
                    }else if (x >= continueRect.x && x <= continueRect.x + continueRect.w &&
                    y >= continueRect.y && y <= continueRect.y + continueRect.h) {
                    Mix_PlayChannel(-1, clickSound, 0);
                    return CONTINUE; // Continue pressed
                    }else if (isRectangleClicked(backButtonRect, x, y)) {
                        Mix_PlayChannel(-1, clickSound, 0);
                        return MAIN_MENU;
                    }   
                }
    SDL_Delay(16); 
    }
}

return EXIT;
}

GameState topplayers(SDL_Renderer *renderer, TTF_Font *font, GameData *gameData) {
    SDL_RenderClear(renderer);
    GameData players[100];
    int count = 0;

    FILE *file = fopen("game_data.txt", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char name[35];
        int score;
        unsigned int time;
        
        if (sscanf(line, "%[^,],%d,%u", name, &score, &time) == 3) {
            int found = 0;
            for (int i = 0; i < count; i++) {
                if (strcmp(players[i].NAME, name) == 0) {
                    if (score > players[i].highscore) {
                        players[i].highscore = score;
                        players[i].time = time;
                    }
                    found = 1;
                    break;
                }
            }
            if (!found && count < 100) {
                strncpy(players[count].NAME, name, sizeof(players[count].NAME) - 1);
                players[count].NAME[sizeof(players[count].NAME) - 1] = '\0';
                players[count].highscore = score;
                players[count].time = time;
                count++;
            }
        }
    }
    fclose(file);

    qsort(players, count, sizeof(GameData), compareScores);
     int yOffset = 170; 
    int lineHeight = 70; 
    
    int running = 1;
    SDL_Rect backButtonRect = { 10, 10, BACKBUTTON_WIDTH, BACKBUTTON_HEIGHT };
    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT ) {
                return EXIT; 
            }else if (event.type == SDL_KEYDOWN) { 
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        Mix_PlayChannel(-1, clickSound, 0);
                        return MAIN_MENU; 
                    }
            }else if (event.type == SDL_MOUSEBUTTONDOWN) {
                
                int mouseX = event.button.x;
                int mouseY = event.button.y;

                if (isRectangleClicked(backButtonRect, mouseX, mouseY)) {
                    Mix_PlayChannel(-1, clickSound, 0);
                    return MAIN_MENU;
                }
            }
        }
        drawleaderboard(renderer);
        drawBackButton(renderer);

        for (int i = 0; i < count && i < 5; i++) {
        char playerText[100];
        snprintf(playerText, sizeof(playerText), "%d. %s - Score: %d - Time: %02u:%02u", 
                 i + 1, players[i].NAME, players[i].highscore, 
                 players[i].time / 60000, (players[i].time / 1000) % 60);

        drawText(renderer, 200, yOffset + i * lineHeight, playerText, font, white);
        }

        SDL_RenderPresent(renderer);
    }
    return EXIT;
}

int isRectangleClicked(SDL_Rect rect, int mouseX, int mouseY) {
    return (mouseX >= rect.x && mouseX <= rect.x + rect.w &&
            mouseY >= rect.y && mouseY <= rect.y + rect.h);

}