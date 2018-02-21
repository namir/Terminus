/**
* @author Namir Hassan
* @date 9/23/2017
* @name Terminus
* @brief Text-based RPG game
* @bug None
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

void printIntro();


struct item_t {
	
	int damage;
	int stat;
	int def;
	int att;
	int str;
	char name;
};

int main() {
	
	// Intro
	printIntro();
	// Start
	
	char buffer[SIZE];
	int choice = 0;
	char username[32];
	char yn;
	char move;
	int move2;
	
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
	int dmg = 0;
	int basedmg = 10;

	/* Enemy Stats */
	char *monster[1];
	monster[0] = "Goblin";
	int monsterHP = 50;
	int monsterLevel = 3;
	int monsterXP = 25;
	int monsterDMG = 5;
	int mposx = 4;
	int mposy = 4;
	int dead = 0;
	
	/* World Stats */
	int hour = 23;
	int min = 45;
	int posx = 0;
	int posy = 0;
	char *location[5];
	char *setloc;
	location[0] = "Forest";
	location[1] = "City";
	location[2] = "Town";
	location[3] = "Tavern";
	location[4] = "River";

	// misc
	int count = 0;
	int time = 0;
	int n = 1;
	
	// Welcome
	printf("\n");
	printf(" ______________________\n");
	printf("| Welcome to Terminus! |\n");
	printf(" ----------------------\n\n");
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

	//tutorial
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
	sscanf(buffer, "%s", &move);
	printf("\n|======================================================\n");
	
	if (move == 'w' || move == 'W') {

		if(count == 0) {
		printf("\n\nYou have moved one space forward! Notice the position [x,y]\n");
		printf("Every time you move. The position will change based on direction.\n");
		count++;
		} else {

			printf("\n\nEvery time you move, stamina will decrease!\n");
			count = 0;
		}
	} else if (move == 's' || move == 'S') {

		if(count == 0) {
		printf("\n\nYou have moved one space backward! Notice the position [x,y]\n");
		printf("Every time you move. The position will change based on direction.\n");
		count++;
		} else {

			printf("\n\nEvery time you move, stamina will decrease!\n");
			count = 0;
		}

	} else if (move == 'd' || move == 'D') {

		if(count == 0) {
		printf("\n\nYou have moved one space right! Notice the position [x,y]\n");
		printf("Every time you move. The position will change based on direction.\n");
		count++;
		} else {

			printf("\n\nEvery time you move, stamina will decrease!\n");
			count = 0;
		}

	} else if (move == 'a' || move == 'A') {

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
		
		case 'q':
		case 'Q':
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
		case 'w':
		case 'W': 
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
		case 's':
		case 'S':
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
		case 'd':
		case 'D':
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
		case 'a':
		case 'A':
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
		case 'r':
		case 'R':
			stamina++;
			min++;
			if(min == 60) {
		    	hour++;
		    	min = 0;
			}
			break;
	}
	
	
	
	} while(move != 0);
		
	}
	printf("\n\n");











	//game



	do {
	if(xp == 100) {
		level++;
	} else if (xp > 100) {
		level++;
		// xp = (xp - 100) + xp
	} else {

	}

	time++;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	if(min < 10) {
		printf("\nTIME:[%d:0%d]\n", hour, min);
	} else {
		printf("\nTIME:[%d:%d]\n", hour, min);
	}
	if(hour > 23) {
		hour = 0;
	}

	if(n == 1){
		if(posx >= 5 && posx <= 15 && posy >= 5 && posy <= 15) {
			if(stamina == 0){
				if(min == 59){
					min = 0;
					hour++;
					min -= 1;
				}
			}
			setloc = location[1];
		} else if(posx >= 25 && posx <= 50 && posy >= 30 && posy <= 60){
			if(stamina == 0){
				if(min == 59){
					min = 0;
					hour++;
					min -= 1;
				}
			}
			setloc = location[2];

		} else {
			if(stamina == 0){
				if(min == 59){
					min = 0;
					hour++;
					min -= 1;
				}
			}
			setloc = location[0];
		}
	}
	printf("_________________________________________________________________\n");
	printf("|[%s] [Health: %d] [Mana: %d] [Stamina: %d] [%d,%d] [%s]\n", username, player_health, mana, stamina, posx, posy, setloc);
	printf("|[Level: %d] [%s]\n", level, classes[choice -1]);	
	printf("|[EXP: %d]\n", xp);
	printf("|\n");
	printf("|(W) Move Forward\n");
	printf("|(A) Move Backward\n");
	printf("|(S) Move Right\n");
	printf("|(D) Move Left\n");
	printf("|\n");
	printf("|(R) Rest\n");
	printf("|(E) Attack\n");
	printf("|\n");
	printf("|(I) Inventory\n");
	printf("|(K) Skills\n");
	printf("|(O) Options\n");
	printf("|\n");
	printf("|(Q) Quit\n");
	printf("_________________________________________________________________\n");
	printf("|:-> ");
	fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%s", &move);
	printf("\n|==============================================================\n");
	
	switch(move) {
		
		case 'q':
		case 'Q':
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
		case 'w':
		case 'W': 
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
		case 's':
		case 'S':
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
		case 'd':
		case 'D':
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
		case 'a':
		case 'A':
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
		case 'r':
		case 'R':
			stamina++;
			min++;
			if(min == 60) {
		    	hour++;
		    	min = 0;
			}
			break;
		case 'e':
		case 'E':
			if(posx == mposx && posy == mposy) {

//ATTACK

		do {
		if(xp == 100) {
			level++;
		} else if (xp > 100) {
			level++;
			// xp = (xp - 100) + xp
		} else {

		}
		
		time++;
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		if(min < 10) {
			printf("\nTIME:[%d:0%d]\n", hour, min);
		} else {
			printf("\nTIME:[%d:%d]\n", hour, min);
		}
		if(hour > 23) {
			hour = 0;
		}

		if(n == 1){
			if(posx >= 5 && posx <= 15 && posy >= 5 && posy <= 15) {
				if(stamina == 0){
					if(min == 59){
						min = 0;
						hour++;
						min -= 1;
					}
				}
				setloc = location[1];
			} else if(posx >= 25 && posx <= 50 && posy >= 30 && posy <= 60){
				if(stamina == 0){
					if(min == 59){
						min = 0;
						hour++;
						min -= 1;
					}
				}
				setloc = location[2];

			} else {
				if(stamina == 0){
					if(min == 59){
						min = 0;
						hour++;
						min -= 1;
					}
				}
				setloc = location[0];
			}
		}
		printf("_________________________________________________________________\n");
		printf("|[%s] [Health: %d] [Mana: %d] [Stamina: %d] [%d,%d] [%s]\n", username, player_health, mana, stamina, posx, posy, setloc);
		printf("|[Level: %d] [%s]\n", level, classes[choice -1]);	
		printf("|[EXP: %d]\n", xp);
		printf("|\n");
		printf("|<%s> [lvl: %d] [HP: %d]\n", monster[0], monsterLevel, monsterHP);
		printf("|\n");
		printf("|\n");
		printf("|(1) Basic attack\n");
		printf("_________________________________________________________________\n");
		printf("|:-> ");
		fgets(buffer, sizeof(buffer), stdin);
		sscanf(buffer, "%d", &move2);
		printf("\n|==============================================================\n");
	
		switch(move2) {
		
			case 'q':
			case 'Q':
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
			if(monsterHP > 0) {
				min++;
				if(min == 60) {
		    		hour++;
		    		min = 0;
				}
			
				if(mana != 0) {
					mana--;
					monsterHP -= basedmg + dmg;
					player_health -= monsterDMG;
				} else {
					printf("Not enough Mana!\n");
					player_health -= monsterDMG;
				}

			} else {
				xp += monsterXP;
				dead = 1;		
				break;
			}
		}
			} while(dead != 1);

		} else {
			printf("\nNo enemy found!\n");
			break;
		}
		break;
	} 
	
	
	
	} while(move != 'q' || move != 'Q');
	
	
	
	
	
	
	return 0;
}

void printIntro() {
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
