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

#define SIZE 1000


void printIntro();

int main() {
	
	// Intro
	printIntro();
	// Start
	
	char buffer[SIZE];
	int choice = 0;
	char username[64];
	char yn;
	
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
	int hour = 12;
	int min = 45;
	int posx = 0;
	int posy = 0;
	
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
		
		exit(1);
		
	}
	
	printf("\n\n");
	printf("[%d:%d]\n", hour, min);
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
