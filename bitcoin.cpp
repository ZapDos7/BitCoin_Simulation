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
#include "transaction.h"

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
	const char s[2] = " ";
	char * token;
	ssize_t read; //file descpriptor, se poion buffer , posa bytes na diavasw
	HT ht(712); //rng for the wallets
	while(read = getline(&line, &len, bitCoinBalancesFilePtr)!=-1) {
		token = strtok(line, s);
		wallet * tmpw;
		while (token != NULL) {
			tmpw = ht.get_table();//->set_id(token)
			tmpw->set_id(token);
			tmpw->print_id();
			fprintf(stderr, "%s \n", token);
			token = strtok(NULL, s); //first bc
			if (token==NULL) {
				fprintf(stderr, "is null\n");
			}
			
		}//end while line
		//if (tmpw) free(tmpw);
	}//end while file
	//elegxos monadikotitas ID wallet, if dublicates merge? delete/ignore?
	fclose (bitCoinBalancesFilePtr);
	if (line) free(line); //line was temporary
	if (token) free(token); //after i read transactions file too
	
	//same for transactions
	//elegxos transactionID-unique, not enough funds

	//while (1) {
		char com[100]; //command
		printf("Enter desired function");
		fscanf(stdin, "%s", com);
		fprintf(stdout, "Your command is\n%s\n", com);
		//read com
		//strtok com
		//check first word to match with command, check entire command if correct
		//time: HH:MM
		//year: DD/MM/YYYY
		//requestTransaction swID rwID amount date time ->elegxgos eparkwn funds, update domes, msg for errors or ok. an de do8ei date-time: wra sustimatos upon execution (must be metagenestera of layyer sunallagis pou katagrafike ws twra apo to app)
		//requestTransactions sID1 rID1 a d t; sID2 wID2 a d t;... -> anamesa exoun semicolon ;
		//requestTransactions inputfile -> apo file (xwrizontai me \n)
		//finEarnings walletID t1 y1 t2 y2 -> walletID = rcvID, return initial poso pou elave o wID (euros xronou may not exist => all (an uparxei t1, must uparxei t2 (same for y1, y2))), present all registers me wID=rcv
		//findPayments walletID -> walletID = senderID (like above)
		//walletStatus walletID -> return current wallet balance
		//bitvoinStatus BCID -> print poses sunallages me auto, poso unused poso, poso used se sunallagi
		//traceCoin BCID -> return istoriko sunallagwn with this bc (not must xroniki seira)
		//exit -> free!!!
		
	//}
	exit(EXIT_SUCCESS);
}