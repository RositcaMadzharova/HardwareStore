/*
 * Hardware.h
 *
 *  Created on: May 16, 2017
 *      Author: Rossy
 */

#ifndef HARDWARE_H_
#define HARDWARE_H_
#include <string>
#include <iostream>
using std::string;
using std::ostream;
using std::endl;

class Hardware {
private:
	int accountNumber;
	int id;
	string name;
	int quantity;
	double price;

public:
	Hardware();
	Hardware(int accountNumberValue, int id, string name, int quantity, double price);
	void setAccountNumber( int );
	int getAccountNumber() const;
	virtual ~Hardware();
	int getId() const;
	void setId(int id);
	const string& getName() const;
	void setName(const string& name);
	double getPrice() const;
	void setPrice(double price);
	int getQuantity() const;
	void setQuantity(int quantity);
	friend ostream& operator<<(ostream& os, const Hardware& obj);
};

#endif /* HARDWARE_H_ */
