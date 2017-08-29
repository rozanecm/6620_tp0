#include <stdio.h>
#include <string.h>
#include <getopt.h>

void print_help_data(){
	printf("Usage:\n \terat-h \n\terat -V \n\terat [options] file \nOptions: \n\t-V, --version \tPrint version and quit. \n\t-h, --help \tPrint this information. \n\t-o, --output \tPath to output file. \n\t-i, --input \tPath to input file. \n\t-q, --qsort \tUse quicksort. \n\t-b, --bsort \tUse bubblesort.\n");
}

void print_version_info(){};

void calculate_sieve_of_Eratosthenes(char* path){};

int main(int argc, char* argv[]){
	static struct option long_options[] = {
		{"help", 	no_argument, 		0, 'h' },
		{"version",	no_argument, 		0, 'v' },
		{"output",	required_argument,	0, 'o' },
		{0,			0,					0,  0  }
	};
	int option_index = 0;
	int c = getopt_long(argc, argv, "hvo:", long_options, &option_index); 
	switch(c){
		case 'h':
			print_help_data();
		case 'v':
			print_version_info();
		case 'o':
			calculate_sieve_of_Eratosthenes(optarg);
		default:
			printf("?? getopt returned character code 0%o ??\n", c);
	}
	return 0;
}
