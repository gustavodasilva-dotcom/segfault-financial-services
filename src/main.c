#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void print_info(void) {
	puts("SegFault Financial Services 0.0.0.0.1\n");
}

static void print_menu(void) {
	puts("Select one of the following options:\n");
	puts("1 - Access account");
	puts("2 - Open account");
	puts("3 - Quit\n");
}

static void die(const char *s) {
	perror(s);
	exit(EXIT_FAILURE);
}

int main(void) {
	print_info();

	while (1) {
		print_menu();

		printf("> ");

		// Ensures prompt is displayed before reading input
		fflush(stdout);
		
		// Reads the intended single character and the newline
		char buf[2];
		if (read(STDIN_FILENO, buf, sizeof buf) == -1 && errno != EAGAIN) die("read");

		switch (buf[0]) {
			case '1':
			case '2':
				break;
			case '3':
				printf("We thank you for choosing SegFault!\n");
				exit(EXIT_SUCCESS);
			default:
				puts("Unrecognized option");
				break;
		}
	}

	return EXIT_SUCCESS;
}
