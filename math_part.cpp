//
//  main.cpp
//  math_asvab
//
//  Created by Daniel Aleman on 7/18/17.
//  Copyright © 2017 Josue Aleman. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <iomanip>
#include <vector>
#include <math.h>
#include <string>
#include <limits>

#define PI 3
using namespace std;


void dividingQuestion();
void areaQuestion();
void exponentQuestion();
void percentageQuestion();
void rateQuestion();
void foilQuestion(vector<int> &);

char generateAnswerDouble(double, bool,string,bool);
char generateAnswerInt(int,bool, string);
char generateAnswerMoney(double,bool,string,bool);

char validateQuestion();
void checkAnswers(char, char);

int randomInt(int, int);
vector<int> foilEval(int,int,int,int);//a,b,c,d passed ex.(a+b)(c+d)



int main()
{
    srand(time(NULL));
    //char continueKey;
    cout<<"ASVAB PREP  v.1.0"<<endl;
    cout<<"by: Josue Aleman"<<endl<<endl<<endl;
    cout<<"Press [ENTER] to continue...";
    //cin>>continueKey;
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    bool yesno=true;
    char response;
    while(yesno){
    
   // cout << string(50, '\n');
        cout<<endl<<endl;
        rateQuestion();
        cout<<endl;
//    dividingQuestion();
//    cout<<endl;
//    areaQuestion();
//    cout<<endl;
//    exponentQuestion();
//    cout<<endl;
//    percentageQuestion();
//    cout<<endl;
//    
        cout<<"Continue? (y/n):";
        cin>>response;
        while(!cin || !(response=='y'||response=='Y'||response=='n'||response=='N'))
        {
            cout<<"Error! Please select (y/n): ";
            cin.clear();
            cin.ignore();
            cin>>response;
        }
        if(response=='n'||response=='N'){yesno=false;}
        else if (response=='y'||response=='Y'){yesno=true;}
        

        
    }
        return 0;
}
char generateAnswerDouble(double answer, bool far, string addon, bool round_num)
{
    srand(time(NULL));
    int answerIndex=randomInt(0, 3);//gives index between 0-3
    char rightanswer=96;
    double val1,val2,val3,val4;
    if(far){val1=randomInt(1, 20);val2=randomInt(1, 20);val3=randomInt(21, 70);val4=randomInt(21, 50);}
    else{val1=randomInt(1, 3);val2=randomInt(1, 3);val3=randomInt(5, 15);val4=randomInt(2, 5);}
    val1=val1*answer+1;val2=answer/val2+2;val3=answer+val3+1;val4=answer*val4/val1+val3+1;
    vector<double> values={val1,val2,val3,val4};
    vector<double> answers={};
    for(int i=0; i<4;i++)
    {
        if(i==answerIndex)
        {
            answers.push_back(answer);
            rightanswer=rightanswer+i+1;
            
        }
        else
        {
            answers.push_back(values[i]);
        }
    }
    if (round_num)
    {
        
        cout<<"a)"<<round(answers[0])<<addon<<endl;
        cout<<"b)"<<round(answers[1])<<addon<<endl;
        cout<<"c)"<<round(answers[2])<<addon<<endl;
        cout<<"d)"<<round(answers[3])<<addon<<endl;
    
    }
    else{
    cout<<fixed<<setprecision(2);
    cout<<"a)"<<answers[0]<<addon<<endl;
    cout<<"b)"<<answers[1]<<addon<<endl;
    cout<<"c)"<<answers[2]<<addon<<endl;
    cout<<"d)"<<answers[3]<<addon<<endl;
    }
    return rightanswer;
}
char generateAnswerInt(int answer, bool far, string addon)
{
    srand(time(NULL));
    int answerIndex=randomInt(0, 3);//gives index between 0-3
    char rightanswer=96;
    int val1,val2,val3,val4;
    if(far){val1=randomInt(1, 20);val2=randomInt(1, 20);val3=randomInt(21, 70);val4=randomInt(21, 50);}
    else{val1=randomInt(1, 3);val2=randomInt(1, 3);val3=randomInt(5, 15);val4=randomInt(2, 5);}
    val1=val1*answer+1;val2=answer/val2+2;val3=answer+val3+1;val4=answer*val4/val1+val3+1;
    vector<int> values={val1,val2,val3,val4};
    vector<int> answers={};
    for(int i=0; i<4;i++)
    {
        if(i==answerIndex)
        {
            answers.push_back(answer);
            rightanswer=rightanswer+i+1;
            
        }
        else
        {
            answers.push_back(values[i]);
        }
    }
    cout<<fixed<<setprecision(2);
    cout<<"a)"<<answers[0]<<addon<<endl;
    cout<<"b)"<<answers[1]<<addon<<endl;
    cout<<"c)"<<answers[2]<<addon<<endl;
    cout<<"d)"<<answers[3]<<addon<<endl;
    return rightanswer;
}

char generateAnswerMoney(double answer, bool far, string addon, bool round_num)
{
    srand(time(NULL));
    int answerIndex=randomInt(0, 3);//gives index between 0-3
    char rightanswer=96;
    double val1,val2,val3,val4;
    if(far){val1=randomInt(1, 20);val2=randomInt(1, 20);val3=randomInt(21, 70);val4=randomInt(21, 50);}
    else{val1=randomInt(1, 3);val2=randomInt(1, 3);val3=randomInt(5, 15);val4=randomInt(2, 5);}
    val1=val1*answer+1;val2=answer/val2+2;val3=answer+val3+1;val4=answer*val4/val1+val3+1;
    vector<double> values={val1,val2,val3,val4};
    vector<double> answers={};
    for(int i=0; i<4;i++)
    {
        if(i==answerIndex)
        {
            answers.push_back(answer);
            rightanswer=rightanswer+i+1;
            
        }
        else
        {
            answers.push_back(values[i]);
        }
    }
    if (round_num)
    {
        cout<<fixed<<setprecision(2);
        cout<<"a) $"<<round(answers[0])<<addon<<endl;
        cout<<"b) $"<<round(answers[1])<<addon<<endl;
        cout<<"c) $"<<round(answers[2])<<addon<<endl;
        cout<<"d) $"<<round(answers[3])<<addon<<endl;
        
    }
    else{
        cout<<fixed<<setprecision(2);
        cout<<"a) $"<<answers[0]<<addon<<endl;
        cout<<"b) $"<<answers[1]<<addon<<endl;
        cout<<"c) $"<<answers[2]<<addon<<endl;
        cout<<"d) $"<<answers[3]<<addon<<endl;
    }
    return rightanswer;
}


char validateQuestion()
{
    char selection;
    cout<<"Please select one of the following: ";
    cin>>selection;
    while(!cin || !(selection=='a'||selection=='b'||selection=='c'||selection=='d'))
    {
        cout<<"Error! Please select from a-d: ";
        cin.clear();
        cin.ignore();
        cin>>selection;
    }
    return selection;
}
void checkAnswers(char user_choice, char right_answer)
{
    if(user_choice==right_answer)
    {
        cout<<"Correct!"<<endl;
    }
    else
    {
        cout<<"Incorrect, the right answer is "<<right_answer<<")"<<endl;
    }
}

void dividingQuestion()
{
    srand(time(NULL));
    int selection=randomInt(0, 3);
    double num1, num2,answer=0.0;
    char user_choice;
    char right_answer;
    
    switch(selection)
    {
        case 0://whole num divided by a whole num
            num1=randomInt(5, 100);
            //num1=rand()%95+5;//number between 5-100
            if(num1>=50){num2=randomInt(5, 49);}
            else{num2=randomInt(50, 100);}
            cout<<"What is "<<num1<<"/"<<num2<<"?"<<endl;
            answer=num1/num2;
            right_answer=generateAnswerDouble(answer, true,"",false);
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;
            
        case 1://whole num divided by a fraction
            num1=randomInt(5, 100);
            //num2=rand()%9+1;
            //cout<<"num2:"<<num2;
            if(num1>=50){
                num2=randomInt(1, 9);num2=num2/100;}//number between 1-9
            else{num2=randomInt(1, 9);num2=num2/10;}
            cout<<"What is "<<num1<<"/"<<fixed<<setprecision(2)<<num2<<"?"<<endl;
            answer=num1/num2;
            right_answer=generateAnswerDouble(answer, false,"",false);
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;
            
        case 2://fraction divided by a fraction
            num1=randomInt(10, 150); //number between 10-150
            num1=num1/100;
            num2=randomInt(1, 40);//number between 1-40
            num2=num2/100;
            cout<<"What is "<<fixed<<setprecision(2)<<num1<<"/"<<num2<<"?"<<endl;
            answer=num1/num2;
            right_answer=generateAnswerDouble(answer, false,"",false);
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;
    
    }
    
}

void areaQuestion()
{
     srand(time(NULL));
    int selection=randomInt(0, 4);
    double radius,length, width, height,area=0.0;
    char user_choice,
         right_answer;
    switch(selection)
    {
        case 0://area of a rectangle
            length=randomInt(5, 75);
            width=randomInt(5, 75);
            area=length*width;
            cout<<"The area of a RECTANGLE with length "<<fixed<<setprecision(0)<<length;
            cout<<" and width "<<width<<" is:"<<endl;
            right_answer=generateAnswerInt(int(area), true,"");
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;
        case 1://area of a square
            length=randomInt(5, 85);
            area=length*length;
            cout<<"The area of a SQUARE with length "<<fixed<<setprecision(0)<<length<<" is:"<<endl;
            right_answer=generateAnswerInt(int(area), true,"");
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;
        case 2://area of a triangle
            width=randomInt(10, 110);
            height=randomInt(20, 140);
            area=(width*height)/2.0;
            cout<<"The area of a TRIANGLE with height "<<fixed<<setprecision(0)<<height;
            cout<<" and width "<<width<<" is:"<<endl;
            right_answer=generateAnswerDouble(area, true,"",false);
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;
        case 3://area of a circle
            radius=randomInt(5, 45);
            area=PI*radius*radius;
            cout<<"The area of a CIRCLE with radius "<<fixed<<setprecision(0)<<radius<<" is:"<<endl;
            right_answer=generateAnswerInt(int(area), true,"");
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;
            
    
    }

}
void exponentQuestion()
{
    srand(time(NULL));
    int selection=randomInt(0, 3);
    int baseNum1=randomInt(2, 5),
            baseNum2=randomInt(3, 6),
            exponent1=randomInt(2, 4),
    exponent2=randomInt(1, 3),
    answer;
    char user_choice,
         right_answer;
    
    switch(selection)
    {
            //pow(x,y)=x^y
        case 0://simple exponent question (ie 4^2=)
            answer=pow(baseNum1,exponent1);
            cout<<"The value of "<<fixed<<setprecision(0)<<baseNum1<<"^"<<exponent1<<" is:"<<endl;
            right_answer=generateAnswerInt(answer, false,"");
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;
        case 1://sum of two nums with exponents (ie 3^2+2^3)
            answer=(pow(baseNum1,exponent1)+pow(baseNum2,exponent2));
            cout<<fixed<<setprecision(0);
            cout<<baseNum1<<"^"<<exponent1<<"+"<<baseNum2<<"^"<<exponent2<<"="<<endl;
            right_answer=generateAnswerInt(answer, false,"");
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;
        case 2://solving for an exponent (ie 2^x*2^3=2^8)
            double exponent3=randomInt(15, 35);
            answer=exponent3-exponent1;
            cout<<fixed<<setprecision(0);
            cout<<"Solve for x in: "<<baseNum1<<"^"<<exponent1;
            cout<<"*"<<baseNum1<<"^x ="<<baseNum1<<"^"<<exponent3<<endl;
            right_answer=generateAnswerInt(answer, false,"");
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;
            
    }
}
void percentageQuestion()
{
    srand(time(NULL));
    int selection=randomInt(0, 2);
    //int selection=1;
    double num1, num2,answer=0.0;
    char user_choice;
    char right_answer;
    
    switch(selection)
    {
        case 0:{//What is _num1_% of _num2_?
            double percent_num=double(randomInt(1, 98)),
            num_val=double(randomInt(50, 600));
            cout<<fixed<<setprecision(0);
            cout<<"What is "<<percent_num<<"% of "<<num_val<<"?"<<endl;
            answer=(percent_num/100)*num_val;
            right_answer=generateAnswerDouble(answer, false,"",false);
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;}
            
        case 1:{//If the total is __ before taxes and ___ after taxes, the tax rate is?
            double before_tax=double(randomInt(80, 400)),
                    after_tax=0.0,
                    tax_rate=double(randomInt(5, 25)); //keeping tax rate bw 5-25%
            answer=tax_rate;
            tax_rate/=100.0;
            after_tax=(before_tax*tax_rate)+before_tax;
            cout<<fixed<<setprecision(2);
            cout<<"If the total is $"<<before_tax<<" before taxes and $"<<after_tax<<" after taxes, the tax rate is?"<<endl;
            right_answer=generateAnswerDouble(answer, false,"%",false);
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;}
            
        }

}

void rateQuestion()
{
    srand(time(NULL));
    double rate, numerator, denominator, answer;
    char user_choice;
    char right_answer;
    
    int selection=3;
    //int selection=randomInt(0, 4);
    
    switch (selection)
    {
        case 0:{//soldier can run ____ miles in ___ time What is the average pace? (mins/mile)
            numerator=double(randomInt(20, 35));
            denominator=double(randomInt(3, 6));
            rate=numerator/denominator;
            cout<<"A soldier can run "<<denominator<<" miles in "<<numerator<<" minutes."<<endl;
            cout<<"What is the average pace of the soldier? (mins/mile)"<<endl;
            answer=rate;
            right_answer=generateAnswerDouble(answer, false, " mins/mile",false);
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;
        }
        case 1:{//a cook can bake ___ cakes in ___ days How many can he bake in __ days?
            numerator=double(randomInt(20, 50));
            denominator=double(randomInt(7, 15));
            double days=double(randomInt(18, 35));
            rate=numerator/denominator;
            cout<<"A cook can bake "<<numerator<<" cakes in "<<denominator<<" days."<<endl;
            cout<<"How many cakes can they bake in "<<days<<" days?"<<endl;
            cout<<"(Round answer to nearest whole num)"<<endl;
            answer=rate*days;
            right_answer=generateAnswerDouble(answer, false, " cakes",true);
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;
        }
        case 2:{//____ weapons cost ___ How much does ___ rifles cost?
            numerator=double(randomInt(600, 2500));
            denominator=double(randomInt(5, 30));
            double weapons=double(randomInt(33, 120));
            rate=numerator/denominator;
            cout<<denominator<<" weapons cost $"<<fixed<<setprecision(2)<<numerator<<"."<<endl;
            cout<<"How much do "<<fixed<<setprecision(0)<<weapons<<" weapons cost?"<<endl;
            answer=rate*weapons;
            right_answer=generateAnswerMoney(answer, false, "", false);
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;
        }
        case 3:{//A vehicle's tank is full and drives ___ miles. It takes ____ to fill the tank. What is the mpg (miles per gallon) of the vehicle?
            numerator=double(randomInt(100, 350));
            denominator=double(randomInt(10, 20));
            rate=numerator/denominator;
            answer=rate;
            cout<<"A vehicle's tank is full and drives "<<numerator<<" miles."<<endl;
            cout<<"It takes "<<denominator<<" gallons  to fill the tank again."<<endl;
            cout<<"What is the MPG (miles per gallon) of the vehicle?"<<endl;
            right_answer=generateAnswerDouble(answer, false, " mpg", false);
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;
        }
    }
    
}

char generateFoilAnswers(vector<int>& foilResult)
{char rightanswer=96;
    int answerIndex=randomInt(0, 3);
    bool allPostiveNums=true;
    for (int i=0;i<sizeof(foilResult);i++)
    {
        if(foilResult[i]<0){allPostiveNums=false;}
    }
    int num1,num2,num3;
    
    return rightanswer;
}

void foilQuestion()
{
    srand(time(NULL));

    int a=1, b=randomInt(1, 9),c=1,d=randomInt(1, 9);
    //int selection=randomInt(0, 3);
    vector<int> foilResult={};
    int selection=0;
    switch(selection)
    {
        case 0://(a+b)(c+d)
            foilResult=foilEval(a, b, c, d);
            cout<<"(x+"<<b<<")(x+"<<d<<") :"<<endl;
            break;
        case 1://(a+b)(c-d)
            d=d*(-1);
            foilResult=foilEval(a, b, c, d);
            cout<<"(x+"<<b<<")(x"<<d<<") :"<<endl;
            break;
        case 2://(a-b)(c-d)
            b=b*(-1);
            d=d*(-1);
            foilResult=foilEval(a, b, c, d);
            cout<<"(x"<<b<<")(x"<<d<<") :"<<endl;
            break;
            
    }
    
}
vector<int> foilEval(int a, int b, int c, int d)
{
    vector<int> foilResult={};
    
    foilResult.push_back((a*c));
    foilResult.push_back(((a*d)+(b*c)));
    foilResult.push_back((b*d));

    return foilResult;
}

int randomInt(int start, int end)
{
   
    int randnum;
    if(start==0)
    {
        randnum=rand()%end;
    }
    else if(start==1)
    {
        randnum=rand()%end+start;
    }
    else
    {
        randnum=rand()%(end-start)+start;
    }
    
    return randnum;
}

