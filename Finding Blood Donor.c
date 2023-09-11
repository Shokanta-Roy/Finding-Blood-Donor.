
#include<stdio.h>

//Create structure

struct members
{
    int id;
    char name[100];
    char blood_group[10];
    int phone;
    char status[5];
};

// insert_members function

void insert_members()
{
    int cap = 0;
    FILE *fptr;
    fptr = fopen("Record.txt", "a");
    struct members member;

    printf("\n\t\tEnter a unique id for donor : ");
    scanf("%d", &member.id);
    fflush(stdin);
    printf("\t\tEnter name of donor : ");
    gets(member.name);

    printf("\t\tEnter Blood Group of donor : ");
    gets(member.blood_group);
    cap = 0;
    while(member.blood_group[cap] != '\0')
    {
        if(member.blood_group[cap] >= 'a' && member.blood_group[cap] < 'z')
        {
            member.blood_group[cap] = member.blood_group[cap] - 32;
        }
        cap++;
    }
    printf("\t\tEnter phone number of donor : ");
    scanf("%d", &member.phone);
    printf("\t\tEnter available status of donor : ");
    gets(member.status);
    gets(member.status);
    cap = 0;
    while(member.status[cap] != '\0')
    {
        if(member.status[cap] >= 'a' && member.status[cap] < 'z')
        {
            member.status[cap] = member.status[cap] - 32;
        }
        cap++;
    }

    fprintf(fptr, "\n%d %s %s  %d %s", member.id, member.name, member.blood_group, member.phone, member.status);
    printf("\n");


    fclose(fptr);
}

void display1(struct members m, char str[])
{
    int len = 0, i = 0, j = 0;

    while(str[len] != '\0')
    {
        len++;
    }

    while(m.status[i] != '\0')
    {
        if(m.status[i] == str[j])
        {
            while(m.status[i] == str[j] && m.status[i] != '\0')
            {
                i++;
                j++;
            }
            if(len == j && m.status[i] == '\0' && str[j] == '\0')
            {
                printf("%d %s  %s %d %s\n", m.id, m.name, m.blood_group, m.phone, m.status);

            }
        }
        else
        {
            break;
        }
        j++;
        i++;
    }
}

void display2(struct members m, char str[])
{
    int len = 0, i = 0, j = 0;

    while(str[len] != '\0')
    {
        len++;
    }

    while(m.blood_group[i] != '\0')
    {
        if(m.blood_group[i] == str[j])
        {
            while(m.blood_group[i] == str[j] && m.blood_group[i] != '\0')
            {
                i++;
                j++;
            }
            if(len == j && m.blood_group[i] == '\0' && str[j] == '\0')
            {
                printf("%d %s  %s %d %s\n", m.id, m.name, m.blood_group, m.phone, m.status);
            }
        }
        else
        {
            break;
        }
        j++;
        i++;
    }
}

//available members function

void available_members(char str[], int num)
{
    int len = 0, i = 0, j = 0;

    FILE *fptr;
    fptr = fopen("Record.txt", "r+");
    struct members member;

    while(!feof(fptr))
    {
        fscanf(fptr, "%d", &member.id);
        fscanf(fptr, "%s", member.name);
        fscanf(fptr, "%s", member.name);
        fscanf(fptr, "%s", member.blood_group);
        fscanf(fptr, "%d", &member.phone);
        fscanf(fptr, "%s", member.status);

        if(num == 1)
        {
            display1(member, str);
        }
        else if(num == 2)
        {
            display2(member, str);
        }

        i++;
    }
    fclose(fptr);
}

//total Members function
int total_Members()
{
    int counter = 0;
    FILE *fptr;
    fptr = fopen("Record.txt", "r+");
    int c = getc(fptr);
    struct members member;

    while(c != EOF)
    {
        if(c == '\n')
        {
            counter++;
        }
        c = getc(fptr);
    }
    return counter;

}

//members list functon
void members_list()
{
    FILE *fptr;
    fptr = fopen("Record.txt", "r");
    int c = getc(fptr);

    while(c != EOF)
    {
        printf("%c", c);
        c = getc(fptr);
    }
}

// MAIN PROGRAM
void main()
{
    int operation, container;
    int num;
    int i = 0;
    char str[5],str2[5];
    printf("\t\t\tWELCOME TO\n");
    printf("\t\tBLOOD DONER MANAGEMENT SYSTEM");
    do
    {

        printf("\n\n\t\t------Menu------\n\n");
        printf("\t\t0. Enter 0 for Exist.\n");
        printf("\t\t1. Insert a new donar.\n");
        printf("\t\t2. Available donor.\n");
        printf("\t\t3. Total donar.\n");
        printf("\t\t4. List of donor.\n");
        printf("\nEnter your operation number : ");
        scanf("%d", &operation);

        if(operation > 0)
        {
            switch(operation)
            {
            case 1:
                insert_members();
                break;
            case 2:
//                    int num;
//                    int i = 0;
//                    char str2[5];
                printf("\t\t1. Search by available status.\n");
                printf("\t\t2. Search by Blood Group.\n");
                printf("\t\tEnter Your Choose : ");
                scanf("%d", &num);

                if(num == 1)
                {
                    printf("\t\tEnter status : ");
                    gets(str2);
                    gets(str2);
                    while(str2[i] != '\0')
                    {
                        if(str2[i] >= 'a' && str2[i] < 'z')
                        {
                            str2[i] = str2[i] - 32;
                        }
                        i++;
                    }
                    available_members(str2, num);
                }
                else if(num == 2)
                {
                    printf("\t\tEnter Blood Group : ");
                    gets(str2);
                    gets(str2);
                    i = 0;
                    while(str2[i] != '\0')
                    {
                        if(str2[i] >= 'a' && str2[i] < 'z')
                        {
                            str2[i] = str2[i] - 32;
                        }
                        i++;
                    }
                    available_members(str2, num);
                }

                else
                {
                    printf("\t\t\tYou choose invalid Option.");
                }

                break;
            case 3:
                container = total_Members();
                printf("\t\tTotal Member = %d", container);
                break;
            case 4:
                str[5] = "YES";
                members_list(str);
                break;
            default:
                printf("\t\t\tYou chose invalid operation number.");
            }
        }
    }
    while(operation != 0);
}
