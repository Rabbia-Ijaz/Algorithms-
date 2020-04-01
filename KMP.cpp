LPS(char P[])
{
	int LPS[strlen(P)];
	j=0;
	i=1;
	while (i<strlen(P))
	{
		if(P[i]==P[j])
		{
			LPS[i]=j+1;
			i++;
			j++;
		}
		else if(j!=0)
		{
			i=LPS[j-1];
		}
		else
		{
			LPS[i]=0;
			i++;
		}
	}

}