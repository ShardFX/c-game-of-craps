/****************************************************************************************************
Name: Anwar Haikal Ruslan
Date Created: 2/21/2017
Last Modified: 2/23/2017
Lab: Section 8

Assignment: PA4 | Programming Assignment 4: A Game of Chance "Craps"
Details:	A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 
			6 spots. After the dice have come to rest, the sum of the spots on the two upward faces 
			is calculated. If the sum is 7 or 11 on the first throw, the player wins. If the sum is 
			2, 3, or 12 on the first throw (called "craps"), the player loses 
			(i.e. the "house" wins). If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then 
			the sum becomes the player's "point." To win, you must continue rolling the dice 
			until you "make your point." The player loses by rolling a 7 before making the point.
****************************************************************************************************/

/// preprocessor directives
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS

/// function prototypes
void craps(void);
void run_app(void);
void restart(void);
int current_time(void);
void print_game_rules(void);
double get_bank_balance(void);
double get_wager_amount(void);
int check_wager_amount(double wager, double balance);
int roll_die(void);
int calculate_sum_dice(int die1_value, int die2_value);
int is_win_loss_or_point(int sum_dice);
int is_point_loss_or_neither(int sum_dice, int point_value);
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);
