#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_states,num_symbols,num_final,start_state,i,j,n,steps[50],flag=0;

    printf("Enter the number of states: ");
    scanf("%d",&num_states);
    int states[num_states];
    printf("Enter the states: ");
    for(i=0;i<num_states;i++){
        scanf("%d",&states[i]);
    }
    printf("Enter the number of symbols: ");
    scanf("%d",&num_symbols);
    int symbols[num_symbols];
    printf("Enter the symbols: ");
    for(i=0;i<num_symbols;i++){
        scanf("%d",&symbols[i]);
    }
    printf("Enter the start state: ");
    scanf("%d",&start_state);
    printf("Enter the number of final states: ");
    scanf("%d",&num_final);
    int final_states[num_final];
    printf("Enter the final state(s):");
    for(i=0;i<num_final;i++) {
        scanf("%d",&final_states[i]);
    }
    int transition[num_states][num_symbols];
    for(i=0;i<num_states;i++){
            printf("From state %d enter the destination  ",states[i]);
        for(j=0;j<num_symbols;j++){
            printf("for symbol %d ",symbols[j]);
            scanf("%d",&transition[i][j]);
        }
    }
    for(i=0;i<num_states;i++){
        for(j=0;j<num_symbols;j++){
            printf("%d ",transition[i][j]);
        }
        printf("\n");
    }
    char str[100];
    printf("Enter your string: ");
    scanf("%s",str);
     for(i=0;str[i];i++){
        steps[i]=start_state;
        for(j=0;j<num_symbols;j++){
            if(str[i]-'0'==symbols[j]){
                start_state=transition[start_state][j];
                break;
            }
        }
     }
     steps[i]=start_state;
     for(j=0;j<num_final;j++){
        if(start_state==final_states[j]) flag=1;
     }
     if(flag==1)printf("ACCEPTED.\n");
	else printf("NOT ACCEPTED.\n");
	printf("Path: ");
	for(int j=0;j<=i;j++)
	{
		printf("%d ",steps[j]);
	}
printf("\n");
    return 0;
}
