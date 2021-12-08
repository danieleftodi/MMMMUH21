#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <unistd.h>

using namespace std;

struct Customer
{
    //Kundens ID från 0, 1, 2, osv..
    int Id;
    //Kundens namn
    std::string name;
    //Kundens hemstad
    std::string city;
    //Kundens län
    std::string state;
    //Dagar sedan senaste besök
    int Last_visit;
    //Totalt värde av kundens inköp
    int Total_sales;
    //Datum för input
    std::string format_date(int date);

} customer;

struct Table
{
    //Redovisar värdet av sammanlagd försäljning
    void get_total_sales();
    // Redovisar antalet kunder genom att hämta högsta angedda siffer-ID
    void get_max_id();
    // Anger Dagens datum
    void write_date();
    // Avläser dagens datum
    void read_date();
    //Skapar tabellen som uppvisar datan
    void print_table();//
    //Skapar en ny rad på tabellen
    std::string insert_row();//
} table;

struct Interface
{
    //Visualiserar vår interface
    void show_interface();
    //Visar användarens olika interaktions alternativ
    void show_options();
    //Adderar en ny kund till listan
    void handle_add_cust();
    //Uppdaterar data om valfri kund baserat på id
    void handle_update_cust();
    //Raderar data om valfri kund baserat på id
    void handle_delete_cust();
    //Visar upp individuell kund baserat på id
    void show_cus(int num);
} interface;

std::vector <Customer> customer_list;
int ID = 0;

void readInCust();
void exit_program();

int main()
{
    
    readInCust();
    
//    bool inSystem = true;
//    int choice = 0;
//    while(inSystem)
//    {
//        interface.show_options();
//        std::cin >> choice;
//        switch (choice)
//        {
//            //Add customer
//            case 1:
//                interface.handle_add_cust();
//                break;
//            //update Customer
//            case 2:
//                interface.handle_update_cust();
//                break;
//            //Show Customers table
//            case 3:
//                interface.show_interface();
//                break;
//            //Delete Customer
//            case 4:
//                interface.handle_delete_cust();
//                break;
//            //Show total sales
//            case 5:
//                table.get_total_sales();
//                break;
//            //Exit program
//            case 6:
//                std::cout << "Exit program\n";
//                exit_program();
//                inSystem = false;
//                break;
//            case 7:
//                for(auto vec : customer_list)
//                {
//                    std::cout << vec.name << " " << vec.Id << std::endl;
//                }
//                break;
//            default:
//                std::cout << "Something went wrong!\n";
//                break;
//        }
//    }

    return 0;
}

//read in customers from file and store in vector
void readInCust()
{
    std::string filename="customers.txt";
    std::ifstream file;
    file.open(filename, std::ios_base::in);
    
    if ( file.is_open() )
    {
        printf("DBG_LOG :: Found file: %s\n", filename.c_str() );
    }


//	bool found_record = false;

    std::string field_id,
                field_name,
                field_city,
                field_state,
                field_last_visit,
                field_total_sales;
    
    printf("DBG_LOG :: Pre while-loop\n");

	while (!file.eof())
	{
        printf("DBG_LOG :: 1st line in while-loop\n");
        getline(file, field_id, ',');
		getline(file, field_name, ',');
		getline(file, field_city, ',');
        getline(file, field_state, ',');
        getline(file, field_last_visit, ',');
        getline(file, field_total_sales, ',');

        printf("DBG_LOG :: %s\n", field_id.c_str());
        printf("DBG_LOG :: %s\n", field_name.c_str());
        printf("DBG_LOG :: %s\n", field_city.c_str());
        printf("DBG_LOG :: %s\n", field_state.c_str());
        printf("DBG_LOG :: %s\n", field_city.c_str());
        printf("DBG_LOG :: %s\n", field_last_visit.c_str());
        printf("DBG_LOG :: %s\n", field_total_sales.c_str());
        
        Customer cust;
        //    cust.Id = stoi(field_id);
        try { cust.Id = stoi(field_id); }
        catch (const std::exception& e) {
            printf("\nDBG_LOG :: Try-Catch :: stoi Error: %s\n", e.what());
            cust.Id = '\0';
        }
        cust.name = field_name;
        cust.city = field_city; 
        cust.state = field_state;
        //    cust.Last_visit = stoi(field_last_visit);
        try { cust.Last_visit = stoi(field_last_visit); }
        catch (const std::exception& e) {
            printf("\nDBG_LOG :: Try-Catch :: stoi Error: %s\n", e.what());
            cust.Last_visit = '\0';
        }
        //    cust.Total_sales = stoi(field_total_sales);
        try { cust.Total_sales = stoi(field_total_sales); }
        catch (const std::exception& e) {
            printf("\nDBG_LOG :: Try-Catch :: stoi Error: %s\n", e.what());
            cust.Total_sales = '\0';
        }
        customer_list.push_back(cust);

    }

	file.close();
}

//void Interface::show_options()
//{
//    std::cout << "What would you like to do?\n"
//    "1 - Add Customer\n2 - Update Customer\n3 - Show Customers Table\n"
//    "4 - Delete Customer\n5 - Show total sales\n6 - Exit Program\n";
//}


/*Customer*/
//Add customer
//void Interface::handle_add_cust()
//{
//    std::string custName;
//    std::string custCity;
//    std::string custState;
//    int custLastVisit;
//    int custTotalSales;
//    Customer newCustomer;
//    std::cin.ignore();
//
//    std::cout << "Enter Customer first and last name: ";
//    getline(std::cin, custName);
//    std::cout << "Enter Customer City: ";
//    getline(std::cin, custCity);
//    std::cout << "Enter Customer State: ";
//    getline(std::cin, custState);
//    std::cout << "Enter Customer's Last Visit(yyyymmdd): ";
//    std::cin >> custLastVisit;
//    std::cout << "Enter Customer's Total Sales': ";
//    std::cin >> custTotalSales;
//
//    int maxId = 0;
//    for(int i = 0; i < customer_list.size(); i++)
//    {
//        if(customer_list[i].Id > maxId)
//        {
//            maxId = customer_list[i].Id;
//        }
//    }
//    ID = maxId + 1;
//
//    newCustomer.Id = ID;
//    newCustomer.name = custName;
//    newCustomer.city = custCity;
//    newCustomer.state = custState;
//    newCustomer.Last_visit = custLastVisit;
//    newCustomer.Total_sales = custTotalSales;
//
//    //lägg till customer i vectorn
//    customer_list.push_back(newCustomer);
//
//    // ofstream fout;
//
//    // //opens an existing file or creates a new file
//    // fout.open("customers.txt", ios::out);
//
//    //insert data to file
//    // fout << ID << ","
//    //      << custName << ","
//    //      << custCity << ","
//    //      << custState << ","
//    //      << custLastVisit << ","
//    //      << custTotalSales << "\n";
//
//    // fout.close();
//    //ID++;
//}

//update customer
//void Interface::handle_update_cust()
//{
//    int customer_id = 0;
//    std::string update_name = "", update_city = "", update_state = "";
//    int update_lastVisit = 0, update_totalSales = 0;
//    std::cout << "Enter customer ID to update: ";
//    std::cin >> customer_id;
//
//    if (customer_id > customer_list.size() || customer_id < 1)
//    {
//        std::cout << "No customer ID " << customer_id << " exists\n";
//    }
//    else
//    {
//        for(int i = 0; i < customer_list.size(); i++)
//        {
//            if(customer_list[i].Id == customer_id)
//            {
//                std::cin.ignore();
//                std::cout << "Found customer Id " << customer_id << std::endl;
//                std::cout << "Enter updated name: (Currently: " << customer_list[i].name << "): ";
//                std::getline(std::cin, update_name);
//                std::cout << "Enter updated city: (Currently: " << customer_list[i].city << "): ";
//                std::getline(std::cin, update_city);
//                std::cout << "Enter updated state: (Currently: " << customer_list[i].state << "): ";
//                std::getline(std::cin, update_state);
//                std::cout << "Enter updated last visit as YYYYMMDD: (Currently: " << customer_list[i].Last_visit << "): ";
//                std::cin >> update_lastVisit;
//                std::cout << "Enter updated total sales: (Currently: " << customer_list[i].Total_sales << "): ";
//                std::cin >> update_totalSales;
//
//                customer_list[i].name = update_name;
//                customer_list[i].city = update_city;
//                customer_list[i].state = update_state;
//                customer_list[i].Last_visit = update_lastVisit;
//                customer_list[i].Total_sales = update_totalSales;
//                std::cout << "Customer " << customer_id << " updated.\n";
//
//            }
//        }
//    }
//}

//Delete customer **inte klar**
//void Interface::handle_delete_cust()
//{
//    int delete_cust = 0;
//    std::cout << "Enter customer ID to delete: ";
//    std::cin >> delete_cust;
//    if (delete_cust > customer_list.size() || delete_cust < 1)
//    {
//        std::cout << "No customer Id " << delete_cust << " exist\n";
//    }
//    else
//    {
//        --delete_cust;
//        char deleteted;
//        std::cout << "Found customer ID " << delete_cust + 1 << " with the following information:\n";
//        std::cout << "Name: " << customer_list[delete_cust].name << std::endl
//            << "City: " << customer_list[delete_cust].city << std::endl
//            << "State: " << customer_list[delete_cust].state << std::endl
//            << "Last Visit: " << customer_list[delete_cust].format_date(customer_list[delete_cust].Last_visit) << std::endl
//            << "Total Sales: " << customer_list[delete_cust].Total_sales
//            << std::endl;
//        std::cout << "Are you sure you want to delete this customer? (Y or N): ";
//        std::cin >> deleteted;
//            if(toupper(deleteted))
//            {
//                std::cout << "Customer deleted.\n";
//
//            }
//            else
//            {
//                std::cout << "customer not deleted.\n";
//            }
//    }
//}


//void Table::get_total_sales()
//{
//    int totalSales = 0;
//    for (int sales = 0; sales < customer_list.size(); sales++)
//    {
//        totalSales += customer_list[sales].Total_sales;
//    }
//    std::cout << "Total company sales are: $" << totalSales << std::endl;
//}


//std::string Table::insert_row()
//{
//    return  "|-----|--------------------|---------------|----------|---------------|---------------|\n";
//}

//print table
//void Table::print_table()
//{
//    std::string table_1 = "|=====|====================|===============|==========|===============|===============|\n";
//    std::string header = "Melina's Customer Managment System";
//
//    std::cout << "|" << std::right << std::setfill('-') << std::setw(86) << "|" << std::endl
//         << "|" << std::right << std::setfill(' ') << std::setw(86) << "|" << std::endl
//         << std::left << "|" << std::setw(85) << header << "|" << std::endl
//         << "|" << std::setw(85) << " " << "|\n" << table_1;
//
//    std::cout << std::left << "|" << std::setw(5) << "ID" << "|" << std::setw(20) << "Name" << "|"
//         << std::setw(15) << "City" << "|" << std::setw(10) << "State" << "|" << std::setw(15)
//         << "Last visit" << "|" << std::setw(15) << "Total sales" << "|\n";
//
//    std::cout << table_1;
//}

//show customer
//void Interface::show_cus(int num)
//{
//    for(int cust = 0; cust < num; cust++)
//        {
//            std::cout << "|" << std::setw(5) << customer_list[cust].Id << "|"
//                << std::setw(20) << customer_list[cust].name << "|"
//                << std::setw(15) << customer_list[cust].city << "|"
//                << std::setw(10) << customer_list[cust].state << "|"
//                << std::setw(15) << customer_list[cust].format_date(customer_list[cust].Last_visit) << "|$"
//                << std::setw(14) << customer_list[cust].Total_sales << "|\n"
//                << table.insert_row();
//        }
//}

//make date to string
//std::string Customer::format_date(int date)
//{
//    std::string str1,
//                str2,
//                str_year = "",
//                str_month = "",
//                str_day = "";
//
//    str1 = std::to_string(date);
//    for(int i = 0; i < str1.length(); i++)
//    {
//        if(i < 4)
//        {
//            str_year += str1[i];
//        }
//        else if(i < 6)
//        {
//            str_month += str1[i];
//        }
//        else
//        {
//            str_day += str1[i];
//        }
//    }
//    str2 = str_year + "-" + str_month + "-" + str_day;
//    return str2;
//}

//void Interface::show_interface()
//{
//    std::string select = "";
//    std::cout << "Select number of customer to show (Enter '*' to show all): ";
//    std::cin >> select;
//
//    table.print_table();
//
//    if(select == "*")
//    {
//        for(int cust = 0; cust < customer_list.size(); cust++)
//        {
//            std::cout << "|" << std::setw(5) << customer_list[cust].Id << "|"
//                << std::setw(20) << customer_list[cust].name << "|"
//                << std::setw(15) << customer_list[cust].city << "|"
//                << std::setw(10) << customer_list[cust].state << "|"
//                << std::setw(15) << customer_list[cust].format_date(customer_list[cust].Last_visit) << "|$"
//                << std::setw(14) << customer_list[cust].Total_sales << "|\n"
//                << table.insert_row();
//        }
//    }
//    else
//    {
//        interface.show_cus(stoi(select));
//    }
//
//}


//void exit_program()
//{
//    std::ofstream fout;
//    bool firsttime = true;
//    for (int i = 0; i < customer_list.size(); i++)
//    {
//        if(firsttime)
//        {
//            fout.open("customers.txt", std::ios::trunc);
//            firsttime = false;
//        }
//        else
//        {
//            fout.open("customers.txt", std::ios::app);
//        }
//        std::cout << customer_list[i].Id << "," << customer_list[i].name << "," << customer_list[i].city
//             << "," << customer_list[i].state << "," << customer_list[i].Last_visit << ","
//             << customer_list[i].Total_sales << "\n";
//        fout << customer_list[i].Id << "," << customer_list[i].name << "," << customer_list[i].city
//             << "," << customer_list[i].state << "," << customer_list[i].Last_visit << ","
//             << customer_list[i].Total_sales << "\n";
//        sleep(3);
//    }
//    //_sleep(10000);
//    fout.close();
//
//}


//customer_list.erase(customer_list.begin() + den du vill ta bort);
