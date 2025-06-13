#ifndef LOGIC_H
#define LOGIC_H

#include "global.h"
#include <stdio.h>

void place_2_aleatoire(int mat[4][4]);

//move
void move_down(int T[4][4], int *moved, int *score, int prevT[4][4], int *prevscore, int *won, int *lose, int *dejawon);
void move_left(int T[4][4], int *moved, int *score, int prevT[4][4], int *prevscore, int *won, int *lose, int *dejawon);
void move_up(int T[4][4], int *moved, int *score, int prevT[4][4], int *prevscore, int *won, int *lose, int *dejawon);
void move_right(int T[4][4], int *moved, int *score, int prevT[4][4], int *prevscore, int *won, int *lose, int *dejawon);

void copy_matrix(int src[4][4], int dest[4][4]);
int if_win(int T[4][4]);
int if_moves_left(int T[4][4]);
void empty_matrix(int T[4][4]);
void undo(int T[4][4], int prevT[4][4], int *score, int prevscore, int *undo_available);

//machine

void move_leftM(int T[4][4], int *H,int *score);
void move_rightM(int T[4][4], int *H,int *score);
void move_upM(int T[4][4], int *H,int *score);
void move_downM(int T[4][4], int *H,int *score);
int evaluate_board(int board[MATRIX_SIZE][MATRIX_SIZE]);
int machine_move(int board[MATRIX_SIZE][MATRIX_SIZE], int score);


#endif