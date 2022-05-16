#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


void main_menu(void);
void space_management(int);
void border_design(int);
void college_info(void);
void admin(void);
void admin_login(void);
void admin_mainmenu(void);
void subject_list(void);
void admin_choice(void);
void add_file(void);
void rewrite_file(void);
void addContent_file(void);
void grades(void);
void grades_rewrite(void);
void grades_add(void);
void students(void);
void students_mainmenu(void);
void quit(void);



int main()
{
   main:
   main_menu();
   int option_main;
   printf("\n\n");
   scanf("\t\t%d", &option_main);


   for(int repeat = 2;repeat != 0; repeat--)
   {
       switch(option_main)
       {
        case 1 :
           system("cls");
           college_info();
           break;

        case 2 :
           system("cls");
           admin();
           break;

        case 3 :
            system("cls");
            students();
            break;

        case 4 :
            quit();
            break;

        default :
            //if(repeat == 2)
                //system("cls");
            printf("\n\n\t\tInvalid Response !  \n");

        }

        // Repeating main_menu if user enters 0 else exit
        if(option_main == 1 || option_main == 2 || option_main == 3)
        {
            int guard_main;
            printf("\n\n\t\t\t\tEnter 0 to back to main menu or any other number to exit : ");
            scanf("%d", &guard_main);

            if(guard_main == 0)
            {
                system("cls");
                goto main;
            }
            else
                break;
        }

        if(option_main == 1 || option_main == 2 || option_main == 3 || option_main == 4)
        {
            break;
        }

        if(option_main != 1 || option_main != 2 || option_main != 3 || option_main != 4)
        {
            printf("\n\n\t\tYou left with %d try !\n\n", repeat);
        }
        printf("\t\tENTER YOUR CHOICE : ");
        scanf("\t\t%d", &option_main);

        if(repeat == 1 && (option_main != 1 || option_main != 2 || option_main != 3 || option_main != 4))
            printf("\n\n\t\tSorry ! Try again.\n\n\n");
   }




    return 0;
}

void main_menu(void)
{

    printf("\n\n\n\n\n");

    for(int i = 1; i <= 30; i++)
    {
        space_management(39);
        border_design(3);

        if(i == 1 || i == 2 || i == 29 || i == 30)
        {
            border_design(63);
        }

        if(i == 5)
        {
            space_management(12);
            printf(" WELCOME TO STUDENT INFO SYSTEM ");

        }

        if(i == 8)
        {
            for(int m = 1; m <= 60; m++)
            {
                printf("*");
            }

        }
        if(i == 11)
        {
            space_management(18);
            printf("1.\t COLLEGE INFO");
        }

        if(i == 15)
        {
            space_management(18);
            printf("2.\t ADMIN");
        }

        if(i == 19)
        {
            space_management(18);
            printf("3.\t STUDENTS");
        }

        if(i == 23)
        {
            space_management(18);
            printf("4.\t QUIT");
        }

        if(i == 26)
        {
            space_management(12);
            printf("ENTER YOUR CHOICE : ");

        }

        if(i == 5)
        {
            space_management(16);
            border_design(3);
        }

        if(i == 8)
        {
            space_management(-1);
            border_design(3);
        }

        if(i == 11)
        {
            space_management(25);
            border_design(3);
        }

        if(i == 15)
        {
            space_management(32);
            border_design(3);
        }

        if(i == 19)
        {
            space_management(29);
            border_design(3);
        }

        if(i == 23)
        {
            space_management(33);
            border_design(3);
        }

        if(i == 26)
        {
            space_management(28);
            border_design(3);
        }


        for(int j = 1; j <= 60; j++)
        {
            if(i==5 || i==8 || i==11 || i==15 || i==19 || i==23 || i == 26)
            {
                continue;
            }
           printf(" ");

        }
        for(int k = 1; k <= 3; k++)
        {
            if(i==1 || i==2 || i==5 || i==8 || i==11 || i==15 || i==19 || i==23 || i == 26 || i==29 || i==30)
            {
                continue;
            }
            printf("|");


        }
        printf("\n");

    }


}

void space_management(int m)
{
    for(int j = 1; j <= m; j++)
        {
           printf(" ");
        }
}

void border_design(int o)
{
    for(int l = 1; l <= o; l++)
        {
            printf("|");
        }
}

void college_info(void)
{
    FILE *collegeInfo_file = NULL;
    collegeInfo_file = fopen("collegeInfo.txt", "r");

    char line[100];
    while(fgets(line, sizeof(line), collegeInfo_file))
    {
        printf("%s", line);
    }

    fclose(collegeInfo_file);
}

#define password_size 11

void admin(void)
{
    admin_login();
    for(int login_repeat = 3; login_repeat > 0; login_repeat--)
    {
        char admin_password[ password_size] = {"vishalkumar"};
        char scan_password[password_size];

        for(int a = 0; a < password_size ; a++)
        {
            scan_password[a] = getch();
            printf("*");
         }

        int return_value = 0;
        for(int i = 0; i < password_size; i++)
        {
            if(admin_password[i] != scan_password[i])
                return_value = 1;
        }

        if(return_value  != 0)
        {
            printf("\n\n\n\t\t Invalid Credentials !!\n");
            printf("\n\n\t\tYou left with %d try !\n\n", login_repeat - 1);
            printf("\t\t  ENTER PASSWORD : \n\n\n");
        }
        else
            break;

        if(login_repeat == 1)
        {
            printf("\n\n\n\t\tSorry ! Try again.\n\n\n");
            goto admin_end;
        }
    }

    admin_main:
    admin_mainmenu();

   int option_adminMain;
   printf("\n\n");
   scanf("\t\t%d", &option_adminMain);


   for(int repeat = 2;repeat >= 0; repeat--)
   {
       switch(option_adminMain)
       {
        case 1 :
           system("cls");
           read_file();
           break;

        case 2 :
           system("cls");
           rewrite_file();
           break;

        case 3 :
            system("cls");
            addContent_file();
            break;

        case 4 :
            break;

        default :
            printf("\n\n\t\tInvalid Response !  \n");
        }

        // Repeating students main_menu if user enters 0 else exit
        if(option_adminMain==1 || option_adminMain==2 || option_adminMain==3)
        {
            int guard_main;
            printf("\n\n\t\t\t\tEnter 0 to back to Admin section or any other number to exit : ");
            scanf("%d", &guard_main);

            if(guard_main == 0)
            {
                system("cls");
                goto admin_main;
            }
            else
                break;
        }

        if(option_adminMain==1 || option_adminMain==2 || option_adminMain==3 || option_adminMain==4)
        {
            break;
        }

        if(option_adminMain!=1 || option_adminMain!=2 || option_adminMain!=3 || option_adminMain!=4)
        {
            printf("\n\n\t\tYou left with %d try !\n\n", repeat);
        }
        printf("\t\tENTER YOUR CHOICE : ");
        scanf("\t\t%d", &option_adminMain);

        if(repeat == 1 && (option_adminMain != 1 || option_adminMain != 2 || option_adminMain != 3 || option_adminMain != 4))
            printf("\n\n\t\tSorry ! Try again.\n\n\n");

   }
    admin_end:
        ;
}

void admin_login(void)
{
    printf("\n\n\n\n\n");
    for(int i = 1; i <= 15; i++)
    {
        space_management(39);
        border_design(3);

        if(i == 1 || i == 2 || i == 14 || i == 15)
        {
            border_design(63);
        }

        if(i == 6)
        {
            space_management(18);
            printf(" ADMIN LOGIN PAGE ");
            space_management(24);
        }

        if(i == 10)
        {
            space_management(8);
            printf("  ENTER PASSWORD : ");
            space_management(33);
        }


        for(int j = 1; j <= 60; j++)
        {
            if(i==6 || i==10)
            {
                continue;
            }
           printf(" ");

        }

        for(int k = 1; k <= 3; k++)
        {
            if(i==1 || i==2 || i==14 || i==15)
            {
                continue;
            }
            printf("|");
        }

        printf("\n");
    }

}

void admin_mainmenu(void)
{
    system("cls");
    printf("\n\n\n\n\n");
    for(int i = 1; i <= 31; i++)
    {
        space_management(39);
        border_design(3);

        if(i == 1 || i == 2 || i == 30 || i == 31)
        {
            border_design(63);
        }

        if(i == 6)
        {
            space_management(17);
            printf(" WELCOME TO ADMIN SECTION ");
            space_management(17);
        }

        if(i == 8)
        {
            for(int j = 1; j <= 60; j++)
            {
                printf("_");
            }
        }

        if(i == 11)
        {
            space_management(18);
            printf(" 1. OPEN FILE ");
            space_management(28);
        }

        if(i == 15)
        {
            space_management(18);
            printf(" 2. REWRITE FILE ");
            space_management(25);
        }

        if(i == 19)
        {
            space_management(18);
            printf(" 3. ADD CONTENT TO FILE ");
            space_management(18);
        }

        if(i == 23)
        {
            space_management(18);
            printf(" 4. QUIT ADMIN SECTION ");
            space_management(19);
        }

        if(i == 26)
        {
            space_management(8);
            printf("  ENTER YOUR CHOICE : ");
            space_management(30);
        }


        for(int j = 1; j <= 60; j++)
        {
            if(i==6 || i==8 || i==11 || i==15 || i==19 || i==23 || i==26)
            {
                continue;
            }
           printf(" ");

        }

        for(int k = 1; k <= 3; k++)
        {
            if(i==1 || i==2 || i==30 || i==31)
            {
                continue;
            }
            printf("|");
        }

        printf("\n");
    }
}

void subject_list(void)
{
    system("cls");
    printf("\n\n\n\n\n");
    for(int i = 1; i <= 39; i++)
    {
        space_management(39);
        border_design(3);

        if(i == 1 || i == 2 || i == 38 || i == 39)
        {
            border_design(63);
        }

        if(i == 6)
        {
            space_management(20);
            printf(" SELECT THE SUBJECT ");
            space_management(20);
        }

        if(i == 8)
        {
            for(int j = 1; j <= 60; j++)
            {
                printf("_");
            }
        }

        if(i == 11)
        {
            space_management(22);
            printf(" 1. PH100 ");
            space_management(28);
        }

        if(i == 15)
        {
            space_management(22);
            printf(" 2. MA101 ");
            space_management(28);
        }

        if(i == 19)
        {
            space_management(22);
            printf(" 3. EC100 ");
            space_management(28);
        }

        if(i == 23)
        {
            space_management(22);
            printf(" 4. IT101 ");
            space_management(28);
        }

        if(i == 27)
        {
            space_management(22);
            printf(" 5. HS101 ");
            space_management(28);
        }

        if(i == 31)
        {
            space_management(22);
            printf(" 6. QUIT THIS SECTION ");
            space_management(16);
        }

        if(i == 34)
        {
            space_management(8);
            printf("  ENTER YOUR CHOICE : ");
            space_management(30);
        }


        for(int j = 1; j <= 60; j++)
        {
            if(i==6 || i==8 || i==11 || i==15 || i==19 || i==23 || i==27 || i==31 || i==34)
            {
                continue;
            }
           printf(" ");

        }

        for(int k = 1; k <= 3; k++)
        {
            if(i==1 || i==2 || i==38 || i==39)
            {
                continue;
            }
            printf("|");
        }

        printf("\n");
    }

}

void admin_choice(void)
{
    system("cls");
    printf("\n\n\n\n\n");

    // this system works line by line
    for(int i = 1; i <= 46; i++)
    {
        // for left most border
        space_management(39);
        border_design(3);

        // for up and down  border
        if(i == 1 || i == 2 || i == 45 || i == 46)
        {
            border_design(63);
        }

        if(i == 6)
        {
            space_management(22);
            printf(" WELCOME ADMIN ");
            space_management(23);
        }

        if(i == 8)
        {
            for(int j = 1; j <= 60; j++)
            {
                printf("_");
            }
        }

        if(i == 11)
        {
            space_management(18);
            printf(" 1. ACEDEMIC CALENDER ");
            space_management(20);
        }

        if(i == 15)
        {
            space_management(18);
            printf("  2. ABOUT FACULTY ");
            space_management(23);
        }

        if(i == 19)
        {
            space_management(18);
            printf("  3. TIME TABLE ");
            space_management(26);
        }

        if(i == 23)
        {
            space_management(18);
            printf("  4. MEETING LINKS ");
            space_management(23);
        }

        if(i == 27)
        {
            space_management(18);
            printf("  5. EXAM/TEST/QUIZ ");
            space_management(22);
        }

        if(i == 31)
        {
            space_management(18);
            printf("  6. ASSIGNMENTS ");
            space_management(25);
        }

        if(i == 35)
        {
            space_management(18);
            printf("  7. GRADES ");
            space_management(30);
        }

        if(i == 39)
        {
            space_management(18);
            printf("  8. QUIT ADMIN CHOICE SECTION ");
            space_management(11);
        }

        if(i == 42)
        {
            space_management(8);
            printf("  ENTER YOUR CHOICE : ");
            space_management(30);
        }


        for(int j = 1; j <= 60; j++)
        {
            if(i==6 || i==8 || i==11 || i==15 || i==19 || i==23 || i==27 || i==31 || i==35 || i==39 || i==42)
            {
                continue;
            }
           printf(" ");

        }

        for(int k = 1; k <= 3; k++)
        {
            if(i==1 || i==2 || i==45 || i==46)
            {
                continue;
            }
            printf("|");
        }
        printf("\n");
    }
}

void read_file(void)
{
    admin_read:
    admin_choice();

   int option_adminRead;
   printf("\n\n");
   scanf("\t\t%d", &option_adminRead);


   for(int repeat = 2;repeat >= 0; repeat--)
   {
       switch(option_adminRead)
       {
        case 1 :
           system("cls");
            FILE *academicCalender_file = NULL;
            academicCalender_file = fopen("academic_calender.txt", "r+");

            char line_academic[100];
            while(fgets(line_academic , sizeof(line_academic), academicCalender_file))
            {
                printf("%s", line_academic);
            }

            fclose(academicCalender_file);
           break;

        case 2 :
           system("cls");
           FILE *faculty_file = NULL;
            faculty_file = fopen("faculty.txt", "r+");

            char line_facaulty[100];
            while(fgets(line_facaulty , sizeof(line_facaulty), faculty_file))
            {
                printf("%s", line_facaulty);
            }

            fclose(faculty_file);
           break;

        case 3 :
            system("cls");
            FILE *timetable_file = NULL;
            timetable_file = fopen("time_table.txt", "r+");

            char line_timetable[100];
            while(fgets(line_timetable , sizeof(line_timetable), timetable_file))
            {
                printf("%s", line_timetable);
            }

            fclose(timetable_file);
            break;

        case 4 :
            system("cls");
            FILE *meetingLinks_file = NULL;
            meetingLinks_file = fopen("meeting_links.txt", "r+");

            char lines_meeting[50];
            while(fgets(lines_meeting , sizeof(lines_meeting), meetingLinks_file))
            {
                printf("%s", lines_meeting);
            }

            fclose(meetingLinks_file);
            break;

        case 5 :
           system("cls");
           FILE *exam_file = NULL;
            exam_file = fopen("exam.txt", "r+");

            char lines_exam[50];
            while(fgets(lines_exam , sizeof(lines_exam), exam_file))
            {
                printf("%s", lines_exam);
            }

            fclose(exam_file);
           break;

        case 6 :
           system("cls");
           FILE *assignments_file = NULL;
            assignments_file = fopen("assignments.txt", "r+");

            char lines_assignment[50];
            while(fgets(lines_assignment, sizeof(lines_assignment), assignments_file))
            {
                printf("%s", lines_assignment);
            }

            fclose(assignments_file);
           break;

        case 7 :
           system("cls");
           grades();
           break;

        case 8 :
           goto read_end;

        default :
            printf("\n\n\t\tInvalid Response !  \n");

        }

        // Repeating students main_menu if user enters 0 else exit
        if(option_adminRead==1 || option_adminRead==2 || option_adminRead==3 || option_adminRead==4 || option_adminRead==5 || option_adminRead==6 || option_adminRead==7)
        {
            int guard_read;
            printf("\n\n\t\t\t\tEnter 0 to back to Admin's choice section or any other number to exit : ");
            scanf("%d", &guard_read);

            if(guard_read == 0)
            {
                system("cls");
                goto admin_read;
            }
            else
                break;
        }

        if(option_adminRead==1 || option_adminRead==2 || option_adminRead==3 || option_adminRead==4 || option_adminRead==5 || option_adminRead==6 || option_adminRead==7)
        {
            break;
        }

        if(option_adminRead!=1 || option_adminRead!=2 || option_adminRead!=3 || option_adminRead!=4 || option_adminRead!=5 || option_adminRead!=6 || option_adminRead!=7)
        {
            printf("\n\n\t\tYou left with %d try !\n\n", repeat);
        }
        printf("\t\tENTER YOUR CHOICE : ");
        scanf("\t\t%d", &option_adminRead);

        if(repeat == 1)
            printf("\n\n\t\tSorry ! Try again.\n\n\n");

   }

   read_end:
       ;
}

void rewrite_file(void)
{
    admin_rewrite:
    admin_choice();

   int option_adminRewrite;
   printf("\n\n");
   scanf("\t\t%d", &option_adminRewrite);


   for(int repeat = 2;repeat >= 0; repeat--)
   {
       switch(option_adminRewrite)
       {
        case 1 :
           system("cls");
            FILE *academicCalender_file = NULL;
            academicCalender_file = fopen("academic_calender.txt", "w+");

            char line_calender[15];
            for(int i = 0; i<sizeof(line_calender); i++)
            {
                scanf("%c", &line_calender[i]);
            }

            for(int k =0; k < sizeof(line_calender); k++)
            {
                fprintf(academicCalender_file,"%c",line_calender[k]);
            }


            fclose(academicCalender_file);
           break;

        case 2 :
           system("cls");
           FILE *faculty_file = NULL;
            faculty_file = fopen("faculty.txt", "w+");

            char line_facaulty[100];
            for(int i = 0; i<sizeof(line_facaulty); i++)
            {
                scanf("%c", &line_facaulty[i]);
            }

            for(int k =0; k < sizeof(line_facaulty); k++)
            {
                fprintf(faculty_file,"%c",line_facaulty[k]);
            }
            fclose(faculty_file);
           break;

        case 3 :
            system("cls");
            FILE *timetable_file = NULL;
            timetable_file = fopen("time_table.txt", "w+");

            char line_timetable[100];
            for(int i = 0; i<sizeof(line_timetable); i++)
            {
                scanf("%c", &line_timetable[i]);
            }

            for(int k =0; k < sizeof(line_timetable); k++)
            {
                fprintf(timetable_file,"%c",line_timetable[k]);
            }

            fclose(timetable_file);
            break;

        case 4 :
            system("cls");
            FILE *meetingLinks_file = NULL;
            meetingLinks_file = fopen("meeting_links.txt", "w+");

            char lines_meeting[50];
            for(int i = 0; i<sizeof(lines_meeting); i++)
            {
                scanf("%c", &lines_meeting[i]);
            }

            for(int k =0; k < sizeof(lines_meeting); k++)
            {
                fprintf(meetingLinks_file,"%c",lines_meeting[k]);
            }

            fclose(meetingLinks_file);
            break;

        case 5 :
           system("cls");
           FILE *exam_file = NULL;
            exam_file = fopen("exam.txt", "w+");

            char lines_exam[50];
            for(int i = 0; i<sizeof(lines_exam); i++)
            {
                scanf("%c", &lines_exam[i]);
            }

            for(int k =0; k < sizeof(lines_exam); k++)
            {
                fprintf(exam_file,"%c",lines_exam[k]);
            }
            fclose(exam_file);
           break;

        case 6 :
           system("cls");
           FILE *assignments_file = NULL;
            assignments_file = fopen("assignments.txt", "w+");

            char lines_assignment[50];
            for(int i = 0; i<sizeof(lines_assignment); i++)
            {
                scanf("%c", &lines_assignment[i]);
            }

            for(int k =0; k < sizeof(lines_assignment); k++)
            {
                fprintf(assignments_file,"%c",lines_assignment[k]);
            }

            fclose(assignments_file);
           break;

        case 7 :
           system("cls");
           grades_rewrite();
           break;

        case 8 :
           goto rewrite_end;

        default :
            printf("\n\n\t\tInvalid Response !  \n");

        }

        // Repeating students main_menu if user enters 0 else exit
        if(option_adminRewrite==1 || option_adminRewrite==2 || option_adminRewrite==3 || option_adminRewrite==4 || option_adminRewrite==5 || option_adminRewrite==6 || option_adminRewrite==7)
        {
            int guard_main;
            printf("\n\n\t\t\t\tEnter 0 to back to Admin's choice section or any other number to exit : ");
            scanf("%d", &guard_main);

            if(guard_main == 0)
            {
                system("cls");
                goto admin_rewrite;
            }
            else
                break;
        }

        if(option_adminRewrite==1 || option_adminRewrite==2 || option_adminRewrite==3 || option_adminRewrite==4 || option_adminRewrite==5 || option_adminRewrite==6 || option_adminRewrite==7)
        {
            break;
        }

        if(option_adminRewrite!=1 || option_adminRewrite!=2 || option_adminRewrite!=3 || option_adminRewrite!=4 || option_adminRewrite!=5 || option_adminRewrite!=6 || option_adminRewrite!=7)
        {
            printf("\n\n\t\tYou left with %d try !\n\n", repeat);
        }
        printf("\t\tENTER YOUR CHOICE : ");
        scanf("\t\t%d", & option_adminRewrite);

        if(repeat == 1)
            printf("\n\n\t\tSorry ! Try again.\n\n\n");

   }

   rewrite_end:
       ;

}

void addContent_file(void)
{
    admin_addContent:
    admin_choice();

   int option_adminAddContent;
   printf("\n\n");
   scanf("\t\t%d", &option_adminAddContent);


   for(int repeat = 2;repeat >= 0; repeat--)
   {
       switch(option_adminAddContent)
       {
        case 1 :
           system("cls");
            FILE *academicCalender_file = NULL;
            academicCalender_file = fopen("academic_calender.txt", "a+");

            char line_calender[100];
            while(fgets(line_calender , sizeof(line_calender), academicCalender_file))
            {
                printf("%s", line_calender);
            }

            char line_calender1[15];
            for(int i = 0; i<sizeof(line_calender1); i++)
            {
                scanf("%c", &line_calender1[i]);
            }

            for(int k =0; k < sizeof(line_calender1); k++)
            {
                fprintf(academicCalender_file,"%c",line_calender1[k]);
            }

            fclose(academicCalender_file);
           break;

        case 2 :
           system("cls");
           FILE *faculty_file = NULL;
            faculty_file = fopen("faculty.txt", "a+");

            char line_facaulty[100];
            while(fgets(line_facaulty , sizeof(line_facaulty), faculty_file))
            {
                scanf("%s", line_facaulty);
            }

            char line_facaulty1[100];
            for(int i = 0; i<sizeof(line_facaulty1); i++)
            {
                scanf("%c", &line_facaulty1[i]);
            }

            for(int k =0; k < sizeof(line_facaulty1); k++)
            {
                fprintf(faculty_file,"%c",line_facaulty1[k]);
            }

            fclose(faculty_file);
           break;

        case 3 :
            system("cls");
            FILE *timetable_file = NULL;
            timetable_file = fopen("time_table.txt", "a+");

            char line_timetable[100];
            while(fgets(line_timetable , sizeof(line_timetable), timetable_file))
            {
                printf("%s", line_timetable);
            }

            char line_timetable1[100];
            for(int i = 0; i<sizeof(line_timetable1); i++)
            {
                scanf("%c", &line_timetable1[i]);
            }

            for(int k =0; k < sizeof(line_timetable1); k++)
            {
                fprintf(timetable_file,"%c",line_timetable1[k]);
            }

            fclose(timetable_file);
            break;

        case 4 :
            system("cls");
            FILE *meetingLinks_file = NULL;
            meetingLinks_file = fopen("meeting_links.txt", "a+");

            char lines_meeting[50];
            while(fgets(lines_meeting , sizeof(lines_meeting), meetingLinks_file))
            {
                printf("%s", lines_meeting);
            }

            char lines_meeting1[50];
            for(int i = 0; i<sizeof(lines_meeting1); i++)
            {
                scanf("%c", &lines_meeting1[i]);
            }

            for(int k =0; k < sizeof(lines_meeting1); k++)
            {
                fprintf(meetingLinks_file,"%c",lines_meeting1[k]);
            }

            fclose(meetingLinks_file);
            break;

        case 5 :
           system("cls");
           FILE *exam_file = NULL;
            exam_file = fopen("exam.txt", "a+");

            char lines_exam[50];
            while(fgets(lines_exam , sizeof(lines_exam), exam_file))
            {
                printf("%s", lines_exam);
            }

            char lines_exam1[50];
            for(int i = 0; i<sizeof(lines_exam1); i++)
            {
                scanf("%c", &lines_exam1[i]);
            }

            for(int k =0; k < sizeof(lines_exam1); k++)
            {
                fprintf(exam_file,"%c",lines_exam1[k]);
            }

            fclose(exam_file);
           break;

        case 6 :
           system("cls");
           FILE *assignments_file = NULL;
            assignments_file = fopen("assignments.txt", "a+");

            char lines_assignment[50];
            while(fgets(lines_assignment, sizeof(lines_assignment), assignments_file))
            {
                printf("%s", lines_assignment);
            }

            char lines_assignment1[50];
            for(int i = 0; i<sizeof(lines_assignment1); i++)
            {
                scanf("%c", &lines_assignment1[i]);
            }

            for(int k =0; k < sizeof(lines_assignment1); k++)
            {
                fprintf(assignments_file,"%c",lines_assignment1[k]);
            }

            fclose(assignments_file);
           break;

        case 7 :
           system("cls");
           grades_add();
           break;

        case 8 :
           goto addContent_end;

        default :
            printf("\n\n\t\tInvalid Response !  \n");

        }

        // Repeating students main_menu if user enters 0 else exit
        if(option_adminAddContent==1 || option_adminAddContent==2 || option_adminAddContent==3 || option_adminAddContent==4 || option_adminAddContent==5 || option_adminAddContent==6 || option_adminAddContent==7)
        {
            int guard_main;
            printf("\n\n\t\t\t\tEnter 0 to back to Admin's choice section or any other number to exit : ");
            scanf("%d", &guard_main);

            if(guard_main == 0)
            {
                system("cls");
                goto admin_addContent;
            }
            else
                break;
        }

        if(option_adminAddContent==1 || option_adminAddContent==2 || option_adminAddContent==3 || option_adminAddContent==4 || option_adminAddContent==5 || option_adminAddContent==6 || option_adminAddContent==7)
        {
            break;
        }

        if(option_adminAddContent!=1 || option_adminAddContent!=2 || option_adminAddContent!=3 || option_adminAddContent!=4 || option_adminAddContent!=5 || option_adminAddContent!=6 || option_adminAddContent!=7)
        {
            printf("\n\n\t\tYou left with %d try !\n\n", repeat);
        }
        printf("\t\tENTER YOUR CHOICE : ");
        scanf("\t\t%d", & option_adminAddContent);

        if(repeat == 1)
            printf("\n\n\t\tSorry ! Try again.\n\n\n");

   }

   addContent_end:
       ;


}

void grades(void)
{
    grades_main:
    subject_list();

   int option_grade;
   printf("\n\n");
   scanf("\t\t%d", &option_grade);


   for(int repeat = 2;repeat >= 0; repeat--)
   {
       switch(option_grade)
       {
        case 1 :
           system("cls");
            FILE *PH100_file = NULL;
            PH100_file = fopen("PH100.txt", "r");

            char line_PH100[100];
            while(fgets(line_PH100 , sizeof(line_PH100), PH100_file))
            {
                printf("%s", line_PH100);
            }

            fclose(PH100_file);
           break;

        case 2 :
           system("cls");
           FILE *MA101_file = NULL;
            MA101_file = fopen("MA101.txt", "r");

            char line_MA101[100];
            while(fgets(line_MA101 , sizeof(line_MA101), MA101_file))
            {
                printf("%s", line_MA101);
            }

            fclose(MA101_file);
           break;

        case 3 :
            system("cls");
            FILE *EC100_file = NULL;
            EC100_file = fopen("EC100.txt", "r");

            char line_EC100[100];
            while(fgets(line_EC100 , sizeof(line_EC100), EC100_file))
            {
                printf("%s", line_EC100);
            }

            fclose(EC100_file);
            break;

        case 4 :
            system("cls");
            FILE *IT101_file = NULL;
            IT101_file = fopen("IT101.txt", "r");

            char lines_IT101[50];
            while(fgets(lines_IT101 , sizeof(lines_IT101), IT101_file))
            {
                printf("%s", lines_IT101);
            }

            fclose(IT101_file);
            break;

        case 5 :
           system("cls");
           FILE *HS101_file = NULL;
            HS101_file = fopen("HS101.txt", "r");

            char lines_HS101[50];
            while(fgets(lines_HS101 , sizeof(lines_HS101), HS101_file))
            {
                printf("%s", lines_HS101);
            }

            fclose(HS101_file);
           break;

        case 6 :
            break;

        default :
            printf("\n\n\t\tInvalid Response !  \n");

        }

        // Repeating students main_menu if user enters 0 else exit
        if(option_grade==1 || option_grade==2 || option_grade==3 || option_grade==4 || option_grade==5)
        {
            int guard_main;
            printf("\n\n\t\t\t\tEnter 0 to back to Subject list section or any other number to exit : ");
            scanf("%d", &guard_main);

            if(guard_main == 0)
            {
                system("cls");
                goto grades_main;
            }
            else
                break;
        }

        if(option_grade==1 || option_grade==2 || option_grade==3 || option_grade==4 || option_grade==5 || option_grade == 6)
        {
            break;
        }

        if(option_grade!=1 || option_grade!=2 || option_grade!=3 || option_grade!=4 || option_grade!=5 || option_grade != 6)
        {
            printf("\n\n\t\tYou left with %d try !\n\n", repeat);
        }
        printf("\t\tENTER YOUR CHOICE : ");
        scanf("\t\t%d", &option_grade);

        if(repeat == 1 && (option_grade != 1 || option_grade != 2 || option_grade != 3 || option_grade != 4 || option_grade != 5 || option_grade != 6))
            printf("\n\n\t\tSorry ! Try again.\n\n\n");

   }

   grades_end:
       ;

}

void grades_rewrite(void)
{
    gradesRewrite_main:
    subject_list();

   int option_gradeRewrite;
   printf("\n\n");
   scanf("\t\t%d", &option_gradeRewrite);


   for(int repeat = 2;repeat >= 0; repeat--)
   {
       switch(option_gradeRewrite)
       {
        case 1 :
           system("cls");
            FILE *PH100_file = NULL;
            PH100_file = fopen("PH100.txt", "w+");

            char line_PH100[100];
            for(int i = 0; i<sizeof(line_PH100); i++)
            {
                scanf("%c", &line_PH100[i]);
            }

            for(int k =0; k < sizeof(line_PH100); k++)
            {
                fprintf(PH100_file,"%c",line_PH100[k]);
            }
            fclose(PH100_file);
           break;

        case 2 :
           system("cls");
           FILE *MA101_file = NULL;
            MA101_file = fopen("MA101.txt", "w+");

            char line_MA101[100];
            for(int i = 0; i<sizeof(line_MA101); i++)
            {
                scanf("%c", &line_MA101[i]);
            }

            for(int k =0; k < sizeof(line_MA101); k++)
            {
                fprintf(MA101_file,"%c",line_MA101[k]);
            }

            fclose(MA101_file);
           break;

        case 3 :
            system("cls");
            FILE *EC100_file = NULL;
            EC100_file = fopen("EC100.txt", "w+");

            char line_EC100[100];
            for(int i = 0; i<sizeof(line_EC100); i++)
            {
                scanf("%c", &line_EC100[i]);
            }

            for(int k =0; k < sizeof(line_EC100); k++)
            {
                fprintf(EC100_file,"%c",line_EC100[k]);
            }

            fclose(EC100_file);
            break;

        case 4 :
            system("cls");
            FILE *IT101_file = NULL;
            IT101_file = fopen("IT101.txt", "w+");

            char lines_IT101[50];
            for(int i = 0; i<sizeof(lines_IT101); i++)
            {
                scanf("%c", &lines_IT101[i]);
            }

            for(int k =0; k < sizeof(lines_IT101); k++)
            {
                fprintf(IT101_file,"%c",lines_IT101[k]);
            }
            fclose(IT101_file);
            break;

        case 5 :
           system("cls");
           FILE *HS101_file = NULL;
            HS101_file = fopen("HS101.txt", "w+");

            char lines_HS101[50];
            for(int i = 0; i<sizeof(lines_HS101); i++)
            {
                scanf("%c", &lines_HS101[i]);
            }

            for(int k =0; k < sizeof(lines_HS101); k++)
            {
                fprintf(HS101_file,"%c",lines_HS101[k]);
            }

            fclose(HS101_file);
           break;

        case 6 :
            break;

        default :
            printf("\n\n\t\tInvalid Response !  \n");

        }

        // Repeating students main_menu if user enters 0 else exit
        if(option_gradeRewrite==1 || option_gradeRewrite==2 || option_gradeRewrite==3 || option_gradeRewrite==4 || option_gradeRewrite==5)
        {
            int guard_main;
            printf("\n\n\t\t\t\tEnter 0 to back to Subject list section or any other number to exit : ");
            scanf("%d", &guard_main);

            if(guard_main == 0)
            {
                system("cls");
                goto gradesRewrite_main;
            }
            else
                break;
        }

        if(option_gradeRewrite==1 || option_gradeRewrite==2 || option_gradeRewrite==3 || option_gradeRewrite==4 || option_gradeRewrite==5 || option_gradeRewrite==6)
        {
            break;
        }

        if(option_gradeRewrite!=1 || option_gradeRewrite!=2 || option_gradeRewrite!=3 || option_gradeRewrite!=4 || option_gradeRewrite!=5 || option_gradeRewrite!=6)
        {
            printf("\n\n\t\tYou left with %d try !\n\n", repeat);
        }
        printf("\t\tENTER YOUR CHOICE : ");
        scanf("\t\t%d", &option_gradeRewrite);

        if(repeat == 1 && (option_gradeRewrite!=1 || option_gradeRewrite!=2 || option_gradeRewrite!=3 || option_gradeRewrite!=4 || option_gradeRewrite!=5 || option_gradeRewrite!=6))
            printf("\n\n\t\tSorry ! Try again.\n\n\n");

   }



}

void grades_add(void)
{
    gradesAdd_main:
    subject_list();

   int option_gradeAdd;
   printf("\n\n");
   scanf("\t\t%d", &option_gradeAdd);


   for(int repeat = 2;repeat >= 0; repeat--)
   {
       switch(option_gradeAdd)
       {
        case 1 :
           system("cls");
            FILE *PH100_file = NULL;
            PH100_file = fopen("PH100.txt", "a+");

            char line_PH100[100];
            while(fgets(line_PH100 , sizeof(line_PH100), PH100_file))
            {
                printf("%s", line_PH100);
            }

             char line_PH100_1[100];
            for(int i = 0; i<sizeof(line_PH100_1); i++)
            {
                scanf("%c", &line_PH100_1[i]);
            }

            for(int k =0; k < sizeof(line_PH100_1); k++)
            {
                fprintf(PH100_file,"%c",line_PH100_1[k]);
            }

            fclose(PH100_file);
           break;

        case 2 :
           system("cls");
           FILE *MA101_file = NULL;
            MA101_file = fopen("MA101.txt", "a+");

            char line_MA101[100];
            while(fgets(line_MA101 , sizeof(line_MA101), MA101_file))
            {
                printf("%s", line_MA101);
            }

            char line_MA101_1[100];
            for(int i = 0; i<sizeof(line_MA101_1); i++)
            {
                scanf("%c", &line_MA101_1[i]);
            }

            for(int k =0; k < sizeof(line_MA101_1); k++)
            {
                fprintf(MA101_file,"%c",line_MA101_1[k]);
            }

            fclose(MA101_file);
           break;

        case 3 :
            system("cls");
            FILE *EC100_file = NULL;
            EC100_file = fopen("EC100.txt", "a+");

            char line_EC100[100];
            while(fgets(line_EC100 , sizeof(line_EC100), EC100_file))
            {
                printf("%s", line_EC100);
            }

            char line_EC100_1[100];
            for(int i = 0; i<sizeof(line_EC100_1); i++)
            {
                scanf("%c", &line_EC100_1[i]);
            }

            for(int k =0; k < sizeof(line_EC100_1); k++)
            {
                fprintf(EC100_file,"%c",line_EC100_1[k]);
            }


            fclose(EC100_file);
            break;

        case 4 :
            system("cls");
            FILE *IT101_file = NULL;
            IT101_file = fopen("IT101.txt", "a+");

            char lines_IT101[50];
            while(fgets(lines_IT101 , sizeof(lines_IT101), IT101_file))
            {
                printf("%s", lines_IT101);
            }

            char lines_IT101_1[50];
            for(int i = 0; i<sizeof(lines_IT101_1); i++)
            {
                scanf("%c", &lines_IT101_1[i]);
            }

            for(int k =0; k < sizeof(lines_IT101_1); k++)
            {
                fprintf(IT101_file,"%c",lines_IT101_1[k]);
            }

            fclose(IT101_file);
            break;

        case 5 :
           system("cls");
           FILE *HS101_file = NULL;
            HS101_file = fopen("HS101.txt", "a+");

            char lines_HS101[50];
            while(fgets(lines_HS101 , sizeof(lines_HS101), HS101_file))
            {
                printf("%s", lines_HS101);
            }

            char lines_HS101_1[50];
            for(int i = 0; i<sizeof(lines_HS101_1); i++)
            {
                scanf("%c", &lines_HS101_1[i]);
            }

            for(int k =0; k < sizeof(lines_HS101_1); k++)
            {
                fprintf(HS101_file,"%c",lines_HS101_1[k]);
            }

            fclose(HS101_file);
           break;

        case 6 :
            break;

        default :
            printf("\n\n\t\tInvalid Response !  \n");

        }

        // Repeating students main_menu if user enters 0 else exit
        if(option_gradeAdd==1 || option_gradeAdd==2 || option_gradeAdd==3 || option_gradeAdd==4 || option_gradeAdd==5)
        {
            int guard_main;
            printf("\n\n\t\t\t\tEnter 0 to back to Subject list section or any other number to exit : ");
            scanf("%d", &guard_main);

            if(guard_main == 0)
            {
                system("cls");
                goto gradesAdd_main;
            }
            else
                break;
        }

        if(option_gradeAdd==1 || option_gradeAdd==2 || option_gradeAdd==3 || option_gradeAdd==4 || option_gradeAdd==5 || option_gradeAdd==6)
        {
            break;
        }

        if(option_gradeAdd!=1 || option_gradeAdd!=2 || option_gradeAdd!=3 || option_gradeAdd!=4 || option_gradeAdd!=5 || option_gradeAdd!=6)
        {
            printf("\n\n\t\tYou left with %d try !\n\n", repeat);
        }
        printf("\t\tENTER YOUR CHOICE : ");
        scanf("\t\t%d", &option_gradeAdd);

        if(repeat == 1 && (option_gradeAdd!=1 || option_gradeAdd!=2 || option_gradeAdd!=3 || option_gradeAdd!=4 || option_gradeAdd!=5 || option_gradeAdd!=6))
            printf("\n\n\t\tSorry ! Try again.\n\n\n");

   }



}

void students(void)
{
   student_main:
   students_mainmenu();

   int option_studentMain;
   printf("\n\n");
   scanf("\t\t%d", &option_studentMain);


   for(int repeat = 2;repeat >= 0; repeat--)
   {
       switch(option_studentMain)
       {
        case 1 :
           system("cls");
            FILE *academicCalender_file = NULL;
            academicCalender_file = fopen("academic_calender.txt", "r");

            char line_calender[100];
            while(fgets(line_calender , sizeof(line_calender), academicCalender_file))
            {
                printf("%s", line_calender);
            }

            fclose(academicCalender_file);
           break;

        case 2 :
           system("cls");
           FILE *faculty_file = NULL;
            faculty_file = fopen("faculty.txt", "r");

            char line_facaulty[100];
            while(fgets(line_facaulty , sizeof(line_facaulty), faculty_file))
            {
                printf("%s", line_facaulty);
            }

            fclose(faculty_file);
           break;

        case 3 :
            system("cls");
            FILE *timetable_file = NULL;
            timetable_file = fopen("time_table.txt", "r");

            char line_timetable[100];
            while(fgets(line_timetable , sizeof(line_timetable), timetable_file))
            {
                printf("%s", line_timetable);
            }

            fclose(timetable_file);
            break;

        case 4 :
            system("cls");
            FILE *meetingLinks_file = NULL;
            meetingLinks_file = fopen("meeting_links.txt", "r");

            char lines_meeting[50];
            while(fgets(lines_meeting , sizeof(lines_meeting), meetingLinks_file))
            {
                printf("%s", lines_meeting);
            }

            fclose(meetingLinks_file);
            break;

        case 5 :
           system("cls");
           FILE *exam_file = NULL;
            exam_file = fopen("exam.txt", "r");

            char lines_exam[50];
            while(fgets(lines_exam , sizeof(lines_exam), exam_file))
            {
                printf("%s", lines_exam);
            }

            fclose(exam_file);
           break;

        case 6 :
           system("cls");
           FILE *assignments_file = NULL;
            assignments_file = fopen("assignments.txt", "r");

            char lines_assignment[50];
            while(fgets(lines_assignment, sizeof(lines_assignment), assignments_file))
            {
                printf("%s", lines_assignment);
            }

            fclose(assignments_file);
           break;

        case 7 :
           system("cls");
           grades();
           break;

        case 8 :
           goto students_end;

        default :
            printf("\n\n\t\tInvalid Response !  \n");

        }

        // Repeating students main_menu if user enters 0 else exit
        if(option_studentMain==1 || option_studentMain==2 || option_studentMain==3 || option_studentMain==4 || option_studentMain==5 || option_studentMain==6 || option_studentMain==7)
        {
            int guard_main;
            printf("\n\n\t\t\t\tEnter 0 to back to Student's section or any other number to exit : ");
            scanf("%d", &guard_main);

            if(guard_main == 0)
            {
                system("cls");
                goto student_main;
            }
            else
                break;
        }

        if(option_studentMain==1 || option_studentMain==2 || option_studentMain==3 || option_studentMain==4 || option_studentMain==5 || option_studentMain==6 || option_studentMain==7)
        {
            break;
        }

        if(option_studentMain!=1 || option_studentMain!=2 || option_studentMain!=3 || option_studentMain!=4 || option_studentMain!=5 || option_studentMain!=6 || option_studentMain!=7)
        {
            printf("\n\n\t\tYou left with %d try !\n\n", repeat);
        }
        printf("\t\tENTER YOUR CHOICE : ");
        scanf("\t\t%d", &option_studentMain);

        if(repeat == 1)
            printf("\n\n\t\tSorry ! Try again.\n\n\n");

   }

   students_end:
       ;
}

void students_mainmenu(void)
{
    printf("\n\n\n\n\n");

    // this system works line by line
    for(int i = 1; i <= 46; i++)
    {
        // for left most border
        space_management(39);
        border_design(3);

        // for up and down  border
        if(i == 1 || i == 2 || i == 45 || i == 46)
        {
            border_design(63);
        }

        if(i == 6)
        {
            space_management(15);
            printf(" WELCOME TO STUDENT'S SECTION ");
            space_management(15);
        }

        if(i == 8)
        {
            for(int j = 1; j <= 60; j++)
            {
                printf("_");
            }
        }

        if(i == 11)
        {
            space_management(18);
            printf(" 1. ACEDEMIC CALENDER ");
            space_management(20);
        }

        if(i == 15)
        {
            space_management(18);
            printf("  2. ABOUT FACULTY ");
            space_management(23);
        }

        if(i == 19)
        {
            space_management(18);
            printf("  3. TIME TABLE ");
            space_management(26);
        }

        if(i == 23)
        {
            space_management(18);
            printf("  4. MEETING LINKS ");
            space_management(23);
        }

        if(i == 27)
        {
            space_management(18);
            printf("  5. EXAM/TEST/QUIZ ");
            space_management(22);
        }

        if(i == 31)
        {
            space_management(18);
            printf("  6. ASSIGNMENTS ");
            space_management(25);
        }

        if(i == 35)
        {
            space_management(18);
            printf("  7. GRADES ");
            space_management(30);
        }

        if(i == 39)
        {
            space_management(18);
            printf("  8. QUIT STUDENT'S SECTION ");
            space_management(14);
        }

        if(i == 42)
        {
            space_management(8);
            printf("  ENTER YOUR CHOICE : ");
            space_management(30);
        }


        for(int j = 1; j <= 60; j++)
        {
            if(i==6 || i==8 || i==11 || i==15 || i==19 || i==23 || i==27 || i==31 || i==35 || i==39 || i==42)
            {
                continue;
            }
           printf(" ");

        }

        for(int k = 1; k <= 3; k++)
        {
            if(i==1 || i==2 || i==45 || i==46)
            {
                continue;
            }
            printf("|");
        }
        printf("\n");
    }
}

void quit(void)
{
    printf("\n\n");
    printf("\n\t\tThank You ! For Using 'STUDENT INFO SYSTEM' \n\n\t\tHave A Nice Day !!\n\n\n");
}

