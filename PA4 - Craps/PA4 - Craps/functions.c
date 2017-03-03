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
#include "functions.h"
#define _CRT_SECURE_NO_WARNINGS

/// functions
/* display greeting & details*/
void intro(void) {
		system("cls");
		current_time();
		puts("Welcome to Craps, one of the most popular games of chance.");
		puts("Craps is played in casinos and back alleys throughout the world.\n");
} // end function intro

/* prints out the rules of the game of "craps" */
void print_game_rules(void) {
	// rules
	puts("The rules of the game are straightforward: \n");
	puts("1) A player rolls two dice. Each die has six faces.");
	puts("2) After the dice is rolled, sum of the spots on the two upward faces is calculated.");
	puts("3) If the sum is 7 or 11 on  first throw, the player wins.");
	puts("4) If the sum is 2, 3, or 12 on  first throw, the player loses .");
	puts("5) If the sum is 4, 5, 6, 8, 9, or 10 on  first throw, then sum becomes player's point.");
	puts("6) To win, you must continue rolling the dice until you make your point.");
	puts("7) The player loses by rolling a 7 before making the point.\n");
	
	// continue?
	printf("Press enter to continue...\n");
	getchar();
	puts("\n");
	putchar('>');
	for (register int i = 0; i < 12; i++) {
		Sleep(200);
		printf(" >");
	} // end for
	system("cls");
} // end functino print_game_rules

/* Prompts initial bank balance, return balance */
double get_bank_balance(void) {
	double balance = 0;
	printf("What is your initial bank balance? ");
	scanf("%lf", &balance);
	return balance;
} // end function get_bank balance

/* prompts wager on roll, return wager */
double get_wager_amount(void) {
	double wager = 0;
	printf("How much do you want to wage? ");
	scanf("%lf", &wager);
	return wager;
} // end function get_wager_amount

/* Checks wager available balance. If exceed, 0; else 1 */
int check_wager_amount(double wager, double balance) {
	if (wager > balance) {
		return 0;
	}
	else {
		return 1;
	}
} // end function check_wager_amount

/* generate value 1-6 randomly, return value */
int roll_die(void) {
	int die = 0;
	die = rand() % 6 + 1;
	return die;
} // end function roll_die

/* sum two dice, return result. 
*  Note: result may become point in future rolls */
int calculate_sum_dice(int die1_value, int die2_value) {
	int sum = 0;
	sum = die1_value + die2_value;
	return sum;
} // end function calculate_sum_dice

/* determine the first roll. If sum 7, 11, win, return 1. 
*  if sum == 2, 3, 12 on first throw, lose return 0. 
*  if sum == 4, 5, 6, 8, 9, 10 on first throw, sum == player's "point", return 0. */
int is_win_loss_or_point(int sum_dice) { // first roll
	if (sum_dice == 7 || sum_dice == 11) {
		return 1;
	}
	else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12) {
		return 0;
	}
	else if (sum_dice == 4 || sum_dice == 5 || sum_dice == 6 || sum_dice == 8 || sum_dice == 9 || sum_dice == 10) {
		return -1;
	}
} // end function is_win_loss_or_point

/* determines result of successive roll after first roll. 
*  if sum of roll == point_value, return 1. 
*  if sum of roll == 7, return 0, 
*  else return -1 */
int is_point_loss_or_neither(int sum_dice, int point_value) { // other rolls
	if (sum_dice == point_value) {
		return 1;
	}
	else if (sum_dice == 7) {
		return 0;
	}
	else {
		return -1;
	}
} // end function is_point_loss_or_neither

/* if add_or_subtract == 1, then wager amount add to bank_balance. 
*  if add_or_subtract == 0, then wager amount subtracted from bank_balance. 
*  else, bank_balance remain same.
*  return bank_balance */
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract) {
	if (add_or_subtract == 1) {
		bank_balance += wager_amount; // add
		return bank_balance;
	}
	else if (add_or_subtract == 0) {
		bank_balance -= wager_amount; // subtract
		return bank_balance;
	}
	else {
		return bank_balance;
	}
} // end function adjust_bank_balance

/* print message on no. of rolls taken, current balance, roll win status. 
*  the win_loss_neither indicate result of previous roll. */
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance) {
	
	int player_points = 0;

	printf("\nNumber of rolls: %d \n", number_rolls);
	
	if (win_loss_neither == 1) {
		puts("You win!");
	} 
	else if (win_loss_neither == 0) {
		puts("You lose!");
	}

	printf("Initial bank balance: %6.2lf \n", initial_bank_balance);
	printf("Current bank balance: %6.2lf \n\n", current_bank_balance);
} // end function chatter_messages

/* run the app  */
void run_app(void) {
	int die1 = 0, die2 = 0, sum = 0, check = 0;
	double balance = 0.0, wager = 0.0;
	int first_roll = 0, other_rolls = 0;
	int points = 0;
	double current_balance = 0.0;
	register int counter = 0;
	
	intro();
	print_game_rules();
	balance = get_bank_balance();
	wager = get_wager_amount();
	check = check_wager_amount(wager, balance);
	while (check != 1) {
		puts("Your wager exceeds your balance");
		puts("Re-enter your wager\n");
		run_app();
	} // end while


	/// first roll
	die1 = roll_die();
	printf("\ndie1: %d\n", die1);
	die2 = roll_die();
	printf("die2: %d\n", die2);
	sum = calculate_sum_dice(die1, die2);
	counter++;
	printf("\n\tsum: %d\n", sum);
	first_roll = is_win_loss_or_point(sum);
	current_balance = adjust_bank_balance(balance, wager, first_roll); // first roll; add/subtract/none
	chatter_messages(counter, first_roll, balance, current_balance);
	if (first_roll == -1) {
		points = sum;
		printf("Your point is: %d\n", points);
	}

	/// non-first rolls
	int check_balance_new = 0;
	char input = 0;
	do {
		printf("\nDo you want to roll again? (y/n) ");
		scanf(" %c", &input);
		switch (input) {
		case 'y':
			system("cls");
			die1 = roll_die();
			printf("\ndie1: %d\n", die1);
			die2 = roll_die();
			printf("die2: %d\n", die2);
			sum = calculate_sum_dice(die1, die2);
			printf("\n\tsum: %d\n", sum);
			counter++;
			other_rolls = is_point_loss_or_neither(sum, points);
			current_balance = adjust_bank_balance(current_balance, wager, other_rolls); // other rolls; add/subtract/none
			chatter_messages(counter, other_rolls, balance, current_balance);
			printf("Your point is: %d\n", points);
			if (current_balance < 0) {
				fflush(stdin);
				fflush(stdout);
				getchar();
				puts("\nYou run out of money!");
				for (register int i = 0; i < 50; i++) {
					Sleep(150);
					puts("You run out of money!");
				}
				printf("\nYour balance is: %d\n", current_balance);
				fflush(stdin);
				getchar();
				puts("Press enter to continue...");
				restart();
			} // end if
			break;
		case 'n':
			restart();
			break;
		default:
			restart();
			break;
		}
	} while (input != 'n' || current_balance >= 0);
	
} // end function run_app

/* display current time */
int current_time(void) {
	time_t mytime;
	mytime = time(NULL);
	printf(ctime(&mytime));
	putchar('\n');
} // end function current_time

/* prompt restart */
void restart(void) {
	system("cls");
	char input = '\0';
	printf("Would you like to restart the app? (y/n) ");
	scanf(" %c", &input);
	switch (input) {
	case 'y':
		system("cls");
		getchar();
		main();
		break;
	case 'n':
		system("cls");
		exit;
		break;
	default:
		system("cls");
		main();
		break;
	} // end switch
} // end function restart