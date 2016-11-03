# include <stdio.h>
# include <stdlib.h>

void main()
{
	int i1, i2, i3, i4, i5, i6, i7, i8, i9;

	for (i1 = 0; i1 <= 1; i1++)
	{
		for (i2 = 0; i2 <= 1; i2++)
		{
			for (i3 = 0; i3 <= 1; i3++)
			{
				for (i4 = 0; i4 <= 1; i4++)
				{
					for (i5 = 0; i5 <= 1; i5++)
					{
						for (i6 = 0; i6 <= 1; i6++)
						{
							for (i7 = 0; i7 <= 1; i7++)
							{
								for (i8 = 0; i8 <= 1; i8++)
								{
									for (i9 = 0; i9 <= 1; i9++)
									{
										if (i3 && (i7 || i8))
											continue;
										if (!i1 && i2 && i4)
											continue;
										if (i1 && i6)
											continue;
										if (!i6 && (i7 || !i5))
											continue;
										if (!i9 && i1 && i3)
											continue;
										if (!i8 && !i2)
											continue;
										if ((!i3 || i6) && (i8 || !i4))
											continue;
										if (i9 && (i5 || !i6))
											continue;
										if (!i4 && (i3 || !i9))
											continue;
										printf("%d %d %d %d %d %d %d %d %d\n", i1, i2, i3, i4, i5, i6, i7, i8, i9);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}