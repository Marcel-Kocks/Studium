# ifndef IGEL_H
# define IGEL_H

# include <stdio.h>
# include <windows.h>
# include <conio.h>

# define printf _cprintf
# define scanf _cscanf

extern void ellipse( int lox, int loy, int rux, int ruy, int strich, COLORREF frame, COLORREF fill);
extern void eframe( int lox, int loy, int rux, int ruy, int strich, COLORREF frame);
extern void fill( int x, int y, COLORREF fill, COLORREF border);
extern void lineto( int x, int y, int strich, COLORREF c);
extern void moveto( int x, int y);
extern void setpixel( int x, int y, COLORREF c);
extern COLORREF getpixel( int x, int y);
extern void rectangle( int lox, int loy, int rux, int ruy, int strich, COLORREF frame, COLORREF fill);
extern void rframe( int lox, int loy, int rux, int ruy, int strich, COLORREF c); 
extern void text( int x, int y, int siz, COLORREF bkc, COLORREF txc, int mode, char *fmt, ...);
extern void textbox( int lox, int loy, int rux, int ruy, int strich, COLORREF frame, COLORREF fill, int siz, COLORREF txc, char *fmt, ...);
extern int load_bitmap( char *bmpfile);

extern void get_windowsize( int *breite, int *hoehe);

extern void wait( unsigned int msecs);

extern int mouse_event( int *flags, int *x, int *y, int wait);
extern int select( int anzahl, ...);

extern void show_console();
extern void hide_console();

# endif
