#ifndef COMODITY_H
#define COMODITY_H

class Comodity
{
	public:
		Comodity();
		virtual int getPrice(int quan) = 0;	// defining a pure virtual function //define for each child class
};

class Fragile : public Comodity
{
	public:
		int getPrice(int quan);
		Fragile();
	private:
		int price;
		int quantity;		
};

class Book : public Comodity
{
	public:
		int getPrice(int quan);
		Book();
	private:
		int price;
		int quantity;
};

class Ordinary : public Comodity{
	public:
		int getPrice(int quan);
		Ordinary();
	private:
		int price;
		int quantity;	
};

#endif
