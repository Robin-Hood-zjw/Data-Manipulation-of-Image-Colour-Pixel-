#include <iostream>
using namespace std;


/*Programmer: JIAWEN ZHANG, Oct. 6  2021( This is the codes for
the second project of EECS402, and this project aims at creating
and implementing the beginnings of three classes to represent
colors, images, and locations within an image

I adjusted the main compile error: usage of macros, and its
location: #include "andrewTest.h". Moreover, I adjusted a
printout logic, some magic numbers, and then changed the
function <doValidRange> to be a private function of the Class
<ColorClass>*/


//constant declarations and initializations
const int MAX_PIXEL_VALUE = 1000;
const int MIN_PIXEL_VALUE = 0;
const int DEFAULT_ROW_ROL_VALUE = -99999;
const int MAX_ROW_NUM = 10;
const int MAX_COL_NUM = 18;
const int MIN_ROW_COL_LIM = 0;
const int LAST_ROW_NUM = 17;

//global function prototypes with comments

//class definitions

/*The class <ColorClass> just indicates the values
in red, green and blue, and their related changes*/
class ColorClass
{
    private:
    int redVal;//this private attribute indicates the value of red
    int greenVal;//this private attribute indicates the value of green
    int blueVal;//this private attribute indicates the value of blue

    /*I removed the three parameters since it is a private function
    and could visit all the private attributes right now*/
    bool doVaildRange();
    /*This function <doValidRange> is for checking the length and
    guarantee the length is within valid length. If a specified
    color value is outside the valid range, it will be “clipped”
    to ensure all ColorClass attributes are always set to be within
    the valid range.*/

    public:
    void setToBlack();//result in “full” Black
    void setToRed();//result in “full” Red
    void setToGreen();//result in “full” Green
    void setToBlue();//result in “full” Blue
    void setToWhite();//result in “full” White
    
    /*This default ctor <ColorClass()> will set the color’s
    initial RGB values to the color full white*/
    ColorClass();
    /*This value ctor <ColorClass(int inRed, int inGreen, int
    inBlue)> will set the color’s initial RGB values to the
    values provided*/
    ColorClass(int inRed, int inGreen, int inBlue);
    /*This function <setTo(int inRed, int inGreen, int inBlue)>
    sets the color object's RGB values to the provided values.*/
    bool setTo(int inRed, int inGreen, int inBlue);
    /*This function sets the color's component color values to
    the same as those in the "inColor" input parameter*/
    bool setTo(ColorClass &inColor);
    /*This function causes each RGB value to have the corresponding
    value from the input parameter color added to it.*/
    bool addColor(ColorClass &rhs);
    /*This function <subtractColor(ColorClass &rhs)> causes each RGB
    value to have the corresponding value from the input parameter
    subtracted from it.*/
    bool subtractColor(ColorClass &rhs);
    /*This function <adjustBrightness(double adjFactor)> performs a
    simplified brightness adjustment which multiplies each RGB value
    by the adjustment factor provided.*/
    bool adjustBrightness(double adjFactor);
    /*Prints the component color values to the console using the
    following format: "R: <red> G: <green> B: <blue>" where <red>,
    <green>, and <blue> are all replaced with their corresponding
    component color values.*/
    void printComponentValues();
};

/*The second class <RowColumnClass>is a simple class to
uniquely identify a specific pixel within an image. */
class RowColumnClass
{
    private:
    int rowVal;//this private attribute indicates the value of row
    int colVal;//this private attribute indicates the value of column

    public:
    /*This default constructor <RowColumnClass()> sets both the row
    and column value of the newly created RowColumnClass object to
    -99999*/
    RowColumnClass();
    /*This value constructor <RowColumnClass(int inRow, int inCol)>
    sets the row and column values to the corresponding values passed
    into the constructor.*/
    RowColumnClass(int inRow, int inCol);
    /*This function <setRowCol(int inRow, int inCol)> is a “setter
    function” that set the appropriate attributes <rowVal> and <colVal>
    to the values provided.*/
    void setRowCol(int inRow, int inCol);
    /*This function <setRow(int inRow)> is a “setter function” that
    set the appropriate attributes <rowVal> to the values provided.*/
    void setRow(int inRow);
    /*This function <setCol(int inCol)> is a “setter function” that
    set the appropriate attributes <colVal> to the values provided.*/
    void setCol(int inCol);
    /*This function <getRow()> is a “getter functions” that return
    the appropriate attribute value to the caller*/
    int getRow();
    /*This function <getCol()> is a “getter functions” that return
    the appropriate attribute value to the caller*/
    int getCol();
    /*This function <addRowColTo(RowColumnClass &inRowCol)> adds the
    row and column index values in the input parameter to the row and
    column index of the object the function is called on*/
    void addRowColTo(RowColumnClass &inRowCol);
    /*This function <printRowCol()> prints the contents of the image
    to the screen.*/
    void printRowCol();
};

/*The last class <ColorImageClass>you will implement will
be named ColorImageClass and will represent a small image*/
class ColorImageClass
{
    private:
    /*This attribute for ColorImageClass is a 2D array of ColorClass
    objects, and your 2D array in ColorImageClass must be set to 10
    rows by 18 columns*/
    ColorClass colorAry[MAX_ROW_NUM][MAX_COL_NUM];

    public:
    /*This default constructor <ColorImageClass()> sets all pixels
    in the image to full black.*/
    ColorImageClass();
    /*This function <initializeTo(ColorClass &inColor)> initializes
    all image pixels to the color provided via input*/
    void initializeTo(ColorClass &inColor);
    /*This function <addImageTo(ColorImageClass &rhsImg)> performs a
    pixel-wise addition, such that each pixel in the image has the
    pixel in the corresponding location in the right hand side input
    image added to it.*/
    bool addImageTo(ColorImageClass &rhsImg);
    /*This function <addImages(int numImgsToAdd, ColorImageClass
    imagesToAdd[])> causes the image's pixel values to be set to the
    sum of the corresponding pixels in each image in the imagesToAdd
    input parameter*/
    bool addImages(int numImgsToAdd, ColorImageClass imagesToAdd []);
    /*This function <setColorAtLocation(RowColumnClass &inRowCol,
    ColorClass &inColor)> sets the pixel at the location specified
    by the “inRowCol” parameter to the color specified via the
    “inColor” parameter.*/
    bool setColorAtLocation(RowColumnClass &inRowCol, ColorClass &inColor);
    /*This function <getColorAtLocation(RowColumnClass &inRowCol,
    ColorClass &outColor)> sets the appropriate attributes to the values
    of the provided objects from two classes. If the row/column provided
    is a valid row/column for the image, this function returns true and
    the output parameter "outColor" is assigned to the color of the image
    pixel at that location.*/
    bool getColorAtLocation(RowColumnClass &inRowCol, ColorClass &outColor);
    /*This function <printImage()> prints the contents of the image to
    the screen*/
    void printImage();
};


#ifdef ANDREW_TEST

//this is the place that I adjusted the compile error: usage of macros
#include "andrewTest.h"
#else
int main()
{
    ColorClass testColor;
    RowColumnClass testRowCol;
    RowColumnClass testRowColOther(111, 222);
    ColorImageClass testImage;
    ColorImageClass testImages[3];
      
    //Test some basic ColorClass operations...
    cout << "Initial: ";
    testColor.printComponentValues();
    cout << endl;
      
    testColor.setToBlack();
    cout << "Black: ";
    testColor.printComponentValues();
    cout << endl;

    testColor.setToGreen();
    cout << "Green: ";
    testColor.printComponentValues();
    cout << endl;

    testColor.adjustBrightness(0.5);
    cout << "Dimmer Green: ";
    testColor.printComponentValues();
    cout << endl;

    //Test some basic RowColumnClass operations...
    cout << "Want defaults: ";
    testRowCol.printRowCol();
    cout << endl;

    testRowCol.setRowCol(2, 8);
    cout << "Want 2,8: ";
    testRowCol.printRowCol();
    cout << endl;

    cout << "Want 111, 222: ";
    testRowColOther.printRowCol();
    cout << endl;

    testRowColOther.setRowCol(4, 2);
    testRowCol.addRowColTo(testRowColOther);
    cout << "Want 6,10: ";
    testRowCol.printRowCol();
    cout << endl;

    //Test some basic ColorImageClass operations...
    testColor.setToRed();
    testImage.initializeTo(testColor);

    testRowCol.setRowCol(555, 5);
    cout << "Want: Color at [555,5]: Invalid Index!" << endl;
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor))
    {
        testColor.printComponentValues();
    }
    else
    {
        cout << "Invalid Index!";
    }
    cout << endl;

    testRowCol.setRow(4);
    cout << "Want: Color at [4,5]: R: 1000 G: 0 B: 0" << endl;
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor))
    {
        testColor.printComponentValues();
    }
    else
    {
        cout << "Invalid Index!";
    }
    cout << endl;

    //Set up an array of images of different colors
    testColor.setToRed();
    testColor.adjustBrightness(0.25);
    testImages[0].initializeTo(testColor);
    testColor.setToBlue();
    testColor.adjustBrightness(0.75);
    testImages[1].initializeTo(testColor);
    testColor.setToGreen();
    testImages[2].initializeTo(testColor);

    //Modify a few individual pixel colors
    testRowCol.setRowCol(4, 2);
    testColor.setToWhite();
    testImages[1].setColorAtLocation(testRowCol, testColor);

    testRowCol.setRowCol(2, 4);
    testColor.setToBlack();
    testImages[2].setColorAtLocation(testRowCol, testColor);

    //Add up all images in testImages array and assign result
    //to the testImage image
    testImage.addImages(3, testImages);
  
    //Check some certain values

    cout << "Added values:" << endl;
    for (int colInd = 0; colInd < 8; colInd += 2)
    {
        testRowCol.setRowCol(4, colInd);
        cout << "Color at ";
        testRowCol.printRowCol();
        cout << ": ";
        if (testImage.getColorAtLocation(testRowCol, testColor))
        {
            testColor.printComponentValues();
        }
        else
        {
            cout << "Invalid Index!";
        }
        cout << endl;
    }
    
    for (int rowInd = 0; rowInd < 8; rowInd += 2)
    {
        testRowCol.setRowCol(rowInd, 4);
        cout << "Color at ";
        testRowCol.printRowCol();
        cout << ": ";
        if (testImage.getColorAtLocation(testRowCol, testColor))
        {
            testColor.printComponentValues();
        }
        else
        {
            cout << "Invalid Index!";
        }
        cout << endl;
    }
    
    cout << "Printing entire test image:" << endl;
    testImage.printImage();
    
    return 0;
}
#endif


//class method definitions


//Part 1: the class methods of the Class <ColorClass>

/*This function <doValidRange> is for checking the length and
guarantee the length is within valid length. If a specified
color value is outside the valid range, it will be “clipped”
to ensure all ColorClass attributes are always set to be within
the valid range.*/

/*I changed the location of this function, making it a private
function of the class <ColorClass>. Moreover, I removed the
parameters wrote in the brackets, and used private attributes
of the class <ColorClass>, including <redval>, <greenVal> and
<blueVal>*/
bool ColorClass::doVaildRange()
{
    bool checkRangeStatus = true;

    if (redVal > MAX_PIXEL_VALUE)
    {
        redVal = MAX_PIXEL_VALUE;
        checkRangeStatus = false;
    }
    else if (redVal < MIN_PIXEL_VALUE)
    {
        redVal = MIN_PIXEL_VALUE;
        checkRangeStatus = false;
    }

    if (greenVal > MAX_PIXEL_VALUE)
    {
        greenVal = MAX_PIXEL_VALUE;
        checkRangeStatus = false;
    }
    else if (greenVal < MIN_PIXEL_VALUE)
    {
        greenVal = MIN_PIXEL_VALUE;
        checkRangeStatus = false;
    }
    
    if (blueVal > MAX_PIXEL_VALUE)
    {
        blueVal = MAX_PIXEL_VALUE;
        checkRangeStatus = false;
    }
    else if (blueVal < MIN_PIXEL_VALUE)
    {
        blueVal = MIN_PIXEL_VALUE;
        checkRangeStatus = false;
    }

    return checkRangeStatus;
}

/*This default ctor <ColorClass()> will set the color’s
initial RGB values to the color full white*/
ColorClass::ColorClass()
{
    redVal = MAX_PIXEL_VALUE;
    greenVal = MAX_PIXEL_VALUE;
    blueVal = MAX_PIXEL_VALUE;
}

/*This value ctor <ColorClass(int inRed, int inGreen, int
inBlue)> will set the color’s initial RGB values to the
values provided*/
ColorClass::ColorClass(
    int inRed,
    int inGreen,
    int inBlue
    )
    {

        redVal = inRed;
        greenVal = inGreen;
        blueVal = inBlue;

        /*I remove the parameters since <doValidRange> is
        a private function of the class <ColorClass>*/
        doVaildRange();
    }

void ColorClass::setToBlack()//result in “full” Black
{
    redVal = MIN_PIXEL_VALUE;
    greenVal = MIN_PIXEL_VALUE;
    blueVal = MIN_PIXEL_VALUE;
}
void ColorClass::setToRed()//result in “full” Red
{
    redVal = MAX_PIXEL_VALUE;
    greenVal = MIN_PIXEL_VALUE;
    blueVal = MIN_PIXEL_VALUE;
}
void ColorClass::setToGreen()//result in “full” Green
{
    redVal = MIN_PIXEL_VALUE;
    greenVal = MAX_PIXEL_VALUE;
    blueVal = MIN_PIXEL_VALUE;
}
void ColorClass::setToBlue()//result in “full” Blue
{
    redVal = MIN_PIXEL_VALUE;
    greenVal = MIN_PIXEL_VALUE;
    blueVal = MAX_PIXEL_VALUE;
}
void ColorClass::setToWhite()//result in “full” White
{
    redVal = MAX_PIXEL_VALUE;
    greenVal = MAX_PIXEL_VALUE;
    blueVal = MAX_PIXEL_VALUE;
}

/*This function <setTo(int inRed, int inGreen, int inBlue)> sets
the color object's RGB values to the provided values.

If any input value is outside the allowed color value range, then
the assigned value is "clipped" in order to keep the RGB color
values within the valid range. If any clipping was necessary, the
function returns true, otherwise the function returns false. */
bool ColorClass::setTo(int inRed, int inGreen, int inBlue)
{
    bool RangeJudgement;

    redVal = inRed;
    greenVal = inGreen;
    blueVal = inBlue;

    /*I remove the parameters since <doValidRange> is
    a private function of the class <ColorClass>*/
    RangeJudgement = doVaildRange();
    return RangeJudgement;
}

/*This function sets the color's component color values to the
same as those in the "inColor" input parameter.

If any clipping was necessary in order to keep the color values
in the allowed range, the function returns true, otherwise it
returns false. Note that, since a ColorClass object is used as
input, and since we are making sure ColorClass attributes are
always within the valid range, this function should never find
a need to clipping, and therefore, would be expected to always
return false.*/
bool ColorClass::setTo(ColorClass &inColor)
{
    bool RangeJudgement;

    redVal = inColor.redVal;
    greenVal = inColor.greenVal;
    blueVal = inColor.blueVal;

    /*I remove the parameters since <doValidRange> is
    a private function of the class <ColorClass>*/
    RangeJudgement = doVaildRange();
    return RangeJudgement;
}

/*This function causes each RGB value to have the corresponding
value from the input parameter color added to it*/
bool ColorClass::addColor(ColorClass &rhs)
{
    bool RangeJudgement;

    redVal += rhs.redVal;
    greenVal += rhs.greenVal;
    blueVal += rhs.blueVal;

    /*I remove the parameters since <doValidRange> is
    a private function of the class <ColorClass>*/
    RangeJudgement = doVaildRange();
    return RangeJudgement;
}

/*This function <subtractColor(ColorClass &rhs)> causes each
RGB value to have the corresponding value from the input
parameter subtracted from it.*/
bool ColorClass::subtractColor(ColorClass &rhs)
{
    bool RangeJudgement;

    redVal -= rhs.redVal;
    greenVal -= rhs.greenVal;
    blueVal -= rhs.blueVal ;
    
    /*I remove the parameters since <doValidRange> is
    a private function of the class <ColorClass>*/
    RangeJudgement = doVaildRange();
    return RangeJudgement;
}

/*This function <adjustBrightness(double adjFactor)> performs
a simplified brightness adjustment which multiplies each RGB
value by the adjustment factor provided.*/
bool ColorClass::adjustBrightness(double adjFactor)
{
    bool RangeJudgement;

    redVal = redVal * adjFactor;
    greenVal = greenVal * adjFactor;
    blueVal= blueVal * adjFactor;
    
    /*I remove the parameters since <doValidRange> is
    a private function of the class <ColorClass>*/
    RangeJudgement = doVaildRange();
    return RangeJudgement;
}

/*Prints the component color values to the console using the
following format: "R: <red> G: <green> B: <blue>" where <red>,
<green>, and <blue> are all replaced with their corresponding
component color values.*/
void ColorClass::printComponentValues()
{
    cout << "R: " << redVal << " G: "
         << greenVal << " B: " << blueVal;
}



//Part 2: the class methods of the Class <RowColumnClass>

/*This default constructor <RowColumnClass()> sets both the row
and column value of the newly created RowColumnClass object to
-99999*/
RowColumnClass::RowColumnClass()
{
    rowVal = DEFAULT_ROW_ROL_VALUE;
    colVal = DEFAULT_ROW_ROL_VALUE;
}

/*This value constructor <RowColumnClass(int inRow, int inCol)>
sets the row and column values to the corresponding values passed
into the constructor.*/
RowColumnClass::RowColumnClass(int inRow, int inCol)
{
    rowVal = inRow;
    colVal = inCol;
}

/*This function <setRowCol(int inRow, int inCol)> is a “setter
function” that set the appropriate attributes <rowVal> and
<colVal> to the values provided.*/
void RowColumnClass::setRowCol(int inRow, int inCol)
{
    rowVal = inRow;
    colVal = inCol;
}

/*This function <setRow(int inRow)> is a “setter function” that
set the appropriate attributes <rowVal> to the values provided.*/
void RowColumnClass::setRow(int inRow)
{
    rowVal = inRow;
}

/*This function <setCol(int inCol)> is a “setter function” that
set the appropriate attributes <colVal> to the values provided.*/
void RowColumnClass::setCol(int inCol)
{
    colVal = inCol;
}

/*This function <getRow()> is a “getter functions” that return the
appropriate attribute value to the caller*/
int RowColumnClass::getRow()
{
    return rowVal;
}

/*This function <getCol()> is a “getter functions” that return the
appropriate attribute value to the caller*/
int RowColumnClass::getCol()
{
    return colVal;
}

/*This function <addRowColTo(RowColumnClass &inRowCol)> adds the row
and column index values in the input parameter to the row and column
index of the object the function is called on*/
//I corrected the output form--removing the << endl
void RowColumnClass::addRowColTo(RowColumnClass &inRowCol)
{
    rowVal += inRowCol.rowVal;
    colVal += inRowCol.colVal;
}

/*This function <printRowCol()> prints the contents of the
image to the screen.*/
void RowColumnClass::printRowCol()
{
    cout << "[" << rowVal << "," << colVal << "]";
}



//Part 3: the class methods of the Class <ColorImageClass>

/*This default constructor <ColorImageClass()> sets all
pixels in the image to full black.*/

//I corrected the magic numbers that existed in the for loop
ColorImageClass::ColorImageClass()
{
    for (int x = 0; x < MAX_ROW_NUM; x++)
    {
        for (int y = 0; y < MAX_COL_NUM; y++)
        {
            //colorAry[x][y] = ColorClass();
            colorAry[x][y].setToBlack();
        }
    }
}

/*This function <initializeTo(ColorClass &inColor)> initializes all image
pixels to the color provided via input*/

//I corrected the magic numbers that existed in the for loop
void ColorImageClass::initializeTo(ColorClass &inColor)
{
    for (int x = 0; x < MAX_ROW_NUM; x++)
    {
        for (int y = 0; y < MAX_COL_NUM; y++)
        {
            colorAry[x][y].setTo(inColor);
        }
    }
}

/*This function <addImageTo(ColorImageClass &rhsImg)> performs a pixel-wise
addition, such that each pixel in the image has the pixel in the corresponding
location in the right hand side input image added to it.*/

//I corrected the magic numbers that existed in the for loop
bool ColorImageClass::addImageTo(ColorImageClass &rhsImg)
{
    bool checkStatus = false;

    for (int x = 0; x < MAX_ROW_NUM; x++)
    {
        for (int y = 0; y < MAX_COL_NUM; y++)
        {
            if (colorAry[x][y].addColor(rhsImg.colorAry[x][y]))
            checkStatus = true;
        }
    }
    return checkStatus;
}

/*This function <addImages(int numImgsToAdd, ColorImageClass imagesToAdd[])>
causes the image's pixel values to be set to the sum of the corresponding
pixels in each image in the imagesToAdd input parameter*/
bool ColorImageClass::addImages(int numImgsToAdd,
                                ColorImageClass imagesToAdd [])
{
    bool checkStatus = false;
    ColorClass blackColor;
    blackColor.setToBlack();
    initializeTo(blackColor);

    for (int i = 0; i < numImgsToAdd; i++)
    {
        checkStatus = addImageTo(imagesToAdd[i]);
    }

    return checkStatus;
}

/*This function <setColorAtLocation(RowColumnClass &inRowCol, ColorClass
&inColor)>sets the pixel at the location specified by the “inRowCol”
parameter to the color specified via the “inColor” parameter.*/
bool ColorImageClass::setColorAtLocation(RowColumnClass &inRowCol,
                                         ColorClass &inColor)
{
    int rowNum;
    int colNum;

    rowNum = inRowCol.getRow();
    colNum = inRowCol.getCol();
    colorAry[rowNum][colNum].setTo(inColor);

    if (rowNum < MAX_ROW_NUM && rowNum >= MIN_ROW_COL_LIM)
    {
        if (colNum < MAX_COL_NUM && colNum >= MIN_ROW_COL_LIM)
        {
            colorAry[rowNum][colNum].setTo(inColor);
            return true;
        }
    }
    return false;
}

/*This function <getColorAtLocation(RowColumnClass &inRowCol, ColorClass
&outColor)> sets the appropriate attributes to the values of the provided
objects from two classes. If the row/column provided is a valid row/column
for the image, this function returns true and the output parameter "outColor"
is assigned to the color of the image pixel at that location.*/
bool ColorImageClass::getColorAtLocation(RowColumnClass &inRowCol,
                                         ColorClass &outColor)
{
    int rowNum;
    int colNum;

    rowNum = inRowCol.getRow();
    colNum = inRowCol.getCol();

    if (rowNum < MAX_ROW_NUM && rowNum >= MIN_ROW_COL_LIM)
    {
        if (colNum < MAX_COL_NUM && colNum >= MIN_ROW_COL_LIM)
        {
            outColor.setTo(colorAry[rowNum][colNum]);
            return true;
        }
    }
    return false;
}

/*This function <printImage()> prints the contents of the image to the screen*/
void ColorImageClass::printImage()
{
    for (int x = 0; x < MAX_ROW_NUM; x++)
    {
        for (int y = 0; y < MAX_COL_NUM; y++)
        {
            colorAry[x][y].printComponentValues();
            if ( y != LAST_ROW_NUM)
            cout << "--" ;
        }
        cout << endl;
    }
}