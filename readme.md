# Bitcoin Simulation

## Assignment info


Ioanna Zapalidi, sdi1400044 <br>
Project #1<br>
System Programming (Class of Even Registration Numbers)<br>
Spring Semester 2018-19<br>
Professor: Ntoulas A.<br>
Final Grade: 35%<br>


## Instructions
To compile: 
    ```
    $make
    ```
To execute:
```
    $make run
```
(edit the Makefile for alterations on values or sequence of arguements)
To clean the directory:
```
    $make clean
```

### Notes
- Used valgrind for memory leak checks and debugging.
- Used git for version control.
- Used include guards in order to avoid double inclusion of header files.
- Used the hash table data structure for the sender and receiver hashtable (HT) as well as the wallet manipulation.
- The files and implemented classes are heavily based on the concept of layering information and information data structures (e.g. with different classes for the node, the list, etc), so that there is reusable code, it's easier to read and understand (based on only the header files, one has a full view on the implementation) and for better code conservation.
- The sender and receiver HT display the history of each transaction whereas the tree displays the history of each bitcoin.
- The $0 don't delete a wallet/tree node.
- There's a virtual transaction when initializing the wallets, when X sends himself the initial amount of money and the initial bitcoins as described in the bitCoinBalancesFile.txt. These are not actual transactions and won't be displayed upon calling a latter function.
- There's pointers from the receiverHT to the tree, as described in the project description, and "backwards" pointers from the tree to the transaction, in both HT.

### Files
The code has been seperated to the following files:
```
    bitcoin.cpp             the main application
    bc.cpp/.h               bitcoin class and methods
    bc_node.cpp/.h          list of bitcoins node so there's layers of abstraction for the list and the bitcoin class may be reusable
    wallet.cpp/.h           my choice of data structure (hashtable) for the elements of the wallets and the wallets themselves.
    wallet_ht.cpp/.h        wallet hash table implementation
    ht.cpp/.h               hash tables implementation
    bucket.cpp/.h           buckets used in the hash tables
    tree.cpp/.h             BitCoin tree implementation
    transaction.cpp/.h      transaction class (id, sndr, rcvr...)
    datetime.cpp/.h         time and date handling classes and methods
    readme.txt              this readme
    Makefile                compilation and execution - a typical makefile.
    bitCoinBalancesFile.txt sample file.
    transactionsFile.txt    sample file.
```

### References
- K04 notes (2014-15) - personal & Professor's, as well as my projects
- K08 notes (2014-15) - personal & Professor's, as well as my projects
- K10 notes (2015-16) - personal & Professor's, as well as my projects
- K18 notes (2017-18) - personal & Professor's, as well as my projects

### Future implementations & fixes
- [ ] Complete all required functins
- [ ] Use templates for the various hash tables (merge sender/receiver HT and wallet HT)
- [ ] Add checking function for the date class (like the constructor)
