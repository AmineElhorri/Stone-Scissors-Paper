


#include <iostream>
#include<cstdlib>
using namespace std;
enum EnGame{stone=1,paper=2,scissors=3};

short RandomNumber(short from, short to)
{
    int RandomNumber = rand() % (to - from + 1) + from;
    return RandomNumber;
}
short HowManyRounds()
{
    short Number;
    cout << " please enter how many rounds do you want to play " << endl;
    cin >> Number;
    return Number;
}
void GameOver(short player,short computer,short Draw,short Number)
{
    cout << "\n\n___________________________________________________________________\n\n";
    cout << "                          +++    Game Over    +++                   \n\n";
    cout << "_________________________________________________________________________\n\n";
    cout << "                                  [Game Results]                         \n\n";

    cout << " Game Rounds : " << Number << endl;
    cout << " Player won times : " << player << endl;
    cout << " Computer won times : " << computer << endl;
    cout << " Draw times : " << Draw << endl;
    if (player > computer)
    {
        cout << " final Winner :   [Player]" << endl;
    }
    if (player == computer)
    {
        cout << " final Winner :    No Winner" << endl;
    }
    if (player < computer)
    {
        cout << " final Winner :     [Computer]" << endl;
    }
    cout << "\n\n_____________________________________________________________________________\n\n";
}
void Result(short N, short yourchoise, short choisecomputer,short Number,short &player,short &computer,short &Draw)
{
    
    cout << "\n\n\n ____________________________________________Round [" << N << "] _______________________________________\n\n";

    switch (yourchoise)
    {
    case EnGame::stone:
        cout << "Player choise : stone " << endl;
        break;
    case EnGame::paper:
        cout << "Player choise : paper " << endl;
        break;
    case EnGame::scissors:
        cout << "Player choise : scissors " << endl;
        break;
    }
    switch (choisecomputer)
    {
    case EnGame::stone:
        cout << "Computer choise : stone " << endl;
        break;
    case EnGame::paper:
        cout << "Computer choise : paper " << endl;
        break;
    case EnGame::scissors:
        cout << "Computer choise : scissors " << endl;
        break;
    }
    if (yourchoise == choisecomputer)
    {
        cout << "Round Winner        :    [ No winner ] " << endl;
        system("color 6F");
        ++Draw;
        
    }
    if (yourchoise == 1 && choisecomputer == 3)
    {
        cout << " Round Winner       :     [Player] " << endl;
        system("color 2F");
        ++player;
        
    }
    if (choisecomputer == 1 && yourchoise == 3)
    {
        cout << " Round Winner        :     [computer] " << endl;
        system("color 4F");
        cout << "\a";
        ++computer;
    }
    if (yourchoise > choisecomputer)
    {
        cout << " Round Winner         :     [Player]   " << endl;
        system("color 2F");
        ++player;
    }
    if(choisecomputer>yourchoise)
    {
        cout << " Round Winner          :     [Computer]  " << endl;
        system("color 4F");
        cout << "\a";
        ++computer;
    }
    cout << "\n\n_____________________________________________________________________________________________________\n";
    cout << "\n\n";
    
}

void TheGame(short &choisecomputer,short &yourchoise,short &Number)
{
    short player=0, computer=0, Draw=0;


    Number = HowManyRounds();
    for (short i = 1; i <= Number; i++)
    {
        cout << " Round [" << i << " ] Begins : " << endl;
        cout << " your choise : [1]:stone , [2]:paper , [3]:scissors  : ";
        cin >> yourchoise;
        choisecomputer = RandomNumber(1, 3);

        Result(i, yourchoise, choisecomputer, Number,player,computer,Draw);
    }

    GameOver(player, computer, Draw, Number);

}
int main()
{
    srand((unsigned)time(NULL));
    short Number, yourchoise, choisecompter;
    TheGame(choisecompter, yourchoise, Number);
}

