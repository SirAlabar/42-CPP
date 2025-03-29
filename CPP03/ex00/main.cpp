/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:20:26 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/29 18:20:27 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    std::cout << "\n===== CLAPTRAP BATTLE SIMULATION INITIATED =====\n" << std::endl;

    std::cout << ">> Deploying ClapTrap unit CT-1 to the battlefield..." << std::endl;
    ClapTrap clap1("CT-1");
    
    std::cout << "\n>> First combat engagement:" << std::endl;
    clap1.attack("Rogue Bandit");
    clap1.takeDamage(5);
    clap1.beRepaired(3);
    
    std::cout << "\n>> Clone unit arriving as backup..." << std::endl;
    ClapTrap clap2(clap1);
    clap2.attack("Skag Pack");
    
    std::cout << "\n>> CT-1 walks into an ambush!" << std::endl;
    clap1.takeDamage(8);
    std::cout << ">> Attempting to continue battle operations after critical damage:" << std::endl;
    clap1.attack("Psycho Bandit");
    clap1.beRepaired(5);
    
    std::cout << "\n>> Fresh unit CT-3 deployed for endurance testing..." << std::endl;
    ClapTrap clap3("CT-3");
    std::cout << ">> Performing continuous attack sequence to drain energy:" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        clap3.attack("Training Dummy");
    }
    
    std::cout << "\n>> Attempting actions after energy depletion:" << std::endl;
    clap3.attack("Boss Enemy");
    clap3.beRepaired(1);
    
    std::cout << "\n===== SIMULATION COMPLETE =====\n" << std::endl;
    
    return 0;
}