#include<iostream>
#include<ctime>
using namespace std;

class bookcopy{
    int book_id;
    int copy_no;
    //1 availabe, 0 nnot available
    int status;
    time_t date_of_issue;
    char title[30];
    char author[30];
    float price;
    public:
    bookcopy(){
        book_id=-1;
        copy_no=-1;
    }
    //status gets 1
    void add_data(int bookid,int copy_no);

    //
    void show_data();
    //only book details not copy_no.,status,date_of_issue
    void show_book_details();

    int get_book_id();
    int get_copy_no();
    int get_status();
    void update_status(int);
    void update_time();
};

class book_copy_list{
    bookcopy list[10];
    //no of books has been added to list
    int cnt;

    public:
    book_copy_list(){
        cnt=0;
    }
    //calls add_data(id, cnt) then cnt++
    void add_bookcopy(int id);

    //searches for copy_no in list returns index if found 
    //else -1
    int search(int n);

    //check status of bookcopy , returns available copy_no, updates status,time
    int issue();

    //searches copy_no, updates status
    void returns(int);

    //displays the list
    void showlist();

    //calls show_book_details() of bookcopy
    void showbook();

    //searches for copy no. n ,if found calls show_data() of that bookcopy
    void showbookcopy(int n);
};

class book{
    int id;
    int books_available;
    book_copy_list bcl;
    public:
    book(){
        books_available=0;
        id=-1;
    }
    int return_id();

    //add copy to bcl, calls add_bookcopy(int id);
    void addbookcopy();

    //displays bcl
    void showcopylist();

    //to display book data, calls showbook of bcl
    void showbook();

    //calls showbookcopy(int n) of bcl with copy_no n
    void showbookcopy(int n);

    //checks available or not,if yes then calls issue of bcl
    int issue();

    //goes to bcl and updates
    void returns(int);
};

class booklist{
    book list[10];
    int cnt;
    public:
    booklist(){
        cnt=0;
    }
    //generic details of book
    void showbook(int id);

    //all the details of a bookcopy
    void showbookcopy(int id,int copy_no);

    //searches id of book in list, if present returns index, else -1
    int search(int id);

    //checks if already present, if not adds new book,cnt++
    void add_book(int id);

    //searches, then adds copy for a book in its bookcopylist
    //calls add_bookcopy(int id) of bcl
    void add_copy(int id);

    //searches,calls issue of book, return copy no 
    int issue(int index);

    //calls search(id),
    //if found stores search index in index
    //calls list[index].returns(int copy_no); 
    void returns(int id,int copy_no);
};

class member{
    protected:
    char name[30];
    char email[30];
    int member_id;
    public:
    member(){
        member_id=-1;
    }
    void add_data(int id);
    void show_data();
    int get_id();
};

//max issue for student=2
class student: public member{
    int books_can_issue;
    public:
    student(){
            books_can_issue=2;
        }

    void addstudent(int id);
    void show_student();

    //checks if issue>0 ,decreases book_can_issue returns 1, else returns 0
    int issue();

    //increses book_can_issue
    void returns(); 

    void display_data();   
};

//max issue for faculty=10
class faculty: public member{
    int books_can_issue;
    public:
    faculty(){
        books_can_issue=10;
    }

    void addfaculty(int id);
    void show_faculty();

    //checks if issue>0 ,decreases book_can_issue returns 1, else returns 0
    void issue();

    //increses book_can_issue
    void returns();   

    void display_data(); 
};

class studentlist{
    student list[100];
    int cnt;
    public:
    studentlist(){
        cnt=0;
    }
    //returns index if present else -1
    int search(int id);

    //calls list[index].addstudent(id)
    void addstudent(int index,int id);

    //checks if  student[index] issue>0 ,decreases book_can_issue returns 1, else returns 0
    int issue(int index);

    //calls search(id),
    //if found stores search index in index
    //calls list[index].returns();
    void returns(int id);
};

class facultylist{
    faculty list[100];
    int cnt;
    public:
    facultylist(){
        cnt=0;
    }
    //returns index if present else -1
    int search(int id);

    //calls list[index].addfaculty(id)
    void addfaculty(int index,int id);

    //checks if  faculty[index] issue>0 ,decreases book_can_issue returns 1, else returns 0
    int issue(int index);

    //calls search(id),
    //if found stores search index in index
    //calls list[index].returns();
    void returns(int id);
};


class transaction{
    int member_id;
    int book_id;
    int copy_id;
    int returned;//0- issued, 1 -returned
    time_t date;

    public:
    //assigns values to respective fields, assigns current date, int returned to 0
    transaction(int id=-1,int bookid=-1,int copyid=-1);

    int get_memberid();
    int get_bookid();
    int get_copyid();
    int get_returned();
    time_t get_date();

    //sets returned to 1 and updates date to current
    void returns();

    void display_transaction();
};

class transactionlist{
    transaction list[100];
    int cnt;
    public:
    transactionlist(){
        cnt=0;
    }
    int search(int id);

    void add(transaction&);

    //calls search(id), if found checks if returned ==0
    //if found stores search index in index
    //calls list[index].return();
    //if successfull returns 1, else 0
    int returns(int id);

    void display_transactions();
};

class Library{
    book_copy_list bk_cp_list;
    booklist bklist;
    studentlist slist;
    facultylist flist;
    transactionlist tlist;
    public:
    void addfaculty(){
        int id;
        //searches in facultylist
        //if present displays already added
        //else calls addfaculty(int id)
    }
    void add_student(){
        int id;
        //searches in studentlist
        //if present displays already added
        //else calls addstudent(int id)
    }
    void addbook(){
        int id;
        //searches in booklist
        //if present checks if maxcopy<10, if true adds bookcopy
        //else calls addbook(int id), then calls addbookcopy(int id)
    }
    void display_facultylist();
    void display_studentlist();
    void dispaly_transactionlist();
    void display_booklist();


    void issue_student(){
        int id;
        cin>>id;
        //checks id in studentlist or not
        int index = slist.search(id);

        if(index!=-1){
            //calls issue of studentlist which calls issue of student
            if(slist.issue(index)){
                int bookid;
                //searches booklist with the id 
                //if finds calls issue of booklist with search index
                //further calls issue of book, checks if available
                //if available returns copyno
                //copyno stored in
                int copy_no;
                transaction t(id,bookid,copy_no);
                tlist.add(t);
            }
            else{
                //dispalys max book issue reached
            }
        }
        else{
            //dispalys student not present
        }
    }

    void issue_faculty(){
        int id;
        cin>>id;
        //checks id in facultylist or not
        int index = flist.search(id);

        if(index!=-1){
            //calls issue of facultylist which calls issue of faculty
            if(flist.issue(index)){
                int bookid;
                //searches booklist with the id 
                //if finds calls issue of booklist with search index
                //further calls issue of book, checks if available
                //if available returns copyno
                //copyno stored in
                int copy_no;
                transaction t(id,bookid,copy_no);
                tlist.add(t);
            }
            else{
                //dispalys max book issue reached
            }
        }
        else{
            //dispalys student not present
        }
    }
    void return_student(){
        int id;
        int bookid;
        int copyno;
        if(tlist.returns(id)){
            //checks if same bookid and copyno as in transaction slip, else displays error
            //calls studentlist.returns(member id) and updates book_issue
            //calls booklist.returns(book id, copyid) and updates book_availabe and book copy 
        }
        else{
            //dispalys wrong id
        }
    }
    void return_faculty(){
        int id;
        int bookid;
        int copyno;
        if(tlist.returns(id)){
            //checks if same bookid and copyno as in transaction slip, else displays error
            //calls facultylist.returns(member id) and updates book_issue
            //calls booklist.returns(book id, copyid) and updates book_availabe and book copy 
        }
        else{
            //dispalys wrong id
        }
    }
};