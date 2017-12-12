///Following project is about how different mobile phone applications use data structure
///Different header files are made to add ease for debugging and more efficient handling. All the header files are meant to
///be saved in the same folder as the main file
///Data structures used are : Arrays, Linked Lists, Stacks, Queues, Graphs, Hash Tables and Tries

///Including all the self-coded header file for data structures and functions
#include <iostream>
#include <stdio.h>
#include "Graph.h"
#include "Hash_Table_Contact.h"
#include "Infix_To_Postfix.h"
#include "Evaluate_Postfix.h"
#include "Trie.h"
#include "Word_Trie.h"
#include "Edit_Distance.h"
#include "Box.h"
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <windows.h>
using namespace std;

///To create a friendly user-interface date, month, year and mobile phone name are displayed on every console log
int d,m,y;
char mname[100];

///display() function is called every time a new console log screen is shown
void display()
{
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
      WORD wOldColorAttrs;
      CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

      /*
       * First save the current color information
       */
      GetConsoleScreenBufferInfo(h, &csbiInfo);
      wOldColorAttrs = csbiInfo.wAttributes;

      /*
       * Set the new color information
       */
      SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );
      printf("\n%45s\n",mname);

      SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
      printf("%80d/%d/%d\n\n\n",d,m,y);

      /*
       * Restore the original colors
       */
      SetConsoleTextAttribute ( h, wOldColorAttrs);
    return;
}

///printMap() function print the adjacency list showing which cities are connected
void printMap(Graph &map)
{
    display();

    ///checking is map is made or not
    if(map.empty())
    {
        cout << "Map not made!!";
        return;
    }
    cout << "           Map\n\n";

    ///printAdjList() function is called to print the map
    map.printAdjList();
    return;
}

///printCities() function print the list of all the cities present on the map
///2D character array stores names of all the cities
void printCities(char s[][1000], int z)
{
    if(z!=1) display();

    ///checking is map is made or not
    if(s[0][0]=='\0')
    {
        cout << "Map not made!!";
        return;
    }
    cout << "           Cities On Map\n\n";
    for(int i=0; s[i][0]!='\0'; i++)
    {
        cout << i+1 << ". " << s[i] << endl;
    }
    return;
}

///makeMap() function is used to make a map of user's choice
///it allows to enter the cities name and the roads connecting them
///map is passed to this function by reference so that changes take place to the actual map
void makeMap(Graph &map, char s[][1000])
{
    display();
    cout << "           Map Maker\n\n";

    ///taking the number of roads connecting the cities
    cout << "Enter Number of roads : ";
    int v;
    cin >> v;

    ///taking the number of cities of map
    ///these will be the number of vertices of the graph used
    cout << "\nEnter no. of cities   : ";
    int a;
    cin >> a;

    map.insertVertices(a);
    cout << "\nEnter cities name     : ";
    ///taking the name of all the cities
    int i;
    for(i=0; i<a; i++)
    {
        cin >> s[i];
        map.adjList[i].insertAtEnd(s[i],i);
    }
    s[i][0]='\0';
    cout << endl;

    printCities(s, 1);
    cout << endl;

    ///taking the roads connecting the cities to make the connections
    int x,y;
    for(int i=0; i<v; i++)
    {
        cout << "Enter edges : ";
        cin >> x >> y;
        map.add_Edge(x-1, s[x-1], y-1, s[y-1]);
    }
    return;
}

///shortestPath() function is used to find the best route possible between two cities
///Breadth First Search algorithm is used to do so
void shortestPath(Graph &map, char s[][1000])
{
    display();

    ///checking is map is made or not
    if(map.empty())
    {
        cout << "Map not made!!";
        return;
    }

    cout << "           Find Route\n\n";

    ///displaying the list of cities available on map and the roads connecting them
    printCities(s,1);
    cout << endl;
    map.printAdjList();
    cout << endl;

    ///using Breadth First Search algorithm
    int a, b;
    cout << "Enter source and destination : ";
    cin >> a >> b;
    cout << endl;
    map.BFS(a-1,b-1);
    cout << endl;
    return;
}

///mapApp() is the user interface proving different things a user can do via this app
void mapApp(Graph &map, char s[][1000])
{
    int choice;
    while(1)
    {
        display();
        cout << "               MAP\n\n";
        cout << "1. Make MAP\n";
        cout << "2. Print Cities\n";
        cout << "3. Print Map\n";
        cout << "4. Find Shortest Path\n\n";
        cout << "5. Exit\n\n";
        cout << "Enter choice : ";
        cin >> choice;

        system("cls");
        switch (choice)
        {
            case 1: makeMap(map, s);
            break;
            case 2: printCities(s, 0);
            break;
            case 3: printMap(map);
            break;
            case 4: shortestPath(map, s);
            break;
            case 5: return;
            break;
            default : cout << "Wrong Input\n";
                      system("cls");
                      continue;
        }
        cout << endl << endl;
        cout << "Press enter to continue";
        cin.get();
        cin.get();
        system("cls");
    }
    return;
}

///insertContact() function is used to insert a contact's info to the hash table
void insertContact(hashTableContact &contact, Trie &t)
{
    display();
    cout << "           Insert Contact's Info\n\n";
    char name[1000];
    char phone[1000];
    char email_id[1000];

    ///getting contact's info
    cout << "Name               :   ";
    cin >> name;
    cout << "Phone (10 digits)  :   ";
    cin >> phone;
    while(strlen(phone)!=10)
    {
        cout << "Invalid phone number!\n\n";
        cout << "Phone (10 digits)  :   ";
        cin >> phone;
    }
    cout << "Email ID           :   ";
    while(1)
    {
        cin >> email_id;
        int atTheRate=0, dot=0;
        for(int i=0; email_id[i]!='\0'; i++) if(email_id[i]=='@') atTheRate++;
        if(atTheRate!=1)
        {
            cout << "\n@ symbol not found!\n\n";
            cout << "Email ID           :   ";
        }
        else break;
    }

    ///inserting it in hash table
    contact.insert(name, phone, email_id);

    ///inserting it in trie
    t.addNum(phone, name);
    return;
}

///removeContact() function is used to remove a contact from the hash table
void removeContact(hashTableContact &contact)
{
    display();
    cout << "           Remove Contact\n";

    ///displaying the available contact list
    contact.printNames();

    cout << "\nWhich contact do you want to remove? : ";
    char str[1000];
    cin >> str;
    contact.remove(str);
    return;
}

///contactApp() is the user interface proving different things a user can do via this app
void contactApp(hashTableContact &contact, Trie &t)
{
    int choice;
    while(1)
    {
        display();
        cout << "1. Insert Contact\n";
        cout << "2. Remove Contact\n";
        cout << "3. See Contacts\n\n";
        cout << "4. Exit\n\n";
        cout << "Enter choice : ";
        cin >> choice;

        system("cls");
        switch (choice)
        {
            case 1: insertContact(contact, t);
            break;
            case 2: removeContact(contact);
            break;
            case 3: display();
                    contact.printNames();
            break;
            case 4: return;
            break;
            default:  cout << "Wrong Input\n";
                      system("cls");
                      continue;
        }
        cout << endl << endl;
        cout << "Press enter to continue";
        cin.get();
        cin.get();
        system("cls");
    }
    return;
}

///trueCallerApp() is the user interface proving different things a user can do via this app
void trueCallerApp(hashTableContact &contact, Trie &t)
{
    display();
    cout << "               TRUECALLER 2.7\n\n";
    char ch[20];
    char choice;
    choice = 'y';
    while(choice!='n')
    {
        cout << "Enter mobile no.        : ";
        cin >> ch;
        cout << endl;

        ///finding the contact through the trie made
        t.findNum(ch, contact);
        cout << "\nAnother Number (y/n)  : ";
        cin >> choice;
        cout << "\n=====================================================================" << endl << endl;
    }
    cout << "Press enter to continue";
    cin.get();
    system("cls");
}

///calculatorApp() is the user interface proving different things a user can do via this app
void calculatorApp()
{
    display();
    cout << "               CALCULATOR\n\n";
    char choice;
    choice = 'y';
    while(choice!='n')
    {
        ///gettin the infix expression and converting it to postfix expression
        char inFix[100];
        cout << "In Fix Expression          : ";
        cin.get();
        cin.getline(inFix,100);
        inFix[strlen(inFix)]=')';
        inFix[strlen(inFix)+1]='\0';

        ///evaluating the postfix expressiong
        char postFix[100];
        convertToPostFix(inFix, postFix);

        cout << "\nResult                     : " << evaluatePostFix(postFix) << endl;
        cout << "\nAnother Calculation (y/n)  : ";
        cin >> choice;
        cout << "\n=====================================================================" << endl << endl;
    }
    return;
}

///didYouMean() is the user interface proving different things a user can do via this app
void didYouMean(WordTrie &wt)
{
    system("cls");
    display();

    ///getting the text in a 2D character array
    cout << "Enter text : \n\n";
    int i=0,j=0;
    char text[1000][1000];
    char ch;
    cin.get();
    cin.get(ch);
    while(ch!='\n')
    {
        if(ch==' ' && j!=0)
        {
            text[i][j]='\0';
            j=0;
            i++;
        }
        else
        {
            text[i][j]=ch;
            j++;
        }
        cin.get(ch);
    }

    cout << endl << endl << "Did You Mean?\n\n";
    for(int k=0; k<=i; k++)
    {
        ///if the word doesn't exist in trie
        if(wt.findWord(text[k])==false)
        {
            ///opening the file and storing the string of a line in word character array
            ifstream g;
            g.open("words.txt",ios::in|ios::out);
            char word[50];

            ///m is the maximum edit distance
            ///slash is count of slash inserted between the different suggestions of that word
            ///index is the index of the pointer of the array in which suggestions are to be stored
            int m=50, slash=0, index=0, flag=0;
            char temp[150];
            char c=text[k][strlen(text[k])-1];
            char t[200];
            strcpy(t,text[k]);

            ///if word has different characters at last then they are removed and inserted as it is later
            if(!((c>=65 && c<=90)||(c>=95 && c<=122)))
            {
                t[strlen(t)-1] = '\0';
                flag=1;
            }

            if(wt.findWord(t)==true)
            {
                cout << text[k] << " ";
                break;
            }

            ///comparing the wrong word with all words in the file
            while(1)
            {
                if(slash==3) break;

                g.getline(word,50);
                if(strcmp(word,"$")==0) break;

                ///finding edit distance with words having same string length
                if(strlen(word)!=strlen(t)) continue;

                ///finding the edit distance
                int e = editDistance(t, word, strlen(t), strlen(word));
                if(m>e) m=e;

                ///storing the suggestion in the character array
                if(e==1)
                {
                    if(slash!=0)
                    {
                        temp[index]='/';
                        index++;
                    }
                    for(int i=0; word[i]!='\0'; i++)
                    {
                        temp[index]=word[i]-32;
                        index++;
                    }
                    slash++;
                }
                g.ignore(unsigned(-1), '\n');
            }
            if(flag==1)
            {
                temp[index]=c;
                index++;
            }
            temp[index]='\0';
            HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
              WORD wOldColorAttrs;
              CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

              /*
               * First save the current color information
               */
              GetConsoleScreenBufferInfo(h, &csbiInfo);
              wOldColorAttrs = csbiInfo.wAttributes;

              /*
               * Set the new color information
               */
              SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
              cout << temp << " ";

              /*
               * Restore the original colors
               */
              SetConsoleTextAttribute ( h, wOldColorAttrs);
            g.close();
        }

        ///if the word exit in the trie
        else cout << text[k] << " ";
    }
    cout << endl << endl;
    return;
}

///changePassword() function is used to change the password of the mobile phone
void changePassword(char *read)
{
    char oldPass[33];
    char newPass[33];

    display();
    cout << "Enter old password : ";
    cin.get();
    cin.getline(oldPass,33);
    cout << "Enter new password : ";
    cin.getline(newPass,33);

    ///checking if the data is valid or not
    while(strcmp(oldPass,read)!=0 && strlen(newPass)<=32)
    {
        system("cls");
        display();
        cout << "Enter old password : ";
        cin.getline(oldPass,33);
        cout << "Enter new password : ";
        cin.getline(newPass,33);
    }

    ///creating a new password file with different name
    ///deleting the original password file
    ///renaming the new password file as original
    ofstream temp;
    temp.open("temp.txt");
    temp << newPass;
    temp.close();

    remove("password.txt");
    rename("temp.txt", "password.txt");
    strcpy(read,newPass);
    cout << "\nPassword changed successfully!";
    return;
}

///main() provides the user interface to access all the apps
int main()
{
    cout << "\n\n\n         Enter date          :   ";
    cin >> ::d;
    cout << "         Enter month         :   ";
    cin >> ::m;
    cout << "         Enter year          :   ";
    cin >> ::y;
    cout << "\n         Enter mobile name   :   ";
    cin.get();
    cin.getline(mname,1000);
    system("cls");

    char pass[33]="";
    char read[33];
    ifstream f;
    f.open("password.txt",ios::in|ios::out);
    f.getline(read,33);
    f.close();

    while(strcmp(pass,read)!=0)
    {
        display();
        cout << "Enter password : ";
        cin.getline(pass,33);
        system("cls");
    }

    ///inserting all the english words in the trie
    WordTrie wt;
    ifstream g;
    g.open("words.txt",ios::in|ios::out);
    char word[50];
    while(1)
    {
        g.getline(word,50);
        if(strcmp(word,"$")==0) break;
        wt.addWord(word);
        g.ignore(unsigned(-1), '\n');
    }
    g.close();

    ///making the hash table and the graph of map
    hashTableContact contact;
    Graph map;
    Trie t;
    char s[1000][1000];
    s[0][0]='\0';

    int choice;
    while(1)
    {
        display();
        cout << "1. Map\n";
        cout << "2. Contact\n";
        cout << "3. Truecaller 2.7\n";
        cout << "4. Calculator\n";
        cout << "5. Did You Mean\n";
        cout << "6. Change Password\n\n";
        cout << "7. Exit\n\n";
        cout << "Enter choice : ";
        cin >> choice;

        system("cls");
        switch (choice)
        {
            case 1: mapApp(map, s);
            break;
            case 2: contactApp(contact, t);
            break;
            case 3: trueCallerApp(contact, t);
            break;
            case 4: calculatorApp();
            break;
            case 5: didYouMean(wt);
            break;
            case 6: changePassword(read);
            break;
            case 7: system("cls");
                     printBox();
                     return 0;
            break;
            default : cout << "Wrong Input\n";
                      system("cls");
                      continue;
        }
        cout << endl << endl;
        cout << "Press enter to continue";
        cin.get();
        cin.get();
        system("cls");
    }
    return 0;
}
