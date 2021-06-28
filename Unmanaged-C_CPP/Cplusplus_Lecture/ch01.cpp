#include <iostream>
/*
ÇÔ¼ö¿Í ³×ÀÓ ½ºÆäÀÌ½º
ÇÔ¼ö ´ÙÇü¼ºÀ» Á¦°øÇÑ´Ù!!
void TestFunc(int a);
void TestFunc(char * a);
ÀÌ·±½ÄÀ¸·Î ÇÔ¼ö¸¦ ¼±¾ğÇÒ ¼ö ÀÖ´Ù!!

Override ÀçÁ¤ÀÇ
OVerloading ´ÙÁß Á¤ÀÇ

C++¿¡¼­ ÀçÁ¤ÀÇ ´ÙÁß Á¤ÀÇÀÌ °¡´ÉÇÑ ÀÌÀ¯´Â ´ÙÁß Á¤ÀÇÇÒ ÇÔ¼ö¸¦ ¿øÇü¸¸ ¾²°í Á¤ÀÇÇÏÁö ¾Ê°í ÄÄÆÄÀÏ ÇÏ°Ô µÇ¸é
ÇÔ¼öÀÇ ¿øÇüÀÌ º¸ÀÌ°í µÚ¿¡´Â ÇÔ¼öÀÇ º»¸íÀ» º¼ ¼ö ÀÖ´Â´Ù >> ÀÌ¿Í °°ÀÌ ÄÄÆÄÀÏ µÇ´Â °ÍÀ» name manglingÀÌ¶ó°í ÇÑ´Ù!!


ÇÔ¼ö ´ÙÁß Á¤ÀÇ
ÇÔ¼ö ÀÌ¸§Àº ÇÏ³ª ÀÎµ¥ ¿©·¯ ÀÇ¹Ì¸¦ µ¿½Ã¿¡ °®´Â°ÍÀ» ¸»ÇÑ´Ù!!

C++ ÅÛÇÃ¸´ÀÌ¶ó´Â °³³äÀÌ ÀÖ°í Class , Fucntion¿¡ ÁÖ·Î »ç¿ëµÈ´Ù 
ÀÌ ÅİÇÃ¸´Àº ÁÖ·Î Âï¾î ³¾¶§ »ç¿ëµÈ´Ù!!
Typescript , JavaÁ¦³×¸¯ °°Àº ´À³¦ÀÌ ÀÖ´Ù

C++ namespace´Â ¼Ò¼Ó°ú °°´Ù°í »ı°¢ÇÏ¸é µÈ´Ù!!

*/


/*
void TestFunc(int a, int b = 100);
int Add(int a, int b);

double Add(double a, double b);
*/
//ÇÔ¼ö ÅÛÇÃ¸´À¸·Î ¶È°°ÀÌ ±¸Çö ÇÒ ¼ö ÀÖ´Ù!!
//TÀÇ ÀÚ·áÇüÀº caller¿¡ µû¶ó Á¤ÇØÁø´Ù!!
template <typename T>
T Add(T a, T b)
{
	return a + b;
}
int ADD(int a, int b) {
	printf("global Function\n");
	return a + b;
}
 namespace Test {
	//Àü¿ª º¯¼ö·Î ¼±¾ğµÈ´Ù!!
	int g_nData = 100;
	int b = 100;
	/*
	ADD ¶ó´Â ÇÔ¼ö¸¦ Àü¿ª¿¡µµ ¼±¾ğÇÏ°í namespace¿¡µµ ¼±¾ğÇÏ°Ô µÈ´Ù¸é ÇöÀç TestFunc¿¡¼­ ¼±¾ğÇÑ ADD´Â namespaceºÎÅÍ ADDÇÔ¼ö¸¦ ¯±â ¶§¹®¿¡ namespaceÀÇ ÇÔ¼ö°¡ ½ÇÇàµÇ´Â¸ğ½ÀÀ» º¼ ¼ö ÀÖ´Ù
	*/
	int ADD(int a, int b) {
		printf("Test Namesace ADD function\n");
		return a + b;
	}
	
	void TestFunc() {
		std::cout << "Test NameSpace TestFunction" << std::endl;
		ADD(10, 20);
	}
	namespace DEV {
		void TestFunc() {
			std::cout << "Dev NameSpace TestFunction" << g_nData << std::endl;
		}	
		namespace WIN {
			int g_nData = 300;
		}
	}

}
 using namespace Test;
 using namespace std;
//usingÀ» namespace¿¡ »ç¿ë ÇÏ¸é namespace¸¦ »ı·« ÇÒ ¼ö ÀÖ´Ù
//ÇÏÁö¸¸ ½Äº°ÀÚ °Ë»ö ÇÒ¶§ ¹®Á¦°¡ ¹ß»ı ÇÑ´Ù!!
 //Àü¿ª (°³³ä»óÀ¸·Ğ ¹«¼Ò¼Ó)
 void PrintString(void) { cout << "::TestFunction()" << endl; }

 namespace Print {
	 //Print ³×ÀÓ ½ºÆäÀÌ½º ¼Ò¼Ó
	 void PrintString(void) { cout << "Print::TestFunction()" << endl; }
 }
 //usingÀ» ÅëÇØ¼­ Print¸¦ »ı·«ÇÏ°í PrintStringÀ» ÇÏ°Ô µÇ¸é ÄÄÆÄÀÏ·¯°¡ ÀÚÃ¼ÀûÀ¸·Î ¸ğÈ£¼ºÀÌ ¹ß°ßµÇ¾ú´Ù°í ¿À·ù°¡ ¹ß»ı ÇÑ´Ù!!
 //using namespace Print;

int main(void) {
	//::¹üÀ§ ÁöÁ¤ ¿¬»êÀÚ¶ó°í ÇÑ´Ù Test(¹üÀ§,¼Ò¼Ó)::a; 
	TestFunc();
	DEV::TestFunc();
	std::cout << "TEST  "<< Test::g_nData << "    " << Test::DEV::WIN::g_nData << std::endl;
	std::cout << Add(10, 20)<<'\t' <<Test::b << std::endl;
	std::cout << Add(10.55, 20.12) << std::endl;
	//c¾ğ¾î¿Í ´Ù¸£°Ô ÇÔ¼ö ¼±¾ğ½Ã ÀÌ¸§¸¸ ¼±¾ğÇØÁÖ´Â °ÍÀÌ ¾Æ´Ï¶ó  ¼Ò¼Ó±îÁö ½áÁÖ´Â°ÍÀÌ ¸Â´Ù!! 
	//Àü¿ª , ¹«¼Ò¼Ó ÀÏ¶§ :: »ç¿ëÇØÁÖ´Â °ÍÀÌ ¸Â´Ù!!
	::PrintString();
	Print::PrintString();

}





 