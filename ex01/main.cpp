#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("Guardian");
	ScavTrap b("Watcher");

	a.attack("Watcher");
	b.takeDamage(20);
	b.beRepaired(10);
	b.guardGate();

	std::cout << std::endl;

	ScavTrap c(a);
	c.attack("target dummy");
	c.guardGate();

	std::cout << std::endl;

	ScavTrap d;
	d = b;
	d.attack("intruder");

	std::cout << std::endl;

	ScavTrap e("Broken");
	e.takeDamage(150);
	e.attack("nobody");
	e.beRepaired(10);

	std::cout << std::endl;

	ScavTrap f("LowBattery");
	for (int i = 0; i < 51; i++)
		f.attack("wall");

	return (0);
}