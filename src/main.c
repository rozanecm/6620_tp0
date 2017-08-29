#include <stdio.h>
#include <string.h>
#include <getopt.h>

void print_help_data(){
	printf("Usage:\n \terat-h \n\terat -V \n\terat [options] N \nOptions:\n\t-h, --help \tPrint usage information.\n\t-V, --version \tPrints version information.\n\t-o, --output\tPath to output file.\nExamples:\n\terat -o - 10\n");
}

void print_version_info(){};

void calculate_sieve_of_Eratosthenes(char* path){};

int main(int argc, char* argv[]){
	static struct option long_options[] = {
		{"help", 	no_argument, 		0, 'h' },
		{"version",	no_argument, 		0, 'V' },
		{"output",	required_argument,	0, 'o' },
		{0,			0,					0,  0  }
	};
	int option_index = 0;
	int c = getopt_long(argc, argv, "hvo:", long_options, &option_index); 
	switch(c){
		case 'h':
			print_help_data();
			break;
		case 'v':
			print_version_info();
			break;
		case 'o':
			calculate_sieve_of_Eratosthenes(optarg);
			break;
		default:
			printf("?? getopt returned character code 0%o ??\n", c);
	}
	return 0;
}
