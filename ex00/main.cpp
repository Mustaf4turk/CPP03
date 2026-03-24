#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Atlas");
	ClapTrap b("Bolt");

	a.attack("Bolt");
	b.takeDamage(3);
	b.beRepaired(2);

	std::cout << std::endl;

	ClapTrap c(a);
	c.attack("training dummy");

	std::cout << std::endl;

	ClapTrap d;
	d = b;
	d.beRepaired(4);

	std::cout << std::endl;

	ClapTrap e("Fragile");
	e.takeDamage(15);
	e.attack("nobody");
	e.beRepaired(5);

	std::cout << std::endl;

	ClapTrap f("Tired");
	for (int i = 0; i < 11; i++)
		f.attack("wall");

	return (0);
}