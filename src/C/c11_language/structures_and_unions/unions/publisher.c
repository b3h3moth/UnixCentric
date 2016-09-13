#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30
#define A_SIZE 100
#define T_SIZE 20
#define ITEMS_SIZE 50
#define NR_STORE 3
#define NR_ITEMS 10
#define BOOK_STORE 0
#define CLOTHING_STORE 1
#define COMPUTER_STORE 2

int main(void) {
    struct Publisher {
        // Dati condivisi inerenti la casa editrice
        char name[SIZE];
        char address[A_SIZE];
        char shopping_center_tel[T_SIZE];

        struct {
            // dati condivisi inerenti il libro
            char name[SIZE];
            char genre[SIZE];
            int floor;
            int store_nr;

            struct {
                // dati comuni per ogni item
                float price;
                int general_item_code;
                
                union {
                    struct { // dati libro
                        char title[ITEMS_SIZE];
                        char author[ITEMS_SIZE];
                        int number_of_pages;
                    } book;

                    struct { // dati abbigliamento
                        char type[ITEMS_SIZE];
                        int size;
                        char color[ITEMS_SIZE];
                    } clothing;

                    struct {// struttura per un computer
                        char model_name[ITEMS_SIZE];
                        int ram; // in GByte
                        int cpu_speed; // in GHertz
                        int hd_capacity; // in GByte
                        _Bool printer;
                        _Bool scanner;
                        _Bool integrated_video_card;
                    } computer;
                };
            
            } item[NR_ITEMS];
            
        } store[NR_STORE]; 
    };

    struct Publisher sc;

    // Informazioni inerenti la casa editrice
    strcpy(sc.name, "Informit Publishing");
    strcpy(sc.address, "New York (USA)");
    strcpy(sc.shopping_center_tel, "123/4567890");

    // Informazioni inerenti la casa di produzione e il genere
    strcpy(sc.store[BOOK_STORE].name, "Addison Wesley");
    strcpy(sc.store[BOOK_STORE].genre, "Computer Science");

    // valorizzazione di un item di un negozio tra: book, clothing o computer 
    sc.store[BOOK_STORE].item[0].general_item_code = 19982;
    sc.store[BOOK_STORE].item[0].price = 45.00f; // in EURO

    strcpy(sc.store[BOOK_STORE].item[0].book.title, "Expert C Programming");
    strcpy(sc.store[BOOK_STORE].item[0].book.author, "P.D.D");
    sc.store[BOOK_STORE].item[0].book.number_of_pages = 682;

    printf("%s\n%s\n%s\n", sc.name, sc.address, sc.shopping_center_tel);
    printf("-----------------------\n");
    printf("Libro: %s di %s\nPrezzo: %.2f Euro acquistabile presso"
           "la libreria %s [%s]\n",
           sc.store[BOOK_STORE].item[0].book.title, 
           sc.store[BOOK_STORE].item[0].book.author,
           sc.store[BOOK_STORE].item[0].price, sc.store[BOOK_STORE].name,
           sc.store[BOOK_STORE].genre);

    return (EXIT_SUCCESS);
}
