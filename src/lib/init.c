#include "init.h"


int compareScores(const void *a, const void *b) {
    GameData *playerA = (GameData *)a;
    GameData *playerB = (GameData *)b;
    return playerB->highscore - playerA->highscore;
}

void distroymediamenu()
{

    SDL_DestroyTexture(gBackgroundTexture);
    SDL_DestroyTexture(gblurrBackgroundTexture);

    SDL_DestroyTexture(gPlayerTexture);
    SDL_DestroyTexture(gMachineTexture);
    SDL_DestroyTexture(gMachineVsPlayerTexture);
    SDL_DestroyTexture(gtopplayersTexture);

    SDL_DestroyTexture(gBackgroundTextureTP);
    SDL_DestroyTexture(gRectTexture);
    SDL_DestroyTexture(gBackButtonTexture);

    //buttons
    SDL_DestroyTexture(gReplayTexture);
    SDL_DestroyTexture(UNDOTexture);
    SDL_DestroyTexture(PAUSETexture);
    SDL_DestroyTexture(ARRETTexture);

    SDL_DestroyTexture(gGOBackgroundTexture);
    SDL_DestroyTexture(gExitTexture);
    SDL_DestroyTexture(gReplayTexture);

    //machine vs p
    SDL_DestroyTexture(gtimeTexture);
    SDL_DestroyTexture(gmachineiconTexture);
    SDL_DestroyTexture(gplayericonTexture);
    //arrows
    SDL_DestroyTexture(UPTexture);
    SDL_DestroyTexture(RIGHTTexture);
    SDL_DestroyTexture(LEFTTexture);
    SDL_DestroyTexture(DOWNTexture);

}

int loadMedia(SDL_Renderer* renderer)
{
    int success = 1;
    //fst page
    FIRSTPAGETexture = loadTexture("assets/images/fstimage.png", renderer);
    if (FIRSTPAGETexture == NULL)
    {
        SDL_Log("Failed to load youwin background image!\n");
        success = 0;
    }
    // Load background
    gBackgroundTexture = loadTexture("assets/images/background.png", renderer);
    if (gBackgroundTexture == NULL)
    {
        SDL_Log("Failed to load background image!\n");
        success = 0;
    }
    // Load buttons
    gPlayerTexture = loadTexture("assets/images/player.png", renderer);
    gMachineTexture = loadTexture("assets/images/machine.png", renderer);
    gMachineVsPlayerTexture = loadTexture("assets/images/machinevsplayer.png", renderer);
    gtopplayersTexture = loadTexture("assets/images/score.png", renderer);
    gblurrBackgroundTexture = loadTexture("assets/images/blurredBG.png", renderer);

    if (gPlayerTexture == NULL || gMachineTexture == NULL ||
        gMachineVsPlayerTexture == NULL || gtopplayersTexture == NULL || gblurrBackgroundTexture == NULL)
    {
        SDL_Log("Failed to load one or more button images!\n");
        success = 0;
    }

    gGOBackgroundTexture = loadTexture("assets/images/gobackground.jpg", renderer);
    if (gGOBackgroundTexture == NULL)
    {
        SDL_Log("Failed to load game over background image!\n");
        success = 0;
    }
    // Load replay button
    gReplayTexture = loadTexture("assets/images/replay.png", renderer);
    if (gReplayTexture == NULL)
    {
        SDL_Log("Failed to load replay button image!\n");
        success = 0;
    }
    // Load exit button
    gExitTexture = loadTexture("assets/images/exit.png", renderer);
    if (gExitTexture == NULL)
    {
        SDL_Log("Failed to load exit button image!\n");
        success = 0;
    }
    // Load exit button
    gtimeTexture = loadTexture("assets/images/time.png", renderer);
    if (gtimeTexture == NULL)
    {
        SDL_Log("Failed to load time icon image!\n");
        success = 0;
    }
    // Load exit button
    gmachineiconTexture = loadTexture("assets/images/sphere2.png", renderer);
    if (gmachineiconTexture == NULL)
    {
        SDL_Log("Failed to load machine icon image!\n");
        success = 0;
    }
    // Load exit button
    gplayericonTexture = loadTexture("assets/images/sphere.png", renderer);
    if (gplayericonTexture == NULL)
    {
        SDL_Log("Failed to load player icon image!\n");
        success = 0;
    }
    // Load REPLAY button
    REPLAYTexture = loadTexture("assets/images/REPLAYicon.png", renderer);
    if (REPLAYTexture == NULL)
    {
        SDL_Log("Failed to load replay icon image!\n");
        success = 0;
    }

    // Load UNDO button
    UNDOTexture = loadTexture("assets/images/UNDO.png", renderer);
    if (UNDOTexture == NULL)
    {
        SDL_Log("Failed to load undo icon image!\n");
        success = 0;
    }
    // Load PAUSE button
    PAUSETexture = loadTexture("assets/images/PAUSE.png", renderer);
    if (PAUSETexture == NULL)
    {
        SDL_Log("Failed to load pause icon image!\n");
        success = 0;
    }

        ARRETTexture = loadTexture("assets/images/savequit.png", renderer);
    if (ARRETTexture == NULL)
    {
        SDL_Log("Failed to load ARRET icon image!\n");
        success = 0;
    }
    // Load background
    gBackgroundTextureTP = loadTexture("assets/images/background2.jpg", renderer);
    if (gBackgroundTextureTP == NULL)
    {
        printf("Failed to load background image!\n");
        success = 0;
    }

    // Load rect.png
    gRectTexture = loadTexture("assets/images/rec.png", renderer);
    if (gRectTexture == NULL)
    {
        SDL_Log("Failed to load rect image!\n");
        success = 0;
    }

    // Load backbutton.png
    gBackButtonTexture = loadTexture("assets/images/backbutton.png", renderer);
    if (gBackButtonTexture == NULL)
    {
        SDL_Log("Failed to load backbutton image!\n");
        success = 0;
    }

    RESUMETexture = loadTexture("assets/images/RESUME.png", renderer);
    if (RESUMETexture == NULL)
    {
        SDL_Log("Failed to load resume image!\n");
        success = 0;
    }

    // arrows
    UPTexture = loadTexture("assets/images/up.png", renderer);
    if (UPTexture == NULL)
    {
        SDL_Log("Failed to load up image!\n");
        success = 0;
    }

    RIGHTTexture = loadTexture("assets/images/right.png", renderer);
    if (RIGHTTexture == NULL)
    {
        SDL_Log("Failed to load right image!\n");
        success = 0;
    }

    LEFTTexture = loadTexture("assets/images/left.png", renderer);
    if (LEFTTexture == NULL)
    {
        SDL_Log("Failed to load left image!\n");
        success = 0;
    }

    DOWNTexture = loadTexture("assets/images/down.png", renderer);
    if (DOWNTexture == NULL)
    {
        SDL_Log("Failed to load down image!\n");
        success = 0;
    }

    YOUWINBackgroundTexture = loadTexture("assets/images/youiwnbg.jpg", renderer);
    if (YOUWINBackgroundTexture == NULL)
    {
        SDL_Log("Failed to load youwin background image!\n");
        success = 0;
    }

    continueTexture = loadTexture("assets/images/continue.png", renderer);
    if (continueTexture == NULL)
    {
        SDL_Log("Failed to load youwin background image!\n");
        success = 0;
    }

    musicONTexture = loadTexture("assets/images/musicON.png", renderer);
    if (musicONTexture == NULL)
    {
        SDL_Log("Failed to load music background image!\n");
        success = 0;
    }

    musicOFFTexture = loadTexture("assets/images/musicOFF.png", renderer);
    if (musicOFFTexture == NULL)
    {
        SDL_Log("Failed to load mute music background image!\n");
        success = 0;
    }


    return success;
}

SDL_Texture* loadTexture(const char* path,  SDL_Renderer* renderer)
{
    SDL_Texture* newTexture = NULL;

    newTexture = IMG_LoadTexture(renderer, path);
    if (!newTexture) {
        SDL_Log("Unable to load texture %s! SDL_image Error: %s\n", path, IMG_GetError());
        return NULL;
    }
    SDL_SetTextureBlendMode(newTexture, SDL_BLENDMODE_BLEND);
    return newTexture;
}

void saveGame(const char *filename, const char *playerName, int matrix[4][4], int score, int highscore, Uint32 gameTime) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Could not save game.\n");
        return;
    }
    fwrite(playerName, sizeof(char), 50, file);  
    fwrite(matrix, sizeof(int), 16, file);     
    fwrite(&score, sizeof(int), 1, file);       
    fwrite(&highscore, sizeof(int), 1, file);   
    fwrite(&gameTime, sizeof(Uint32), 1, file); 
    fclose(file);
}

void loadGame(const char *filename, char *playerName, int matrix[4][4], int *score, int *highscore, Uint32 *gameTime) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("No saved game found.\n");
        return;
    }
    fread(playerName, sizeof(char), 50, file);  
    fread(matrix, sizeof(int), 16, file);     
    fread(score, sizeof(int), 1, file);        
    fread(highscore, sizeof(int), 1, file);   
    fread(gameTime, sizeof(Uint32), 1, file);  
    fclose(file);
}

void saveGameData(const char *filename, GameData playerData) {
    FILE *file = fopen(filename, "r");
    GameData *entries = NULL;
    size_t count = 0;


    if (file != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            GameData temp;
            if (sscanf(line, "%34[^,],%d,%u", temp.NAME, &temp.highscore, &temp.time) == 3) {
                entries = realloc(entries, (count + 1) * sizeof(GameData));
                if (!entries) {
                    fclose(file);
                    perror("Memory allocation failed");
                    return;
                }
                entries[count++] = temp;
            }
        }
        fclose(file);
    }


    GameData *unique_entries = NULL;
    size_t unique_count = 0;

    for (size_t i = 0; i < count; i++) {
        GameData *current = &entries[i];
        int found = 0;
        for (size_t j = 0; j < unique_count; j++) {
            if (strcmp(unique_entries[j].NAME, current->NAME) == 0) {
                found = 1;
                if (current->highscore > unique_entries[j].highscore) {
                    unique_entries[j] = *current;
                }
                break;
            }
        }
        if (!found) {
            unique_entries = realloc(unique_entries, (unique_count + 1) * sizeof(GameData));
            if (!unique_entries) {
                perror("Memory allocation failed");
                free(entries);
                return;
            }
            unique_entries[unique_count++] = *current;
        }
    }


    int found = 0;
    for (size_t j = 0; j < unique_count; j++) {
        if (strcmp(unique_entries[j].NAME, playerData.NAME) == 0) {
            found = 1;
            if (playerData.highscore > unique_entries[j].highscore) {
                unique_entries[j] = playerData;
            }
            break;
        }
    }
    if (!found) {
        unique_entries = realloc(unique_entries, (unique_count + 1) * sizeof(GameData));
        if (!unique_entries) {
            perror("Memory allocation failed");
            free(entries);
            return;
        }
        unique_entries[unique_count++] = playerData;
    }


    file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file for writing");
        free(entries);
        free(unique_entries);
        return;
    }

    for (size_t j = 0; j < unique_count; j++) {
        fprintf(file, "%s,%d,%u\n", unique_entries[j].NAME, unique_entries[j].highscore, unique_entries[j].time);
    }

    fclose(file);
    free(entries);
    free(unique_entries);
}



Mix_Music* loadMusic(const char* filepath) {
    Mix_Music* music = Mix_LoadMUS(filepath);
    if (!music) {
        fprintf(stderr, "Failed to load music: %s\n", Mix_GetError());
    }
    return music;
}

void toggleMute(Mix_Chunk* clickSound) {
    if (Mix_PausedMusic()) {
        Mix_ResumeMusic();
        Mix_Resume(-1); 
        if (clickSound) Mix_PlayChannel(-1, clickSound, 0);
    } else {

        if (clickSound) Mix_PlayChannel(-1, clickSound, 0);
        SDL_Delay(100); 
        Mix_PauseMusic();
        Mix_Pause(-1); 
    }
}

int getBestHighScore(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {

        return 0;
    }

    int bestHighScore = 0;
    char line[256];
    
    while (fgets(line, sizeof(line), file)) {
        GameData temp;
        if (sscanf(line, "%34[^,],%d,%u", temp.NAME, &temp.highscore, &temp.time) == 3) {
            if (temp.highscore > bestHighScore) {
                bestHighScore = temp.highscore;
            }
        }
    }
    
    fclose(file);
    return bestHighScore;
}