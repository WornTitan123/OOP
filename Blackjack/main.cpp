#include <iostream>
#include <string>
#include <algorithm>
#include <io.h>
#include <fcntl.h>
#include <time.h>
#include "Card.h"
#include "blackjackplay.h"

using namespace std;

int main()
{
    Deck deck1;
    deck1.shuffle();
    Card dealer[11];
    Card player[11];
    int playerpoint = 0;
    int dealerpoint = 0;
    int round = 2;
    int rounddealer = 2;
    bool hit = false;
    int check;
    int playeracenum = 0;
    int dealeracenum = 0;
    bool wannastand = false;
    bool dealerstand = false;
    srand((unsigned)time(NULL));
    int randomchoice;
    bool wannaplay = true;
    while (wannaplay == true)
    {
    if(deck1.cardsLeft() > 4)
    {
        player[0] = deck1.deal();
        player[1] = deck1.deal();
        dealer[0] = deck1.deal();
        dealer[1] = deck1.deal();

    playerpoint = player[0].getPoint()+player[1].getPoint();
    if(player[0].getValue() == 1 || player[1].getValue() == 1)
    {
        playeracenum++;
    }
    if(player[0].getValue() == 1 && player[1].getValue() == 1)
    {
        playerpoint = 12;
    }
    dealerpoint = dealer[0].getPoint()+dealer[1].getPoint();
    if(dealer[0].getValue() == 1 || dealer[1].getValue() == 1)
    {
        dealeracenum++;
    }
    if(dealer[0].getValue() == 1 && dealer[1].getValue() == 1)
    {
        dealerpoint = 12;
    }
    cout << "Your card: ";
    player[0].display();
    cout << " and ";
    player[1].display();
    cout<< endl;
    cout << "One of dealer's card: ";
    dealer[1].display();
    cout<< endl;
    while(playerpoint < 21 && wannastand == false)
    {
    cout << "Hit or stand?(1 for hit, other for stand)" << endl;
    cin >> check;
    if(check == 1)
    {
        player[round] = deck1.deal();
        playerpoint += player[round].getPoint();
        player[round].display();
        cout << endl;
        if(player[round].getValue() == 1)
        {
            playeracenum++;
        }
        round++;
    }
    if(check != 1)
    {
        wannastand = true;
    }
    while(playerpoint>21 && playeracenum >0)
    {
        playeracenum--;
        playerpoint -= 10;
    }
    }


    if(playerpoint > 21)
    {
        cout << " over 21 . You lost." << endl;
    }
    else
    {
        while(dealerpoint < 21 && dealerstand == false)
        {
            cout << " dealer's another card : " << endl;
            dealer[0].display();
            if(dealerpoint<15)
            {
                dealer[round] = deck1.deal();
                dealerpoint += dealer[round].getPoint();
                cout << "dealer hit" << endl;
                dealer[round].display();
                cout << endl;
                round ++;
            }
            else
            {
                randomchoice = rand()%3;
                if(randomchoice == 1)
                {
                    dealer[round] = deck1.deal();
                    dealerpoint += dealer[round].getPoint();
                    cout << "dealer hit" << endl;
                    dealer[round].display();
                    cout << endl;
                    round ++;
                }
                if(randomchoice == 2)
                {
                    cout << "dealer stand" << endl;
                    dealerstand = true;
                }
            }
            while(dealerpoint > 21 && dealeracenum>0)
            {
                dealeracenum--;
                dealerpoint -= 10;
            }
        }
        if(dealerpoint > 21)
        {
            cout << "dealer over 21" << endl;
        }
        else
        {
            if(playerpoint > dealerpoint)
            {
                cout << " You won ";
            }
            if(playerpoint < dealerpoint)
            {
                cout << " You lost ";
            }
            if(playerpoint == dealerpoint)
            {
                cout << " draw ";
            }
        }
    }

    }
    cout << endl << " Wanna play next round? (1 for yes, other for no) " << endl;
    cin >> check;
    if(check == 1)
    {
        round = 2;
        rounddealer = 2;
        playeracenum = 0;
        dealeracenum = 0;
        playerpoint = 0;
        dealerpoint = 0;
        wannastand = false;
        dealerstand = false;
    }
    if(check != 1)
    {
        wannaplay = false;
    }
    }
    return 0;
}
