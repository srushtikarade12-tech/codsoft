#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

class Calculator
{
private:
    vector<string> history;

public:
    void menu()
    {
        cout << "\n========================================\n";
        cout << "        SIMPLE CALCULATOR\n";
        cout << "========================================\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Modulus\n";
        cout << "6. Power\n";
        cout << "7. Square Root\n";
        cout << "8. Percentage\n";
        cout << "9. View History\n";
        cout << "10. Exit\n";
        cout << "Enter Choice : ";
    }

    void addHistory(string s)
    {
        history.push_back(s);
    }

    void addition()
    {
        double a,b;
        cout<<"Enter First Number : ";
        cin>>a;
        cout<<"Enter Second Number : ";
        cin>>b;

        double ans=a+b;

        cout<<"\nResult = "<<ans<<endl;

        addHistory(to_string(a)+" + "+to_string(b)+" = "+to_string(ans));
    }

    void subtraction()
    {
        double a,b;
        cout<<"Enter First Number : ";
        cin>>a;
        cout<<"Enter Second Number : ";
        cin>>b;

        double ans=a-b;

        cout<<"\nResult = "<<ans<<endl;

        addHistory(to_string(a)+" - "+to_string(b)+" = "+to_string(ans));
    }

    void multiplication()
    {
        double a,b;
        cout<<"Enter First Number : ";
        cin>>a;
        cout<<"Enter Second Number : ";
        cin>>b;

        double ans=a*b;

        cout<<"\nResult = "<<ans<<endl;

        addHistory(to_string(a)+" * "+to_string(b)+" = "+to_string(ans));
    }

    void division()
    {
        double a,b;
        cout<<"Enter Dividend : ";
        cin>>a;
        cout<<"Enter Divisor : ";
        cin>>b;

        if(b==0)
        {
            cout<<"Division by zero is not allowed.\n";
            return;
        }

        double ans=a/b;

        cout<<"\nResult = "<<fixed<<setprecision(2)<<ans<<endl;

        addHistory(to_string(a)+" / "+to_string(b)+" = "+to_string(ans));
    }

    void modulus()
    {
        int a,b;

        cout<<"Enter First Integer : ";
        cin>>a;

        cout<<"Enter Second Integer : ";
        cin>>b;

        if(b==0)
        {
            cout<<"Division by zero is not allowed.\n";
            return;
        }

        int ans=a%b;

        cout<<"\nResult = "<<ans<<endl;

        addHistory(to_string(a)+" % "+to_string(b)+" = "+to_string(ans));
    }

    void power()
    {
        double base,exp;

        cout<<"Enter Base : ";
        cin>>base;

        cout<<"Enter Exponent : ";
        cin>>exp;

        double ans=pow(base,exp);

        cout<<"\nResult = "<<ans<<endl;

        addHistory(to_string(base)+" ^ "+to_string(exp)+" = "+to_string(ans));
    }

    void squareRoot()
    {
        double num;

        cout<<"Enter Number : ";
        cin>>num;

        if(num<0)
        {
            cout<<"Square Root of negative number not possible.\n";
            return;
        }

        double ans=sqrt(num);

        cout<<"\nSquare Root = "<<ans<<endl;

        addHistory("sqrt("+to_string(num)+") = "+to_string(ans));
    }

    void percentage()
    {
        double total,obtained;

        cout<<"Enter Total Marks : ";
        cin>>total;

        cout<<"Enter Obtained Marks : ";
        cin>>obtained;

        if(total==0)
        {
            cout<<"Total Marks cannot be zero.\n";
            return;
        }

        double ans=(obtained/total)*100;

        cout<<"\nPercentage = "<<fixed<<setprecision(2)<<ans<<"%"<<endl;

        addHistory("Percentage = "+to_string(ans)+"%");
    }

    void showHistory()
    {
        cout<<"\n========== HISTORY ==========\n";

        if(history.empty())
        {
            cout<<"No Calculations Yet.\n";
            return;
        }

        for(int i=0;i<history.size();i++)
        {
            cout<<i+1<<". "<<history[i]<<endl;
        }
    }
};

int main()
{
    Calculator calc;

    int choice;

    while(true)
    {
        calc.menu();

        cin>>choice;

        switch(choice)
        {
        case 1:
            calc.addition();
            break;

        case 2:
            calc.subtraction();
            break;

        case 3:
            calc.multiplication();
            break;

        case 4:
            calc.division();
            break;

        case 5:
            calc.modulus();
            break;

        case 6:
            calc.power();
            break;

        case 7:
            calc.squareRoot();
            break;

        case 8:
            calc.percentage();
            break;

        case 9:
            calc.showHistory();
            break;

        case 10:
            cout<<"\nThank You for Using Calculator.\n";
            return 0;

        default:
            cout<<"\nInvalid Choice.\n";
        }
    }

    return 0;
}