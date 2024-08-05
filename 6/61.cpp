#include <iostream>
#include <string>
#include <cstddef>
#include <bits/stdc++.h>
// program takes book, book list classes according to their usual definitions
// book also has attributes :- max copies of the book available , and how many of them are currently available
// book copy class stores the info about a particular copy like its serial number , whether its available , and if not then which
// member id has the book . copy_list stores all the copies of all the books .
// member class is inherited by student and faculty .
// member class also has attribute :- how many books are currently issued by the member
// student and faculty have static data members which hold the max issues possible by a student and by a faculty because
// it remains same across all student objects or all faculty objects
// studentlist and faculty list are created
// transaction to perform a transaction if book is issued or returned
// transaction list to store all transactions
// when a book is returned the transaction object which was created during its issue is updated with the appropriate values
// rather than storing it in a new object
using namespace std;

class Book
{
private:
   int book_id;
   char title[31];
   char author[31];
   char publisher[31];
   double price;
   int total_copies;
   int available_copies;

public:
   // Default constructor
   Book() : book_id(0), price(0), total_copies(0), available_copies(0)
   {
      memset(title, 0, sizeof(title));
      memset(author, 0, sizeof(author));
      memset(publisher, 0, sizeof(publisher));
   }

   // Function to take input for book details
   void take_input()
   {
      cout << "Enter Book ID: ";
      cin >> book_id;
      cout << "Enter Title: ";
      cin.ignore();
      cin.getline(title, sizeof(title));
      cout << "Enter Author: ";
      cin.getline(author, sizeof(author));
      cout << "Enter Publisher: ";
      cin.getline(publisher, sizeof(publisher));
      cout << "Enter Price: ";
      cin >> price;
      cout << "Enter Total Copies: ";
      cin >> total_copies;
      available_copies = total_copies;
   }

   // Function to check if the book is available
   bool is_available()
   {
      return available_copies >= 1;
   }

   void issue()
   {
      if (available_copies > 0)
      {
         available_copies--;
      }
      else
      {
         cout << "No available copies of this book." << endl;
      }
   }

   void ret()
   {
      if (available_copies < total_copies)
      {
         available_copies++;
      }
      else
      {
         cout << "All copies of this book have been returned." << endl;
      }
   }

   int get_id()
   {
      return book_id;
   }

   int get_copies()
   {
      return total_copies;
   }

   int get_available_copies()
   {
      return available_copies;
   }

   // Function to display book details
   void display()
   {
      cout << "Book ID: " << book_id << endl;
      cout << "Title: " << title << endl;
      cout << "Author: " << author << endl;
      cout << "Publisher: " << publisher << endl;
      cout << "Price: $" << price << endl;
      cout << "Total Copies: " << total_copies << endl;
      cout << "Available Copies: " << available_copies << endl;
   }
};
class BookCopy
{
private:
   int book_id;
   int copy_no;
   int mem_id;
   bool status;
   char date_of_issue[11]; // Changed from string to char array

public:
   // Parameterized constructor
   BookCopy()
   {
      mem_id = 0;
      status = false;
      date_of_issue[0] = '\0';
   }

   BookCopy(int book_id, int copy_no, bool status, const char *date_of_issue, int id) // Changed from string to const char*
       : book_id(book_id), copy_no(copy_no), status(status), mem_id(id)
   {
      strncpy(this->date_of_issue, date_of_issue, sizeof(this->date_of_issue));
      this->date_of_issue[sizeof(this->date_of_issue) - 1] = '\0'; // Ensure null-termination
   }

   // Getter for book ID
   int getBookId()
   {
      return book_id;
   }

   // Getter for copy number
   int getCopyNo()
   {
      return copy_no;
   }

   // Getter for status
   bool getStatus()
   {
      return status;
   }

   // Getter for date of issue
   const char *getDateOfIssue() // Changed from string to const char*
   {
      return date_of_issue;
   }

   // Setter for book ID
   void setBookId(int newBookId)
   {
      book_id = newBookId;
   }

   int get_mem_id()
   {
      return mem_id;
   }

   void set_mem_id(int i)
   {
      mem_id = i;
   }

   // Setter for copy number
   void setCopyNo(int newCopyNo)
   {
      copy_no = newCopyNo;
   }

   // Setter for status
   void setStatus(bool newStatus)
   {
      status = newStatus;
   }

   // Setter for date of issue
   void setDateOfIssue(const char *newDateOfIssue) // Changed from string to const char*
   {
      strncpy(date_of_issue, newDateOfIssue, sizeof(date_of_issue));
      date_of_issue[sizeof(date_of_issue) - 1] = '\0'; // Ensure null-termination
   }
};

class BookList
{
private:
   char filename[31];
   // An array of Book objects

public:
   // Function to fill the array with book details
   BookList()
   {
   }
   BookList(char *fl)
   {
      strcpy(filename, fl);
   }
   void fill_list(Book ob)
   {
      fstream fi;
      fi.open(filename, ios::binary | ios::app);
      fi.write((char *)&ob, sizeof(ob));
      cout << "Added to file." << endl;
      fi.close();
   }

   // Function to check if a given book ID matches any book in the array
   Book match_book_id(int book_id_to_check)
   {
      fstream fi;
      fi.open(filename, ios::binary | ios::in);
      Book i;
      while (fi.read((char *)&i, sizeof(i)))
      {
         if (i.get_id() == book_id_to_check)
         {
            cout << "Found. " << endl;
            fi.close();
            return i;
         }
      }

      fi.close();
      // Return a reference to a default book with ID -1 when the book is not found
   }
   void edit(Book ob) {
    fstream file;
    file.open(filename, ios::binary | ios::in | ios::out);

    Book b; 
    while(file.read((char*)&b, sizeof(ob))) {
      if(b.get_id() == ob.get_id()) {
        int pos = file.tellg() - sizeof(ob);
        file.seekp(pos);
        file.write((char*)&ob, sizeof(ob));
        cout << "Book updated successfully!" << endl;
      }
    }

    file.close();
  }
   // Function to display the list of books
   void display_list()
   {
      fstream fi;
      fi.open(filename, ios::binary | ios::in);
      Book i;
      while (fi.read((char *)&i, sizeof(i)))
      {
         i.display();
      }
      fi.close();
   }
};
class copy_list
{
private:
   char filename[31];

public:
   copy_list()
   {
      // size = 0;
   }
   copy_list(char *fl)
   {
      strcpy(filename, fl);
   }

   void initialise(BookList &bookList)
   {
      Book ob;

      cout << "Enter details for Book "
           << ":" << endl;
      ob.take_input();
      bookList.fill_list(ob);
      int fin_size = ob.get_copies();
      fstream fi;
      fi.open(filename, ios::binary | ios::app);
      for (int i = 0; i < fin_size; i++)
      {

         BookCopy obj(ob.get_id(), i + 1, true, "", -1);
         // list[i] = obj;

         fi.write((char *)&obj, sizeof(obj));
      }
      fi.close();
      // size = fin_size;
      //  bookList
      //  list2.initialise(books[i]);
      //   list[i].initialise(books[i]);
   }
   int issue(char *date, int id, int book_id)
   {
      fstream fi;
      fi.open(filename, ios::binary | ios::in | ios::out);

      BookCopy obj;
      while (fi.read((char *)&obj, sizeof(obj)))
      {
         if (obj.getBookId() == book_id && obj.getStatus())
         {
            obj.setStatus(false);
            obj.setDateOfIssue(date);
            obj.set_mem_id(id);

            int pos = fi.tellg() - sizeof(obj);
            fi.seekp(pos, ios::beg);
            fi.write((char *)&obj, sizeof(obj));

            cout << "Copy " << obj.getCopyNo() << " issued to " << id << "\n";
            fi.close();
            return obj.getCopyNo();
         }
      }

      fi.close();
      return 0;
   }
   bool ret_book(int n, int id, char *dat, int book_id)
   {
      fstream fi;
      fi.open(filename, ios::binary | ios::in | ios::out);

      BookCopy obj;
      while (fi.read((char *)&obj, sizeof(obj)))
      {
         if (obj.getBookId() == book_id &&
             obj.get_mem_id() == id &&
             obj.getCopyNo() == n)
         {

            cout << "Book copy returned\n";
            obj.setStatus(true);
            obj.set_mem_id(-1);
            obj.setDateOfIssue(dat);

            int pos = fi.tellg() - sizeof(obj);
            fi.seekp(pos);
            fi.write((char *)&obj, sizeof(obj));

            fi.close();
            return true;
         }
      }

      fi.close();

      cout << "Book copy " << n << " was not issued to " << id << "\n";
      return false;
   }
   int issue_a_book(int id, int mem_id, char *date, BookList &book_list)
   {
      Book ob = book_list.match_book_id(id);
      if (ob.get_id() != 0)
      {

         if (ob.is_available())
         {
            ob.issue();
            book_list.edit(ob);

            int val = issue(date, mem_id, id);
            return val;
         }
      }
      return 0;
   }
   bool ret(int mem_id, int book_id, int copy, char *date, BookList &book_list)
   {
      Book ob = book_list.match_book_id(book_id);
      if (ob.get_id() != 0)
      {
         if (ret_book(copy, mem_id, date, book_id))
         {
            ob.ret();
            book_list.edit(ob);
            return true;
         }
         // list[i].issue(date,mem_id);
         // break;
      }

      return false;
   }
};

class Member
{
private:
   int member_id;
   char name[31];     // Changed from string to char array
   char email[31];    // Changed from string to char array
   char address[101]; // Changed from string to char array
   int num;

public:
   // Constructor
   Member()
   {
      member_id = 0;
      num = 0;
      name[0] = '\0';
      email[0] = '\0';
      address[0] = '\0';
   }

   Member(int id, char *n, char *e, char *a, int na) // Changed from string to const char*
       : member_id(id), num(na)
   {
      strncpy(name, n, sizeof(name));
      name[sizeof(name) - 1] = '\0'; // Ensure null-termination

      strncpy(email, e, sizeof(email));
      email[sizeof(email) - 1] = '\0'; // Ensure null-termination

      strncpy(address, a, sizeof(address));
      address[sizeof(address) - 1] = '\0'; // Ensure null-termination
   }

   // Function to input member details
   void input()
   {
      cout << "Enter Member ID: ";
      cin >> member_id;
      cin.ignore(); // Clear the input buffer
      cout << "Enter Name: ";
      cin.getline(name, sizeof(name));
      cout << "Enter Email: ";
      cin.getline(email, sizeof(email));
      cout << "Enter Address: ";
      cin.getline(address, sizeof(address));
      num = 0;
   }

   // Function to display member details
   void display()
   {
      cout << "Member ID: " << member_id << endl;
      cout << "Name: " << name << endl;
      cout << "Email: " << email << endl;
      cout << "Address: " << address << endl;
      cout << "number of books taken at present=" << num << endl;
   }

   // Getter functions
   int getMemberId()
   {
      return member_id;
   }

   const char *getName() // Changed from string to const char*
   {
      return name;
   }

   const char *getEmail() // Changed from string to const char*
   {
      return email;
   }

   const char *getAddress() // Changed from string to const char*
   {
      return address;
   }

   int getNum()
   {
      return num;
   }

   void issue()
   {
      num++;
   }

   void ret()
   {
      num--;
   }
};

class Student : public Member
{
public:
   static int max_issue;
   Student()
   {
   }
   Student(int id, char *&n, char *&e, char *&a, int &na)
       : Member(id, n, e, a, na) {}
};

int Student::max_issue = 2; // Initialize max_issue for students

class Faculty : public Member
{
public:
   static int max_issue;
   Faculty()
   {
   }

   Faculty(int id, char *n, char *e, char *a, int na)
       : Member(id, n, e, a, na) {}
};

int Faculty::max_issue = 5; // Initialize max_issue for faculty

#include <fstream>

class StudentList
{
private:
   Student def;
   char filename[31];

public:
   StudentList() {}

   StudentList(char *fl)
   {
      strcpy(filename, fl);
   }

   bool addStudent(Student s)
   {
      fstream file;
      file.open(filename, ios::binary | ios::app);
      file.write((char *)&s, sizeof(Student));
      file.close();
      return true;
   }

   void displayStudents()
   {
      fstream file;
      file.open(filename, ios::binary | ios::in);
      Student s;
      while (file.read((char *)&s, sizeof(Student)))
      {
         cout << "ID: " << s.getMemberId() << endl;
      }
      file.close();
   }

   Student isStudentIdPresent(int id)
   {
      fstream file;
      file.open(filename, ios::binary | ios::in);
      Student s;
      while (file.read((char *)&s, sizeof(Student)))
      {
         if (s.getMemberId() == id)
         {
            cout << "Member found\n";
            file.close();
            return s;
         }
      }
      file.close();
      return def;
   }
   void editStudent(Student s) {
  fstream file;
  file.open(filename, ios::binary | ios::in | ios::out);

  Student stud;
  while(file.read((char*)&stud, sizeof(s))) {
    if(stud.getMemberId() == s.getMemberId()) {
      int pos = file.tellg() - sizeof(s);
      file.seekp(pos);
      file.write((char*)&s, sizeof(s));
      cout << "Student updated successfully!" << endl;
    }
  }

  file.close();
}
};
class FacultyList
{

public:
   FacultyList() {}
   FacultyList(char* fl)
   {
      strcpy(filename,fl);
   }
   bool addFaculty(Faculty f)
   {
      fstream file;
      file.open(filename, ios::binary | ios::app);
      file.write((char *)&f, sizeof(Faculty));
      file.close();
      return true;
   }

   void displayFacultyMembers()
   {
      fstream file;
      file.open(filename, ios::binary | ios::in);
      Faculty f;
      while (file.read((char *)&f, sizeof(Faculty)))
      {
         cout << "ID: " << f.getMemberId() << endl;
      }
      file.close();
   }

   Faculty isFacultyIdPresent(int id)
   {
      fstream file;
      file.open(filename, ios::binary | ios::in);
      Faculty f;
      while (file.read((char *)&f, sizeof(Faculty)))
      {
         if (f.getMemberId() == id)
         {
            cout << "Member found\n";
            file.close();
            return f;
         }
      }
      file.close();
      return def;
   }
void editFaculty(Faculty f) {
  fstream file;
  file.open(filename, ios::binary | ios::in | ios::out);

  Faculty fac;
  while(file.read((char*)&fac, sizeof(f))) {
    if(fac.getMemberId() == f.getMemberId()) {
      int pos = file.tellg() - sizeof(f);
      file.seekp(pos);
      file.write((char*)&f, sizeof(f));
      cout << "Faculty updated successfully!" << endl;
    }
  }

  file.close();
}
private:
   char filename[31];
   Faculty def;
};

class Transaction
{
protected:
   char date[11];
   int member_id;
   int book_id;
   int serial_number;
   bool issue;

public:
   Transaction() {}

   Transaction(const char *d, int m_id, const int &b_id, int s_no, bool is_issue)
       : member_id(m_id), book_id(b_id), serial_number(s_no), issue(is_issue)
   {
      strcpy(date, d);
   }

   void display() const
   {
      cout << "Date: " << date << endl;
      cout << "Member ID: " << member_id << endl;
      cout << "Book ID: " << book_id << endl;
      cout << "Serial Number: " << serial_number << endl;
      cout << "Transaction Type: " << (issue ? "Issue" : "Return") << endl;
   }
   void setserial(int s)
   {
      serial_number = s;
   }
   int getserial()
   {
      return serial_number;
   }
   int get_mem_id()
   {
      return member_id;
   }
   int get_book_id()
   {
      return book_id;
   }
   void setdate(const char *d)
   {
      strcpy(date, d);
   }
   void setstatus(bool s)
   {
      issue = s;
   }
   char *get_date()
   {
      return date;
   }
};

class Issue : public Transaction
{
public:
   Issue() : Transaction() {}
   Issue(char *d, int m_id, const int &b_id, int s_no, bool is_issue)
       : Transaction(d, m_id, b_id, s_no, is_issue) {}
   bool canMemberIssueBook(int member_id, StudentList &studentList, FacultyList &facultyList)
   {
      Student ob = studentList.isStudentIdPresent(member_id);
      if (ob.getMemberId() != 0)
      {
         if (ob.getNum() < Student::max_issue)
         {
            cout << "Member eligible to be issued book\n";
            return true;
         }
      }
      Faculty obj = facultyList.isFacultyIdPresent(member_id);
      if (obj.getMemberId() != 0)
      {
         if (obj.getNum() < Faculty::max_issue)
         {
            cout << "Member eligible to be issued book\n";
            return true;
         }
      }
      cout << "couldnot be issued\n";
      return false; // Member not found
   }
   bool can_issue_book(int mem_id, StudentList &studentList, FacultyList &facultyList, int book_id, BookList &list1, copy_list &list2)
   {
      if (canMemberIssueBook(mem_id, studentList, facultyList) == false)
      {
         return false;
      }
      Student st = studentList.isStudentIdPresent(mem_id);
      Faculty fa = facultyList.isFacultyIdPresent(mem_id);

      // cout << "enter date";
      // cin >> date;
      int res = list2.issue_a_book(book_id, mem_id, date, list1);
      if (res)
      {
         setserial(res);
         if (st.getMemberId() != 0)
         {
            st.issue();
            studentList.editStudent(st);
         }
         else
         {
            fa.issue();
            facultyList.editFaculty(fa);
         }
         cout << "successfully issued\n";
         return true;
      }
      cout << "couldnot be issued\n";
      return false;
   }
};

class return_book : public Transaction
{
public:
   return_book() : Transaction() {}
   return_book(char *d, int m_id, const int &b_id, int s_no, bool is_issue)
       : Transaction(d, m_id, b_id, s_no, is_issue) {}

   bool ret_book(int book_id, int mem_id, int s, StudentList &studentList, FacultyList &facultyList, BookList &list1, copy_list &list2)
   {
      Student ob = studentList.isStudentIdPresent(member_id);
      if (ob.getMemberId() == 0)
      {
         Faculty obj = facultyList.isFacultyIdPresent(member_id);
         if (obj.getMemberId() == 0)
         {
            return false;
            cout << "couldnot be returned\n";
         }
      }

      if (list2.ret(mem_id, book_id, s, date, list1))
      {
         if (ob.getMemberId() == 0)
         {
            Faculty obj = facultyList.isFacultyIdPresent(member_id);
            cout << "book returned\n";
            obj.ret();
            facultyList.editFaculty(obj);
         }
         else
         {
            cout << "book returned\n";
            ob.ret();
            studentList.editStudent(ob);
         }

         return true;
      }
      else
      {
         cout << "book could not be returned\n";
         return false;
      }
   }
};
class Transaction_List
{

public:
   Transaction_List() {}

   bool add_issue(char *date, int memberId, int bookId, bool isIssue, StudentList &list1, FacultyList &list2, BookList &list3, copy_list &list4)
   {
      Issue transaction(date, memberId, bookId, 0, isIssue);

      if (transaction.can_issue_book(memberId, list1, list2, bookId, list3, list4))
      {
         fstream file;
         file.open("transactions.dat", ios::binary | ios::app);
         file.write((char *)&transaction, sizeof(Issue));
         file.close();
         return true;
      }
      else
      {
         return false;
      }
   }

   bool update_return(char *date, int memberId, int serial, int bookId, bool isIssue, StudentList &list1, FacultyList &list2, BookList &list3, copy_list &list4)
   {
      return_book transaction(date, memberId, bookId, serial, isIssue);

      if (transaction.ret_book(bookId, memberId, serial, list1, list2, list3, list4))
      {
         fstream file;
         file.open("transactions.dat", ios::binary | ios::in | ios::out);
         Issue t;
         while (file.read((char *)&t, sizeof(t)))
         {
            if (t.get_mem_id() == memberId && t.getserial() == serial && t.get_book_id() == bookId)
            {
               t.setdate(date);
               t.setstatus(0);

               int pos = file.tellg() - sizeof(t);
               file.seekp(pos);
               file.write((char *)&t, sizeof(t));
            }
         }
         file.close();
         return true;
      }
      else
      {
         return false;
      }
   }
};
class lms
{

public:
   static void driver()
   {
      StudentList list1("studentlist.dat");
      FacultyList list2("facultylist.dat");
      BookList list3("booklist.dat");
      copy_list list4("copylist.dat");
      Transaction_List tlist;
      Student obj;
      Faculty ob;
      char continueTransaction;

      continueTransaction = 'y';
      do
      {
         char ch;
         cout << " enter 1 to add member to student list , 2 to add member to faculty list , 3 to add book to book list,4 to transact \n";
         cin >> ch;

         switch (ch)
         {
         case '1':
            obj.input();
            list1.addStudent(obj);
            break;

         case '2':
            ob.input();
            list2.addFaculty(ob);
            break;

         case '3':
            list4.initialise(list3);
            break;

         case '4':
            char date[50];
            int memberId, bookId, serialNumber;
            bool isIssue;

            cout << "Enter Date (e.g., YYYY-MM-DD): ";
            cin >> date;

            cout << "Enter Member ID: ";
            cin >> memberId;

            cout << "Enter Book ID: ";
            cin >> bookId;

            // Determine if it's an issue or return transaction
            cout << "Is this an issue transaction? (1 for Issue / 0 for Return): ";
            cin >> isIssue;

            if (isIssue)
            {
               if (tlist.add_issue(date, memberId, bookId, isIssue, list1, list2, list3, list4))
               {
                  cout << "Book issued successfully." << endl;
               }
               else
               {
                  cout << "Failed to issue the book." << endl;
               }
            }
            else
            {
               cout << "Enter Serial Number: ";
               cin >> serialNumber;

               if (tlist.update_return(date, memberId, serialNumber, bookId, 0, list1, list2, list3, list4))
               {
                  cout << "Book returned successfully." << endl;
               }
               else
               {
                  cout << "Failed to return the book." << endl;
               }
            }

            break;
         }

         cout << "Do you want to perform another operation? (y/n): ";
         cin >> continueTransaction;

      } while (continueTransaction == 'y' || continueTransaction == 'Y');
   }
};
int main()
{
   lms::driver();
}
