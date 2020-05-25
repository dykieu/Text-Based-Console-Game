/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/12/19
 * Purpose:     Game class will facilitated assigning characters
 *              through the use of menu class. Game class also
 *              facilitates each round of the game, will display
 *              stats relevant to that current battle
***************************************************************/
#include "game.hpp"

/***************************************************************
 * Function:    Game()
 * Purpose:     initializes variables for the game.
****************************************************************/
Game::Game()
{
    tempPlayer = NULL;
    position = NULL;
    roundCounter = 20;
}

/***************************************************************
 * Function:    playGame()
 * Purpose:     Facilitates the game state. Calls for function 
 *              to choose chars and then plays the game with 
 *              said characters.
****************************************************************/
void Game::playGame()
{
    //Creates a new map (Visual and virtual)
    newMap();

    //Clears Inventory items
    test.setEquipment("empty", "empty", "empty");

    do
    {
        //Displays visual map
        displayMap();

        //Displays game stats
        cout << "Days remaining: " << roundCounter << endl;
        cout << "[HP]: " << test.getHp() <<"    [MP]: " << test.getMp() << "    Rank: " << test.getRank() << endl;
        
        //Checks that its the first turn
        if (roundCounter != 20)
        {
            //Display inventory by grabbing from inventory
            cout << "Inventory: ";
            for (int i = 0; i < inventory.size() ; i++)
            {
                //Checks that the inventory slot is not empty before printing it out
                if (inventory[i]->getname() != "empty" || inventory[i]->getname() != "none" )
                {
                    cout << inventory[i]->getname() << "  ";
                }
                
            }
            cout <<"\r\n";
        }
        //Displays inventory at the start of the game
        else if (roundCounter == 20)
        {
            cout << "Inventory: empty   empty   empty" << endl;
        }
        cout << "\r\n"; 

        //Runs special event in that space
        position->specialEvent(&test);

        //Test if user has defeated baran(boss) or not
        if (test.getBaran() == 1)
        {
            cout << "*****************************************************" << endl;
            cout << "\r\n";  

            //Prints out game winning message
            gameMenu.gameWon();
            cout << "\r\n";
            return; 
        }

        //Checks user hp after special event(In case user died)
        if (test.getHp() == 0)
        {
            cout << "*****************************************************" << endl;
            cout << "****               [GAME OVER]                   ****" << endl;
            cout << "*****************************************************" << endl;
            return;
        }
        cout << "\r\n";

        //Runs search event in current space
        position->search(&test);

        //updates or creates virtual inventory
        inventoryCheck();

        //Loops until a direction is valid
        validDirection = false;
        while (validDirection == false)
        {
            direction = gameMenu.directionChoice();
            switch (direction)
            {
            //Checks UP position
            case 1:
                //Checks UP position is valid
                if (position->getUp() == NULL)
                {
                    cout << "   You attemped to head [UP]...    But there is no path [UP]." << endl;
                    cout << "\r\n" << endl;
                    break;
                }
                //If valid
                else
                {
                    if (position->getUp() != bossRoom)
                    {
                        cout << "   You attemped to head [UP]...    And procceed to the next room." << endl;
                        validDirection = true;

                        //Moves character position to new space
                        position = position->getUp();

                        //changes player piece in visual map
                        prevX = xPos;
                        prevY = yPos;

                        //Moves position up one unit vertically
                        yPos = yPos - 1;

                        //Empties the previous room, but leaves it "discovered". Moves character piece.
                        map[yPos][xPos] = '*';
                        map[prevY][prevX] = ' ';
                        break;
                    }
                    else
                    {
                        //If the next up room is boss room, checks that user has key
                        if (test.getMisc() == "key")
                        {
                            cout << "   You attemped to head [UP]...    You successfully unlocked the door" << endl;
                            validDirection = true;

                            //Moves character position to new space
                            position = position->getUp();

                            //changes player piece in visual map
                            prevX = xPos;
                            prevY = yPos;

                            //Moves position up one unit vertically
                            yPos = yPos - 1;

                            //Empties the previous room, but leaves it "discovered". Moves character piece.
                            map[yPos][xPos] = '*';
                            map[prevY][prevX] = ' ';
                            break;
                        }
                        else
                        {
                            cout << "   You attemped to head [UP]...    But you can't because do not have the key." << endl;
                            cout << "\r\n" << endl;
                            break;
                        }  
                    }  
                }
            //Checks DOWN direction
            case 2:
                //Checks if the direction is valid
                if (position->getDown() == NULL)
                {
                    cout << "   You attemped to head [DOWN]...    But there is no path [DOWN]." << endl;
                    cout << "\r\n" << endl;
                    break;
                }
                //If valid
                else
                {
                    validDirection = true;
                    cout << "   You attemped to head [DOWN]...    And procceed to the next room." << endl;
                    position = position->getDown();

                    //changes player piece in visual map
                    prevX = xPos;
                    prevY = yPos;

                    //Moves position up one unit vertically
                    yPos = yPos + 1;

                    //Empties the previous room, but leaves it "discovered". Moves character piece.
                    map[yPos][xPos] = '*';
                    map[prevY][prevX] = ' ';
                    break;
                }
            //Checks if LEFT is valid
            case 3:
                //If Left not valid
                if (position->getLeft() == NULL)
                {
                    cout << "   You attemped to head [Left]...    But there is no path [LEFT]." << endl;
                    cout << "\r\n" << endl;
                    break;
                }
                //If left is valid
                else
                {
                    validDirection = true;
                    cout << "   You attemped to head [Left]...    And procceed to the next room." << endl;
                    
                    //Updates position of character
                    position = position->getLeft();

                    //changes player piece in visual map
                    prevX = xPos;
                    prevY = yPos;

                    //Moves position up one unit Horizontal
                    xPos = xPos - 1;

                    //Empties the previous room, but leaves it "discovered". Moves character piece.
                    map[yPos][xPos] = '*';
                    map[prevY][prevX] = ' ';
                    break;
                }
            //Check if Right direction is valid
            case 4:
                //IF not valid
                if (position->getRight() == NULL)
                {
                    cout << "   You attemped to head [Right]...    But there is no path [RIGHT]." << endl;
                    cout << "\r\n" << endl;
                    break;
                }
                //IF valid
                else
                {
                    validDirection = true;
                    cout << "   You attemped to head [Right]...    And procceed to the next room." << endl;
                    
                    //Changes character position
                    position = position->getRight();
                    
                    //changes player piece in visual map
                    prevX = xPos;
                    prevY = yPos;

                    //Moves position up one unit Horizontal
                    xPos = xPos + 1;

                    //Empties the previous room, but leaves it "discovered". Moves character piece.
                    map[yPos][xPos] = '*';
                    map[prevY][prevX] = ' ';
                    break;
                }
            }
        }

        //Decrements round counter and then resets validDirection flag
        validDirection = false;
        roundCounter--;
    } while (roundCounter !=0);

    //IF user has run out of rounds
    if (roundCounter == 0)
    {
        //Prints out game ending message
        cout << "\r\n";  
        gameMenu.gameEnd();
        cout << "\r\n";
        cout << "*****************************************************" << endl;
        cout << "****               [GAME OVER]                   ****" << endl;
        cout << "*****************************************************" << endl;
    }
    
    return;
}

/***************************************************************
 * Function:    displayMap()
 * Purpose:     Displays the visual map for users
****************************************************************/
void Game::displayMap()
{
    //Prints out the map
    cout << "***************************************************************" << endl;
    cout << " [CURRENT MAP]" << endl;
    for (int i = 0; i < 11; i++)
    {
        cout << "   ";
        for (int j = 0; j < 9; j++)
        {
            cout << map[i][j];
        }
        cout << "\r\n";
    }
    cout << "KEY:" << endl;
    cout << "You are currently at '*' "<< endl;
    cout << "Undiscovered: '?' " << endl;
    cout << "Discovered: ' ' " << endl;
    cout << "***************************************************************" << endl;
    return;
}

/***************************************************************
 * Function:    newMap()
 * Purpose:     Facilitates the creation of a visual and virtual
 *              map. Using space class and an array.
****************************************************************/
void Game::newMap()
{
    //Fills the whole map with '#' to simulate unaccessable areas.
    for (int i = 0; i <= 11; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            map[i][j] = '|';
        }
    }
    
    //Create the visual dungeon
    map[1][3] = '?';
    map[2][3] = '?';
    createDung(3, 1, 4);
    map[3][7] = '?';
    map[4][3] = '?';
    map[4][7] = '?';
    createDung(5, 3, 8);
    map[6][3] = '?';
    createDung(7, 1, 6);
    map[7][3] = '*';
    
    //starting position of character unit
    xPos = 3;
    yPos = 7;

    //Key:
    //A - Empty      B - Basement       C - Hallway
    //D - Baracks    E - Armory         F - Training Hall
    //G - Blood      H - mini-boss      I - Boss      
    //J - Garden     K - Trap           L - Hidden Room 

    //Dynamically allocating the visual map with space class
    //Main Room | Position Vector[0]
    gameMap.addUp(&position, NULL, 'A', &temp);
    spaceAddress.push_back(temp);  

    //Hallway 1 | Position Vector[1]
    gameMap.addUp(&position, NULL, 'C', &temp);
    spaceAddress.push_back(temp); 

    //Garden | Position Vector[2]
    gameMap.addUp(&position, NULL, 'J', &temp);
    spaceAddress.push_back(temp);

    //Hallway 2 | Position Vector[3]
    gameMap.addUp(&position, NULL, 'C', &temp);
    spaceAddress.push_back(temp);  

    //Baracks  | Position Vector[4]
    gameMap.addUp(&position, NULL, 'D', &temp);
    spaceAddress.push_back(temp);
  
    //Hallway 3 | Position Vector[5]
    gameMap.addUp(&position, NULL, 'C', &temp);
    spaceAddress.push_back(temp);    

    //Training Hall | Position Vector[6]
    gameMap.addUp(&position, NULL, 'F', &temp);
    spaceAddress.push_back(temp);  

    //Hallway 4 | Position Vector[7]
    gameMap.addRight(&position, NULL, 'C', &temp);
    spaceAddress.push_back(temp);

    //Trap room | Position Vector[8]
    gameMap.addRight(&position, NULL, 'K', &temp);
    spaceAddress.push_back(temp);

    //Hallway 5 | Position Vector[9]
    gameMap.addLeft(&position, NULL, 'C', &temp);
    spaceAddress.push_back(temp);

    //Basement 1 | Position Vector[10]
    gameMap.addLeft(&position, NULL, 'B', &temp);
    spaceAddress.push_back(temp);

    startAddress = spaceAddress[10];

    //Hallway 6 | Position Vector[11]
    gameMap.addDown(&startAddress, NULL, 'C', &temp);
    spaceAddress.push_back(temp);

    //Hidden Room | Position Vector[12]
    gameMap.addDown(&startAddress, NULL, 'L', &temp);
    spaceAddress.push_back(temp);

    //moves starting position to Main Hall 2?
    startAddress = spaceAddress[2];

    //Hallway 7 | Vector[13]
    gameMap.addRight(&startAddress, NULL, 'C', &temp);
    spaceAddress.push_back(temp);

    //BLood room | vector[14]
    gameMap.addRight(&startAddress, NULL, 'G', &temp);
    spaceAddress.push_back(temp);

    //Hallway 8 | Vector[15]
    gameMap.addRight(&startAddress, NULL, 'C', &temp);
    spaceAddress.push_back(temp);

    //Mini-Boss | Vector[16]
    gameMap.addRight(&startAddress, NULL, 'H', &temp);
    spaceAddress.push_back(temp);

    //Sets address to mini-boss room
    startAddress = spaceAddress[16];

    //Hallway 9 | vector[17]
    gameMap.addUp(&startAddress, NULL, 'C', &temp);
    spaceAddress.push_back(temp);

    //Boss Room | vector[18]
    gameMap.addUp(&startAddress, NULL, 'I', &temp);
    bossRoom = temp;
    spaceAddress.push_back(temp);

    //Sets address baracks (5th ele in vec)
    startAddress = spaceAddress[4];

    //Hallway 10 | vector[19]
    gameMap.addLeft(&startAddress, NULL, 'C', &temp);
    spaceAddress.push_back(temp);

    //Armory | vector[20]
    gameMap.addLeft(&startAddress, NULL, 'E', &temp);
    spaceAddress.push_back(temp);

    return;
}

/***************************************************************
 * Function:    createDung()
 * Purpose:     Fills the visual map with undiscovered areas by
 *              the user. Represented by '?'
****************************************************************/
void Game::createDung(int row, int colStart, int colEnd)
{
    for (int i = colStart; i < colEnd; i++)
    {
        map[row][i] = '?';
    }
    return;
}

/***************************************************************
 * Function:    invetoryCheck()
 * Purpose:     Creates and updates the inventory system. Used
 *              to store user items.
****************************************************************/
void Game::inventoryCheck()
{
    //If the inventory is empty(At beginning of the game, create empty objects)
    if (inventory.empty())
    {
        //Create weapon item spot
        Item* tempItem = new Item;
        tempItem->setname(test.getWepEQ());
        tempItem->setType("wep");
        inventory.push_back(tempItem);
        
        //Create armor item spot
        Item* tempItem2 = new Item;
        tempItem2->setname(test.getArmEQ());
        tempItem2->setType("def");
        inventory.push_back(tempItem2);

        //Create key item spot
        Item* tempItem3 = new Item;
        tempItem3->setname(test.getMisc());
        tempItem3->setType("key");
        inventory.push_back(tempItem3);

        return;
    }
    //If inventory is not empty
    else
    {
        //Looks through ever element of the inventory
        int size = inventory.size();
        for (int i = inventory.size() - 1; i >= 0; i--)
        { 
            //Checks if there is already a wep equipped
            if (inventory[i]->getType() == "wep")
            {
                //If the current wep item is not the one equipped on the hunter
                if (inventory[i]->getname() != test.getWepEQ())
                {
                    //stores the previous item
                    Item* delItem = inventory[i];

                    //deletes the previous item
                    inventory.erase(inventory.begin() + i);
                    delete delItem;
                    
                    //Creates new item
                    Item* tempItem = new Item;
                    tempItem->setname(test.getWepEQ());
                    tempItem->setType("wep");

                    //Test which item the user is wearing and allocates the stats to it
                    if (test.getWepEQ() == "DKD")
                    {
                        tempItem->setAttPwr(99);
                        tempItem->setDefPwr(0);
                    }
                    else if (test.getWepEQ() == "rusted blade")
                    {
                        tempItem->setAttPwr(10);
                        tempItem->setDefPwr(0);
                    }

                    //Equips weapon to user
                    test.changeWep(tempItem->getAttPwr());

                    //Stores item into inventory
                    inventory.push_back(tempItem);      
                }
            }

            //Checks if there is already a armor equipped
            if (inventory[i]->getType() == "def")
            {
                //If the current wep item is not the one equipped on the hunter
                if (inventory[i]->getname() != test.getArmEQ())
                {
                    //stores the previous item
                    Item* delItem = inventory[i];

                    //deletes the previous item
                    inventory.erase(inventory.begin() + i);
                    delete delItem;
                    
                    //Creates new item
                    Item* tempItem = new Item;
                    tempItem->setname(test.getArmEQ());
                    tempItem->setType("def");

                    //Sets item stats for the armor
                    if (test.getArmEQ() == "chainmail")
                    {
                        tempItem->setAttPwr(0);
                        tempItem->setDefPwr(10);
                    }

                    //Equips new armor
                    test.changeArmor(tempItem->getDefPwr());

                    //Stores item into inventory
                    inventory.push_back(tempItem);      
                }
            }

            //Checks if there is already a armor equipped
            if (inventory[i]->getType() == "key")
            {
                //If the current wep item is not the one equipped on the hunter
                if (inventory[i]->getname() != test.getMisc())
                {
                    //stores the previous item
                    Item* delItem = inventory[i];

                    //deletes the previous item
                    inventory.erase(inventory.begin() + i);
                    delete delItem;
                    
                    //Creates new item
                    Item* tempItem = new Item;
                    tempItem->setname(test.getMisc());
                    tempItem->setType("key");

                    //Stores item into inventory
                    inventory.push_back(tempItem);       
                }
            }  
        }
    }

    return; 
}

/***************************************************************
 *                  Game::~Game()
 * Destructor to free dynamically allocated memory at the end of
 * the game.
****************************************************************/
Game::~Game()
{
    //Deletes all the spaces used to create the dungeon
    for (int i = spaceAddress.size() - 1; i >= 0; i--)
    {
        temp = spaceAddress[i];
        spaceAddress.pop_back();
        delete temp;
    }

    //Deletes the created items
    for (int i = inventory.size() - 1; i >= 0; i--)
    {
        deleteItem = inventory[i];
        inventory.pop_back();
        delete deleteItem;
    }
    
    
}