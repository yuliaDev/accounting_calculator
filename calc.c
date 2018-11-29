#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<stdbool.h>

void Menu ();
void MathCalc();
void VATCalc ();
void SalaryCalc();
void WorkDaysCalc();

void VAT_price_ex();
void VAT_price_inc();
void VAT_profit();

void Salary_w();
void Salary_th();

void setStringConsoleColor(char *str, int color);  //set the color to string
void wrongKeyMessage();                            //dispay an error message about invalid input
void byeMessage();                                 //dispay a bye message
void casesKeysSubMenuMessage();                    //user prompt to press keys Y, M or Esc
void casesKeysSub2MenuMessage();                   //user prompt to press keys Y, B, M or Esc
bool numberValidation(char *s);                    //check if the input string is a float number, return "true" or "false"
bool intNumberValidation(char *s);                 //check if the input string is an integer number, return "true" or "false"


main()
{
	SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    system("title accounting calculator");
    Menu();
	getchar();
}

/*
*The function calls the menu with options where choice is making by pressing specified keys
*/
void Menu (){
	char key;
	bool flag;
		
	system("cls");
	/*Display a text of a menu on a screen*/
	puts("");
    char s1[80]="           * * * * * MENU * * * * *";
    setStringConsoleColor(s1, 1);
    char s2[80]="(Choose function that you want to use pressing the menu item number)";
    setStringConsoleColor(s2, 11);
    puts("");
	puts("1. Mathematical calculator");
	puts("2. VAT calculator");
	puts("3. Salary calculator");
	puts("4. Calculation of working days and days off per month");
	puts("");
	char s3[80]="Press Esc to quit the program";
	setStringConsoleColor(s3, 11);		
	printf("\n");
	do{
		flag=true;
		key=getch();
		switch(key){
			case '1': MathCalc(); break;                                 //call function of Math Calculator by pressing key "1"
			case '2': VATCalc(); break;                                  //call function of VAT Calculator by pressing key "2"
			case '3': SalaryCalc(); break;                               //call function of Salary Calculator by pressing key "3"
			case '4': WorkDaysCalc(); break;                             //call function of Workdays Calculator by pressing key "4"
			case 27: byeMessage(); exit(0); break;                       //exit the program by pressing "Esc"
		
			default:                                                     //in another case display the warning message
				wrongKeyMessage(); flag = false; break;
		}
	}while(!flag);
}


void MathCalc(){
	float x,y;
	char sign, key;
	char str[30];
	char *s=str;
	bool retry;
	bool MCCheck;
			
	do{
		system("cls");
		char sMenuItem[80]="          MATHEMATICAL CALCULATOR";
		setStringConsoleColor(sMenuItem, 5);
		puts("");
		do {
			printf("Enter the first number: ");
			scanf ("%s", s);
			numberValidation(s);
			if (!numberValidation(s)) wrongKeyMessage();
		}while(!numberValidation(s));
		x = atof (s);
		do {
			printf("Enter the sign of operation (+, -, *, / or ^ for power): ");
			scanf("%s", &sign);
			if(sign!='+' && sign!='-' && sign!='*' && sign!='/' && sign!='^') wrongKeyMessage();
		} while(sign!='+' && sign!='-' && sign!='*' && sign!='/' && sign!='^');
		do{
			printf("Enter the second number: ");
			scanf ("%s", s);
			numberValidation(s);
			if (!numberValidation(s)) wrongKeyMessage();
		}while(!numberValidation(s));
		y = atof (s);
		
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, 14);
		switch(sign){
			case '+': printf("\n%.2f+%.2f=%.2f\n", x, y, x+y); break;
			case '-': printf("\n%.2f-%.2f=%.2f\n", x, y, x-y); break;
			case '*': printf("\n%.2f*%.2f=%.2f\n", x, y, x*y); break;
			case '/': printf("\n%.2f/%.2f=%.2f\n", x, y, x/y); break;
			case '^': printf("\n%.2f^%.2f=%.2f\n", x, y, pow(x,y)); break;
		}
		SetConsoleTextAttribute(handle,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		casesKeysSubMenuMessage();	
		
		do{
			retry=false;
			MCCheck=true;
			key=getch();
			switch(key){
				case 'y': 
				case 'Y':
				case 'í':
				case 'Í': retry=true; break;
				case 'M': 
				case 'm': 
				case 'Ü': 
				case 'ü': Menu(); break;
				case 27: byeMessage(); exit(0); break;
		
				default: wrongKeyMessage();	MCCheck=false; break;
			}
		}while(!MCCheck);
	}while(retry);
}

void VATCalc (){
	char key;
	bool MCCheck;
	char sMenuItem[80]="                  VAT CALCULATOR";
	char s2[80]="(Choose function that you want to use pressing the menu item number)";
	char s3[200]="Press key M if you want to return to the main menu \nPress Esc to quit the program";
	
	system("cls");
	setStringConsoleColor(sMenuItem, 5);
	puts("");
	setStringConsoleColor(s2, 11);
	puts("");
	puts("1. Finding the price with VAT and the amount of VAT from the price excluding VAT");
	puts("2. Finding the price without VAT and the amount of VAT from the price including VAT");
	puts("3. Calculation of net profit and VAT to pay from the amount of selling price and purchase price");
	puts("");
	setStringConsoleColor(s3, 11);
	do{
		MCCheck=true;
		key=getch();
		switch(key){
			case '1': VAT_price_ex(); break;
			case '2': VAT_price_inc(); break;
			case '3': VAT_profit(); break;
			case 'M': 
			case 'm': 
			case 'Ü':
			case 'ü': Menu(); break;
			case 27: byeMessage(); exit(0); break;
			default: wrongKeyMessage(); MCCheck=false; break;
		}
	}while(!MCCheck);
}

void VAT_price_ex(){
	float price_ex_VAT, VAT, price_inc_VAT;
	char key;
	bool validator, retry;
	char str[30];
	char *s=str;
	
	do{
		system("cls");
		puts("");
		char sMenuItem[80]="                  VAT CALCULATOR";
		setStringConsoleColor(sMenuItem, 5);
		char sSubMenuItem[200]="1. Finding the price with VAT and the amount of VAT from the price excluding VAT";
		setStringConsoleColor(sSubMenuItem, 3);
		do
	 	{
	  		printf("\nEnter the price excluding VAT: ");
			scanf ("%s", s);
			numberValidation(s);
			if (!numberValidation(s)) wrongKeyMessage();
	  	} while(!numberValidation(s));
	  	price_ex_VAT=atof (s);
	  		
	  	VAT=price_ex_VAT*0.2;
	  	price_inc_VAT=price_ex_VAT*1.2;
	  	puts("");
	  	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, 14);
		printf("VAT=%.2f\n", VAT);
		printf("The price including VAT=%.2f\n", price_inc_VAT);
		SetConsoleTextAttribute(handle,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		casesKeysSub2MenuMessage();
			
		do{
			validator=true;	
			retry=false;
			key=getch();
			switch(key){
				case 'y': 
				case 'Y': 
				case 'í': 
				case 'Í': retry=true; break;
				case 'b': 
				case 'B': 
				case 'è': 
				case 'È': VATCalc (); break;
				case 'M': 
				case 'm': 
				case 'Ü': 
				case 'ü': Menu(); break;
				case 27: byeMessage(); exit(0); break;
				default: wrongKeyMessage(); validator=false; break;
			}
		}while(!validator);
	}while(retry);
}
	
void VAT_price_inc(){
	float price_inc_VAT, VAT, price_ex_VAT;
	char key;
	bool validator, retry;
	char str[30];
	char *s=str;
	char sMenuItem[80]="                  VAT CALCULATOR";
	char sSubMenuItem[200]="2. Finding the price without VAT and the amount of VAT from the price including VAT";
	
	do{
		system("cls");
		puts("");
		setStringConsoleColor(sMenuItem, 5);
		setStringConsoleColor(sSubMenuItem, 3);
		do
	 	{
	  		printf("\nEnter the price including VAT: ");
			scanf ("%s", s);
			numberValidation(s);
			if (!numberValidation(s)) wrongKeyMessage();
	  	} while(!numberValidation(s));
	  	price_inc_VAT=atof (s);
	  		
		VAT=price_inc_VAT/6;
	  	price_ex_VAT=price_inc_VAT/1.2;
	  	puts("");
	  	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, 14);
		printf("VAT=%.2f\n", VAT);
		printf("The price excluding VAT=%.2f\n", price_ex_VAT);
		SetConsoleTextAttribute(handle,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		casesKeysSub2MenuMessage();
		do{
			validator=true;	
			retry=false;
			key=getch();	
			switch(key){
				case 'y': 
				case 'Y': 
				case 'í': 
				case 'Í': retry=true; break;
				case 'b':
				case 'B': 
				case 'è': 
				case 'È': VATCalc (); break;
				case 'M': 
				case 'm': 
				case 'Ü': 
				case 'ü': Menu(); break;
				case 27: byeMessage(); exit(0); break;
				default: wrongKeyMessage(); validator=false;	break;
			}
		}while(!validator);
	}while(retry);
}

void VAT_profit(){
	float purchase_price,  selling_price, check_num;
	char key;
	bool validator, retry;
	char str[30];
	char *s=str;
	char sMenuItem[80]="                  VAT CALCULATOR";
	char sSubMenuItem[200]="3. Calculation of net profit and VAT to pay from the amount of selling price and purchase price";
	
	do{
		system("cls");
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		puts("");
		setStringConsoleColor(sMenuItem, 5);
		setStringConsoleColor(sSubMenuItem, 3);
		do
	 	{
	  		printf("\nEnter the purchase price: ");
			scanf ("%s", s);
			numberValidation(s);
			if (!numberValidation(s)) wrongKeyMessage();
	  	} while(!numberValidation(s));
	 	purchase_price=atof (s);
		
		do
	 	{
	  		printf("Enter the selling price: ");
			scanf ("%s", s);
			numberValidation(s);
			if (!numberValidation(s)) wrongKeyMessage();
	  	} while(!numberValidation(s));
	  	selling_price=atof (s);
		
		if ((selling_price-purchase_price)<0) {
			puts("");
			SetConsoleTextAttribute(handle, 4);
			printf("WARNING! This operation is money-losing.\n");
			SetConsoleTextAttribute(handle,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		else{
			puts("");
			SetConsoleTextAttribute(handle, 14);
			printf("VAT to pay in the budget is the difference of VAT of purchase price (%.2f)and VAT of selling price (%.2f) = %.2f\n", purchase_price/6, selling_price/6, (selling_price-purchase_price)/6);
			printf("Net profit = %.2f\n", (selling_price-purchase_price)/1.2);
			SetConsoleTextAttribute(handle,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		casesKeysSub2MenuMessage();
		do{
			validator=true;	
			retry=false;
			key=getch();	
			switch(key){
				case 'y': 
				case 'Y': 
				case 'í': 
				case 'Í': retry=true; break;
				case 'b': 
				case 'B':
				case 'è': 
				case 'È': VATCalc (); break;
				case 'M': 
				case 'm': 
				case 'ü': 
				case 'Ü': Menu(); break;
				case 27: byeMessage(); exit(0); break;
				default: wrongKeyMessage(); validator=false; break;
			}	
		}while(!validator);	
	}while(retry);
}

void SalaryCalc(){
	char key;
	bool validator;
	char sMenuItem[80]="                  SALARY CALCULATOR";
	char s2[80]="(Choose function that you want to use pressing the menu item number)";
	char s3[200]="Press key M if you want to return to the main menu \nPress Esc to quit the program";
	
	system("cls");
	puts("");
	setStringConsoleColor(sMenuItem, 5);
	puts("");
	setStringConsoleColor(s2, 11);
	puts("");
	puts("1. Finding salary taxes and the amount of take-home pay from the value of wage rate");
	puts("2. Finding the wage rate and salary taxes from the value of take-home pay");
	puts("");
	setStringConsoleColor(s3, 11);
	do{
		validator=true;	
		key=getch();
		switch(key){
			case '1': Salary_w(); break;
			case '2': Salary_th(); break;
			case 'M': 
			case 'm': 
			case 'Ü': 
			case 'ü': Menu(); break;
			case 27: byeMessage(); exit(0); break;
			default: wrongKeyMessage(); validator=false;	break;
		}
	}while(!validator);
}

void Salary_w(){
	char key;
	bool validator, retry;
	float WR, VZ, PDFO, ESV, S, check_num;
	char str[30];
	char *s=str;
	float ESVmin=819.06;                                                      //minimum value of ESV for Ukraine in 2018
	float ESVmax=12285.90;
	char sMenuItem[80]="                  SALARY CALCULATOR";
	char sSubMenuItem[200]="1. Finding salary taxes and the amount of take-home pay from the value of wage rate";
	
	do{
	system("cls");
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	puts("");
	setStringConsoleColor(sMenuItem, 5);
	setStringConsoleColor(sSubMenuItem, 3);
	do
	 	{
	  		printf("\nEnter the wage rate: ");
			scanf ("%s", s);
			numberValidation(s);
			if (!numberValidation(s)) wrongKeyMessage();
	  	} while(!numberValidation(s));
	  	WR=atof (s);
		VZ=0.015*WR;
		PDFO=0.18*WR;
		ESV=0.22*WR;
		if(ESV<ESVmin) ESV=ESVmin;
		if(ESV>ESVmax) ESV=ESVmax;
		S=WR-VZ-PDFO;
		puts("");
		SetConsoleTextAttribute(handle, 14);
		printf("Military duty=%.2f\n", VZ);
		printf("PDFO=%.2f\n", PDFO);
		printf("ESV=%.2f\n", ESV);
		printf("Take-home pay=%.2f\n", S);
		printf("General credit of operation=%.2f\n", WR+ESV);
		SetConsoleTextAttribute(handle,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		casesKeysSub2MenuMessage();
		puts("\n");
		do{
			validator=true;
			retry=false;	
			key=getch();	
			switch(key){
				case 'y': 
				case 'Y': 
				case 'í': 
				case 'Í': retry=true; break;
				case 'b': 
				case 'B': 
				case 'è': 
				case 'È': SalaryCalc(); break;
				case 'M':
				case 'm': 
				case 'Ü':
				case 'ü': Menu(); break;
				case 27: byeMessage(); exit(0); break;
				default: wrongKeyMessage(); validator=false;	break;
			}
		}while(!validator);	
	}while(retry);
}

void Salary_th(){
	char key;
	char str[30];
	char *s=str;
	bool validator, retry;
	float WR, VZ, PDFO, ESV, S, check_num;
	float ESVmin=819.06;
	float ESVmax=12285.90;
	char sMenuItem[80]="                  SALARY CALCULATOR";
	char sSubMenuItem[200]="2. Finding the wage rate and salary taxes from the value of take-home pay";
	
	do{
		system("cls");
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		puts("");
		setStringConsoleColor(sMenuItem, 5);
		setStringConsoleColor(sSubMenuItem, 3);
		do{
	  		printf("\nEnter the take-home pay: ");
			scanf ("%s", s);
			numberValidation(s);
			if (!numberValidation(s)) wrongKeyMessage();
	  	} while(!numberValidation(s));
	  	S=atof (s);
		WR=1/0.805*S;
		VZ=0.015*WR;
		PDFO=0.18*WR;
		ESV=0.22*WR;
		if(ESV<ESVmin) ESV=ESVmin;
		if(ESV>ESVmax) ESV=ESVmax;
		puts("");
		SetConsoleTextAttribute(handle, 14);
		printf("The wage rate=%.2f\n", WR);
		printf("Military duty=%.2f\n", VZ);
		printf("PDFO=%.2f\n", PDFO);
		printf("ESV=%.2f\n", ESV);
		printf("General credit of operation=%.2f\n", WR+ESV);
		SetConsoleTextAttribute(handle,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		casesKeysSub2MenuMessage();
		puts("\n");
		do{
			validator=true;	
			retry=false;
			key=getch();	
			switch(key){
				case 'y': 
				case 'Y': 
				case 'í': 
				case 'Í': retry=true; break;
				case 'b': 
				case 'B': 
				case 'è': 
				case 'È': SalaryCalc(); break;
				case 'M': 
				case 'm': 
				case 'ü': 
				case 'Ü': Menu(); break;
				case 27: byeMessage(); exit(0); break;
				default: wrongKeyMessage();	validator=false; break;
			}
		}while(!validator);	
	}while(retry);
}

void WorkDaysCalc(){
	int m, n, year, day, work_day, rest_day;
	char key;
	char str[30];
	char *s=str;
	bool MCCheck, retry;
	char sMenuItem[80]="    Calculation of working days and days off per month";
	
	do{
		 m=0, n=0, year=0, day=0, work_day=0, rest_day=0;
		system("cls");
		puts("");
		setStringConsoleColor(sMenuItem, 5);
		puts("");
		do {
			printf("\nEnter the number of the month of a year /1 - January, 2 - February, ... , 12 - December/: ");
			scanf ("%s", s);
			numberValidation(s);
			if (numberValidation(s)){
				m = atoi(s);
				if (m<1 || m>12) wrongKeyMessage();
			}
			else wrongKeyMessage();
		}while(!numberValidation(s) || m<1 || m>12);
		
		switch(m){
			case 1: n=31; break;
			case 2: printf("Enter the year: ");
				scanf("%i", &year);
				if (year%4==0){
					if (year%100==0){
						if (year%400==0) n=29; else n=28;
					} else n=28;
				} else n=28; break;
			case 3: n=31; break;
			case 4: n=30; break;
			case 5: n=31; break;
			case 6: n=30; break;
			case 7: n=31; break;
			case 8: n=31; break;
			case 9: n=30; break;
			case 10: n=31; break;
			case 11: n=30; break;
			case 12: n=31; break;
		}
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, 14);
		printf("This month has %i days.", n);
		SetConsoleTextAttribute(handle,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		printf("\n");
		do{
			printf("Enter the day of the week for the first date of the month /1 - Monday, 2 - Tuesday, ... , 7 - Sunday/: ");
			scanf ("%s", s);
			numberValidation(s);
			if (numberValidation(s)){
				day = atoi(s);
				if (day<1 || day>7) wrongKeyMessage();
			}
			else wrongKeyMessage();
		}while(!numberValidation(s) || day<1 || day>7);
			
		if(day==6 || day==7) rest_day+=(7-day+1);
		if (day>0 && day<6){
			work_day+=(6-day);
			rest_day+=2;	
		}
		n=n-7+day-1;
		while(n>=7){
 			work_day+=5;
			rest_day+=2;	
			n=n-7;
		}
  		if (n>5){
 			work_day+=5;
 			rest_day+=(n-5);
		 }
 		else 	work_day+=n;
		SetConsoleTextAttribute(handle, 14);
		printf("This month has %i working days and %i days off.\n", work_day, rest_day);
		SetConsoleTextAttribute(handle,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		puts("");
		casesKeysSubMenuMessage();
		do{
			MCCheck=true; retry=false;
			key=getch();	
			switch(key){
				case 'y':
				case 'Y':
				case 'í': 
				case 'Í': retry=true; break;
				case 'M': 
				case 'm': 
				case 'ü': 
				case 'Ü': Menu(); break;
				case 27: byeMessage(); exit(0); break;
				default: wrongKeyMessage(); MCCheck=false; break;
			}
		}while(!MCCheck);
	}while(retry);
}

void setStringConsoleColor(char *str, int color){
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color);
    puts(str);
    SetConsoleTextAttribute(handle,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	
}

void wrongKeyMessage(){
	char sError[40]="Invalid input. Try again!";
	setStringConsoleColor(sError, 4);
}

void byeMessage(){
	system("cls");
	char sBye[60]="\n\n\n\n\n                  Thank you for using our program!\n\n\n";
	setStringConsoleColor(sBye, 10);
}

void casesKeysSubMenuMessage(){
	char message[200]="Press Y if you want to retry the operation \nPress key M if you want to return to the main menu \nPress Esc to quit the program";
	puts("");
	setStringConsoleColor(message, 11);
	puts("");
}

void casesKeysSub2MenuMessage(){
	char message[200]="Press Y if you want to retry the operation\nB - back in the previous menu\nM - in the main menu\nEcs - to quit the program";
	puts("");
	setStringConsoleColor(message, 11);
	puts("");
}

bool numberValidation(char *s){
	int i;
	bool check;
	for (i=0;i<strlen(s);i++)
		{
			check=true;
			if(((*(s+i)<'0') || (*(s+i)>'9'))&&(*(s+i)!='.'))
			{
				check=false;
				break;
			}
		}
	return check;
}

bool intNumberValidation(char *s){
	int i;
	bool check;
	for (i=0;i<strlen(s);i++)
		{
			check=true;
			if(((*(s+i)<'0') || (*(s+i)>'9')))
			{
				check=false;
				break;
			}
		}
	return check;
}

