#include <stdio.h>
#include <stdlib.h>

static void print_menu(void) {
	puts("Select one of the following options:\n");
	puts("1 - Access account");
	puts("2 - Open account\n");
	fputs("> ", stdout);
}

int main(void) {
	puts("SegFault Financial Services 0.0.0.0.1");
	puts("Press Ctrl+C to Exit\n");

	while (1) {
		print_menu();

		char buffer[1024];
		fgets(buffer, 1024, stdin);

		printf("Selected option: %s\n", buffer);
	}

	return 0;
}
