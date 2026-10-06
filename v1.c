#include <stdio.h>

int main(void)
{
    printf("========================================================\n");
    printf("      PHOTOCOPY AND PRINT SHOP - JOB QUEUE SYSTEM       \n");
    printf("========================================================\n");
    printf("1. Accept a job\n");
    printf("2. Show the queue\n");
    printf("3. Complete the next job\n");
    printf("4. Search by customer\n");
    printf("5. Day's earnings\n");
    printf("6. Save & load\n");
    printf("7. Exit\n");
    printf("--------------------------------------------------------\n");
    printf("%-6s%-16s%6s%7s%7s%7s%7s\n", "JOB", "CUSTOMER", "PAGES", "COPIES", "DUPLEX", "URGENT", "SHEETS");
    printf("%-6d%-16s%6d%7d%7d%7d%7d\n", 1003, "Rahim Uddin", 9, 1, 1, 1, 5);
    printf("%-6d%-16s%6d%7d%7d%7d%7d\n", 1001, "Nusrat Jahan", 40, 1, 1, 0, 20);
    printf("%-6d%-16s%6d%7d%7d%7d%7d\n", 1002, "Tanvir Ahmed", 7, 2, 0, 0, 7);
    printf("--------------------------------------------------------\n");
    printf("Jobs waiting: 3\n");
    return 0;
}