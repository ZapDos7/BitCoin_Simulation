/*
Ioanna Zapalidi, sdi1400044
System Programming Project #1, 2018-19
*/
#include <stdio.h> //printf
#include <cstdlib> //exit
#include <cstring> //strtok
#include <unistd.h> //ssize_t

#include "wallet.h"
//#include "bc.h"

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
	walletHT wht(712); //rng
	while(read = getline(&line, &len, bitCoinBalancesFilePtr)!=-1) {
		token = strtok(line, s);
		wallet * tmpw;
		while (token != NULL) {
			//fprintf(stderr, "%s\n", token);
			tmpw = wht.get_table();//->set_id(token)
			tmpw->set_id(token);
			tmpw->print_id();
			token = strtok(NULL, s); //first bc
			/*if (token == NULL) {
				//fprintf(stderr, "No more bitcoins before 1st\n");
				continue;
			}
			else {*/
				fprintf(stderr, "%s \n", token);
			//}
			tmpw->init_bclist(atoi(token), BCValue);
			while(token != NULL){ //read the rest line
				bitcoin_node * tmp;
				tmpw->add_bc(atoi(token), BCValue);
				token = strtok(NULL, s);
				if (token == NULL) {
					//fprintf(stderr, "No more bitcoins after 1st\n");
					continue;
				}
				else {
					fprintf(stderr, "%s \n", token);
				}
			}
			tmpw->print_bc();
		}//end while line
		if (tmpw) free(tmpw);
	}//end while file
//	fprintf (stderr, "ok\n");
	fclose (bitCoinBalancesFilePtr);
	if (line) free(line); //line was temporary
	if (token) free(token); //after i read transactions file too
	
	//read input
	//pick a method while(1)

	exit(EXIT_SUCCESS);
}