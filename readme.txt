Ioanna Zapalidi, sdi1400044
Project #1
System Programming (Class of Even Registration Numbers)
Spring Semester 2018-19
Professor: Ntoulas A.
~~~
INSTRUCTIONS
To compile: 
    $make
To execute:
    $make run
(edit the Makefile for alterations on values or sequence of arguements)
To clean the directory:
    $make clean
~~~
NOTES
Used valgrind for memory leak checks and debugging.
Used git for version control.
Used include guards in order to avoid double inclusion of header files.
Used the hash table data structure for the sender and receiver hashtable (HT) as well as the wallet manipulation.
~~~
FILES
The code has been seperated to the following files:
    bitcoin.cpp             the main application
    bc.cpp/.h               bitcoin class and methods files
    bc_node.cpp/.h          list of bitcoins node so there's layers of abstraction for the list and the bitcoin class may be reusable
    wallet.cpp/.h           my choice of data structure (hashtable) for the elements of the wallets and the wallets themselves.
    ht.cpp/.h               hash tables implementations
    readme.txt              this readme
    Makefile                compilation and execution - a typical makefile.
    bitCoinBalancesFile.txt sample file.
    transactionsFile.txt    sample file.
~~~
REFERENCES:
    K04 notes (2014-15) - personal & Professor's, as well as my then projects
    K08 notes (2014-15) - personal & Professor's, as well as my then projects
    K10 notes (2015-16) - personal & Professor's, as well as my then projects
    K18 notes (2017-18) - personal & Professor's, as well as my then projects