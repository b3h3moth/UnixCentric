#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char *argv[]) {
    // Connessione al database
    sqlite3        *db = NULL;
    // Database filename
