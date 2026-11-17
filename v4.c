
#include <stdio.h>

#define PRICE_PER_SHEET 2.0
#define URGENTRATE 0.25
void clear_input_line(void);
void banner(void);
void show_menu(void);
void read_job(void);
double calculate_total(void);
void print_job(void);

int job_no, pages, copies, duplex, urgent, sheets;
double charge, extra_fee, total;

void clear_input_line(void)
{
int c;
 while ((c = getchar()) != '\n' && c != EOF);
}
void banner(void)
{printf("=======PHOTOCOPY AND PRINT SHOP=======\n");}

void show_menu(void)
{
    printf("1. Add job\n");
    printf("2. Show jobs\n");
    printf("3. Show totals\n");
    printf("4. Exit\n");
}


void read_job(void)
{
    printf("Job no:");
    while (scanf("%d",&job_no) != 1 || job_no < 1)
        {
            clear_input_line();
            printf("Invalid input. Job no must be 1 or more.\nJob no:");

        }

    printf("Pages:");
    while (scanf("%d",&pages) != 1 || pages < 1)
        {
            clear_input_line();
            printf("Invalid input. Pages must be 1 or more.\nPages:");
        }

    printf("Copies:");
    while(scanf("%d",&copies) != 1 || copies < 1)
        {
            clear_input_line();
            printf("Invalid input. Copies must be 1 or more.\nCopies:");
        }

    printf("Sides?? (1 = both, 0 = one side only):");
    while(scanf("%d",&duplex) != 1 || (duplex != 1 && duplex != 0))
          {
              clear_input_line();
              printf("Invalid input. Enter 1 or 0.\nSides??(1 = both, 0 = one side only):");
          }


    printf("Urgent? (1=yes, 0=no):");
    while(scanf("%d",&urgent) != 1 || (urgent != 1 && urgent != 0))
          {
              clear_input_line();
              printf("Invalid input. Enter 1 or 0.\nUrgent? (1=yes, 0=no):");
          }
}

double calculate_total(void)
{
sheets=pages;
sheets=sheets- duplex *(pages/2);
 sheets= sheets * copies;

 charge=sheets*PRICE_PER_SHEET;
 extra_fee= charge * URGENTRATE * urgent;
total=charge +extra_fee;

    return total;
}

void print_job(void)
{printf("Job no:%d\n",job_no);
 printf("Pages:%d\n", pages);
printf("Copies:%d\n",copies);
printf("Duplex:%d\n",duplex);
printf("Urgent:%d\n",urgent);
printf("Sheets:%d\n",sheets);
printf("Charge: %.2f\n" ,charge);
 printf("Urgent fee:%.2f\n",extra_fee);
printf("Total: %.2f\n", total);
}



int main(void)
{
int choice=0,job_count=0;
double grand_total=0.0;
banner();
while (choice != 4)
{  show_menu();
   printf("Enter choice:");
    
   if (scanf("%d", &choice) != 1)
     {clear_input_line();
        choice = 0;}

    switch(choice)
     {case 1:
     read_job();
     calculate_total();
     print_job();

    grand_total=grand_total+ total;
     job_count= job_count +1;
     break;

     case 2:
    if (job_count == 0)
    printf("No jobs entered yet.\n");
    else
    print_job();
    break;

    case 3:
    printf("Total jobs:%d\n",job_count);
    printf("Grand total:%.2f\n",grand_total);
   break;

    case 4:
    printf("Goodbye.\n");
    break;

    default:
        printf("Invalid choice. Choose 1, 2, 3 or 4.\n");
        }
    }

    return 0;
}
