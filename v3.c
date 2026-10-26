#include <stdio.h>

int job_no, pages,copies, duplex, urgent;

void banner(void)
{
    printf("======= PHOTOCOPY AND PRINT SHOP =======\n");
}

void show_menu(void)
{
    printf("1. Add job\n");
    printf("2. Show jobs\n");
    printf("3.Exit\n");
}

void read_job(void)
{
    printf("Job no:");  
    scanf("%d", &job_no);
    
    printf("Pages:"); 
    scanf("%d", &pages);

    printf("Copies:");  
    scanf("%d", &copies);
    
    printf("Duplex (0/1) : ");  
    scanf("%d", &duplex);
   
    printf("Urgent (0/1) : ");  
    scanf("%d", &urgent);
}

int total_pages(int pages1, int copies1)     
{
    return pages1 *copies1;
}

void print_job(int total)
{
    printf("Job no %d\n", job_no);
    printf("Pages  : %d\n", pages);
    printf("Copies : %d\n", copies);
    printf("Duplex : %d\n", duplex);
    printf("Urgent: %d\n", urgent);
    printf("Total pages to print : %d\n", total);
}

int main(void)
{
    banner();
    show_menu();
    read_job();
    print_job(total_pages(pages, copies));
    return 0;
}