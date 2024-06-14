
#include <iostream>
#include <Windows.h>
#include <mysql.h>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include<string>
#include <time.h>
#include <conio.h>
#include<ctime>


using namespace std;


int main()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;

    int qstate;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "mealticketmachine", 0, NULL, 0);

    system("CLS");
    if (conn)
    {


        ////////////////////////////////////////////////////// MAIN PAGE /////////////////////////////////////////////////////////////

        cout << "=================================== MEAL TICKET MACHINE =============================" << endl;
        cout << "                                                                                     " << endl;
        cout << "                                                                                     " << endl;
        cout << "                                                                                     " << endl;
        cout << "                                      1. ADMIN                                       " << endl;
        cout << "                                                                                     " << endl;
        cout << "                                      2. CUSTOMER                                    " << endl;
        cout << "                                                                                     " << endl;
        cout << "                                                                                     " << endl;
        cout << "                                                                                     " << endl;
        cout << "                                                                                     " << endl;
        cout << "  ^^ OPTION (1) FOR ADMIN USER  AND OPTION (2)FOR CUSTOMER USER PLEASE ENTER YOUR^^  " << endl;
        cout << " ====================================================================================" << endl;
        cout << endl;
        cout << " ENTER YOUR OPTION : ";
        int main_input;
        cin >> main_input;
        cin.clear(); cin.ignore(1000, '\n');
        cout << endl;



        if (main_input == 1)
        {
            /////////////////////////////////////////////////////// SIGNUP AND LOGIN PAGE ///////////////////////////////////////////////////////
            system("cls");
            cout << "=================================== MEAL TICKET MACHINE =============================" << endl;
            cout << "                                                                                     " << endl;
            cout << "                                ~ SIGNUP AND LOGIN PAGE ~                            " << endl;
            cout << "                                                                                     " << endl;
            cout << "                                                                                     " << endl;
            cout << "                                    1. ADMIN LOGIN                                   " << endl;
            cout << "                                                                                     " << endl;
            cout << "                                    2. ADMIN SIGN UP                                 " << endl;
            cout << "                                                                                     " << endl;
            cout << "                                                                                     " << endl;
            cout << "                                                                                     " << endl;
            cout << "                                                                                     " << endl;
            cout << " ====================================================================================" << endl;
            cout << endl;
            cout << " ENTER YOUR OPTION : ";
            int Admi_input;
            cin >> Admi_input;
            cin.clear(); cin.ignore(1000, '\n');
            cout << endl;


            if (Admi_input == 1)
            {
            adminLogin:

                system("cls");
                cout << "===========================================  ADMIN LOGIN ====================================" << endl << endl;

                int ch;
                string admin_name, password;
                cout << "\t\t\t\t ADMIN NAME: ";
                cin >> admin_name;
                cout << endl;
                cout << "\t\t\t\t PASSWORD: ";
                ch = getch();

                while (ch != 13)

                {
                    password.push_back(ch);
                    cout << '*';
                    ch = getch();
                }

                cout << endl;
                cout << endl;

                string login_query = "select * from admin where admin_name  = '" + admin_name + "' and password = '" + password + "' ";
                const char* qn = login_query.c_str();

                qstate = mysql_query(conn, qn);

                if (!qstate)
                {
                    res = mysql_store_result(conn);
                    if ((row = mysql_fetch_row(res)))
                    {
                        cout << "\n\n\nlogged in sucessfully" << endl;
                        Sleep(2000);
                        system("cls");
                        goto admin;
                    }
                    else
                    {
                        cout << "wrong admin_name or password" << endl;

                        system("pause");
                        main();
                    }
                }
                else
                {
                    cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
                }

            }

            else if (Admi_input == 2)
            {


                system("CLS");
                int ch;
                string admin_name, password, phone_no, address, email;
                cout << endl;
                cout << " ================================  PLEASE REGISTER FIRST ============================ " << endl;
                cout << " " << endl;
                cout << " ADMIN NAME  : ";
                getline(cin, admin_name);
                cout << endl;
                cout << " PASSWORD : ";

                ch = getch();
                while (ch != 13)
                {
                    password.push_back(ch);
                    cout << '*';
                    ch = getch();
                }

                cout << endl;
                cout << endl;
                cout << " PHONE_NUMBER  : ";
                getline(cin, phone_no);
                cout << endl;
                cout << " ADDRESS  : ";
                getline(cin, address);
                cout << endl;
                cout << " EMAIL  : ";
                getline(cin, email);
                cout << endl;

                stringstream ss;
                ss << "INSERT INTO admin (admin_name, password, phone_no,address,email) values ('" << admin_name << "','" << password << "','" << phone_no << "','" << address << "','" << email << "')";
                string query = ss.str();
                const char* q = query.c_str();
                qstate = mysql_query(conn, q);
                if (qstate == 0)
                {
                    cout << " NEW ADMIN ADDED SUCCESSFUL..." << endl;
                    cin.ignore(1000, '\n');
                    //  goto customerLoginPage;
                    goto adminLogin;

                }
                else
                {
                    cout << " DATABASE ERROR X";
                }

            }


            //admin page()
        admin:
            system("CLS");
            cout << endl;
            cout << "=================================== ADMIN SETTING PAGE ==============================" << endl;
            cout << "                                                                                     " << endl;
            cout << "                                                                                     " << endl;
            cout << "                                    1. MEAL MENU SETTING                             " << endl;
            cout << "                                                                                     " << endl;
            cout << "                                    2. REPORT GENERATION AND ANALYSIS                " << endl;
            cout << "                                                                                     " << endl;
            cout << "                                    0. EXIT                                          " << endl;
            cout << "                                                                                     " << endl;
            cout << "                                                                                     " << endl;
            cout << " ====================================================================================" << endl;
            cout << endl;
            string admin_input;
            cout << " ^^ ENTER YOUR OPTION : ";
            cin >> admin_input;
            cin.clear(); cin.ignore(1000, '\n');

            if (admin_input == "1")
            {
                //management()
            management:
                system("CLS");
                cout << " #_MEAL MENU SETTING                                                                  " << endl;
                cout << "                                                                                     " << endl;
                string id, name, price;
                double d_price;

                cout << "                                  MEAL MENU                                       " << endl;
                cout << " ---------------------------------------------------------------------------------" << endl;
                cout << "  Code\t" << " Name\t\t" << " Price\t" << endl;
                //cout << " \t" << "\t\t" << "\t" << endl;
                cout << " ---------------------------------------------------------------------------------" << endl;
                qstate = mysql_query(conn, "SELECT * FROM meal"); ///////display item
                if (!qstate)
                {
                    res = mysql_store_result(conn);
                    while (row = mysql_fetch_row(res))
                    {
                        cout << left << "  " << setw(5) << row[0] << " " << setw(22) << row[1] << " " << setw(15) << row[2] << "" << endl;
                    }
                    cout << " ===================================================================================" << endl;
                }
                cout << endl;
                cout << " \n 1. TO ADD MEAL : \n 2. TO DELETE MEAL : \n 3. TO UPDATE MEAL : \n 4. EXIT" << endl << endl;
                cout << " ^^ ENTER YOUR CHOICE : ";
                cin >> admin_input;
                cin.clear(); cin.ignore(1000, '\n');


                if (admin_input == "1")
                {
                    //Process to add Meal
                    cout << endl;
                    cout << " TO ADD MEAL" << endl;
                    cout << " -----------" << endl;
                    cout << " MEAL NAME  : ";
                    getline(cin, name);
                    cout << " SET MEAL PRICE : ";
                    cin >> d_price; cin.clear(); cin.ignore(1000, '\n');
                    if (d_price > 0)
                    {
                        cout << endl;
                        string zero = "0";
                        stringstream strtodouble;
                        strtodouble << d_price;
                        stringstream ss;
                        ss << "INSERT INTO meal (Name, Price, Quantity, Sales) values ('" << name << "','" << strtodouble.str() << "','" << zero << "','" << zero << "')";
                        string query = ss.str();
                        const char* q = query.c_str();
                        qstate = mysql_query(conn, q);
                        if (qstate == 0)
                        {
                            cout << " MEAL ADD SUCCESSFUL..." << endl;
                            cin.ignore(1000, '\n');
                            goto management;
                        }
                        else
                        {
                            cout << " DATABASE ERROR X";
                        }
                    }
                    else if (d_price <= 0)
                    {
                        cout << endl << " ERROR  X!!! PLEASE ENTER VALID PRICE ";
                        cin.ignore(1000, '\n');
                        goto management;
                    }
                    else
                    {
                        cout << endl << " INVALID PRICE...!!!";
                        cin.ignore(1000, '\n');
                        goto management;
                    }
                }
                else if (admin_input == "2")
                {
                    //Process to delete
                    cout << endl;
                    cout << " REMOVE A MEAL " << endl;
                    cout << " --------------" << endl;
                    cout << " ENTER THE MEAL CODE TO REMOVE :";
                    cin >> admin_input; cin.clear(); cin.ignore(1000, '\n');
                    //delete

                    //confirmation message
                    string confirmation;
                    cout << endl << " REMOVE A MEAL? " << endl;
                    cout << "   (Y/N) : ";
                    getline(cin, confirmation);
                    if (confirmation == "y" || confirmation == "Y")
                    {
                        int count = 0;
                        stringstream ss;
                        ss << "SELECT * FROM meal WHERE Meal_ID = " + admin_input;
                        string query = ss.str();
                        const char* q = query.c_str();
                        qstate = mysql_query(conn, q);
                        if (qstate == 0)
                        {
                            res = mysql_store_result(conn);
                            while (row = mysql_fetch_row(res))
                            {
                                count++;
                            }
                            if (count > 0)
                            {
                                stringstream ss;
                                ss << "DELETE FROM meal WHERE Meal_ID = " + admin_input;
                                string query = ss.str();
                                const char* q = query.c_str();
                                qstate = mysql_query(conn, q);
                                cout << endl << " REMOVED SUCCESSFULLY...";
                                cin.ignore(1000, '\n');
                                goto management;
                            }
                            else
                            {
                                cout << endl << " ERROR X... THIS CODE IS WRONG!!! ";
                                cin.ignore(1000, '\n');
                                goto management;
                            }
                        }
                        else
                        {
                            cout << endl << " INVALID MEAL CODE...";
                            cin.ignore(1000, '\n');
                            goto management;
                        }
                    }
                    else
                    {
                        goto management;
                    }
                }
                else if (admin_input == "3")
                {
                    //Process to update
                    cout << endl;
                    cout << " TO UPDATE A MEAL " << endl;
                    cout << " -----------------" << endl;
                    cout << " ENTER THE MEAL CODE TO UPDATE : ";
                    cin >> admin_input; cin.clear(); cin.ignore(1000, '\n');
                    int count = 0;
                    stringstream ss;
                    ss << "SELECT * FROM meal WHERE Meal_ID = " + admin_input;
                    string query = ss.str();
                    const char* q = query.c_str();
                    qstate = mysql_query(conn, q);
                    if (qstate == 0)
                    {
                        res = mysql_store_result(conn);
                        while (row = mysql_fetch_row(res))
                        {
                            count++;
                        }
                        if (count > 0)
                        {
                            cout << endl << " UPDATE (" << admin_input << ") Meal Details" << endl;
                            cout << " NEW MEAL NAME  : ";
                            getline(cin, name);
                            cout << " NEW MEAL PRICE : ";
                            cin >> d_price; cin.clear(); cin.ignore(1000, '\n');
                            if (d_price > 0)
                            {
                                cout << endl;
                                stringstream strtodouble;
                                strtodouble << d_price;
                                stringstream ss;
                                ss << "UPDATE meal SET Name = '" << name << "',Price = '" << strtodouble.str() << "' where Meal_ID = '" << admin_input << "' ";
                                string query = ss.str();
                                const char* q = query.c_str();
                                qstate = mysql_query(conn, q);
                                if (qstate == 0)
                                {
                                    cout << " MEAL UPDATE SUCCESSFULLY " << endl;
                                    cin.ignore(1000, '\n');
                                    goto management;
                                }
                                else
                                {
                                    cout << "DATABASE ERROR X... ";
                                }
                            }
                            else if (d_price <= 0)
                            {
                                cout << endl << " ERROR X...PLEASE ENTER VALID PRICE!!! ";
                                cin.ignore(1000, '\n');
                                goto management;
                            }
                            else
                            {
                                cout << endl << " # INVALID PRICE  ...";
                                cin.ignore(1000, '\n');
                                goto management;
                            }
                        }
                        else
                        {
                            cout << endl << " WRONG MEAL CODE";
                            cin.ignore(1000, '\n');
                            goto management;
                        }
                    }
                    else
                    {
                        cout << endl << " INVALID MEAL CODE";
                        cin.ignore(1000, '\n');
                        goto management;
                    }
                }
                else if (admin_input == "4")
                {
                    // BACK TO ADMIN
                    goto admin;
                }
                else
                {
                    cout << endl << " SORRY, YOUR OPTION IS WRONG PLEASE TRY AGAIN ...";
                    cin.ignore(1000, '\n');
                    goto management;
                }
            }
            else if (admin_input == "2")
            {
                //report()
            report:
                system("CLS");
                cout << " ==================================== REPORT GENERATION AND ANALYSIS =======================================" << endl;
                cout << "                                                                                                            " << endl;
                cout << "                                                                                                            " << endl;
                cout << " -----------------------------------------------------------------------------------------------------------" << endl;
                cout << left << "  " << setw(5) << "Code" << " " << setw(14) << "Name" << " " << setw(6) << "Price" << " " << setw(6) << "Sales" << " " << setw(10) << "Sub-Total" << "" << endl;
                cout << "                                               " << endl;
                cout << " -----------------------------------------------------------------------------------------------------------" << endl;
                qstate = mysql_query(conn, "SELECT * FROM meal"); ///////display item
                if (!qstate)
                {
                    double grandtotal = 0;
                    res = mysql_store_result(conn);
                    while (row = mysql_fetch_row(res))
                    {
                        double subtotal = atof(row[2]) * atof(row[4]);
                        grandtotal += subtotal;
                        cout << "" << setw(5) << row[0] << "" << setw(20) << row[1] << "" << setw(6) << row[2] << "" << setw(6) << row[4] << "" << setw(10) << setprecision(2) << fixed << subtotal << "" << endl;
                    }

                    cout << "                                                                                                      " << endl;
                    cout << "                                                            TOTAL   | " << setw(17) << grandtotal << " " << endl;
                    cout << " ======================================================================================================" << endl;
                }
                cout << endl;

                cout << " \n 1. SORT BY NAME :  \n 2. SORT BY PRICE:  \n 3. SORT BY SALES: \n 4. SALES GRAPH \n 0. BACK" << endl;
                cout << " ENTER YOUR OPTION : ";
                cin >> admin_input; cin.clear(); cin.ignore(1000, '\n');

                if (admin_input == "1")
                {
                    //sort by name
                    system("CLS");
                    cout << "======================================== SORTED BY NAME ================================================= " << endl;
                    cout << "                                                                                                        " << endl;
                    cout << "                                                                                                        " << endl;
                    cout << "------------------------------------------------------------------------------------------------------- " << endl;
                    cout << left << "  " << setw(5) << "Code" << "" << setw(16) << "Name" << "" << setw(6) << "Price" << "" << setw(6) << "Sales" << "" << setw(10) << "Sub-Total" << "" << endl;
                    cout << "------------------------------------------------------------------------------------------------------- " << endl;

                    qstate = mysql_query(conn, "SELECT * FROM meal ORDER BY Name"); ///////display item
                    double grandtotal = 0;
                    res = mysql_store_result(conn);
                    while (row = mysql_fetch_row(res))
                    {
                        double subtotal = atof(row[2]) * atof(row[4]);
                        grandtotal += subtotal;
                        cout << "  " << setw(5) << row[0] << " " << setw(14) << row[1] << " " << setw(6) << row[2] << "" << setw(6) << row[4] << " " << setw(10) << setprecision(2) << fixed << subtotal << "" << endl;
                    }
                    cout << " ------------------------------------------------------------------------------------------------------" << endl;
                    cout << "                                                                                                       " << endl;
                    cout << "                                                             TOTAL     " << setw(10) << grandtotal << "" << endl;
                    cout << " ======================================================================================================" << endl;
                    cout << endl << " # Continue...";
                    cin.ignore(1000, '\n');
                    goto report;
                }
                else if (admin_input == "2")
                {
                    system("CLS");
                    //sort by price
                    cout << " ======================================== SORTED BY PRICE ========================================" << endl;
                    cout << "                                                                                                  " << endl;
                    cout << "                                                                                                  " << endl;
                    cout << "                                                                                                  " << endl;
                    cout << "                                                                                                  " << endl;
                    cout << left << "  " << setw(5) << "Code" << "" << setw(16) << "Name" << "" << setw(6) << "Price" << "" << setw(6) << "Sales" << "" << setw(10) << "Sub-Total" << "" << endl;
                    cout << " --------------------------------------------------------------------------------------------------" << endl;

                    qstate = mysql_query(conn, "SELECT * FROM meal ORDER BY Price"); ///////display item
                    double grandtotal = 0;
                    res = mysql_store_result(conn);
                    while (row = mysql_fetch_row(res))
                    {
                        double subtotal = atof(row[2]) * atof(row[4]);
                        grandtotal += subtotal;
                        cout << "  " << setw(5) << row[0] << " " << setw(14) << row[1] << " " << setw(6) << row[2] << " " << setw(6) << row[4] << "" << setw(10) << setprecision(2) << fixed << subtotal << "" << endl;
                    }
                    cout << " -------------------------------------------------------------------------------------------------" << endl;
                    cout << "                                                                                                  " << endl;
                    cout << "                                                         TOTAL     " << setw(10) << grandtotal << "" << endl;
                    cout << " =================================================================================================" << endl;
                    cout << endl << " BACK...";
                    cin.ignore(1000, '\n');
                    goto report;
                }
                else if (admin_input == "3")
                {
                    system("CLS");
                    //sort by sales
                    cout << " ======================================== SORTED BY SALES =========================================" << endl;
                    cout << "                                                                                                   " << endl;
                    cout << "                                                                                                   " << endl;
                    cout << "                                                                                                   " << endl;
                    cout << "                                                                                                   " << endl;
                    cout << left << "  " << setw(5) << "Code" << " " << setw(10) << "Name" << " " << setw(6) << "Price" << "" << setw(6) << "Sales" << "" << setw(10) << "Sub-Total" << "" << endl;
                    cout << " --------------------------------------------------------------------------------------------------" << endl;

                    qstate = mysql_query(conn, "SELECT * FROM meal ORDER BY Sales"); ///////display item
                    double grandtotal = 0;
                    res = mysql_store_result(conn);
                    while (row = mysql_fetch_row(res))
                    {
                        double subtotal = atof(row[2]) * atof(row[4]);
                        grandtotal += subtotal;
                        cout << "  " << setw(5) << row[0] << " " << setw(14) << row[1] << "" << setw(6) << row[2] << "" << setw(6) << row[4] << " " << setw(10) << setprecision(2) << fixed << subtotal << "" << endl;
                    }
                    cout << " -------------------------------------------------------------------------------------------------" << endl;
                    cout << "                                                                                                  " << endl;
                    cout << "                                                               TOTAL    " << setw(10) << grandtotal << " " << endl;
                    cout << " =================================================================================================" << endl;
                    cout << endl << " BACK...";
                    cin.ignore(1000, '\n');
                    goto report;
                }
                else if (admin_input == "4")
                {
                    //generate graph
                    int daloop = 0;
                    int fixrange = 0;
                    cout << endl;
                    cout << " Graph x = Sales, y = Meal ID" << endl << endl;
                    cout << "   Meal ID" << endl;
                    cout << "      ^" << endl;
                    qstate = mysql_query(conn, "SELECT * FROM meal ORDER BY Sales DESC"); ///////display item data
                    double grandtotal = 0;
                    res = mysql_store_result(conn);
                    while (row = mysql_fetch_row(res))
                    {
                        if (fixrange <= atof(row[4]))
                            fixrange = atof(row[4]);

                        cout << " " << row[0] << " | ";
                        daloop = atof(row[4]);
                        for (int i = 0; i < daloop; i++)
                        {
                            cout << "|";
                        }
                        cout << " (" << daloop << ")" << endl;
                    }
                    cout << "      |-";
                    for (int i = 0; i < fixrange; i++)
                        cout << "-";
                    cout << "------> Sales" << endl;
                    cout << "          (RESTAURANTS SALES)" << endl;
                    cout << endl << " # Continue..." << endl;
                    cin.ignore(1000, '\n');
                    goto report;
                }
                else if (admin_input == "0")
                {
                    //report back to admin
                    goto admin;
                }
                else
                {
                    //report ERROR
                    cout << endl << " INVALID OPTION TRY AGAIN...";
                    cin.ignore(1000, '\n');
                    goto report;
                }
            }
            else if (admin_input == "3")
            {
                //setting
            setting:
                system("CLS");

            }
            else if (admin_input == "0")
            {

                return main(); //back to main page
            }

            else
            {
                //admin error
                cout << endl << " INVALID OPTION TRY AGAIN......";
                cin.ignore(1000, '\n');
                goto admin;
            }

        }// first if

//******************************************************** customer page *****************************************************************

        else if (main_input == 2)

        {
            system("cls");

            cout << "=================================== MEAL TICKET MACHINE =============================" << endl;
            cout << "                                                                                     " << endl;
            cout << "                                ~ SIGNUP AND LOGIN PAGE ~                            " << endl;
            cout << "                                                                                     " << endl;
            cout << "                                                                                     " << endl;
            cout << "                                    1. CUSTOMER LOGIN                                " << endl;
            cout << "                                                                                     " << endl;
            cout << "                                    2. CUSTOMER SIGNU                                " << endl;
            cout << "                                                                                     " << endl;
            cout << "                                                                                     " << endl;
            cout << "                                                                                     " << endl;
            cout << "                                                                                     " << endl;
            cout << " ====================================================================================" << endl;
            cout << endl;
            cout << " ENTER YOUR OPTION : ";
            int cus_input;
            cin >> cus_input;
            cin.clear(); cin.ignore(1000, '\n');
            cout << endl;

            if (cus_input == 1)
            {
            customerLogin:

                system("cls");
                cout << "======================================== CUSTOMER LOGIN =============================================" << endl << endl;

                int ch;

                string customer_name, password;

                cout << "\t\t\t\t USERNAME: ";
                cin >> customer_name;
                cout << endl;
                cout << "\t\t\t\t PASSWORD: ";
                ch = getch();

                while (ch != 13)

                {
                    password.push_back(ch);
                    cout << '*';
                    ch = getch();
                }

                cout << endl;
                cout << endl;

                string login_query = "select * from customer where customer_name  = '" + customer_name + "' and password = '" + password + "' ";
                const char* qn = login_query.c_str();

                qstate = mysql_query(conn, qn);

                if (!qstate)
                {
                    res = mysql_store_result(conn);
                    if ((row = mysql_fetch_row(res)))
                    {
                        cout << "\n\n\nlogged in sucessfully" << endl;
                        Sleep(2000);
                        system("cls");
                        goto customer;
                    }
                    else
                    {
                        cout << "wrong customer_name or password" << endl;

                        system("pause");
                        main();
                    }
                }
                else
                {
                    cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
                }

            }

            else if (cus_input == 2)
            {

                system("CLS");
                int ch;
                string customer_name, password, phone_no, address, email;
                cout << endl;
                cout << " ================================  PLEASE REGISTER FIRST ============================ " << endl;
                cout << " " << endl;
                cout << " CUSTOMER_NAME  : ";
                getline(cin, customer_name);
                cout << endl;
                cout << " PASSWORD : ";


                ch = getch();

                while (ch != 13)

                {
                    password.push_back(ch);
                    cout << '*';
                    ch = getch();
                }


                //cin >> password; cin.clear(); cin.ignore(1000, '\n');
                cout << endl;
                cout << endl;
                cout << " PHONE_NO  : ";
                getline(cin, phone_no);
                cout << endl;
                cout << " ADDRESS  : ";
                getline(cin, address);
                cout << endl;
                cout << " EMAIL  : ";
                getline(cin, email);


                cout << endl;


                stringstream ss;
                ss << "INSERT INTO customer (customer_name, password, phone_no,address,email) values ('" << customer_name << "','" << password << "','" << phone_no << "','" << address << "','" << email << "')";
                string query = ss.str();
                const char* q = query.c_str();
                qstate = mysql_query(conn, q);
                if (qstate == 0)
                {
                    cout << " NEW CUSTOMER ADDED SUCCESSFUL..." << endl;
                    cin.ignore(1000, '\n');
                    //  goto customerLoginPage;
                    goto customerLogin;
                }
                else
                {
                    cout << "DATABASE ERROR X";
                }

            }


        customer:
            string id, name, price;
            system("CLS");
            cout << "                                   MEAL MENU                                          " << endl;
            cout << " -------------------------------------------------------------------------------------" << endl;
            cout << left << "  " << setw(5) << "Code" << " " << setw(16) << "Name" << " " << setw(5) << "Price" << endl;
            cout << " -------------------------------------------------------------------------------------" << endl;

            qstate = mysql_query(conn, "SELECT * FROM meal"); ///////display item
            if (!qstate)
            {
                res = mysql_store_result(conn);
                while (row = mysql_fetch_row(res))
                {
                    cout << left << "  " << setw(5) << row[0] << " " << setw(14) << row[1] << " " << setw(6) << row[2] << "" << endl;
                }
                cout << " ------------------------------------------------------------------------------------" << endl;
            }
            cout << endl;
            cout << " #_PLEASE ORDER YOUR MEAL                                    " << endl;
            cout << "                                                                                     " << endl;
            cout << "                                ORDER LIST                                           " << endl;
            cout << " ====================================================================================" << endl;
            cout << left << "  " << setw(5) << "Code" << " " << setw(16) << "Name" << " " << setw(5) << "Price" << endl;
            cout << " ------------------------------------------------------------------------------------" << endl;
            double total = 0;
            qstate = mysql_query(conn, "SELECT * FROM meal where Quantity != 0"); //////display order
            if (!qstate)
            {
                res = mysql_store_result(conn);
                while (row = mysql_fetch_row(res))
                {
                    int repeat = atof(row[3]);
                    for (int i = 0; i < repeat; i++)
                    {
                        cout << left << "  " << setw(5) << row[0] << "| " << setw(14) << row[1] << " " << setw(6) << row[2] << "|" << endl;
                        total += atof(row[2]);
                    }
                }
                cout << " ------------------------------------------------------------------------------------" << endl;
                cout << "                                                     \tTotal Price\t " << setprecision(2) << fixed << total << "\t " << endl;
                cout << " ====================================================================================" << endl;
            }
            cout << endl;

            int count = 0;
            string respond;
            string respond_code;
            string new_quantity;
            cout << "\nA. TO ADD A MEAL\nB. TO DELETE A MEAL\nC. PAYMENT\nD. EXIT " << endl;
            cout << "\n ^^ ENTER YOUR OPTION   [ (A)\t(B)\t(C)\t(D) ] : ";
            cin >> respond; cin.clear(); cin.ignore(1000, '\n');
            cout << endl;
            //////////////////////////////add order
            if (respond == "A" || respond == "a")
            {
                cout << " ^^ INSERT MEAL CODE TO ADD(+)INTO ORDER LIST " << endl;
                cout << "--------------------------------------------- " << endl;
                cout << " MEAL CODE : ";
                cin >> respond_code;
                cin.clear();
                cin.ignore(1000, '\n');
                string path = "SELECT * FROM meal where Meal_ID = " + respond_code; //search item
                const char* qri = path.c_str();
                qstate = mysql_query(conn, qri);
                if (qstate == 0)
                {
                    res = mysql_store_result(conn);
                    while (row = mysql_fetch_row(res))
                    {
                        int cal_quantity = atoi(row[3]) + 1;
                        stringstream ss;
                        ss << cal_quantity;
                        new_quantity = ss.str();
                        ///////// found quantity and +1 then update to database
                        count++;
                    }
                    if (count != 0)
                    {
                        stringstream ss;
                        ss << "UPDATE meal SET Quantity = '" << new_quantity << "' where Meal_ID = '" << respond_code << "' ";
                        string query = ss.str();
                        const char* q = query.c_str();
                        qstate = mysql_query(conn, q);
                        if (qstate == 0)
                        {
                            cout << endl;
                            cout << " # Meal Added";
                        }
                        else
                        {
                            cout << "DATABASE Error X...";
                        }
                    }
                    else
                    {
                        cout << endl;
                        cout << " WRONG CODE..!!! X";
                    }
                }
                else
                {
                    cout << endl;
                    cout << "INVALID CODE...";
                }
            }
            //////////////////////////////////////////////////delete orderS
            else if (respond == "B" || respond == "b")
            {
                cout << " ^^ INSERT MEAL CODE TO DELETE (-) FROM ORDER LIST " << endl;
                cout << "-------------------------------------------------- " << endl;
                cout << " MEAL CODE : ";
                cin >> respond_code;
                cin.clear();
                cin.ignore(1000, '\n');
                string path = "SELECT * FROM meal where Meal_ID = " + respond_code + " AND Quantity != 0"; //search item
                const char* qri = path.c_str();
                qstate = mysql_query(conn, qri);
                if (qstate == 0)
                {
                    res = mysql_store_result(conn);
                    while (row = mysql_fetch_row(res))
                    {
                        int cal_quantity = atoi(row[3]) - 1;
                        stringstream ss;
                        ss << cal_quantity;
                        new_quantity = ss.str();
                        count++;
                    }
                    if (count != 0)
                    {
                        stringstream ss;
                        ss << "UPDATE meal SET Quantity = '" << new_quantity << "' where Meal_ID = '" << respond_code << "' ";
                        string query = ss.str();
                        const char* q = query.c_str();
                        qstate = mysql_query(conn, q);
                        if (qstate == 0)
                        {
                            cout << endl;
                            cout << "MEAL DELETED";
                        }
                        else
                        {
                            cout << "DATABASE ERROR X...";
                        }
                    }
                    else
                    {
                        cout << endl;
                        cout << "WRONG CODE .... X";
                    }
                }
                else
                {
                    cout << endl;
                    cout << " INVALID CODE...";
                }
            }
            else if (respond == "C" || respond == "c")
            {
                if (total == 0.00)
                {
                    cout << "THE ORDER LIST IS EMPTY (0)... PLEASE ORDER";
                    cin.ignore(1000, '\n');
                    goto customer;
                }
                double cal_total = total;
                //payment checkout()
            repay:
                double payment;
                double change;
                cout << " PAYMENT REMAIN - RM " << cal_total << endl;
                cout << "-------------------- " << endl;
                cout << "   INSERT : RM ";
                cin >> payment; cin.clear(); cin.ignore(1000, '\n');
                change = payment - cal_total;
                cal_total = cal_total - payment;
                if (payment <= NULL)
                {
                    cout << endl << "SORRY, PAYMENT CANCELLED...";
                }
                else
                {
                    if (change < 0)
                    {
                        cout << endl;
                        goto repay;
                    }
                    else if (change >= 0)
                    {

                        cout << endl << " # Thank you! Here is your change RM " << change << endl << endl << " # Printing Ticket(s)";
                        cout << endl << " Continue...";
                        cin.ignore(1000, '\n');
                        ////////// display data in ticket form, customer cash and change ticket id then database quantity transfer to sales;
                        //ref number
                        int ref_id, date;

                        string rstaurant;

                        double data_amount;
                        qstate = mysql_query(conn, "SELECT * FROM invoice_order"); //////display order
                        res = mysql_store_result(conn);
                        while (row = mysql_fetch_row(res))
                        {
                            rstaurant = atof(row[0]);
                            ref_id = atof(row[1]);
                            data_amount = atof(row[2]);
                            date = atof(row[3]);
                        }
                        ref_id++;
                        data_amount = data_amount + total; //
                        stringstream sss;
                        stringstream ssss;
                        sss << ref_id;
                        ssss << data_amount;
                        stringstream ss;
                        ss << "UPDATE invoice_order SET Ref_Number = '" << sss.str() << "' , Amount = '" << ssss.str() << "' ";
                        string query = ss.str();
                        const char* q = query.c_str();
                        qstate = mysql_query(conn, q);


                        system("CLS");

                        cout << "                             ~ INVOICE FOR CUSTOMER ~                                " << endl;
                        cout << " ------------------------------------------------------------------------------------" << endl;
                        cout << "                                   CASH RECEIPT                                      " << endl;
                        cout << "                                                                                     " << endl;
                        cout << "              Name of Restaurant : " << rstaurant << "   MEAL TICKET MACHINE         " << endl;
                        cout << "                                                                                     " << endl;
                        cout << "                                                                                     " << endl;
                        cout << "    Inv No : " << ref_id << "                               Date : " << date << "    " << endl;
                        cout << "------------------------------------------------------------------------------------" << endl;
                        cout << "                                                                                     " << endl;
                        cout << "                                                                                     " << endl;


                        /////database print
                        qstate = mysql_query(conn, "SELECT * FROM meal where Quantity != 0"); //////display order
                        res = mysql_store_result(conn);
                        while (row = mysql_fetch_row(res))
                        {
                            int repeat = atof(row[3]);
                            for (int i = 0; i < repeat; i++)
                            {
                                cout << left << "  " << row[0] << " " << setw(14) << row[1] << " RM " << setw(6) << row[2] << "  " << endl;
                            }
                        }
                        cout << "                                                                                              " << endl;
                        cout << "                                                        Total RM " << setw(6) << total << "   " << endl;
                        cout << "                                                        Cash RM " << setw(6) << total + change << "   " << endl;
                        cout << "                                                        Change RM " << setw(6) << change << "   " << endl;
                        cout << "                                                                                              " << endl;
                        cout << "------------------------------------------------------------------------------------" << endl;
                        cout << "                             Thank you please come again                            " << endl;
                        cout << endl << endl << endl << endl << endl << endl;
                        qstate = mysql_query(conn, "SELECT * FROM meal where Quantity != 0");
                        res = mysql_store_result(conn);
                        while (row = mysql_fetch_row(res))
                        {
                            int repeat = atof(row[3]);
                            for (int i = 0; i < repeat; i++)
                            {
                                cout << "                                ~ INVOICE FOR KITCHEN ~                              " << endl;
                                cout << " ------------------------------------------------------------------------------------" << endl;
                                cout << "  Inv No : " << ref_id << "                           Date : " << date << "          " << endl;
                                cout << " ------------------------------------------------------------------------------------" << endl;
                                cout << "                                                                                     " << endl;
                                cout << "                                                                                     " << endl;
                                cout << "    " << row[0] << " " << setw(22) << row[1] << " " << endl;
                                cout << "                                                                                     " << endl;
                                cout << " ------------------------------------------------------------------------------------" << endl;
                                cout << endl;
                            }
                        }

                        /////clear database
                        int i = 0;
                        int quantity1;
                        int quantity2;
                        int quantity3;
                        string id[20] = {};
                        string sales[20] = {};
                        qstate = mysql_query(conn, "SELECT * FROM meal where Quantity != 0");
                        res = mysql_store_result(conn);
                        while (row = mysql_fetch_row(res))
                        {
                            quantity1 = atof(row[3]);
                            quantity2 = atof(row[4]);
                            quantity3 = quantity1 + quantity2;
                            stringstream ss;
                            ss << quantity3;
                            sales[i] = ss.str();
                            id[i] = row[0];
                            i++;
                        }
                        //
                        int arraysize = *(&id + 1) - id;
                        for (int i = 0; i < arraysize; i++)
                        {
                            stringstream ss;
                            ss << "UPDATE meal SET Quantity = 0,Sales = '" << sales[i] << "' where Meal_ID = '" << id[i] << "' ";
                            string query = ss.str();
                            const char* q = query.c_str();
                            qstate = mysql_query(conn, q);
                        }
                        cout << " # Enter again to navigate back to Main Menu";
                        cin.ignore(1000, '\n');
                        return main();
                    }
                }
            }
            else if (respond == "D" || respond == "d")
            {
                return main();
            }
            else
            {
                cout << " # Invalid respond...";
            }

            cout << endl;
            cout << " Continue...";
            cin.ignore(1000, '\n');
            goto customer;
        }
        else
        {
            cout << "Invalid Choice! Please try again...";
            cin.ignore(1000, '\n');
            return main();
        }



    }//end if


    else
    {
        cout << "Connection Fail";
    }




    return 0;
}


