make:
	g++ -c bitcoin.cpp
	g++ -c wallet.cpp
	g++ -c bc.cpp
	g++ -c wallet_ht.cpp
	g++ -c ht.cpp
	g++ -c bc_node.cpp
	g++ -c tree.cpp
	g++ -c transaction.cpp
	g++ -c bucket.cpp
	g++ -c datetime.cpp
	g++ -g3 -Wall bitcoin.o wallet.o bc.o wallet_ht.cpp bc_node.o ht.o tree.o transaction.o datetime.o bucket.o -o bitcoin

run:
	./bitcoin -a bitCoinBalancesFile.txt -t transactionsFile.txt -v 1 -h1 16 -h2 16 -b 4

clean:
	rm bitcoin
	rm *.o

val:
	valgrind --leak-check=full --track-origins=yes ./bitcoin -a bitCoinBalancesFile.txt -t transactionsFile.txt -v 1 -h1 2 -h2 2 -b 2

#val1:
#	valgrind --track-origins=yes ./bitcoin -a bitCoinBalancesFile.txt –t transactionsFile.txt -v 1 –h1 2 –h2 2 –b 2
#
#hel:
#	valgrind --tool=helgrind ./bitcoin -a bitCoinBalancesFile.txt –t transactionsFile.txt -v 1 –h1 2 –h2 2 –b 2
