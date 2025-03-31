/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:54:48 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/29 19:54:49 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "AMateria.hpp"
// #include "Ice.hpp"
// #include "Cure.hpp"
// #include "Character.hpp"
// #include "MateriaSource.hpp"
// #include <iostream>

// int main() {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
    
//     ICharacter* me = new Character("me");
    
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
    
//     ICharacter* bob = new Character("bob");
    
//     me->use(0, *bob);
//     me->use(1, *bob);
    
//     std::cout << "\n--- Additional Tests ---\n" << std::endl;
    
//     tmp = src->createMateria("fire");
//     if (!tmp)
//         std::cout << "Could not create 'fire' materia (as expected)" << std::endl;
    
//     std::cout << "Unequipping materia at slot 0..." << std::endl;
//     me->unequip(0);
//     me->use(0, *bob);
    
//     std::cout << "Creating a copy of 'me' character..." << std::endl;
//     Character* meClone = new Character(*(Character*)me);
//     meClone->use(1, *bob);
    
//     delete bob;
//     delete me;
//     delete meClone;
//     delete src;
    
//     return 0;
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:54:48 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/29 19:54:49 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>
#include <unistd.h> 

#define RED "\033[31m"
#define BOLD_RED "\033[1;31m"
#define GREEN "\033[32m"
#define BOLD_GREEN "\033[1;32m"
#define CYAN "\033[36m"
#define BOLD_CYAN "\033[1;36m"
#define RESET "\033[0m"

void displayIceBolt() {
    std::cout << CYAN; 
    std::cout << "\n    *      ";
    usleep(100000);
    std::cout << "\n      *    ";
    usleep(100000);
    std::cout << "\n        *  ";
    usleep(100000);
    std::cout << "\n          *";
    usleep(100000);
    std::cout << "\n            *";
    usleep(100000);
    std::cout << "\n              *";
    usleep(100000);
    std::cout << "\n                *";
    usleep(100000);     
    std::cout << "\n                  ❄️";
    usleep(200000);
    std::cout << "\n                    💥";
    usleep(150000);
    std::cout << RESET << std::endl; 
}

void displayHealing() {
    std::cout << GREEN;
    std::cout << "\n   ✨   ";
    usleep(100000);
    std::cout << "\n    ✨  ";
    usleep(100000);
    std::cout << "\n     ✨ ";
    usleep(100000);
    std::cout << "\n      ✨";
    usleep(150000);
    std::cout << "\n       💚";
    usleep(200000);
    std::cout << RESET << std::endl; 
}

class EnhancedIce : public Ice {
public:
    EnhancedIce() : Ice() {}
    virtual ~EnhancedIce() {}

    virtual void use(ICharacter& target) {
        std::cout << CYAN << "* shoots an enhanced ice bolt at " << target.getName() << " *" << RESET <<std::endl;
        displayIceBolt();
    }
};

class EnhancedCure : public Cure {
public:
    EnhancedCure() : Cure() {}
    virtual ~EnhancedCure() {}

    virtual void use(ICharacter& target) {
        std::cout << GREEN << "* performs an enhanced healing on " << target.getName() << "'s wounds *" << RESET << std::endl;
        displayHealing();
    }
};

void testInventoryLimit(ICharacter* character) {
    std::cout << "\n=== Testing Inventory Limit ===\n" << std::endl;
    
    AMateria* materias[6];
    for (int i = 0; i < 6; i++) {
        if (i % 2 == 0)
            materias[i] = new Ice();
        else
            materias[i] = new Cure();
    }

    std::cout << "Trying to equip 6 materias to a character with 4 slots:" << std::endl;
    for (int i = 0; i < 6; i++) {
        std::cout << "Equipping materia " << i+1 << " (" << materias[i]->getType() << ")... ";
        character->equip(materias[i]);
        std::cout << "Done" << std::endl;
    }

    std::cout << "\nTesting all 6 equipped slots:" << std::endl;
    ICharacter* dummy = new Character("dummy");
    for (int i = 0; i < 6; i++) {
        std::cout << "Using slot " << i << ": ";
        character->use(i, *dummy);
    }

    for (int i = 4; i < 6; i++) {
        delete materias[i];
    }

    delete dummy;
}

void testMateriaCopying() {
    std::cout << "\n=== Testing Materia Copying ===\n" << std::endl;
    
    Ice* originalIce = new Ice();
    Cure* originalCure = new Cure();
    
    AMateria* clonedIce = originalIce->clone();
    AMateria* clonedCure = originalCure->clone();
    
    ICharacter* testChar1 = new Character("TestChar1");
    ICharacter* testChar2 = new Character("TestChar2");
    
    testChar1->equip(originalIce);
    testChar2->equip(clonedIce);
    testChar1->equip(originalCure);
    testChar2->equip(clonedCure);
    
    std::cout << "Using original Ice:" << std::endl;
    testChar1->use(0, *testChar2);
    
    std::cout << "Using cloned Ice:" << std::endl;
    testChar2->use(0, *testChar1);
    
    std::cout << "Using original Cure:" << std::endl;
    testChar1->use(1, *testChar1);
    
    std::cout << "Using cloned Cure:" << std::endl;
    testChar2->use(1, *testChar2);
    
    delete testChar1;
    delete testChar2;
}

void testUnequipAndEquip() {
    std::cout << "\n=== Testing Unequip and Equip ===\n" << std::endl;
    
    Character* character = new Character("Warrior");
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    
    std::cout << "Equipping Ice to slot 0..." << std::endl;
    character->equip(ice);
    std::cout << "Equipping Cure to slot 1..." << std::endl;
    character->equip(cure);
    
    ICharacter* target = new Character("Target");
    std::cout << "Using materias before unequipping:" << std::endl;
    character->use(0, *target); 
    character->use(1, *target);
    
    std::cout << "\nUnequipping materia from slot 0..." << std::endl;
    character->unequip(0);
    
    std::cout << "Using materias after unequipping:" << std::endl;
    character->use(0, *target);
    character->use(1, *target);
    
    std::cout << "\nRe-equipping Ice to slot 0..." << std::endl;
    character->equip(ice);
    
    std::cout << "Using materias after re-equipping:" << std::endl;
    character->use(0, *target);
    character->use(1, *target);
    
    character->unequip(0);
    character->unequip(1);
    
    delete target;
    delete character;
    delete ice;
    delete cure;
}

void testEnhancedMaterias() {
    std::cout << "\n=== Testing Enhanced Materias ===\n" << std::endl;
    
    Character* wizard = new Character("Wizard");
    Character* target = new Character("Enemy");
    
    AMateria* enhancedIce = new EnhancedIce();
    AMateria* enhancedCure = new EnhancedCure();
    
    wizard->equip(enhancedIce);
    wizard->equip(enhancedCure);
    
    std::cout << "Wizard casting enhanced spells:" << std::endl;
    wizard->use(0, *target);
    wizard->use(1, *wizard);
    
    delete wizard;
    delete target;
}

int main() {
    std::cout << "\033[1;35m=== Basic Tests from the Subject ===\033[0m" << std::endl;
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
    
    std::cout << "\n\033[1;35m=== Additional Tests ===\033[0m" << std::endl;
    
    Character* testChar = new Character("TestCharacter");
    testInventoryLimit(testChar);
    delete testChar;
    
    testMateriaCopying();
    
    testUnequipAndEquip();
    
    testEnhancedMaterias();
    
    std::cout << "\n\033[1;32mAll tests completed successfully!\033[0m" << std::endl;
    
    return (0);
}