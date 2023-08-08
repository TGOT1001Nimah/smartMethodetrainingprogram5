
int colA = A4;
int colB = A3;
int colC = A2;
int colD = A1;
int colE = A0;

int row1 = 7;
int row2 = 6;
int row3 = 5;
int row4 = 4;
int row5 = 3;
int row6 = 2;
int row7 = 1;
int row8 = 0;

int cols[5] = {colA, colB, colC, colD, colE};
int rows[5] = {row1, row2, row3, row4, row5};

//character fonts 5X5
byte a[5] = {0x04, 0x0A, 0x11, 0x1F, 0x11};
byte b[5] = {0x1E, 0x11, 0x1E, 0x11, 0x1E};  
byte c[5] = {0x1E, 0x11, 0x10, 0x11, 0x1E};  
byte d[5] = {0x1E, 0x11, 0x11, 0x11, 0x1E};  
byte e[5] = {0x1F, 0x10, 0x1E, 0x10, 0x1F};
byte f[5] = {0x1F, 0x10, 0x1F, 0x10, 0x10};
byte h[5] = {0x11, 0x11, 0x1F, 0x11, 0x11};
byte i[5] = {0x1F, 0x04, 0x04, 0x04, 0x1F};
byte j[5] = {0x1F, 0x04, 0x04, 0x14, 0x1C};
byte k[5] = {0x11, 0x12, 0x1C, 0x12, 0x11};
byte l[5] = {0x10, 0x10, 0x10, 0x10, 0x1F};
byte m[5] = {0x1B, 0x15, 0x15, 0x11, 0x11};
byte n[5] = {0x11, 0x19, 0x15, 0x13, 0x11};
byte o[5] = {0x0E, 0x11, 0x11, 0x11, 0x0E};
byte p[5] = {0x1F, 0x11, 0x1F, 0x10, 0x10};
byte q[5] = {0x0E, 0x11, 0x15, 0x12, 0x0D};
byte r[5] = {0x1E, 0x11, 0x1E, 0x11, 0x11};
byte s[5] = {0x0F, 0x10, 0x0E, 0x01, 0x1E};
byte t[5] = {0x1F, 0x04, 0x04, 0x04, 0x04};
byte u[5] = {0x11, 0x11, 0x11, 0x11, 0x0E};
byte v[5] = {0x11, 0x11, 0x11, 0x0A, 0x04};
byte y[5] = {0x11, 0x0A, 0x04, 0x04, 0x04};
byte space[5] = {0x00, 0x00, 0x00, 0x00, 0x00};

boolean frame_buffer_new[5][5];
boolean string_map[5][5*6];
unsigned long string_map_max_col;

unsigned int tcnt2;
unsigned int timer_counter = 0;
unsigned long current_col = 0;

void setup()
{
  pinMode(colA, OUTPUT); pinMode(colB, OUTPUT); pinMode(colC, OUTPUT); pinMode(colD, OUTPUT); pinMode(colE, OUTPUT);
  pinMode(row1, OUTPUT); pinMode(row2, OUTPUT); pinMode(row3, OUTPUT); pinMode(row4, OUTPUT); pinMode(row5, OUTPUT); pinMode(row6, OUTPUT); pinMode(row7, OUTPUT); pinMode(row8, OUTPUT);
  
  //set timer stuff
  TIMSK2 &= ~(1<<TOIE2);
  TCCR2A &= ~(1<<WGM21) | (1<<WGM20);
  TCCR2B &= ~(1<<WGM22);
  ASSR &= ~(1<<AS2);
  TIMSK2 &= ~(1<<OCIE2A);
  TCCR2B |= (1<<CS22) | (1<<CS20);
  TCCR2B &= ~(1<<CS21);
  tcnt2 = 6;
  TCNT2 = tcnt2;
  TIMSK2 |= (1<<TOIE2);
  
  Serial.begin(9600);
  Serial.println("ISR initialized");
  
  string_map_max_col = 5 * 6;
  create_string_map("hello");
  
  //update frame_buffer_new with first frame
  for(int j=0;j<5;j++)
  {
    frame_buffer_new[0][j] = string_map[0][j];
    frame_buffer_new[1][j] = string_map[1][j];
    frame_buffer_new[2][j] = string_map[2][j];
    frame_buffer_new[3][j] = string_map[3][j];
    frame_buffer_new[4][j] = string_map[4][j];
  }
  display_off();
  Serial.println("String map + first frame created ...");
  //print string_map
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<string_map_max_col;j++)
    {
      Serial.print(string_map[i][j]);
      Serial.print(".");
    }
    Serial.println();
  }
}

//install the ISR
ISR(TIMER2_OVF_vect)
{
  timer_counter++;
  if(timer_counter==110) //500 = 1 sec
  {
    //reset timer_counter
    timer_counter=0;
    //disable timer
    TIMSK2 |= (0<<TOIE2);
    //update frame
    Serial.println("Frame update event ...");
    current_col++;
    for(int j=0;j<5;j++)
    {
      frame_buffer_new[0][j] = string_map[0][(current_col+j)%string_map_max_col];
      frame_buffer_new[1][j] = string_map[1][(current_col+j)%string_map_max_col];
      frame_buffer_new[2][j] = string_map[2][(current_col+j)%string_map_max_col];
      frame_buffer_new[3][j] = string_map[3][(current_col+j)%string_map_max_col];
      frame_buffer_new[4][j] = string_map[4][(current_col+j)%string_map_max_col];
    }
    display_and_hold_frame();
    Serial.println(current_col%string_map_max_col);
    /*Serial.println("updated frame buffer");
    for(int i=0;i<5;i++)
    {
      for(int j=0;j<5;j++)
      {
        Serial.print(frame_buffer_new[i][j]);
        Serial.print(".");
      }
      Serial.println();
    }*/
  }
  else
  {
    display_and_hold_frame(); 
  }
  TCNT2 = tcnt2;
  //enable timer
  TIMSK2 |= (1<<TOIE2);
}
  
void loop()
{
  //do nothing .. ISR will take care of it
}

void display_off()
{
  for(int i=0;i<5;i++){digitalWrite(rows[i], LOW);digitalWrite(cols[i], HIGH);}
}

void display_and_hold_frame()
{
  for(int i=0;i<5;i++){set_col(i);display_off();}
}

void set_col(int i)
{
  //set col i to ON => LOW
  digitalWrite(cols[i], LOW);
  if(frame_buffer_new[0][i]) {digitalWrite(rows[0],HIGH);} 
  if(frame_buffer_new[1][i]) {digitalWrite(rows[1],HIGH);} 
  if(frame_buffer_new[2][i]) {digitalWrite(rows[2],HIGH);} 
  if(frame_buffer_new[3][i]) {digitalWrite(rows[3],HIGH);} 
  if(frame_buffer_new[4][i]) {digitalWrite(rows[4],HIGH);}
}

void create_string_map(String str)
{
  byte *current_letter;
  int length = str.length();
  
  for(int counter=0;counter<length;counter++)
  {
    switch(str.charAt(counter))
    {
       case 'a': current_letter = a; break; case 'b': current_letter = b; break; 
       case 'c': current_letter = c; break; case 'd': current_letter = d; break; 
       case 'e': current_letter = e; break; case 'f': current_letter = f; break; 
       case 'h': current_letter = h; break; case 'i': current_letter = i; break; 
       case 'j': current_letter = j; break; case 'k': current_letter = k; break;
       case 'l': current_letter = l; break; case 'm': current_letter = m; break; 
       case 'n': current_letter = n; break; case 'o': current_letter = o; break; 
       case 'p': current_letter = p; break; case 'q': current_letter = q; break; 
       case 'r': current_letter = r; break; case 's': current_letter = s; break; 
       case 't': current_letter = t; break; case 'u': current_letter = u; break; 
       case 'v': current_letter = v; break; case 'y': current_letter = y; break; 
    }
    
    for(int j=0;j<5;j++)
    {
      string_map[j][(counter*6)+0] = (current_letter[j]&bit(4))?true:false;
      string_map[j][(counter*6)+1] = (current_letter[j]&bit(3))?true:false;
      string_map[j][(counter*6)+2] = (current_letter[j]&bit(2))?true:false;
      string_map[j][(counter*6)+3] = (current_letter[j]&bit(1))?true:false;
      string_map[j][(counter*6)+4] = (current_letter[j]&bit(0))?true:false;
      string_map[j][(counter*6)+5] = false; //filler column
    }
  }
}
