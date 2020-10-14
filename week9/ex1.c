#include <stdio.h>
#include <stdlib.h>

typedef struct Pager{
    int numberOfPages;
    int* pages;
    char* paccess;

    int h;
    int m;
} PAGER;

PAGER* CreatePage(int num){
    PAGER* p = (PAGER*)malloc(sizeof(PAGER));
    p->numberOfPages = num;
    p->pages = (int*)malloc(sizeof(int) * num);
    p->paccess = (char*)malloc(sizeof(char) * num);
    p->h = p->m = 0;

    return p;
}

void TickSimulate(PAGER* p){
    for(int i=0; i<p->numberOfPages; ++i)
        p->paccess[i] = p->paccess[i] >> 1;
}

int swapPages(PAGER* p, int idx, int pid){
    p->pages[idx] = pid;
    p->paccess[idx] = 0b10000000;
    p->m++;
    return 1;
}

int paccess(PAGER* p, int pid){
    int idx = 0;
    char* byte = p->pages[0];
    for(int i=0; i < p->numberOfPages; ++i){
        if(p->pages[i] == pid){
            p->h++;
            p->paccess[i] = p->paccess[i] | 0b10000000;
            return 0;
        }
        if(p->paccess[i] < byte){
            idx = i;
            byte = p->paccess[i];
        }
    }

    return swapPages(p, idx, pid);
}

int main(int argc, char* agrv[]){
    int numberOfPages = atoi(agrv[0]);
    PAGER* pager = CreatePage(numberOfPages);

    FILE* fin = fopen("input.txt", "r");

    int tmp = 0;

    while(fscanf(fin, "%d", &tmp) != EOF){
        TickSimulate(pager);
        paccess(pager, tmp);
    }

    int h = pager->h, m  = pager->m;
    printf("Hit/Miss: %d/%d\n", h,m);


    fclose(fin);

    return 0;
}
