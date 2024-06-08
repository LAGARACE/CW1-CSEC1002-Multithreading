// Library's used by my program 

#include <pthread.h>    /*Here by including the pthread library it provides the program a function in order to create and controlling threads */
#include <stdio.h>      /*Here by including the stdio which stands for 'standard input/output library it provides the program a function to use input and output operations, an example in my program would be the use of printf */
#include <stdlib.h>     /*Here by including the standard library we provides the program the function to allocate memory allocation, here an example in my code is the use of  calloc and atoi */

// Variables that hold the final results, integer data type for simplicity

int minNum = 0; /* I am using 'int minNum' in order to declare and initialize my variables to store the minimum */
int maxNum = 0; /* Then i made use of 'int maxNum'  in order to declare and initialize my variables to store the maximum */
int *values;    /* And finaly this line is here in order to declare and initialize my variables to store the array of integers values */
int size;       /* This line declares a global variable in order to store the size of the array of integers*/
int avgNum = 0; /* And like for my maximum and my minimum variables i'am using 'int avgNum in order to declare and initialize a  variable to store my average value*/


// Functions' declaration. Definition is at the bottom

void *avgfunc(void *param);
void *minfunc(void *param);  /* From line 18 to line 20 i am using 'void *' in order to declare and create the functions avgfunc, minfunc, and maxfunc, i am using to calculate the average, minimum, and maximum later on in the code */
void *maxfunc(void *param);

int main(int argc, char **argv) /* Here from this point is where i start my main function which is used in order to take the command line number and redistribute them to my function to create my three threads of calculating */
{

    if (argc < 2) {
        fprintf(stderr, "Error: %s <Not enough numbers inputed>\n", argv[0]);
        exit(1);            /* from line 25 to line 28 this is where my program check if there is any numbers inputed through the command line, and if no numbers have been inputed it will prints the error message 'Error:<Not enough numbers inputed'*/
    }
    int i;      /* Here my line is used to declares a variable that will be used in for the loop later on the program */

    --argc;    /* '--argc' and '++argv'  adjust the variables for the for loop that follows*/
    ++argv;

    values = calloc(argc,sizeof(int)); /* i am making use of 'values = calloc (argc,sizeof(int))' to allocate the memory of the array of integers by using' calloc'*/

    for (i = 0;  i < argc;  i++) {   /*This is where my loop is made, my loop will assigns the numbers inputed in the command line to the array of integers and it will increment the size for each numbers */
        values[i] = atoi(argv[i]);
        size++;
    }

// Create thread IDs 

    pthread_t avgPT;   
    pthread_t minPT;   /*Here from line 41 to 43 those lines declare my thread ID, one thread for each function  will be created*/
    pthread_t maxPT;


// Create thread attributes 

#if 0        /* Here this line initializes the thread attributes */
    pthread_attr_t attr; 
#endif

// Initialize thread attributes 

pthread_attr_init ; /* The proceess of initializing the thread attributes simply just defines or sets the values to be used by the thread while its being created */
#if 0

// Create thread

pthread_create(&avgPT, &attr, avgfunc, argv[1]);
pthread_create(&minPT, &attr, minfunc, argv[1]);
pthread_create(&maxPT, &attr, maxfunc, argv[1]);

#else

pthread_create(&avgPT, NULL, avgfunc, values); /* Here from line 67 to 69 I create the three threads, and im also passing the thread IDs, the thread attributes, and the array of integers as arguments*/
pthread_create(&minPT, NULL, minfunc, values);
pthread_create(&maxPT, NULL, maxfunc, values);

#endif

// Wait for threads to exit 

pthread_join(avgPT, NULL); 
pthread_join(minPT, NULL);
pthread_join(maxPT, NULL);

// Print results of threads

 printf("%d %d %d ",avgNum, minNum, maxNum); /* Here this line is used in order to prints the final results of the average, minimum, and maximum values */

}

void * avgfunc(void *param) /* Here from line 85 to line 100 i have crrated a function that calculates the average value by simplyadding and summing up all the numbers (elements) in the values array and dividing by the ammount of numbers (size), the program will then stores the result in the 'avgNum' variable and exits the thread*/
{

 /* Write the code to calculate the average value and store it in avgNum variable */

    int sum = 0;
    int i = 0;
    int *values;

    values = param;
    for (i = 0; i < size; i++)
        sum += values[i];
    avgNum = sum / (int) size;

    pthread_exit(0);
}

void *minfunc(void *param) /* Here from line 102 to line 121 i made a function that will calculates the minimum value by initializing 'minNum' to the first element of the values array, and comparing each number (element) to minNum, and updating minNum if an element is smaller and then exits the thread */
{

 /* Write the code to calculate the minimum value and store it in minNum variable */

    int i = 0;
    int *values;

    values = param;
    minNum = values[0];

    for (i = 0; i < size; i++) {
        if (values[i] < minNum)
            minNum = values[i];
    }

    pthread_exit(0);
}

void *maxfunc(void *param) /* And finally my last function here follows the same exact process as the 'minfunc' as it calculates the maximum value by initializing maxNum to the first element of the values array, and then comparing each element to maxNum, and updating maxNum if an element is larger and exits the thread */

{

 /* Write the code to calculate the average value and store it in maxNum variable */

    int i = 0;
    int *values;

    values = param;
    maxNum = values[0];

    for (i = 0; i < size; i++) {
        if (values[i] > maxNum)
            maxNum = values[i];
    }

    pthread_exit(0);
}

/* Explaining my program in more details : 
This program as requested by the coursework is a multithreaded program that is meant to be taking numbers as input through the command line in order to then 
calculates the average,rthe minimum, and the maximum of these numbers using 3 separate threads

The program uses libraries, such as pthread.h, stdio.h, and stdlib.h, which are here in order to provide functions for thread creation and control, 
input and output operations, and memory allocation 

First thing my program will do i start by checking if some number have been inputed through the command line using the 'argc' variable, 
then ff there is less than a minimum of 2 numbers, then my program will print the error message "Error: <Not enough numbers inputed>"
Next, the program has a loop in it in order to convert the numbers from strings to integers using the function 'atoi' 
After that, my program is going to be creating three threads, one for each of the avgfunc(), minfunc(), and maxfunc() functions, using the pthread_create() 

Then as described earlier on as a comment in my code the avgfunc() function calculates the average of the input numbers by summing up all the number
in the array and dividing by the amount of numbers, then it will then assigns the result of the calculation to the avgNum variable, then the minfunc() function finds the minimum number
in the array by going through the array and comparing each number to the current minimum, updating the minimum value if a smaller number is found and
assigns the result to the minNum variable, and the maxfunc() function finds the maximum number in the array by goiing through the array and comparing 
each number to the current maximum, updating the maximum value if a larger number is found and assigns the result to the maxNum variable.

Then my program will joins the 3 threads by making use of 'pthread_join' function to wait for them to be done before printing the results of the calculation using the printf() function */
