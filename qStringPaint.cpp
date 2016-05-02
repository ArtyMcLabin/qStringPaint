/*
 * Original code by Arty McLabin 24/07/15
 *  for free usage
 *
 * you are welcome to contribute to it ofc.
 * maybe one day it will become a part of the next Qt version :)
 *
     GPLv2  Copyright (C) 2015  Arty McLabin

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.*/


#include "qStringPaint.h"
#include <QDebug>


//version1        replaces the input string with colored version
void qStringPaint::qStringPaint(QString* str, QString htmlColorCode) //a most significant version which all the rest will handle to
{
    if(!htmlColorCode.startsWith("#"))
        htmlColorCode = "#"+htmlColorCode;

    *str = "<span style=\" color:" + htmlColorCode + ";\">" + *str + "</span>";
}





//version2         calls the first version to do the work, but this time returns a modified QString instead of replacing the input.
QString qStringPaint::qStringPaint(QString str, QString htmlColorCode)
{
     qStringPaint(&str,htmlColorCode); //call void version
    return str;
}





//version 3        replacing the qt color (eg. qt::red, qt::black etc) with a proper html code color and then passes to first version.
// cases are int represantation of the qt colors (see QColor manual in google)
void qStringPaint::qStringPaint(QString* str, int qtcolor)
{
    QString htmlColorCode;

    switch(qtcolor){
        case 3: 	htmlColorCode="#ffffff"; break;
        case 2: 	htmlColorCode="#000000"; break;
        case 7: 	htmlColorCode="#ff0000"; break;
        case 13:	htmlColorCode="#800000"; break;
        case 8: 	htmlColorCode="#00ff00"; break;
        case 14:	htmlColorCode="#008000"; break;
        case 9: 	htmlColorCode="#0000ff"; break;
        case 15:	htmlColorCode="#000080"; break;
        case 10:	htmlColorCode="#00ffff"; break;
        case 16:	htmlColorCode="#008080"; break;
        case 11:	htmlColorCode="#ff00ff"; break;
        case 17:	htmlColorCode="#800080"; break;
        case 12:	htmlColorCode="#ffff00"; break;
        case 18:	htmlColorCode="#800080"; break;
        case 5: 	htmlColorCode="#a0a0a4"; break;
        case 4:  	htmlColorCode="#808080"; break;
        case 6:	        htmlColorCode="#c0c0c0"; break;
                  }

     qStringPaint(str, htmlColorCode); //notice, the "str" this time is a QString&, so it calls the first version!! not the second as it might look!!
}






//version 4       calls the upper version to edit the string before we return it here
QString qStringPaint::qStringPaint(QString str, int qtcolor)
{
     qStringPaint(&str,qtcolor);
    return str;
}





