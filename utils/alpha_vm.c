/**
 * @file alpha_vm.c
 *
 * Utility library for the implementation of the alpha
 * syntax analyzer.
 *
 * Created for the purposes of the virtual machine, as part
 * of the project for HY-340, Spring 2024
 *
 * Computer science department of Crete, Greece
 *
 * -Team members: 
 * @Dimitris Segkesser
 * @Nikoleta Xenaki
 * @Vicky Miliaraki
 *
 * @date 30/5/2024
*/

#include "alpha_vm_utilities.h"

void printAVMHelp(char* programName);

int main(int argc, char** argv){
    /*Let the magic begin*/

    char* in_filename;
    if(argc==2){
        /*Input file specified*/
        in_filename = argv[1];
    }else{
        /*Input file unspecified, error*/
        printAVMHelp(argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE* in_file = fopen(in_filename, "rb");
    if(in_file==NULL){
        perror("Error opening avm input file");
        exit(EXIT_FAILURE);
    }

    loadBinaryFile(in_file);
    fclose(in_file);

    top = AVM_STACKSIZE - 1 - totalGlobals;
    //printf("top is %d\n", top);
    //printf("topsp is %d\n", topsp);
    avm_initstack();

    while(executionFinished == 0){
		//printf("Executing instruction %d\n",pc );
		execute_cycle();
	}

}

void printAVMHelp(char* programName)
{
    fprintf(stdout,"Usage: %s <source file>\n",programName);
}
