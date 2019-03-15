/*
Ioanna Zapalidi, sdi1400044
System Programming Project #1, 2018-19
*/
#include <stdio.h> //printf
#include <cstdlib> //exit
#include <cstring> //strtok
#include <unistd.h> //ssize_t

#include "bc.h"
#include "bc_node.h"
#include "wallet.h"
#include "ht.h"
#include "tree.h"
#include "wallet_ht.h"
#include "transaction.h"
#include "datetime.h"

using namespace std;

int main(int argc, char const *argv[]) {
	//step 1 - read command line
	//./bitcoin -a bitCoinBalancesFile –t transactionsFile -v bitCoinValue –h1 senderHashtableNumOfEntries –h2 receiverHashtableNumOfEntries –b bucketSize
	//argv[0]   1           2          3       4            5     6          7     8                         9        10                      11       12 or any combo
	int BCValue, sHTsize, rHTsize, bucket_size = 0;
	FILE * bitCoinBalancesFilePtr;
	FILE * transactionsFilePtr;
	if (argc !=13) {	//wrong input
		fprintf(stderr, "Invalid execution, please try again!\n");
		exit(-1);
	}
	else {
		for (int i = 1; i < argc; i+=2) {	//check each odd arg, the next is the desired value
			if (strcmp(argv[i],"-a")==0) {
				bitCoinBalancesFilePtr = fopen(argv[i+1], "r");
				if (bitCoinBalancesFilePtr==NULL) {
					fprintf(stderr,"Unable to open bitcoin balances file, aborting.\n");
					exit(1);
				}
				//fprintf(stderr, "A\n");
				continue;
			}
			else if (strcmp(argv[i],"-v")==0) {
				BCValue = atoi(argv[i+1]);
				//fprintf(stderr, "v\n");
				continue;
			}
			else if (strcmp(argv[i],"-t")==0) {
				transactionsFilePtr = fopen(argv[i+1],"r");
				if (transactionsFilePtr==NULL) {
					fprintf(stderr,"Unable to open transactions file, aborting.\n");
					exit(1);
				}
				//fprintf(stderr, "t\n");
				continue;
			}
			else if (strcmp(argv[i],"-b")==0) {
				bucket_size = atoi(argv[i+1]);
				//fprintf(stderr, "b\n");
				continue;
			}
			else if (strcmp(argv[i],"-h1")==0) {
				sHTsize = atoi(argv[i+1]);
				//fprintf(stderr, "h1\n");
				continue;
			}
			else if (strcmp(argv[i],"-h2")==0) {
				rHTsize = atoi(argv[i+1]);
				//fprintf(stderr, "h2\n");
				continue;
			}
			else {
				fprintf(stderr, "Argv handling error\n");
				exit(1);
			}
		}
	}
	
	//step 2 - initialize data structures
	//read bc file
	char * line = NULL;
	size_t len = 0;
	char * token;
	ssize_t read;
	/*wHT ht(712); //712 <- rng for the wallets
	while(read = getline(&line, &len, bitCoinBalancesFilePtr)!=-1) {
		token = strtok(line, " ");
		wallet * tmpw;
		while (token != NULL) {
			tmpw->set_id(token);
			tmpw->print_id();
			fprintf(stderr, "%s \n", token);
			token = strtok(NULL, " "); //first bc
			if (token==NULL) {
				fprintf(stderr, "is null\n");
			}
			
		}//end while line
		
		if (tmpw) free(tmpw);
	}//end while file
	*/
	//elegxos monadikotitas ID wallet, if dublicates merge? delete/ignore?
	fclose (bitCoinBalancesFilePtr);
	if (line) free(line); //line was temporary
	if (token) free(token); //after i read transactions file too
	
	//same for transactions
	//elegxos transactionID-unique, not enough funds

	//while (1) { //end when error in bitCoinFile
		//char com[100]; //command
		//printf("Enter desired function");
		//fscanf(stdin, "%s", com); or fgets or getline?
		//fprintf(stdout, "Your command is\n%s\n", com);
		//read com
		//strtok com or strtok_r
		//check first word to match with command, check entire command if correct
		//time: HH:MM
		//year: DD/MM/YYYY
		//1
		//if not exists date/time, add current max
		//if exists, check if before current max, update currwnt max
		//requestTransaction swID rwID amount date time ->elegxgos eparkwn funds, update domes, msg for errors or ok. an de do8ei date-time: wra sustimatos upon execution (must be metagenestera of layyer sunallagis pou katagrafike ws twra apo to app)
		//2
		//string manipulation of (1)
		//requestTransactions sID1 rID1 a d t; sID2 wID2 a d t;... -> anamesa exoun semicolon ;
		//3
		//like (2) but file
		//requestTransactions inputfile -> apo file (xwrizontai me \n) -  PALI EGW DINW ID
		//4
		//split into 3 functions? (w/o dt, with d, with t, both) -> math.cpp for < >
		//finEarnings walletID t1 y1 t2 y2 -> walletID = rcvID, return initial poso pou elave o wID (euros xronou may not exist => all (an uparxei t1, must uparxei t2 (same for y1, y2))), present all registers me wID=rcv
		//5
		//like above
		//findPayments walletID -> walletID = senderID (like above)
		//6
		//posa exei o sender (apo HT/list)
		//walletStatus walletID -> return current wallet balance
		//7
		//counter of num of trans for each coin?
		//unspent = rightmost leaf node of bc tree!!!!!!
		//bitvoinStatus BCID -> print poses sunallages me auto, poso unused poso, poso used se sunallagi
		//8
		//for each BC -> each transaction -> BFS tree, print (check if double prints! - pointers back to tree - case "static")
		//traceCoin BCID -> return istoriko sunallagwn with this bc (not must xroniki seira)
		//9!!!
		//exit -> free!!!
		
	//}
	exit(EXIT_SUCCESS);
}

/*
Se kathe transaction:
	1. elegxos upoloipou sender
	2. elegxw an elava pote to apaitoumeno poso apo kapoion kai den to ksodepsa (rcvHT ->node -> is leaf?) if yes, go to 3: if no, go to 6:
	3. update wallet, coin counter
	4. insert transaction to sndrHT, rcvrHT
	5. update tree of bitcoin used
	6. sum unspent -> thelw parapanw bitcoins, do the same many times (3,4,5)
*/