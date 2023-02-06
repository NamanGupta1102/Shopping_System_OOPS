#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
//e=0 customer
//e=1 employee
//employee pasword is abc
class basket;
class user 
{
    string name;
    string pass;
    protected :
    int e;

    public:
    user()
    {
      name ="Default_name";
      pass = "Default_pass";
      e =0;
    }
    
    void reg()
    {
      ofstream app;
      app.open("lr.csv",ios::app);
      string a,b;
      cout<<"\t\t\t\t------Registration-------- \n";
      cout<<"\t\t\t\tCreate a new user name: ";
      cin>>a;
      app<< a<<",";
      l1:
      cout<<"\t\t\t\tSelect a new password: ";
      cin>>a;
      cout<<"\t\t\t\tRenter the password: ";
      cin>>b;
      if(a!=b)
      {
        cout<<"\t\t\t\tPasswords don't match\n";
        goto l1;
      }
      app<< a<<",";
      //cout<<"--------------";
      l2:
      cout<<"\n\t\t\t\tEnter 0 if you are a customer\n\t\t\t\tEnter 1 if you are an employee: ";
      cin>>a;
      // cout<<"--------------";
      e = 0;
      if(a == "1")
      {
        cout<<"\t\t\t\tEnter employee password: ";
        cin>>b;
        if(b!="abc")
        {
          cout<<"\t\t\t\tWrong password, try again\n";
          goto l2;
        }
        e=1;
      }
      else if(a != "0")
      {
        cout<<"\t\t\t\tInvalid input , please try again\n";
        goto l2;
      }
      app<<a<<"\n";
      cout<<"\t\t\t\tSuccessfully registred\n";
      app.close();
      }

      void login()
      {
        cout<<"\t\t\t\t---------Login---------\n";
        ifstream see;
        see.open("lr.csv");
        string w,p;
        int c=0;
        cout<<"\t\t\t\tEnter Username: ";
        cin>>p;
        while(getline(see,w,','))
        {
          if(w == p)
          {
            c++;
            getline(see,w,',');
            l1:
            cout<<"\t\t\t\tEnter password: ";
            cin>>p;
            
            if(p != w)
            {
              cout<<"\t\t\t\tWrong password \n ";
              goto l1;
            }
            getline(see,w,'\n');
            if(w=="1")
            {
              cout<<"\n\n\t\t\t\tWelcome Employee, Thank You for working hard\n";
              e = 1;
            }
            else
            {
              // cout<<"--------------";
              e = 0;
              cout<<"\n\n\n\t\t\t\tWelcome dear customer :-\n";
            }
            break;
          }
          else
          {
            getline(see,w,',');
            getline(see,w,'\n');
          }
        }
        if(c==0)
        {
          cout<<"\n\n\n\t\t\t\tUsername not found\n";
          login();
        }
        see.close();

      }

    
};
// id , name, price, stock 
class product
{
  int price;
  string name;
  int stock;
  int id;
  public:
  void convert(product a[],int &n)
  {
    ifstream see;
    see.open("product.csv");
    string w;
    int i=0;
    n=0;
    while(getline(see,w,','))
    {
      a[i].id = stoi(w);
      getline(see,w,',');  
      a[i].price = stoi(w);
      getline(see,w,',');
      a[i].stock = stoi(w);
      getline(see,w,'\n');
      a[i++].name = w;
      n++;
    }
    see.close();
  }
  void out(product a[], int n)
  {
    cout<<"\t\t\tId   \t|\tprice \t|\tstock \t|\tname\n";
    int i=0;
    while(i<n)
    {
      cout<<"\t\t\t"<<a[i].id<<"\t|\t"<<a[i].price<<"  \t|\t "<<a[i].stock<<"  \t|\t"<<a[i].name<<endl;
      i++;
    }
  }

  void enter(product a[],int &n)
  {
    ofstream edit;
    edit.open("product.csv",ios_base::app);
  
    //cout<<"Enter product id:\n";
    a[n].id = 1000+n;
    cout<<"\t\t\tEnter product name: ";
    cin>>a[n].name;
    cout<<"\t\t\tEnter product cost: ";
    cin>>a[n].price;
    cout<<"\t\t\tEnter product stock: ";
    cin>>a[n].stock;
    edit<<a[n].id<<","<<a[n].price<<","<<a[n].stock<<","<<a[n].name<<"\n";
    n++;
    edit.close();
  }

  void searched(product obj[],int n)
  {
    int s =0;
    int c =0;
    l1:
    cout<<"\t\t\t\tEnter 0 for search by name\n\t\t\t\tEnter 1 for search by id\n\t\t\t\t";
    cin>>s;
    string nam;
    int ids;
    
    if(s==0)
    {
      cout<<"\t\t\t\tEnter product name: ";
    cin>>nam;
      for(int i = 0;i<n;i++)
      {
        if(nam == obj[i].name)
        {
          c++;
          cout<<"\t\t\t\tName : "<<obj[i].name<<endl;
          cout<<"\t\t\t\tID : "<<obj[i].id<<endl;
          cout<<"\t\t\t\tPrice : "<<obj[i].price<<endl;
          cout<<"\t\t\t\tStock : "<<obj[i].stock<<endl;
          break;
        }
      }
    }
    else if(s == 1)
    {
      cout<<"\t\t\t\tEnter product code: ";
      cin>>ids;
      for(int i = 0;i<n;i++)
      {
        if(ids == obj[i].id)
        {
          c++;
          cout<<"\t\t\t\tName : "<<obj[i].name<<endl;
          cout<<"\t\t\t\tID : "<<obj[i].id<<endl;
          cout<<"\t\t\t\tPrice : "<<obj[i].price<<endl;
          cout<<"\t\t\t\tStock : "<<obj[i].stock<<endl;
          break;
        }
      }
    }
    else
    {
      cout<<"\t\t\t\tWrong input for searching, please try again\n";
      goto l1;
    }  
    if(c==0)
    {
      cout<<"\t\t\t\tNot found\n";
    }
  }

  int sorch(product obj[],int n, int ids)
  {
    int c =0;
    
    
    for(int i =0;i<n;i++)
    {
      if(obj[i].id == ids)
      {
        
        return c; 
      }
      c++;
    }
    
    return -1;
    
  }

  void close(product o[],int n)
  {
    ofstream con;
    con.open("product.csv");
    int i = 0;
      int id = 1000;
    while(i<n)
    {
      //cout<<"Converting "<<id<<endl;
      if(o[i].stock==0)
      {
        i++;
        continue;
      }
      con<<id++<<","<<o[i].price<<","<<o[i].stock<<","<<o[i].name<<"\n";
      i++;
    }
    con.close();

  }
  friend basket;

  void del(product o[],int n)
  {
    int id;
    int st;
    cout<<"\t\t\t\tEnter product id to delete stock: ";
    cin>>id;
    cout<<"\t\t\t\tEnter Amount of stock to be deleted: ";
    cin>>st;
    int z = sorch(o,n,id);
    if(z == -1)
    {
      cout<<"\t\t\t\tProduct Id not found:\n";
    }
    else
    {
      if(o[z].stock < st)
      {
        o[z].stock = 0;
      }
      else {
      o[z].stock = o[z].stock - st;
      }
    }
  }

  void ad(product o[],int n)
  {
    int id;
    int st;
    cout<<"\t\t\t\tEnter product id to add stock: ";
    cin>>id;
    cout<<"\t\t\t\tEnter Amount of stock to be added: ";
    cin>>st;
    int z = sorch(o,n,id);
    if(z == -1)
    {
      cout<<"\t\t\t\tProduct Id not found:\n";
    }
    else
    {
      o[z].stock = o[z].stock + st;

    }
  }

};

class basket
{
  product bas[10];
  int st[10];
  int siz;
   // array of products which is the basket
  //int n;
  public:
  basket(){ siz =0;}
  void add(product obj[],int n)
  {
    int ids;
    cout<<"\t\t\t\tEnter id of product to be added: ";
    cin>>ids;
   // cout<<"its working\n";
    //product *o = new product; 
    int o =0;
    o =  bas[0].sorch(obj,n,ids);
    if( o == -1)
    {
        cout<<"\t\t\t\tProduct not found\n";
        return;
    }
    else
    {
      int sto;
      cout<<"\t\t\t\tEnter stock: ";
      cin>>sto;
      if(sto>obj[o].stock)
      {
        cout<<"\t\t\t\tNot enough stock\n";
        return;
      }
      obj[o].stock = obj[o].stock - sto;
      // cout<<"O stock = "<<obj[o].stock<<"  Name = "<<obj[o].name<<" o = "<<o<<endl;
      st[siz] = sto;
      bas[siz] = obj[o];
      siz++;
      //baas.push_back(*o);
    }
  }

  void display_cart()
  {
    //int c =0;
    //product o[siz];
    int su =0;
    for(int i =0;i<siz;i++)
    {
      bas[i].stock = st[i];
      su+= bas[i].stock * bas[i].price;
    }
    cout<<"\t\t\t\tYour Cart has these items :-\n";
    bas[0].out(bas ,siz);
    cout<<"\n------------------------ Total cost = " <<su<<" ------------------------\n"<<endl;
  }

};

class menu: public basket,public user
{
    product obj[50];
    int n;


    public:
    void fin()
    {
      obj[0].convert(obj,n);
      
      int lr;
      l1:
      cout<<"\t\t\t\tEnter 1 to login or 2 to register: ";
      cin>>lr;
      
      if(lr == 1)
      {
        login();
      }
      else if(lr == 2)
      {
        reg();
      }
      else
      {
        cout<<"\t\t\t\tWrong input\n";
        goto l1;
      }
      //cout<<"Emoloyee status  = "<<e<<endl;

      if(e == 0)
      {
        
        cust_menu();
      }
      else if(e == 1)
      {
        
        emp_menu();
      }  
      obj[0].close(obj,n);
    }

    void emp_menu()
    {
      int s = 1;// view append deleye add
      while(s!=6)
      {
        cout<<"\t\t\t\tEnter 1 to View catalogue\n";
        cout<<"\t\t\t\tEnter 2 to Add new product\n";
        cout<<"\t\t\t\tEnter 3 to Remove stocks of a product\n";
        cout<<"\t\t\t\tEnter 4 to Add stocks to existing product\n";
        cout<<"\t\t\t\tEnter 5 to Search for products\n";
        cout<<"\t\t\t\tEnter 6 to END\n\t\t\t\t";
        cin>>s;
        switch(s)
        {
          case 1:
          obj[0].out(obj,n);
          break;
          case 2:
          obj[0].enter(obj,n);
          break;
          case 3:
          obj[0].del(obj, n);
          break;
          case 4:
          obj[0].ad(obj,n);
          break;
          case 5:
          obj[0].searched(obj,n);
          break;
          case 6:
          cout<<"\t\t\t\t\tThank You for using Tequip\n";
          break;
          default:
          cout<<"\t\t\t\tWrong input\n";

        }
      }
    }

    void cust_menu()
    {
      int ch =0;
      int s = 1;
      while(true)
      {
        cout<<"\t\t\t\tEnter 1 to View catalogue\n";
        cout<<"\t\t\t\tEnter 2 to Search for products\n";
        cout<<"\t\t\t\tEnter 3 to Add product to cart\n";
        cout<<"\t\t\t\tEnter 4 to View cart\n\t\t\t\t";
        cin>>s;
        switch(s)
        {
          case 1:
          obj[0].out(obj,n);
          break;
          case 2:
          obj[0].searched(obj,n);
          break;
          case 3:
          add(obj, n);
          break;
          case 4:
          display_cart();
          cout<<"\t\t\t\tEnter 1 to Pay and leave\n\t\t\t\tEnter 2 to continue shopping: ";
          cin>>ch;
          if(ch == 1)
          {
            cout<<"\t\t\t\tPayment Successful\n";
            cout<<"\t\t\t\tThank you for using Tequip\n";
            return;
          }
          break;
          default:
          cout<<"\t\t\t\tWrong input\n";

        }
      }
    }
};


int main()
{
  menu a;
  a.fin();
  return 0;
}