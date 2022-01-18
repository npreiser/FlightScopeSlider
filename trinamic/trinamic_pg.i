/* example.i */
%module trinamic_pg
%inline %{
    extern int initDriver();
    extern int cleanupDriver();
    extern int findHome();
    extern void gotoRegion(int targetRegion);
    extern int setNormalRunModeParams();
%}
