#include "Comodity.h"

Comodity::Comodity()
{
	//
}

Fragile::Fragile()
{
	price = 8;
	quantity = 0;
}

int Fragile::getPrice(int quan)
{
	return price * quan;
}


Book::Book()
{
	price = 2;
	quantity = 0;
}

int Book::getPrice(int quan)
{
	return price * quan;
}



Ordinary::Ordinary()
{
	price = 5;
	quantity = 0;
}

int Ordinary::getPrice(int quan)
{
	return price * quan;
}
