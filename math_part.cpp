//
//  main.cpp
//  math_asvab
//
//  Created by Daniel Aleman on 7/18/17.
//  Copyright © 2017 Josue Aleman. All rights reserved.
//

#include <iostream>
#include "shapes.h"
#include <time.h>
#include <iomanip>
#include <vector>
#include <math.h>

#define PI 3
using namespace std;


void dividingQuestion();
void areaQuestion();
void exponentQuestion();
void foilQuestion();

char generateAnswerDouble(double, bool);
char generateAnswerInt(int,bool);
char validateQuestion();
void checkAnswers(char, char);

int randomInt(int, int);
vector<int> foilEval(int,int,int,int);//a,b,c,d passed ex.(a+b)(c+d)



int main()
{
    srand(time(NULL));
    
    dividingQuestion();
    cout<<endl;
    areaQuestion();
    cout<<endl;
    exponentQuestion();
    cout<<endl;
        return 0;
}
char generateAnswerDouble(double answer, bool far)
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
    cout<<fixed<<setprecision(2);
    cout<<"a)"<<answers[0]<<endl;
    cout<<"b)"<<answers[1]<<endl;
    cout<<"c)"<<answers[2]<<endl;
    cout<<"d)"<<answers[3]<<endl;
    return rightanswer;
}
char generateAnswerInt(int answer, bool far)
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
    cout<<"a)"<<answers[0]<<endl;
    cout<<"b)"<<answers[1]<<endl;
    cout<<"c)"<<answers[2]<<endl;
    cout<<"d)"<<answers[3]<<endl;
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
            right_answer=generateAnswerDouble(answer, true);
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
            right_answer=generateAnswerDouble(answer, false);
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
            right_answer=generateAnswerDouble(answer, false);
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
            right_answer=generateAnswerInt(int(area), true);
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;
        case 1://area of a square
            length=randomInt(5, 85);
            area=length*length;
            cout<<"The area of a SQUARE with length "<<fixed<<setprecision(0)<<length<<" is:"<<endl;
            right_answer=generateAnswerInt(int(area), true);
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;
        case 2://area of a triangle
            width=randomInt(10, 110);
            height=randomInt(20, 140);
            area=(width*height)/2.0;
            cout<<"The area of a TRIANGLE with height "<<fixed<<setprecision(0)<<height;
            cout<<" and width "<<width<<" is:"<<endl;
            right_answer=generateAnswerDouble(area, true);
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;
        case 3://area of a circle
            radius=randomInt(5, 45);
            area=PI*radius*radius;
            cout<<"The area of a CIRCLE with radius "<<fixed<<setprecision(0)<<radius<<" is:"<<endl;
            right_answer=generateAnswerInt(int(area), true);
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
            right_answer=generateAnswerInt(answer, false);
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;
        case 1://sum of two nums with exponents (ie 3^2+2^3)
            answer=(pow(baseNum1,exponent1)+pow(baseNum2,exponent2));
            cout<<fixed<<setprecision(0);
            cout<<baseNum1<<"^"<<exponent1<<"+"<<baseNum2<<"^"<<exponent2<<"="<<endl;
            right_answer=generateAnswerInt(answer, false);
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;
        case 2://solving for an exponent (ie 2^x*2^3=2^8)
            double exponent3=randomInt(15, 35);
            answer=exponent3-exponent1;
            cout<<fixed<<setprecision(0);
            cout<<"Solve for x in: "<<baseNum1<<"^"<<exponent1;
            cout<<"*"<<baseNum1<<"^x ="<<baseNum1<<"^"<<exponent3<<endl;
            right_answer=generateAnswerInt(answer, false);
            user_choice=validateQuestion();
            checkAnswers(user_choice, right_answer);
            break;
            
    }
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
