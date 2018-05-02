#include <iostream>
#include <stdio.h>
#define DEBUG 0
/**********************************************
 *    Dijital Enigma D                        *
 *Hazırlayanlar: Özgün Bozay ve Berkan Şahin  *
 *                                            *
 *Giriş olarak aldığı karakteri rotorlar      *
 *üzerinden geçirerek çıkışa şifrelenmiş      *
 *olarak verir                                *
 *                                            *
 **********************************************/

/*****************************************************************
 *Rotor tanımlamları:                                            *
 *rotorlardaki harflerin sıraları gerçek Enigma'daki             *
 *rotorların a'dan z'ye girişlerinin bağlantılarını temsil eder. *
 *Örn: type1'de a ->l , b -> p vs.                               *
 *****************************************************************/

char etw[]    = "QWERTZUIOASDFGHJKPYXCVBNML";
char type1[]  = "LPGSZMHAEOQKVXRFYBUTNICJDW";
char type2[]  = "SLVGBTFXJQOHEWIRZYAMKPCNDU";
char type3[]  = "CJGDPSHKTURAWZXFMYNQOBVLIE";
char rev[]    = "IMETCGFRAYSQBZXWLHKDVUPOJN";
char type3r[] = "LVADZPCGYBHXQSVETKFIJWMORN";
char type2r[] = "SEWYMGDLOIUBTXKVJPAFZCNHRQ";
char type1r[] = "HRWYIPCGVXLAFUJBKODTSMZNQE";
//Geçici değişken tanımlama
char input;
char buffer;
//Pozisyon değişkenleri tanımlama
unsigned int pos1,pos2,pos3 = 1;

//Ana program içinde kullanılacak foksiyonların tanımlanması
char uppercase(char input);
char rotor(char input, char rotor[], unsigned int pos);
char reverserotor(char input, char rotor[], unsigned int pos);
int main(void){

	printf("Dijital Enigma D\nHazirlayanlar: Ozgun Bozay ve Berkan Sahin\n\n");

	//Sonsuz döngü
	for(;;){
	  printf("Rotor pozisyonlarini degistirmek icin \".\" karakterini yazin.\nProgramdan cikis icin \"-\" karakterini yazin.\n");
	  //Kullanıcıdan bir karakter istenir
	  std::cin >> buffer;
	  //kullanıcıdan alınan karakter ASCII'deki sayı karşılığı olarak atanır
	  int bojingles = (int)buffer;
	  //Kullanıcdan alınan karakterin . veya - olup olmadığı kontrol edilir.
		if(bojingles == 46) {

			printf("Sirasiyla rotor 3,2 ve 1\'in pozisyonlarini belirlemek icin 3 adet tamsayi yazin.\n");
			std::cin >> pos3;
			if((pos3 >26) || (pos3<=0)) pos3 = 1;
			printf("Rotor 3\'un yeni pozisyonu:%u\n", pos3);
			std::cin >> pos2;
			if((pos2 > 26) || (pos2<=0)) pos2 = 1;
			printf("Rotor 2\'nin yeni pozisyonu:%u\n", pos2);
			std::cin >> pos1;
			if((pos1 > 26) || (pos1<=0)) pos1 = 1;
			printf("Rotor 1\'in yeni pozisyonu:%u\n", pos1);
		}

		else if(bojingles == 45) return 0;
		else if(bojingles > 127){

		  printf("Gecersiz karakter.\n");
		  return 1;
		}
		else{

		        //Rotor pozisyonlarının arttırılması
		        pos1++;
			if(pos1 > 26) pos1 = 1;
			if(pos1 == 8) pos2++;
			if(pos2 > 26) pos2 = 1;
			if(pos2 == 15) pos3++;
			if(pos3 > 26) pos3 = 1;

			//Değişkenin yeniden karakter olması ve büyük harfe dönüştürülmesi

			input = uppercase(buffer);
			//if(DEBUG) std::cout << "uppercase "<< input << std::endl;
			//input = rotor(input, etw, 1);
			//if(DEBUG) std::cout <<"etw "<< input << std::endl;

			//input değişkeni sırayla rotorlardan geçer
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

			//Sonuç olan harfi ve rotor pozisyonlarını yaz
			printf("%c\n", input);
			printf("Rotor Pozisyonlari:\n%u-%u-%u\n", pos3 , pos2 ,pos1);


		}



	}
	return 2;
}

char uppercase(char input){

  int heleloy = (int)input;
  if(heleloy >= 97) return (char)(heleloy-32);
  else return (char)heleloy;

}

char rotor(char input, char rotor[], unsigned int pos){

  /*********************************************************************
  *Bu fonksiyonda karakterler rotor pozisyonuna göre 0 ile 25 arasında *
  *bir değer alır (Enigma'daki A-Z girişleri). Daha sonra bu değer     *
  *verilen rotor üzerine yerleştirilip çıkan sonuç dışarı verilir      *
  *********************************************************************/

  int heleloy = (int)input;
  heleloy = heleloy-66+pos;
  if(heleloy > 25) heleloy = heleloy-26;
  //if(DEBUG) std::cout << heleloy <<std::endl;
  return rotor[heleloy];

}

char reverserotor(char input, char rotor[], unsigned int pos){

  /*************************************************************************************
   *Bu fonksiyonda Enigma'nın doğası dikkate alınarak verilen rotor dizisi üzerinde    *
   *oynamalar yapılıp tersi çıkarılır. Daha sonra bu dizi üzerinde diğer rotor         *
   *fonksiyonu uygulanır.                                                              *
   *************************************************************************************/

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


