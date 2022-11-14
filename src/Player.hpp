#ifndef TOWER_DEFENSE_PLAYER
#define TOWER_DEFENSE_PLAYER

#include <string>

class Player {
 public:
    //Creates Player
    Player(std::string username);
    
    //Increases the amount of money the player has
    void AddMoney(int a);

    /**Decreases the amount of money the player has, when the player is buying a tower
     * If the towers cost is higher than the amount of money the player has return false and dont decrease the amount of money
     * Otherwise return true and decrease the amount of money the player has */
    bool Pay(int a);

    //Increases the amount of points the player has
    void AddPoints(int a);

 private:
    //Username of the player
    std::string username_;

    //The players points
    int points_;

    //The players money
    int money_;

};

#endif