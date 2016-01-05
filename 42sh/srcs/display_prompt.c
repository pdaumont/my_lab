int	display_prompt(int c)
{
	int static state = 0;
	
	if (c == 1)
		state = 1;
	else 
		state = 0;
	return (state);
}