/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:23:41 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/29 18:23:42 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Creating an array of animals ---" << std::endl;
    
    const int numAnimals = 4;
    AAnimal *animals[numAnimals];
    
    for (int i = 0; i < numAnimals; i++)
    {
        if (i < numAnimals / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    //AAnimal* abstract_animal = new AAnimal(); // This will not compile

    std::cout << "\n--- Making all animals make sounds ---" << std::endl;
    for (int i = 0; i < numAnimals; i++)
    {
        std::cout << "Animal " << i << " (type: " << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }
    
    std::cout << "\n--- Deleting all animals ---" << std::endl;
    for (int i = 0; i < numAnimals; i++)
        delete animals[i];
    
    std::cout << "\n--- Testing deep copy for Cat ---" << std::endl;
    Cat *originalCat = new Cat();
    originalCat->getBrain()->setIdea(0, "I want to catch mice");
    originalCat->getBrain()->setIdea(1, "I need a nap");
    
    Cat *copyCat = new Cat(*originalCat);
    
    std::cout << "\nOriginal cat's ideas:" << std::endl;
    std::cout << "Idea 0: " << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << originalCat->getBrain()->getIdea(1) << std::endl;
    
    std::cout << "\nCopy cat's ideas:" << std::endl;
    std::cout << "Idea 0: " << copyCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << copyCat->getBrain()->getIdea(1) << std::endl;
    
    std::cout << "\nChanging original cat's idea 0..." << std::endl;
    originalCat->getBrain()->setIdea(0, "I want to catch birds instead");
    
    std::cout << "\nOriginal cat's ideas after change:" << std::endl;
    std::cout << "Idea 0: " << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << originalCat->getBrain()->getIdea(1) << std::endl;
    
    std::cout << "\nCopy cat's ideas after original was changed:" << std::endl;
    std::cout << "Idea 0: " << copyCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << copyCat->getBrain()->getIdea(1) << std::endl;
    
    std::cout << "\n--- Testing assignment operator for Dog ---" << std::endl;
    Dog *originalDog = new Dog();
    originalDog->getBrain()->setIdea(0, "I want to play fetch");
    originalDog->getBrain()->setIdea(1, "I need a walk");
    
    Dog *assignedDog = new Dog();
    *assignedDog = *originalDog;
    
    std::cout << "\nOriginal dog's ideas:" << std::endl;
    std::cout << "Idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << originalDog->getBrain()->getIdea(1) << std::endl;
    
    std::cout << "\nAssigned dog's ideas:" << std::endl;
    std::cout << "Idea 0: " << assignedDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << assignedDog->getBrain()->getIdea(1) << std::endl;
    
    std::cout << "\nChanging original dog's idea 0..." << std::endl;
    originalDog->getBrain()->setIdea(0, "I want to chase squirrels instead");
    
    std::cout << "\nOriginal dog's ideas after change:" << std::endl;
    std::cout << "Idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << originalDog->getBrain()->getIdea(1) << std::endl;
    
    std::cout << "\nAssigned dog's ideas after original was changed:" << std::endl;
    std::cout << "Idea 0: " << assignedDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << assignedDog->getBrain()->getIdea(1) << std::endl;
    
    std::cout << "\n--- Cleaning up ---" << std::endl;
    delete originalCat;
    delete copyCat;
    delete originalDog;
    delete assignedDog;
    
    return (0);
}