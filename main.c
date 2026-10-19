#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_CANDIDATES 100
#define MAX_NAME_LEN 100
#define PARTY_CHAR_LEN 100
bool running = true;
int candidate_amount = 0;
char user_input;

typedef struct {
		char name[MAX_NAME_LEN];
		char party[PARTY_CHAR_LEN];
		int age;
		char symbol;
		int vote_amt;
} Candidate;

void add_candidate(Candidate candidates[], int index){
	printf("enter candidate name: \n");
	fgets(candidates[index].name, sizeof candidates[index].name, stdin);

	printf("enter candidate party: \n");
	fgets(candidates[index].party, sizeof candidates[index].party, stdin);

	printf("enter candidate age: \n");
	scanf("%d", &candidates[index].age);

	printf(" %s \n", candidates[index].name);
	printf(" %s \n", candidates[index].party);
	printf("%d \n", candidates[index].age);

	candidate_amount += 1;
}

void list_candidates(Candidate candidates[]){
	for (int i = 0; i < candidate_amount; i++) {
		printf("Candidate Name: %s\n", candidates[i].name);
		printf("Candidate Party: %s\n", candidates[i].party);
		printf("Candidate Age: %d\n", candidates[i].age);
		printf("---------------------");
	}

}

int main(void) {
	Candidate candidates[MAX_CANDIDATES];


	while (running) {

	printf("What would you like to do? \n (1) Add a Candidate \n (2) View Candidates \n (3) Vote for a Candidate \n (4) Quit \n");
	scanf(" %c", &user_input);

	while (getchar() != '\n') {}

	switch(user_input) {
		case '1':
			add_candidate(candidates, candidate_amount);
			break;

		case '2':
			list_candidates(candidates);
			break;

		case '3':
			break;

		case '4':
			return 0;

		default:
			printf("Invalid Input");
			break;
	}
}

}


