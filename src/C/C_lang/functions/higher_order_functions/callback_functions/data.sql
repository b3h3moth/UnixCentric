CREATE TABLE IF NOT EXISTS oslist(
    id INTEGER PRIMARY KEY,
    name TEXT,
    year INTEGER
) WITHOUT ROWID;

INSERT INTO oslist(id, name, year) VALUES (1, 'OpenBSD', 1910);
INSERT INTO oslist(id, name, year) VALUES (2, 'FreeBSD', 1920);
INSERT INTO oslist(id, name, year) VALUES (3, 'NetBSD', 1930);
INSERT INTO oslist(id, name, year) VALUES (4, 'Debian', 1990);
