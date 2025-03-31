#ifndef CLOCK_H
#define CLOCK_H


class clock{
    private:
        int hr= 0;
        int min= 0;
        float sec= 0.0F;
        int aHr= 0;
        int aMin= 0;
        bool isAlarm= false;
        // Define segment pins (A to DP)
        const int segmentPins[8] = {11, 7, 4, A5, A0, 10, 5, 3};  // A, B, C, D, E, F, G, DP
        
        
        const int alarmPin= 9;

    public:
        // Define digit control pins
        const int digitPins[4] = {12, 2, 8, 6};  // D1, D2, D3, D4
        clock();
        int getHr();
        int getMin();
        int getSec();
        void offAlarm();
        int getAlarmPin();
        void setSec(int sec);
        int getAHr();
        int getAMin();
        void setTime(int hr, int min);
        void setATime(int hr,int min);
        void one(int panel);
        void two(int panel);
        void three(int panel);
        void four(int panel);
        void five(int panel);
        void six(int panel);
        void seven(int panel);
        void eight(int panel);
        void nine(int panel);
        void zero(int panel);
        void dp(int panel);
        void cntrlHr(int hr);
        void cntrlMin(int min);
        void display(int digit, int panel);
        void clear();
        void setAlarm(int hr, int min);
        void start();
        ~clock();
};   

extern clock Clock;


class controller{
    private:
        int IRread= 13;
        bool modeTime= true;
    public:
        controller();
        uint32_t read();
        void poweroff();
        void mute();
        int mode();
        void signalWorker();
};


#endif