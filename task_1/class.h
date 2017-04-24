//declare all the classes
#include<stdlib.h>
#include<fstream>
const int MAX_RANGE = 200;
enum sys{vec, com, cyl, sph};

class System
{
protected:
	~System()
	 {}
	enum {MAX_RANGE = 100};

	//three cartesian co-ordinates
	double X[MAX_RANGE],Y[MAX_RANGE],Z[MAX_RANGE];

	//three angles
	double RHO[MAX_RANGE],PHI[MAX_RANGE],THETA[MAX_RANGE];

	//other common variables for all the classes
	char choice;
	unsigned int wish;
	unsigned int count,j;


  public:
   virtual void add() =0;//adding co-ordinates
   virtual void subtract() =0;//subtract co-ordinates
   virtual void shift_of_origin() =0;//shift of origin
   virtual void menu() =0;//display the menu for each operation to be performed
   virtual void read(bool ) =0;//take the input from the user
   virtual void display(bool ) =0;//display appropriate results
   virtual void log() =0;//log of actions
   virtual void convert() =0;//represent in other system
   virtual void dot_product(bool ) =0;//vector dot-product
   virtual void cross_product(bool ) =0;//vector cross product
   virtual void angle_bw_vectors(bool ) =0;//angle between vectors

};

//declare the Run class
class Run
{
 protected:
  unsigned int choice;

 public:
  //action function to populate the menu
  void action();
};

//declare the Complex system class derived from the system class
class Complex : public System
{
 private:
	//log count for each result stored
  unsigned int log_count;

protected:

 public:

  ~Complex()
     {}

  //ddeclare the strucuture
  struct c_data
  {
  	  double x;
  	  double y;
  };

  struct c_data dat;
  //fstream file;

  //declaration of the member functions
  void convert();
  void read(bool );
  void display(bool );
  void add();
  void log();
  void subtract();
  void shift_of_origin();
  void menu();

  //virtual functions
  void dot_product(bool )
  {

  }
  void cross_product(bool )
  {

  }
  void angle_bw_vectors(bool )
  {

  }
};

//declare the Spherical system class derived from the system class
class Spherical : public System
{
private:
	//log count for each result stored
	unsigned int log_count;

protected:

 public:

	   ~Spherical()
	     {}

	   //declare the memeber functions
  void convert();
  void log();
  void read(bool );
  void display(bool );
  void add();
  void subtract();
  void shift_of_origin();
  void menu();

  //virtual functions
  void dot_product(bool )
    {}
  void cross_product(bool )
    {}
  void angle_bw_vectors(bool )
    {}
};

//declare the Cylindrical system class derived from the system class
class Cylindrical : public System
{
private:
	//log count for each result stored
	unsigned int log_count;

protected:

 public:

	 ~Cylindrical()
	   {}

	 //declare the member functions
  void convert();
  void log();
  void read(bool );
  void display(bool );
  void add();
  void subtract();
  void shift_of_origin();
  void menu();

  //virtual
  void dot_product(bool )
      {}
  void cross_product(bool )
      {}
  void angle_bw_vectors(bool )
      {}
};

//declare the Vector system class derived from the system class
class Vector : public System
{
private:
	//log count for each result stored
	unsigned int log_count;

protected:

 public:

	 ~Vector()
	    {}

//declare the member functions
  void convert();
  void log();
  void read(bool );//done
  void display(bool );//done
  void add();//done
  void subtract();//done
  void shift_of_origin();//done
  void menu();//done
  void dot_product(bool );
  void cross_product(bool );
  void angle_bw_vectors(bool );

};

//***********************************************  linklist to sore the operation performed  ***********************//

//declare structure
struct link
{
  char str[MAX_RANGE];
  link *next;
};

//create a linklist class to store the operations performed
class linklist
{
 private:
  link *first;
  int log_number;

 public:
  //declare constructer
 linklist():log_number(0)
  {first = NULL;}

  //add a new log?
  void add_log(char [] );

  //increment the log
  void inc_log();

  //get the log count
  void get_log_num();

  //show the log of operations
  void show_log(link *);

  //return the head of the linklist
  link *lfirst();
};


//********************************************** converter class ***********************************************//


class Converter
{

public:
	~Converter()
		{}
//member functions to convert the data from one system to the other
	void convert_v(sys );
	void convert_c(sys );
	void convert_cy(sys );
	void convert_s(sys );

};
