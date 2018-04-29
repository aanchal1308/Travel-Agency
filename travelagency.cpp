
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>
#include<dos.h>
#include<fstream.h>
#include<ctype.h>
#include<string.h>
#include<process.h>

int i=0;

void startup();
int opening1();
void opening2();
void maketrfile();
void makehofile();
void places();

/*CLASS TRAVELAGENCY  CONSISTING OF FUNTIONS AND DATA MEMBERS RELATED
TO HOTEL ANDTRANSPORTATION  RESERVATIONS*/
class travelagency
{
private:

char name[50],destination[30],hotel[30],Phn[15],ans1,ans2,trans[30];
float price_hotel,price_trans;
int num_tickets,TYPE_HOTEL,num_days,num_rooms,MODE_TRANS; //DATA MEMBERS IN PRIVATE AREA
int fst,tst,nst;
int atr,ttr,rtr;

public:

int toggle;

void resho();
void showhotel();
void viewhorec();
void showhotelrec();
void delhotelrec();                    //MEMBER FUNTIONS FOR HOTEL RESERVATION.
void searchhotrec();
void edithoteldata();


void restr();
void showtransport();
void viewtrrec();
void showtransportrec();             //MEMBER FUNTIONS FOR TRANSPORT RESERVATION.
void deltransportrec();
void searchtransportrec();
void edittransportdata();


void assignprice();                      //FUNCTION TO CALCULATE price_hotel

void nindia(int ndes);
void sindia(int sdes);        //FUNCTIONS TO VIEW  DIFFERENT DESTINATIONS
void eindia(int wdes);
void windia(int edes);
void cindia(int cdes);

}user,user1[100];

/*   HOTEL RESERVATIONS */


/* FUNTION USED TO RESERVE HOTEL */
void travelagency::resho()
{
textbackground(BLUE);
clrscr();
ans1='N';
while(ans1!='Y')
{  clrscr();
cout<<endl<<endl<<endl;
cout<<"            Please Enter Information For Hotel Reservation"
<<endl<<endl<<endl<<endl;
cout<<"                 1: Five Star"<<endl<<endl;
cout<<"                 2: Three Star"<<endl<<endl;
cout<<"                 3: Normal"<<endl<<endl;
cout<<"            Please enter the choice of your hotel..";
cin>>TYPE_HOTEL;
clrscr();

assignprice();

clrscr();
cout<<endl<<endl;
cout<<"PLEASE FILL IN THE DETAILS ..."<<endl;
cout<<"                  HOTEL RESERVATION FORM"<<endl;
cout<<"             _____________________________"<<endl<<endl;
cout<<"Name: ";
gets(name);
cout<<endl<<"Contact no.: ";
gets(Phn);
cout<<endl<<"Destination: ";
gets(destination);
cout<<endl<<"Name of Hotel: ";
gets(hotel);
cout<<endl<<"No. of days to stay: ";
cin>>num_days;
cout<<endl<<"No. of Rooms to be Reserved" ;
cin>>num_rooms;
cout<<endl<<endl<<"Is the information correct(y/n)?? ";
cin>>ans1;
ans1=toupper(ans1);
}
showhotel();
}


/*FUNTION USED TO MAKE HOTEL RECORD.*/

void makehofile()
{
fstream fil;
fil.open("hotel.dat",ios::binary | ios::out |ios::app );
user1[i].toggle=1;
user1[i].resho();
fil.write((char*)&user1[i],sizeof (user1[i]));
fil.close();
}

/* FUNTION USED TO SHOW HOTEL RESERVATIONS */


void travelagency::showhotel()
{
int a,b;
if(TYPE_HOTEL==1)
price_hotel=(fst*num_rooms*num_days);
else
if(TYPE_HOTEL==2)
price_hotel=(tst*num_rooms*num_days);
else
if(TYPE_HOTEL==3)
price_hotel=(nst*num_rooms*num_days);

if(toggle==1)
{

textcolor(WHITE);
textbackground(BLUE);
clrscr();
for(int h=25;h<50;h++)
{
cout<<endl<<endl<<"           Please wait while we make the Reservation"<<endl;
gotoxy(10+h,20);cout<<"ÛÛ";
delay(100);
}
toggle=0;
}
textbackground(BLUE);
clrscr();

cout<<endl<<endl;
cout<<"                            Hotel     Reservation  "<<endl;
cout<<"                           -----------------------"<<endl<<endl<<endl;
cout<<"            Name:"<<strupr(name)<<endl<<endl;
cout<<"            Contact no.:"<<strupr(Phn)<<endl<<endl;
cout<<"            Name of the hotel:  "<<strupr(hotel)  <<" , "<<strupr(destination)<<endl<<endl;
cout<<"            No. of Days to stay: "<<num_days<<endl;
cout<<"             No. of rooms reserved: "<<num_rooms<<endl<<endl;
cout<<"             Your Reservations have been done ."<<endl<<
"              Please pay the Amount!"<<endl<<endl;
cout<<"                Amount: Rs."<<setprecision(2)<<price_hotel<<endl;
getch();

}

/*FUNTION USED TO VIEW HOTEL RECORDS.*/

void travelagency::viewhorec()
{
textbackground(BLUE);
clrscr();
int option;

cout<<endl<<endl;
cout<<"            HOTEL RESERVATION INFORMATION"<<endl<<endl<<endl<<endl;

cout<<"            1: View hotel reservation records"<<endl<<endl;
cout<<"            2: Delete a particular record"<<endl<<endl;
cout<<"            3: Search for a record"<<endl<<endl;
cout<<"            4: Edit a record "<<endl<<endl;
cout<<"            5: Exit "<<endl<<endl<<endl<<endl;
cout<<"           please enter the desired option..";cin>>option;
if(option!=5)
{
switch(option)
{
case 1:showhotelrec();
break;
case 2:delhotelrec();
break;
case 3:searchhotrec();
break;
case 4:edithoteldata();
break;
}
}    }


/*FUNTION USED TO SHOW ALL HOTEL RESERVATIONS*/\

void travelagency::showhotelrec()
{

fstream fil1;

fil1.open("hotel.dat",ios::binary|ios::in);

while(fil1.read((char*)&user,sizeof (user)))
{
user.showhotel();
}
fil1.close();
}


/*FUNTION USED TO DELETE A HOTEL RECORD.*/

void travelagency::delhotelrec()
{
clrscr();
char confirm;
char dname[20];
cout<<endl<<endl<<"  Enter name to delete record for..."<<endl;
gets(dname);
strupr(dname);

fstream  fil2,fil3;
int del=0;

fil2.open("hotel.dat",ios::binary | ios::in);
fil3.open("temp.dat",ios::binary | ios::out);

while(fil2.read ((char*)&user,sizeof (user)))
{
if ((strcmp(name,dname))==0)
{ user.showhotel();
del++;
cout<<"Are you sure, you want to delete this record?(y/n).."<<endl<<endl;
cin>>confirm;
if (confirm=='n')
fil3.write((char*)&user,sizeof(user));
}
else
fil3.write((char*)&user,sizeof (user));

}
if((del!=0) && (confirm=='y'))
cout<<endl<<"                         ...Deleted...";
else
cout<<endl<<"                     ...Record not found..";
getch();
fil2.close();
fil3.close();
remove("hotel.dat");
rename("temp.dat", "hotel.dat");

}


/*FUNTION USED TO SEARCH FOR A HOTEL RECORD.*/

void travelagency::searchhotrec()
{
clrscr();

char sname[20];
cout<<"Enter Name to search for.."<<endl;
gets(sname);
strupr(sname);

fstream fil4;
fil4.open("hotel.dat",ios::binary | ios::in);

int srch=0;

while(fil4.read((char*)&user,sizeof (user)))
{
if(strcmp(name,sname)==0)
{
srch++;
user.showhotel();
}
}
if(srch==0)
cout<<"                         No Record Exists";
fil4.close();
getch();
}


/*FUNTION USED TO EDIT A  HOTEL RECORD.*/

void travelagency::edithoteldata()
{
clrscr();
char ename[30];
int ede=0;

cout<<endl<<endl;
cout<<"Enter Name to Edit Record for..."<<endl;
gets(ename);
strupr(ename);

fstream fil5,fil6;
fil5.open("hotel.dat",ios::binary | ios::in) ;
fil6.open("temp1.dat",ios::binary | ios::out ) ;

while(!fil5.eof())
{
fil5.read((char*)&user,sizeof(user));
if (strcmp (ename,name)==0)
{ cout<<"Now, enter the new details for reresvation"<<endl;
restr();
ede++;
}
fil6.write((char*)&user,sizeof (user));
}
if(ede==0)
cout<<"Record doesn't exist!!"<<endl;
else
cout<<" Record successfully updated!!"<<endl;
getch();
fil5.close();
fil6.close();
remove("hotel.dat");
rename("temp1.dat","hotel.dat");

}

            /*_________________________________________________________________________*/

/*TRANSPORTATION RESERVATIONS*/



/*FUNTION USED TO RESERVE TRANSPORTATION.*/

void travelagency::restr()
{textbackground(BLUE);
textcolor(GREEN);
clrscr();
ans2='N';
while(ans2!='Y')
{
clrscr();
cout<<endl<<endl<<endl<<endl;
cout<<"          Please enter the choice of your mode of transportaion......"<<endl<<endl;
cout<<"         1: by Air"<<endl<<endl;
cout<<"         2: by Train"<<endl<<endl;
cout<<"         3: by Road"<<endl<<endl;
cout<<"......";cin>>MODE_TRANS;
clrscr();

assignprice();

clrscr();
            cout<<endl<<endl<<endl;
cout<<"           PLEASE FILL IN THE DETAILS .."<<endl<<endl;
cout<<"                 TRANSPORT RESERVATION FORM"<<endl;
cout<<"_____________________________________________________________"<<endl<<endl;
cout<<"Name: ";
gets(name);
cout<<endl<<"Contact no.: ";
gets(Phn);
cout<<endl<<"Destination: ";
gets(destination);
cout<<endl<<"Mode of Transport: ";
gets(trans);
cout<<endl<<"Number of Tickets to be Reserved: " ;
cin>>num_tickets;
cout<<endl<<"Is the information correct(y/n)?? ";
cin>>ans2;
ans2=toupper(ans2);
}
showtransport();
}

/*FUNTION USED TO MAKE TRANSPORT RECORD.*/

void maketrfile()
{
fstream fil;
fil.open("transport.dat",ios::binary | ios::out |ios::app);
user1[i].toggle=1;
user1[i].restr();
fil.write((char*)&user1[i],sizeof (user1[i]));
fil.close();
}


/*FUNTION USED TO SHOW TRANSPORT RESERVATION.*/

void travelagency::showtransport()
{
if(MODE_TRANS==1)
price_trans=atr*num_tickets;
else
if(MODE_TRANS==2)
price_trans=ttr*num_tickets;
else
if(MODE_TRANS==3)
price_trans=rtr*num_tickets;

if(toggle==1)
{
clrscr();
gotoxy(20,8);cout<<"Please wait while we make the Reservation";
for(int h=25;h<50;h++)
{

gotoxy(h,10);cout<<"Û";
delay(250);
}
toggle=0;
}


clrscr();
cout<<endl<<endl;
cout<<"                            Transport    Reservation  "<<endl;
cout<<"                           -----------------------"<<endl<<endl<<endl;
cout<<"            Name:"<<strupr(name)<<endl<<endl;
cout<<"            Contact no.:"<<strupr(Phn)<<endl<<endl;
cout<<"            Mode of transportation:    "<<strupr(trans)<<endl<<endl;
cout<<"            Destination:"<<strupr(destination)<<endl<<endl;
cout<<"            No.  tickets reserved: "<<num_tickets<<endl<<endl;
cout<<"                 Your Reservations have been done ."<<endl<<endl<<endl<<
"                 Please pay the Amount!"<<endl<<endl;
cout<<"                Amount: Rs."<<setprecision(2)<<price_trans<<endl;
getch();
}


/*FUNTION USED TO VIEW TRANSPORT RECORDS.*/

void travelagency::viewtrrec()
{
int option;
while(option!=5)
{textcolor(YELLOW);
textbackground(BLUE);
clrscr();
cout<<endl<<endl;
cout<<"            TRANSPORT RESERVATION INFORMATION"<<endl<<endl<<endl<<endl;

cout<<"            1: View all transport reservation records"<<endl<<endl;
cout<<"            2: Delete a particular record"<<endl<<endl;
cout<<"            3: Search for a record"<<endl<<endl;
cout<<"            4: Edit a record "<<endl<<endl;
cout<<"            5: Exit "<<endl<<endl<<endl<<endl;
cout<<"           please enter the desired option..";
cin>>option;

switch(option)
{
case 1:showtransportrec();
break;
case 2:deltransportrec();
break;
case 3:searchtransportrec();
break;
case 4:edittransportdata();
break;
}
}
}


/*FUNTION USED TO SHOW ALL TRANSPORT RECORDS.*/

void travelagency::showtransportrec()
{
fstream file1;
file1.open("transport.dat",ios::binary|ios::in);
while(file1.read((char*)&user,sizeof (user)))
user.showtransport();
file1.close();
}



/*FUNTION USED TO DELETE A  TRANSPORT RECORDS.*/

void travelagency::deltransportrec()
{ textbackground(BLUE);
clrscr();

char confirm;
char dname[20];
cout<<endl<<endl<<"  Enter name to delete record for..."<<endl;
gets(dname);
strupr(dname);

fstream  fil2,fil3;
int del=0;

fil2.open("transport.dat",ios::binary | ios::in);
fil3.open("temp3.dat",ios::binary | ios::out);

while(fil2.read ((char*)&user,sizeof (user)))
{
if ((strcmp(name,dname))==0)
{ user.showtransport();
del++;
cout<<"Are you sure, you want to delete this record?(y/n).."<<endl<<endl;
cin>>confirm;
if (confirm=='n')
fil3.write((char*)&user,sizeof(user));
}
else
fil3.write((char*)&user,sizeof (user));

}
if((del!=0) && (confirm=='y'))
cout<<endl<<"                         ...Deleted...";
else
cout<<endl<<"                     ...Record not found..";
getch();
fil2.close();
fil3.close();
remove("transport.dat");
rename("temp3.dat", "hotel.dat");

}


/*FUNTION USED TO SEARCH FOR A TRANSPORT RECORDS.*/

void travelagency::searchtransportrec()
{
clrscr();
char sename[20];
gotoxy(20,5);cout<<"Enter Name to search for..";
gotoxy(25,7);gets(sename);
strupr(sename);
fstream file4;
file4.open("transport.dat",ios::binary | ios::in);
int serch=0;
while(file4.read((char*)&user,sizeof (user)))
{
if(strcmp(name,sename)==0)
{
serch++;
user.showtransport();
}
}
if(serch==0)
cout<<"                       No Record Exists";
file4.close();
getch();
}



/*FUNTION USED TO EDIT TRANSPORT RECORD.*/

void travelagency::edittransportdata()
{
clrscr();
char ename[30];
int ede1=0;
cout<<endl<<endl;
cout<<"Enter Name to Edit Record for..."<<endl;
gets(ename);
strupr(ename);

fstream fil5,fil6;
fil5.open("transport.dat",ios::binary | ios::in) ;
fil6.open("temp2.dat",ios::binary | ios::out ) ;

while(!fil5.eof())
{
fil5.read((char*)&user,sizeof(user));
if (strcmp (ename,name)==0)
{ cout<<"Now, enter the new details for reresvation"<<endl;
resho();
ede1++;
}
fil6.write((char*)&user,sizeof (user));
}
if(ede1==0)
cout<<"Record doesn't exist!!"<<endl;
else
cout<<" Record successfully updated!!"<<endl;
getch();
fil5.close();
fil6.close();
remove("transport.dat");
rename("temp2.dat","transport.dat");
}





/***** MAIN FUNTION USED TO CALL OTHER FUNTIONS *******/

/*_________________________________________________________________________*/


void main()
{
clrscr();
cout.setf(ios::fixed,ios::floatfield);
cout.setf(ios::showpoint);
startup();                       //FUNTION TO DISPLAY INTRODUCTION SCREEN
int opt;

opt=opening1();                  //FUNTION CALL TO DISPLAY MENU
switch(opt)
{
case 1:places();                //FUNTION CALL TO VIEW PLACES
break;
case 2:                         //FUNTION CALL TO RESERVE TRANSPORT
maketrfile();i++;
break;
case 3:                         //FUNTION CALL TO RESERVE HOTEL
makehofile();i++;
break;
case 4:clrscr();
int search1;
cout<<endl<<endl;
cout<<"                    VIEW EXISTING RECORDS  "  <<endl;
cout<<"____________________________________________________________________"<<endl<<endl;
cout<<"                   1: Hotel Reservation Records"<<endl<<endl;
cout<<"                   2: Transport Reservation Records"<<endl<<endl;\
cout<<endl<<endl;
cout<<"        Choose the desired option....";cin>>search1;

switch(search1)
{
case 1:user.viewhorec();    //FUNTION CALL FOR HOTEL RECORDS
break;
case 2:user.viewtrrec();    //FUNTION CALL FOR TRANSPORT RECORDS
break;
}
break;
case 5: exit(0);
}
}



/*FUNTION USED TO DISPLAY INTRODUCTION SCREEN*/

void startup()
{
int a;
for(a=50;a>30;a--)
{
clrscr();
textcolor(WHITE);
textbackground(BROWN);
gotoxy(25,10);cout<<"Welcome to the TRAVEL AGENCY";
delay(30);
}
for(a=22;a<52;a++)
{
gotoxy(a,18);cout<<"...";
delay(50);
}
delay(500);

textcolor(WHITE);
textbackground(BLUE);

clrscr();
cout<<endl<<endl<<endl<<endl;
cout<<"     ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ"<< endl<<endl;

cout<<"         ÛÛÛÛÛÛ   Û      Û     ÛÛÛÛÛÛ  Û                  ÛÛÛÛÛ    ÛÛÛÛÛÛ    ÛÛÛÛÛÛ	   "<< endl;
cout<<"         Û                  Û     Û     Û            Û  Û                  Û         Û    Û           Û    Û                  "<< endl;
cout<<"         ÛÛÛÛ           ÛÛ        ÛÛÛÛÛÛ   Û                  Û         Û    ÛÜÜÜÜÛ   ÛÛÛÛ 	   "<< endl;
cout<<"         Û                  Û    Û      Û                 Û                  Û         Û    Û Û             Û                    "<< endl;
cout<<"         ÛÛÛÛÛÛ   Û      Û     Û                  ÛÛÛÛÛÛ  ÛÛÛÛÛ    Û     Û         ÛÛÛÛÛÛ       "<< endl<<endl;

cout<<"     ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ    "<< endl<<endl;

cout<<"                ÜÜÜÜÜÜ  Ü         Ü     ÜÜÜÜÜÜ  ÜÜÜÜÜÜ   ÜÜÜÜÜÜ  "<< endl;
cout<<"                        Û         ÛÛ      Û    Û            Û         Û          Û            Û  "<< endl;
cout<<"                        Û         Û   Û   Û    Û            Û         Û          ÛÜÜÜÜÛ  "<< endl;
cout<<"                        Û         Û     Û Û    Û            Û         Û           Û           Û  "<< endl;
cout<<"                ÜÜÜÛÜÜ   Ü        Û     ÛÛÛÜÜÜ  ÜÛÜÜÜÛ    Ü          Ü  "<< endl<<endl;

cout<<"              ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ  "<< endl;



gotoxy(25,25);
cout<<"Press any key to continue...";
getch();
}

/*FUNTION USED TO DISPLAY MENU*/

int opening1()
{
int pass;
clrscr();
textcolor (WHITE);
textbackground (MAGENTA);
{ clrscr();
cout<<endl<<endl<<endl<<endl;
cout<<endl<<endl<<endl;
cout<< "       What would you like us to do for you?"<<endl<<endl<<endl;
cout<<"       1: View Tourist Places"<<endl<<endl;
cout<<"       2: Reserve Transportation"<<endl<<endl;
cout<<"       3: Reserve Accomodation"<<endl<<endl;
cout<<"       4: View Existing Bookings"<<endl<<endl;
cout<<"       5: Exit"<<endl<<endl;
cout<<"       Enter the desired option (1,2,3,4 or 5) "<<endl<<endl;
delay(100);
}

for(int f=1;f<20;f++)
{
gotoxy(3,f);cout<<"Î";gotoxy(78,f);cout<<"Î";
delay(50);
}
gotoxy(48,21);cin>>pass;
return(pass);
}

//function to display menu with places

void opening2()
{
int opt2;
gotoxy(10,21);cout<<"1: Reserve Transportation";
gotoxy(10,22);cout<<"2: Reserve Accomodation";
gotoxy(10,23);cout<<"3: Reserve Transportation and Accomodation";
gotoxy(10,24);cout<<"4: Exit   ";
gotoxy(10,25);cout<<"please enter desired option  ";cin>>opt2;
if(opt2!=4)
{
switch(opt2)
{
case 1:maketrfile();i++;
break;
case 2:makehofile();i++;
break;
case 3:maketrfile();i++;
makehofile();i++;
break;
}
}
}


/*FUNTION USED TO DISPLAY CHOICE OF DESTINATION*/

void places()
{
int des;
textcolor(YELLOW);
textbackground(BLUE);
{
clrscr();
gotoxy(14,6);cout<<"Exciting places all over India.." <<endl<<endl<<endl;
cout<<"          ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»  "<<endl;
cout<<"          º                                          º "<<endl;
cout<<"          º      1.NORTH INDIA        º "<<endl;
cout<<"          º      2.SOUTH INDIA         º "<<endl;
cout<<"          º      3.EAST INDIA             º "<<endl;
cout<<"          º      4.WEST INDIA            º "<<endl;
cout<<"          º      5.CENTRAL INDIA      º "<<endl;
cout<<"          º      6.EXIT                          º "<<endl;
cout<<"          º                                           º "<<endl;
cout<<"          ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÐ    "<<endl;
delay(50);
}

gotoxy(14,22);cout<<"Enter your choice..";cin>>des;
int des1;
if (des!=6)
{
switch(des)
{
case 1: {
clrscr();
gotoxy(14,6);cout<<"CHOOSE YOUR DESTINATION "<<endl<<endl<<endl;
cout<<"        ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ» "<<endl;
cout<<"        º                                                	  º "<<endl;
cout<<"        º      1.JAMMU & KASHMIR        º "<<endl;
cout<<"        º      2.HIMACHAL PRADESH       º "<<endl;
cout<<"        º      3.EXIT                          	  º "<<endl;
cout<<"        º                            	                º "<<endl;
cout<<"        º                             		  º "<<endl;
cout<<"        ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÐ "<<endl;

}
delay(100);
gotoxy(14,22);cout<<"Enter the desired option..";cin>>des1;
if(des1!=4)
user.nindia(des1);
break;

case 2:  {
clrscr();
gotoxy(14,6);cout<<"CHOOSE YOUR DESTINATION"<<endl<<endl<<endl;
cout<<"          ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ» "<<endl;
cout<<"          º                          		               º "<<endl;
cout<<"          º      1.KERELA               		  º "<<endl;
cout<<"          º      2.ANDAMAN AND NICOBAR         º "<<endl;
cout<<"          º      3.EXIT                 			  º "<<endl;
cout<<"          º                             			  º "<<endl;
cout<<"          ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÐ "<<endl;
delay(100);
}
gotoxy(14,22);cout<<"Enter the desired option.." ;cin>>des1;
if(des1!=5)
user.sindia(des1);
break;

case 3: {
clrscr();
gotoxy(14,6);cout<<"CHOOSE YOUR DESTINATION"<<endl<<endl<<endl;
cout<<"       ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ» "<<endl;
cout<<"       º                               º "<<endl;
cout<<"       º      1.ASSAM                  º "<<endl;
cout<<"       º      2.WEST BENGAL     º "<<endl;
cout<<"       º      3.EXIT                        º "<<endl;
cout<<"       º                                        º "<<endl;
cout<<"       ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÐ "<<endl;
delay(50);
}
gotoxy(14,22);cout<<"Enter the desired option.." ;cin>>des1;
if(des1!=4)
user.eindia(des1);
break;

case 4:	{ clrscr();
gotoxy(14,6);cout<<"CHOOSE YOUR DESTINATION"<<endl<<endl<<endl;
cout<<"        ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ» " <<endl;
cout<<"        º                                             º "<<endl;
cout<<"        º          1.GUJARAT               º "<<endl;
cout<<"        º          2.RAJASTHAN          º "<<endl;
cout<<"        º          3.EXIT         	    º "<<endl;
cout<<"        º                           		    º "<<endl;
cout<<"        º                              	   º "<<endl;
cout<<"        ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÐ "<<endl;
}
delay(50);

gotoxy(14,22);cout<<"Enter the desired option.." ;cin>>des1;
if(des1!=3)
user.windia(des1);
break;

case 5:	{clrscr();
gotoxy(14,6);cout<<"CHOOSE YOUR DESTINATION"<<endl<<endl<<endl;
cout<<"              ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ» "<<endl;
cout<<"              º                                       	   º "<<endl;
cout<<"              º                                		    º "<<endl;
cout<<"              º        (1) ORISSA           	    º "<<endl;
cout<<"              º        (2) MADHYA PRADESH    º "<<endl;
cout<<"              º        (3) EXIT             		    º "<<endl;
cout<<"              º                              		   º "<<endl;
cout<<"              º                              		   º "<<endl;
cout<<"              ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÐ "<<endl<<endl<<endl<<endl;
}
delay(50);
gotoxy(14,22);cout<<"Enter the desired option.." ;cin>>des1;
if(des1!=3)
user.cindia(des1);
break;

}
}
}


/*FUNTION USED TO DISPLAY NORTH-INDIA INFORMATION.*/

void travelagency::nindia(int ndes)
{textcolor(WHITE);
textbackground(RED);
clrscr();
switch(ndes)
{
case 1: clrscr();
gotoxy(25,1);cout<<"Jammu and Kashmir ";
gotoxy(24,2);cout<<"___________________";
gotoxy(20,3);cout<<"Places To Visit::        -Kashmir-    -Jammu- "<<"\n";

gotoxy(5,4);cout<<"Transportation Available::(from delhi)"<<"\n";
cout<<"    MODE      Place        NAME                   price          Timings         "<<"\n";
cout<<"  BY Air        jam.         042 I.A.                 12000Rs.     8:00(d)- 9:40(a)"<<"\n";
cout<<"  BY Train    kash.      Kashmir Express   2500Rs.      13:00(d)-18:00(a)"<<endl;
cout<<"  By Train     jam.      Jammu Mail            2500Rs.      15:00(d)-16:30(a)"<<"\n";
cout<<"  By Road    kash.           Bus                      700Rs.      12:00(d)-20:00(a)"<<"\n";

gotoxy(5,12);cout<<"Accomodation Available::"<<endl;

cout<<"   Star      Place        NAME Of Hotel         Tariff      "<<"\n";
cout<<"    5        kashmir        Kashmir             11000Rs            "<<"\n";
cout<<"    3        jammu          passenger           6000Rs.         "<<"\n";
cout<<"  normal    kashmir         rest               3000Rs.           "<<endl;

cout<<setw(10)<<" NOTE::(The Tarrif does not include meals )     ";

atr=12000;ttr=2500;rtr=700;fst=11000;tst=6000;nst=3000;
opening2();
break;




case 2:clrscr();
gotoxy(25,1);cout<<" HIMACHAL PRADESH";
gotoxy(24,2);cout<<"____________________"<<endl;
cout<<"     Places To Visit::         -Shimla-         -Manali-      "<<endl;

cout<<"  Transportation Available::(from Delhi)"<<endl;
cout<<"   MODE            Place           NAME                  price                     Timings       "<<endl;
cout<<"  BY Air             shi.             151 I.A.                10000Rs.       12:30(d)-13:30(a)"<<endl;
cout<<"  BY Air            man.            152 I.A.                10000Rs.       6:50(d)- 7:40(a)"<<endl;
cout<<"  BY Train          shi.       Himachal Express    2000Rs.        13:00(d)-19:00(a)"<<endl;
cout<<"  By Train         man.        kalka Mail               2000Rs.        14:00(d)-19:30(a)"<<endl;
cout<<"  By Road          shi.                Bus                      800Rs.          12:00(d)-20:00(a)"<<endl;

cout<<"  Accomodation Available::"<<endl;
cout<<"   Star      Place        NAME Of Hotel              Tariff       "<<endl;
cout<<"    5            shi              chamba                       12000Rs          "<<endl;
cout<<"    5            man           chanakya                  12000Rs.          "<<endl;
cout<<"    3             shi             geetanjali                  7000Rs.          "<<endl;
cout<<"    3            man           parkview                    7000Rs.         "<<endl;
cout<<"  normal    man         mountview                 1000Rs.          "<<endl;
cout<<setw(10)<<"          NOTE::(The Tarrif does not include meals)     ";

atr=10000;ttr=2000;rtr=800;fst=12000;tst=7000;nst=1000;
opening2();
break;
}
}


/*FUNTION USED TO DISPLAY SOUTH-INDIA INFORMATION.*/

void travelagency::sindia(int sdes)
{
textcolor(WHITE);
textbackground(RED);
clrscr();
switch(sdes)
{
case 1:clrscr();
gotoxy(25,1);cout<<"      KERELA ";
gotoxy(24,2);cout<<"------------------";
gotoxy(20,3);cout<<"Places To Visit::         -Trivandram-    -Kochi- "<<endl;

gotoxy(5,4);cout<<"Transportation Available::(from delhi)"<<endl;
cout<<"   MODE       Place        NAME           price               Timings     "<<endl;
cout<<"  BY Air      tri.           141 I.A.          15000Rs.         13:50(d)-16:30(a)"<<endl;
cout<<"  BY Air      koc.        142 I.A.            15000Rs.          8:00(d)-11:40(a)"<<endl;
cout<<"  BY Train    tri.   Kerela Express    3500Rs.         06:00(d)-18:00(a)"<<endl;
cout<<"  By Train    koc.     Kochi Mail       3500Rs.         05:00(d)-16:30(a)"<<endl;
cout<<"  By Road     tri.           Bus               1200Rs.          05:00(d)-22:00(a)"<<endl;
cout<<"  By Road     koc.        Bus                1200Rs.          05:00(d)-23:00(a)"<<endl;

gotoxy(5,12);cout<<"Accomodation Available::"<<endl;
cout<<"   Star       Place        NAME Of Hotel            Tariff  "<<endl;
cout<<"    5         tri            Manum_rooms                 15000Rs        "<<endl;
cout<<"    5         koc           holiday                15000Rs.          "<<endl;
cout<<"    3         tri          South park              8000Rs.         "<<endl;
cout<<"    3         koc          passenger               8000Rs.          "<<endl;
cout<<"  normal    koc          Jas                     5000Rs.           "<<endl;
cout<<setw(10)<<"          NOTE::(The Tarrif doesnot include meals except breakfast)     ";

atr=15000;ttr=3500;rtr=1200;fst=15000;tst=8000;nst=5000;
opening2();
break;

case 2:clrscr();
gotoxy(25,1);cout<<"ANDAMAN AND NICOBAR";
gotoxy(24,2);cout<<"-------------------";
gotoxy(20,3);cout<<"Places To Visit::         -Port Blair-    "<<endl;

gotoxy(5,4);cout<<"Transportation Available::(from delhi)"<<endl;
cout<<"   MODE     Place       NAME          price                  Timings          "<<endl;
cout<<"  BY Air       P.b.        151 I.A.     15000Rs.         12:30(d)-16:30(a)"<<endl;
cout<<"  BY Ship    P.b.          Ship         2000Rs.           13:00(d)-19:00(a)"<<endl;
cout<<"  By Road   P.b.           N.a.                                                               "<<endl;

gotoxy(5,12);cout<<"Accomodation Available::"<<endl;
cout<<"   Star       Place        NAME Of Hotel          Tariff  "<<endl;
cout<<"    5            P.b.            chamba                   9000Rs           "<<endl;
cout<<"    3            P.b.           geetanjali                6000Rs.         "<<endl;
cout<<"  normal    P.b.           guest                       2000Rs.        "<<endl;
cout<<setw(10)<<"          NOTE::(The Tarrif doesnot include meals )";

atr=15000;ttr=2000;rtr=0;fst=9000;tst=6000;nst=2000;
opening2();
break;
}
}


/* FUNTION USED TO DISPLAY EAST-INDIA INFORMATION.*/

void travelagency::eindia(int edes)
{
textcolor(WHITE);
textbackground(RED);
clrscr();
switch(edes)
{
case 1:clrscr();
gotoxy(25,1);cout<<"      ASSAM ";
gotoxy(24,2);cout<<"------------------";
gotoxy(20,3);cout<<"Places To Visit::         -Guwahati-     "<<endl;
gotoxy(5,4);cout<<"Transportation Available::(from delhi)"<<endl;
cout<<"   MODE      Place        NAME                   price                Timings          "<<endl;
cout<<"  BY Air        Guw.        045 I.A.             12000Rs.       11:50(d)-15:30(a)"<<endl;
cout<<"  BY Train   Guw.      Assam Express    2500Rs.        08:00(d)-18:00(a)"<<endl;
cout<<"  By Road    Guw.         Bus                    700Rs.           12:00(d)-20:00(a)"<<endl;

gotoxy(5,12);cout<<"Accomodation Available::"<<endl;
cout<<"   Star          Place        NAME Of Hotel         Tariff  "<<endl;
cout<<"    5              Guw          Regency                    9000Rs.         "<<endl;
cout<<"    3              Guw          Nandan                     6000Rs.        "<<endl;
cout<<"  normal     Guw          Corneto                    2000Rs.         "<<endl;
cout<<setw(10)<<" NOTE::(The Tarrif doesnot include meals except breakfast)     ";

atr=12000;ttr=2500;rtr=700;fst=9000;tst=6000;nst=2000;
opening2();
break;

case 2:clrscr();
gotoxy(25,1);cout<<"    WEST BENGAL";
gotoxy(24,2);cout<<"------------------";
gotoxy(20,3);cout<<"Places To Visit::         -Calcutta-    -Darjiling- "<<endl;

gotoxy(5,4);cout<<"Transportation Available::(from delhi)"<<endl;
cout<<"   MODE        Place        NAME                     price                        Timings     "<<endl;
cout<<"  BY Air          Cal.         451 I.A.                   12000Rs.         12:30(d)-13:30(a)"<<endl;
cout<<"  BY Air          Dar.        452 I.A.        	12000Rs.         6:50(d)- 7:40(a)"<<endl;
cout<<"  BY Train      Cal.      Rajdhani Express     2000Rs.          08:00(d)-19:00(a)"<<endl;
cout<<"  By Train       Dar.      kalka Mail       	 2000Rs.         09:00(d)-19:30(a)"<<endl;
cout<<"  By Road       Cal.            Bus             	800Rs.             05:00(d)-20:00(a)"<<endl;

gotoxy(5,12);cout<<"Accomodation Available::"<<endl;
cout<<"   Star      Place        NAME Of Hotel              Tariff  "<<endl;
cout<<"    5            Cal            Continental              14000Rs          "<<endl;
cout<<"    5            Dar            Diplomat                 14000Rs.          "<<endl;
cout<<"    3             Cal           geetanjali                7000Rs.          "<<endl;
cout<<"    3             Dar           parkview                  7000Rs.          "<<endl;
cout<<"  normal     Dar           Paragon                    1500Rs.           "<<endl;
cout<<setw(10)<<"          NOTE::(The Tarrif doesnot include meals )     ";

atr=12000;ttr=2000;rtr=800;fst=14000;tst=7000; nst=1500;
opening2();
break;
}
}


/*FUNTION USED TO DISPLAY WEST-INDIA INFORMATION. */

void travelagency::windia(int wdes)
{
textcolor(WHITE);
textbackground(RED);
clrscr();
switch(wdes)
{
case 1:clrscr();
gotoxy(25,1);cout<<"     GUJARAT ";
gotoxy(24,2);cout<<"------------------";
gotoxy(20,3);cout<<"Places To Visit::         -Ahmedabad-    -Gandhinagar- "<<endl;

gotoxy(5,4);cout<<"Transportation Available::(from delhi)"<<endl;
cout<<"   MODE       Place        NAME                             price                        Timings     "<<endl;
cout<<"  BY Air        Ahm.        045 I.A.     		       12000Rs.         13:50(d)-15:30(a)"<<endl;
cout<<"  BY Air         Gan.        045 I.A.       	                 12000Rs.         8:00(d)- 9:40(a)"<<endl;
cout<<"  BY Train    Ahm.       Ahmedabad Express        2500Rs.           11:00(d)-18:00(a)"<<endl;
cout<<"  By Train    Gan.        Gujarat Mail      	       2500Rs.            12:00(d)-16:30(a)"<<endl;
cout<<"  By Road     Ahm.            Bus                             700Rs.          09:00(d)-20:00(a)"<<endl;
cout<<"  By Road     Gan.            Bus                              700Rs.          10:00(d)-15:00(a)"<<endl;

gotoxy(5,12);cout<<"Accomodation Available::"<<endl;
cout<<"   Star          Place        NAME Of Hotel          Tariff   "<<endl;
cout<<"    5              Ahm           Royal                       12000Rs          "<<endl;
cout<<"    5              Gan          Kingfort               	 12000Rs.          "<<endl;
cout<<"    3              Ahm          Kinshu                 	 5000Rs.          "<<endl;
cout<<"  normal      Ahm          best                   	 2000Rs.           "<<endl;
cout<<"  normal      Gan          jesture                	 2000Rs.           "<<endl;
cout<<setw(10)<<"NOTE::(The Tarrif doesnot include meals except breakfast)     ";

atr=12000;ttr=2500;rtr=700;fst=12000;tst=5000; nst=2000;
opening2();
break;

case 2:clrscr();
gotoxy(25,1);cout<<"     RAJASTHAN";
gotoxy(24,2);cout<<"-------------------";
gotoxy(20,3);cout<<"Places To Visit::         -Jaipur-    -Jodhpur- "<<endl;

gotoxy(5,4);cout<<"Transportation Available::(from delhi)"<<endl;
cout<<"   MODE      Place        NAME            price                Timings    "<<endl;
cout<<"  BY Air     Jai.      351 I.A.               10000Rs.         12:50(d)-13:30(a)"<<endl;
cout<<"  BY Air     Jod.      352 I.A.              10000Rs.         7:00(d)- 7:40(a)"<<endl;
cout<<"  BY Train   Jai.   Pinkcity Express    1500Rs.         13:00(d)-18:00(a)"<<endl;
cout<<"  By Train   Jod.    Avadh Mail         1500Rs.         14:00(d)-14:30(a)"<<endl;
cout<<"  By Road    Jai.      Bus                     300Rs.         12:00(d)-20:00(a)"<<endl;
cout<<"  By Road    Jod.      Bus                  300Rs.          14:00(d)-15:00(a)"<<endl;

gotoxy(5,12);cout<<"Accomodation Available::"<<endl;
cout<<"   Star       Place        NAME Of Hotel            Tariff            "<<endl;
cout<<"    5             Jai                Clarks                     10000Rs           "<<endl;
cout<<"    5             Jod          Rajputana                  10000Rs.         "<<endl;
cout<<"    3              Jai          copperchimney          6000Rs.         "<<endl;
cout<<"    3             Jod              resort                       6000Rs.          "<<endl;
cout<<"  normal     Jod            Rajstar                      2000Rs.           "<<endl;
cout<<setw(10)<<"NOTE::(The Tarrif doesnot include meals except breakfast)     ";

atr=10000;ttr=1500;rtr=300;fst=10000;tst=6000; nst=2000;
opening2();
break;
}
}


/*FUNTION USED TO DISPLAY CENTRAL-INDIA INFORMATION.*/
void travelagency::cindia(int cdes)
{
textcolor(WHITE);
textbackground(RED);
clrscr();
switch(cdes)
{
case 1:clrscr();
gotoxy(25,1);cout<<"      ORISSA ";
gotoxy(24,2);cout<<"------------------";
gotoxy(20,3);cout<<"Places To Visit::         -Bhubaneshwar-    -Cuttack- "<<endl;

gotoxy(5,4);cout<<"Transportation Available::(from delhi)"<<endl;
cout<<"   MODE      Place        NAME                price                    Timings        "<<endl;
cout<<"  BY Air       Bhub.       091 I.A.           13000Rs.         13:50(d)-17:30(a)"<<endl;
cout<<"  BY Air       Cutt.       092 I.A.              13000Rs.         8:00(d)-11:40(a)"<<endl;
cout<<"  BY Train   Bhub.     Puri Express      2500Rs.          04:00(d)-18:00(a)"<<endl;
cout<<"  By Road    Bhub .        Bus                   700Rs.           03:00(d)-20:00(a)"<<endl;

gotoxy(5,12);cout<<"Accomodation Available::"<<endl;
cout<<"   Star          Place        NAME Of Hotel           Tariff         "<<endl;
cout<<"    5              Bhub         Janpath                     9000Rs            "<<endl;
cout<<"    5               Cutt         Lingraj                       9000Rs.         "<<endl;
cout<<"    3              Bhub         Prachi                        3000Rs.        "<<endl;
cout<<"  normal     Bhub         Anarkali                   1000Rs.          "<<endl;
cout<<"  normal     Cutt         Pushpak                     1000Rs.           "<<endl;
cout<<setw(10)<<"NOTE::(The Tarrif doesnot include meals except breakfast)     ";

atr=13000;ttr=2500;rtr=700;fst=9000;tst=3000; nst=1000;
opening2();
break;

case 2:clrscr();
gotoxy(25,1);cout<<"   MADHYA PRADESH";
gotoxy(24,2);cout<<"--------------------";
gotoxy(20,3);cout<<"Places To Visit::         -Bhopal-    -Gwalior- "<<endl;

gotoxy(5,4);cout<<"Transportation Available::(from delhi)"<<endl;
cout<<"   MODE      Place        NAME                 price              Timings      "<<endl;
cout<<"  BY Air     Bhop.       061 I.A.              10000Rs.         11:50(d)-13:30(a)"<<endl;
cout<<"  BY Air     Gwal.       062 I.A.               10000Rs.          6:00(d)- 7:40(a)"<<endl;
cout<<"  BY Train   Bhop.   Deccan Express    1500Rs.         11:00(d)-18:00(a)"<<endl;
cout<<"  By Train   Gwal.    Gwalior Mail     1500Rs.         07:00(d)-14:30(a)"<<endl;
cout<<"  By Road    Bhop.       Bus                  300Rs.          07:00(d)-20:00(a)"<<endl;

gotoxy(5,12);cout<<"Accomodation Available::"<<endl;
cout<<"   Star        Place        NAME Of Hotel              Tariff            "<<endl;
cout<<"    5            Bhop         taj                                  11000Rs            "<<endl;
cout<<"    5            Gwal         fortview                       11000Rs.          "<<endl;
cout<<"    3            Bhop         metro                           7000Rs.          "<<endl;
cout<<"    3             Gwal         president                    7000Rs.          "<<endl;
cout<<"  normal     Bhop         shelter                        3000Rs.           "<<endl;
cout<<"  normal     Gwal         safari                           3000Rs.           "<<endl;
cout<<setw(10)<<"          NOTE::(The Tarrif doesnot include meals except breakfast)     ";

atr=10000;ttr=1500;rtr=300;fst=11000;tst=7000; nst=3000;
opening2();
break;
}
}


/*FUNTION USED TO ASSIGN PRICE ACCORDING TO DESTINATION*/

void travelagency::assignprice()
{
textcolor(WHITE);
textbackground(RED);
clrscr();
int destination;

cout<<endl<<endl<<"          DESTINATIONS TO CHOOSE FROM "<<endl;
cout<<"      _________________________________________________________"<<endl<<endl<<endl;
cout<<"1:Kashmir and Jammu "<<endl;
cout<<"2:Shimla and Manali "<<endl;
cout<<"3:Trivandrum and Kochi "<<endl;
cout<<"4:Port blair "<<endl;
cout<<"5:Guwahati "<<endl;
cout<<"6:Calcutta and Darjiling "<<endl;
cout<<"7:Ahmedabad and Gandhinagar "<<endl;
cout<<"8:Jaipur and Jodhpur "<<endl;
cout<<"9:Bhubneshwar and Cuttack "<<endl;
cout<<"10:Bhopal and Gwalior "<<endl;
cout<<"11: Exit"<<endl;
cout<<endl<<endl<<"Enter the desired destination... ";
cin>>destination;


switch(destination)
{
case 1:atr=12000;ttr=2500;rtr=700;fst=11000;tst=6000;nst=3000;
break;
case 2:atr=10000;ttr=2000;rtr=800;fst=12000;tst=7000;nst=1000;
break;
case 3:atr=15000;ttr=3500;rtr=1200;fst=15000;tst=8000;nst=5000;
break;
case 4:atr=15000;ttr=2000;rtr=0;fst=9000;tst=6000;nst=2000;
break;
case 5:atr=12000;ttr=2500;rtr=700;fst=9000;tst=6000;nst=2000;
break;
case 6:atr=12000;ttr=2000;rtr=800;fst=14000;tst=7000; nst=1500;
break;
case 7:atr=12000;ttr=2500;rtr=700;fst=12000;tst=5000; nst=2000;
break;
case 8:atr=10000;ttr=1500;rtr=300;fst=10000;tst=6000; nst=2000;
break;
case 9:atr=10000;ttr=1500;rtr=300;fst=11000;tst=7000; nst=3000;
break;
case 10:atr=13000;ttr=2500;rtr=700;fst=9000;tst=3000; nst=1000;
break;

}

}



