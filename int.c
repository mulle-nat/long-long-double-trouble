#include <assert.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


int   fits_int( double value)
{
   int  i_val;
   int  fits;

   if( value < (double) INT_MIN || value > (double) INT_MAX)
      return( 0);

   i_val = (int) value;
   fits  = (double) i_val == value;
   if( ! fits)
      fprintf( stderr, "Mismatch %f with %d\n", value, i_val);

   return( fits);
}


int   main( int argc, char *argv[])
{
   double  value;

   fprintf( stderr, "int (%d bytes): %d - %d\n", (int) sizeof( int), INT_MIN, INT_MAX);
   fprintf( stderr, "double (%d bytes): %g - %g\n", (int) sizeof( double), DBL_MIN, DBL_MAX);

   assert( (double) INT_MAX <= DBL_MAX);

   // keep my code optimiza
   if( argc == 1)
      value = (double) INT_MAX;
   else
      value = (double) (INT_MAX - atoi( argv[ 1]));

   if( fits_int( value))
      printf( "FITS\n");
   else
      printf( "NOPE\n");
   return( 0);
}
