#include <assert.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


int   fits_llong( double value)
{
   long long   ll_val;
   int         fits;

   if( value < (double) LLONG_MIN || value > (double) LLONG_MAX)
      return( 0);

   ll_val = (long long) value;
   fits   = (double) ll_val == value;
   if( ! fits)
      fprintf( stderr, "Mismatch %f with %lld\n", value, ll_val);

   return( fits);
}


int   main( int argc, char *argv[])
{
   double  value;

   fprintf( stderr, "long-long (%d bytes): %lld - %lld\n", (int) sizeof( long long), LLONG_MIN, LLONG_MAX);
   fprintf( stderr, "double (%d bytes): %g - %g\n", (int) sizeof( double), DBL_MIN, DBL_MAX);

   assert( (double) LLONG_MAX <= DBL_MAX);

   // keep my code optimiza
   if( argc == 1)
      value = (double) LLONG_MAX;
   else
      value = (double) (LLONG_MAX - atoi( argv[ 1]));

   if( fits_llong( value))
      printf( "FITS\n");
   else
      printf( "NOPE\n");
   return( 0);
}
