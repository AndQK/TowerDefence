#include <vector>
#include <string>
#include <Map.hpp>
#include <vector>





class Level {
public:
    

   Level(int initial_money, int initial_lives, int enemies_killed,
                 Map &Map, std::vector<int> enemy);

    /// Initial money
    /// \return
    int initial_money() const;

    /// Initial lives
    /// \return
    int initial_lives() const;

    /// Count of how many enemies have spawned.
    int enemies_killed() const;

    /// Spawn new enemies according to game time
    /// \param time
    /// \return Collection of enemy type pointers to use for spawning new
    ///         enemies.
    std::vector<int> killing_enemies(int time);


    /// True if all enemies have killed else false.
    bool done();

private:
    const int initial_money_;
    const int initial_lives_;

    /// Counter for how many enemies have already killed
    int enemies_killed_;
    std::vector<int> enemy_;
  
};