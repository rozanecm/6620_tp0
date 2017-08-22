#include <stdio.h>
#include <string.h>
void printHelpData(){
	printf("%s\n\t%s\n\t%s\n\t%s\n%s\n\t%s\t%s\n\t%s\t%s\n\t%s\t%s\n\t%s\
\t%s\n\t%s\t%s\n\t%s\t%s\n",\
      	"Usage:", "tp0 -h", "tp0 -V", "tp0 [options] file", "Options:", \
		"-V, --version", "Print version and quit.", "-h, --help", \
		"Print this information.", "-o, --output", "Path to output file.", \
		"-i, --input", "Path to input file.", "-q, --qsort", "Use quicksort.", \
		"-b, --bsort", "Use bubblesort.");
}

int main(int argc, char* argv[]){
	if (strcmp(argv[1], "-h") == 0)
		printHelpData();
	//TODO check this if statement; use strcmp
	else if (argv[1] == "-V" || argv[1] == "--version")
//		printVersionNumber();

	return 0;
}
