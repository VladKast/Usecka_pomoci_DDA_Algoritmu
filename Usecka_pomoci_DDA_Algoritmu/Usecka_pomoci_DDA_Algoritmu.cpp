#include <cmath>
#include <iostream>
#include <Windows.h>

HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);
COORD koordinaceMonitoru;

//funkce pro vykresleni pixelu na konzoli
void zakreslitPixel(int x, int y) {
    koordinaceMonitoru.X = x;
    koordinaceMonitoru.Y = y;
    SetConsoleCursorPosition(a, koordinaceMonitoru);
    std::cout << '.';
    Sleep(50);
}
// fce pro vykrelseni usecky
void vykreslitUseckuDDA(double pocatecniBodX, double pocatecnitBodY, int koncovyBodX, int koncovyBodY) {
    int vx = koncovyBodX - pocatecniBodX,
        vy = koncovyBodY - pocatecnitBodY,

        krokVykresleni = abs(vx); // abs = absolutní hodnota 
    double vykresleniX = (double)vx / krokVykresleni;
    double vykresleniY = (double)vy / krokVykresleni;

    while (krokVykresleni != 0) {
        zakreslitPixel(round(pocatecniBodX), round(pocatecnitBodY));
        pocatecniBodX += vykresleniX;
        pocatecnitBodY += vykresleniY;
        krokVykresleni--;
    }
}

int main()
{
    vykreslitUseckuDDA(1, 1, 25, 25);
    system("color a");
    system("pause");

}


