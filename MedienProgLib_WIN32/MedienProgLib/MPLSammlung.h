#include <stdio.h>;

void f1();
void GoToPos(int x, int y);
void GoToPosZero();
void AusgabeViereck(int breite, int hoehe, char buchstabe);
void AusgabeRaute(int anzahl, char buchstabe, int sx, int sy);
char** CreateFillArray();

//Aufg3
void Zeichne_Stein(int sx, int sy);
void GetViereckArr(int breite, int hoehe, char buchstabe);
void ClearCurrentArray();
void Erstelle_Stein(int breite, int hoehe, char buchstabe, int x, int y, int geometryType);