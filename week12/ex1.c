#include <stdio.h>

int main() {
	FILE *rand = fopen("/dev/random", "r");
	char randomChars[21];

	fscanf(rand, "%c", randomChars);
	fclose(rand);

	ranChars[20] = '\0';
	char *iterat = ranChars;
	for (int i = 0; i < 20; ++i, iterat++) {
		*iterat = (*iterat % (char) 62) + (char) 65;
	}

	FILE *outFile = fopen("ex1.txt", "w");
	fprintf(outFile, "%s\n", ranChars);
	fclose(outFile);

	return 0;
}
