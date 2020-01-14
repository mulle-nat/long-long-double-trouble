#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>


int   fits_long( double value)
{
   long   l_val;
   int    fits;

   if( value < (double) LONG_MIN || value > (double) LONG_MAX)
      return( 0);

   l_val = (long) value;
   fits  = (double) l_val == value;
   if( ! fits)
      fprintf( stderr, "Mismatch %f with %ld\n", value, l_val);

   return( fits);
}


int   main( int argc, char *argv[])
{
   double  value;

   fprintf( stderr, "long (%d bytes): %ld - %ld\n", (int) sizeof( long), LONG_MIN, LONG_MAX);
   fprintf( stderr, "double (%d bytes): %g - %g\n", (int) sizeof( double), DBL_MIN, DBL_MAX);

   assert( (double) LONG_MAX <= DBL_MAX);

   // keep my code optimiza
   if( argc == 1)
      value = (double) LONG_MAX;
   else
      value = (double) (LONG_MAX - atoi( argv[ 1]));

   if( fits_long( value))
      printf( "FITS\n");
   else
      printf( "NOPE\n");
   return( 0);
}
