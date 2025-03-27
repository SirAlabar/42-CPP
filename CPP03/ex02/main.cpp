#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "\n===== CLAPTRAP, SCAVTRAP & FRAGTRAP BATTLE SIMULATION INITIATED =====\n" << std::endl;

    std::cout << ">> Deploying ClapTrap unit CT-1 to the battlefield..." << std::endl;
    ClapTrap clap1("CT-1");
    
    std::cout << "\n>> First combat engagement:" << std::endl;
    clap1.attack("Rogue Bandit");
    clap1.takeDamage(5);
    clap1.beRepaired(3);
    
    std::cout << "\n>> Deploying ScavTrap unit ST-1 to reinforce..." << std::endl;
    ScavTrap scav1("ST-1");
    
    std::cout << "\n>> ScavTrap engaging enemies:" << std::endl;
    scav1.attack("Elite Psycho");
    scav1.takeDamage(30);
    scav1.beRepaired(15);
    scav1.guardGate();
    
    std::cout << "\n>> Deploying FragTrap unit FT-1 for heavy combat..." << std::endl;
    FragTrap frag1("FT-1");
    
    std::cout << "\n>> FragTrap engaging enemies:" << std::endl;
    frag1.attack("Boss Enemy");
    frag1.takeDamage(50);
    frag1.beRepaired(25);
    frag1.highFivesGuys();
    
    std::cout << "\n>> Testing proper constructor/destructor chain:" << std::endl;
    {
        std::cout << ">> Creating a temporary FragTrap..." << std::endl;
        FragTrap tempFrag("TEMP-FT");
        std::cout << ">> Temporary FragTrap will be destroyed upon exiting this scope..." << std::endl;
    }
    
    std::cout << "\n>> Testing copy constructor for FragTrap:" << std::endl;
    FragTrap frag2(frag1);
    frag2.attack("Mini Boss");
    frag2.highFivesGuys();
    
    std::cout << "\n>> Testing assignment operator for FragTrap:" << std::endl;
    FragTrap frag3;
    frag3 = frag1;
    frag3.attack("Elite Guard");
    
    std::cout << "\n===== SIMULATION COMPLETE =====\n" << std::endl;
    
    return (0);
}