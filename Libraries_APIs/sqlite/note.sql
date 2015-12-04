CREATE TABLE hostnote(
    id INTEGER PRIMARY KEY AUTOINCREMENT, 
    data DATE NOT NULL, 
    ora TIME NOT NULL, 
    testo TEXT NOT NULL,
    unique(testo)
);

