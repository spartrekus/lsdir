

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>   //chdir
#include <dirent.h>

#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>


int main( int argc, char *argv[])
{ 
    int my_arg_t = 0;

    if ( argc >= 2)
    {
      if ( strcmp( argv[1] , "-t" ) ==  0 )
      {
	 my_arg_t = 1;
         if ( argc >= 3)
          if ( strcmp( argv[2] , "" ) !=  0 )
	   chdir( argv[2] );
      }
      else 
      {
         if ( strcmp( argv[1] , "" ) !=  0 )
	   chdir( argv[ 1 ] );
      }
   }

   DIR *dirp;
   struct dirent *dp;
   dirp = opendir( "." );
   while  ((dp = readdir( dirp )) != NULL ) 
   {
        if (dp->d_type == DT_DIR) 
         if (  strcmp( dp->d_name, "." ) != 0 )
          if (  strcmp( dp->d_name, ".." ) != 0 )
           if ( dp->d_name[0] != '.' ) 
          {
	    if ( my_arg_t == 1 ) 
               printf( "%s\t", dp->d_name );
	    else 
               printf( "%s\n", dp->d_name );
          }
   }
   closedir( dirp );
   printf( "\n");
   return 0;
}



