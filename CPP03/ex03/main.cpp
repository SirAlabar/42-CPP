#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "\n===== CLAPTRAP, SCAVTRAP, FRAGTRAP & DIAMONDTRAP BATTLE SIMULATION INITIATED =====\n" << std::endl;

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
    
    std::cout << "\n>> Deploying DiamondTrap unit DT-1 for elite combat..." << std::endl;
    DiamondTrap diamond1("DT-1");
    
    std::cout << "\n>> DiamondTrap engaging enemies:" << std::endl;
    diamond1.attack("Mega Boss");
    diamond1.takeDamage(40);
    diamond1.beRepaired(20);
    diamond1.guardGate();
    diamond1.highFivesGuys();
    diamond1.whoAmI();
    
    std::cout << "\n>> Testing proper constructor/destructor chain:" << std::endl;
    {
        std::cout << ">> Creating a temporary DiamondTrap..." << std::endl;
        DiamondTrap tempDiamond("TEMP-DT");
        std::cout << ">> Temporary DiamondTrap will be destroyed upon exiting this scope..." << std::endl;
    }
    
    std::cout << "\n>> Testing copy constructor for DiamondTrap:" << std::endl;
    DiamondTrap diamond2(diamond1);
    diamond2.attack("Ultra Boss");
    diamond2.whoAmI();
    
    std::cout << "\n>> Testing assignment operator for DiamondTrap:" << std::endl;
    DiamondTrap diamond3;
    diamond3 = diamond1;
    diamond3.attack("Supreme Guard");
    diamond3.whoAmI();
    
    std::cout << "\n===== SIMULATION COMPLETE =====\n" << std::endl;
    
    return (0);
}