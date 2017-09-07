#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <math.h>
#define MAX_INPUT 1000000


void print_help_data(){
	printf("Usage:\n \terat-h \n\terat -V \n\terat [options] N \n"
				   "Options:\n\t-h,--help \tPrint usage information.\n\t-V, "
				   "--version \tPrints version information.\n\t-o, --output\t"
				   "Path to output file.\nExamples:\n\terat -o - 10\n");
}

void print_version_info(){
	printf("Version 1.0\n");
}

void erat(unsigned int * numeros,unsigned int N){

	int i = 2;
	int j = 2;
	
	while(pow(i,2)<N){
		while(i*j <= N){
			numeros[i*j] = 0;
			j++;
		}
		i++;
		j = 2;
	}
	
}



void print_sieve_of_Eratosthenes(char* path, unsigned int N){
    /* pi(N): In mathematics, the prime-counting function is the function
     * counting the number of prime numbers less than or equal to some real
     * number x. It is denoted by π(x) (unrelated to the number π).
     * Source: https://en.wikipedia.org/wiki/Prime-counting_function */
    unsigned int all_nums [N+1];
	for (int i = 0; i <= N; ++i){
		all_nums[i] = i;
	}
	erat(all_nums, N);

	/* check where to print results */
	if (*path == 45){
		// output to stdout
        for (int i = 2; i <= N; ++i){
        	if(all_nums[i]!=0)
           		printf("%i\n", all_nums[i]);
        }
	}else{
		FILE* file = fopen(path, "w");
        for (int i = 2; i <= N; ++i){
        	if(all_nums[i]!=0)
            	fprintf(file, "%i\n", all_nums[i]);
        }
		fclose(file);
	}

}

void check_input_num_and_print_sieve(char* path, int N){
	if (N > MAX_INPUT){
		fprintf(stderr, "Given number (%i) exceeded max input %i.\n", N, MAX_INPUT);
	}else if (N < 2){
		fprintf(stderr, "Given number (%i) is not a valid number\n", N);
	}else{
		print_sieve_of_Eratosthenes(path, N);
	}
}

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
			break;
		case 'v':
			print_version_info();
			break;
		case 'o':
			check_input_num_and_print_sieve(optarg, atoi(argv[argc-1]));
			break;
		default:
			printf("Invalid option, run ./erat -h for help\n");
	}
	return 0;
}
