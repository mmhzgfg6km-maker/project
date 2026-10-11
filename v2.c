#include <stdio.h>

#define PRICE_PER_SHEET 2.00   
#define URGENT_RATE     0.25   /* 25% extra if it is an urgent job */

int main(void)
{
    int    job, pages, copies, duplex, urgent;
    int    sheets_per_copy, sheets;
    double charge, surcharge, total;

    printf("========================================================\n");
    printf("      PHOTOCOPY AND PRINT SHOP - JOB QUEUE SYSTEM       \n");
    printf("========================================================\n");

    printf("Enter job number          : ");  scanf("%d", &job);
    printf("Enter pages               : ");  scanf("%d", &pages);
    printf("Enter copies              : ");  scanf("%d", &copies);
    printf("Both sides? (1=yes, 0=no) : ");  scanf("%d", &duplex);
    printf("Urgent?     (1=yes, 0=no) : ");  scanf("%d", &urgent);

    /* wrote duplex as a phrase; its value is 1 or 0, so this works without an if:
       duplex = 1 > pages - pages/2  (same as (pages + 1) / 2)
       duplex = 0 > pages - 0        (= pages)*/
    sheets_per_copy = pages - duplex * (pages / 2);
    sheets          = sheets_per_copy * copies;

    charge    = sheets * PRICE_PER_SHEET;
    surcharge = charge * URGENT_RATE * urgent;
    total     = charge + surcharge;

    printf("\n");
    printf("--------------------------------------------------------\n");
    printf("%-6s%6s%7s%7s%7s%7s%9s%9s%9s\n", /* left alignment stuff */
           "JOB", "PAGES", "COPIES", "DUPLEX", "URGENT", "SHEETS",
           "CHARGE", "URGENT+", "TOTAL");
    printf("%-6d%6d%7d%7d%7d%7d%9.2f%9.2f%9.2f\n",
           job, pages, copies, duplex, urgent, sheets,
           charge, surcharge, total);
    printf("--------------------------------------------------------\n");
    return 0;
}