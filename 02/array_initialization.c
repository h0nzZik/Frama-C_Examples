#include <limits.h>


void try_initialize_array ( void )
{
	int array[5];

	// To prove asserts at the end of this function,
	// uncomment following loop invariant.
	// //@ loop invariant I1: \forall integer j; 0 <= j < i ==> array[j] == 1 - j;
	for (int i = 0; i < 5; i++)
	{
		// Try uncommenting one of following lines:
		// i = -1; // Runtime error
		// i = 0;  // No error, but does not terminate. Invariant is preserved

		array[i] = 1 - i;
	}

	if ( array[2] == -2 )
		array[2]++;

	//@ assert array[2] != -2;	
	//@ assert array[3] == -2;
}


// TODO: Zatim se mi to jeste nedari overit bez -wp-invariants.
/*@
	requires len > 0;
	requires \valid ( array + ( 0 .. len - 1 ) );
	// In specifications we use mathematical integers.
	requires len + base_value < INT_MAX;

	// i++ may overflow elsewhere
	requires len < INT_MAX;
	// assigns array + (0 .. len - 1);
	ensures \forall integer i; 0 <= i < len ==>
		array [i] == base_value + i;
 */
void try_initialize_given_array ( int *array, int len, int base_value )
{
	/*@
		loop invariant
			// WP somehow knows this
			 0 <= i <= len &&
			(
				\forall integer j; 0 <= j < i ==>
				array[j] == base_value + j
			);
			// BTW an error happens when using this syntax:
			// loop assigns array + (0 .. len - 1);

			// It is easy to forget 'i'
			loop assigns i, array[0 .. len - 1];

	 */
	for ( int i = 0; i < len; i++)
	{
		array[i] = base_value + i;
	}
}

int main ( int argc, char *argv[] )
{
	try_initialize_array();
	int array[17];
	try_initialize_given_array ( array + 3, 11, 5 );
	//@ assert array[11] == 13;
	
	// This fails, because precondition is not met
	try_initialize_given_array ( array, 18, 0 );
	return 0;
}
