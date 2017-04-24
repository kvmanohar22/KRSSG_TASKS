#include<bits/stdc++.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include "class.h"
using namespace std;

//declare some constants
const float PI = 3.1415926;
const int MAX = 100;
unsigned static int count_ptr = 0;

//declare the objects of classes
  linklist li;
  Vector vect;
  Complex comp;
  Cylindrical cyli;
  Spherical sphe;
  Converter con;
  Run r_obj;
  link *first;
  System *ptr[MAX];


//declare the variables for conversion purpose
double x,y,z,rh,th,ph;

void Run::action()
{

  do
  {
	//populate the menu
    cout<<"\nHere's your list of actions:\n"<<endl;
    cout<<"1 COMPLEX CO-ORDINATE SYSTEM"<<endl
        <<"2 SPHERICAL CO-ORDINATE SYSTEM"<<endl
        <<"3 CYLINDRICAL CO-ORDINATE SYSTEM"<<endl
        <<"4 VECTOR CO-ORDINATE SYSTEM"<<endl
        <<"5 DISPLAY THE LOG OF OPERATIONS"<<endl
        <<"6 EXIT\n"<<endl
        <<"Please pick your choice:"<<endl;
    cin>>choice;

    //switch to the choice
  switch(choice)
    {
    case 1:
    	ptr[count_ptr] = new Complex;
      break;

    case 2:
    	ptr[count_ptr] = new Spherical;
      break;

    case 3:
    	ptr[count_ptr] = new Cylindrical;
      break;

    case 4:
    	ptr[count_ptr] = new Vector;
      break;

    case 5:
        li.get_log_num();
    	first = li.lfirst();
    	li.show_log(first);
    	Run::action();
      break;

    case 6:
      cout<<"You have chosen to quit!\n\nExiting..."<<endl;
      exit(0);
      break;

    default:
      cout<<"Please enter a valid choice!\n"<<endl;
      Run::action();
    }

  ptr[count_ptr]->menu();

  }while(choice != 6);

}//END OF RUN::ACTION()


//************************************** complex class ********************************************//

void Complex::convert()
{
	//read the co-ordinates
	ptr[count_ptr]->read(false);

	//populate the menu
	cout<<"Enter the system to which you want transformation to:"<<endl;
	cout<<"1 SPHERICAL CO-ORDINATE SYSTEM"<<endl
	    <<"2 CYLINDRICAL CO-ORDINATE SYSTEM"<<endl
	    <<"3 VECTOR CO-ORDINATE SYSTEM"<<endl
	    <<"Please pick your choice:"<<endl;
	 cin>>wish;

	 //assign those values to global variables
	  x = X[0];
	  y = Y[0];
      z = 0;
	 switch(wish)
	 {
	 case 1:
		 con.convert_s(com);
		 //Converter::convert_s();
		 //ptr[count_ptr]->convert_s();
		 break;
	 case 2:
		 con.convert_cy(com);
		 //ptr[count_ptr]->convert_cy();
		 break;
	 case 3:
		 con.convert_v(com);
		// ptr[count_ptr]->convert_v();
		 break;
	 default:
		 cout<<"Please enter a valid choice:"<<endl;
		 ptr[count_ptr]->convert();
	 }
}

void Complex::read(bool check)
{
	cout<<"Please enter in this format(real and imaginary):"<<endl;

	//check how many members are to be read
  if(check)
    {
      for(int j=0;j<count;j++)
	    cin>>X[j]>>Y[j];
    }
  else
    cin>>X[0]>>Y[0];
}

void Complex::display(bool check)
{
	//display in proper format
  if(check)
    {
      for(j=0;j<count;j++)
	 cout<<"Number "<<j+1<<": "<<X[j]<<" + j"<<Y[j]<<endl;
    }
  else
    cout<<"Number 1: "<<X[0]<<" + j "<<Y[0]<<endl;
}

void Complex::add()
{
	//strcpy(str[],"Addition of complex numbers");
   //strcpy(str,"Addition of complex numbers");
   //linklist::add_log(str);
  cout<<"How many complex numbers do you want to add(1 to 100)?"<<endl;
  cin>>count;
  Complex::read(true);
  cout<<"\nEntered complex number(s) are as follows:"<<endl;
  Complex::display(true);

  for(int j=0;j<count;j++)
    {
      X[count]+=X[j];
      Y[count]+=Y[j];
    }

  //display the result
  cout<<"Sum of entered complex numbers is:"<<endl;
  X[0] = X[count];
  Y[0] = Y[count];
  ptr[count_ptr]->display(false);

  //ask if the user wants to store the result
  //cout<<"Do you want this result to be stored in log(y/n)?"<<endl;
  //cin>>choice;
  /*
  if(choice == 'y'||choice == 'Y')
     {
      dat.x = X[0];
      dat.y = Y[0];

	 // file.open(“c_data.txt”, ios::app | ios::out | ios::in | ios::binary );
     //file.open("c_data.txt", ios::app | ios::out | ios::in | ios::binary);
     //file.write( reinterpret_cast<char*>(&pers), sizeof(pers) );
     //file.write(reinterpret_cast<char*>(&dat), sizeof(c_data));
     //file.seekg(0);



	  /*
       // Complex::in_log();
      ofstream outfile("c_data[log_count++].txt");
      outfile<<"Result-of-addition-is:"
             <<X[0]
             <<"+j"
             <<Y[0];

        log_count++;
	//cout<<log_count;
        cout<<"Result is saved successfully!"<<endl;

        */
    // }
  //else
    // {
        // cout<<log_count;
      //  cout<<"Result is not saved in the log"<<endl;
     //}

}

void Complex::subtract()
{
  count = 2;
  //read the data
  Complex::read(true);

  //display the entered data
  cout<<"\nEntered complex number(s) are as follows:"<<endl;
  Complex::display(true);
  X[0] = X[0] - X[1];
  Y[0] = Y[0] - Y[1];
  cout<<"Difference of entered complex numbers is:"<<endl;

  ptr[count_ptr]->display(false);

  //ask if the user waants to store the result
  /*
  cout<<"Do you want this result to be stored in log(y/n)?"<<endl;
  cin>>choice;
  if(choice == 'y'||choice == 'Y')
    {
      //Complex::in_log();
      ofstream outfile("c_data[log_count++].txt");
      outfile<<endl
             <<"Result-of-subtraction-is:"
             <<X[0]
             <<"+j"
             <<Y[0];
	//<<'\0';

      log_count++;
      cout<<"Result is saved successfully!"<<endl;
    }
  else
    cout<<"Result is not saved in the log"<<endl;
    */
}

void Complex::shift_of_origin()
{
	//read the data
	Complex::read(false);
	cout<<"Enter the co-ordinates to which you want to shift origin to:"<<endl;
	cin>>X[1]>>Y[1];

	//shift the origin
	cout<<"After the shift of origin, the new co-ordinates are:"<<endl;
	X[0] = X[0] - X[1];
	Y[0] = Y[0] - Y[1];

	ptr[count_ptr]->display(false);
}

void Complex::log()
{
  string str1,str2;
  double d1,d2;
  char ch;

  fstream file;
  /*
  // cout<<log_count;
  if(log_count >= 1)
  {
	  int temp = log_count;
	  while(temp>=0)
	  {
         cout<<"Result log stored for complex system is as follows:\n"<<endl;
         ifstream infile("c_data[--temp].txt");
        //while(!infile.eof())
          //{
            infile>>str1>>d1>>str2>>d2;
            cout<<str1<<d1<<str2<<d2<<endl;
          //}

           file.read( reinterpret_cast<char*>(&pers), sizeof(pers) );
while( !file.eof() )
//quit on EOF
{
cout << “\nPerson:”;
//display person
pers.showData();
//read another person
file.read( reinterpret_cast<char*>(&pers), sizeof(pers) );
}
cout << endl;

  cout<<"Result log stored for complex system is as follows:\n"<<endl;
  file.read(reinterpret_cast<char*>(&dat), sizeof(c_data));
  while(!file.eof())
  {
	  cout<<"Result:";
	  cout<<dat.x<<" +j "<<dat.y;
	  file.read(reinterpret_cast<char*>(&dat), sizeof(c_data));
  }
*/




}

void Complex::menu()
{
//populate the menu
  cout<<"Here is a list of actions which can be implemented:\n"<<endl;
  cout<<"[COMPLEX SYSTEM]"<<endl
      <<"1 Add members belonging to this system"<<endl
      <<"2 Subtract members belonging to this system"<<endl
      <<"3 Show members by shifting the origin"<<endl
      <<"4 Convert members of this system to other systems"<<endl
      //<<"5 Display the log of results stored in this system"<<endl
      <<"5 Switch the system of operation to other system"<<endl
      <<"Please pick your choice:\n";
  cin>>wish;

  //use switch case statement to perform all the operations necesary
  switch(wish)
    {
    case 1:
      li.add_log("[COMPLEX SYSTEM] Addition of complex numbers");
      ptr[count_ptr]->add();
      ptr[count_ptr]->menu();
      break;

    case 2:
      li.add_log("[COMPLEX SYSTEM] Subtraction of complex numbers");
      ptr[count_ptr]->subtract();
      ptr[count_ptr]->menu();
      break;

    case 3:
      li.add_log("[COMPLEX SYSTEM] Shift of origin of complex number");
      ptr[count_ptr]->shift_of_origin();
      ptr[count_ptr]->menu();
      break;

    case 4:
      li.add_log("[COMPLEX SYSTEM] Conversion of elements of complex system to other systems");
      ptr[count_ptr]->convert();
      ptr[count_ptr]->menu();
      break;
/*
    case 5:
      li.add_log("[COMPLEX SYSTEM] Display of log of results of complex numbers");
      ptr[count_ptr]->log();
      ptr[count_ptr]->menu();
      break;
*/
    case 5:
      count_ptr++;
      r_obj.action();
      break;

    default:
      cout<<"Please enter a valid choice!"<<endl;
      ptr[count_ptr]->menu();
    }
}

//***************************************** vector class *******************************************//

void Vector::menu()
{
	//populate the menu
	cout<<"Here is a list of actions which can be implemented:\n"<<endl;
	  cout<<"[VECTOR SYSTEM]"<<endl
	      <<"1 Add members belonging to this system"<<endl
	      <<"2 Subtract members belonging to this system"<<endl
	      <<"3 Show members by shifting the origin"<<endl
	      <<"4 Convert members of this system to other systems"<<endl
	      //<<"5 Display the log of results stored in this system"<<endl
	      <<"5 Switch the system of operation to other system"<<endl
	      <<"6 Compute the dot product between two vectors"<<endl
	      <<"7 Compute the cross product between two vectors"<<endl
	      <<"8 Compute the angle between two vectors"<<endl
	      <<"Please pick your choice:\n";
	  cin>>wish;

	  //use switch case statement to perform all the operations necesary
	  switch(wish)
	      {
	      case 1:
	    	li.add_log("[VECTOR SYSTEM] Addition of vectors");
	        ptr[count_ptr]->add();
	        ptr[count_ptr]->menu();
	        break;

	      case 2:
	    	li.add_log("[VECTOR SYSTEM] Difference of vectors");
	        ptr[count_ptr]->subtract();
	        ptr[count_ptr]->menu();
	        break;

	      case 3:
	    	li.add_log("[VECTOR SYSTEM] Shift of origin of vector");
	        ptr[count_ptr]->shift_of_origin();
	        ptr[count_ptr]->menu();
	        break;

	      case 4:
	    	li.add_log("[VECTOR SYSTEM] Conversion of elements of vector system to other systems");
	    	ptr[count_ptr]->convert();
	    	ptr[count_ptr]->menu();
	        break;
/*
	      case 5:
	    	li.add_log("[VECTOR SYSTEM] Display of log of results of Vector system");
	    	ptr[count_ptr]->log();
	    	ptr[count_ptr]->menu();
	        break;
*/
	      case 5:
	    	  count_ptr++;
	          r_obj.action();
	        break;

	      case 6:
	    	li.add_log("[VECTOR SYSTEM] Computation of dot-product of vectors");
	    	ptr[count_ptr]->dot_product(true);
	    	ptr[count_ptr]->menu();
	        break;

	      case 7:
	    	li.add_log("[VECTOR SYSTEM] Computation of cross-product of vectors");
	    	ptr[count_ptr]->cross_product(true);
	    	ptr[count_ptr]->menu();
	      	break;

	      case 8:
	    	li.add_log("[VECTOR SYSTEM] Computation of angle between vectors");
	    	ptr[count_ptr]->angle_bw_vectors(true);
	      	ptr[count_ptr]->menu();
	      	break;

	      default:
	        cout<<"Please enter a valid choice!"<<endl;
	        ptr[count_ptr]->menu();
	      }

}

void Vector::add()
{
	//ask the user how many members are to addedd
	cout<<"How many vectors do you want to add(1 to 100)?"<<endl;
	cin>>count;
	Vector::read(true);

	//populate the entered members
	cout<<"\nEntered vector(s) are as follows:"<<endl;
	Vector::display(true);

	//add the members
	for(int j=0;j<count;j++)
	{
      X[count]+=X[j];
      Y[count]+=Y[j];
      Z[count]+=Z[j];
	}

	//display the result
	cout<<"Sum of the vectors is as follows:"<<endl;
	X[0] = X[count];
	Y[0] = Y[count];
	Z[0] = Z[count];
	ptr[count_ptr]->display(false);
	//implement the log operation
}

void Vector::subtract()
{
	count = 2;
	//read the members
	  Vector::read(true);
	  cout<<"\nEntered vector(s) are as follows:"<<endl;
	  Vector::display(true);
	  X[count] = X[0] - X[1];
	  Z[count] = Z[0] - Z[1];
	  Y[count] = Y[0] - Y[1];

	  //display the result
	  X[0] = X[count];
	  Y[0] = Y[count];
	  Z[0] = Z[count];
	  cout<<"The subtraction result of the vectors is:"<<endl;
      ptr[count_ptr]->display(false);
	  //implement the log
}

void Vector::shift_of_origin()
{
	//read the members
	Vector::read(false);
		cout<<"Enter the co-ordinates to which you want to shift origin to:"<<endl;
		cin>>X[1]>>Y[1]>>Z[1];

		//shift the origin
		cout<<"After the shift of origin, the new co-ordinates are:"<<endl;
		X[0] = X[0] - X[1];
		Y[0] = Y[0] - Y[1];
		Z[0] = Z[0] - Z[1];
		cout<<"Vector after transformation"<<endl;

		//populate the result
		ptr[count_ptr]->display(false);
}

void Vector::read(bool choice)
{
	//read the members in proper format
	cout<<"Please enter in this format(x, y, z):"<<endl;

	  if(choice)
	    {
	      for(int j=0;j<count;j++)
		    cin>>X[j]>>Y[j]>>Z[j];
	    }
	  else
	    cin>>X[0]>>Y[0]>>Z[0];
}

void Vector::display(bool check)
{
	//display the members inproper format
	  if(check)
	    {
	      for(j=0;j<count;j++)
		   cout<<"Vector "<<j+1<<": ["<<X[j]<<", "<<Y[j]<<", "<<Z[j]<<"]"<<endl;
	    }
	  else
		  cout<<"Vector 1"<<": ["<<X[0]<<", "<<Y[0]<<", "<<Z[0]<<"]"<<endl;
}

void Vector::dot_product(bool choice)
{
	count = 2;

	//raed the members
		  Vector::read(true);
		  cout<<"\nEntered vector(s) are as follows:"<<endl;
		  Vector::display(true);

		  //calculate dot product
		  X[0] = X[0]*X[1];
		  Y[0] = Y[0]*Y[1];
		  Z[0] = Z[0]*Z[1];

		  //populate the result
		  cout<<"The resultant vector of dot product is:"<<endl;
		  Vector::display(false);
}

void Vector::cross_product(bool check)
{
	count = 2;
	//read the vectors
			  Vector::read(true);
			  cout<<"\nEntered vector(s) are as follows:"<<endl;
			  Vector::display(true);

			  //compute the cross product
			  X[2] = Y[0]*Z[1]-Y[1]*Z[0];
			  Y[2] = -X[0]*Z[1]+X[1]*Z[0];
			  Z[2] = X[0]*Y[1]-X[1]*Y[0];
			  X[0] = X[2];
			  Y[0] = Y[2];
			  Z[0] = Z[2];

			  //populate the result
			  cout<<"The resultant vector of cross product is:"<<endl;
			  Vector::display(false);
}

void Vector::angle_bw_vectors(bool check)
{
	count = 2;

	//reaad the vectors
			  Vector::read(true);
			  cout<<"\nEntered vector(s) are as follows:"<<endl;
			  Vector::display(true);

			  //compute the theta
             double theta = X[0]*X[1] + Y[0]*Y[1] + Z[0]*Z[1];
             theta = theta/(sqrt(pow(X[0],2)+pow(Y[0],2)+pow(Z[0],2))*sqrt(pow(X[1],2)+pow(Y[0],2)+pow(Z[0],2)));
             theta = acos(theta);
             cout<<"Angle between the given two vectors is: "<<(theta*180)/PI<<" degrees"<<endl;
}

void Vector::convert()
{
	ptr[count_ptr]->read(false);
		cout<<"Enter the system to which you want transformation to:"<<endl;
		cout<<"1 SPHERICAL CO-ORDINATE SYSTEM"<<endl
		    <<"2 CYLINDRICAL CO-ORDINATE SYSTEM"<<endl
		    <<"3 COMPLEX CO-ORDINATE SYSTEM"<<endl
		    <<"Please pick your choice:"<<endl;
		 cin>>wish;

		 //assign those values to global variables
		  x = X[0];
		  y = Y[0];
	      z = Z[0];
		 switch(wish)
		 {
		 case 1:
			 con.convert_s(vec);
			 //Converter::convert_s();
			 //ptr[count_ptr]->convert_s();
			 break;
		 case 2:
			 con.convert_cy(vec);
			 //ptr[count_ptr]->convert_cy();
			 break;
		 case 3:
			 con.convert_c(vec);
			// ptr[count_ptr]->convert_v();
			 break;
		 default:
			 cout<<"Please enter a valid choice:"<<endl;
			 ptr[count_ptr]->convert();
		 }
}

void Vector::log()
{
;
}

//******************************************** cylindrical class ***************************************//

void Cylindrical::menu()
{

	//explain what is rho theta and z
	  cout<<"[CONVENTION]"<<endl
		  <<"#1 We assume that the axis of cylinder is parallel to z-axis"<<endl
		  <<"#2 Angle theta is measured with respect +ve x-axis"<<endl
		  <<"#3 Angle measured in CCW is taken to be positive"<<endl;
	  cout<<"\nHere is a list of actions which can be implemented:\n"<<endl;
	  cout<<"[CYLINDRICAL SYSTEM]"<<endl
	      <<"1 Add members belonging to this system"<<endl
	      <<"2 Subtract members belonging to this system"<<endl
	      <<"3 Show members by shifting the origin"<<endl
	      <<"4 Convert members of this system to other systems"<<endl
	     // <<"5 Display the log of results stored in this system"<<endl
	      <<"5 Switch the system of operation to other system"<<endl
	      <<"Please pick your choice:\n";
	  cin>>wish;

	  switch(wish)
	    {
	    case 1:
	    	li.add_log("[CYLILNDRICAL SYSTEM] Addition of co-ordinates");
	    	ptr[count_ptr]->add();
	    	ptr[count_ptr]->menu();
	      break;

	    case 2:
	    	li.add_log("[CYLILNDRICAL SYSTEM] Difference of co-ordinates");
	    	ptr[count_ptr]->subtract();
	    	ptr[count_ptr]->menu();
	      break;

	    case 3:
	    	li.add_log("[CYLILNDRICAL SYSTEM] Shift of origin of co-ordinate");
	    	ptr[count_ptr]->shift_of_origin();
	    	ptr[count_ptr]->menu();
	      break;

	    case 4:
	    	li.add_log("[CYLILNDRICAL SYSTEM] Conversion of elements of cylindrical system to other systems");
	    	ptr[count_ptr]->convert();
	    	ptr[count_ptr]->menu();
	      break;
/*
	    case 5:
	    	li.add_log("[CYLINDRICAL SYSTEM] Display of log of results of Cylindrical system");
	    	ptr[count_ptr]->log();
	    	ptr[count_ptr]->menu();
	      break;
*/
	    case 5:
	    	count_ptr++;
	    	r_obj.action();
	      break;

	    default:
	      cout<<"Please enter a valid choice!"<<endl;
	      ptr[count_ptr]->menu();
	    }
}

void Cylindrical::read(bool check)
{

	cout<<"Please enter in this format(rho, theta, z):"<<endl;
    cout<<"NOTE:: 'theta' in degrees"<<endl;
	  if(check)
	    {
	      for(int j=0;j<count;j++)
		    cin>>RHO[j]>>PHI[j]>>Z[j];
	    }
	  else
	    cin>>RHO[0]>>PHI[0]>>Z[0];
}

void Cylindrical::display(bool check)
{
	int j;
		  if(check)
		    {
		      for(j=0;j<count;j++)
			   cout<<"Co:ordinate "<<j+1<<": ["<<RHO[j]<<", "<<PHI[j]<<", "<<Z[j]<<"]"<<endl;
		    }
		  else
			  cout<<"Co-ordinate 1"<<": ["<<RHO[0]<<", "<<PHI[0]<<", "<<Z[0]<<"]"<<endl;
}

void Cylindrical::add()
{
	    cout<<"How many co-ordinates do you want to add(1 to 100)?"<<endl;
		cin>>count;
		Cylindrical::read(true);
		cout<<"\nEntered co-ordinates(s) are as follows:"<<endl;
		Cylindrical::display(true);

		//convert into normal cartesian co-ordinates
		for(j=0;j<count;++j)
		{
			X[j] = RHO[j]*cos((PI*PHI[j])/180.0);
			Y[j] = RHO[j]*sin((PI*PHI[j])/180.0);
		}

		//add them in the caartesian system
		for(j=0;j<count;++j)
		{
			X[count] += X[j];
			Y[count] += Y[j];
			Z[count] += Z[j];
		}

		//convert back into cylindrical system
		RHO[count+1] = sqrt(pow(X[count],2)+pow(Y[count],2));
		PHI[count+1] = atan2(Y[count], X[count]);

		//populate the result
		cout<<"Resultant of addition of co-ordinates is:"<<endl;
		RHO[0] = RHO[count+1];
		PHI[0] = PHI[count+1];
		Z[0] = Z[count];

		ptr[count_ptr]->display(false);
}

void Cylindrical::convert()
{
	ptr[count_ptr]->read(false);
				cout<<"Enter the system to which you want transformation to:"<<endl;
				cout<<"1 VECTOR CO-ORDINATE SYSTEM"<<endl
				    <<"2 SPHERICAL CO-ORDINATE SYSTEM"<<endl
				    <<"3 COMPLEX CO-ORDINATE SYSTEM"<<endl
				    <<"Please pick your choice:"<<endl;
				 cin>>wish;

				 //assign those values to global variables
				 rh = RHO[0];
				 ph = PHI[0];
				 z = Z[0];

				 switch(wish)
				 {
				 case 1:
					 con.convert_v(cyl);
					 //Converter::convert_s();
					 //ptr[count_ptr]->convert_s();
					 break;
				 case 2:
					 con.convert_s(cyl);
					 //ptr[count_ptr]->convert_cy();
					 break;
				 case 3:
					 con.convert_c(cyl);
					// ptr[count_ptr]->convert_v();
					 break;
				 default:
					 cout<<"Please enter a valid choice:"<<endl;
					 ptr[count_ptr]->convert();
				 }
}

void Cylindrical::log()
{

}

void Cylindrical::shift_of_origin()
{
	//read the co-ordinate to be transformed
   ptr[count_ptr]->read(false);

        //read the co-ordinates where to be transformed to
        cout<<"Enter the co-ordinates to which you want to shift origin to:"<<endl;
   		cin>>RHO[1]>>PHI[1]>>Z[1];
   		cout<<"After the shift of origin, the new co-ordinates are:"<<endl;

   		//convert into the cartesian system
   		X[0] = RHO[0]*cos((PI*PHI[0])/180.0);
   		Y[0] = RHO[0]*sin((PI*PHI[0])/180.0);
   		X[1] = RHO[1]*cos((PI*PHI[1])/180.0);
   		Y[1] = RHO[1]*sin((PI*PHI[1])/180.0);


   		//shift the origin
   		X[0] = X[0] - X[1];
   		Y[0] = Y[0] - Y[1];
   		Z[0] = Z[0] - Z[1];

   		//convert back into the cylindrical system
   		RHO[0] = sqrt(pow(X[0],2)+pow(Y[0],2));
   	    PHI[0] = atan2(Y[0], X[0]);

   	    //populate the co-ordinates after transformation
   	    cout<<"Coordinate after transformation:"<<endl;
   	    ptr[count_ptr]->display(false);
}

void Cylindrical::subtract()
{
	count = 2;
	      //read the co-ordinates
		  ptr[count_ptr]->read(true);
		  cout<<"\nEntered co-ordinates(s) are as follows:"<<endl;

		  //popuplate the co-ordinates
		  ptr[count_ptr]->display(true);

		  //convert into the cartesain co-ordinate system
		  X[0] = RHO[0]*cos((PI*PHI[0])/180.0) - RHO[1]*cos((PI*PHI[1])/180.0);
		  Y[0] = RHO[0]*sin((PI*PHI[0])/180.0) - RHO[1]*sin((PI*PHI[1])/180.0);
		  Z[0] = Z[0] - Z[1];

		  //convert back into the cylindrical system
		  RHO[0] = sqrt(pow(X[0],2)+pow(Y[0],2));
		  PHI[0] = atan2(Y[0], X[0]);

		  //populate the resultant co-ordinates
		  cout<<"Resultant of subtraction of co-ordinates is:"<<endl;
		  ptr[count_ptr]->display(false);
}


//**************************************** Spherical class **************************************************//
void Spherical::add()
{
	        cout<<"How many co-ordinates do you want to add(1 to 100)?"<<endl;
			cin>>count;
			ptr[count_ptr]->read(true);
			cout<<"\nEntered co-ordinates(s) are as follows:"<<endl;
			ptr[count_ptr]->display(true);

	  //convert into cartesian co-ordinate system
      for(j=0;j<count;++j)
       {
          X[j] = RHO[j]*sin((PI*THETA[j])/180.0)*cos((PI*PHI[j])/180.0);
          Y[j] = RHO[j]*sin((PI*THETA[j])/180.0)*sin((PI*PHI[j])/180.0);
          Z[j] = RHO[j]*cos((PI*THETA[j])/180.0);
       }

      //add the cartesian co-ordinates
     for(j=0;j<count;++j)
       {
	      X[count] += X[j];
	      Y[count] += Y[j];
	      Z[count] += Z[j];
       }

     //convert back into the spherical system
     RHO[0] = sqrt(pow(X[count],2) + pow(Y[count],2) + pow(Z[count],2));
     THETA[0] = atan2(sqrt(pow(X[count],2) + pow(Y[count],2)),Z[count]);
     PHI[0] = atan2(Y[count],X[count]);

     //populate the result
     cout<<"Resultant of addition of co-ordinates is:"<<endl;
     ptr[count_ptr]->display(false);

}

void Spherical::convert()
{
	ptr[count_ptr]->read(false);
			cout<<"Enter the system to which you want transformation to:"<<endl;
			cout<<"1 VECTOR CO-ORDINATE SYSTEM"<<endl
			    <<"2 CYLINDRICAL CO-ORDINATE SYSTEM"<<endl
			    <<"3 COMPLEX CO-ORDINATE SYSTEM"<<endl
			    <<"Please pick your choice:"<<endl;
			 cin>>wish;

			 //assign those values to global variables
			 rh = RHO[0];
			 th = THETA[0];
			 ph = PHI[0];

			 switch(wish)
			 {
			 case 1:
				 con.convert_v(sph);
				 //Converter::convert_s();
				 //ptr[count_ptr]->convert_s();
				 break;
			 case 2:
				 con.convert_cy(sph);
				 //ptr[count_ptr]->convert_cy();
				 break;
			 case 3:
				 con.convert_c(sph);
				// ptr[count_ptr]->convert_v();
				 break;
			 default:
				 cout<<"Please enter a valid choice:"<<endl;
				 ptr[count_ptr]->convert();
			 }
}

void Spherical::display(bool check)
{
	int j;
			  if(check)
			    {
			      for(j=0;j<count;j++)
				   cout<<"Co:ordinate "<<j+1<<": ["<<RHO[j]<<", "<<THETA[j]<<", "<<PHI[j]<<"]"<<endl;
			    }
			  else
				  cout<<"Co-ordinate 1"<<": ["<<RHO[0]<<", "<<THETA[0]<<", "<<PHI[0]<<"]"<<endl;
}

void Spherical::log()
{

}

void Spherical::menu()
{
	      cout<<"[CONVENTION]"<<endl
	    	  <<"#1 'rho' is the radius of the sphere measured from origin"<<endl
			  <<"#2 Angle 'theta' is measured with respect +ve z-axis"<<endl
			  <<"#3 Angle 'phi' is measured with respect +ve x-axis of the projection of line joining origin and point"<<endl;
	      cout<<"Here is a list of actions which can be implemented:\n"<<endl;
		  cout<<"[SPHERICAL SYSTEM]"<<endl
		      <<"1 Add members belonging to this system"<<endl
		      <<"2 Subtract members belonging to this system"<<endl
		      <<"3 Show members by shifting the origin"<<endl
		      <<"4 Convert members of this system to other systems"<<endl
		      //<<"5 Display the log of results stored in this system"<<endl
		      <<"5 Switch the system of operation to other system"<<endl
		      <<"Please pick your choice:\n";
		  cin>>wish;

		  switch(wish)
		  	    {
		  	    case 1:
		  	    	li.add_log("[SPHERICAL SYSTEM] Addition of co-ordinates");
		  	    	ptr[count_ptr]->add();
		  	    	ptr[count_ptr]->menu();
		  	      break;

		  	    case 2:
		  	    	li.add_log("[SPHERICAL SYSTEM] SUbtraction of co-ordinates");
		  	    	ptr[count_ptr]->subtract();
		  	    	ptr[count_ptr]->menu();
		  	      break;

		  	    case 3:
		  	    	li.add_log("[SPHERICAL SYSTEM] Shift of origin of co-ordinate");
		  	    	ptr[count_ptr]->shift_of_origin();
		  	    	ptr[count_ptr]->menu();
		  	      break;

		  	    case 4:
		  	    	li.add_log("[SPHERICAL SYSTEM] Conversion of elements of spherical system to other systems");
		  	    	ptr[count_ptr]->convert();
		  	    	ptr[count_ptr]->menu();
		  	      break;
/*
		  	    case 5:
		  	    	ptr[count_ptr]->log();
		  	    	ptr[count_ptr]->menu();
		  	      break;
*/
		  	    case 5:
		  	    	count_ptr++;
		  	    	r_obj.action();
		  	      break;

		  	    default:
		  	      cout<<"Please enter a valid choice!"<<endl;
		  	      ptr[count_ptr]->menu();
		  	    }
}

void Spherical::read(bool check)
{
	    cout<<"Please enter in this format(rho, theta, phi):"<<endl;
	    cout<<"NOTE:: 'theta' and 'phi' in degrees"<<endl;
		  if(check)
		    {
		      for(int j=0;j<count;j++)
			    cin>>RHO[j]>>THETA[j]>>PHI[j];
		    }
		  else
		    cin>>RHO[0]>>THETA[0]>>PHI[0];
}

void Spherical::shift_of_origin()
{

	//read the co-ordinate to be transformed
	   ptr[count_ptr]->read(false);

	        //read the co-ordinates where to be transformed to
	        cout<<"Enter the co-ordinates to which you want to shift origin to:"<<endl;
	   		cin>>RHO[1]>>THETA[1]>>PHI[1];
	   		cout<<"After the shift of origin, the new co-ordinates are:"<<endl;

	   		//convert into the cartesain system
	   		for(j=0;j<2;++j)
	   		    {
	   		        X[j] = RHO[j]*sin((PI*THETA[j])/180.0)*cos((PI*PHI[j])/180.0);
	   		        Y[j] = RHO[j]*sin((PI*THETA[j])/180.0)*sin((PI*PHI[j])/180.0);
	   		        Z[j] = RHO[j]*cos((PI*THETA[j])/180.0);
	   		    }

	   		//shift the origin
	   		X[0] = X[0] - X[1];
	   		Y[0] = Y[0] - Y[1];
	   		Z[0] = Z[0] - Z[1];

	   		//convert back into the spherical system
	   		RHO[0] = sqrt(pow(X[0],2) + pow(Y[0],2) + pow(Z[0],2));
	   		THETA[0] = atan2(sqrt(pow(X[0],2) + pow(Y[0],2)),Z[0]);
	   		PHI[0] = atan2(Y[0],X[0]);

	   		//populate the new co-ordinates
	   		ptr[count_ptr]->display(false);
}

void Spherical::subtract()
{
	count = 2;
	          //read the co-ordinates
			  ptr[count_ptr]->read(true);
			  cout<<"\nEntered co-ordinates(s) are as follows:"<<endl;

			  //populate the entered co-ordinates
			  ptr[count_ptr]->display(true);

			  //convert into the cartesain co-ordinate system
			  X[0] = RHO[0]*sin((PI*THETA[0])/180.0)*cos((PI*PHI[0])/180.0)
					  -RHO[1]*sin((PI*THETA[1])/180.0)*cos((PI*PHI[1])/180.0);
			  Y[0] = RHO[0]*sin((PI*THETA[0])/180.0)*sin((PI*PHI[0])/180.0)
		              -RHO[1]*sin((PI*THETA[1])/180.0)*sin((PI*PHI[1])/180.0);
			  Z[0] = RHO[0]*cos((PI*THETA[0])/180.0)
					  -RHO[1]*cos((PI*THETA[1])/180.0);

			  //convert back into the spherical system
			  RHO[0] = sqrt(pow(X[0],2) + pow(Y[0],2) + pow(Z[0],2));
			  THETA[0] = atan2(sqrt(pow(X[0],2) + pow(Y[0],2)),Z[0]);
			  PHI[0] = atan2(Y[0],X[0]);

			  //populate the result
			  cout<<"Resultant of difference of co-ordinates is:"<<endl;
			  ptr[count_ptr]->display(false);
}



//*****************************  linklist class for log of operations performed *****************************//


void linklist::get_log_num()
{
  cout<<"[LOG]"<<endl;
  cout<<"In total ["<<log_number<<"] operations are performed so far"<<endl;
  cout<<"Those operations are as follows:"<<endl;
  cout<<"\n";
}


//return the head of linklist
link *linklist::lfirst()
{
  return first;
}

void linklist::inc_log()
{
 ++log_number;
}

void linklist::add_log(char operation[])
{
  link *newlink = new link;

  //copy the operation performed
  strcpy(newlink->str,operation);

  //point to the next link
  newlink->next = first;

  //move the head of linklist
  first = newlink;

  //increment the log count
  linklist::inc_log();
}

void linklist::show_log(link *current)
{
  if(current == NULL)
    return;

  //call the function recursively
  show_log(current->next);
  std::cout<<current->str;
  std::cout<<"\n";
}



//*************************************** converter class function definitons *****************************//
void Converter::convert_v(sys wh)
{
    switch(wh)
     {
    case cyl:
    	x = rh*cos((PI*ph)/180.0);
    	y = rh*sin((PI*ph)/180.0);
    	break;
    case sph:
    	x = rh*sin((PI*th)/180.0)*cos((PI*ph)/180.0);
    	y = rh*sin((PI*th)/180.0)*sin((PI*ph)/180.0);
        z = rh*cos((PI*th)/180.0);
    	break;
    case com:
    	//same in-coming co-ordinates
    	break;
     }
    cout<<"Co-ordinate in vector system is:"<<endl;
    cout<<"Vector 1"<<": ["<<x<<", "<<y<<", "<<z<<"]"<<endl;
}

void Converter::convert_c(sys wh)
{
	   switch(wh)
	     {
	    case cyl:
	    	if(z!=0)
	    	  {
	    		 cout<<"Cannot transform, make sure that the vector lies in the x-y plane"<<endl;
	    		 cout<<"Give another try with z = 0"<<endl;
	    		 ptr[count_ptr]->convert();
	    	  }
	    	else
	    	{
	    		x = rh*cos((PI*ph)/180.0);
	    	    y = rh*sin((PI*ph)/180.0);
	    	}
	    	break;
	    case sph:
	    	if(rh*cos((PI*th)/180.0))
	    	{
	    	  cout<<"Cannot transform, make sure that theta = 90 degrees"<<endl;
	    	  cout<<"Give another try with z = 0"<<endl;
	    	  ptr[count_ptr]->convert();
	    	}
	    	else
	    	{
	    		x = rh*sin((PI*th)/180.0)*cos((PI*ph)/180.0);
	    	    y = rh*sin((PI*th)/180.0)*sin((PI*ph)/180.0);
	    	}
	    	break;
	    case vec:
	    	if(z!=0)
	    	{
	    		cout<<"Cannot transform, make sure that the vector lies in the x-y plane"<<endl;
	    		cout<<"Give another try with z = 0"<<endl;
	    		ptr[count_ptr]->convert();
	    	}

	    	break;
	     }
	    cout<<"Co-ordinate in complex system is:"<<endl;
	    cout<<"Number 1: "<<x<<" + j "<<y<<endl;
}

void Converter::convert_cy(sys wh)
{
	   switch(wh)
	     {
	    case vec:
              rh = sqrt(pow(x,2) + pow(y,2));
              th = atan2(y, x);
	    	break;
	    case sph:
	    	x = rh*sin((PI*th)/180.0)*cos((PI*ph)/180.0);
	    	y = rh*sin((PI*th)/180.0)*sin((PI*ph)/180.0);
	    	z = rh*cos((PI*th)/180.0);

	    	rh = sqrt(pow(x, 2) + pow(y, 2));;
	    	th = atan2(y, x);;
	    	break;
	    case com:
	    	rh = sqrt(pow(x, 2) + pow(y, 2));
	    	th = atan2(y, x);
	    	break;
	     }
	    cout<<"Co-ordinate in cylindrical system is:"<<endl;
	    cout<<"Co-ordinate 1"<<": [rho = "<<rh<<", theta =  "<<th<<" radians, z = "<<z<<"]"<<endl;
}

void Converter::convert_s(sys wh)
{
	   switch(wh)
	     {
	    case cyl:
	    	x = rh*cos((PI*ph)/180.0);
	    	y = rh*sin((PI*ph)/180.0);

	    	rh = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
	    	th = atan2(sqrt(pow(x,2) + pow(y,2)), z);
	    	ph = atan2(y, x);
	    	break;
	    case vec:
	    	rh = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
	        th = atan2(sqrt(pow(x,2) + pow(y,2)), z);
	        ph = atan2(y, x);
	    	break;
	    case com:
	    	rh = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
	    	th = atan2(sqrt(pow(x,2) + pow(y,2)), z);
	    	ph = atan2(y, x);
	    	break;
	     }
	    cout<<"Co-ordinate in spherical system is:"<<endl;
	    cout<<"Co-ordinate 1"<<": [rho = "<<rh<<", theta = "<<th<<" radians, phi = "<<ph<<" radians]"<<endl;
}
