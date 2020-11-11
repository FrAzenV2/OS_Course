#include <stdio.h>
#include <buffing.h>

#define BUFF 100
#define PROCESSES 5
#define RESOURCES 3

int main(int argc, char *argv[]) {
    char buff[BUFF];
    FILE* input;
    FILE* output;
    int existingRes[RESOURCES];
    int availableRes[RESOURCES];
    int matrixAlloc[PROCESSES][RESOURCES];
    int matrixReq[PROCESSES][RESOURCES];
    int dlProcs[PROCESSES];


    int dl = 0;
    int finished[PROCESSES];
    int currSymb = 0;
    int canExecute[PROCESSES];
    int changed = 1;

    if (argc < 2) {
        printf("No input filename provided\n Usage: %s filename\n", argv[0]);
        return 0;
    }

    input = fopen(argv[1], "r");

    if (input == NULL) {
        printf("File with name \"%s\" not found\n Provide a correct input filename\n", argv[1]);
        return 0;
    }

    fgets(buff, BUFF, input);
    for (size_t i = 0; i < RESOURCES; i++) {
        existingRes[i] = (int)(buff[currSymb] - '0');
        currSymb += 2;
    }

    currSymb = 0;
    fgets(buff, BUFF, input);
    fgets(buff, BUFF, input);

    fgets(buff, BUFF, input);
    for (size_t i = 0; i < RESOURCES; i++) {
        availableRes[i] = (int)(buff[currSymb] - '0');
        currSymb += 2;
    }

    currSymb = 0;
    fgets(buff, BUFF, input);
    fgets(buff, BUFF, input);

    fgets(buff, BUFF, input);
    for (size_t i = 0; i < PROCESSES; i++) {
        for (size_t j = 0; j < RESOURCES; j++) {
            matrixAlloc[i][j] = (int)(buff[currSymb] - '0');
            currSymb += 2;
        }

        currSymb = 0;
        fgets(buff, BUFF, input);
    }

    currSymb = 0;

    fgets(buff, BUFF, input);
    for (size_t i = 0; i < PROCESSES; i++) {
        for (size_t j = 0; j < RESOURCES; j++) {
            matrixReq[i][j] = (int)(buff[currSymb] - '0');
            currSymb += 2;
        }

        currSymb = 0;
        fgets(buff, BUFF, input);
    }
    fclose(input);

    for (size_t i = 0; i < PROCESSES; i++) {
        dlProcs[i] = 0;
        canExecute[i] = 1;
        finished[i] = 0;
    }

    while (changed) {
        changed = 0;
        for (size_t i = 0; i < PROCESSES; i++) {
            canExecute[i] = 1;
            for (size_t j = 0; j < RESOURCES; j++) {
                if (matrixReq[i][j] > availableRes[j]) {
                    canExecute[i] = 0;
                    break;
                }
            }
        }

        for (size_t i = 0; i < PROCESSES; i++) {
            if (canExecute[i] && finished[i] == 0) {
                for (size_t j = 0; j < RESOURCES; j++) {
                    availableRes[j] += matrixAlloc[i][j];
                    matrixAlloc[i][j] = 0;
                    matrixReq[i][j] = 0;
                    changed = 1;
                    finished[i] = 1;
                }
            }
        }
    }

    for (size_t i = 0; i < PROCESSES; i++) {
        if (finished[i] == 0) {
            dlProcs[i] = 1;
            dl = 1;
        }
    }

    if (dl) {
        output = fopen("output_dl.txt", "w+");

        for (size_t i = 0; i < PROCESSES; i++) {
            if (dlProcs[i]) {
                fprintf(output, "Process %ld is in a dl\n", i+1);
            }
        }
        fprintf(output, "(Counting from 1 to %d)", PROCESSES);
    } else {
        output = fopen("output_ok.txt", "w+");

        fprintf(output, "No dls found");
    }

    fclose(output);

    return 0;
}
