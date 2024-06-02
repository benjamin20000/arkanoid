#include"blocks/block.hpp"
#include"setting.hpp"
#include"sprite.hpp"
#include<vector>

class Manage_Blocks
{

public:
    Manage_Blocks(Setting& setting, sf::RenderWindow& window);
    ~Manage_Blocks();
    void creat_blocks();
    void disply_vector();
    
    sf::Sprite* get_sprite();
    std::vector<Block> m_blocks_vector{};    
private:
    Setting& m_setting;
    sf::RenderWindow& m_window;    
};



