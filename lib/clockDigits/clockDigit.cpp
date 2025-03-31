#include <Arduino.h>
#include <clockDigits.h>
#include <IRremote.hpp>

#define POWER 0xED127F80
#define UP 0xFC037F80
#define DOWN 0xFD027F80
#define MUTE 0xE11E7F80
#define MODE 0xE51A7F80
#define ZERO 0xF8077F80   
#define ONE 0xF50A7F80
#define TWO 0xE41B7F80
#define THREE 0xE01F7F80
#define FOUR 0xF30C7F80
#define FIVE 0xF20D7F80
#define SIX 0xF10E7F80
#define SEVEN 0xFF007F80
#define EIGHT 0xF00F7F80
#define NINE 0xE6197F80
#define CONFIRM 0xFE017F80

bool ledon= true;
bool signalon= false;

clock::clock(){
    // initialising for common cathode (CC)
    // pinmode for segments and digit pins
    
    for (int i= 0; i<8; i++){
        pinMode(this->segmentPins[i], OUTPUT);
    }

    for (int i= 0; i<4; i++){
        pinMode(this->digitPins[i], OUTPUT);
        digitalWrite(this->digitPins[i], HIGH);
    }

    pinMode(this->alarmPin, OUTPUT);
}

void clock::one(int panel){
    // clearing

    this->clear();

    // turning on the panel
    digitalWrite(digitPins[panel], LOW);

    // display on the target panel
    digitalWrite(segmentPins[1], HIGH);
    digitalWrite(segmentPins[2], HIGH);
    
}

void clock::two(int panel){
    // clearing
    this->clear();

    // turning on the panel
    digitalWrite(digitPins[panel], LOW);
    // display on the target panel 
    digitalWrite(segmentPins[0], HIGH);
    digitalWrite(segmentPins[1], HIGH);
    digitalWrite(segmentPins[3], HIGH);
    digitalWrite(segmentPins[4], HIGH);
    digitalWrite(segmentPins[6], HIGH);



}

void clock::three(int panel){
    // clearing
    this->clear();

    // turning on the panel
    digitalWrite(digitPins[panel], LOW);
    // display on the target panel 
    digitalWrite(segmentPins[0], HIGH);
    digitalWrite(segmentPins[1], HIGH);
    digitalWrite(segmentPins[2], HIGH);
    digitalWrite(segmentPins[3], HIGH);
    digitalWrite(segmentPins[6], HIGH);
}


void clock::four(int panel){
   // clearing
   this->clear();

   // turning on the panel
   digitalWrite(digitPins[panel], LOW);
   // display on the target panel 

   digitalWrite(segmentPins[1], HIGH);
   digitalWrite(segmentPins[2], HIGH);
   digitalWrite(segmentPins[6], HIGH);
   digitalWrite(segmentPins[5], HIGH);
}

void clock::five(int panel){
    // clearing
    this->clear();

    // turning on the panel
    digitalWrite(digitPins[panel], LOW);
    // display on the target panel 
    digitalWrite(segmentPins[0], HIGH);
    digitalWrite(segmentPins[5], HIGH);
    digitalWrite(segmentPins[6], HIGH);
    digitalWrite(segmentPins[2], HIGH);
    digitalWrite(segmentPins[3], HIGH);
}

void clock::six(int panel){
    // clearing
    this->clear();

    // turning on the panel
    digitalWrite(digitPins[panel], LOW);
    // display on the target panel 
    digitalWrite(segmentPins[0], HIGH);
    digitalWrite(segmentPins[5], HIGH);
    digitalWrite(segmentPins[4], HIGH);
    digitalWrite(segmentPins[3], HIGH);
    digitalWrite(segmentPins[2], HIGH);
    digitalWrite(segmentPins[6], HIGH);

}

void clock::seven(int panel){
    // clearing
    this->clear();

    // turning on the panel
    digitalWrite(digitPins[panel], LOW);
    // display on the target panel 
    digitalWrite(segmentPins[0], HIGH);
    digitalWrite(segmentPins[1], HIGH);
    digitalWrite(segmentPins[2], HIGH);

}

void clock::eight(int panel){
    // clearing
    this->clear();

    // turning on the panel
    digitalWrite(digitPins[panel], LOW);
    // display on the target panel 
    digitalWrite(segmentPins[0], HIGH);
    digitalWrite(segmentPins[1], HIGH);
    digitalWrite(segmentPins[2], HIGH);
    digitalWrite(segmentPins[3], HIGH);
    digitalWrite(segmentPins[6], HIGH);
    digitalWrite(segmentPins[5], HIGH);
    digitalWrite(segmentPins[4], HIGH);
}

void clock::nine(int panel){
    // clearing
    this->clear();

    // turning on the panel
    digitalWrite(digitPins[panel], LOW);
    // display on the target panel 
    digitalWrite(segmentPins[0], HIGH);
    digitalWrite(segmentPins[1], HIGH);
    digitalWrite(segmentPins[2], HIGH);
    digitalWrite(segmentPins[6], HIGH);
    digitalWrite(segmentPins[5], HIGH);
    digitalWrite(segmentPins[3], HIGH);
}

void clock::zero(int panel){
    // clearing
    this->clear();

    // turning on the panel
    digitalWrite(digitPins[panel], LOW);
    // display on the target panel 
    digitalWrite(segmentPins[0], HIGH);
    digitalWrite(segmentPins[1], HIGH);
    digitalWrite(segmentPins[2], HIGH);
    digitalWrite(segmentPins[3], HIGH);
    digitalWrite(segmentPins[5], HIGH);
    digitalWrite(segmentPins[4], HIGH);
}

void clock::dp(int panel){
    this->clear();

    digitalWrite(digitPins[panel], LOW);

    digitalWrite(segmentPins[7], HIGH);
}

void clock::offAlarm(){
    this->isAlarm= false;
    // digitalWrite(this->getAlarmPin(), LOW);//
    noTone(this->alarmPin);
}

void clock::display(int digit, int panel){
    

    if (digit == 1){
        this->one(panel);
        } else if (digit == 2){
        this->two(panel);
        } else if (digit == 3){
        this->three(panel);
        } else if (digit == 4){
        this->four(panel);
        } else if (digit == 5){
        this->five(panel);
        } else if (digit == 6){
        this->six(panel);
        } else if (digit == 7){
        this->seven(panel);
        } else if (digit == 8){
        this->eight(panel);
        } else if (digit == 9){
        this->nine(panel);
        } else if (digit == 0){
        this->zero(panel);
        }
    
}

void clock::cntrlHr(int hr){
    
    // this->dp(1);

    

    int hrDigits[]= {0, 0};
    hrDigits[1]= hr%10;
    hrDigits[0]= (hr/10) % 10;

    // displaying
    for (int i= 0; i < 2; i++){
        
        this->display(hrDigits[i], i);
        delay(5);
        
    }
}

void clock::cntrlMin(int min){
    int minDigits[]= {0, 0};
    minDigits[1]= min%10;
    minDigits[0]= (min/10) % 10;

    // displaying
    for (int i= 0; i < 2; i++){
        
        this->display(minDigits[i], 2+i);
        delay(5);
        
    }
}

void clock::clear(){
    // resetting the segments and digit states
    for (int i= 0; i<8; i++){
        digitalWrite(this->segmentPins[i], LOW);
    }

    for (int i= 0; i<4; i++){
        digitalWrite(this->digitPins[i], HIGH);
    }
}

void clock::setTime(int hr, int min){
    if (hr > 23){
        hr= 23;
    }
    if (min >= 60){
        min= 59;
    }

    this->hr= hr;
    this->min= min;
}

int clock::getHr(){
    return this->hr;
}

int clock::getMin(){
    return this->min;
}

int clock::getAHr(){
    return this->aHr;
}

int clock::getAMin(){
    return this->aMin;
}

int clock::getSec(){
    return this->sec;
}

void clock::setSec(int sec){
    this->sec= sec;
}

int clock::getAlarmPin(){
    return this->alarmPin;
}

void clock::start(){
    controller cntrl;
    // here we need to countdown seconds and thus respectively update hr and minute
    while (true){
        // int toneLevel= 0;
        unsigned long startTime= millis();
        
        if (ledon == true){
            // lights work
            this->dp(1);
            delay(3);
            digitalWrite(digitPins[1], HIGH);
            this->cntrlHr(this->hr);
            // delay(3);
            this->cntrlMin(this->min);
        } else{
            this->clear();
            delay(13);
        }

        // alarm
        if (isAlarm == true){
            if ((this->hr == this->aHr) && (this->min == this->aMin)){
                // highing up the alarm pins
                delay(2);
                tone(this->alarmPin, 1000);
                
                // digitalWrite(this->alarmPin, HIGH); //

                
            } else{
                // digitalWrite(this->alarmPin, LOW);//
                noTone(this->alarmPin);
            }

        } 

        cntrl.signalWorker();

        unsigned long endTime= millis();
        float seconds= (endTime - startTime)/ 1000.0F;
        
        this->sec += seconds;
        if (this->sec >= 60){
            
            this->min += this->sec/60;
            this->sec= 0;
           
        }

        if (this->min >= 60){
            this->hr++;
            this->min= 0;
        }

        if (this->hr > 23){
            this->hr = 0;
        }


    }
}

clock Clock;

void clock::setAlarm(int hr, int min){
    this->aHr = hr;
    this->aMin = min;
    this->isAlarm= true;
}

void clock::setATime(int hr, int min){
    if (hr > 23){
        hr= 23;
    }
    if (min >= 60){
        min= 59;
    }

    this->setAlarm(hr, min);
}


controller::controller(){
    
    IrReceiver.begin(this->IRread);
}

uint32_t controller::read(){
    
    if (IrReceiver.decode()) {
        Serial.print("HEX code: ");
        Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print in HEX
        IrReceiver.resume(); // Prepare to receive the next signal
        return IrReceiver.decodedIRData.decodedRawData;
    } else{
        return 0;
    }
}



void controller::poweroff(){
    if (ledon == true){
        ledon= false;
    } else {
        ledon= true;
    }
}

// void controller::blink(int panel){
//     clock obj; obj.clear();
    
// }

int controller::mode(){
    // this function will be doing two things
    // 1. changing the mode from time to alarm
    // 2. interface to set time or alarm respectively
    if (this->modeTime == true){
        // altering
        // this->modeTime = false;
        // Serial.println("entered modeTime true");

        // setting up the interface
        Clock.clear();  // clearing the led

        int panel= 0;
        int hrData[2]= {0, 0};
        int minData[2]= {0, 0};
        int count= 0;
        while (count < 2){
            // Serial.println("entered the first while loop");
            // Serial.println(count);
            // Serial.println(hrData[0]);
            // Serial.println(hrData[1]);
            uint32_t signal= this->read();
            if (signal == static_cast<uint32_t>(ZERO)){
                hrData[count]= 0;
                count++;
                Clock.display(0, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(ONE)){
                hrData[count]= 1;
                count++;
                Clock.display(1, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(TWO)){
                hrData[count]= 2;
                count++;
                
                Clock.display(2, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(THREE)){
                hrData[count]= 3;
                count++;
                Clock.display(3, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(FOUR)){
                hrData[count]= 4;
                count++;
                Clock.display(4, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(FIVE)){
                hrData[count]= 5;
                count++;
                Clock.display(5, panel);
                panel++;
            }else if (signal == static_cast<uint32_t>(SIX)){
                hrData[count]= 6;
                count++;
                Clock.display(6, panel);
                panel++;
            }else if (signal == static_cast<uint32_t>(SEVEN)){
                hrData[count]= 7;
                count++;
                Clock.display(7, panel);
                panel++;
            }else if (signal == static_cast<uint32_t>(EIGHT)){
                hrData[count]= 8;
                count++;
                Clock.display(8, panel);
                panel++;
            }else if (signal == static_cast<uint32_t>(NINE)){
                hrData[count]= 9;
                count++;
                Clock.display(9, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(MODE)){
                this->modeTime= false;
                this->mode();
                return 1;
            }
            // ensuring continuous appearance of the valid numbers
            for (int i= 0; i<2; i++){
                Clock.display(hrData[i], i);
                delay(5);
            }

            for (int i = 0; i < 4; i++){
                Clock.dp(i);
                delay(1);
                digitalWrite(Clock.digitPins[i], HIGH);
            }

            for (int i= 0; i<2; i++){
                Clock.display(minData[i], 2+i);
                delay(5);
            }
            


        }

        count= 0;

        while (count < 2){
            uint32_t signal= this->read();
            // Serial.println("entered the second while loop");
            if (signal == static_cast<uint32_t>(ZERO)){
                minData[count]= 0;
                count++;
                Clock.display(0, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(ONE)){
                minData[count]= 1;
                count++;
                Clock.display(1, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(TWO)){
                minData[count]= 2;
                count++;
                
                Clock.display(2, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(THREE)){
                minData[count]= 3;
                count++;
                Clock.display(3, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(FOUR)){
                minData[count]= 4;
                count++;
                Clock.display(4, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(FIVE)){
                minData[count]= 5;
                count++;
                Clock.display(5, panel);
                panel++;
            }else if (signal == static_cast<uint32_t>(SIX)){
                minData[count]= 6;
                count++;
                Clock.display(6, panel);
                panel++;
            }else if (signal == static_cast<uint32_t>(SEVEN)){
                minData[count]= 7;
                count++;
                Clock.display(7, panel);
                panel++;
            }else if (signal == static_cast<uint32_t>(EIGHT)){
                minData[count]= 8;
                count++;
                Clock.display(8, panel);
                panel++;
            }else if (signal == static_cast<uint32_t>(NINE)){
                minData[count]= 9;
                count++;
                Clock.display(9, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(MODE)){
                this->modeTime= false;
                this->mode();
                return 1;

            }

            // ensuring continuous appearance of the valid numbers
            for (int i= 0; i<2; i++){
                Clock.display(hrData[i], i);
                delay(5);
            }

            for (int i = 0; i < 4; i++){
                Clock.dp(i);
                delay(1);
                digitalWrite(Clock.digitPins[i], HIGH);
            }

            for (int i= 0; i<2; i++){
                Clock.display(minData[i], 2+i);
                delay(5);
            }
            

        }
        // updating hr and minutes
        // using equation 10x+y
        Clock.setTime((10 * hrData[0]) + hrData[1], (10 * minData[0]) + minData[1]);
        
    }

    else{
        // for alarm
        // altering
        // this->modeTime = true;

        // setting up the interface
        Clock.clear();  // clearing the led

        int panel= 0;
        int hrData[2]= {0, 0};
        int minData[2]= {0, 0};
        int count= 0;
        while (count < 2){
 
            uint32_t signal= this->read();
            if (signal == static_cast<uint32_t>(ZERO)){
                hrData[count]= 0;
                count++;
                Clock.display(0, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(ONE)){
                hrData[count]= 1;
                count++;
                Clock.display(1, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(TWO)){
                hrData[count]= 2;
                count++;
                
                Clock.display(2, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(THREE)){
                hrData[count]= 3;
                count++;
                Clock.display(3, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(FOUR)){
                hrData[count]= 4;
                count++;
                Clock.display(4, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(FIVE)){
                hrData[count]= 5;
                count++;
                Clock.display(5, panel);
                panel++;
            }else if (signal == static_cast<uint32_t>(SIX)){
                hrData[count]= 6;
                count++;
                Clock.display(6, panel);
                panel++;
            }else if (signal == static_cast<uint32_t>(SEVEN)){
                hrData[count]= 7;
                count++;
                Clock.display(7, panel);
                panel++;
            }else if (signal == static_cast<uint32_t>(EIGHT)){
                hrData[count]= 8;
                count++;
                Clock.display(8, panel);
                panel++;
            }else if (signal == static_cast<uint32_t>(NINE)){
                hrData[count]= 9;
                count++;
                Clock.display(9, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(MODE)){
                this->modeTime= true;
                return 1;
            }
            // ensuring continuous appearance of the valid numbers
            for (int i= 0; i<2; i++){
                Clock.display(hrData[i], i);
                delay(5);
            }


            for (int i= 0; i<2; i++){
                Clock.display(minData[i], 2+i);
                delay(5);
            }
            


        }

        count= 0;

        while (count < 2){
            uint32_t signal= this->read();
            // Serial.println("entered the second while loop");
            if (signal == static_cast<uint32_t>(ZERO)){
                minData[count]= 0;
                count++;
                Clock.display(0, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(ONE)){
                minData[count]= 1;
                count++;
                Clock.display(1, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(TWO)){
                minData[count]= 2;
                count++;
                
                Clock.display(2, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(THREE)){
                minData[count]= 3;
                count++;
                Clock.display(3, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(FOUR)){
                minData[count]= 4;
                count++;
                Clock.display(4, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(FIVE)){
                minData[count]= 5;
                count++;
                Clock.display(5, panel);
                panel++;
            }else if (signal == static_cast<uint32_t>(SIX)){
                minData[count]= 6;
                count++;
                Clock.display(6, panel);
                panel++;
            }else if (signal == static_cast<uint32_t>(SEVEN)){
                minData[count]= 7;
                count++;
                Clock.display(7, panel);
                panel++;
            }else if (signal == static_cast<uint32_t>(EIGHT)){
                minData[count]= 8;
                count++;
                Clock.display(8, panel);
                panel++;
            }else if (signal == static_cast<uint32_t>(NINE)){
                minData[count]= 9;
                count++;
                Clock.display(9, panel);
                panel++;
            } else if (signal == static_cast<uint32_t>(MODE)){
                this->modeTime= true;
                return 1;
            }

            // ensuring continuous appearance of the valid numbers
            for (int i= 0; i<2; i++){
                Clock.display(hrData[i], i);
                delay(5);
            }


            for (int i= 0; i<2; i++){
                Clock.display(minData[i], 2+i);
                delay(5);
            }
            

        }
        // updating hr and minutes
        // using equation 10x+y
        Clock.setATime((10 * hrData[0]) + hrData[1], (10 * minData[0]) + minData[1]);

    }
    // Serial.println("leaving modetime true");
    return 0;
}



void controller::signalWorker(){
    uint32_t signal= this->read();
    if (signal != 0){
        // Serial.println(signal);
        // Serial.println(static_cast<uint32_t>(POWER));
        // Serial.println(signal == static_cast<uint32_t>(MODE));
        if (signal == static_cast<uint32_t>(POWER)){
            this->poweroff();
        } else if (signal == static_cast<uint32_t>(MODE)){
            this->mode();
        } else if(signal == static_cast<uint32_t>(MUTE)){
            Clock.offAlarm();
        }
}
}

clock::~clock(){
    
}

