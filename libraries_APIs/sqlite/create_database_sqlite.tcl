#! /usr/bin/tclsh

# How to create a 'logged entry' database by using SQLite Tcl extension

package require sqlite3
sqlite3 db $argv

if {$argc != 1 } {
    puts "Usage: $argv0 <database name>"
    exit
} 

db eval {
    CREATE TABLE logged_users(
        userPID INTEGER,
        login_name VARCHAR(30),
        access TIME,
        logout TIME
    );
}
