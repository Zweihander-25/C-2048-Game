#include "logic.h"

void place_2_aleatoire(int mat[4][4]) {
    int T[4 * 4];
    int L = 0; 

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (mat[i][j] == 0) {
                T[L++] = i * 4 + j;
            }
        }
    }

    if (L > 0) {

        int random = T[rand() % L]; 
        int row = random / 4;
        int col = random % 4; 
        int value =(rand()/(double)RAND_MAX)<0.9? 2 : 4;

        mat[row][col] = value;
    }
}

void move_right(int T[4][4], int *moved, int *score, int prevT[4][4], int *prevscore, int *won, int *lose, int *dejawon)
{
    int TT[4][4];
    int Temp[4][4] = {{0}};
    int i, j, k, Tempscore;
    copy_matrix(T, TT);
    Tempscore = *score;

    for(i=0; i<=3; i++){
        for(j=2; j>=0; j--){
            if(TT[i][j] !=0)
            {
                k=j+1;
                while(k<=3 && TT[i][k]==0)
                {
                    TT[i][k]= TT[i][k-1];
                    TT[i][k-1]= 0;
                    k++;
                    *moved=1;
                }
                if(k<=3 && TT[i][k]==TT[i][k-1] && Temp[i][k]==0)
                {
                    TT[i][k]= TT[i][k]*2;
                    Tempscore += TT[i][k];
                    TT[i][k-1]= 0;
                    Temp[i][k]= 1;
                    *moved=1;
                }
            }
        }
    }
    
    if(*moved==1)
    {
        copy_matrix(T, prevT);
        *prevscore = *score;
        copy_matrix(TT, T);
        *score = Tempscore;
        if(if_win(T))
        {
            if(*dejawon == 0)
            {
                *won = 1;
                *dejawon = 1;
            }
        }
    }
    if(if_moves_left(T) == 0)
        {
            *lose = 1;
        }
}

void move_up(int T[4][4], int *moved, int *score, int prevT[4][4], int *prevscore, int *won, int *lose, int *dejawon)
{
    int TT[4][4];
    int Temp[4][4] = {{0}};
    int i, j, k, Tempscore;
    copy_matrix(T, TT);
    Tempscore = *score;

    for(j=0; j<=3; j++){
        for(i=1; i<=3; i++){
            if(TT[i][j] !=0)
            {
                k=i-1;
                while(k>=0 && TT[k][j]==0)
                {
                    TT[k][j]= TT[k+1][j];
                    TT[k+1][j]= 0;
                    k--;
                    *moved=1;
                }
                if(k>=0 && TT[k][j]==TT[k+1][j] && Temp[k][j]==0)
                {
                    TT[k][j]= TT[k][j]*2;
                    Tempscore += TT[k][j];
                    TT[k+1][j]= 0;
                    Temp[k][j]= 1;
                    *moved=1;


                }
            }
        }
    }

    if(*moved==1)
    {
        copy_matrix(T, prevT);
        *prevscore = *score;
        copy_matrix(TT, T);
        *score = Tempscore;

        if(if_win(T))
        {
            if(*dejawon == 0)
            {
                *won = 1;
                *dejawon = 1;
            }
        }
    }
    if(if_moves_left(T) == 0)
        {
            *lose = 1;
        }
}

void move_left(int T[4][4], int *moved, int *score, int prevT[4][4], int *prevscore, int *won, int *lose, int *dejawon)
{
    int TT[4][4];
    int Temp[4][4] = {{0}};
    int i, j, k, Tempscore;

    copy_matrix(T, TT);
    Tempscore = *score;

    for(i=0; i<=3; i++){
        for(j=1; j<=3; j++){
            if(TT[i][j] !=0)
            {
                k=j-1;
                while(k>=0 && TT[i][k]==0)
                {
                    TT[i][k]= TT[i][k+1];
                    TT[i][k+1]= 0;
                    k--;
                    *moved=1;
                }
                if(k>=0 && TT[i][k]==TT[i][k+1] && Temp[i][k]==0)
                {
                    TT[i][k]= TT[i][k]*2;
                    Tempscore += TT[i][k];
                    TT[i][k+1]= 0;
                    Temp[i][k]= 1;
                    *moved=1;

                }
            }
        }
    }

    
    if(*moved==1)
    {
        copy_matrix(T, prevT);
        *prevscore = *score;
        copy_matrix(TT, T);
        *score = Tempscore;

        if(if_win(T))
        {
            if(*dejawon == 0)
            {
                *won = 1;
                *dejawon = 1;
            }
        }
    }
    if(if_moves_left(T) == 0)
        {
            *lose = 1;
        }
}

void move_down(int T[4][4], int *moved, int *score, int prevT[4][4], int *prevscore, int *won, int *lose, int *dejawon)
{
    int TT[4][4];
    int Temp[4][4] = {{0}};
    int i, j, k, Tempscore;

    copy_matrix(T, TT);
    Tempscore = *score;

    for(j=0; j<=3; j++){
        for(i=2; i>=0; i--){
            if(TT[i][j] !=0)
            {
                k=i+1;;
                while(k<=3 && TT[k][j]==0)
                {
                    TT[k][j]= TT[k-1][j];
                    TT[k-1][j]= 0;
                    k++;
                    *moved=1;
                }
                if(k<=3 && TT[k][j]==TT[k-1][j] && Temp[k][j]==0)
                {
                    TT[k][j]= TT[k][j]*2;
                    Tempscore += TT[k][j];
                    TT[k-1][j]= 0;
                    Temp[k][j]= 1;
                    *moved=1;
                }
            }
        }
    }

 
    if(*moved==1)
    {
        copy_matrix(T, prevT);
        *prevscore = *score;
        copy_matrix(TT, T);
        *score = Tempscore;

        if(if_win(T))
        {
            if(*dejawon == 0)
            {
                *won = 1;
                *dejawon = 1;
            }
        }
    }
    if(if_moves_left(T) == 0)
        {
            *lose = 1;
        }
}

void copy_matrix(int src[4][4], int dest[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

int if_moves_left(int T[4][4])
{

    for(int i=0; i<=3; i++){
        for(int j=0; j<=3; j++){
            if (T[i][j] == 0) return 1;
            if (j<3 && T[i][j]== T[i][j + 1]) return 1;
            if (i<3 && T[i][j]== T[i + 1][j]) return 1;
        }
    }
return 0;
}

int if_win(int T[4][4]){

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (T[i][j] == 2048)
            {
                return 1;
            }
        }
    }
    return 0;
}

void empty_matrix(int T[4][4]){
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            T[i][j] = 0;
        }
    }
    
}

void undo(int T[4][4], int prevT[4][4], int *score, int prevscore, int *undo_available)
{
    if(*undo_available)
    {
        copy_matrix(prevT, T);
        *score = prevscore;
        *undo_available = 0;
    }
}

//machine
void move_leftM(int T[4][4], int *H,int *score) {
    int Temp[4][4] = {{0}};
    int i, j, k;
    for (i = 0; i <= 3; i++) {
        for (j = 1; j <= 3; j++) {
            if (T[i][j] != 0) {
                k = j - 1;
                while (k >= 0 && T[i][k] == 0) {
                    T[i][k] = T[i][k + 1];
                    T[i][k + 1] = 0;
                    k--;
                    *H = 1;
                }
                if (k >= 0 && T[i][k] == T[i][k + 1] && Temp[i][k] == 0) {
                    T[i][k] = T[i][k] * 2;
                    T[i][k + 1] = 0;
                    Temp[i][k] = 1;
                    *H = 1;
                    *score += T[i][k]; 
                }
            }
        }
    }
}

void move_rightM(int T[4][4], int *H,int *score) {
    int Temp[4][4] = {{0}};
    int i, j, k;
    for (i = 0; i <= 3; i++) {
        for (j = 2; j >= 0; j--) {
            if (T[i][j] != 0) {
                k = j + 1;
                while (k <= 3 && T[i][k] == 0) {
                    T[i][k] = T[i][k - 1];
                    T[i][k - 1] = 0;
                    k++;
                    *H = 1;
                }
                if (k <= 3 && T[i][k] == T[i][k - 1] && Temp[i][k] == 0) {
                    T[i][k] = T[i][k] * 2;
                    T[i][k - 1] = 0;
                    Temp[i][k] = 1;
                    *H = 1;
                    *score += T[i][k]; 
                }
            }
        }
    }
}

void move_upM(int T[4][4], int *H,int *score) {
    int Temp[4][4] = {{0}};
    int i, j, k;
    for (j = 0; j <= 3; j++) {
        for (i = 1; i <= 3; i++) {
            if (T[i][j] != 0) {
                k = i - 1;
                while (k >= 0 && T[k][j] == 0) {
                    T[k][j] = T[k + 1][j];
                    T[k + 1][j] = 0;
                    k--;
                    *H = 1;
                }
                if (k >= 0 && T[k][j] == T[k + 1][j] && Temp[k][j] == 0) {
                    T[k][j] = T[k][j] * 2;
                    T[k + 1][j] = 0;
                    Temp[k][j] = 1;
                    *H = 1;
                    *score += T[k][j]; 
                }
            }
        }
    }
}

void move_downM(int T[4][4], int *H,int *score) {
    int Temp[4][4] = {{0}};
    int i, j, k;
    for (j = 0; j <= 3; j++) {
        for (i = 2, k = i + 1; i >= 0; i--, k = i + 1) {
            if (T[i][j] != 0) {
                while (k <= 3 && T[k][j] == 0) {
                    T[k][j] = T[k - 1][j];
                    T[k - 1][j] = 0;
                    k++;
                    *H = 1;
                }
                if (k <= 3 && T[k][j] == T[k - 1][j] && Temp[k][j] == 0) {
                    T[k][j] = T[k][j] * 2;
                    T[k - 1][j] = 0;
                    Temp[k][j] = 1;
                    *H = 1;
                    *score += T[k][j]; 
                }
            }
        }
    }
}

int evaluate_board(int board[MATRIX_SIZE][MATRIX_SIZE]) {
    int score = 0;

    // Monotonicity
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE - 1; j++) {
            if (board[i][j] > board[i][j + 1]) {
                score -= 5; // Penalize non-monotonic rows
            }
        }
    }

    // Smoothness
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE - 1; j++) {
            if (board[i][j] == board[i][j + 1]) {
                score += 50; // Reward adjacent tiles with the same value
            }
        }
    }

    // Empty cells
    int empty_cells = 0;
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (board[i][j] == 0) {
                empty_cells++;
            }
        }
    }
    score += empty_cells * 150; // Reward more empty cells
    // Corner strategy
    int max_tile = 0;
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (board[i][j] > max_tile) {
                max_tile = board[i][j];
            }
        }
    }
    if (board[0][0] == max_tile) {
        score += 300; // Reward the highest tile in the corner
    }
    return score;
}


int machine_move(int board[MATRIX_SIZE][MATRIX_SIZE], int score) {
    int best_move = -1;
    int best_score = -1;
    for (int i = 0; i < DIRECTIONS; i++) {
        int new_board[MATRIX_SIZE][MATRIX_SIZE];
        
        // Copy the board to a temporary board
        for (int j = 0; j < MATRIX_SIZE; j++) {
            for (int k = 0; k < MATRIX_SIZE; k++) {
                new_board[j][k] = board[j][k];
            }
        }
        
        // Apply the appropriate move function based on the direction
        int move_made = 0;
        switch (directions[i]) {
            case 0: // Up
                move_upM(new_board, &move_made, &score);
                break;
            case 1: // Right
                move_rightM(new_board, &move_made, &score);
                break;
            case 2: // Down
                move_downM(new_board, &move_made, &score);
                break;
            case 3: // Left
                move_leftM(new_board, &move_made, &score);
                break;
        }

        // If no move was made, skip evaluation
        if (!move_made) {
            continue;
        }

        // Evaluate the board after the move
        int score = evaluate_board(new_board);

        // Update the best move if this move is better
        if (score > best_score) {
            best_score = score;
            best_move = directions[i];
        }
    }

    return best_move;
}