#include <stdio.h>

void simple_menu() {
    double kebap, lahmacun, pide, doner, kola, su, kunefe, sutlac;
    int option = 0;
    kebap = 75.99;
    lahmacun = 21.50;
    pide = 40.00;
    doner = 55.60;
    kola = 15.00;
    su = 5.00;
    kunefe = 60.00;
    sutlac = 32.50;
    
    printf("Menu:\n1.Kebap\n2.Lahmacun\n3.Pide\n4.Döner\n5.Kola\n6.Su\n7.Künefe\n8.Sütlaç");
    while(option != 0) {
        printf("Please choose a product from the menu:");
        scanf(" %d", &option);
        getchar();
        
    }
}

int main() {

}