# include "Igel.h"

void IgelMain()
{
	int x, y, evt, drw, sel;

	for (drw = 0; ; )
	{
		evt = mouse_event(0, &x, &y, 0);
		if (evt == WM_LBUTTONDOWN)
		{
			drw = 1;
			moveto(x, y);
		}
		if (drw)
			lineto(x, y, 5, RGB(0, 0, 0));
		if (evt == WM_LBUTTONUP)
			drw = 0;
		if (evt == WM_RBUTTONDOWN)
		{
			sel = select(3, "rot", "grün", "blau");
			switch (sel)
			{
			case 1:
				fill(x, y, RGB(255, 0, 0), RGB(0, 0, 0));
				break;
			case 2:
				fill(x, y, RGB(0, 255, 0), RGB(0, 0, 0));
				break;
			case 3:
				fill(x, y, RGB(0, 0, 255), RGB(0, 0, 0));
				break;
			}
		}
	}
}