/*
 * productbatch.h
 *
 *  Created on: Apr 23, 2016
 *      Author: Taylor
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_
	#include "product.h"
#endif /* PRODUCT_H_ */

class ProductBatch {
 public:
	ProductBatch(Product* prod, unsigned long num, int rec);
	virtual ~ProductBatch();

	//mutators
	bool ship(unsigned long amount);
	bool expire_process(void);

	//accessors
	unsigned long num_in_stock(void) const;
	int received_on(void) const;
	int expires_on(void) const;
	Product& product(void) const;

 private:
	unsigned long m_num_in_stock;
	int m_received_on;
	int m_expires_on;
	Product& m_product;
};
