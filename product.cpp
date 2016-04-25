/*
 * product.cpp
 *
 *  Created on: Feb 8, 2016
 *      Author: Taylor Hoss, X432Z869
 *  Assignment: 1
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_
	#include "product.h"
#endif /* PRODUCT_H_ */


//constuctor: set the 3 identifying characteristics to their input values and set the stock to 0
Product::Product( int product_id, std::string product_name, Category category, unsigned int storage_life) :
					m_product_id(product_id), m_product_name(product_name), m_category(category), m_storage_life(storage_life)
{}

//destructor: nothing is dynamically allocated so this function does nothing
Product::~Product()
{
	for(int i = 0; i < m_batches.size(); i++)
	{
		delete m_batches.at(i);
	}
}

//transfer of products
//receive simply adds to the count
bool Product::receive(unsigned long amount, int day_of_receipt)
{
	m_batches.push_back( new ProductBatch(*this, amount, day_of_receipt) );

	return true;
}

bool Product::ship_from_batch(unsigned long amount, unsigned int b)
{
	try{
		m_batches.at(b)->ship(amount);
	}catch (const std::out_of_range& oor)
	{
		return false;
	}

	if( m_batches.at(b)->num_in_stock == 0 )
	{
		m_batches.erase(m_batches.begin() + b);
	}

	return true;
}

// accessors: each returns its specified value
int Product::product_id(void) const
{
	return m_product_id;
}

std::string Product::product_name(void) const
{
	return m_product_name;
}

Category Product::category(void) const
{
	return m_category;
}

unsigned int Product::storage_life(void) const
{
	return m_storage_life;
}

unsigned int Product::num_batches(void) const
{
	return m_batches.size();
}
	//returns m_batches[i] if i valid, else NULL
ProductBatch* Product::batch(unsigned int i) const
{
	try{
		return m_batches.at(i);
	}catch (const std::out_of_range& oor)
	{
		return NULL;
	}
}

// mutators: changing name or category, but not id
bool Product::set_name(std::string new_name)
{
	m_product_name = new_name;

	return true;
}

bool Product::set_category_and_storage(Category category, unsigned int days)
{
	if( ( category == NONPERISHABLE && days == 0 ) || ( category == PERISHABLE && days > 0 ))
	{
		m_category = category;
		m_storage_life = days;
		return true;
	}

	return false;
}
