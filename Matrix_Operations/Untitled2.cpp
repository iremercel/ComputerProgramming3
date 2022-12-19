#include <stdio.h>
#include <iostream>
#include <string>



using namespace std;
class Personel {
	public:

  string adi;
  string soyadi;
  int numara;
  
  void yazdir(){
  	cout<<"Adi: "<<adi<<" Soyadi:"<<soyadi<<" Numara:"<<numara<<end1;
  }


};

 void degistir(Personel p, string a, string s, int n)
{
	 
	  Personel yeni;
	  yeni.adi=a;
	  yeni.soyadi=s;
	  yeni.numara=n;
	  p=yeni;
}
int main() {
  
  Personel per1, per2;
  per1.adi ="Asdfg";
  per1.soyadi= "wewrt";
  per1.numara=3456;
  per1.yazdir();
  
  degistir(p1, "ece", "on", 2);
  per1.yazdir();
  
  p3->adi="selen";
  p3->soyadi="sel";
  p3->numara=34;
  p3->yazdir();
  
  delete p3;
  
  return 0;
}
