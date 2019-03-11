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
Used include guards in order to avoid double inclusion of header files.
The code has been seperated to the following files:
    bitcoin.cpp             the main application
    wallet.cpp/.h           my choice of data structure (hashtable) for the elements of the wallets.
    bc.cpp/.h               bitcoin class and methods files
    readme.txt              this readme
    Makefile                compilation and execution - a typical makefile.
    bitCoinBalancesFile.txt sample file.
    transactionsFile.txt    sample file.
