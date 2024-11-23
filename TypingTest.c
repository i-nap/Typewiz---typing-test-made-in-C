#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_WORDS 1024
#define MAX_WORD_LENGTH 1024

struct user_info_create{
    char firstName[200];
    char secondName[200];
    char userName[200];
    char passWord[200];
    char rep_passWord[200];
}u[1];

struct user_info_read{
    char firstName[200];
    char secondName[200];
    char userName[200];
    char passWord[200];
}ur[1];

struct highscore_user{
    char username[200];
    int user_wpm;
};

int login_page()
{
    //login page beginning page of the program
        printf("\033[35m"); //purple color
    	char text[1024]="\
\n\t\t\t\t-----------------------------------------------------------\r\
\n\t\t\t\t000000 00  00 00000   000000 00            00 000000 000000\r\
\n\t\t\t\t  00    0000  00   00 00      00          00    00       0\r\
\n\t\t\t\t  00     00   00000   0000     00   00   00     00      0\r\
\n\t\t\t\t  00     00   00      00        00 0000 00      00     0\r\
\n\t\t\t\t  00     00   00      000000      00  00      000000 000000\r\
\n\t\t\t\t-----------------------------------------------------------\r\
\n\r\
";
    printf("%s",text);
    printf("\033[36m"); //cyan
    printf("\n\t\t\t\t1.");
    printf("\033[35m"); //purple color
    printf("Login");
    printf("\033[36m"); //cyan
    printf("\n\t\t\t\t2.");
    printf("\033[35m"); //purple color
    printf("Create an account\n");
    int user_selection;
    printf("\033[36m"); //cyan
    scanf("%d",&user_selection);
    return user_selection;
}

int login()
{
    any:
    memset(u[0].passWord,0,strlen(u[0].passWord));
    memset(u[0].rep_passWord,0,strlen(u[0].rep_passWord));
    system("cls");
    printf("\033[35m"); //purple color
    printf("\n\t\t\t\tUsername:");
    printf("\033[36m"); //cyan
    scanf("%s",u[0].userName);
    printf("\033[35m"); //purple color
    printf("\n\t\t\t\tPassword(Press Tab instead of Enter pls):");
    char ch;
    int i=0;
    printf("\033[36m"); //cyan
    while(1)
    {
        ch = getch();
        if(ch=='\t')
        {
            break;
        }
        if(ch=='\b' && i!=0)
        {
            i--;
            u[0].passWord[i] = '\0';
            printf("\b");
            printf(" ");
            printf("\b");
        }
        else if(ch!='\b')
        {
            u[0].passWord[i] = ch;
            printf("*");
            i++;
        }
    }
    int check;
    FILE *fp;
    fp=fopen("usersData.txt","r");
    while(fscanf(fp,"%s %s %s %s",ur[0].firstName,ur[0].secondName,ur[0].userName,ur[0].passWord)!=EOF)
    {
        if(strcmp(ur[0].userName,u[0].userName)==0 && strcmp(ur[0].passWord,u[0].passWord)==0)
        {
            check=1;
            break;
        }
    }
    randomkey:
    if(check==1)
    {
        system("cls");
        printf("\033[35m"); //purple color
        printf("\n\n\t\t\t\tSuccessfully logined in as ");
        printf("\033[36m"); //cyan
        printf("%s",u[0].userName);
        sleep(3);
        system("cls");
    }
    else
    {
        system("cls");
        printf("\033[35m"); //purple color
        printf("\n\n\t\t\t\tIncorrect username or password\n\t\t\t\tTo go back press 'BACKSPACE'\n\t\t\t\tTo try again press 'TAB'.");
        char in=getch();
        if(in=='\b')
        {
            return 1;
        }
        else if(in=='\t')
        {
            goto any;
        }
        else
        {
            goto randomkey;
        }
    }
}

int create()
{
    char ch;
    printf("\033[35m"); //purple color
    printf("\n\t\t\t\tFirst Name:");
    printf("\033[36m"); //cyan
    scanf("%s",u[0].firstName);
    printf("\033[35m"); //purple color
    printf("\n\t\t\t\tSurname:");
    printf("\033[36m"); //cyan
    scanf("%s",u[0].secondName);
    printf("\033[35m"); //purple color
    printf("\n\t\t\t\tUsername:");
    printf("\033[36m"); //cyan
    scanf("%s",u[0].userName);
    password:
    memset(u[0].passWord,0,strlen(u[0].passWord));
    memset(u[0].rep_passWord,0,strlen(u[0].rep_passWord));
    printf("\033[35m"); //purple color
    printf("\n\t\t\t\tPassword(Press Tab instead of Enter pls):");
    int i=0;
    printf("\033[36m"); //cyan
    while(1)
    {
        ch = getch();
        if(ch=='\t')
        {
            break;
        }
        if(ch=='\b' && i!=0)
        {
            i--;
            u[0].passWord[i] = '\0';
            printf("\b");
            printf(" ");
            printf("\b");
        }
        else if(ch!='\b')
        {
            u[0].passWord[i] = ch;
            printf("*");
            i++;
        }
    }
    printf("\033[35m"); //purple color
    printf("\n");
    printf("\n\t\t\t\tRepeat Password:");
    i=0;
    printf("\033[36m"); //cyan
    while(1)
    {
        ch = getch();
        if(ch=='\t')
        {
            break;
        }
        if(ch=='\b' && i!=0)
        {
            i--;
            u[0].rep_passWord[i] = '\0';
            printf("\b");
            printf(" ");
            printf("\b");
        }
        else if(ch!='\b')
        {
            u[0].rep_passWord[i] = ch;
            printf("*");
            i++;
        }
    }
    printf("\n\n");
    if(strcmp(u[0].rep_passWord,u[0].passWord)!=0)
    {
        int a=0;
        const int trigger = 500; // ms
        const int numDots = 4;
        const char prompt[] = "Password doesnt match. Try again";
        while (a<1) 
        {
        // Return and clear with spaces, then return and print prompt.
            a=a+1;
            printf("\r%*s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
            fflush(stdout);

            // Print numDots number of dots, one every trigger milliseconds.
            for (int i = 0; i < numDots; i++) 
            {
                usleep(trigger * 1000);
                fputc('.', stdout);
                fflush(stdout);
            }
            
        }
        goto password;
    }
    FILE *fp;
    fp=fopen("usersData.txt","a");
    fprintf(fp,"\n%s %s %s %s",u[0].firstName,u[0].secondName,u[0].userName,u[0].passWord);
    fclose(fp);
    system("cls");
}

int home_screen()
{

    printf("\033[0m"); //defualt color
    printf("\033[35m"); //purple color
    printf("\n\t\t\t\t\t\t\t\t%s",__DATE__);
    printf("\033[36m"); //cyan
    printf("\n\t\t\t\t\t\t\t\t%s\n",__TIME__);
    printf("\033[35m"); //purple color
    printf("\n\t\t\t\t\t\t\t\tHello!");
    printf("\033[36m"); //cyan
    printf("%s\t\n",u[0].userName);
    printf("\033[36m"); //cyan
    printf("\n\t\t\t\t1.");
    printf("\033[35m"); //purple color
    printf(" Start\n");
    printf("\033[36m"); //cyan
    printf("\n\t\t\t\t2.");
    printf("\033[35m"); //purple color
    printf(" High Scores \n");
    printf("\033[36m"); //cyan
    printf("\n\t\t\t\t3.");
    printf("\033[35m"); //purple color
    printf(" Help\n");
    printf("\033[36m"); //cyan
    printf("\n\t\t\t\t4.");
    printf("\033[35m"); //purple color
    printf(" Exit\n");
    int home_screen_option;
    printf("\033[36m"); //cyan
    scanf("\n\t\t\t\t%d",&home_screen_option);
    fflush(stdin);
    system("cls");
    return home_screen_option;
    printf("\033[0m"); //defualt color

}

void help()
{
    system("cls");
    printf("\033[35m"); //purple color
    printf("\t\t/////////////////////////////////////////////////////");
    printf("\033[36m"); //cyan
    printf("HELP");
    printf("\033[35m"); //purple color
    printf("/////////////////////////////////////////////////////\n");
    printf("\033[35m"); //purple color
    printf("\n\t\t\tWelcome to the Typing Tutor help section! This program is designed to help you improve your typing\n\t\t\tspeed and accuracy. To get started, simply select press start from the main menu, choose the\n\t\t\tseconds and begin typing the words that appear on the screen. As you type, the program will keep\n\t\t\ttrack of your speed and accuracy. If you need to retry or stop a session, simply hit the Tab key.\n\t\t\tIf you have any questions or encounter any issues while using the program, please refer to the user\n\t\t\tmanual or contact our support team for assistance. Happy typing!\n"); //instruction lekh
    getch();
}

int test()
{
    int rand_num;
    char randomized_words[4000]="";
    char entered_words[1024]={};
    int user_set_time,time_option;

    char words[MAX_WORDS][MAX_WORD_LENGTH]; //take data from the file word.txt
    FILE *fptr = fopen("words.txt","r");
    int i=0,word_count;
    while(fscanf(fptr,"%s",words[i])!=EOF) // till end of file
    {
        i++;
    }
    word_count=i; // kati ota word cha count garchaa line line cha soo accurate so 20 auuncha
    retry:
    system("cls");
    printf("\033[35m"); //purple color
    printf("/////////////////////////////////////////////////////");
    printf("\033[36m"); //cyan
    printf("TIME");
    printf("\033[35m"); //purple color
    printf("/////////////////////////////////////////////////////");
    printf("\033[36m"); //cyan
    printf("\n\t\t\t\t\t\t1.");
    printf("\033[35m"); //purple color
    printf(" 15sec");
    printf("\033[36m"); //cyan
    printf("\n\t\t\t\t\t\t2.");
    printf("\033[35m"); //purple color
    printf(" 30sec");
    printf("\033[36m"); //cyan
    printf("\n\t\t\t\t\t\t3.");
    printf("\033[35m"); //purple color
    printf(" 60sec\n");
    printf("\033[36m"); //cyan
    scanf("%d",&time_option);
    printf("\033[0m"); //defualt color

    if(time_option==1)
    {
        user_set_time=15;
    }
    else if(time_option==2)
    {
        user_set_time=30;
    }
    else if(time_option==3)
    {
        user_set_time=60;
    }
    else
    {
        system("cls");
        printf("\033[35m"); //purple color
        printf("\n\t\t\t\tInvalid Input!");
        sleep(2);
        printf("\033[0m"); //defualt color
        goto retry;
    }
    tabbed:
    memset(randomized_words,0,strlen(randomized_words));
    memset(entered_words,0,strlen(entered_words));

    system("cls");
    printf("\033[0m"); //defualt color
    time_t t;
    srand((unsigned) time(&t));
    for (int i=0;i<150;i++)
    {
        int word_num=rand() % word_count; // yaha plus 1 na gareko reason chai rand le 20 lekhya ki 19 mancha so 0-19 =20
        strcat(randomized_words,words[word_num]);
        strcat(randomized_words," "); // kina ki file handling bela space auudaina raicha so to create space
    }

    system("cls");
    printf("\033[0m"); //defualt color
    int randomized_words_count= strlen(randomized_words);
    char randomized_words_without_space[4000]="";
    strcpy(randomized_words_without_space,randomized_words); //kina ki last ma auuta space hunthiyo to remove that arko variable ma last ko value - garyara save garyako 
    printf("\033[36m"); //cyan
    printf("%s\n", randomized_words_without_space);
    
    space:
    printf("\033[35m"); //purple color
    printf("\n\n\t\t\t\tTo regenerate or restart the words press Tab");
    printf("\n\n\t\t\t\tType the first character to start:\n");
    printf("\033[36m"); //cyan
    char first_character=getche();
    entered_words[0]=first_character;
    char first_character_random=randomized_words_without_space[0];
    if(first_character=='\t')
    {
        goto tabbed;
    }
    else if(entered_words[0]!=first_character_random)
    {
        system("cls");
        printf("\033[36m"); //cyan
        printf("%s\n",randomized_words_without_space);
        goto space;
    }
    fflush(stdin);
    time_t user_time_start = time(NULL);
    time_t user_current_time =user_time_start;//start timer
    printf("\033[0m"); //defualt color

    float acc_typed_char=1;
    char input;
    int wrong_input=0;
    for (int i=1;i<strlen(randomized_words_without_space);)
    {
        backspace:
        input=getch();
        if (input =='\b')
        {
            if(i>=1)
            {
                i--;
                entered_words[i] = '\0';
                printf("\033[0m");
                printf("\b");
                printf(" ");
                printf("\b");
            }
            goto backspace;
        }
        else if(input=='\t')
        {
            goto tabbed;
        }
        else //remove gardaa output ma ni remove hos
        {
            acc_typed_char=acc_typed_char+1; //backspace in count garrnaa lahi naya varaible leko yeta
            entered_words[i]=input; //remove garna parcha backspace ma index awrnusar
            if(entered_words[i]!=randomized_words_without_space[i]) //wrong input auuda color change hunchaaa
            {
                
                printf("\033[1;31m");// red color code
                printf("\e[4;31m"); //underline red text
                printf("%c",input);
            }
            else    //right input auuda color changes back to normal
            {
                printf("\033[0m");
                printf("\033[36m"); //cyan
                printf("%c",input);
            }
            i++;
        }
       
        if((user_current_time-user_time_start)>=user_set_time)
        {
            break;
        }
        user_current_time=time(NULL);
    }
    /*char randomized_words_not_array[200]={};
    for (int i=0;i<strlen(randomized_words_without_space);i++)
    {
        randomized_words_not_array[i]=randomized_words_without_space;
    }
    printf("%s", randomized_words_not_array);*/
    printf("\033[0m"); //defualt color
    for (int i=0; i<strlen(entered_words);i++)
    {
        if(entered_words[i]!=randomized_words_without_space[i])
        {
            wrong_input=wrong_input+1;
        }
    }
    again:
    system("cls");
    float correct_typed_characters=strlen(entered_words)-wrong_input;
    int correct_typed_words=(strlen(entered_words)-wrong_input)/5; // calculating the number of words 
    int accuracy= (correct_typed_characters/acc_typed_char)*100;
    int wpm= (correct_typed_words*60)/user_set_time; //calculating the words per minute
    int typed_words=(strlen(entered_words)/5);
    int raw_wpm=(typed_words*60)/user_set_time;
    printf("\033[0m"); //defualt color
    printf("\033[35m"); //purple color
    printf("\n\n\t\t\t\tWPM:");
    printf("\033[36m"); //cyan
    printf("%d",wpm);
    printf("\033[35m"); //purple color
    printf("\n\n\t\t\t\tRaw WPM:");
    printf("\033[36m"); //cyan
    printf("%d",raw_wpm);
    printf("\033[35m"); //purple color
    printf("\n\n\t\t\t\tAccuracy:");
    printf("\033[36m"); //cyan
    printf("%d",accuracy);
    printf("\033[35m"); //purple color
    printf("\n\n\t\t\t\tPress TAB to restart");
    printf("\n\n\t\t\t\tPress '0' to exit");
    printf("\033[0m"); //defualt color
    input=getch();
    if(input=='\t')
    {
        FILE *fp;
        if(time_option==1)
        {
        fp=fopen("15s.txt","a");
        fprintf(fp,"\n%s %d",u[0].userName,wpm);
        fclose(fp);
        }
        else if(time_option==2)
        {
            fp=fopen("30s.txt","a");
            fprintf(fp,"\n%s %d",u[0].userName,wpm);
            fclose(fp);
        }
        else if(time_option==3)
        {
            fp=fopen("60s.txt","a");
            fprintf(fp,"\n%s %d",u[0].userName,wpm);
            fclose(fp);
        }
        goto tabbed;
    }
    else if(input=='0')
    {
        FILE *fp;
        if(time_option==1)
        {
        fp=fopen("15s.txt","a");
        fprintf(fp,"\n%s %d",u[0].userName,wpm);
        fclose(fp);
        }
        else if(time_option==2)
        {
            fp=fopen("30s.txt","a");
            fprintf(fp,"\n%s %d",u[0].userName,wpm);
            fclose(fp);
        }
        else if(time_option==3)
        {
            fp=fopen("60s.txt","a");
            fprintf(fp,"\n%s %d",u[0].userName,wpm);
            fclose(fp);
        }
        return 0;
    }
    else
    {
        goto again;
    }
}

int highscores()
{
    yaha:
    printf("\033[35m"); //purple color
    printf("/////////////////////////////////////////////////////");
    printf("\033[36m"); //cyan
    printf("TIME");
    printf("\033[35m"); //purple color
    printf("/////////////////////////////////////////////////////");
    printf("\033[36m"); //cyan
    printf("\n\t\t\t\t\t\t1.");
    printf("\033[35m"); //purple color
    printf(" 15sec");
    printf("\033[36m"); //cyan
    printf("\n\t\t\t\t\t\t2.");
    printf("\033[35m"); //purple color
    printf(" 30sec");
    printf("\033[36m"); //cyan
    printf("\n\t\t\t\t\t\t3.");
    printf("\033[35m"); //purple color
    printf(" 60sec\n");
    printf("\033[36m"); //cyan
    int option;
    scanf("\n\t\t\t\t\t%d",&option);
    printf("\033[0m"); //defualt color
    system("cls");

    if(option==1)
    {
        char highScore_userName[200];
        int user_wpm,ch;
        int count=0;
        FILE *fp;
        fp=fopen("15s.txt","r");

        while(fscanf(fp,"%s %d",highScore_userName,&user_wpm)!=EOF)
            {
                count=count+1;
            } 

        rewind(fp);

        struct highscore_user hs[count],a;
        
        count=0;
        while(fscanf(fp,"%s %d",hs[count].username,&hs[count].user_wpm)!=EOF)
        {
            count=count+1;
        }

        for (int i=0; i<count; i++) 
            {
                for (int j = i+1; j < count; j++)
                {
                    if (hs[i].user_wpm < hs[j].user_wpm) 
                    {
                        a =  hs[i];
                        hs[i] = hs[j];
                        hs[j] = a;
                    }       
                }
            }
        printf("\033[35m"); //purple color
        printf("\n\t\t\t\tUsername");
        printf("\033[36m"); //cyan
        printf("\t\tWPM");
        for(int i=0;i<count;i++)
        {
            printf("\033[35m"); //purple color
            printf("\n\t\t\t\t%s",hs[i].username);
            printf("\033[36m"); //cyan
            printf("\t\t\t%d\n",hs[i].user_wpm);
        }
        fclose(fp);
        printf("\033[0m"); //defualt color
    }
    else if(option==2)
    {
        char highScore_userName[200];
        int user_wpm,ch;
        int count=0;
        FILE *fp;
        fp=fopen("30s.txt","r");

        while(fscanf(fp,"%s %d",highScore_userName,&user_wpm)!=EOF)
            {
                count=count+1;
            } 

        rewind(fp);

        struct highscore_user hs[count],a;
        
        count=0;
        while(fscanf(fp,"%s %d",hs[count].username,&hs[count].user_wpm)!=EOF)
        {
            count=count+1;
        }

        for (int i=0; i<count; i++) 
                {
        
                    for (int j = i+1; j < count; j++)
                    {
        
                        if (hs[i].user_wpm < hs[j].user_wpm) 
                        {
                            a =  hs[i];
                            hs[i] = hs[j];
                            hs[j] = a;
                        }
        
                    }
        
                }
        printf("\033[35m"); //purple color
        printf("\n\t\t\t\tUsername");
        printf("\033[36m"); //cyan
        printf("\t\tWPM");
        for(int i=0;i<count;i++)
        {
            printf("\033[35m"); //purple color
            printf("\n\t\t\t\t%s",hs[i].username);
            printf("\033[36m"); //cyan
            printf("\t\t\t%d\n",hs[i].user_wpm);
        }
        fclose(fp);
        printf("\033[0m"); //defualt color
    }
    else if(option==3)
    {
        char highScore_userName[200];
        int user_wpm,ch;
        int count=0;
        FILE *fp;
        fp=fopen("60s.txt","r");

        while(fscanf(fp,"%s %d",highScore_userName,&user_wpm)!=EOF)
            {
                count=count+1;
            } 

        rewind(fp);

        struct highscore_user hs[count],a;
        
        count=0;
        while(fscanf(fp,"%s %d",hs[count].username,&hs[count].user_wpm)!=EOF)
        {
            count=count+1;
        }

        for (int i=0; i<count; i++) 
                {
        
                    for (int j = i+1; j < count; j++)
                    {
        
                        if (hs[i].user_wpm < hs[j].user_wpm) 
                        {
        
                            a =  hs[i];
                            hs[i] = hs[j];
                            hs[j] = a;
                        }
        
                    }
        
                }
        printf("\033[35m"); //purple color
        printf("\n\t\t\t\tUsername");
        printf("\033[36m"); //cyan
        printf("\t\tWPM");
        for(int i=0;i<count;i++)
        {
            printf("\033[35m"); //purple color
            printf("\n\t\t\t\t%s",hs[i].username);
            printf("\033[36m"); //cyan
            printf("\t\t\t%d\n",hs[i].user_wpm);
        }
        fclose(fp);
        printf("\033[0m"); //defualt color
    }
    else
    {
        int a=0;
        const int trigger = 500; // ms
        const int numDots = 4;
        const char prompt[] = "Invalid Option";
        while (a<1) 
        {
        // Return and clear with spaces, then return and print prompt.
            a=a+1;
            printf("\r%*s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
            fflush(stdout);

            // Print numDots number of dots, one every trigger milliseconds.
            for (int i = 0; i < numDots; i++) 
            {
                usleep(trigger * 1000);
                fputc('.', stdout);
                fflush(stdout);
            }
        }
        system("cls");
        goto yaha;
    }
    getch();
}

int main()
{
    int user_selection;
    int new_account;
    repeat:
    user_selection=login_page();
    printf("\033[0m"); //defualt color
    system("cls");
    if(user_selection==1)
    {
        new_account=login();
        printf("\033[0m"); //defualt color
    }
    else if(user_selection==2)
    {
        create();
        printf("\033[0m"); //defualt color
    }
    else
    {
        int a=0;
        const int trigger = 500; // ms
        const int numDots = 4;
        const char prompt[] = "Invalid Option";
        while (a<1) 
        {
        // Return and clear with spaces, then return and print prompt.
            a=a+1;
            printf("\r%*s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
            fflush(stdout);

            // Print numDots number of dots, one every trigger milliseconds.
            for (int i = 0; i < numDots; i++) 
            {
                usleep(trigger * 1000);
                fputc('.', stdout);
                fflush(stdout);
            }
            
        }
        system("cls");
        goto repeat;
    }
    if(new_account==1)
    {
        goto repeat;
    }
    int home_screen_option; //returns the option from the home screen  
    //int lvl_diff_num;

    check:
    home_screen_option=home_screen();
    printf("\033[0m"); //defualt color
    if (home_screen_option==1)// option: start
    {
        test();
        printf("\033[0m"); //defualt color
    }
    else if (home_screen_option==2)// option : highscores
    {
        highscores();
        printf("\033[0m"); //defualt color
    }
    else if (home_screen_option==3)// Help
    {
        help();
        printf("\033[0m"); //defualt color
    }
    else if (home_screen_option==4)// Exit
    {
        exit(0);
    }
    else //Invalid option
    {
        int a=0;
        const int trigger = 500; // ms
        const int numDots = 4;
        const char prompt[] = "Invalid Option";
        while (a<1) 
        {
        // Return and clear with spaces, then return and print prompt.
            a=a+1;
            printf("\r%*s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
            fflush(stdout);

            // Print numDots number of dots, one every trigger milliseconds.
            for (int i = 0; i < numDots; i++) 
            {
                usleep(trigger * 1000);
                fputc('.', stdout);
                fflush(stdout);
            }
            
        }
        system("cls");
        home_screen_option=home_screen(); // otherwise the value of home_screen_option would be the same always
        printf("\033[0m"); //defualt color
        goto check; //to check the condition again
    }
    system("cls");
    goto check;
}