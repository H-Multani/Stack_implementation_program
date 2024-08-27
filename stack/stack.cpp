#include <iostream>
#include<iomanip>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

// add element
void stack_push(int size_of_stack, int &statvar, int *a)
{                                    // or simply a[] bhi likh sakte hai apan instead of *a, cant give address of a(like statvar) bcoz a array hai ek, multiple address hai toh array ka reference variable nahi le sakte (array me multiple elements, reference var ek value ka hota na) so we have to use pointer,
    if (statvar < size_of_stack - 1) // -1 isliye bcoz normal me statvar==size_of_stack vaali condn me bhi element recieve ho rahe the
    {
        cout << "enter new element" << endl;
        int n;
        cin >> n;
        statvar++;
        // cout << "pushing element "<<n << endl;
        // cout << "size of satck is " << size_of_stack << endl;// ye apne help ke liya hai, samajhne ke liya
        // cout << "status variable is " << statvar << endl;// ye apne help ke liya hai, samajhne ke liya
        a[statvar] = n;
        cout << "element "<< a[statvar]<<" pushed " << endl;
    }
    else
    {
        cout << "stack overflow" << endl;
    }
}

// pop element 
void stack_pop(int &statvar, int *a)
{
    if (statvar != -1)
    {
        cout << "element popped "<<a[statvar] << endl;
        statvar--;
    }
    else
        cout << "stack underflow" << endl;
}






int max_size(int *a, int &statvar)
{
    // iss approach me hum baar baar length nikaal kar compare kar rahe hain, toh complexity badh rahi h
    // int temp1=abs(a[0]);
    // int max = log10(temp1) + 1; // pehle element ki length max maan li
    // for (int i = 0; i < statvar + 1; i++)
    // {
    //     if (a[i] >= 0)
    //     {
    //         // length of a[i] is log10(a[i])+1
    //         if (log10(a[i]) + 1 > max)
    //         {
    //             max = log10(a[i]) + 1; // size of the number
    //         }
    //     }
    //     else 
    //     {
    //         int temp=abs(a[i]);
    //         if (log10(temp) + 1 > max)
    //         {
    //             max = log10(a[i]) + 1; // normal size of the number
    //             max++;                 // for the - sign, ek jagah zyada lagegi
    //         }
    //         else ;
    //     }
    // }
    // return max;




    // alternate way to do same thing, in case the bits library doesnt work
    // int min = a[0], max = a[0], minlen, maxlen;
    // for(int i = 0; i<statvar+1; i++){
    //     if(a[i]<min) min = a[i];
    //     if(a[i]>max) max = a[i];
    // }

    // if(min<0){
    //     min=abs(min);// positive bana diya
    //     minlen=log10(min)+2;
    //     if (minlen>maxlen) return minlen;
    // }
    // return maxlen;


    int min=*min_element(a,a+statvar),maxlen;
    int max=*max_element(a,a+statvar),minlen;
    maxlen=log10(max)+1;
    if (min>=0)
    {
        return maxlen;
    }
    else
    {
        min=abs(min);// positive bana diya
        minlen=log10(min)+2;
        if (minlen>maxlen)
        {
            return minlen;
        }
        else return maxlen;
        
    }
}





// prints the stack, ready to use
// void print_all(int &statvar, int *a)
// {
//     for (int i = statvar; i >= 0; i--)
//     {

//         cout << a[i] << endl;
//     }
// }




// prints the stack but in a box, looks better
int box(int size, int &length_of_biggest_element,int *a, int &statvar){
    for (int i = 0; i < 3*(length_of_biggest_element+3)-4; i++)// ye 3*(length_of_biggest_element+3)-4 , pura trial end error se aaya hai
    {  
        cout<<"-";   
    }
    cout<<endl;
    cout<<setw(2)<<"|"<<setw(length_of_biggest_element*2)<<"Stack"<<setw(length_of_biggest_element+1)<<"|"; 
    cout<<endl;
    for (int i = 0; i < 3*(length_of_biggest_element+3)-4; i++)
    {  
        cout<<"-";   
    }
    cout<<endl;



    // sued to check if box works
    // for (int i = 0; i < length_of_biggest_element+3; i++)
    // {  
    //     cout<<setw(2)<<"|"<<setw(length_of_biggest_element*2)<<4597<<setw(length_of_biggest_element+1)<<"|";  
    //     cout<<endl;
    // }



    for (int i = size-1; i >= 0; i--)
    // =0 because aakhri element 0 index par hoga,size-1 cos for 10 size(for eg) i goes 9.8.7....2.1.0(10 iterations) 
    {
        if (i>statvar)// 4>1, 3>1 ,2>1 ,1==1
        {
            cout<<setw(2)<<"|"<<setw(length_of_biggest_element*2)<<""<<setw(length_of_biggest_element+1)<<"|";
        }
        else cout<<setw(2)<<"|"<<setw(length_of_biggest_element*2)<<a[i]<<setw(length_of_biggest_element+1)<<"|";
        cout<<endl;
    }
    
    for (int i = 0; i <  3*(length_of_biggest_element+3)-4; i++)
    {  
        cout<<"-";   
    }
    cout<<endl;
    
}




int main()
{
    int a[100];
    int stat_var = -1, choice;
    int stack_size,biggest_element_size;
    label_here:// this is the label, for that stack size input
    cout << "enter size of stack ";
    cin >> stack_size;
    if (stack_size==0 || stack_size<0)// galat size input hoga toh vapas se stacksize lega 
    {
        cout<<"wrong input, please enter again "<<endl;
        goto label_here;// goes back to label to retake value
    }
    else if(stack_size>=100){
        cout<<"stack size greater than defined, please enter again"<<endl;
        goto label_here;
    }
    help_label:// this is label for help window, when 0 pressed
    cout<<"--------------------------------------------"<<endl;
    cout <<"   "<< "press 0 for help " << endl;
    cout <<"   "<< "press 1 to add elements" << endl;
    cout <<"   "<< "press 2 to delete elements" << endl;
    cout <<"   "<< "press 3 to show elements" << endl;
    cout <<"   "<< "press 4 to get size of biggest element" << endl;
    cout <<"   "<< "press 5 to exit" << endl;
    cout<<"--------------------------------------------"<<endl;
    do
    {
        // cout << "status variable is " << stat_var << endl;
        cout<<"--------------------------------------------"<<endl;
        cout << "      enter choice  ";
        cin >> choice;
        cout<<endl<<"--------------------------------------------"<<endl;
        switch (choice)
        {
        case 0:
            goto help_label;
            break;
        
        case 1:
            cout<<"------------------------------------------------"<<endl;
            cout<<"       ACTION 1 PERFORMING "<<endl;
            cout<<"------------------------------------------------"<<endl;
            if (stat_var == -1)
            {
                cout << "stack empty" << endl;
            }
            stack_push(stack_size, stat_var, a);
            break;
        case 2:
            cout<<"------------------------------------------------"<<endl;
            cout<<"       ACTION 2 PERFORMING "<<endl;
            cout<<"------------------------------------------------"<<endl;
            if (stat_var == -1)
            {
                cout << "stack empty " << endl;
            }
            stack_pop(stat_var,a);

            break;
        case 3:
            cout<<"------------------------------------------------"<<endl;
            cout<<"       ACTION 3 PERFORMING "<<endl;
            cout<<"------------------------------------------------"<<endl;
            // print_all(stat_var, a);// sue this to print the stack normally, not all box and stuff
            biggest_element_size=max_size(a,stat_var);
            box(stack_size,biggest_element_size,a,stat_var);
            break;
        case 4:
            cout<<"------------------------------------------------"<<endl;
            cout<<"       ACTION 4 PERFORMING "<<endl;
            cout<<"------------------------------------------------"<<endl;
            cout<<"size of biggest element is "<<max_size(a,stat_var)<<endl;
        default:
            break;
        }

    } while (choice != 5);
}
// stack_push(4, stat_var++, a); , stackvar++ se ye problem ho rahi thi ki even if stack overflowed the status variable value increased, toh apan ne simply status_var ka address send kar diya funcn me , funcn ne address leke usko ek formal paramter me save kar diya(statvar), phir iss address ke help se jab apan ne statvar ko increse kiya toh original stat_var increse hoga
// basically hamne stat_var ka ek reference variable banaya(statvar) , ye reference variable (statvar) has the same address as the original variable(stat_var), toh increasing statvar increases the value at that address, thereby increasing stat_var, stat_var ka address statvar me daal diya  google:call by reference in cpp , ya fir dono ka address print kara ke dekh lo same hai (check kar chuka mai)
// listen to the voice note of today

// so everythig works noice, only thing remaining is we use the box do display the ouptut, update: this also works but another problem
// element ka max element length  waala function(max_length) sahi se kaam nahi kar raha hai, sahi karna hai isko