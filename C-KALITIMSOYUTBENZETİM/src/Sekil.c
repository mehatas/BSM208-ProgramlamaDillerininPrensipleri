#include "Sekil.h"

char* ZamanGetir(){
	char* str = malloc(sizeof(char)*100);
	time_t suan = time(0);
	strftime(str,100,"%Y-%m-%d %H:%M",localtime(&suan));
	return str;
}
int Uzunluk(double deger){
	char str[50];
	sprintf(str,"%lf",deger);
	int uzunluk = strlen(str);
	return uzunluk;
}

Sekil SekilOlustur(char* renk){
	Sekil this;
	this = (Sekil)malloc(sizeof(struct SEKIL));
	this->renk=renk;
	this->olusturulmaTarihi=ZamanGetir();
	
	this->setRenk = &setRenk;
	this->getTarih = &getTarih;
	this->toString = &toString;
	this->yoket = &SekilYoket;
	return this;
}
void setRenk(const Sekil this, char* renk){
	this->renk=renk;
}
char* getTarih(const Sekil this){
	return this->olusturulmaTarihi;	
}
char* toString(const Sekil this,void* p){
	int toplamUzunluk=36;
	toplamUzunluk+= strlen(this->olusturulmaTarihi);
	toplamUzunluk+= strlen(this->renk);
	toplamUzunluk+=Uzunluk(this->Alan(p));
	toplamUzunluk+=Uzunluk(this->Cevre(p));
	char *str=(char*)malloc(sizeof(char)*toplamUzunluk+1);
	sprintf(str,"\n\nTarih: %s\nRenk: %s\nAlan: %lf\nCevre: %lf",
											this->olusturulmaTarihi,
											this->renk,
											this->Alan(p),
											this->Cevre(p));
	return str;
}
void SekilYoket(const Sekil this){
	if(this==NULL) return;
	free(this->olusturulmaTarihi);
	free(this);
	
}