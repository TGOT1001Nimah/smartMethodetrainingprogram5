int i, j, k;
int cols[5] = {A0, A1, A2, A3, A4};
int rows[5] = {1, 2, 3, 4, 5};
void setup()
{
  for(i=1; i<=5; i++)
  {
    pinMode(i, OUTPUT);
  }
  
 
  for(j=0; j<5; j++)
  {
    pinMode(cols[j], OUTPUT);
  }  
}
void high_all_cols()
{
  digitalWrite(A0, HIGH); 
  digitalWrite(A1, HIGH); 
  digitalWrite(A2, HIGH); 
  digitalWrite(A3, HIGH); 
  digitalWrite(A4, HIGH); 
}
void low_all_cols()
{
  digitalWrite(A0, !HIGH);
  digitalWrite(A1, !HIGH);
  digitalWrite(A2, !HIGH);
  digitalWrite(A3, !HIGH);
  digitalWrite(A4, !HIGH);
}
void high_all_rows()
{
  digitalWrite(1, HIGH); 
  digitalWrite(2, HIGH); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, HIGH); 
  digitalWrite(5, HIGH); 
}
void low_all_rows()
{
  digitalWrite(1, !HIGH);
  digitalWrite(2, !HIGH);
  digitalWrite(3, !HIGH);
  digitalWrite(4, !HIGH);
  digitalWrite(5, !HIGH);
}

//Pattern 1: START

void pattern_1()
{
  //normal sequence
  for(j=0; j<5; j++)
  {
    digitalWrite(cols[j], HIGH); 
    high_all_rows();
    delay(500);
    digitalWrite(cols[j], LOW);
    low_all_rows();
    delay(500);    
  }
  
  low_all_cols();
  low_all_rows();
  delay(500);
  
  //reverse sequence
  for(i=4; i>=0; i--)
  {
    digitalWrite(cols[i], HIGH); 
    high_all_rows();
    delay(500);
    digitalWrite(cols[i], LOW);
    low_all_rows();
    delay(500);
  }
    delay(500);
}

//Pattern 1: END

//Pattern 2: START

void pattern_2()
{
  //normal sequence
  for(j=0; j<5; j++)
  {
    digitalWrite(rows[j], HIGH); 
    high_all_cols();
    delay(500); 
    digitalWrite(rows[j], LOW);
    low_all_cols();
    delay(500);    
  }
  
  low_all_cols();
  low_all_rows();
  delay(500);
  
  //reverse sequence
  for(i=4; i>=0; i--)
  {
    digitalWrite(rows[i], HIGH); 
    high_all_cols();
    delay(500);
    digitalWrite(rows[i], LOW);
    low_all_cols();
    delay(500);
  }
    delay(500); 
}

//Pattern 2: END

//Pattern 3: START

void pattern_3()
{
  for(j=0; j<5; j++)
  {
    digitalWrite(cols[j], HIGH);
    high_all_rows();
    delay(500);
  }
  for(k=0; k<2; k++)
  {
    low_all_cols();
    low_all_rows();
    delay(500);
    high_all_cols();
    high_all_rows();
    delay(500);
  }
  low_all_cols();
  low_all_rows();
  delay(500);  
}

//Pattern 3: END


//Pattern 4: START

void pattern_4()
{
  for(j=0; j<5; j++)
  {
    digitalWrite(rows[j], HIGH);
    high_all_cols();
    delay(500);
  }
  for(k=0; k<2; k++)
  {
    low_all_cols();
    low_all_rows();
    delay(500);
    high_all_cols();
    high_all_rows();
    delay(500);
  }
    low_all_cols();
    low_all_rows();
    delay(500); 
}

//Pattern 4: END

//Pattern 5: START

void for_p5(int x) //additional function for pattern 5
{
  switch(x)
  {
    case 1:
    {
      digitalWrite(A0, HIGH);
      digitalWrite(5, HIGH);
      delay(500);
      digitalWrite(A0, LOW);
      digitalWrite(5, LOW);
      delay(500);
      break;
    }
    case 2:
    {
      digitalWrite(A0, HIGH);//1st led
    digitalWrite(4, HIGH);
      delay(20);
      digitalWrite(A0, LOW);
      digitalWrite(4, LOW);
      delay(5);
      digitalWrite(A1, HIGH);//2nd led
      digitalWrite(5, HIGH);
      delay(20);
      digitalWrite(A1, LOW);
      digitalWrite(5, LOW);
      delay(500);
      break;
    }
    case 3:
    {
      digitalWrite(A0, HIGH);//1st led
      digitalWrite(3, HIGH);
      delay(20);
      digitalWrite(A0, LOW);
      digitalWrite(3, LOW);
      delay(5);
      digitalWrite(A1, HIGH);//2nd led
      digitalWrite(4, HIGH);
      delay(20);
      digitalWrite(A1, LOW);
      digitalWrite(4, LOW);
      delay(5);
      digitalWrite(A2, HIGH);//3rd led
      digitalWrite(5, HIGH);
      delay(20);
      digitalWrite(A2, LOW);
      digitalWrite(5, LOW);
      delay(500);
      break;
    }
    case 4:
    {
      digitalWrite(A0, HIGH);//1st led
      digitalWrite(2, HIGH);
      delay(20);
      digitalWrite(A0, LOW);
      digitalWrite(2, LOW);
      delay(5);
      digitalWrite(A1, HIGH);//2nd led
      digitalWrite(3, HIGH);
      delay(20);
      digitalWrite(A1, LOW);
      digitalWrite(3, LOW);
      delay(5);
      digitalWrite(A2, HIGH);//3rd led
      digitalWrite(4, HIGH);
      delay(20);
      digitalWrite(A2, LOW);
      digitalWrite(4, LOW);
      delay(5);
      digitalWrite(A3, HIGH);//4th led
      digitalWrite(5, HIGH);
      delay(20);
      digitalWrite(A3, LOW);
      digitalWrite(5, LOW);
      delay(500);
      break;
    }
    case 5:
    {
      digitalWrite(A0, HIGH);//1st led
      digitalWrite(1, HIGH);
      delay(20);
      digitalWrite(A0, LOW);
      digitalWrite(1, LOW);
      delay(5);
      digitalWrite(A1, HIGH);//2nd led
      digitalWrite(2, HIGH);
      delay(20);
      digitalWrite(A1, LOW);
      digitalWrite(2, LOW);
      delay(5);
      digitalWrite(A2, HIGH);//3rd led
      digitalWrite(3, HIGH);
      delay(20);
      digitalWrite(A2, LOW);
      digitalWrite(3, LOW);
      delay(5);
      digitalWrite(A3, HIGH);//4th led
      digitalWrite(4, HIGH);
      delay(20);
      digitalWrite(A3, LOW);
      digitalWrite(4, LOW);
      delay(5);
      digitalWrite(A4, HIGH);//5th led
      digitalWrite(5, HIGH);
      delay(20);
      digitalWrite(A4, LOW);
      digitalWrite(5, LOW);
      delay(500);
      break;
    }
    case 6:
    {
      digitalWrite(A1, HIGH);//1st led
      digitalWrite(1, HIGH);
      delay(20);
      digitalWrite(A1, LOW);
      digitalWrite(1, LOW);
      delay(5);
      digitalWrite(A2, HIGH);//2nd led
      digitalWrite(2, HIGH);
      delay(20);
      digitalWrite(A2, LOW);
      digitalWrite(2, LOW);
      delay(5);
      digitalWrite(A3, HIGH);//3rd led
      digitalWrite(3, HIGH);
      delay(20);
      digitalWrite(A3, LOW);
      digitalWrite(3, LOW);
      delay(5);
      digitalWrite(A4, HIGH);//4th led
      digitalWrite(4, HIGH);
      delay(20);
      digitalWrite(A4, LOW);
      digitalWrite(4, LOW);
      delay(500);
      break;
    }
    case 7:
    {
      digitalWrite(A2, HIGH);//1st led
      digitalWrite(1, HIGH);
      delay(20);
      digitalWrite(A2, LOW);
      digitalWrite(1, LOW);
      delay(5);
      digitalWrite(A3, HIGH);//2nd led
      digitalWrite(2, HIGH);
      delay(20);
      digitalWrite(A3, LOW);
      digitalWrite(2, LOW);
      delay(5);
      digitalWrite(A4, HIGH);//3rd led
      digitalWrite(3, HIGH);
      delay(20);
      digitalWrite(A4, LOW);
      digitalWrite(3, LOW);
      delay(500);
      break;
    }
    case 8:
    {
      digitalWrite(A3, HIGH);//1st led
      digitalWrite(1, HIGH);
      delay(20);
      digitalWrite(A3, LOW);
      digitalWrite(1, LOW);
      delay(5);
      digitalWrite(A4, HIGH);//2nd led
      digitalWrite(2, HIGH);
      delay(20);
      digitalWrite(A4, LOW);
      digitalWrite(2, LOW);
      delay(500);
      break;
    }
    case 9:
    {
      digitalWrite(A4, HIGH);
      digitalWrite(1, HIGH);
      delay(20);
      digitalWrite(A4, LOW);
      digitalWrite(1, LOW);
      delay(500);
      break;
    }
    case 10:
    {
      digitalWrite(A0, HIGH);//1st led
      digitalWrite(1, HIGH);
      delay(20);
      digitalWrite(A0, LOW);
      digitalWrite(1, LOW);
      delay(5);
      digitalWrite(A1, HIGH);//2nd led
      digitalWrite(2, HIGH);
      delay(20);
      digitalWrite(A1, LOW);
      digitalWrite(2, LOW);
      delay(5);
      digitalWrite(A2, HIGH);//3rd led
      digitalWrite(3, HIGH);
      delay(20);
      digitalWrite(A2, LOW);
      digitalWrite(3, LOW);
      delay(5);
      digitalWrite(A3, HIGH);//4th led
      digitalWrite(4, HIGH);
      delay(20);
      digitalWrite(A3, LOW);
      digitalWrite(4, LOW);
      delay(5);
      digitalWrite(A4, HIGH);//5th led
      digitalWrite(5, HIGH);
      delay(20);
      digitalWrite(A4, LOW);
      digitalWrite(5, LOW);
      delay(5);
      digitalWrite(A4, HIGH);//6th led
      digitalWrite(1, HIGH);
      delay(20);
      digitalWrite(A4, LOW);
      digitalWrite(1, LOW);
      delay(5);
      digitalWrite(A3, HIGH);//7th led
      digitalWrite(2, HIGH);
      delay(20);
      digitalWrite(A3, LOW);
      digitalWrite(2, LOW);
      delay(5);
      digitalWrite(A2, HIGH);//8th led
      digitalWrite(3, HIGH);
      delay(20);
      digitalWrite(A2, LOW);
      digitalWrite(3, LOW);
      delay(5);
      digitalWrite(A1, HIGH);//9th led
      digitalWrite(4, HIGH);
      delay(20);
      digitalWrite(A1, LOW);
      digitalWrite(4, LOW);
      delay(5);
      digitalWrite(A0, HIGH);//10th led
      digitalWrite(5, HIGH);
      delay(20);
      digitalWrite(A0, LOW);
      digitalWrite(5, LOW);
      break;
    }
  }
}
void pattern_5()
{
  //normal sequence
  for(i=1; i<10; i++)
  {
    for_p5(i);
  }
  for(j=8; j>=1; j--)
  {
    for_p5(j);
  }
  //reverse sequence
  for(k=0; k<=2; k++)
  {
    low_all_cols();
    low_all_rows();
    delay(500); 
    
    for_p5(10);
    delay(500);
  }  
    low_all_cols();
    low_all_rows();
    delay(500);
} 
//Pattern 5: END


//Pattern 6: START

/*the following functions "iter_1" to "iter_24"
are just predefined functions for pattern 6*/
void iter_1()
{
  digitalWrite(A2, HIGH);
  digitalWrite(3, HIGH);
  delay(500);   
  digitalWrite(A2, LOW);
  digitalWrite(3, LOW);
  delay(500);
}
void iter_2()
{
  digitalWrite(A2, HIGH);
  digitalWrite(3, HIGH);
  delay(20);    
  digitalWrite(A2, LOW);
  digitalWrite(3, LOW);
  delay(5);
  digitalWrite(A2, HIGH);
  digitalWrite(2, HIGH);
  delay(20);    
  digitalWrite(A2, LOW);
  digitalWrite(2, LOW);   
}
void iter_3()
{
  iter_2();
  delay(5);
  digitalWrite(A3, HIGH);
  digitalWrite(2, HIGH);
  delay(20);    
  digitalWrite(A3, LOW);
  digitalWrite(2, LOW);   
}
void iter_4()
{
  iter_3();
  delay(5);
  digitalWrite(A3, HIGH);
  digitalWrite(3, HIGH);
  delay(20);    
  digitalWrite(A3, LOW);
  digitalWrite(3, LOW);   
}
void iter_5()
{
  iter_4();
  delay(5);
  digitalWrite(A3, HIGH);
  digitalWrite(4, HIGH);
  delay(20);    
  digitalWrite(A3, LOW);
  digitalWrite(4, LOW);   
}
void iter_6()
{
  iter_5();
  delay(5);
  digitalWrite(A2, HIGH);
  digitalWrite(4, HIGH);
  delay(20);    
  digitalWrite(A2, LOW);
  digitalWrite(4, LOW); 
}
void iter_7()
{
  iter_6();
  delay(5);
  digitalWrite(A1, HIGH);
  digitalWrite(4, HIGH);
  delay(20);    
  digitalWrite(A1, LOW);
  digitalWrite(4, LOW); 
}
void iter_8()
{
  iter_7();
  delay(5);
  digitalWrite(A1, HIGH);
  digitalWrite(3, HIGH);
  delay(20);    
  digitalWrite(A1, LOW);
  digitalWrite(3, LOW);
}
void iter_9()
{
  iter_8();
  digitalWrite(A1, HIGH);
  digitalWrite(2, HIGH);
  delay(20);    
  digitalWrite(A1, LOW);
  digitalWrite(2, LOW);
}
void iter_10()
{
  iter_9();
  digitalWrite(A1, HIGH);
  digitalWrite(1, HIGH);
  delay(20);    
  digitalWrite(A1, LOW);
  digitalWrite(1, LOW);
}
void iter_11()
{
  iter_10();
  digitalWrite(A2, HIGH);
  digitalWrite(1, HIGH);
  delay(20);    
  digitalWrite(A2, LOW);
  digitalWrite(1, LOW);  
}
void iter_12()
{
  iter_11();
  digitalWrite(A3, HIGH);
  digitalWrite(1, HIGH);
  delay(20);    
  digitalWrite(A3, LOW);
  digitalWrite(1, LOW); 
}
void iter_13()
{
  iter_12();
  digitalWrite(A4, HIGH);
  digitalWrite(1, HIGH);
  delay(20);    
  digitalWrite(A4, LOW);
  digitalWrite(1, LOW);   
}
void iter_14()
{
  iter_13();
  digitalWrite(A4, HIGH);
  digitalWrite(2, HIGH);
  delay(20);    
  digitalWrite(A4, LOW);
  digitalWrite(2, LOW); 
}
void iter_15()
{
  iter_14();
  digitalWrite(A4, HIGH);
  digitalWrite(3, HIGH);
  delay(20);    
  digitalWrite(A4, LOW);
  digitalWrite(3, LOW);   
}
void iter_16()
{
  iter_15();
  digitalWrite(A4, HIGH);
  digitalWrite(4, HIGH);
  delay(20);    
  digitalWrite(A4, LOW);
  digitalWrite(4, LOW); 
}
void iter_17()
{
  iter_16();
  digitalWrite(A4, HIGH);
  digitalWrite(5, HIGH);
  delay(20);    
  digitalWrite(A4, LOW);
  digitalWrite(5, LOW); 
}
void iter_18()
{
  iter_17();
  digitalWrite(A3, HIGH);
  digitalWrite(5, HIGH);
  delay(20);    
  digitalWrite(A3, LOW);
  digitalWrite(5, LOW); 
}
void iter_19()
{
  iter_18();
  digitalWrite(A2, HIGH);
  digitalWrite(5, HIGH);
  delay(20);    
  digitalWrite(A2, LOW);
  digitalWrite(5, LOW); 
} 
void iter_20()
{
  iter_19();
  digitalWrite(A1, HIGH);
  digitalWrite(5, HIGH);
  delay(20);    
  digitalWrite(A1, LOW);
  digitalWrite(5, LOW); 
}
void iter_21()
{
  iter_20();
  digitalWrite(A0, HIGH);
  digitalWrite(5, HIGH);
  delay(20);    
  digitalWrite(A0, LOW);
  digitalWrite(5, LOW); 
}
void iter_22()
{
  iter_21();
  digitalWrite(A0, HIGH);
  digitalWrite(4, HIGH);
  delay(20);    
  digitalWrite(A0, LOW);
  digitalWrite(4, LOW); 
}
void iter_23()
{
  iter_22();
  digitalWrite(A0, HIGH);
  digitalWrite(3, HIGH);
  delay(5);   
  digitalWrite(A0, LOW);
  digitalWrite(3, LOW); 
}
void iter_24()
{
  iter_23();
  digitalWrite(A0, HIGH);
  digitalWrite(2, HIGH);
  delay(20);    
  digitalWrite(A0, LOW);
  digitalWrite(2, LOW); 
}
//ends here


void pattern_6()
{
iter_1();
iter_2();
delay(500);
iter_3();
delay(500);  
iter_4();
delay(500);
iter_5();
delay(500);
iter_6();
delay(500);
iter_7();
delay(500);
iter_8();
delay(500);
iter_9();
delay(500);
iter_10();
delay(500);
iter_11();
delay(500);
iter_12();
delay(500);
iter_13();
delay(500);
iter_14();
delay(500);
iter_15();
delay(500);
iter_16();
delay(500);
iter_17();
delay(500);
iter_18();
delay(500);
iter_19();
delay(500);
iter_20();
delay(500);
iter_21();
delay(500);
iter_22();
delay(500);
iter_23();
delay(500);
iter_24();
delay(500);
high_all_cols();
high_all_rows();
delay(500); 
low_all_cols();
low_all_rows();
delay(500);   
}

//Pattern 6: END


//Pattern 7: START

void pattern_7()
{
 for(i=0; i<6; i++)
 {
  //first figure
  for_p5(10);
  delay(5);
  digitalWrite(A0, HIGH);
  digitalWrite(3, HIGH);
  delay(20);
  digitalWrite(A0, LOW);
  digitalWrite(3, LOW);
  delay(5);
  digitalWrite(A2, HIGH);
  digitalWrite(1, HIGH);
  delay(20);
  digitalWrite(A2, LOW);
  digitalWrite(1, LOW);
  delay(5);
  digitalWrite(A4, HIGH);
  digitalWrite(3, HIGH);
  delay(20);
  digitalWrite(A4, LOW);
  digitalWrite(3, LOW);
  delay(5);
  digitalWrite(A2, HIGH);
  digitalWrite(5, HIGH);
  delay(20);
  digitalWrite(A2, LOW);
  digitalWrite(5, LOW);
  delay(500);
  
  //second figure
  digitalWrite(A0, HIGH);//1st led
  digitalWrite(2, HIGH);
  delay(20);
  digitalWrite(A0, LOW);
  digitalWrite(2, LOW);
  delay(5);
  digitalWrite(A1, HIGH);//2nd led
  digitalWrite(3, HIGH);
  delay(20);
  digitalWrite(A1, LOW);
  digitalWrite(3, LOW);
  delay(5);
  digitalWrite(A2, HIGH);//3rd led
  digitalWrite(4, HIGH);
  delay(20);
  digitalWrite(A2, LOW);
  digitalWrite(4, LOW);
  delay(5);
  digitalWrite(A3, HIGH);//4th led
  digitalWrite(5, HIGH);
  delay(20);
  digitalWrite(A3, LOW);
  digitalWrite(5, LOW);
  delay(5);
  digitalWrite(A1, HIGH);//1st led
  digitalWrite(1, HIGH);
  delay(20);
  digitalWrite(A1, LOW);    
  digitalWrite(1, LOW);
  delay(5);
  digitalWrite(A2, HIGH);//2nd led
  digitalWrite(2, HIGH);
  delay(20);
  digitalWrite(A2, LOW);
  digitalWrite(2, LOW);
  delay(5);
  digitalWrite(A3, HIGH);//3rd led
  digitalWrite(3, HIGH);
  delay(20);
  digitalWrite(A3, LOW);
  digitalWrite(3, LOW);
  delay(5);
  digitalWrite(A4, HIGH);//4th led
  digitalWrite(4, HIGH);
  delay(20);
  digitalWrite(A4, LOW);
  digitalWrite(4, LOW);
  delay(5);
  digitalWrite(A3, HIGH);//1st led
  digitalWrite(1, HIGH);
  delay(20);
  digitalWrite(A3, LOW);
  digitalWrite(1, LOW);
  delay(5);
  digitalWrite(A4, HIGH);//2nd led
  digitalWrite(2, HIGH);
  delay(20);
  digitalWrite(A4, LOW);
  digitalWrite(2, LOW);
  delay(5);
  digitalWrite(A0, HIGH);//3rd led
  digitalWrite(4, HIGH);
  delay(20);
  digitalWrite(A0, LOW);
  digitalWrite(4, LOW);
  delay(5);
  digitalWrite(A1, HIGH);//4th led
  digitalWrite(5, HIGH);
  delay(20);
  digitalWrite(A1, LOW);
  digitalWrite(5, LOW);
  delay(500); 
 }
}

//Pattern 7: END

void loop()
{
  pattern_1();
  pattern_2();
  pattern_3();
  pattern_4();
  pattern_5();
  pattern_6();
  pattern_7(); 
}
