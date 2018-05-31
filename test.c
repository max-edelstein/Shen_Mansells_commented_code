#include <gb/gb.h> 
#include "pic_tiles.c"
#include "pic_map.c"

/*******************************************************************************************************************************
* Bung example explained by Max Edelstein. I did not make the code or graphics, I just commented Mansell's file      *
* I am not the original author of this palette map setting program, I just edited this and experimented in an attempt   *
* to explain it to myself and hopefully others, the original creators contact can be found here                                      *
* Shen Mansell (shenmansell@hotmail.com)                                                                                                                 *
* where: http://shen.mansell.tripod.com                
* also I wanted to note what the batch  file does                                                                                                            *
* lcc -Wl -yp0x143=0x80 -o test.gb test.c first is the flag to the linkers and loaders telling we are using gbc             *
* so the gbc flag is set, I found this using gbdk documentation.                                                                                    *
* bung.gb is the name of the rom that will be  created when the bat file is ran. note that is you keep the previous     *
* gb in the same bin folder, when compiled again the old rom will be overwritten with the contents of of your main  *
* c file that you have been using. test.c is the name of the c file where all of the code will go. Note everything is    *
* written here using c and various gbdk requirements.                                                                                                *
* "pause" placed at the end of the .bat file forces the batch file to stay open after you run the bat file.                     *
*  pause is much like the equivalent of using return 0 or getchar in the main method to keep the program open     *
* the bat file is ran by double clicking the bat file                                                                                                         *
* the bat file is edited by you by right clicking and pressing edit                                                                                 * 
****************************************************************************************************************************/




// the 1 represent the previous loaded color palettes in memory
// so 0 is first palette "red" and 1 is second palette "blue"
const unsigned char pal[] =
{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1  // 20 1's are here
};

void main(void)        /* main program */
{
  
    //set color palettes, four colors in one bkg palette so below only two colors are used for entire map
       // the only two colors used in this program are red and blue
              
  // only red colour is actually used cause set in GBTD
  set_bkg_palette_entry(0,0,RGB(31,31,31)); // white colour
  set_bkg_palette_entry(0,1,RGB(23,23,23));  // light grey colour
  set_bkg_palette_entry(0,2,RGB(15,15,15));  //  dark grey colour
  set_bkg_palette_entry(0,3,RGB(31,0,0));   // red colour

  // only blue colour is used cause set in GBTD
  set_bkg_palette_entry(1,0,RGB(31,31,31));  // white colour
  set_bkg_palette_entry(1,1,RGB(23,23,23));   // light grey colour
  set_bkg_palette_entry(1,2,RGB(15,15,15));  // dark grey colour
  set_bkg_palette_entry(1,3,RGB(0,0,31));  // blue colour
  

  VBK_REG = 0;	//select VRAM bank 0 for tiles transfer

 
    // set tiles-data which can be viewed in vram of bgb
  set_bkg_data( 0, 158, pic_tiles);


  // Set the map data made using GBMB 
  set_bkg_tiles( 0, 2, 20, 18, pic_map);  // was 1

  SHOW_BKG;
  DISPLAY_ON;

  // now change the palette of a few of the lines

  VBK_REG = 1; // select VRAM bank 1 for tile attribute transfer
// no colors were set when creating in GBTD or GBMB,
// only black and white pixels were used
// first param is tiles across
// second param is tiles down,
// third param is tiles across colored
// fourth param is colour palette selected from  the pal colour palette
// the last parameter is the colour palette used

  // just sets one blue tile on the bung logo, hope this helps someone
  set_bkg_tiles (8,5,1,1,pal);
  
  VBK_REG = 0; // select VRAM bank 0 for tile transfer

  while(1)
  {
    /*  The infinite loop here is just to keep the game open until you close the game much like using return 0 */
  /*   or getchar() to keep the console in a regular c program.    */
  } 


}  // end of the main method 
 
