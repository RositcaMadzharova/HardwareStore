/*
 * Hardware.cpp
 *
 *  Created on: May 16, 2017
 *      Author: Rossy
 */

#include "Hardware.h"



int Hardware::getId() const {
	return id;
}

void Hardware::setId(int id) {
	this->id = id;
}

const string& Hardware::getName() const {
	return name;
}

void Hardware::setName(const string& name) {
	this->name = name;
}

double Hardware::getPrice() const {
	return price;
}

void Hardware::setPrice(double price) {
	this->price = price;
}

int Hardware::getQuantity() const {
	return quantity;
}

Hardware::Hardware(int accountNumberValue, int id, string name, int quantity, double price) {
	setAccountNumber( accountNumberValue );
	setId(id);
	setName(name);
	setQuantity(quantity);
	setPrice(price);
}

Hardware::Hardware() {
	setAccountNumber(0);
	setId(0);
	setName("");
	setQuantity(0);
	setPrice(0);
}

void Hardware::setAccountNumber(int accountNumberValue) {
	 accountNumber = accountNumberValue;
}

int Hardware::getAccountNumber() const {
	return accountNumber;
}

void Hardware::setQuantity(int quantity) {
	this->quantity = quantity;
}

ostream& operator<<(ostream& os, const Hardware& obj){
	os << "Account number: " << obj.accountNumber << endl;
	os << "ID: " << obj.id << endl;
	os << "Name: " << obj.name << endl;
	os << "Quantity: " << obj.quantity << endl;
	os << "Price: " << obj.price << endl;
	return os;
}

Hardware::~Hardware() {
	// TODO Auto-generated destructor stub
}

