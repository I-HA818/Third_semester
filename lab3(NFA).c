#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STATES 100
#define MAX_ALPHABET 100
int stateCount, alphabetCount;
char states[MAX_STATES];
char alphabet[MAX_ALPHABET];
char initialState, finalState;
char transitions[MAX_STATES][MAX_ALPHABET][MAX_STATES];
int transitionCount[MAX_STATES][MAX_ALPHABET];
char inputString[100];

bool acceptsInput(char currentState, int index)

 {
    if (index == strlen(inputString) && currentState == finalState) {
        return true;
    }

    int symbolIndex = -1;

    for (int j = 0; j < alphabetCount; j++) {
        if (inputString[index] == alphabet[j]) {
            symbolIndex = j;
            break;
        }
    }

    if (symbolIndex == -1) {
        return false;
    }

    char nextState;
    bool result = false;

    for (int m = 0; m < transitionCount[currentState - states[0]][symbolIndex]; m++) {
        nextState = transitions[currentState - states[0]][symbolIndex][m];
        result = result || acceptsInput(nextState, index + 1);
    }

    return result;
}



int main() {
    printf("Enter the number of states: ");
    scanf("%d", &stateCount);

    for (int i = 0; i < stateCount; i++) {
        scanf(" %c", &states[i]);
        getchar();
    }

    printf("Enter the number of alphabet: ");
    scanf("%d", &alphabetCount);
    getchar();

    for (int i = 0; i < alphabetCount; i++) {
        scanf(" %c", &alphabet[i]);
        getchar();
    }

    for (int i = 0; i < stateCount; i++) {
        for (int j = 0; j < alphabetCount; j++) {
            printf("From %c through %c\n", states[i], alphabet[j]);
            printf("Number of transitions: ");
            scanf("%d", &transitionCount[i][j]);
            getchar();
            for (int k = 0; k < transitionCount[i][j]; k++) {
                scanf(" %c", &transitions[i][j][k]);
                getchar();
            }
        }
    }

    printf("Enter the initial state: ");
    	 scanf(" %c", &initialState);
    getchar();

    printf("Enter the final state: ");
     	scanf(" %c", &finalState);
    getchar();

    printf("Enter the input string: ");
	 scanf("%s", inputString);

    if (acceptsInput(initialState, 0)) {
        printf("ACCEPTED.\n");
    } else {
        printf("REJECTED.\n");
    }

    return 0;
}

