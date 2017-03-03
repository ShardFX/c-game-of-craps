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

Version: 1.01
****************************************************************************************************/

/// preprocessor directives
#include "functions.h"
#define _CRT_SECURE_NO_WARNINGS

/// main function
int main(void) {
	srand((unsigned int)time(NULL)); // random seed
	run_app();
	getchar();
	return EXIT_SUCCESS;
} // end function main;