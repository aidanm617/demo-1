///////////////////////////////////////////////////////////////////////////////
// Book_test.cpp
//
// Unit tests for code declared in Book.hpp.
//
///////////////////////////////////////////////////////////////////////////////

#include <sstream>
#include <string>

#include "gtest/gtest.h"

#include "Book.hpp"

TEST(ConstructorsAndAssignment, Unused) {

  // default constructor
  {
    Book b;
    EXPECT_EQ("", b.title());
    EXPECT_EQ("", b.author());
    EXPECT_EQ("", b.isbn());
    EXPECT_EQ(0.0, b.price());
  }

  // conversion constructor
  {
    Book b("a", "b", "c", 8.0);
    EXPECT_EQ("a", b.title());
    EXPECT_EQ("b", b.author());
    EXPECT_EQ("c", b.isbn());
    EXPECT_EQ(8.0, b.price());
  }

  // assignment operator
  {
    Book b;
    b = Book("a", "b", "c", 8.0);
    EXPECT_EQ("a", b.title());
    EXPECT_EQ("b", b.author());
    EXPECT_EQ("c", b.isbn());
    EXPECT_EQ(8.0, b.price());
  }

  // copy constructor
  {
    Book b("a", "b", "c", 8.0);
    Book c(b);
    EXPECT_EQ("a", c.title());
    EXPECT_EQ("b", c.author());
    EXPECT_EQ("c", c.isbn());
    EXPECT_EQ(8.0, c.price());
  }  
}

TEST(Accessors, Unused) {
  {
    Book b;
    EXPECT_EQ("", b.title());
    EXPECT_EQ("", b.author());
    EXPECT_EQ("", b.isbn());
    EXPECT_EQ(0.0, b.price());
  }

  {
    Book b("a", "b", "c", 8.0);
    EXPECT_EQ("a", b.title());
    EXPECT_EQ("b", b.author());
    EXPECT_EQ("c", b.isbn());
    EXPECT_EQ(8.0, b.price());
  }
}

TEST(Modifiers, Unused) {
  // modifiers
  Book b("a", "b", "c", 8.0);
  EXPECT_EQ("a", b.title());
  EXPECT_EQ("b", b.author());
  EXPECT_EQ("c", b.isbn());
  EXPECT_EQ(8.0, b.price());

  b.title("x");
  EXPECT_EQ("x", b.title());
  EXPECT_EQ("b", b.author());
  EXPECT_EQ("c", b.isbn());
  EXPECT_EQ(8.0, b.price());

  b.author("y");
  EXPECT_EQ("x", b.title());
  EXPECT_EQ("y", b.author());
  EXPECT_EQ("c", b.isbn());
  EXPECT_EQ(8.0, b.price());

  b.isbn("z");
  EXPECT_EQ("x", b.title());
  EXPECT_EQ("y", b.author());
  EXPECT_EQ("z", b.isbn());
  EXPECT_EQ(8.0, b.price());

  b.price(16.0);
  EXPECT_EQ("x", b.title());
  EXPECT_EQ("y", b.author());
  EXPECT_EQ("z", b.isbn());
  EXPECT_EQ(16.0, b.price());

  // returns reference to self
  EXPECT_EQ(&b, &b.title("a2"));
  EXPECT_EQ(&b, &b.author("b2"));
  EXPECT_EQ(&b, &b.isbn("c2"));
  EXPECT_EQ(&b, &b.price(1.0));
  EXPECT_EQ("a2", b.title());
  EXPECT_EQ("b2", b.author());
  EXPECT_EQ("c2", b.isbn());
  EXPECT_EQ(1.0, b.price());

  // chaining
  EXPECT_EQ(&b, &(b.title("a3").author("b3").isbn("c3").price(-1.0)));
  EXPECT_EQ("a3", b.title());
  EXPECT_EQ("b3", b.author());
  EXPECT_EQ("c3", b.isbn());
  EXPECT_EQ(-1.0, b.price());
}

TEST(RelationalOperators, Unused) {

  Book b("Goodnight Moon", "Margaret Wise Brown", "9780064430173", 8.99),
    copy(b);

  const std::string different("different");
  const double different_price(1.0);

  // ==
  EXPECT_TRUE(b == b);
  EXPECT_TRUE(b == copy);
  EXPECT_TRUE(b == Book(b.title(), b.author(), b.isbn(), b.price()));
  EXPECT_FALSE(b == Book(different, b.author(), b.isbn(), b.price()));
  EXPECT_FALSE(b == Book(b.title(), different, b.isbn(), b.price()));
  EXPECT_FALSE(b == Book(b.title(), b.author(), different, b.price()));
  EXPECT_FALSE(b == Book(b.title(), b.author(), b.isbn(), different_price));

  // !=
  EXPECT_FALSE(b != b);
  EXPECT_FALSE(b != copy);
  EXPECT_FALSE(b != Book(b.title(), b.author(), b.isbn(), b.price()));
  EXPECT_TRUE(b != Book(different, b.author(), b.isbn(), b.price()));
  EXPECT_TRUE(b != Book(b.title(), different, b.isbn(), b.price()));
  EXPECT_TRUE(b != Book(b.title(), b.author(), different, b.price()));
  EXPECT_TRUE(b != Book(b.title(), b.author(), b.isbn(), different_price));

  // <
  EXPECT_FALSE(b < copy);
  EXPECT_FALSE(b < Book(b.title(), b.author(), b.isbn(), b.price()));
  EXPECT_TRUE(b < Book("Z", b.author(), b.isbn(), b.price()));
  EXPECT_TRUE(b < Book(b.title(), "Z", b.isbn(), b.price()));
  EXPECT_TRUE(b < Book(b.title(), b.author(), "9999999999", b.price()));
  EXPECT_TRUE(b < Book(b.title(), b.author(), b.isbn(), 1000.0));

  // <=
  EXPECT_TRUE(b <= copy);
  EXPECT_TRUE(b <= Book(b.title(), b.author(), b.isbn(), b.price()));
  EXPECT_TRUE(b <= Book("Z", b.author(), b.isbn(), b.price()));
  EXPECT_TRUE(b <= Book(b.title(), "Z", b.isbn(), b.price()));
  EXPECT_TRUE(b <= Book(b.title(), b.author(), "9999999999", b.price()));
  EXPECT_TRUE(b <= Book(b.title(), b.author(), b.isbn(), 1000.0));

  // >
  EXPECT_FALSE(b > copy);
  EXPECT_FALSE(b > Book(b.title(), b.author(), b.isbn(), b.price()));
  EXPECT_TRUE(Book("Z", b.author(), b.isbn(), b.price()) > b);
  EXPECT_TRUE(Book(b.title(), "Z", b.isbn(), b.price()) > b);
  EXPECT_TRUE(Book(b.title(), b.author(), "9999999999", b.price()) > b);
  EXPECT_TRUE(Book(b.title(), b.author(), b.isbn(), 1000.0) > b);

  // >=
  EXPECT_TRUE(b >= copy);
  EXPECT_TRUE(b >= Book(b.title(), b.author(), b.isbn(), b.price()));
  EXPECT_TRUE(Book("Z", b.author(), b.isbn(), b.price()) >= b);
  EXPECT_TRUE(Book(b.title(), "Z", b.isbn(), b.price()) >= b);
  EXPECT_TRUE(Book(b.title(), b.author(), "9999999999", b.price()) >= b);
  EXPECT_TRUE(Book(b.title(), b.author(), b.isbn(), 1000.0) >= b);

  // orders by...
  // ISBN first
  EXPECT_TRUE(Book("B", "B", "A", 2.0) < Book("A", "A", "B", 1.0));
  // then author
  EXPECT_TRUE(Book("B", "A", "T", 2.0) < Book("A", "B", "T", 1.0));
  // then title
  EXPECT_TRUE(Book("A", "T", "T", 2.0) < Book("B", "T", "T", 1.0));
  // then price
  EXPECT_TRUE(Book("T", "T", "T", 1.0) < Book("T", "T", "T", 2.0));
}

TEST(StreamInsertion, Unused) {

  // returns reference to stream
  {
    std::stringstream ss;
    EXPECT_EQ(&ss, &(ss << Book()));
  }

  {
    std::stringstream ss;
    ss << Book("title", "author", "isbn", 1.0);
    EXPECT_EQ("\"isbn\",\"title\",\"author\",1\n", ss.str());
  }

  {
    std::stringstream ss;
    ss << Book();
    EXPECT_EQ("\"\",\"\",\"\",0\n", ss.str());
  }

  {
    std::stringstream ss;
    ss << Book("Goodnight Moon", "Margaret Wise Brown", "9780064430173", 8.99);
    EXPECT_EQ("\"9780064430173\",\"Goodnight Moon\",\"Margaret Wise Brown\",8.99\n", ss.str());
  }

  // chained insertion
  {
    std::stringstream ss;
    ss << Book("A", "B", "123", 1.0)
       << Book("D", "E", "456", 2.0)
       << Book("G", "H", "789", 3.0);
    EXPECT_EQ("\"123\",\"A\",\"B\",1\n"
              "\"456\",\"D\",\"E\",2\n"
              "\"789\",\"G\",\"H\",3\n",
              ss.str());
  }
}

TEST(StreamExtraction, Unused) {
  // returns reference to stream
  {
    std::stringstream ss("\"\",\"\",\"\",0\n");
    Book b;
    EXPECT_EQ(&ss, &(ss >> b));
  }

  // opposite of insertion examples above

  {
    std::stringstream ss("\"isbn\",\"title\",\"author\",1\n");
    Book b;
    ss >> b;
    EXPECT_EQ("isbn", b.isbn());
    EXPECT_EQ("title", b.title());
    EXPECT_EQ("author", b.author());
    EXPECT_EQ(1.0, b.price());
  }

  {
    std::stringstream ss("\"\",\"\",\"\",0\n");
    Book b;
    ss >> b;
    EXPECT_EQ("", b.isbn());
    EXPECT_EQ("", b.title());
    EXPECT_EQ("", b.author());
    EXPECT_EQ(0.0, b.price());
  }

  {
    std::stringstream ss("\"9780064430173\",\"Goodnight Moon\",\"Margaret Wise Brown\",8.99\n");
    Book b;
    ss >> b;
    EXPECT_EQ("9780064430173", b.isbn());
    EXPECT_EQ("Goodnight Moon", b.title());
    EXPECT_EQ("Margaret Wise Brown", b.author());
    EXPECT_EQ(8.99, b.price());
  }

  {
    std::stringstream ss("\"123\",\"A\",\"B\",1\n"
      "\"456\",\"D\",\"E\",2\n"
      "\"789\",\"G\",\"H\",3\n");
    Book a, b, c;
    ss >> a >> b >> c;

    EXPECT_EQ("123", a.isbn());
    EXPECT_EQ("A", a.title());
    EXPECT_EQ("B", a.author());
    EXPECT_EQ(1, a.price());

    EXPECT_EQ("456", b.isbn());
    EXPECT_EQ("D", b.title());
    EXPECT_EQ("E", b.author());
    EXPECT_EQ(2, b.price());

    EXPECT_EQ("789", c.isbn());
    EXPECT_EQ("G", c.title());
    EXPECT_EQ("H", c.author());
    EXPECT_EQ(3, c.price());
  }

}

