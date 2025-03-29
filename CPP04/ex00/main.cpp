/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:21:59 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/29 18:22:00 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() 
{
    std::cout << "=== Proper polymorphism test ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "J Type: " << j->getType() << std::endl;
    std::cout << "I Type: " << i->getType() << std::endl;
    
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    
    delete meta;
    delete j;
    delete i;
    
    std::cout << "\n=== Wrong animal hierarchy test (no polymorphism) ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << "WrongCat Type: " << wrongCat->getType() << std::endl;
    
    wrongCat->makeSound();
    wrongMeta->makeSound();
    
    std::cout << "\n=== Additional tests with stack-allocated objects ===" << std::endl;
    Animal regularAnimal;
    Dog regularDog;
    Cat regularCat;
    
    std::cout << "Regular Animal Type: " << regularAnimal.getType() << std::endl;
    std::cout << "Regular Dog Type: " << regularDog.getType() << std::endl;
    std::cout << "Regular Cat Type: " << regularCat.getType() << std::endl;
    
    regularAnimal.makeSound();
    regularDog.makeSound();
    regularCat.makeSound();
    
    delete wrongMeta;
    delete wrongCat;
    
    return (0);
}