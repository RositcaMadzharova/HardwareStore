//============================================================================
// Name        : mainHardware.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::ios;
using std::left;
using std::right;
using std::showpoint;

#include <fstream>
using std::ofstream;
using std::ifstream;
using std::ostream;
using std::fstream;

#include <iomanip>
using std::setw;
using std::setprecision;

#include <cstdlib>
using std::exit;
#include "Hardware.h"

int enterChoice();
void createTextFile( ifstream& );
void updateRecord( fstream& );
void newRecord( ifstream&, ofstream& );
void deleteRecord( fstream& );
void outputLine( ostream&, const Hardware & );
int getAccount( const char * const );
void initialize(ofstream&);

enum Choices { PRINT = 1, UPDATE, NEW, DELETE, END };

int main() {



		ofstream outTools( "tools.dat", ios::binary );
	   ifstream inTools( "tools.dat", ios::in|ios::binary );
	   initialize(outTools);

	   newRecord(inTools, outTools);

		createTextFile(inTools);
/*
	   int choice;

	      while ( ( choice = enterChoice() ) != END )
	      {
	         switch ( choice )
	         {
	            case PRINT:
	               createTextFile( inOutTools );
	               break;
	            case UPDATE:
	               updateRecord( inOutTools );
	               break;
	            case NEW:
	               newRecord( inOutTools );
	               break;
	            case DELETE:
	               deleteRecord( inOutTools );
	               break;
	            default:
	               cerr << "Incorrect choice" << endl;
	               break;
	         }

	         inOutTools.clear();
	      }

*/


















	return 0;
}

int enterChoice()
{

   cout << "\nEnter your choice" << endl
      << "1 - store a formatted text file of accounts" << endl
      << "    called \"print.txt\" for printing" << endl
      << "2 - update an account" << endl
      << "3 - add a new account" << endl
      << "4 - delete an account" << endl
      << "5 - end program\n? ";

   int menuChoice;
   cin >> menuChoice;
   return menuChoice;
}

void createTextFile( ifstream& readFromFile ){
	 ofstream outTools( "tools.txt", ios::out );
	   if ( !outTools )
	   {
	      cerr << "File could not be created." << endl;
	      exit( 1 );
	   } // end if

	   outTools << left << setw( 10 ) << "ID" << setw( 16 )
	      << "Name" << setw( 11 ) << "Quantity" << right
	      << setw( 10 ) << "Price" << endl;

	   readFromFile.seekg( 0 );
	   readFromFile.clear();


	   Hardware tools;

	   while ( !readFromFile.eof() )
	   {
		   readFromFile.read( reinterpret_cast< char * >( &tools ), sizeof( Hardware ) );
	      //if ( tools.getAccountNumber() != 0 )
	         outputLine( outTools, tools );
	   }
	}



void updateRecord( fstream& updateFile ){
	 int accountNumber = getAccount( "Enter account to update" );

	   updateFile.seekg( ( accountNumber - 1 ) * sizeof( Hardware ) );

	   Hardware tools;
	   updateFile.read( reinterpret_cast< char * >( &tools ),
	      sizeof( Hardware ) );

	   if ( tools.getAccountNumber() != 0 )
	   {
	      outputLine( cout, tools );

	      cout << "\nEnter charge (+) or payment (-): ";
	      double transaction;
	      cin >> transaction;

	      double oldPrice = tools.getPrice();
	      tools.setPrice( oldPrice + transaction );
	      outputLine( cout, tools );

	      updateFile.seekp( ( accountNumber - 1 ) * sizeof(Hardware ) );

	      updateFile.write( reinterpret_cast< const char * >( &tools ),
	         sizeof( Hardware ) );
	   }
	   else
	      cerr << "Account #" << accountNumber
	         << " has no information." << endl;
}


void newRecord( ifstream& read, ofstream& write ){

	/*

	 read.clear();
	   read.seekg( ( accountNumber - 1 ) * sizeof( Hardware ) );

	   read.read( reinterpret_cast< char * >( &tools ), sizeof(Hardware ) );

	   if ( tools.getAccountNumber() == 0 )
	   {*/
		   int id;
		   string name;
		   int quantity;
		   double price;

	int accountNumber = getAccount( "Enter new account number" );
	   Hardware tools;
	      cout << "Enter ID, Name, Quantity, Price\n? ";
	      cin >> setw( 15 ) >> id;
	      cin >> setw( 10 ) >> name;
	      cin >> setw( 15 ) >> quantity;
	      cin >> setw( 10 ) >> price;

	      tools.setId(id);
	      tools.setName(name);
	      tools.setQuantity(quantity);
	      tools.setPrice(price);
	      tools.setAccountNumber( accountNumber );
	      cout << tools;

	      write.clear();
	      write.seekp( ( accountNumber - 1 ) * sizeof( Hardware ) );
	      write.write( reinterpret_cast< const char * >( &tools ), sizeof( Hardware ) );
	  /* }
	   else
	      cerr << "Account #" << accountNumber
	         << " already contains information." << endl;*/
}

void deleteRecord( fstream &deleteFromFile )
{
   int accountNumber = getAccount( "Enter account to delete" );

   deleteFromFile.seekg( ( accountNumber - 1 ) * sizeof( Hardware ) );

   Hardware tools;
   deleteFromFile.read( reinterpret_cast< char * >( &tools ),
      sizeof( Hardware ) );

   if ( tools.getAccountNumber() != 0 )
   {
      Hardware blankTools;

      deleteFromFile.seekp( ( accountNumber - 1 ) *
         sizeof( Hardware ) );

      deleteFromFile.write(
         reinterpret_cast< const char * >( &blankTools ),
         sizeof( Hardware ) );

      cout << "Account #" << accountNumber << " deleted.\n";
   }
   else
      cerr << "Account #" << accountNumber << " is empty.\n";
}

void outputLine( ostream &output, const Hardware &tools )
{
   output << left << setw( 10 ) << tools.getId()
      << setw( 16 ) << tools.getName()
      << setw( 11 ) << tools.getQuantity()
      << setw( 10 ) << setprecision( 2 ) << right << fixed
      << showpoint << tools.getPrice() << endl;
}

int getAccount( const char * const prompt )
{
   int accountNumber;

   do
   {
      cout << prompt << " (1 - 100): ";
      cin >> accountNumber;
   } while ( accountNumber < 1 || accountNumber > 100 );

   return accountNumber;
}

void initialize(ofstream& outTools){
		Hardware blankTools;

		 for ( int i = 0; i < 100; i++ )
		      outTools.write( reinterpret_cast< const char * >( &blankTools ),  sizeof( Hardware ) );

}
