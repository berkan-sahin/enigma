#include <iostream>
#include <stdio.h>
#define DEBUG 0

char etw[]    = "QWERTZUIOASDFGHJKPYXCVBNML";
char type1[]  = "LPGSZMHAEOQKVXRFYBUTNICJDW";
char type2[]  = "SLVGBTFXJQOHEWIRZYAMKPCNDU";
char type3[]  = "CJGDPSHKTURAWZXFMYNQOBVLIE";
char rev[]    = "IMETCGFRAYSQBZXWLHKDVUPOJN";
char type3r[] = "LVADZPCGYBHXQSVETKFIJWMORN";
char type2r[] = "SEWYMGDLOIUBTXKVJPAFZCNHRQ";
char type1r[] = "HRWYIPCGVXLAFUJBKODTSMZNQE";
char input;
char buffer;
unsigned int pos1,pos2,pos3 = 1; 
char uppercase(char input);
char rotor(char input, char rotor[], unsigned int pos);
char reverserotor(char input, char rotor[], unsigned int pos);
int main(void){

	printf("Type in a dot to change rotor alignment\nType in a dash to quit\n");
	for(;;){
	  std::cin >> buffer;
	  int bojingles = (int)buffer;

		if(bojingles == 46) {

			printf("Type in 3 integers for rotor positions respectively for rotor 3, 2 and 1.\n");
			std::cin >> pos3;
			if((pos3 >26) || (pos3<=0)) pos3 = 1;
			printf("New position for rotor 3 is:%u\n", pos3);
			std::cin >> pos2;
			if((pos2 > 26) || (pos2<=0)) pos2 = 1;
			printf("New position for rotor 2 is:%u\n", pos2);
			std::cin >> pos1;
			if((pos1 > 26) || (pos1<=0)) pos1 = 1;
			printf("New position for rotor 1 is:%u\n", pos1);
		}
		
		else if(bojingles == 45) return 0;

		else{

		  	pos1++;
			if(pos1 > 26) pos1 = 1;
			if(pos1 == 8) pos2++;	
			if(pos2 > 26) pos2 = 1;
			if(pos2 == 15) pos3++;
			if(pos3 > 26) pos3 = 1;
			
			input = uppercase(buffer);
			//if(DEBUG) std::cout << "uppercase "<< input << std::endl;
			//input = rotor(input, etw, 1);
			//if(DEBUG) std::cout <<"etw "<< input << std::endl;
			input = rotor(input, type1, pos1);
			if(DEBUG) std::cout <<"rotor1-1 "<< input << std::endl;
			input = rotor(input, type2, pos2);
			if(DEBUG) std::cout <<"rotor2-1 "<< input << std::endl;
			input = rotor(input, type3, pos3);
			if(DEBUG) std::cout <<"rotor3-1 "<< input << std::endl;
			input = rotor(input, rev, 1);
			if(DEBUG) std::cout <<"reverse "<< input << std::endl;
			input = reverserotor(input, type3r, pos3);
			if(DEBUG) std::cout <<"rotor3-2 "<< input << std::endl;
			input = reverserotor(input, type2r, pos2);
			if(DEBUG) std::cout <<"rotor2-2 "<< input << std::endl;
			input = reverserotor(input, type1r, pos1);
			if(DEBUG) std::cout <<"rotor1-2 "<< input << std::endl;
			//input = rotor(input, etw, 1);
			printf("%c\n", input);
			printf("Positions of the rotors are:\n %u-%u-%u\n", pos3 , pos2 ,pos1);
		

		}



	}
	return 1;
}

char uppercase(char input){

  int heleloy = (int)input;
  if(heleloy >= 97) return (char)(heleloy-32);
  else return (char)heleloy;
  
}

char rotor(char input, char rotor[], unsigned int pos){

  int heleloy = (int)input;
  heleloy = heleloy-66+pos;
  if(heleloy > 25) heleloy = heleloy-26;
  //if(DEBUG) std::cout << heleloy <<std::endl;
  return rotor[heleloy];
  
}   

char reverserotor(char input, char rotor[], unsigned int pos){

  int heleloy;
  char altrotor[26];
  for(int i = 0; i < 26; i++){

    heleloy = ((int)rotor[i])-pos+1;
    if(heleloy < 65) heleloy = heleloy+26;
    altrotor[i] = (char)heleloy;
  }
  
  int a = (int)input;
  a = a-65;
  if(a > 25) a = a-26;
  //if(DEBUG) std::cout << a <<std::endl;
  return altrotor[a];
}

    
