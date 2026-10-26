#include <stdio.h>

#define PRICE_PER_SHEET 2.0
#define URGENTRATE 0.25

int job_no, pages, copies, duplex, urgent,sheets;
double charge, extra_fee, total;

void banner(void)
{
    printf("=======PHOTOCOPY AND PRINT SHOP=======\n");
}

void show_menu(void)
{
    printf("1.Add job\n");
    printf("2.Show jobs\n");
    printf("3. Exit\n");
}

void read_job(void)
{
    printf("Job no:");
    scanf("%d",&job_no);

    printf("Pages:");
    scanf("%d",&pages);

    printf("Copies:");
    scanf("%d",&copies);

    printf("Sides?? (1=bothh, 0=one side only):");
    scanf("%d",&duplex);

    printf("Urgent? (1=yes, 0=no):");
    scanf("%d",&urgent);
}

double calculate_total(void)
{
    sheets = pages;
    sheets = sheets - duplex * (pages / 2);
    sheets = sheets * copies;

    charge = sheets * PRICE_PER_SHEET;
    extra_fee =charge*URGENTRATE * urgent;
    total =charge +extra_fee;

    return total;
}

void print_job(void)
{
    printf("Job no: %d\n", job_no);
    printf("Pages:%d\n",pages);
    printf("Copies:%d\n", copies);
    printf("Duplex:%d\n", duplex);
    printf("Urgent:%d\n",urgent);
    printf("Sheets:%d\n",sheets);
    printf("Charge:%.2f\n",charge);
    printf("Urgent fee:%.2f\n", extra_fee);
    printf("Total:%.2f\n", total);
}

int main(void)
{
    banner();
    show_menu();
    read_job();
    calculate_total();
    print_job();
    return 0;
}
