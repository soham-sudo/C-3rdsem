#include <iostream>
#include <string>
#include <cstddef>
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
   string title;
   string author;
   string publisher;
   double price;
   int total_copies;
   int available_copies;

public:
   // Default constructor
   Book() : book_id(0), price(0), total_copies(0), available_copies(0) {}

   // Function to take input for book details
   void take_input()
   {
      cout << "Enter Book ID: ";
      cin >> book_id;
      cout << "Enter Title: ";
      cin.ignore(); // Clear the input buffer
      getline(cin, title);
      cout << "Enter Author: ";
      getline(cin, author);
      cout << "Enter Publisher: ";
      getline(cin, publisher);
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
      available_copies--;
   }
   void ret()
   {
      available_copies++;
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
   string date_of_issue;

public:
   // Parameterized constructor
   BookCopy()
   {
   }
   BookCopy(int book_id, int copy_no, bool status, string date_of_issue, int id)
       : book_id(book_id), copy_no(copy_no), status(status), date_of_issue(date_of_issue) { mem_id = id; }

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
   string getDateOfIssue()
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
   void setDateOfIssue(string newDateOfIssue)
   {
      date_of_issue = newDateOfIssue;
   }
};
class BookList
{
private:
   Book books[5];
   int size;
   // An array of Book objects

public:
   // Function to fill the array with book details
   BookList()
   {
      size = 0;
   }
   void fill_list(Book ob)
   {
      books[size] = ob;
      size++;
   }

   // Function to check if a given book ID matches any book in the array
   Book &match_book_id(int book_id_to_check)
   {
      for (int i = 0; i < size; i++)
      {
         if (books[i].get_id() == book_id_to_check)
         {
            cout << "Book found\n";
            return books[i];
         }
      }

      // Return a reference to a default book with ID -1 when the book is not found
   }

   // Function to display the list of books
   void display_list()
   {
      cout << "Book List:" << endl;
      for (int i = 0; i < size; i++)
      {
         cout << "Book " << i + 1 << ":" << endl;
         books[i].display();
         cout << endl;
      }
   }
};
class copy_list
{
private:
   BookCopy list[1000];
   int size;

public:
   copy_list()
   {

      size = 0;
   }

   void initialise(BookList &bookList)
   {
      Book ob;

      cout << "Enter details for Book "
           << ":" << endl;
      ob.take_input();
      bookList.fill_list(ob);
      int fin_size = size + ob.get_copies();

      for (int i = size; i < fin_size; i++)
      {

         BookCopy obj(ob.get_id(), i + 1 - size, true, "", -1);
         list[i] = obj;
      }
      size = fin_size;
      // bookList
      // list2.initialise(books[i]);
      //  list[i].initialise(books[i]);
   }
   int issue(string date, int id, int book_id)
   {
      for (int i = 0; i < size; i++)
      {
         if (list[i].getBookId() == book_id && list[i].getStatus() == true)
         {
            list[i].setStatus(false);
            list[i].setDateOfIssue(date);
            list[i].set_mem_id(id);
            cout << "copy " << list[i].getCopyNo() << "issued to " << id << "\n";
            return (list[i].getCopyNo());
         }
      }

      return 0;
   }
   bool ret_book(int n, int id, string dat, int book_id)
   {

      for (int i = 0; i < size; i++)
      {
         if (list[i].getBookId() == book_id && list[i].get_mem_id() == id && list[i].getCopyNo() == n)
         {
            cout << "book copy returned\n";
            list[i].setStatus(true);
            list[i].set_mem_id(-1);
            list[i].setDateOfIssue(dat);
            return true;
         }
      }

      cout << "book copy " << n << " was not issued to " << id << "\n";
      return false;
   }
   int issue_a_book(int id, int mem_id, string date, BookList &book_list)
   {
      Book ob = book_list.match_book_id(id);
      if (ob.get_id() != 0)
      {

         if (ob.is_available())
         {
            ob.issue();

            int val = issue(date, mem_id, id);
            return val;
         }
      }
      return 0;
   }
   bool ret(int mem_id, int book_id, int copy, string date, BookList &book_list)
   {
      Book ob = book_list.match_book_id(book_id);
      if (ob.get_id() != 0)
      {
         if (ret_book(copy, mem_id, date, book_id))
         {
            ob.ret();
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
   string name;
   string email;
   string address;
   int num;

public:
   // Constructor
   Member()
   {
   }
   Member(int id, const string &n, const string &e, const string &a, int &na)
       : member_id(id), name(n), email(e), address(a), num(na)
   {
   }

   // Function to input member details
   void input()
   {
      cout << "Enter Member ID: ";
      cin >> member_id;
      cin.ignore(); // Clear the input buffer
      cout << "Enter Name: ";
      getline(cin, name);
      cout << "Enter Email: ";
      getline(cin, email);
      cout << "Enter Address: ";
      getline(cin, address);
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

   string getName()
   {
      return name;
   }

   string getEmail()
   {
      return email;
   }

   string getAddress()
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
   Student(int id, const string &n, const string &e, const string &a, int &na)
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

   Faculty(int id, const string &n, const string &e, const string &a, int na)
       : Member(id, n, e, a, na) {}
};

int Faculty::max_issue = 5; // Initialize max_issue for faculty

class StudentList
{
public:
   StudentList() : size(0) {}

   bool addStudent(Student s)
   {
      if (size >= MaxSize)
      {
         cout << "Student list is full. Cannot add more students." << endl;
         return false;
      }

      // Check if the student with the same ID already exists
      for (int i = 0; i < size; ++i)
      {
         if (students[i].getMemberId() == s.getMemberId())
         {
            cout << "Student with ID " << s.getMemberId() << " already exists. Not added." << endl;
            return false;
         }
      }

      students[size++] = s;
      cout << "Student with ID " << s.getMemberId() << " added." << endl;
      return true;
   }

   void displayStudents()
   {
      for (int i = 0; i < size; ++i)
      {
         cout << "ID: " << students[i].getMemberId() << endl;
      }
   }
   Student &isStudentIdPresent(int id)
   {
      for (int i = 0; i < size; ++i)
      {
         if (students[i].getMemberId() == id)
         {
            cout << "Member found\n";
            return students[i]; // ID is present in the list
         }
      }
      return def; // ID is not present in the list
   }
   void fill_list()
   {
      for (int i = 0; i < 5; i++)
      {
         Student obj;
         obj.input();
         addStudent(obj);
      }
   }

private:
   static const int MaxSize = 5;
   Student students[MaxSize];
   Student def;
   int size;
};
class FacultyList
{
public:
   FacultyList() : size(0) {}

   bool addFaculty(Faculty f)
   {
      if (size >= MaxSize)
      {
         cout << "Faculty list is full. Cannot add more faculty members." << endl;
         return false;
      }

      // Check if the faculty member with the same ID already exists
      for (int i = 0; i < size; ++i)
      {
         if (facultyMembers[i].getMemberId() == f.getMemberId())
         {
            cout << "Faculty member with ID " << f.getMemberId() << " already exists. Not added." << endl;
            return false;
         }
      }

      facultyMembers[size++] = f;
      cout << "Faculty member with ID " << f.getMemberId() << " added." << endl;
      return true;
   }

   void displayFacultyMembers()
   {
      for (int i = 0; i < size; ++i)
      {
         cout << "ID: " << facultyMembers[i].getMemberId() << endl;
      }
   }
   Faculty &isFacultyIdPresent(int id)
   {
      for (int i = 0; i < size; ++i)
      {
         if (facultyMembers[i].getMemberId() == id)
         {
            cout << "Member found\n";

            return facultyMembers[i]; // ID is present in the list
         }
      }
      return def; // ID is not present in the list
   }
   void fill_list()
   {
      for (int i = 0; i < 5; i++)
      {
         Faculty obj;
         obj.input();
         addFaculty(obj);
      }
   }

private:
   static const int MaxSize = 5;
   Faculty facultyMembers[MaxSize];
   Faculty def;
   int size;
};

class Transaction
{
protected:
   string date;
   int member_id;
   int book_id;
   int serial_number;
   bool issue;

public:
   Transaction() {}

   Transaction(const string &d, int m_id, const int &b_id, int s_no, bool is_issue)
       : date(d), member_id(m_id), book_id(b_id), serial_number(s_no), issue(is_issue) {}

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
   void setdate(string d)
   {
      date = d;
   }
   void setstatus(bool s)
   {
      issue = s;
   }
   string get_date()
   {
      return date;
   }
};
class Issue : public Transaction
{
public:
   Issue() : Transaction() {}
   Issue(const string &d, int m_id, const int &b_id, int s_no, bool is_issue)
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
         }
         else
         {
            fa.issue();
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
   return_book(const string &d, int m_id, const int &b_id, int s_no, bool is_issue)
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
         }
         else
         {
            cout << "book returned\n";
            ob.ret();
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
   Issue list[100];
   int size;

public:
   Transaction_List()
   {
      size = 0;
   }
   bool add_issue(string date, int memberId, int bookId, bool isIssue, StudentList &list1, FacultyList &list2, BookList &list3, copy_list &list4)
   {
      Issue transaction(date, memberId, bookId, 0, isIssue);
      if (transaction.can_issue_book(memberId, list1, list2, bookId, list3, list4))
      {
         cout << "Book issued successfully." << endl;

         list[size] = transaction;
         cout << " transaction object \n";
         list[size].display();
         size++;
         return true;
      }
      else
      {
         cout << "Failed to issue the book." << endl;
         return false;
      }
   }
   bool update_return(string date, int memberId, int serial, int bookId, bool isIssue, StudentList &list1, FacultyList &list2, BookList &list3, copy_list &list4)
   {
      return_book transaction(date, memberId, bookId, serial, isIssue);
      if (transaction.ret_book(bookId, memberId, serial, list1, list2, list3, list4))
      {
         int copy = 0;

         cout << "Book returned successfully." << endl;
         for (int i = 0; i < size; i++)
         {
            if (list[i].get_mem_id() == memberId && list[i].getserial() == serial && list[i].get_book_id() == bookId)
            {
               list[i].setdate(date);
               list[i].setstatus(0);
               copy = i;
            }
         }
         cout << " transaction object \n";
         list[copy].display();
         size++;
      }
      else
      {
         cout << "Failed to return the book." << endl;
      }
   }
};
class lms
{

public:
   static void driver()
   {
      StudentList list1;
      FacultyList list2;
      BookList list3;
      copy_list list4;
      Transaction_List tlist;
      Student obj;
      Faculty ob;
      char continueTransaction;

      do
      {
         char ch;
         cout << " enter 1 to add member to student list , 2 to add member to faculty list , 3 to add book to book list,4 to transact\n";
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
            string date;
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
         }
         cout << "Do you want to perform another operation? (y/n): ";
         cin >> continueTransaction;
      } while (continueTransaction == 'y' || continueTransaction == 'Y');

      // Take user input for a transaction
   }
};
int main()
{
   lms::driver();
}
