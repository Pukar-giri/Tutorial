

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;
typedef struct
{
    string name;
    string id;
    float stockqty;
    float price;
} item;

class stock
{
  protected:
   static vector<item> lists;

  public:
    stock()
    {
        ifstream infile("./stock.clx");
        string line;
	//lists.clear();
        while (getline(infile, line))
        {
            getline(infile, line);
            string name = line;
            getline(infile, line);
            string id = line;
            getline(infile, line);
            float stock = stof(line);
            getline(infile, line);
            float price = stof(line);
            getline(infile, line);
            add_item(name,id,stock,price);
        }
        infile.close();
    }
    ~stock()
    {
        ofstream outfile("./stock.clx");
        for (auto item : lists)
        {
            outfile<<"Start_Item<<"<<endl;
            outfile<<item.name<<endl;
            outfile<<item.id<<endl;
            outfile<<item.stockqty<<endl;
            outfile<<item.price<<endl;
            outfile<<">>End_Item"<<endl;
        }
        outfile.close();
    }
    void show()
    {
        cout << string(65, '_') << endl;
        cout << "|" << setw(25) << "Item Name"
             << "|" << setw(15) << "Item Id"
             << "|" << setw(10) << "Stock Qty"
             << "|" << setw(10) << "Price"
             << "|" << endl;
        cout << "|" << setw(25) << string(25, '_') << "|" << setw(15) << string(15, '_') << "|" << setw(10) << string(10, '_') << "|" << setw(10) << string(10, '_') << "|" << endl;
        for (auto item : lists)
        {
            cout << "|" << left << setw(25) << item.name << "|" << setw(15) << item.id << "|" << right << setw(10) << item.stockqty << "|" << setw(10) << item.price << "|" << endl;
        }
        cout << "|" << setw(25) << string(25, '_') << "|" << setw(15) << string(15, '_') << "|" << setw(10) << string(10, '_') << "|" << setw(10) << string(10, '_') << "|" << endl;
    }
    void add_item(string name,string id, float qty, float price)
    {
        for (auto item : lists)
        {
            if (item.name==name || item.id ==id )
            {
                return;
            }
        }
        lists.push_back({name,id,qty,price});
    }
    item get_item (string name)
    {
        for (auto item :lists)
        {
            if (item.name==name)
            {
                return item;
            }            
        }
        return {"","",0.0,0.0} ;
    }
  static void update_stock(string iname,float iqty)
    {
        for (int i =0;i<lists.size();i++)

        {
            if(lists[i].name==iname)
            {
                 if (lists[i].stockqty>=iqty)
                 {
                    lists[i]={lists[i].name,lists[i].id,lists[i].stockqty-iqty,lists[i].price};
                    return;
                 }
                 else
                 {
                    throw invalid_argument("Out Of Stock");
                 }
            }
                     
        }
        throw invalid_argument("no such item known");
    }
};
vector <item>stock::lists={};
class bill
{
  protected:
    vector<string> id;
    vector<string> name;
    vector<float> qty;
    vector<float> price;
    vector<float> amount;
    float total_amount=0;
    stock stk;

  public:
    bill() = default;

    void add_item(string iname, float iqty)
    {
        item item1=stk.get_item(iname);
	if(item1.name!="")
        {
        stk.update_stock(iname,iqty);
        name.push_back(iname);
        id.push_back(item1.id);
        qty.push_back(iqty);
        price.push_back(item1.price);
	amount.push_back(item1.price*iqty);
        total_amount+=(item1.price*iqty);
        }

    }
friend std::ostream &operator<<(std::ostream &out, bill &bill)
  {
	cout << string(76, '_') << endl;
        cout << "|" << setw(25) << "Name"
             << "|" << setw(15) << "Id"
             << "|" << setw(10) << "Qty"
             << "|" << setw(10) << "Price"
	     << "|" << setw(10) << "Amount"
             << "|" << endl;
        cout << "|" << setw(25) << string(25, '_') << "|" << setw(15) << string(15, '_') << "|" << setw(10) << string(10, '_') << "|" << setw(10) 	<< string(10, '_')<< "|"<< setw(10) 	<< string(10, '_') << "|" << endl;
        for (int i=0;i<bill.name.size();i++)
        {
            cout << "|" << left << setw(25) << bill.name[i] << "|" << setw(15) << bill.id[i]<< "|" << right << setw(10) << bill.qty[i] << "|" << 		setw(10) << bill.price[i] << "|"<<setw(10) << bill.price[i]*bill.qty[i]<< "|" << endl;
        }
        cout << "|" << setw(25) << string(25, '_') << "|" << setw(15) << string(15, '_') << "|" << setw(10) << string(10, '_') << "|" << setw(10) 	<< string(10, '_')<< "|"<< setw(10) 	<< string(10, '_') << "|" << endl;    
    return out;
  }
};

int main()
{
//Todo : add user-interfacce for this billing app
    stock s1; ///this is to be used for initializing the stock;
    s1.add_item("potato","tha77688",100,35);
    s1.add_item("rice","hel53435",500,75);
    s1.add_item("jam","tha78688",20,250);
    s1.add_item("bag","hel33935",60,600);
    s1.add_item("harpic","tha77088",30,350);
    s1.add_item("flour","hel33735",75,90);   
    bill b1;
    b1.add_item("potato",5);
    b1.add_item("rice",10);
    b1.add_item("bag",5);
    s1.show();
    cout<<endl;
    cout<<b1<<endl;   
}
