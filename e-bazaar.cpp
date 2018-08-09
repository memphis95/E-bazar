#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<math.h>
#include<fstream>
#include<cstdlib>
#include<time.h> //for delay function
#include<iomanip>

using namespace std;

class guest;
class customer;
void main_menu();
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

template<typename T>

	       T d(T a)
	       {
	           return a;
	       }
class faq1
{
    char faq[200];
  char ans[200];
    public:

    void showfaq()
    {
  system("cls");
        cout<<"                   FREQUENTLY ASKED QUESTIONS "<<endl;
        FILE *fp;
        fp=fopen("faq.txt","r");
        faq1 s;
        cout<<"\n";
            while(fscanf(fp," %[^\n]s  %[^\n]s",s.faq,s.ans)!=EOF)
        {
            cout<<s.faq<<"\n"<<s.ans<<"\n";
            //cout<<"\n";
        }
        fclose(fp);
    }
};
class product;

class combo
{
    friend class product;
    friend class administrator;

    int comboId;
    char comboName[40];
    int comboCost;
    int comboQtyAv;

    public:

    combo()
    {
        comboId=10;
    }
    combo addCombo(product, product);
    void showCombo()
    {
        cout<<"\n Combo ID: "<<comboId;
        cout<<"\n Combo Name: "<<comboName;
        cout<<"\n Combo Quantity Available: "<<comboQtyAv;
        cout<<"\n Final bill:"<<comboCost-10;

    }

    void orderCombo();

};
class product
{
    friend class administrator;

	public: int productId;

     char prodName[20];
     char categ[20];
     int cost;
	 int qtyAv;     //quantity available
     bool availability;
     char specs[50];
	 /*Supplier *s[50];
	 Reviews *rev[10];

	 FAQ *f;*/
	 public:
	         /*product()
		     {   /*fstream fp;
	             fp.open("prod.txt", ios::app);


		     }*/
		  //OVERLOADED =
            void operator =(product p1)
            {
                productId=p1.productId;
                strcpy(p1.prodName,prodName);
                strcpy(p1.categ,categ);
                cost=p1.cost;
                qtyAv=p1.qtyAv;
                availability=p1.availability;
                strcpy(p1.specs,specs);
            }


		  void addProd()
		  {

		         FILE *fp;
		         //exception handling
	               try{


	                  fp=fopen("product.txt","a");
	                  if(fp==NULL)
                        throw "Product.txt File cant be opened ";

		             }
		          catch(const char* msg)
		          {
		              cerr<<msg<<endl;
		              exit(0);
		          }


		      cout<<"Product id: "<<endl;
              cin>>productId;
              cout<<"Product name: "<<endl;
              cin>>prodName;
              cout<<"Category: "<<endl;
              cin >>categ;

              cout<<"Cost(in rupees): "<<endl;
              cin>>cost;
              cout<<"Qty available: "<<endl;
              cin>>qtyAv;
                if(qtyAv>0)
                   availability=true;
              cout<<"Specifications: "<<endl;
              cin>>specs;
               //fp.seekg(0, ios::end);
               fprintf(fp,"%d %s %s %d %d %d %s\n",productId,prodName,categ,cost,qtyAv,availability,specs);
               system("cls");
               //fscanf(fp,"%d %s %s %d %d %d\n",&productId,prodName,categ,&cost,&qtyAv,&availability,specs);


               fclose(fp);
               this->getinfo();
		  }

	      void getinfo()
	      {
			  cout<<"Product id: "<<d(productId)<<endl;
              cout<<"Product name: "<<d(prodName)<<endl;
              cout<<"Category: "<<d(categ)<<endl;
              cout<<"Cost(in rupees): "<<d(cost)<<endl;
              cout<<"Qty available: "<<d(qtyAv)<<endl;
              cout<<"Availability:  "<<d(availability)<<endl;
              cout<<"Specifications: "<<d(specs)<<endl;
		  }

		    combo operator+(product Px)
        {
            combo Cx;
            Cx.comboCost=cost+Px.cost;
            Cx.comboQtyAv=min(qtyAv, Px.qtyAv);
            strcpy(Cx.comboName, Px.prodName);
            strcat(Cx.comboName, " - ");
            strcat(Cx.comboName, prodName);
            //cout<<"\n operator overloading";
            return Cx;
        }

        operator combo()
        {
            combo Cx;
            Cx.comboCost=(int)cost;
            Cx.comboQtyAv=(int)qtyAv;
            strcpy(Cx.comboName, prodName);
            return Cx;
        }


};

combo combo::addCombo(product P1, product P2)
{
    combo C;
    C=P1+P2;
    cout<<"\n 1 combo added.";
    return C;
}

void combo::orderCombo()
    {
        char pp1[20], pp2[20];
        product p1, p2;
        combo c1, c2;
        cout<<"\n ORDER COMBO";
        cout<<"\n Enter name of first product: ";
        cin>>pp1;
        cout<<"\n Enter name of second product: ";
        cin>>pp2;
        FILE *fp;
        fp=fopen("product.txt","r");
        while(fscanf(fp,"%d %s %s %d %d %d %s",&p1.productId,p1.prodName,p1.categ,&p1.cost,&p1.qtyAv,&p1.availability,p1.specs)!=EOF)
        {
            if(strcmp(p1.prodName,pp1)==0)
            {
                break;
            }
        }
        rewind(fp);
        while(fscanf(fp,"%d %s %s %d %d %d %s",&p2.productId,p2.prodName,p2.categ,&p2.cost,&p2.qtyAv,&p2.availability,p2.specs)!=EOF)
        {
            if(strcmp(p2.prodName,pp2)==0)
            {
                break;
            }
        }
        fclose(fp);
        c2=c1.addCombo(p1, p2);
        c2.showCombo();
    }

class order
{   static int totOrd;
	int orderId;
	product *p;
	char c[5][20];
	char c1[5][20];
    //struct time dateCreated;

	//string status;
	friend class product;
	//string shipId;


	public:
	       order()
	       {

	           orderId=totOrd++;
	       }

	     void disp_categ()
	     {

	         FILE *fp;   int i;  int j;
	         fp=fopen("product.txt","r");
	         product p1; i=0;
	         cout<<"\nCategories are :"<<endl;
	         while(fscanf(fp,"%d %s %s %d %d %d %s",&p1.productId,p1.prodName,p1.categ,&p1.cost,&p1.qtyAv,&p1.availability,p1.specs)!=EOF)
             {   //j=0;

                  strcpy(c[i++],p1.categ);



             }


              int k;
             for(j=0;j<i;j++)
             {

                 for(k=j+1;k<i;k++)
                 {
                     if(strcmp(c[j],c[k])==0)
                        //strcpy(c[j],c[j]);
                        strcpy(c[k],"0");
                 }
             }



             for( j=0;j<i;j++)
             {   if(strcmp(c[j],"0")!=0)
                 cout<<c[j]<<endl;
             }


	     }

	     int placeOrder()
	     {
	        FILE*fp2,*fp1;
             int id;  int q;
	        fp2=fopen("order.txt","a");
           product p1;
	        system("cls");
	        int ch;  char ct[20];
	        cout<<"1.Search products by category\n";
	        cout<<"2.Search by product\n";
	        cin>>ch;
	        switch(ch)
	        {
	         case 1:
	                   disp_categ();
	                   fp1=fopen("product.txt","r");
	                   cout<<"Enter category :";
	                         cin>>ct;
	                         cout<<"productId"<<"    prodName"<<"    categ"<<"    cost"<<"    qtyAv"<<"    availability"<<"    specs"<<endl;
	                         while(fscanf(fp1,"%d %s %s %d %d %d %s",&p1.productId,p1.prodName,p1.categ,&p1.cost,&p1.qtyAv,&p1.availability,p1.specs)!=EOF)
                             {
                                 if(strcmp(p1.categ,ct)==0)
                                 {
                                      cout<<setw(5)<<d(p1.productId)<<"\t "<<setw(8)<<d(p1.prodName)<<" "<<setw(9)
                                <<d(p1.categ)<<" "<<setw(11)<<d(p1.cost)<<" "<<setw(9)<<d(p1.qtyAv)<<" "<<setw(9)
                                <<d(p1.availability)<<" "<<setw(11)<<d(p1.specs)<<endl;
                                 }
                             }
                            fclose(fp1);
                            break;
               case 2:
                        fp1=fopen("product.txt","r");
	                   cout<<"Enter product name :";
	                         cin>>ct;
	                         cout<<"productId"<<"    prodName"<<"    categ"<<"    cost"<<"    qtyAv"<<"    availability"<<"    specs"<<endl;
	                         while(fscanf(fp1,"%d %s %s %d %d %d %s",&p1.productId,p1.prodName,p1.categ,&p1.cost,&p1.qtyAv,&p1.availability,p1.specs)!=EOF)
                             {
                                 if(strcmp(p1.prodName,ct)==0)
                                 {
                                      cout<<setw(5)<<d(p1.productId)<<"\t "<<setw(8)<<d(p1.prodName)<<" "<<setw(9)
                                <<d(p1.categ)<<" "<<setw(11)<<d(p1.cost)<<" "<<setw(9)<<d(p1.qtyAv)<<" "<<setw(9)
                                <<d(p1.availability)<<" "<<setw(11)<<d(p1.specs)<<endl;
                                 }
                             }
                            fclose(fp1);
                            break;



                }

                z:  cout<<"Enter product id for ordering :";

                 cin>>id;
                 cout<<"\nEnter quantity:";
                 try{
                   cin>>q;
                   if(q<0)
                    throw "Quantity cant be negative\n Enter again";
                 }
                 catch(const char * msg)
                 {
                     cerr<<msg<<endl;
                     goto z;
                 }
                 fp1=fopen("product.txt","r");
                 int flag=0;
                 while(fscanf(fp1,"%d %s %s %d %d %d %s",&p1.productId,p1.prodName,p1.categ,&p1.cost,&p1.qtyAv,&p1.availability,p1.specs)!=EOF)
                             {
                                 if(p1.productId==id && p1.qtyAv>=q)
                                    {
                                        flag=1;

                                        break;
                                    }
                             }
                             fclose(fp1);
                             if(flag==0)
                             {cout<<"\nInvalid product Id or Qty available is lesser";
                                 goto z;
                             }
                             else if(flag==1)
                             {
                                     //updating file
                                    product p2;
                     		      FILE *fp1,*fp3;
                                    fp1=fopen("product.txt","r");
                                    fp3=fopen("temp1.txt","w");


                                while(fscanf(fp1,"%d %s %s %d %d %d %s\n",&p2.productId,p2.prodName,p2.categ,&p2.cost,&p2.qtyAv,&p2.availability,p2.specs)!=EOF)
                              {
                                    if(p1.productId!=p2.productId)
                                            fprintf(fp3,"%d %s %s %d %d %d %s\n",p2.productId,p2.prodName,p2.categ,p2.cost,p2.qtyAv,p2.availability,p2.specs);
                                    else
                                        {    //if(p2.qtyAv>=q)
                                            fprintf(fp3,"%d %s %s %d %d %d %s\n",p2.productId,p2.prodName,p2.categ,p2.cost,(p2.qtyAv-q),p2.availability,p2.specs);
                                        }
                              }
                                    fclose(fp1);
                                    fclose(fp3);
                                    remove("product.txt");
                                    rename("temp1.txt","product.txt");

                                   //updated.......file


                                 orderId=totOrd++;
                                 p=&p1;
                                 int bill=p1.cost*q;
                                 system("cls");

                                 cout<<"Your Order Details\n";
                                 cout<<"Order Id :"<<orderId;
                                 cout<<"\nProduct Id :"<<p1.productId<<endl;
                                 cout<<"Product :"<<p1.prodName<<endl;
                                 cout<<"Cost :"<<p1.cost<<endl;
                                 cout<<"Quantity :"<<q<<endl<<endl;
                                 cout<<"\n\n\n..................................................\n";

                                 cout<<"Total Amount :\t"<<bill<<endl;
                                 fprintf(fp2,"%d %d %s %d %d\n",orderId,p1.productId,p1.prodName,p1.cost,q);
                                 fclose(fp2);

                                    cout<<"\nThanks for ordering\nProduct will be delivered within 3-4 days";
                                               cout<<"\nLoading....";
                                                 delay(3000);

return bill;
                                 }




                             }






		 int cancelOrder(){}
         void trackOrder(){}
};
 int order::totOrd=0;

 class cart
{
   static int totCart;
	int cartId;
	product *p[100];
	char c[5][20];
	char c1[5][20];

	public:
            cart()
	        {

	            cartId=++totCart;
	        }

	        void disp_categ()
	     {

	         FILE *fp;   int i;  int j;
	         fp=fopen("product.txt","r");
	         product p1; i=0;
	         cout<<"\nCategories are :"<<endl;
	         while(fscanf(fp,"%d %s %s %d %d %d %s",&p1.productId,p1.prodName,p1.categ,&p1.cost,&p1.qtyAv,&p1.availability,p1.specs)!=EOF)
             {   //j=0;

                  strcpy(c[i++],p1.categ);




             }


              int k;
             for(j=0;j<i;j++)
             {

                 for(k=j+1;k<i;k++)
                 {
                     if(strcmp(c[j],c[k])==0)
                        //strcpy(c[j],c[j]);
                        strcpy(c[k],"0");
                 }
             }



             for( j=0;j<i;j++)
             {   if(strcmp(c[j],"0")!=0)
                 cout<<c[j]<<endl;
             }



	     }
	       void addToCart()
	       {


	        FILE*fp2,*fp1;
             int id;  int q;
	        fp2=fopen("cart.txt","a");
           product p1;
	        system("cls");
	        int ch;  char ct[20];
	        cout<<"1.Search products by category\n";
	        cout<<"2.Search by product\n";
	        cin>>ch;
	        switch(ch)
	        {
	         case 1:
	                   disp_categ();
	                   fp1=fopen("product.txt","r");
	                   cout<<"Enter category :";
	                         cin>>ct;
	                         cout<<"productId"<<"    prodName"<<"    categ"<<"    cost"<<"    qtyAv"<<"    availability"<<"    specs"<<endl;
	                         while(fscanf(fp1,"%d %s %s %d %d %d %s",&p1.productId,p1.prodName,p1.categ,&p1.cost,&p1.qtyAv,&p1.availability,p1.specs)!=EOF)
                             {
                                 if(strcmp(p1.categ,ct)==0)
                                 {
                                      cout<<setw(5)<<p1.productId<<"\t "<<setw(8)<<p1.prodName<<" "<<setw(9)
                                <<p1.categ<<" "<<setw(11)<<p1.cost<<" "<<setw(9)<<p1.qtyAv<<" "<<setw(9)
                                <<p1.availability<<" "<<setw(11)<<p1.specs<<endl;
                                 }
                             }
                            fclose(fp1);
                            break;
               case 2:
                        fp1=fopen("product.txt","r");
	                   cout<<"Enter product name :";
	                         cin>>ct;
	                         cout<<"productId"<<"    prodName"<<"    categ"<<"    cost"<<"    qtyAv"<<"    availability"<<"    specs"<<endl;
	                         while(fscanf(fp1,"%d %s %s %d %d %d %s",&p1.productId,p1.prodName,p1.categ,&p1.cost,&p1.qtyAv,&p1.availability,p1.specs)!=EOF)
                             {
                                 if(strcmp(p1.prodName,ct)==0)
                                 {
                                      cout<<setw(5)<<p1.productId<<"\t "<<setw(8)<<p1.prodName<<" "<<setw(9)
                                <<p1.categ<<" "<<setw(11)<<p1.cost<<" "<<setw(9)<<p1.qtyAv<<" "<<setw(9)
                                <<p1.availability<<" "<<setw(11)<<p1.specs<<endl;
                                 }
                             }
                            fclose(fp1);
                            break;



                }

                z:  cout<<"Enter product id for ordering :";

                 cin>>id;
                 cout<<"\nEnter quantity:";
                 try{
                   cin>>q;
                   if(q<0)
                    throw "Quantity cant be negative\n Enter again";
                 }
                 catch(const char * msg)
                 {
                     cerr<<msg<<endl;
                     goto z;
                 }
                 fp1=fopen("product.txt","r");
                 int flag=0;
                 while(fscanf(fp1,"%d %s %s %d %d %d %s",&p1.productId,p1.prodName,p1.categ,&p1.cost,&p1.qtyAv,&p1.availability,p1.specs)!=EOF)
                             {
                                 if(p1.productId==id && p1.qtyAv>=q)
                                    {flag=1;

                                        break;
                                    }
                             }
                             fclose(fp2);

                             if(flag==0)
                             {cout<<"\nInvalid product Id or lesser Qty available ";
                                 goto z;
                             }
                             else if(flag==1)
                             {   fprintf(fp2,"%d %d %s %s %d %d\n",cartId,p1.productId,p1.prodName,p1.categ,p1.cost,q);

                                   cout<<"\n\nAdding product to cart...."<<endl;
                                   //updating file
                                    product p2;
                     		      FILE *fp1,*fp3;
                                    fp1=fopen("product.txt","r");
                                    fp3=fopen("temp1.txt","w");


                                while(fscanf(fp1,"%d %s %s %d %d %d %s\n",&p2.productId,p2.prodName,p2.categ,&p2.cost,&p2.qtyAv,&p2.availability,p2.specs)!=EOF)
                              {
                                    if(p1.productId!=p2.productId)
                                            fprintf(fp3,"%d %s %s %d %d %d %s\n",p2.productId,p2.prodName,p2.categ,p2.cost,p2.qtyAv,p2.availability,p2.specs);
                                    else
                                        {    if(p2.qtyAv>=q)
                                            fprintf(fp3,"%d %s %s %d %d %d %s\n",p2.productId,p2.prodName,p2.categ,p2.cost,(p2.qtyAv-q),p2.availability,p2.specs);
                                        }
                              }
                                    fclose(fp1);
                                    fclose(fp3);
                                    remove("product.txt");
                                    rename("temp1.txt","product.txt");

                                   //updated.......file
                                   delay(2000);
                               cout<<"\nProduct successfully added to cart !!"<<endl;
                                    fclose(fp2);
                                // orderId=totOrd++;
                                 /*p=&p1;
                                 int bill=p1.cost*q;
                                 system("cls");*/

                               /*  cout<<"Your Order Details\n";
                                 cout<<"Order Id :"<<orderId;
                                 cout<<"\nProduct Id :"<<p1.productId<<endl;
                                 cout<<"Product :"<<p1.prodName<<endl;
                                 cout<<"Cost :"<<p1.cost<<endl;
                                 cout<<"Quantity :"<<q<<endl<<endl;
                                 cout<<"\n\n\n..................................................\n";

                                 cout<<"Total Amount :\t"<<bill<<endl;
                                 cout<<"How would you like to pay\n";
                                 cout<<"1. Cash On Delivery\n2. Wallet\n3. Credit card\n=>";
                                 cin>>ch;
                                 switch(ch)
                                 {
                                    case 1:    cout<<"\nThanks for ordering\nProduct will be delivered within 3-4 days";
                                               cout<<"Loading....";
                                                 delay(3000);

                                                 break;
                                    case 2 :   break;

                                 }

                                 return bill;

                                 */
                             }


                     fclose(fp1);

	       }

            void see_cart()
            {
                FILE *fp;
                product p1;
                int q[20];
                int i=0,ch;
                fp=fopen("cart.txt","r");
                cout<<"\n\n Current status of cart :"<<endl;
                cout<<"Cart Id"<<"    prodId"<<"    ProdName"<<"    Categ"<<"    Cost"<<"    Quantity"<<endl;
                while(fscanf(fp,"%d %d %s %s %d %d",&cartId,&p1.productId,p1.prodName,p1.categ,&p1.cost,&q[i])!=EOF)
                             {

                                      cout<<setw(5)<<d(cartId)<<"\t "<<setw(8)<<d(p1.productId)<<" "<<setw(9)
                                <<d(p1.prodName)<<" "<<setw(11)<<d(p1.categ)<<" "<<setw(9)<<d(p1.cost)<<" "<<setw(9)
                                <<d(q[i])<<endl;
                                i++;
                             }
                fclose(fp);
                delay(8000);
            }
		   //void updateQty(){}
		   //void viewCart(){}
		   void checkOut()
		   {
		       FILE *fp;
		       product p1;
		       fp=fopen("cart.txt","r");
		       int i=0;
		       int q[20],co[20]; int pid[20];
		       while(fscanf(fp,"%d %d %s %s %d %d",&cartId,&p1.productId,p1.prodName,p1.categ,&p1.cost,&q[i])!=EOF)
               {

                  // p[i]=&p1;
                  co[i] =p1.cost;
                  pid[i]=p1.productId;
                   //cout<<p[i]->productId<<p[i]->prodName<<endl;
                   i++;
               }
               fclose(fp);



               int ch;
               int bill=0;
               int j=0;
               while(j<i)
               {     cout<<co[j]<<" ";
                   bill=bill+(co[j]*q[j]);
                   j++;

               }
               cout<<"\n OFFER!!!  here are some promocodes choose any 1 to apply"<<endl;
               cout<<"1. start10 : Get 10% off\n2. flexi777\n3. bigbang2=>";
               cin>>ch;
               cout<<"total bill :"<<bill<<endl;
               cout<<"Promo code applied"<<endl;
               switch(ch)
               {

                    case 1:   bill=bill-(0.1*bill);
                                break;
                    case 2:   bill =bill-(0.12*bill);
                                break;
                     case 3:   bill=bill-(0.2*bill);
                                 break;
                     default :    break;

               }
               cout<<"Net amount payable"<<bill;

               delay(5000);
               remove("cart.txt");

		   }
		   int removeItem(){}
};

int cart::totCart=0;

class creditcard
{    friend class customer;
    char cardNo[16]; // 16 digits
	char bank[20];
	char holder[20];
	int pin;
	public:
	       int verifyPin(){
	           int p;
	           cout<<"card no.:"<<cardNo<<endl;
	         cout<<"enter pin:";
	         cin>>p;
	         if(p==pin)
                return 1;
             else
                return 0;
	         }
};
class guest
{
   // order *o;
	 public:
	 /*   void enterDetails()
	    {


	    } // name  address phone etc;*/
		virtual void show_product()
		{

                            FILE *fp;
	                        fp=fopen("product.txt","r");
                            int ct=2,ch;

                            product p1;
                            system("cls");
                            cout<<"\n\t\t\t\t Welcome to e-Bazaar, Guest!"<<endl;
                            cout<<"\n\n";
                            cout<<"These are the products we sell:-"<<endl;
                            cout<<"productId"<<"\tprodName"<<"    categ"<<"   cost"<<"\tqtyAv"<<"\tavailability"<<"\tspecs"<<endl;
                            while(fscanf(fp,"%d %s %s %d %d %d %s",&p1.productId,p1.prodName,p1.categ,&p1.cost,&p1.qtyAv,&p1.availability,p1.specs)!=EOF)
                             {
                                   cout<<setw(5)<<p1.productId<<"\t "<<setw(10)<<p1.prodName<<" "<<setw(9)
                                <<p1.categ<<" "<<setw(11)<<p1.cost<<" "<<setw(9)<<p1.qtyAv<<" "<<setw(9)
                                <<p1.availability<<" "<<setw(11)<<p1.specs<<endl;


                            }
                                cout<<"\n\n Do you want to order?[1(yes)/0(Exit)]"<<endl;
                                cin>>ch;
                                if(ch==1)
                                {
                                   cout<<"\n Get yourself registered with us then!"<<endl;
                                   delay(1000);
                                   cout<<"Directing you to the user menu....."<<endl;
                                   delay(2000);

                                   main_menu();
                                }
                        fclose(fp);

		}
};
class customer:public guest
{
     friend class administrator;

   char name[30];
   char adrs[50];   //address
   char phone[10];
   char email[20];
   char user_id[20];
   char passwd[20];   //password
   int login_state;
   creditcard cc;
  cart mycart;
   order *ord;
   char notifications[200];
   //wishlist wishes[20];
   //giftcard *g[10];
   //issue *is[10];
   //wallet w;
   public:
           customer()
           {

                login_state=0;
           }
           void user_entry()
           {

                  int ch;
               label :  system("cls");
                         cout<<"\n1. LOGIN";
                         cout<<"\n2. REGISTER";
                         cout<<"\n3. BACK TO MAIN MENU\n=>";
                         cin>>ch;
                          switch(ch)
                          {
                              case 1: login();
                                       break;
                              case 2:  registr();
                                       break;
                              case 3: return;
                              goto label;

                          }

            }
           void user_menu()
           {
                        system("cls");
                         int ch;
            label:  system("cls");
                    cout<<"\t\t USER MAIN MENU"<<endl;
                    cout<<"\n1. SHOW PRODUCTS";
                    cout<<"\n2. ORDER a PRODUCT";
                    cout<<"\n3. ORDER a COMBO";
                    cout<<"\n4. REVIEW PRODUCT";
                    cout<<"\n5. UPDATE PROFILE";
                    cout<<"\n6. ADD TO CART";
                    cout<<"\n7. CHANGE PASSWORD";
                    cout<<"\n8. LOGOUT";
                    cout<<"\n9. DEACTIVATE ACCOUNT";
                    cout<<"\n10. CHECKOUT ( CART )";
                    cout<<"\n11. SEE CART";
                    cout<<"\nEnter choice :";
                    cin>>ch;
            switch(ch)
                {
                    case 1:show_product(); break;
                    case 2: { ord=new order();
                             int y=ord->placeOrder();
                              break;
                            }

                    case 3: {combo c;
                        c.orderCombo(); }break;
                    case 4://review_product();
                           break;
                    case 5:updateProfile(); break;
                    case 6: mycart.addToCart();
                               break;
                    case 7:changePwd();
                            break;
                    case 8:main_menu();
                            break;
                    case 9:deactivate();
                             break;
                    case 10: mycart.checkOut(); break;

                    case 11: mycart.see_cart(); break;
                     default: goto label;
                }

                 cout<<"\n\n1. logout\n2.Go to user menu\n";
                  cin>>ch;
                   if(ch==1)
                     main_menu();
                   else
                      goto label;
           }
          void show_product()
          {
              system("cls");
             cout<<"\nProducts we sell:-"<<endl;
             FILE *fp;
                int ch,y;
             product p1;
             fp=fopen("product.txt","r");
             cout<<"productId"<<"\tprodName"<<"\tcateg"<<"\tcost"<<"\tqtyAv"<<"\tavailability"<<"\tspecs"<<endl;
                while(fscanf(fp,"%d %s %s %d %d %d %s",&p1.productId,p1.prodName,p1.categ,&p1.cost,&p1.qtyAv,&p1.availability,p1.specs)!=EOF)
                   {
                          cout<<"\t"<<setw(14)<<p1.productId<<"\t "<<setw(8)<<p1.prodName<<" "<<setw(9)
                                <<p1.categ<<" "<<setw(11)<<p1.cost<<" "<<setw(9)<<p1.qtyAv<<" "<<setw(9)
                                <<p1.availability<<" "<<setw(11)<<p1.specs<<endl;
                   }
                   fclose(fp);
           cout<<"\n";
           cout<<"\n Do you wish to see products cost wise?(1/0)";
           cin>>ch;
            fp=fopen("product.txt","r");
           if(ch==1)
           {
               label: cout<<"(1)<=500"<<endl;
                cout<<"(2)501 to 1000"<<endl;
                cout<<"(3)1001 to 5000 "<<endl;
                cout<<"(4)>=5001"<<endl;
                cout<<"\n Enter your choice:";
                cin>>y;
                cout<<"\n";
                cout<<"productId"<<"\tprodName"<<"\tcateg"<<"\tcost"<<"\tqtyAv"<<"\tavailability"<<"\tspecs"<<endl;
                switch(y)
                 {
           case 1:
                    while(fscanf(fp,"%d %s %s %d %d %d %s",&p1.productId,p1.prodName,p1.categ,&p1.cost,&p1.qtyAv,&p1.availability,p1.specs)!=EOF)
                   {
                       if(p1.cost<=500)
                         cout<<setw(5)<<p1.productId<<"\t "<<setw(8)<<p1.prodName<<" "<<setw(9)
                                <<p1.categ<<" "<<setw(11)<<p1.cost<<" "<<setw(9)<<p1.qtyAv<<" "<<setw(9)
                                <<p1.availability<<" "<<setw(11)<<p1.specs<<endl;
                   } break;
           case 2:
            while(fscanf(fp,"%d %s %s %d %d %d %s",&p1.productId,p1.prodName,p1.categ,&p1.cost,&p1.qtyAv,&p1.availability,p1.specs)!=EOF)
                   {
                       if(p1.cost>501 && p1.cost<=1000)
                         cout<<setw(5)<<p1.productId<<"\t "<<setw(8)<<p1.prodName<<" "<<setw(9)
                                <<p1.categ<<" "<<setw(11)<<p1.cost<<" "<<setw(9)<<p1.qtyAv<<" "<<setw(9)
                                <<p1.availability<<" "<<setw(11)<<p1.specs<<endl;
                   } break;
           case 3:
            while(fscanf(fp,"%d %s %s %d %d %d %s",&p1.productId,p1.prodName,p1.categ,&p1.cost,&p1.qtyAv,&p1.availability,p1.specs)!=EOF)
                   {
                       if(p1.cost>1001 && p1.cost<=5000)
                         cout<<setw(5)<<p1.productId<<"\t "<<setw(8)<<p1.prodName<<" "<<setw(9)
                                <<p1.categ<<" "<<setw(11)<<p1.cost<<" "<<setw(9)<<p1.qtyAv<<" "<<setw(9)
                                <<p1.availability<<" "<<setw(11)<<p1.specs<<endl;
                   } break;
           case 4:
             while(fscanf(fp,"%d %s %s %d %d %d %s",&p1.productId,p1.prodName,p1.categ,&p1.cost,&p1.qtyAv,&p1.availability,p1.specs)!=EOF)
                   {
                       if(p1.cost>5000)
                         cout<<setw(5)<<p1.productId<<"\t "<<setw(8)<<p1.prodName<<" "<<setw(9)
                                <<p1.categ<<" "<<setw(11)<<p1.cost<<" "<<setw(9)<<p1.qtyAv<<" "<<setw(9)
                                <<p1.availability<<" "<<setw(11)<<p1.specs<<endl;
                   } break;
        default: goto label;
                 }
                 fclose(fp);
           }
           cout<<"\n Go back to main menu or exit?(1-mainmenu/0-exit)";
           cin>>ch;
           if(ch==1)
           {
              cout<<" Redirecting to main menu...";
             delay(1000);
             cout<<"..";
             delay(50);
             cout<<"....";
             user_menu();
           }
           else
             exit(0);
        }
          void registr()
          {   system("cls");
              cout<<"\t\tCustomer Registration"<<endl;
              cout<<"Enter Name: ";
              cin>>name;
              cout<<"Address : ";
              cin>>adrs;
              cout<<"Phone : ";
              cin>>phone;
              cout<<"Email : ";
              cin>>email;
              cout<<"User_id";
              cin>>user_id;
              cout<<"Password : ";
              cin>>passwd;
              FILE *fp;
              fp=fopen("customers.txt","a");
              fprintf(fp,"%s %s %s %s %s %s\n",name,adrs,phone,email,user_id,passwd);
              fclose(fp);

          }
		  void login()
		  {  char id[20],pw[20];

		     l:
		         system("cls");
		         cout<<"\t\tCustomer Login"<<endl;
		     cout<<"Enter UserID :";
		     cin>>id;
		     cout<<"Enter Password :";
		     cin>>pw;
		     customer c1;
		     FILE *fp;
		     fp=fopen("customers.txt","r");
		     while(fscanf(fp,"%s %s %s %s %s %s",c1.name,c1.adrs,c1.phone,c1.email,c1.user_id,c1.passwd)!=EOF)
                             {

                                 if((strcmp(id,c1.user_id)==0) && (strcmp(pw,c1.passwd)==0))
                                    {
                                      strcpy(name,c1.name);
                                      strcpy(adrs,c1.adrs);   //address
                                      strcpy(phone,c1.phone);
                                      strcpy(email,c1.email);
                                      strcpy(user_id,c1.user_id);
                                      strcpy(passwd,c1.passwd);
                                      login_state=1;
                                      break;
                                     }

                            }

                            fclose(fp);
                         //   cout<<login_state;
                          if(login_state==1)
                            {   cout<<"Successful Login";
                                      user_menu();
                            }

                        else{        system("cls");
                                    cout<<"\n\n\t\tOops!Login failed"<<endl;
                                    int ch;
                                    cout<<"You are not registered with us!"<<"\nPress 1 for registration (0 for exit or 2 for retrying):";
                                    cin>>ch;
                                    if(ch==1)
                                      registr();
                                      else if(ch==2)
                                        goto l;
                                        else
                                       exit(0);
                            }

		  }
		  //overloaded =
		  void operator=(customer c1)
		  {

		      strcpy(name,c1.name);
               strcpy(adrs,c1.adrs);   //address
              strcpy(phone,c1.phone);
              strcpy(email,c1.email);
               strcpy(user_id,c1.user_id);
               strcpy(passwd,c1.passwd);

		  }

		  void updateProfile()
		  {
		      cout<<"Edit your profile"<<endl;
		      cout<<"Name :";
		      cin>>name;
              cout<<"Address : ";
              cin>>adrs;
              cout<<"Phone : ";
              cin>>phone;
              cout<<"Email : ";
              cin>>email;


		       customer c1;
		      FILE *fp1,*fp2;
		      fp1=fopen("customers.txt","r");
		      fp2=fopen("temp1.txt","w");
		      /*cout<<"Enter user id";
		      cin>>*/

		      while(fscanf(fp1,"%s %s %s %s %s %s",c1.name,c1.adrs,c1.phone,c1.email,c1.user_id,c1.passwd)!=EOF)
              {
                  if(strcmp(c1.user_id,user_id)!=0)
                     fprintf(fp2,"%s %s %s %s %s %s\n",c1.name,c1.adrs,c1.phone,c1.email,c1.user_id,c1.passwd);
                  else
                    fprintf(fp2,"%s %s %s %s %s %s\n",name,adrs,phone,email,user_id,passwd);

              }
              fclose(fp1);
              fclose(fp2);
              remove("customers.txt");
              rename("temp1.txt","customers.txt");


          }
		  void addCreditCard()
		  {
		    cout<<"Enter credit card number: ";
		    cin>>cc.cardNo;
		    cout<<"Enter pin: ";
		    cin>>cc.pin;
		    FILE *fp;
		    fp=fopen("ccards.txt","a");
		    fprintf(fp,"%s %s %s %d",user_id,cc.cardNo,cc.bank,cc.pin);
		    fclose(fp);

		  }

		  void changePwd()
		  {    system("cls");
               customer c1;
		      FILE *fp1,*fp2;
		      fp1=fopen("customers.txt","r");
		      fp2=fopen("temp1.txt","w");
		      /*cout<<"Enter user id";
		      cin>>*/
		      cout<<"Enter new password\n";
		      cin>>passwd;
		      while(fscanf(fp1,"%s %s %s %s %s %s",c1.name,c1.adrs,c1.phone,c1.email,c1.user_id,c1.passwd)!=EOF)
              {
                  if(strcmp(c1.user_id,user_id)!=0)
                     fprintf(fp2,"%s %s %s %s %s %s\n",c1.name,c1.adrs,c1.phone,c1.email,c1.user_id,c1.passwd);
                  else
                    fprintf(fp2,"%s %s %s %s %s %s\n",name,adrs,phone,email,user_id,passwd);

              }
              fclose(fp1);
              fclose(fp2);
              remove("customers.txt");
              rename("temp1.txt","customers.txt");


		  }
		  void deactivate()
		  {    int ch;
		      cout<<"\t Deactivation"<<endl;
		      cout<<"ARE YOU SURE YOU WANT TO DEACTIVATE YOUR ACCOUNT\n Press 1 for yes , 0 for no";
		      cin>>ch;
		      if(ch==1)
              {

                   customer c1;
		      FILE *fp1,*fp2;
		      fp1=fopen("customers.txt","r");
		      fp2=fopen("temp1.txt","w");
		      /*cout<<"Enter user id";
		      cin>>*/

		      while(fscanf(fp1,"%s %s %s %s %s %s",c1.name,c1.adrs,c1.phone,c1.email,c1.user_id,c1.passwd)!=EOF)
              {
                  if(strcmp(c1.user_id,user_id)!=0)
                     fprintf(fp2,"%s %s %s %s %s %s\n",c1.name,c1.adrs,c1.phone,c1.email,c1.user_id,c1.passwd);

              }
              fclose(fp1);
              fclose(fp2);
              remove("customers.txt");
              rename("temp1.txt","customers.txt");
               user_entry();
              }

		  }
		  void getNotifications(){}

};



class administrator  //public product
{     friend class product;
      friend class customer;
      product *p[100];
      customer *c[100];
      int totProd;
      int totCus;

	  string adminName;
	  string email;
	  //customer *c;
	  public:
	         friend void main_menu();
            administrator()
            {   system("cls");
                 /*cout<<"Enter admin name :";
                 cin>>adminName;
                 cout<<"Email :";
                 cin>>email;*/
                totCus=0;
                totProd=0;
               // init_prod();
                //init_cust();
            }

            void init_prod()
            {

                FILE *fp;
                fp=fopen("product.txt","r");
	                        product p1;

                            while(fscanf(fp,"%d %s %s %d %d %d %s",&p1.productId,p1.prodName,p1.categ,&p1.cost,&p1.qtyAv,&p1.availability,p1.specs)!=EOF)
                             { p[totProd]=new product();
                                p[totProd++]=&p1;
                            }

                            fclose(fp);
            }
            void init_cust()
            {
                FILE *fp;
                fp=fopen("customers.txt","r");
	                        customer c1;
                           while(fscanf(fp,"%s %s %s %s %s %s %s",c1.name,c1.adrs,c1.phone,c1.email,c1.user_id,c1.passwd)!=EOF)
                             { c[totCus]=new customer();
                                c[totCus++]=&c1;
                            }

                            fclose(fp);

            }



            void admin_menu()
           {
              label:  system("cls");
               int ch;
             cout<<"\t\t ADMIN MAIN MENU"<<endl;
                    cout<<"\n1. SHOW PRODUCTS";
                    cout<<"\n2. ADD PRODUCT";
                    cout<<"\n3. DELETE PRODUCT";
                    cout<<"\n4. MODIFY PRODUCT";
                    cout<<"\n5. Exit";
                    cout<<"\nEnter choice :";
                    cin>>ch;
            switch(ch)
                {
                    case 1:  {
                            FILE *fp;
	                        fp=fopen("product.txt","r");
	                        //int ch= getc(fp);
	                        //while(getc(fp) != EOF)
                            int ct=2;
                            product p1;
                            cout<<"productId"<<"\tprodName"<<"\tcateg"<<"\tcost"<<"\tqtyAv"<<"\tavailability"<<"\tspecs"<<endl;
                            while(fscanf(fp,"%d %s %s %d %d %d %s",&p1.productId,p1.prodName,p1.categ,&p1.cost,&p1.qtyAv,&p1.availability,p1.specs)!=EOF)
                             {
                                  cout<<"    "<<setw(5)<<p1.productId<<"\t"<<setw(8)<<p1.prodName<<" "<<setw(9)
                                <<p1.categ<<" "<<setw(10)<<p1.cost<<setw(9)<<p1.qtyAv<<setw(9)
                                <<p1.availability<<setw(11)<<p1.specs<<endl;
                            }

                            fclose(fp);

                            }      break;
                    case 2: addProd1(); break;
                    case 3:delete_product(); break;
                    case 4:updateProd(); break;

                    case 5:main_menu(); break;

                   default: goto label;
                }
                cout<<"\nPress 1 for main menu and 0 for logout"<<endl;
                cin>>ch;
                if(ch==1)
                    goto label;
                else
                    main_menu();
        }
void admin_login()
        {     system("cls");
              string username,password;
              cout<<"Enter Username:";
              cin>>username;
              cout<<"Enter Password:";
              cin>>password;
              if((username=="a") && (password=="a"))
                admin_menu();
        }


	         void addProd1()
	         {
                 int c=1;
	           while(c==1)
                {
                  p[totProd]=new product();
                  p[totProd++]->addProd();
                  cout<<"\nproduct added" ;
                  cout<<"\nWant to add more (1 for yes) OR go back to admin menu(press 0)";
                  cin>>c;
                }
                if(c==0)
                     admin_menu();

             }

              void updateProd()
		  {    product p;
		      cout<<"Edit a product"<<endl;
		      cout<<"ProductId :";
		      cin>>p.productId;
              cout<<"ProductName : ";
              cin>>p.prodName;
              cout<<"Categ :";
              cin>>p.categ;
              cout<<"Cost :";
              cin>>p.cost;
              cout<<"Qty Av :";
              cin>>p.qtyAv;
              cout<<"Specs :";
              cin>>p.specs;
              if(p.qtyAv>0)
                p.availability=1;



		       product p1;
		      FILE *fp1,*fp2;
		      fp1=fopen("product.txt","r");
		      fp2=fopen("temp1.txt","w");
		      /*cout<<"Enter user id";
		      cin>>*/

		      while(fscanf(fp1,"%d %s %s %d %d %d %s\n",&p1.productId,p1.prodName,p1.categ,&p1.cost,&p1.qtyAv,&p1.availability,p1.specs)!=EOF)
              {
                  if(p1.productId!=p.productId)
                     fprintf(fp2,"%d %s %s %d %d %d %s\n",p1.productId,p1.prodName,p1.categ,p1.cost,p1.qtyAv,p1.availability,p1.specs);
                  else
                    fprintf(fp2,"%d %s %s %d %d %d %s\n",p.productId,p.prodName,p.categ,p.cost,p.qtyAv,p.availability,p.specs);

              }
              fclose(fp1);
              fclose(fp2);
              remove("product.txt");
              rename("temp1.txt","product.txt");


          }


             void getinfo1()
             {  // FILE *fp;
                 //fp=fopen("prod.txt","r");
                 system("cls");
               //fscanf(fp,"%d %s %s %d %d %d\n",&productId,prodName,categ,&cost,&qtyAv,&availability,specs);
                // p[1]->getinfo();
                 //fclose(fp);
                 //p[1]->getinfo();
             }
              void delete_product()
             {
                FILE *fp1;
                FILE *fp2;
                int pid;
                product Pd;
                cout<<"\n Which product do you want to delete? Enter product Id: ";
                cin>>pid;
                fp1=fopen("product.txt","r");
                fp2=fopen("bb.txt","w");
                if (fp1 == NULL)
                    printf("Error in opening file\n");
                if (fp2 == NULL)
                    printf("Error in opening file\n");
        //delete product id record
                while(!feof(fp1))
                    {
                        fscanf(fp1,"%d %s %s %d %d %d %s\n",&Pd.productId,Pd.prodName,Pd.categ,&Pd.cost,&Pd.qtyAv,&Pd.availability,Pd.specs);
                        if(Pd.productId!=pid)
                            {
                               fprintf(fp2,"%d %s %s %d %d %d %s\n",Pd.productId,Pd.prodName,Pd.categ,Pd.cost,Pd.qtyAv,Pd.availability,Pd.specs);
                            }
                    }
                fclose(fp1);
                fclose(fp2);
                remove("product.txt");
                rename("bb.txt","product.txt");


             }
			// void seeWishlists(){}
			// void blockCustomer(){}
			 //void assignIssueToAgent(){}
			// void askFeedbackOnResolve(){}
};


void main_menu()
{

	  administrator *aa;
	  customer *c;
	  guest *g;
	  faq1 *f1;
      //main_menu();
	  //aa.addProd();
     int ch;
     system("cls");
    label:cout<<"\t\t Welcome to E-Bazaar!"<<endl;
          cout<<"\n MAIN MENU";
          cout<<"\n1.ADMIN MODE";
          cout<<"\n2.CUSTOMER MODE";
          cout<<"\n3.GUEST MODE";
           cout<<"\n4.FAQs";
          cout<<"\n5.EXIT";
          cout<<"\nEnter choice :";
          cin>>ch;
            switch(ch)
                {
                    case 1: aa=new administrator;
                            aa->admin_login();
                             break;
                    case 2: c=new customer;
                            c->user_entry();
                            break;
                    case 3: g=new guest;
                            /*c=new customer;
                            guest *a=(&c);
                            customer *b=dynamic_cast<customer *>(&a);
                            */
                            g->show_product();
                            break;
                      case 4: f1=new faq1;
                            f1->showfaq(); break;
                    case 5: cout<<"\n\n\n\t\tExiting..."<<endl;
                                delay(1000);
                            exit(0); break;
                    default:cout<<"\n Enter valid choice ! ";
                    goto label;
                }
}

int main()
{
    main_menu();
    return 0;
}


