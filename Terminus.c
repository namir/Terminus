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
	
	char *classes[3];
	classes[0] = "Warrior";
	classes[1] = "Wizard";
	classes[2] = "Hunter";
	
	/* Player Stats */
	int initHealth = 100;
	int player_health = initHealth;
	
	printf("\n\n\n\n\n");
	printf("Hello, welcome to Terminus!\n");
	printf("Choose your class:\n\n1.) Warrior\n2.) Wizard\n3.) Hunter\n:");
	fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%d", &choice);
	
	printf("\nYou chose %s!\n\n", classes[choice-1]); 
	printf("\nWould you like to keep this class?\n1.) Yes\n2.) No\n\n");
	fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%d", &choice);
	
	if(choice == 1) {
		
		exit(1);
	} else {
		choice = 0;
		printf("Change to:\n\n1.) Warrior\n2.) Wizard\n3.) Hunter\n:");
		fgets(buffer, sizeof(buffer), stdin);
		sscanf(buffer, "%d", &choice);
		
		switch(choice) {
			
			case 0: 
				printf("\nYou chose %s!\n\n", classes[choice-1]);
				break; 
			case 1:
				printf("\nYou chose %s!\n\n", classes[choice-1]);
				break;
			case 2:
				printf("\nYou chose %s!\n\n", classes[choice-1]);
				break;
		}	
	}
	
	
	
	
	
	
	
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
