/*
 * product.hpp
 *
 *  Created on: Feb 8, 2016
 *      Author: Taylor Hoss, X432Z869
 *  Assignment: 1
 */

#ifndef STRING_
#define STRING_
	#include <string>
#endif /* STRING_ */

#ifndef VECTOR_
#define VECTOR_
	#include <vector>
#endif /* VECTOR_ */

#ifndef PRODUCTBATCH_H_
#define PRODUCTBATCH_H_
	#include "productbatch.h"
#endif /* PRODUCTBATCH_H_ */

//creating enum category for perishability
enum Category { PERISHABLE, NONPERISHABLE };

class Product
{
 public:
	//constuctor: set the 3 identifying characteristics to their input values and set the stock to 0
	Product( int product_id, std::string product_name, Category category, unsigned int storage_life);

	//destructor: nothing is dynamically allocated so this function does nothing
	~Product();

	//transfer of products
	bool receive(unsigned long amount, int day_of_receipt);
	bool ship_from_batch(unsigned long amount, unsigned int b);

	//accessors: each returns its value
	int product_id(void) const;
	std::string product_name(void) const;
	Category category(void) const;
	unsigned int storage_life(void) const;
	//returns the size of m_batches
	unsigned int num_batches(void) const;
	//returns m_batches[i] if i valid, else NULL
	ProductBatch* batch(unsigned int i) const;

	//mutators: changing name or category, but not id
	bool set_name(std::string new_name);
	bool set_category_and_storage(Category category, unsigned int days);

 private:
	//data members: each holds its corresponding product information
	int m_product_id;
	std::string m_product_name;
	Category m_category;
	unsigned int m_storage_life;
	std::vector<ProductBatch*> m_batches;
};
