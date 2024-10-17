#include <LiquidCrystal.h>
#include <DHT.h>
#include <IRremote.h>


#define DHT_PIN 9
#define IR_RECEIVER_PIN 7

//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
DHT dht(DHT_PIN, DHT11);
IRrecv irrecv(IR_RECEIVER_PIN);
decode_results results;


//const int rs = 4, en = 6, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int buttonPin = 8;  // button pin
const int backLight = 4;
int counter = 0; 
int mCounter = 0;
String matrix[8][2];
unsigned long timer = 0; // CHAT GPT idea
int ONOFF = 0;
int stagger = 0;


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(18, 2);
  dht.begin();
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);

  //digitalWrite(backLight, LOW); // turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.
  //noBacklight();


  // Start the IR receiver
  irrecv.enableIRIn();
}


void loop() { // can use custom counter honnestly
    //while (digitalRead(buttonPin) == LOW || counter == 1) {



    irrecv.resume();
    int temp = dht.readTemperature();
    temp = int(temp * 1.8 + 32);
    float humidity = dht.readHumidity();

    matrix[0][0] = "    Welcome,";
    matrix[0][1] = "     Micah";
    matrix[1][0] = "Temperature: " + String(temp) + "F";
    matrix[1][1] = "Humidity: " + String(humidity) + "%";
    matrix[2][0] = "I hope you have";
    matrix[2][1] = "an amazing day:)";
    matrix[3][0] = "IR Detection:";
    matrix[3][1] = "ENABLED";
    matrix[4][0] = "Iteration:";
    matrix[4][1] = "#" + String(counter); 

      timer = millis();

      // Check if IR signal is received
      while (!irrecv.decode(&results) || ONOFF == 0) {

      counter++;

      
      while(millis() - timer <= 6900 && ONOFF == 0) {
        
        if((irrecv.decode(&results))) {
          if (results.value == 0XFFC23D ) { // fast forward
            if(mCounter != 4) {
               mCounter++;
            }
          }
          if (results.value == 0XFF22DD ) { // go back
            if(mCounter != 0) {
               mCounter--;
            }
          }
          if (results.value == 0XFFA25D) { // ON
            stagger = 1;
            ONOFF = 1;
            int c = 0;
            while(c < 3) {
              lcd.clear();
              lcd.setCursor(0, 0);        //sets cursor to second line first row
              lcd.print("loading");  // last name on second line
              delay(400);
              lcd.clear();

              lcd.print("loading.");
              delay(400);
              lcd.clear();

              lcd.print("loading..");
              delay(400);
              lcd.clear();


              lcd.print("loading...");
              delay(400);
              lcd.clear();
              c++;
              irrecv.resume();
            }
          }
          break;
        }
        lcd.setCursor(0, 0);        //sets cursor to second line first row
        lcd.print(matrix[mCounter][0]);  // last name on second line
        lcd.setCursor(0, 1);        // cursor to first position first line
        lcd.print(matrix[mCounter][1]);
        //lcd.clear();
      }
      lcd.clear();
     timer = millis();
      mCounter++;
      if(mCounter == 5) { mCounter = 0;}

      
      lcd.clear(); // can make random
    }


    lcd.setCursor(0, 0);
    lcd.print("   Press a");
    lcd.setCursor(0, 1);
    lcd.print("   Button ");


    

    
    while(irrecv.decode(&results) && ONOFF == 1) {
      Serial.println("with click");
      //StrToHex(input); 
      Serial.println(irrecv.decodedIRData.decodedRawData, HEX);


      


      // Check if the received code is the desired number
      if (results.value == 0XFF6897 ) { // 0 in hex format
        lcd.clear();
        lcd.setCursor(0, 0);        //sets cursor to second line first row
        lcd.print("   mr 0 ,");  // last name on second line
        lcd.setCursor(0, 1);        // cursor to first position first line
        lcd.print("     lol ");
        delay(300);
        lcd.clear();

      }
        if (results.value == 0XFF30CF ) { // 1
          lcd.clear();
          lcd.setCursor(0, 0);        //sets cursor to second line first row
          lcd.print("   1 ,");  // last name on second line
          lcd.setCursor(0, 1);        // cursor to first position first line
          lcd.print("     Work");
          delay(300);
          lcd.clear();

      }

      if (results.value == 0XFF18E7 ) { // 2
        lcd.clear();
        lcd.setCursor(0, 0);        //sets cursor to second line first row
        lcd.print("   2 ,");  // last name on second line
        lcd.setCursor(0, 1);        // cursor to first position first line
        lcd.print("     Work");
        delay(300);
        lcd.clear();

      }

      if (results.value == 0XFF7A85 ) { // 3
        lcd.clear();
        lcd.setCursor(0, 0);        //sets cursor to second line first row
        lcd.print("   3 ,");  // last name on second line
        lcd.setCursor(0, 1);        // cursor to first position first line
        lcd.print("     Work");
        delay(300);
        lcd.clear();
      }

      if (results.value == 0XFF10EF ) { // 4
        lcd.clear();
        lcd.setCursor(0, 0);        //sets cursor to second line first row
        lcd.print("   4 ,");  // last name on second line
        lcd.setCursor(0, 1);        // cursor to first position first line
        lcd.print("     Work");
        delay(300);
        lcd.clear();
      }
      if (results.value == 0XFF38C7 ) { // 5 in hex format
        lcd.clear();
        lcd.setCursor(0, 0);        //sets cursor to second line first row
        lcd.print("   mr 5 ,");  // last name on second line
        lcd.setCursor(0, 1);        // cursor to first position first line
        lcd.print("     lol ");
        delay(300);
        lcd.clear();
      }

        if (results.value == 0XFF5AA5 ) { // 6
        lcd.clear();
        lcd.setCursor(0, 0);        //sets cursor to second line first row
        lcd.print("   6 ,");  // last name on second line
        lcd.setCursor(0, 1);        // cursor to first position first line
        lcd.print("     Work");
        delay(300);
        lcd.clear();
      }

      if (results.value == 0XFF42BD ) { // 7
        lcd.clear();
        lcd.setCursor(0, 0);        //sets cursor to second line first row
        lcd.print("   7 ,");  // last name on second line
        lcd.setCursor(0, 1);        // cursor to first position first line
        lcd.print("     Work");
        delay(300);
        lcd.clear();
      }

      if (results.value == 0XFF42BD ) { // 8
        lcd.clear();
        lcd.setCursor(0, 0);        //sets cursor to second line first row
        lcd.print("   8 ,");  // last name on second line
        lcd.setCursor(0, 1);        // cursor to first position first line
        lcd.print("     Work");
        delay(300);
        lcd.clear();
      }

      if (results.value == 0XFF52AD ) { // 9
        lcd.clear();
        lcd.setCursor(0, 0);        //sets cursor to second line first row
        lcd.print("   9 ,");  // last name on second line
        lcd.setCursor(0, 1);        // cursor to first position first line
        lcd.print("     Work");
        delay(300);
        lcd.clear();
      }

      if (results.value == 0XFFA25D) { // ON -- return to automation but change stagger first!!!
        int d = 0;
        lcd.clear();

        while(d < 3) {
          lcd.setCursor(0, 0);   
          lcd.print("Reverting to"); 
          lcd.setCursor(0, 1); 
          lcd.print("automation");
          delay(400);
          lcd.clear();

          lcd.setCursor(0, 0);   
          lcd.print("Reverting to"); 
          lcd.setCursor(0, 1); 
          lcd.print("automation.");
          delay(400);
          lcd.clear();

          lcd.setCursor(0, 0);   
          lcd.print("Reverting to"); 
          lcd.setCursor(0, 1); 
          lcd.print("automation..");
          delay(400);
          lcd.clear();

          lcd.setCursor(0, 0);   
          lcd.print("Reverting to"); 
          lcd.setCursor(0, 1); 
          lcd.print("automation...");
          delay(400);
          lcd.clear();

          d++;
        }




        ONOFF = 0;
        break;
      }

      if (results.value == 0XFF629D ) { // vol +
        lcd.clear();
        lcd.setCursor(0, 0);        //sets cursor to second line first row
        lcd.print("   vol +  ,");  // last name on second line
        lcd.setCursor(0, 1);        // cursor to first position first line
        lcd.print("     Work");
        delay(2000);
        lcd.clear();
      }
      
      if (results.value == 0XFFE21D ) { // func 
        lcd.clear();
        lcd.setCursor(0, 0);        //sets cursor to second line first row
        lcd.print("    func,");  // last name on second line
        lcd.setCursor(0, 1);        // cursor to first position first line
        lcd.print("     Work");
        delay(3000);
        lcd.clear();
      }
      
      if (results.value == 0XFF22DD ) { // go back
        lcd.clear();
        lcd.setCursor(0, 0);        //sets cursor to second line first row
        lcd.print("   go back ,");  // last name on second line
        lcd.setCursor(0, 1);        // cursor to first position first line
        lcd.print("     Work");
        delay(50);
        lcd.clear();
      }
      
      if (results.value == 0XFF02FD ) { // play / pause
        lcd.clear();
        lcd.setCursor(0, 0);        //sets cursor to second line first row
        lcd.print("  play/pause  ,");  // last name on second line
        lcd.setCursor(0, 1);        // cursor to first position first line
        lcd.print("     Work");
        delay(6900);
        lcd.clear();
      }
      
      if (results.value == 0XFFC23D ) { // fast forward
        lcd.clear();
        lcd.setCursor(0, 0);        //sets cursor to second line first row
        lcd.print("   fast fowrard ,");  // last name on second line
        lcd.setCursor(0, 1);        // cursor to first position first line
        lcd.print("     Work");
        delay(50);
        lcd.clear();
      }

      if (results.value == 0XFFE01F ) { // down
        lcd.clear();
        lcd.setCursor(0, 0);        //sets cursor to second line first row
        lcd.print("   down ,");  // last name on second line
        lcd.setCursor(0, 1);        // cursor to first position first line
        lcd.print("     Work");
        delay(6900);
        lcd.clear();

      }
      if (results.value == 0XFFA857 ) { // vol -
        lcd.clear();
        lcd.setCursor(0, 0);        //sets cursor to second line first row
        lcd.print("   Vol - ,");  // last name on second line
        lcd.setCursor(0, 1);        // cursor to first position first line
        lcd.print("     Work");
        delay(6900);
        lcd.clear();
      }

      if (results.value == 0XFF906F ) { // up
        lcd.clear();
        lcd.setCursor(0, 0);        //sets cursor to second line first row
        lcd.print("   up ,");  // last name on second line
        lcd.setCursor(0, 1);        // cursor to first position first line
        lcd.print("     Work");
        delay(6900);
        lcd.clear();

      }

      if (results.value == 0XFF9867 ) { // EQ
        lcd.clear();
        lcd.setCursor(0, 0);        //sets cursor to second line first row
        lcd.print("   EQ ,");  // last name on second line
        lcd.setCursor(0, 1);        // cursor to first position first line
        lcd.print("     Work");
        delay(6900);
        lcd.clear();

      }

      if (results.value == 0XFFB04F ) { // st/rept
        lcd.clear();
        lcd.setCursor(0, 0);        //sets cursor to second line first row
        lcd.print("   st/rept ,");  // last name on second line
        lcd.setCursor(0, 1);        // cursor to first position first line
        lcd.print("     Work");
        delay(6900);
        lcd.clear();

      }
      // Receive the next value
      irrecv.resume();
      }

    delay(500);
    stagger = 0;
  }