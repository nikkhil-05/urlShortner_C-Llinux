#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "db.h"

void main(){

	static char input[1000];
	printf("Enter the link you want to shorten: ");

	fgets(input, 999, stdin);
	input[strcspn(input, "\n")] = '\0'; // remove newline

	char shortKey[20];

	char *result = fetch(input);
	if (result != NULL) {
		strncpy(shortKey, result, sizeof(shortKey)-1);
		shortKey[sizeof(shortKey)-1] = '\0';
		free(result);

		char finalURL[64];
		snprintf(finalURL, sizeof(finalURL), "http://localhost:8080/%s", shortKey);

		printf("\nShortened URL (clickable):\n");
		printf("\033]8;;%s\033\\%s\033]8;;\033\\\n\n", finalURL, finalURL);
	} else {
		printf("Failed to fetch short URL.\n");
	}

}
