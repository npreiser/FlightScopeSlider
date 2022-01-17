/* example.i */
%module trinamic_pg
%inline %{
    extern int vstart;
    extern int a1;
    extern int v1;
    extern int amax;
    extern int vmax;
    extern int dmax;
    extern int d1;
    extern int vstop;
    extern void initMotorParams(char motor);
    extern void gotoTarget(char motor, int targetPos, int wait);
    extern void disableMotorPower();
    extern void shutdown();
    extern int getPosition(char motor);
    extern void resetMotorDrivers(char motor);
    extern int run_example();
    extern int setupGpio();
    extern int return_pass();
    extern int bcminit();
    extern int initwirepi();
    extern void initSpi();
%}
