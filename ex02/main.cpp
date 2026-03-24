#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap scav("Guardian");
	FragTrap frag("Blaster");

	scav.attack("enemy");
	scav.guardGate();

	std::cout << std::endl;

	frag.attack("target");
	frag.takeDamage(20);
	frag.beRepaired(10);
	frag.highFivesGuys();

	std::cout << std::endl;

	FragTrap copy(frag);
	copy.highFivesGuys();

	std::cout << std::endl;

	FragTrap assigned;
	assigned = frag;
	assigned.attack("another target");

	return (0);
}