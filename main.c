#include <stdio.h>
#include <string.h>
void printHelpData(){
	printf("Usage:\n \ttp0 -h \n\ttp0 -V \n\ttp0 [options] file \nOptions: \n\t-V, --version \tPrint version and quit. \n\t-h, --help \tPrint this information. \n\t-o, --output \tPath to output file. \n\t-i, --input \tPath to input file. \n\t-q, --qsort \tUse quicksort. \n\t-b, --bsort \tUse bubblesort.\n");
}

int main(int argc, char* argv[]){
	if (argc > 1){
		if (strcmp(argv[1], "-h") == 0){
			printHelpData();
		}
		//TODO check this if statement; use strcmp
		else if (argv[1] == "-V" || argv[1] == "--version"){
	//		printVersionNumber();
		}
	}
	return 0;
}
