#include <cmath>                                                      // abs(), pow()
#include <iomanip>                                                    // quoted()
#include <iostream>
#include <string>
#include <type_traits>                                                // is_floating_point_v, common_type_t
#include <utility>                                                    // move()

#include "Book.hpp"

/*******************************************************************************
**  Constructors, assignments, and destructor
*******************************************************************************/

// Default and Conversion Constructor
Book::Book( std::string title,  std::string author,  std::string isbn,  double price )
{
  _title = title;
  _author = author;
  _isbn = isbn;
  _price = price;
}




// Copy constructor
Book::Book( Book const & other )
{
  _title = other._title;
  _author = other._author;
  _isbn = other._isbn;
  _price = other._price;
}




// Copy Assignment Operator
Book & Book::operator=( Book const & rhs ) &
{
  if (this != & rhs){
    _title = rhs._title;
    _author = rhs._author;
    _isbn = rhs._isbn;
    _price = rhs._price;
  }
  return *this;
}



// Destructor
Book::~Book() noexcept
{
  
}








/*******************************************************************************
**  Accessors
*******************************************************************************/

// isbn() const
std::string const & Book::isbn() const &
{
  return _isbn;
}




// title() const
std::string const & Book::title() const &
{
  return _title;
}




// author() const
std::string const & Book::author() const &
{ 
  return _author;
}



// price() const
double Book::price() const &
{
  return _price;
}




// isbn()
std::string Book::isbn() &&
{
  return _isbn;
}




// title()
std::string Book::title() &&
{
  return _title;
}




// author()
std::string Book::author() &&
{
  return _author;
}








/*******************************************************************************
**  Modifiers
*******************************************************************************/

// isbn()
Book & Book::isbn( std::string newIsbn ) &
{
  _isbn = std::move(newIsbn);
  return *this;
}




// title()
Book & Book::title( std::string newTitle ) &
{
  _title = std::move(newTitle);
  return *this;
}




// author()
Book & Book::author( std::string newAuthor ) &
{
  _author = std::move(newAuthor);
  return *this;
}




// price()
Book & Book::price( double newPrice ) &
{
  _price = std::move(newPrice);
  return *this;
}



/*******************************************************************************
**  Relational Operators
*******************************************************************************/


// operator==
bool Book::operator==( const Book & rhs ) const noexcept
{
  if (_isbn == rhs._isbn && _title == rhs._title && _author == rhs._author && _price == rhs._price){
    return true;
  }
  return false;
}

// operator!=
bool Book::operator!=( const Book & rhs ) const noexcept
{
  if (_isbn != rhs._isbn || _title != rhs._title || _author != rhs._author || _price != rhs._price){
    return true;
  }
  return false;
}

// operator<
bool Book::operator<( const Book & rhs ) const noexcept
{
  if (_isbn < rhs._isbn){
    return true;
  }
  else if (_isbn == rhs._isbn){
    if (_author < rhs._author){
      return true;
    }
    else if (_author == rhs._author){
      if (_title < rhs._title){
        return true;
      }
      else if (_title == rhs._title){
        if (_price < rhs._price){
          return true;
        }
      }
    }
  }
  return false;
}

// operator<=
bool Book::operator<=( const Book & rhs ) const noexcept
{
  if (_isbn < rhs._isbn){
    return true;
  }
  else if (_isbn == rhs._isbn){
    if (_author < rhs._author){
      return true;
    }
    else if (_author == rhs._author){
      if (_title < rhs._title){
        return true;
      }
      else if (_title == rhs._title){
        if (_price <= rhs._price){
          return true;
        }
      }
    }
  }
  return false;
}

// operator>
bool Book::operator>( const Book & rhs ) const noexcept
{
  if (_isbn > rhs._isbn){
    return true;
  }
  else if (_isbn == rhs._isbn){
    if (_author > rhs._author){
      return true;
    }
    else if (_author == rhs._author){
      if (_title > rhs._title){
        return true;
      }
      else if (_title == rhs._title){
        if (_price > rhs._price){
          return true;
        }
      }
    }
  }
  return false;
}

// operator>=
bool Book::operator>=( const Book & rhs ) const noexcept
{
  if (_isbn > rhs._isbn){
    return true;
  }
  else if (_isbn == rhs._isbn){
    if (_author > rhs._author){
      return true;
    }
    else if (_author == rhs._author){
      if (_title > rhs._title){
        return true;
      }
      else if (_title == rhs._title){
        if (_price >= rhs._price){
          return true;
        }
      }
    }
  }
  return false;
}







/*******************************************************************************
**  Insertion and Extraction Operators
*******************************************************************************/

// operator>>
std::istream & operator>>( std::istream & stream, Book & book )
{
  char comma;
  stream >> std::quoted(book._isbn) ;
  stream >> comma;
  stream >> std::quoted(book._title);
  stream >> comma;
  stream >> std::quoted(book._author);
  stream >> comma;
  stream >> book._price;
  return stream;
}




// operator<<
std::ostream & operator<<( std::ostream & stream, const Book & book )
{
  char comma = ',';
  stream << std::quoted(book._isbn) << comma << std::quoted(book._title) << comma << std::quoted(book._author) << comma << book._price << "\n";
  return stream;
}
