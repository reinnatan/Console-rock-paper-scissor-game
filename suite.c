#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
	
	char commands[3]={'R', 'S', 'P'};
	char *clearConsole = "\e[1;1H\e[2J";
	char askPlayAgain;
	
	do{	
		printf("%s",clearConsole);
		printf("===========================\n");
		printf("=== ROCK SCISSOR PAPER ====\n");
		printf("===========================\n");
	

		int start = 0;
		int times = 0;

		printf("How many times to suite? : ");
		scanf("%d", &times);
		
		int countComputer=0;
		int countPlayer=0;
		char sel, selsuit;

		while(start<times){
			int rnd = rand() % 3;
			sel = commands[rnd];
			
			printf("your suite : ");
			while((selsuit=getc(stdin))=='\n');
			//printf("%c", selsuit);
			selsuit = toupper(selsuit);	
		
			if (selsuit == 'R'){
				if(sel=='P'){
					countComputer +=1;			
				}else if(sel=='S'){
					countPlayer +=1;
				}

			}else if(selsuit=='S'){
				if (sel=='R'){
					countComputer +=1;	
				}else if(sel=='P'){
					countPlayer +=1;
				}
			
			}else if(selsuit=='P'){
				if (sel=='R'){
					countPlayer +=1;
				}else if(sel=='S'){
					countComputer +=1;
				}
			}


			//printf("\nComputer Count : %d \n", countComputer);
			//printf("Player Count : %d\n\n", countPlayer);
		
			start+=1;
		}

		if(countPlayer==countComputer){
			printf("Draw !!!\n");
		}else if(countPlayer<countComputer){
			printf("You Lose !!!\n");
		}else{
			printf("You Win !!!\n");
		}
		
		
		printf("Do you want to play again? : ");		
		while((askPlayAgain=getc(stdin))=='\n');
	
	}while(askPlayAgain =='Y' || askPlayAgain =='y');

}
