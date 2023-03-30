#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

// --------------------------------main functions------------------------
void printHeader();
void menu();
void options();
void keys();
void Instructions();
void printMaze();
void gamerunning();

// ---------------------------------Jack Functions---------------------------
void printJack(int, int);
void erazeJack(int x, int y);
void bulletInactive(int index);
void generateBullet(int, int);
void eraseBullet(int x, int y);
void moveBullet();
void printBullet(int, int);
void bulletCollisionWithJack();
void bulletCollisionOfGladosWithJack();
void bulletCollisionOfFreshWithJack();
void bulletCollisionOfBusterWithJack();
void printJackHealth();
void eraseJackHealth();

// ---------------------------------Fresh Functions---------------------------
void printFresh();
void moveFreshBullet();
void printFreshBullet(int x, int y);
void eraseFreshBullet(int x, int y);
void makeFreshBulletInactive(int index);
void generateFreshBullet();
void bulletCollisionWithFresh();
void printFreshHealth();
void eraseFreshHealth();
void moveFresh();

// ---------------------------------Glados Functions---------------------------
void printGlados();
void moveGladosBullet();
void printGladosBullet(int x, int y);
void eraseGladosBullet(int x, int y);
void makeGladosBulletInactive(int index);
void generateGladosBullet();
void bulletCollisionWithGlados();
void moveGlados();
void printGladosHealth();
void eraseGladosHealth();
void eraseGlados();

// ---------------------------------Buster Functions---------------------------
void printBuster();
void moveBusterBullet();
void printBusterBullet(int x, int y);
void eraseBusterBullet(int x, int y);
void makeBusterBulletInactive(int index);
void generateBusterBullet();
void bulletCollisionWithBuster();
void moveBuster();
void printBusterHealth();
void eraseBusterHealth();
void eraseBuster();

// ---------------------------------Yutani Functions---------------------------
void moveYutani();
void printYutani();
void yutaniJackCollision();

// ---------------------------------Scoring Functions---------------------------
void addScore();
void printScore();

// ---------------------------------File Handling Functions---------------------------
void storeCoordinates();
void storeHealth();
void storeBulletCount();
void readCoordinates();
void readHealth();
void readBulletCount();

// ---------------------------------Level-2 Functions---------------------------
void level2();
void bulletCollisionOfGladosWithGrid();
char resumeMenu();
void resetCoordinates();
char getCharAtxy(short int, short int);
void gotoxy(int, int);



char bigbox = 219;
char smallbox = 220;
char upbox = 223;
char top = 30;

char fresh[4][6] = {{' ', ' ', ' ', '-', '-', '-'},
                    {'<', '=', '=', '(', '0', ')'},
                    {' ', ' ', ' ', '\\', '@', '/'},
                    {' ', ' ', ' ', '*', '*', '*'}};
char jack[3][3] = {{' ', top, ' '},
                   {smallbox, bigbox, smallbox},
                   {' ', upbox, ' '}};

char yutani[4][6] = {{' ', ' ', ' ', '^', '^', '^'},
                     {'<', '=', '=', '(', '$', ')'},
                     {' ', ' ', ' ', '\\', '%', '/'},
                     {' ', ' ', ' ', '*', '*', '*'}};

char glados[4][5] = {{'(', '-', ' ', '-', ')'},
                     {'<', '|', ' ', '|', '>'},
                     {' ', '\\', '_', '/', ' '},
                     {' ', ' ', '.', ' ', ' '}};

char buster[3][5] = {{'&', '&', '&', '&', '&'},
                     {'&', '&', '&', '&', '&'},
                     {' ', ' ', '+', ' ', ' '}};

int bulletX[100];
int bulletY[100];
bool isBulletActive[100];

int bulletCount = 0;
int freshBulletCount = 0;
int gladosBulletCount = 0;
int busterBulletCount = 0;
int timer = 5;
bool flag = false;
int timer1 = 5;
int deadCount = 0;
int score = 0;
int scoreG = 0;
string direction;
int deadCount1 = 0;
int deadCount2 = 0;
char atrate = '@';
char bull = 17;



int jackx = 60;
int jacky = 28;
int freshX = 100;
int freshY = 28;
float yutaniX = 40;
float yutaniY = 7;
int gladosX = 20;
int gladosY = 6;
int busterX = 7;
int busterY = 3;

int freshHealth = 100;
int jackHealth = 1000;
int gladosHealth = 100;
int busterHealth = 300;
string freshDirection = "Up";
string gladosDirection = "Right";
string busterDirection = "Right";

int freshBulletX[1000];
int freshBulletY[1000];
int busterBulletX[10000];
int busterBulletY[10000];
int gladosBulletX[10000];
int gladosBulletY[10000];
bool isFreshBulletActive[1000];
bool isGladosBulletActive[10000];
bool isBusterBulletActive[10000];

// ----------------------------------------GRID -------------------------------------------
string maze[34][1] = {
    {"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"},
    {"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"},
    {"@@                                                                                                                            @@"},
    {"@@                                                                                                                            @@"},
    {"@@                                                                                                                            @@"},
    {"@@                                                                                                                            @@"},
    {"@@         @@                                                                                                                 @@"},
    {"@@         @@                                                         @@                              @@@@@@@@@@@@            @@"},
    {"@@         @@                                                         @@                                                      @@"},
    {"@@         @@                                        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                                     @@"},
    {"@@         @@                                                         @@                                                      @@"},
    {"@@         @@                                                         @@                                                      @@"},
    {"@@                                                                                                                            @@"},
    {"@@                                                                                                                            @@"},
    {"@@                                                                                                                            @@"},
    {"@@                      @@@@@@@@@@@@@@@@@@@@@                                                                                 @@"},
    {"@@                                         @@                                                                                 @@"},
    {"@@                                         @@                                                                                 @@"},
    {"@@                                         @@                                                                                 @@"},
    {"@@                                         @@                                                                                 @@"},
    {"@@                                         @@                                                  @@                             @@"},
    {"@@                                                                                             @@                             @@"},
    {"@@        @@                                                                                   @@                             @@"},
    {"@@        @@                                                                                   @@                             @@"},
    {"@@        @@                                                  @@@@@@@@@@@@@@@@@@@@             @@                             @@"},
    {"@@        @@                                                                                   @@                             @@"},
    {"@@        @@                                                                                   @@                             @@"},
    {"@@        @@@@@@@@@@@@@@@@@@@@@@@@                                                                                            @@"},
    {"@@                                                                                                                            @@"},
    {"@@                                                                                                                            @@"},
    {"@@                                                                                                                            @@"},
    {"@@                                                                                                                            @@"},
    {"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"},
    {"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"}};

// --------------------------------------- MAIN -------------------------------------------
main()
{
    char option;
    bool isRunning = true;

    while (isRunning = true)
    {
        readBulletCount();
        system("cls");
        printHeader();
        if (bulletCount == 0)
        {
            menu();
            cout << "Enter the Option number : ";
            cin >> option;
            if (option == '1')
            {
                resetCoordinates();
                gamerunning(); // all operations of game are performed in this function.
            }
            else if (option == '2')
            {
                int number;
                while (number != 3)
                {
                    system("cls");
                    printHeader();
                    options();
                    cout << "Enter the option number : ";
                    cin >> number;
                    if (number == 1)
                    {
                        system("cls");
                        printHeader();
                        keys(); // Show the controler keys of the game.
                    }
                    else if (number == 2)
                    {
                        system("cls");
                        printHeader();
                        Instructions(); // provide the instructions regarding game.
                    }
                    else if (number == 3)
                    {
                        break;
                    }
                }
            }
            else if (option == '3')
            {
                isRunning = false;
            }
        }
        else
        {
            option = resumeMenu(); // resume game will start game from the point where it had been left.
            if (option == '1')
            {
                readCoordinates();
                readHealth();
                gamerunning();
            }
            else if (option == '2')
            {
                resetCoordinates(); // itwill reset the coordinates and will start a new game.
                gamerunning();
            }
            else if (option == '3')
            {
                bool isRunning = true;
                while (isRunning = true)
                {
                    system("cls");
                    printHeader();
                    int number;
                    options();
                    cout << "Enter the option number : ";
                    cin >> number;
                    if (number == 1)
                    {
                        system("cls");
                        printHeader();
                        keys();
                    }
                    else if (number == 2)
                    {
                        system("cls");
                        printHeader();
                        Instructions();
                    }
                    else if (number == 3)
                    {
                        break;
                    }
                }
            }
            else if (option == '4')
            {
                break;
            }
        }
    }
}

//---------------------------------------FUNCTIONS----------------------------------------- 

void printHeader() //
{
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@                                                                                                              @@" << endl;
    cout << "@@ ####### ##    ## ######  ##     ##  #####  ##    ##     ######  ##    ## ###    ## ###    ## ####### ######  @@" << endl;
    cout << "@@ ##      ##    ## ##   ## ##     ## ##   ##  ##  ##      ##  ##  ##    ## ####   ## ####   ## ##      ##  ##  @@" << endl;
    cout << "@@ ####### ##    ## ######  ##  #  ## #######   ####       ######  ##    ## ## ##  ## ## ##  ## #####   ######  @@" << endl;
    cout << "@@      ## ##    ## ##   ## ## ### ## ##   ##    ##        ## ##   ##    ## ##  ## ## ##  ## ## ##      ## ##   @@" << endl;
    cout << "@@ #######  ######  ######   ### ###  ##   ##    ##        ##   ##  ######  ##   #### ##   #### ####### ##   ## @@" << endl;
    cout << "@@                                                                                                              @@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
}

// it will print menu of the game.
void menu()
{
    cout << "   Menu" << endl;
    cout << "____________________" << endl;
    cout << "  " << endl;
    cout << "1. Start." << endl;
    cout << "2. Options." << endl;
    cout << "3. Exit." << endl;
}

// it will provide the options to user.
void options()
{

    cout << "  " << endl;
    cout << "1. Keys." << endl;
    cout << "2. Instructions." << endl;
    cout << "3. Exit." << endl;
}

// it give information regarding the keys used in game.
void keys()
{
    cout << "   Keys" << endl;
    cout << "____________________" << endl;
    cout << "  " << endl;
    cout << "1. Up                Go Up." << endl;
    cout << "2. Down              Go Down." << endl;
    cout << "3. Right             Go Right." << endl;
    cout << "1. Left              Go Left." << endl;
    cout << "2. Space             Fire." << endl;
    cout << "3. Esc               Resume." << endl;
    cout << "Press any key to continue:" << endl;
    getch();
}

// it will give important instructions about the game.
void Instructions()
{
    cout << "Player can collect the coins and its score increases." << endl;
    cout << "Player can dough the hurdles. If player collide with " << endl;
    cout << "the hurdle he will die and if he collide with the bullets" << endl;
    cout << "fired by Frank and Glados , his power reduces slowly " << endl;
    cout << "and he will gradually die." << endl;
    getch();
}

// this function will print maze on the screen.
void printMaze()
{
    system("cls");
    for (int row = 0; row < 34; row++)
    {
        for (int col = 0; col < 1; col++)
        {
            cout << maze[row][0];
        }
        cout << endl;
    }
}

// ----------------------------- Jack Functions ------------------------------------

// it will print main charater jack on screen.
void printJack(int x, int y)
{
    for (int row = 0; row < 3; row++)
    {
        gotoxy(x, y + row);
        for (int col = 0; col < 3; col++)
        {
            cout << jack[row][col];
        }
    }
}

// this function will erase the jack.
void erazeJack(int x, int y)
{
    for (int row = 0; row < 3; row++)
    {
        gotoxy(x, y + row);
        for (int col = 0; col < 3; col++)
        {
            cout << " ";
        }
    }
}

// this function is used to detect bullet collision of Fresh with Jack.
void bulletCollisionOfFreshWithJack()
{

    for (int i = 0; i < freshBulletCount; i++)
    {
        if (isFreshBulletActive[i] == true)
        {
            char next;
            next = getCharAtxy(freshBulletX[i] - 1, freshBulletY[i]);
            if (next == bigbox || next == smallbox || next == upbox || next == top)
            {
                eraseJackHealth();
                jackHealth = jackHealth - 5;
            }
        }
    }
}

// this function is used to detect bullet collision of Glados with Jack.
void bulletCollisionOfGladosWithJack()
{

    for (int i = 0; i < gladosBulletCount; i++)
    {
        if (isGladosBulletActive[i] == true)
        {
            char next;
            next = getCharAtxy(gladosBulletX[i], gladosBulletY[i] + 1);
            if (next == bigbox || next == smallbox || next == upbox || next == top)
            {
                eraseJackHealth();
                jackHealth = jackHealth - 5;
                printJackHealth();
            }
        }
    }
}

// this function is used to print Jack health.
void printJackHealth()
{
    if (jackHealth >= 0)
    {
        gotoxy(134, 10);
        cout << "Jack Health: " << jackHealth << "  ";
    }
}

// this function is used to erase Jack health.
void eraseJackHealth()
{
    gotoxy(134, 10);
    cout << "                  ";
}

// this function is used to generate bullets of Jack.
void generateBullet(int gbullx, int gbully)
{
    if ((gbullx && gbully - 1) != '@')
    {
        bulletX[bulletCount] = gbullx;
        bulletY[bulletCount] = gbully - 1;
        isBulletActive[bulletCount] = true;
        gotoxy(gbullx, gbully - 1);
        cout << '.';
        bulletCount++;
    }
}

// This function is used to erase bullets of Jack
void eraseBullet(int x, int y)
{

    gotoxy(x, y);
    cout << " ";
}

// This function  is used to move bullets of Jack.
void moveBullet()
{
    for (int i = 0; i < bulletCount; i++)
    {
        if (isBulletActive[i] == true)
        {
            char nextLocation = getCharAtxy(bulletX[i], bulletY[i] - 1);
            if (nextLocation != ' ')
            {
                eraseBullet(bulletX[i], bulletY[i]);
                bulletInactive(i);
            }
            else
            {
                eraseBullet(bulletX[i], bulletY[i]);
                bulletY[i] = bulletY[i] - 1;
                printBullet(bulletX[i], bulletY[i]);
            }
        }
    }
}

// this function is used to print bullets of Jack.
void printBullet(int bulletX, int bulletY)
{
    gotoxy(bulletX, bulletY);
    cout << ".";
}

// this function is used to make bullets of Jack inactive to remove it from screen.
void bulletInactive(int index)
{
    isBulletActive[index] = false;
}

// this function is used to detect collision of busetr bullet with jack.
void bulletCollisionOfBusterWithJack()
{

    for (int i = 0; i < busterBulletCount; i++)
    {
        if (isBusterBulletActive[i] == true)
        {
            char next;
            next = getCharAtxy(busterBulletX[i], busterBulletY[i] + 1);
            if (next == bigbox || next == smallbox || next == upbox || next == top)
            {
                eraseJackHealth();
                jackHealth = jackHealth - 5;
                printJackHealth();
            }
        }
    }
}
// ----------------------------------Jack Functions End--------------------------------

// ----------------------------------Fresh Functions ----------------------------------
// this function will print the enemy named as fresh .
void printFresh()
{
    for (int row = 0; row < 4; row++)
    {
        gotoxy(freshX, freshY + row);
        for (int col = 0; col < 6; col++)
        {
            cout << fresh[row][col];
        }
    }
}

// this function will erase the enemy Fresh.
void eraseFresh()
{
    for (int row = 0; row < 4; row++)
    {
        gotoxy(freshX, freshY + row);
        for (int col = 0; col < 6; col++)
        {
            cout << " ";
        }
    }
}

// this function is used to move fresh up and down vertically.
void moveFresh()
{
    if (freshDirection == "Up")
    {
        char next = getCharAtxy(freshX, freshY - 1);
        if (next == ' ' || next == '.')
        {
            eraseFresh();
            freshY--;
            printFresh();
            generateFreshBullet();
        }
        else if (next == '@')
        {
            freshDirection = "Down";
        }
    }

    if (freshDirection == "Down")
    {
        char next = getCharAtxy(freshX, freshY + 4);
        if (next == ' ' || next == '.')
        {
            eraseFresh();
            freshY++;
            printFresh();
            generateFreshBullet();
        }
        else if (next == '@')
        {
            freshDirection = "Up";
        }
    }
}

// this function is used to move the bullets of Fresh.
void moveFreshBullet()
{
    for (int i = 0; i < freshBulletCount; i++)
    {
        if (isFreshBulletActive[i] == true)
        {
            char next = getCharAtxy(freshBulletX[i] - 1, freshBulletY[i]);
            if (next != ' ')
            {
                eraseFreshBullet(freshBulletX[i], freshBulletY[i]);
                makeFreshBulletInactive(i);
            }
            else
            {
                eraseFreshBullet(freshBulletX[i], freshBulletY[i]);
                printFreshBullet(freshBulletX[i], freshBulletY[i]);
                freshBulletX[i]--;
            }
        }
    }
}

// this function is used to generate the bullets of Fresh.
void generateFreshBullet()
{
    freshBulletY[freshBulletCount] = freshY + 1;
    freshBulletX[freshBulletCount] = freshX - 7;
    isFreshBulletActive[freshBulletCount] = true;
    gotoxy(freshX - 7, freshY + 1);
    cout << "-";
    freshBulletCount++;
}

// this function is used to print the bullets of Fresh.
void printFreshBullet(int x, int y)
{
    gotoxy(x, y);
    cout << "-";
}

// this function is used to erase the bullets of Fresh.
void eraseFreshBullet(int x, int y)
{
    gotoxy(x, y);
    cout << "  ";
}

// this function is used to make the bullets of Fresh inactive in order to remove it from screen.
void makeFreshBulletInactive(int index)
{
    isFreshBulletActive[index] = false;
}

// this function is used to detect bullet collision with Fresh.
void bulletCollisionWithFresh()
{
    for (int i = 0; i < bulletCount; i++)
    {
        if (isBulletActive[i] == true)
        {
            if (bulletY[i] - 1 == freshY + 3 && (bulletX[i] == freshX || bulletX[i] == freshX + 1 || bulletX[i] == freshX + 2 || bulletX[i] == freshX + 3 || bulletX[i] == freshX + 4 || bulletX[i] == freshX + 5 || bulletX[i] == freshX + 6))
            {
                addScore();
                score++;
                eraseFreshHealth();
                freshHealth = freshHealth - 5;
            }
            if (freshY + 4 == bulletY[i] && freshX + 1 == bulletX[i])
            {
                addScore();
                score++;
                eraseFreshHealth();
                freshHealth = freshHealth - 5;
            }
        }
    }
}

// this function is used to print fresh health.
void printFreshHealth()
{
    if (freshHealth >= 0)
    {
        gotoxy(134, 15);
        cout << "Fresh Health: " << freshHealth << "   ";
    }
}

// this function is used to erase fresh health.
void eraseFreshHealth()
{
    gotoxy(134, 15);
    cout << "                        ";
}

// -------------------------------------Fresh Functions End -------------------------------------------

// -------------------------------------Glados Functions  ----------------------------------------------

// this function will print the enemy named as Glados.
void printGlados()
{
    for (int rows = 0; rows < 4; rows++)
    {
        gotoxy(gladosX, gladosY + rows);
        for (int col = 0; col < 5; col++)
        {
            cout << glados[rows][col];
        }
    }
}

// this function will erase the enemy Glados.
void eraseGlados()
{
    for (int rows = 0; rows < 4; rows++)
    {
        gotoxy(gladosX, gladosY + rows);
        for (int col = 0; col < 6; col++)
        {
            cout << " ";
        }
    }
}

// this function is used to move Glados left and right horizontally.
void moveGlados()
{
    if (gladosDirection == "Right")
    {
        char next = getCharAtxy(gladosX + 6, gladosY);
        if (next == ' ' || next == '.')
        {
            eraseGlados();
            gladosX++;
            printGlados();
            generateGladosBullet();
        }
        if (gladosX > 40)
        {
            gladosDirection = "Left";
        }
    }

    if (gladosDirection == "Left")
    {
        char next = getCharAtxy(gladosX - 1, gladosY);
        if (next == ' ' || next == '.')
        {
            eraseGlados();
            gladosX--;
            printGlados();
            generateGladosBullet();
        }
        else if (gladosX < 15)
        {
            gladosDirection = "Right";
        }
    }
}

// this function is used to move the bullets of Glados.
void moveGladosBullet()
{
    for (int i = 0; i < gladosBulletCount; i++)
    {
        if (isGladosBulletActive[i] == true)
        {
            char next = getCharAtxy(gladosBulletX[i] + 1, gladosBulletY[i] + 1);
            // char next1 = getCharAtxy(gladosBulletX[i] + 1, gladosBulletY[i]);
            if (next != ' ')
            {
                eraseGladosBullet(gladosBulletX[i], gladosBulletY[i]);
                makeGladosBulletInactive(i);
            }
            else
            {

                eraseGladosBullet(gladosBulletX[i], gladosBulletY[i]);
                gladosBulletY[i]++;
                printGladosBullet(gladosBulletX[i], gladosBulletY[i]);
            }
        }
    }
}

// this function is used to generate the bullets of Glados.
void generateGladosBullet()
{
    gladosBulletY[gladosBulletCount] = gladosY + 4;
    gladosBulletX[gladosBulletCount] = gladosX + 2;
    isGladosBulletActive[gladosBulletCount] = true;
    gotoxy(gladosX + 2, gladosY + 4);
    cout << " - " << endl;
    gladosBulletCount++;
}

// this function is used to print the bullets of Glados.
void printGladosBullet(int x, int y)
{
    gotoxy(x, y);
    cout << "-";
}

// this function is used to erase the bullets of Glados.
void eraseGladosBullet(int x, int y)
{
    gotoxy(x, y);
    cout << "  ";
}

// this function is used to make the bullets of Glados inactive in order to remove it from screen.
void makeGladosBulletInactive(int index)
{
    isGladosBulletActive[index] = false;
}

// this function is used to detect bullet collision with Glados.
void bulletCollisionWithGlados()
{
    for (int i = 0; i < bulletCount; i++)
    {
        if (isBulletActive[i] == true)
        {
            if (bulletY[i] - 1 == gladosY + 4 && (bulletX[i] == gladosX || bulletX[i] == gladosX + 1 || bulletX[i] == gladosX + 2 || bulletX[i] == gladosX + 3 || bulletX[i] == gladosX + 4 || bulletX[i] == gladosX + 5))
            {
                addScore();
                // score++;
                eraseGladosHealth();
                gladosHealth = gladosHealth - 5;
            }
            if (gladosY + 5 == bulletY[i] && gladosX + 1 == bulletX[i])
            {
                addScore();
                // score++;
                eraseGladosHealth();
                gladosHealth = gladosHealth - 5;
            }
        }
    }
}

// this function is used to detect bullet collision of Glados with grid.
void bulletCollisionOfGladosWithGrid()
{

    for (int i = 0; i < gladosBulletCount; i++)
    {
        if (isGladosBulletActive[i] == true)
        {
            char next;
            next = getCharAtxy(gladosBulletX[i], gladosBulletY[i] + 1);
            if (next == '@')
            {
                eraseGladosBullet(gladosBulletX[i], gladosBulletY[i]);
                makeGladosBulletInactive(i);
            }
        }
    }
}

// this function is used to print Glados health.
void printGladosHealth()
{
    if (gladosHealth >= 0)
    {
        gotoxy(134, 30);
        cout << "Glados Health: " << gladosHealth << "   ";
    }
}

// this function is used to erase Glados health.
void eraseGladosHealth()
{
    gotoxy(134, 30);
    cout << "                        ";
}

// -------------------------------------Glados Functions End -------------------------------------------



// ------------------------------------- Yutani Functions -------------------------------------------

// this function prints enemy named Yutani on screen.
void printYutani()
{
    for (int rows = 0; rows < 4; rows++)
    {
        gotoxy(yutaniX, yutaniY + rows);
        for (int col = 0; col < 6; col++)
        {
            cout << yutani[rows][col];
        }
    }
}

// this function erases enemy named Yutani on screen.
void eraseYutani()
{
    for (int rows = 0; rows < 4; rows++)
    {
        gotoxy(yutaniX, yutaniY + rows);
        for (int col = 0; col < 6; col++)
        {
            cout << " ";
        }
    }
}

// this function is used to move enemy Yutani on screen.
void moveYutani()
{
    if (yutaniX < jackx)
    {
        int nextlocation1 = getCharAtxy(yutaniX + 6, yutaniY);
        int nextlocation2 = getCharAtxy(yutaniX + 6, yutaniY + 1);
        int nextlocation3 = getCharAtxy(yutaniX + 6, yutaniY + 2);
        int nextlocation4 = getCharAtxy(yutaniX + 6, yutaniY + 3);

        if ((nextlocation1 == ' ' || nextlocation1 == '.' || nextlocation1 == '-') && (nextlocation2 == ' ' || nextlocation2 == '.' || nextlocation2 == '-') && (nextlocation3 == ' ' || nextlocation3 == '.' || nextlocation3 == '-') && (nextlocation4 == ' ' || nextlocation4 == '.' || nextlocation4 == '-'))
        {
            eraseYutani();
            yutaniX += 0.5;
            printYutani();
        }

    }
    if (yutaniX > jackx)
    {
        int nextlocation1 = getCharAtxy(yutaniX - 2, yutaniY);
        int nextlocation2 = getCharAtxy(yutaniX - 2, yutaniY + 1);
        int nextlocation3 = getCharAtxy(yutaniX - 2, yutaniY + 2);
        int nextlocation4 = getCharAtxy(yutaniX - 2, yutaniY + 3);

        if ((nextlocation1 == ' ' || nextlocation1 == '.' || nextlocation1 == '-') && (nextlocation2 == ' ' || nextlocation2 == '.' || nextlocation2 == '-') && (nextlocation3 == ' ' || nextlocation3 == '.' || nextlocation3 == '-') && (nextlocation4 == ' ' || nextlocation4 == '.' || nextlocation4 == '-'))
        {
            eraseYutani();
            yutaniX -= 0.5;
            printYutani();
        }

        if (nextlocation2 == smallbox || nextlocation2 == bigbox || nextlocation2 == upbox)
        {
            eraseJackHealth();
            jackHealth = jackHealth - 5;
        }

    }
    if (yutaniY < jacky)
    {
        int nextlocation1 = getCharAtxy(yutaniX, yutaniY + 4);
        int nextlocation2 = getCharAtxy(yutaniX + 1, yutaniY + 4);
        int nextlocation3 = getCharAtxy(yutaniX + 2, yutaniY + 4);
        int nextlocation4 = getCharAtxy(yutaniX + 3, yutaniY + 4);
        int nextlocation5 = getCharAtxy(yutaniX + 4, yutaniY + 4);
        int nextlocation6 = getCharAtxy(yutaniX + 5, yutaniY + 4);

        if ((nextlocation1 == ' ' || nextlocation1 == '.' || nextlocation1 == '-') && (nextlocation2 == ' ' || nextlocation2 == '.' || nextlocation2 == '-') && (nextlocation3 == ' ' || nextlocation3 == '.' || nextlocation3 == '-') && (nextlocation4 == ' ' || nextlocation4 == '.' || nextlocation4 == '-') && (nextlocation5 == ' ' || nextlocation5 == '.' || nextlocation5 == '-') && (nextlocation6 == ' ' || nextlocation6 == '.' || nextlocation6 == '-'))
        {
            eraseYutani();
            yutaniY += 0.5;
            printYutani();
        }

    }
    if (yutaniY > jacky)
    {
        int nextlocation1 = getCharAtxy(yutaniX, yutaniY - 1);
        int nextlocation2 = getCharAtxy(yutaniX + 1, yutaniY - 1);
        int nextlocation3 = getCharAtxy(yutaniX + 2, yutaniY - 1);
        int nextlocation4 = getCharAtxy(yutaniX + 3, yutaniY - 1);
        int nextlocation5 = getCharAtxy(yutaniX + 4, yutaniY - 1);
        int nextlocation6 = getCharAtxy(yutaniX + 5, yutaniY - 1);

        if ((nextlocation1 == ' ' || nextlocation1 == '.' || nextlocation1 == '-') && (nextlocation2 == ' ' || nextlocation2 == '.' || nextlocation2 == '-') && (nextlocation3 == ' ' || nextlocation3 == '.' || nextlocation3 == '-') && (nextlocation4 == ' ' || nextlocation4 == '.' || nextlocation4 == '-') && (nextlocation5 == ' ' || nextlocation5 == '.' || nextlocation5 == '-') && (nextlocation6 == ' ' || nextlocation6 == '.' || nextlocation6 == '-'))
        {
            eraseYutani();
            yutaniY -= 0.5;
            printYutani();
        }

    }
}

// this function is used to detect jack and yutani collision.
void yutaniJackCollision()
{
    char next = getCharAtxy(yutaniX - 1, yutaniY + 1);

    if (next == bigbox || next == smallbox || next == upbox || next == top)
    {
        eraseJackHealth();
        jackHealth = jackHealth - 5;
    }
}

// -------------------------------------Yutani Functions End -------------------------------------------

// ------------------------------------- Buster Functions ---------------------------------------------

// this function will print enemy named as Buster on Screen.
void printBuster()
{
    for (int rows = 0; rows < 3; rows++)
    {
        gotoxy(busterX, busterY + rows);
        for (int col = 0; col < 5; col++)
        {
            cout << buster[rows][col];
        }
    }
}

// this function is used to move Buster on Screen.
void moveBusterBullet()
{
    for (int i = 0; i < busterBulletCount; i++)
    {
        if (isBusterBulletActive[i] == true)
        {
            char next = getCharAtxy(busterBulletX[i] + 1, busterBulletY[i] + 1);
            char next1 = getCharAtxy(busterBulletX[i] - 1, busterBulletY[i] + 1);
            // char next1 = getCharAtxy(busterBulletX[i] + 1, gladosBulletY[i]);
            if (next != ' ' || next1 != ' ')
            {
                eraseBusterBullet(busterBulletX[i], busterBulletY[i]);
                makeBusterBulletInactive(i);
            }
            else
            {

                eraseBusterBullet(busterBulletX[i], busterBulletY[i]);
                busterBulletY[i]++;
                printBusterBullet(busterBulletX[i], busterBulletY[i]);
            }
        }
    }
}

// this function is used to print bullets of buster on screen.
void printBusterBullet(int x, int y)
{
    gotoxy(x, y);
    cout << bull;
}

// this function is used to erase bullets of buster on screen.
void eraseBusterBullet(int x, int y)
{
    gotoxy(x, y);
    cout << "  ";
}

// this function is used to print bullets of buster on screen.
void makeBusterBulletInactive(int index)
{
    isBusterBulletActive[index] = false;
}

// this function is used to make bullets of Buster inactive to remove it from screen.
void generateBusterBullet()
{
    busterBulletY[busterBulletCount] = busterY + 3;
    busterBulletX[busterBulletCount] = busterX + 2;
    isBusterBulletActive[busterBulletCount] = true;
    gotoxy(busterX + 2, busterY + 3);
    cout << bull << endl;
    busterBulletCount++;
}

// this function will detect collision of bullets with buster.
void bulletCollisionWithBuster()
{
    for (int i = 0; i < bulletCount; i++)
    {
        if (isBulletActive[i] == true)
        {
            if (bulletY[i] - 1 == busterY + 3 && (bulletX[i] == busterX || bulletX[i] == busterX + 1 || bulletX[i] == busterX + 2 || bulletX[i] == busterX + 3 || bulletX[i] == busterX + 4))
            {
                addScore();
                // score++;
                eraseBusterHealth();
                busterHealth = busterHealth - 5;
            }
            if (busterY + 4 == bulletY[i] && busterX + 1 == bulletX[i])
            {
                addScore();
                // score++;
                eraseBusterHealth();
                busterHealth = busterHealth - 5;
            }
        }
    }
}

// this function is used to move buster .
void moveBuster()
{
    if (busterDirection == "Right")
    {
        char next = getCharAtxy(busterX + 5, busterY);
        if (next == ' ' || next == '.')
        {
            eraseBuster();
            busterX++;
            printBuster();
            generateBusterBullet();
        }
        if (busterX > 100)
        {
            busterDirection = "Left";
        }
    }

    if (busterDirection == "Left")
    {
        char next = getCharAtxy(busterX - 1, busterY);
        if (next == ' ' || next == '.')
        {
            eraseBuster();
            busterX--;
            printBuster();
            generateBusterBullet();
        }
        else if (busterX < 20)
        {
            busterDirection = "Right";
        }
    }
}

// this function is used to print buster healt.
void printBusterHealth()
{
    if (busterHealth >= 0)
    {
        gotoxy(134, 32);
        cout << "Buster Health: " << busterHealth << "   ";
    }
}

// this function is used to erase buster healt.
void eraseBusterHealth()
{
    gotoxy(134, 30);
    cout << "                        ";
}

// this function is used to erase buster.
void eraseBuster()
{
    for (int rows = 0; rows < 3; rows++)
    {
        gotoxy(busterX, busterY + rows);
        for (int col = 0; col < 5; col++)
        {
            cout << " ";
        }
    }
}

// -------------------------------------Buster Functions End -------------------------------------------


//---------------FILE HANDLING ----------------------

void storeCoordinates()
{
    fstream file;
    file.open("Coordinates", ios::out);
    {
        file << jackx << endl;
        file << jacky << endl;
        file << freshX << endl;
        file << freshY << endl;
        file << yutaniX << endl;
        file << yutaniY << endl;
        file << gladosX << endl;
        file << gladosY << endl;
        file << busterX << endl;
        file << busterY << endl;
    }
    file.close();
}

void storeHealth()
{
    fstream file;
    file.open("Health", ios::out);
    {
        file << jackHealth << endl;
        file << freshHealth << endl;
        file << gladosHealth << endl;
        file << busterHealth << endl;
    }
    file.close();
}

void storeBulletCount()
{
    fstream file;
    file.open("Bullets", ios::out);
    {
        file << bulletCount << endl;
        file << freshBulletCount << endl;
        file << gladosBulletCount << endl;
        file << busterBulletCount << endl;
    }
    file.close();
}

void readCoordinates()
{
    fstream file;
    file.open("Coordinates", ios::in);
    {
        file >> jackx;
        file >> jacky;
        file >> freshX;
        file >> freshY;
        file >> yutaniX;
        file >> yutaniY;
        file >> gladosX;
        file >> gladosY;
        file >> busterX;
        file >> busterY;
    }
    file.close();
}

void readHealth()
{
    fstream file;
    file.open("Health", ios::in);
    {
        file >> jackHealth;
        file >> freshHealth;
        file >> gladosHealth;
        file >> busterHealth;
    }
    file.close();
}

void readBulletCount()
{
    fstream file;
    file.open("Bullets", ios::in);
    {
        file >> bulletCount;
        file >> freshBulletCount;
        file >> gladosBulletCount;
        file >> busterBulletCount;
    }
    file.close();
}

// ---------------File Handling End ----------------- 


// this menu shows an additional feature resume to resume the game.
char resumeMenu()
{
    char choice;
    cout << "   Menu" << endl;
    cout << "____________________" << endl;
    cout << "  " << endl;
    cout << "1. Resume." << endl;
    cout << "2. Start." << endl;
    cout << "3. Options." << endl;
    cout << "4. Exit." << endl;
    cout << "Please Enter Your Choice : ";
    cin >> choice;
    return choice;
}

// this function will reset all the coordinates.
void resetCoordinates()
{
    jackx = 60;
    jacky = 28;
    freshX = 100;
    freshY = 28;
    yutaniX = 40;
    yutaniY = 7;
    gladosX = 20;
    gladosY = 6;

    freshHealth = 100;
    jackHealth = 1000;
    gladosHealth = 100;

    deadCount1 = 0;
    deadCount2 = 0;

    timer = 0;
    timer1 = 0;
    freshBulletCount = 0;
    gladosBulletCount = 0;
    bulletCount = 0;
}

// this function contain all function of level 2.
void level2()
{
    jackx = 60;
    jacky = 28;
    system("cls");
    printBuster();
    printMaze();
    printJack(jackx, jacky);
    gotoxy(40, 40);

    while (true)
    {

        printScore();
        printBusterHealth();
        printJackHealth();
        if (GetAsyncKeyState(VK_RIGHT))
        {
            char nextlocation = getCharAtxy(jackx + 3, jacky);
            char nextlocation1 = getCharAtxy(jackx + 3, jacky + 1);
            char nextlocation2 = getCharAtxy(jackx + 3, jacky + 2);

            if ((nextlocation == ' ' || nextlocation == '.' || nextlocation == '-') && (nextlocation1 == ' ' || nextlocation == '.' || nextlocation == '-') && (nextlocation2 == ' ' || nextlocation == '.' || nextlocation == '-'))
            {
                erazeJack(jackx, jacky);
                jackx = jackx + 1;
                printJack(jackx, jacky);
            }
            direction = "right";
        }

        if (GetAsyncKeyState(VK_LEFT))
        {
            char nextlocation = getCharAtxy(jackx - 1, jacky);
            char nextlocation1 = getCharAtxy(jackx - 1, jacky + 1);
            char nextlocation2 = getCharAtxy(jackx - 1, jacky + 2);
            if ((nextlocation == ' ' || nextlocation == '.' || nextlocation == '-') && (nextlocation1 == ' ' || nextlocation == '.' || nextlocation == '-') && (nextlocation2 == ' ' || nextlocation == '.' || nextlocation == '-'))
            {
                erazeJack(jackx, jacky);
                jackx = jackx - 1;
                printJack(jackx, jacky);
            }
            direction = "left";
        }

        if (GetAsyncKeyState(VK_UP))
        {
            char nextlocation = getCharAtxy(jackx, jacky - 2);
            char nextlocation1 = getCharAtxy(jackx + 1, jacky - 2);
            char nextlocation2 = getCharAtxy(jackx + 2, jacky - 2);
            if ((nextlocation == ' ' || nextlocation == '.' || nextlocation == '-') && (nextlocation1 == ' ' || nextlocation == '.' || nextlocation == '-') && (nextlocation2 == ' ' || nextlocation == '.' || nextlocation == '-'))
            {
                erazeJack(jackx, jacky);
                jacky = jacky - 1;
                printJack(jackx, jacky);
            }
            direction = "up";
        }

        if (GetAsyncKeyState(VK_DOWN))
        {
            char nextlocation = getCharAtxy(jackx, jacky + 3);
            char nextlocation1 = getCharAtxy(jackx + 1, jacky + 3);
            char nextlocation2 = getCharAtxy(jackx + 2, jacky + 3);
            if ((nextlocation == ' ' || nextlocation == '.' || nextlocation == '-') && (nextlocation1 == ' ' || nextlocation == '.' || nextlocation == '-') && (nextlocation2 == ' ' || nextlocation == '.' || nextlocation == '-'))
            {
                erazeJack(jackx, jacky);
                jacky = jacky + 1;
                printJack(jackx, jacky);
            }
            direction = "down";
        }

        if (GetAsyncKeyState(VK_SPACE))
        {
            generateBullet(jackx, jacky);
            storeBulletCount();
        }

        if (GetAsyncKeyState(VK_ESCAPE))
        {
            system("cls");
            storeCoordinates();
            storeBulletCount();
            storeHealth();
            break;
        }

        if (busterHealth <= 0)
        {
            system("cls");
            char ch;
            cout << " YOU WIN " << endl;
            cout << "Press any key to continue : ";
            cin >> ch;
        }
        if (jackHealth <= 0)
        {
            system("cls");
            char ch;
            cout << " GAME OVER " << endl;
            cout << "Press any key to continue : ";
            cin >> ch;
        }
        generateBusterBullet();
        moveBusterBullet();
        moveBullet();
        moveBuster();
        bulletCollisionWithBuster();
        bulletCollisionOfBusterWithJack();
        Sleep(50);
    }
}

// this function is used to add score.
void addScore()
{
    score++;
}

// this function is used to print score on screen.
void printScore()
{
    gotoxy(134, 8);
    cout << "Score: " << score << " ";
}

// In this function all functions of game is running .
void gamerunning()
{
    system("cls");
    printMaze();
    printJack(jackx, jacky);
    gotoxy(40, 40);
    while (true)
    {

        printScore();
        printFreshHealth();
        printJackHealth();

        // move Jack to Right.
        if (GetAsyncKeyState(VK_RIGHT))
        {
            char nextlocation = getCharAtxy(jackx + 3, jacky);
            char nextlocation1 = getCharAtxy(jackx + 3, jacky + 1);
            char nextlocation2 = getCharAtxy(jackx + 3, jacky + 2);

            if ((nextlocation == ' ' || nextlocation == '.' || nextlocation == '-') && (nextlocation1 == ' ' || nextlocation == '.' || nextlocation == '-') && (nextlocation2 == ' ' || nextlocation == '.' || nextlocation == '-'))
            {
                erazeJack(jackx, jacky);
                jackx = jackx + 1;
                printJack(jackx, jacky);
            }
            direction = "right";
        }

        // move Jack to Left.
        if (GetAsyncKeyState(VK_LEFT))
        {
            char nextlocation = getCharAtxy(jackx - 1, jacky);
            char nextlocation1 = getCharAtxy(jackx - 1, jacky + 1);
            char nextlocation2 = getCharAtxy(jackx - 1, jacky + 2);
            if ((nextlocation == ' ' || nextlocation == '.' || nextlocation == '-') && (nextlocation1 == ' ' || nextlocation == '.' || nextlocation == '-') && (nextlocation2 == ' ' || nextlocation == '.' || nextlocation == '-'))
            {
                erazeJack(jackx, jacky);
                jackx = jackx - 1;
                printJack(jackx, jacky);
            }
            direction = "left";
        }

        // move Jack Up.
        if (GetAsyncKeyState(VK_UP))
        {
            char nextlocation = getCharAtxy(jackx, jacky - 2);
            char nextlocation1 = getCharAtxy(jackx + 1, jacky - 2);
            char nextlocation2 = getCharAtxy(jackx + 2, jacky - 2);
            if ((nextlocation == ' ' || nextlocation == '.' || nextlocation == '-') && (nextlocation1 == ' ' || nextlocation == '.' || nextlocation == '-') && (nextlocation2 == ' ' || nextlocation == '.' || nextlocation == '-'))
            {
                erazeJack(jackx, jacky);
                jacky = jacky - 1;
                printJack(jackx, jacky);
            }
            direction = "up";
        }

        // move Jack Down.
        if (GetAsyncKeyState(VK_DOWN))
        {
            char nextlocation = getCharAtxy(jackx, jacky + 3);
            char nextlocation1 = getCharAtxy(jackx + 1, jacky + 3);
            char nextlocation2 = getCharAtxy(jackx + 2, jacky + 3);
            if ((nextlocation == ' ' || nextlocation == '.' || nextlocation == '-') && (nextlocation1 == ' ' || nextlocation == '.' || nextlocation == '-') && (nextlocation2 == ' ' || nextlocation == '.' || nextlocation == '-'))
            {
                erazeJack(jackx, jacky);
                jacky = jacky + 1;
                printJack(jackx, jacky);
            }
            direction = "down";
        }

        // space is used to generate bullets
        if (GetAsyncKeyState(VK_SPACE))
        {
            generateBullet(jackx, jacky);
            storeBulletCount();
        }

        bulletCollisionOfFreshWithJack();
        bulletCollisionOfGladosWithJack();
        moveFreshBullet();
        if (freshHealth > 0 && timer == 0)
        {
            printFresh();
            moveFresh();
            generateFreshBullet();
            timer = 5;
        }
        if (freshHealth <= 0)
        {
            eraseFresh();
            freshHealth = 0;
            deadCount1 = 1;
            printGlados();
            flag = true;
        }
        if (jackHealth <= 0)
        {
            system("cls");
            char ch;
            cout << " GAME OVER " << endl;
            cout << "Press C to continue : ";
            cin >> ch;
        }
        moveGladosBullet();
        printGladosHealth();

        if (gladosHealth > 0 && freshHealth <= 0)
        {
            moveGlados();
            if (timer == 0)
            {
                generateGladosBullet();
            }
            bulletCollisionWithGlados();
            bulletCollisionOfGladosWithGrid();
            timer1 = 5;
        }
        else if (gladosHealth <= 0)
        {
            eraseGlados();
            gladosHealth = 0;
            deadCount2 = 1;
        }

        timer--;
        timer1--;
        if (freshHealth == 0 && gladosHealth == 0)
        {
            deadCount = 1;
        }
        if ((deadCount1 == 1 && deadCount2 == 1) && jackHealth > 0)
        {
            char character;
            system("cls");
            cout << "Press any key to continue : ";
            cin >> character;
            level2();
        }
        moveYutani();
        moveBullet();

        bulletCollisionWithFresh();

        if (GetAsyncKeyState(VK_ESCAPE))
        {
            system("cls");
            storeCoordinates();
            storeBulletCount();
            storeHealth();
            break;
        }

        Sleep(30);
    }
    getch();
}

// this function is used to get the characetr at x,y coordinates.
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : 'B';
}

// this function is used to move to x,y position.
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

// ----------------------------- END --------------------------------