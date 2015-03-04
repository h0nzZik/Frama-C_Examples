
int Frama_C_interval ( int, int );

int main ( int argc, char *argv[] )
{
	int array[25];
	array[argc] = 7;
	int idx = Frama_C_interval ( -1, 26 );
	idx = idx / 2;
	array[idx] = 0x1234;

	idx = idx * 2 + 3;
	array[idx] = 0x4567;

	idx += 28;
	array[idx] = 15;

	return 0;
}
