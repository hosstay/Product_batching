/*
 * productbatch.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: Taylor
 */

#include "productbatch.h"

ProductBatch::ProductBatch(Product* prod, unsigned long num, int rec):
													m_product(*prod), m_num_in_stock(num), m_received_on(rec)
{
	if(prod->category == PERISHABLE)
	{
		m_expires_on = m_received_on + prod->storage_life();
	}
	else
		m_expires_on = 0;

}

ProductBatch::~ProductBatch() {}

//ship subtracts from the count unless doing so would make the number in stock negative
bool ProductBatch::ship(unsigned long amount)
{

	//if num in stock after subtracting amount to ship is less than 0 or greater than a million, error
	if( (m_num_in_stock - amount) >= 0 && (m_num_in_stock - amount) <= 1000000)
	{
		m_num_in_stock -= amount;

		return true;
	}
	else
		return false;
}

bool ProductBatch::expire_process(void)
{
	if( m_num_in_stock > 0)
	{
		ship(m_num_in_stock);
		return true;
	}else
		return false;
}

unsigned long ProductBatch::num_in_stock(void) const
{
	return m_num_in_stock;
}

int ProductBatch::received_on(void) const
{
	return m_received_on;
}

int ProductBatch::expires_on(void) const
{
	return m_expires_on;
}

Product& ProductBatch::product(void) const
{
	return m_product;
}
