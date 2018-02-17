/**
* @author Namir Hassan
* @date 9/23/2017
* @name Terminus
* @brief Text-based RPG game
* @bug non-critical warning during compliation  
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

void printIntro();

int main() {
	
	// Intro
	printIntro();
	// Start
	
	char buffer[SIZE];
	int choice = 0;
	char username[32];
	char yn;
	int move;
	
	char *classes[3];
	classes[0] = "Warrior";
	classes[1] = "Wizard";
	classes[2] = "Hunter";
	
	/* Player Stats */
	int initHealth = 100;
	int initMana = 50;
	int player_health = initHealth;
	int mana = initMana;;
	int level = 1;
	int stamina = 20;
	int xp = 0;
	
	/* World Stats */
	int hour = 23;
	int min = 45;
	int posx = 0;
	int posy = 0;
	char location[32];

	// misc
	int count = 0;
	int time;
	
	// Welcome
	printf("\n\n\n\n\n");
	printf("Hello, welcome to Terminus!\n");
	printf("Choose your class:\n\n1.) Warrior\n2.) Wizard\n3.) Hunter\n\n:");
	fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%d", &choice);
	
	printf("\nYou chose %s!\n\n", classes[choice-1]); 
	printf("\nWould you like to keep this class?\n1.) Yes\n2.) No\n\n");
	fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%d", &choice);
	
	if(choice != 1) {
		printf("Change to:\n\n1.) Warrior\n2.) Wizard\n3.) Hunter\n\n:");
		fgets(buffer, sizeof(buffer), stdin);
		sscanf(buffer, "%d", &choice);
		
		switch(choice) {
			
			case 1: 
				printf("\nYou chose %s!\n\n", classes[choice-1]);
				break; 
			case 2:
				printf("\nYou chose %s!\n\n", classes[choice-1]);
				break;
			case 3:
				printf("\nYou chose %s!\n\n", classes[choice-1]);
				break;
		}	
	} 
	
	printf("\nUsername: ");
	fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%s", &username);
	printf("\n\nWelcome %s, would you like to play the Tutorial? y/N\n\n:", username);
	fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%c", &yn);

	if(yn == 'y' || yn == 'Y') {
	

	printf("\n\n");
	do {
	time++;
	if(min < 10) {
		printf("\nTIME:[%d:0%d]\n", hour, min);
	} else {
		printf("\nTIME:[%d:%d]\n", hour, min);
	}
	if(hour > 23) {
		hour = 0;
	}
	printf("_______________________________________________________\n");
	printf("|[%s] [Health: %d] [Mana: %d] [Stamina: %d] [%d,%d]\n", username, player_health, mana, stamina, posx, posy);
	printf("|[Level: %d] [%s]\n", level, classes[choice -1]);	
	printf("|[EXP: %d]\n", xp);
	printf("|\n");
	printf("|(1) Move Forward\n");
	printf("|(2) Move Backward\n");
	printf("|(3) Move Right\n");
	printf("|(4) Move Left\n");
	printf("_______________________________________________________\n");
	printf("|:-> ");
	fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%d", &move);
	printf("\n|======================================================\n");
	
	if (move == 1) {

		if(count == 0) {
		printf("\n\nYou have moved one space forward! Notice the position [x,y]\n");
		printf("Every time you move. The position will change based on direction.\n");
		count++;
		} else {

			printf("\n\nEvery time you move, stamina will decrease!\n");
			count = 0;
		}
	} else if (move == 2) {

		if(count == 0) {
		printf("\n\nYou have moved one space backward! Notice the position [x,y]\n");
		printf("Every time you move. The position will change based on direction.\n");
		count++;
		} else {

			printf("\n\nEvery time you move, stamina will decrease!\n");
			count = 0;
		}

	} else if (move == 3) {

		if(count == 0) {
		printf("\n\nYou have moved one space right! Notice the position [x,y]\n");
		printf("Every time you move. The position will change based on direction.\n");
		count++;
		} else {

			printf("\n\nEvery time you move, stamina will decrease!\n");
			count = 0;
		}

	} else if (move == 4) {

		if(count == 0) {
		printf("\n\nYou have moved one space left! Notice the position [x,y]\n");
		printf("Every time you move. The position will change based on direction.\n");
		count++;
		} else {

			printf("\n\nEvery time you move, stamina will decrease!\n");
			count = 0;
		}

	}

	switch(move) {
		
		case 0:
			printf("\nWould you like to quit? y/N\n");
			fgets(buffer, sizeof(buffer), stdin);
			sscanf(buffer, "%c", &yn);
			if(yn == 'y' || yn == 'Y') {
				printf("\nGame Over, %s.\n\n", classes[choice-1]);
				exit(1);
			} else {
				break;
			}
			break;
		case 1: 
			min++;
			if(stamina == 0) {
				printf("\n\nOUT OF STAMINA!\n\n");
				break;
			}
			posy++;
			stamina--;
			if(min == 60) {
		    	hour++;
		    	min = 0;
			}
			break;
		case 2:
			min++;
			if(stamina == 0) {
				printf("\n\nOUT OF STAMINA!\n\n");
				break;
			}
			posy--;
			stamina--;
			if(min == 60) {
		    	hour++;
		    	min = 0;
			}
			break;
		case 3:
			min++;
			if(stamina == 0) {
				printf("\n\nOUT OF STAMINA!\n\n");
				break;
			}
			posx++;
			stamina--;
			if(min == 60) {
		    	hour++;
		    	min = 0;
			}
			break;
		case 4: 
			min++;
			if(stamina == 0) {
				printf("\n\nOUT OF STAMINA!\n\n");
				break;
			}
			posx--;
			stamina--;
			if(min == 60) {
		    	hour++;
		    	min = 0;
			}
		case 5:
			stamina++;
			min++;
			if(min == 60) {
		    	hour++;
		    	min = 0;
			}
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
	}
	
	
	
	} while(move != 0);
		
	}
	printf("\n\n");
	do {
	time++;
	if(min < 10) {
		printf("\nTIME:[%d:0%d]\n", hour, min);
	} else {
		printf("\nTIME:[%d:%d]\n", hour, min);
	}
	if(hour > 23) {
		hour = 0;
	}
	printf("_______________________________________________________\n");
	printf("|[%s] [Health: %d] [Mana: %d] [Stamina: %d] [%d,%d]\n", username, player_health, mana, stamina, posx, posy);
	printf("|[Level: %d] [%s]\n", level, classes[choice -1]);	
	printf("|[EXP: %d]\n", xp);
	printf("|\n");
	printf("|(1) Move Forward\n");
	printf("|(2) Move Backward\n");
	printf("|(3) Move Right\n");
	printf("|(4) Move Left\n");
	printf("|(5) Wait\n");
	printf("|(6) Attack\n");
	printf("|(7) Inventory\n");
	printf("|(8) Skills\n");
	printf("|(9) Options\n");
	printf("_______________________________________________________\n");
	printf("|:-> ");
	fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%d", &move);
	printf("\n|======================================================\n");
	
	switch(move) {
		
		case 0:
			printf("\nWould you like to quit? y/N\n");
			fgets(buffer, sizeof(buffer), stdin);
			sscanf(buffer, "%c", &yn);
			if(yn == 'y' || yn == 'Y') {
				printf("\nGame Over, %s.\n\n", classes[choice-1]);
				printf(".: %s's Stats :.\n", username);
				printf("Total Experience: %d\n", xp);
				printf("Total Level: %d\n", level);
				printf("Time Spent: %d turns\n\n\n", time);
				exit(1);
			} else {
				break;
			}
			break;
		case 1: 
			min++;
			if(stamina == 0) {
				printf("\n\nOUT OF STAMINA!\n\n");
				break;
			}
			posy++;
			stamina--;
			
			if(min == 60) {
		    	hour++;
		    	min = 0;
			}
			break;
		case 2:
			min++;
			if(stamina == 0) {
				printf("\n\nOUT OF STAMINA!\n\n");
				break;
			}
			posy--;
			stamina--;
			
			if(min == 60) {
		    	hour++;
		    	min = 0;
			}
			break;
		case 3:
			min++;
			if(stamina == 0) {
				printf("\n\nOUT OF STAMINA!\n\n");
				break;
			}
			posx++;
			stamina--;
			if(min == 60) {
		    	hour++;
		    	min = 0;
			}
			break;
		case 4: 
			min++;
			if(stamina == 0) {
				printf("\n\nOUT OF STAMINA!\n\n");
				break;
			}
			posx--;
			stamina--;
			if(min == 60) {
		    	hour++;
		    	min = 0;
			}
		case 5:
			stamina++;
			min++;
			if(min == 60) {
		    	hour++;
		    	min = 0;
			}
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
	}
	
	
	
	} while(move != 0);
	
	
	
	
	
	
	return 0;
}

void printIntro() {
	
	printf("|-----------------------------------------------------------------| \n");
	printf("|-----------------------------------------------------------------| \n");
	printf("|-_______--_____--____------------_____-------------------_______-| \n");
	printf("|----|----|------|----*--|*----/|---|---|*-----|-|-----|-|--------| \n");
	printf("|----|----|------|-----)-|-*--/-|---|---|-*----|-|-----|-|--------| \n");
	printf("|----|----|------|____/--|--*/--|---|---|--*---|-|-----|-|--------| \n");
	printf("|----|----|=====-|----*--|------|---|---|---*--|-|-----|-|______--| \n");
	printf("|----|----|------|-----*-|------|---|---|----*-|-|-----|- ------|-| \n");
	printf("|----|----|------|-----|-|------|---|---|-----*| |-----|--------|-| \n");
	printf("|----|----|_____-|-----|-|------|-__|__-|------|-|_____|-_______|-| \n");
	printf("|-----------------------------------------------------------------| \n");
	printf("|-----------------------------------------------------------------| \n");
	printf("|-------------------Developed-by-Namir-Hassan---------------------| \n");
	printf("|-------------------------Sep-23-2017-----------------------------| \n");
	printf("|------------------------(version-1.0)----------------------------| \n");
	printf("|-----------------------------------------------------------------| \n");
	printf("|-----------------------------------------------------------------| \n");
	
}
