/* name:          memory.c
 * aims:          to see how the compiler allocates memory to each region of
 *                the process (user visible part), including text region (program instructions),
 *                data region, heap, stack, command line arguments and process environment region

 * author:        Mohsin Ali Khan
 * updated:       2023.10.13
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

extern char **environ;


int gx = 10;   // initialised global
int gy;  // uninitialised global
char gname1[] = "Hi, there!";
char *gname2  = "Computer Science";
const int gc = 100;
int gz;

void printAddress(char *description, void *addr)
{
    unsigned long a = (unsigned long) addr;

    unsigned long b  = a & 0x3ff;
    unsigned long kib = a >> 10; kib = kib & 0x3ff;
    unsigned long mib = a >> 20; mib = mib & 0x3ff;
    unsigned long gib = a >> 30; gib = gib & 0x3ff;
    unsigned long tib = a >> 40; tib = tib & 0x3ff;
    printf("%s,  %lu,  %lu, %lu, %lu, %lu, %lu\n", description, a, tib, gib, mib, kib, b);

    return;
}

int f1(int x1, int x2, float x3, double x4, char x5, int x6 )
{
    int     f1_l1;
    float   f1_l2;
    char    f1_l3;
    char    f1_l3b;
    double  f1_l4;
    const int     f1_l5;
    int     f1_l6;

    // TO DO:
    // print the addresses of all formal parameters of function f1
    printAddress("&x1", &x1);
    printAddress("&x2", &x2);
    printAddress("&x3", &x3);
    printAddress("&x4", &x4);
    printAddress("&x5", &x5);
    printAddress("&x6", &x6);

    // print the addresses of all local variables of function f1
    printAddress("&f1_l1", &f1_l1);
    printAddress("&f1_l2", &f1_l2);
    printAddress("&f1_l3", &f1_l3);
    printAddress("&f1_l3b", &f1_l3b);
    printAddress("&f1_l4", &f1_l4);
    printAddress("&f1_l5", (void*)&f1_l5);
    printAddress("&f1_l6", &f1_l6);

    return 0;
}

void f2()
{
    #define BUFSIZE 1024*1024
    char f2_buf[BUFSIZE];
    char *f2_p;
    f2_p = malloc(BUFSIZE);
    if (f2_p==NULL) {
         perror("mallc memory");
         exit(1);
    }

    // TO DO:
    // print the addresses of local variables f2_buf and f2_p of function f2
    printAddress("&f2_buf", &f2_buf);
    printAddress("&f2_p", &f2_p);

    // print the addresses of heap allocated memory pointed to by p in function f2
    printAddress("f2_p", f2_p);

    //==== call function f1 in function f2  ====
    f1(10, 20, 10.2, 20.3, 'a', 100);


    return;
}

int main(int argc, char *argv[], char *env[])
{
    char main_buf[256];
    int nv=0;   // number of environment variables

    //==== print excel spreadsheet header =====
    printf("Description,Address,TiB,GiB,MiB,KiB,B\n");

/*
    // end of text, end of init data and end of data on linux
    // doesnt apply if your computer runs macOS
    extern char etext; // end of text region
    extern char edata; // end of the initialised data
    extern char end;   // end of uninitialised data
    printAddress("&etext", &etext);
    printAddress("&edata", &edata);
    printAddress("&end", &end);
*/
    //==== program text ====
    printAddress("&printAddress", &printAddress); // same, they are the start address of the function
    // TO DO:
    // print the addresses of function f1, f2 and main
    printAddress("&f1", &f1);
    printAddress("&f2", &f2);
    printAddress("&main", &main);

    //==== constants and initialised globals ====
    // TO DO:
    // print the addresses of constant gc and string literal "Computer Science"
    printAddress("&gc", (void*)&gc);
    printAddress("\"Computer Science\"", gname2);

    // print the addresses of initialised global variables gx, gname1, gname2
    printAddress("&gx", &gx);
    printAddress("&gname1", &gname1);
    printAddress("&gname2", &gname2);


    //==== uninitialised globals ====
    // TO DO:
    // print the addresses of uninitialised global variables gy, gz
    printAddress("&gy", &gy);
    printAddress("&gz", &gz);


    //==== extern variables ====
    // TO DO:
    // print the addresses of extern variable environ
    printAddress("&environ", &environ);


    //==== formal parameters in function main ====
    // TO DO:
    // print the addresses of formal parameters argc, argv, and env
    printAddress("&argc", &argc);
    printAddress("&argv", &argv);
    printAddress("&env", &env);


    //==== allocate memory from heap ====
    char *main_p1 = malloc(200);
    char *main_p2 = malloc(10000);

    //==== local variables in main ====
    // TO DO:
    // print the addresses of local variables main_buf, nv, main_p1, main_p2
    printAddress("&main_buf", &main_buf);
    printAddress("&nv", &nv);
    printAddress("&main_p1", &main_p1);
    printAddress("&main_p2", &main_p2);


    //==== dynamic variables in heap ====
    // TO DO:
    // print the addresses of heap allocated memmory pointed to by main_p1 and main_p2
    printAddress("main_p1", main_p1);
    printAddress("main_p2", main_p2);


    //==== call function f2 from main function ====
    f2();

    //==== arrays of pointers to cmd line arguments ====
    // TO DO:
    // print the start and end addresses of the array of pointers point to cmd line arguments
    printAddress("argv start", argv);
    printAddress("argv end", argv+argc);


    //==== command line arguments ====
    // TO DO:
    // print start and end addresses of the block containing the cmd line arguments 
    printAddress("argv[0] start", argv[0]);
    printAddress("argv[argc-1] end", argv[argc-1] + strlen(argv[argc-1]));


    // find out the number of environment variables
    while (env[nv]) ++nv;

    //==== arrays of pointers to a list of environment variables ====
    // TO DO:
    // print the start and end addresses of the array of pointers to a list of env variables
    printAddress("env start", env);
    printAddress("env end", env+nv+1);


    //==== environment ====
    // TO DO:
    // print start and end addresses of the environment variables
    printAddress("env[0] start", env[0]);
    printAddress("env[nv-1] end", env[nv-1] + strlen(env[nv-1]));


    exit(0);
}
