/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:20:39 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/29 18:20:40 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "\n===== CLAPTRAP & SCAVTRAP BATTLE SIMULATION INITIATED =====\n" << std::endl;

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
    
    std::cout << "\n>> Deploying clone of ScavTrap ST-1..." << std::endl;
    ScavTrap scav2(scav1);
    scav2.attack("Badass Nomad");
    
    std::cout << "\n>> Testing proper constructor/destructor chain:" << std::endl;
    {
        std::cout << ">> Creating a temporary ScavTrap..." << std::endl;
        ScavTrap tempScav("TEMP-ST");
        std::cout << ">> Temporary ScavTrap will be destroyed upon exiting this scope..." << std::endl;
    }
    
    std::cout << "\n>> Original ScavTrap engaging in heavy combat:" << std::endl;
    scav1.takeDamage(80);
    scav1.attack("Boss Enemy");
    scav1.beRepaired(50);
    
    std::cout << "\n===== SIMULATION COMPLETE =====\n" << std::endl;
    
    return 0;
}