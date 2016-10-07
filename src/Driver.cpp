#include "Shape.h"
#include "Rectangle.h"
#include "IsoTriangle.h"
#include "RightAngle.h"
#include "Rhombus.h"
#include "PlainCanvas.h"
#include "BorderedCanvas.h"
#include "TitledCanvas.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	PlainCanvas pCanvas(20, 10);
	pCanvas.clear('-');
	cout << pCanvas;
	cout << endl;

	BorderedCanvas bCanvas(20, 10);
	cout << bCanvas;
	cout << endl;

	TitledCanvas tCanvas(20, 10, "A titled canvas");
	tCanvas.clear('^');
	cout << tCanvas;
	cout << endl;

	RightAngle shp1 = RightAngle(6);
	shp1.draw(8, 2, pCanvas);
	cout << pCanvas;
	cout << endl;

	shp1.draw(9, 4, bCanvas);
	cout << bCanvas;
	cout << endl;

	shp1.draw(3, 0, tCanvas, 'O');
	cout << tCanvas;
	cout << endl;

	shp1.draw(16, 6, tCanvas);
	cout << tCanvas;
	cout << endl;

	tCanvas.clear();
	Rhombus rhom(9);
	rhom.draw(1, 1, tCanvas);
	IsoTriangle iso(1);
	iso.draw(10, 4, tCanvas, 'O');
	cout << tCanvas;
	cout << endl;

	for (int k = 0; k < 3; ++k)
	{
	tCanvas.clear();
	rhom.scale(-1);
	rhom.draw(1, 1, tCanvas);
	iso.scale(+1);
	iso.draw(10, 4, tCanvas, 'O');
	cout << tCanvas;
	cout << endl;
	}
	

	// draw a house front view on a 44-column and 50-row titles canvas
	TitledCanvas canvas(44, 50, "A Geometric House: Front View");

	Rectangle chimney(2, 14, "Chimeny on the roof"); // A vertical 14 x 2 chimney
	chimney.draw(4, 7, canvas, 'H'); // Draw chimney on canvas

	IsoTriangle roof(21, "House roof"); // A triangular roof of height 21
	roof.draw(1, 1, canvas, '/');// Draw roof

	Rectangle skylightFrame(9, 5, "Frame around skylight"); // A 9c x 5r skylight frame
	skylightFrame.draw(17, 11, canvas, 'H');// Draw skylight frame

	Rectangle skylight(7, 3, "skylight"); // A 7c x 3r skylight
	skylight.draw(18, 12, canvas, ' ');// Draw skylight

	Rectangle front(41, 22, "Front wall");// A 41c x 22r rectangular front wall
	front.draw(1, 23, canvas, ':'); // draw front wall

	Rectangle top_left_brackets(21, 1, "top Left Brackets "); // top left square brackets
	top_left_brackets.draw(1, 22, canvas, '['); // top left square brackets

	Rectangle bottom_left_brackets(21, 1, "Bottom Left Brackets "); // bottom left square brackets
	bottom_left_brackets.draw(1, 44, canvas, '['); // bottom left square brackets

	Rectangle top_right_brackets(20, 1, "top Right Brackets "); // top brackets right square brackets
	top_right_brackets.draw(22, 22, canvas, ']'); // Draw top brackets right square brackets

	Rectangle bottom_right_brackets(20, 1, "Bottom Right Brackets "); // a bottom right square brackets
	bottom_right_brackets.draw(22, 44, canvas, ']');// Draw bottom right square brackets

	Rectangle right_right_brackets(2, 22, "Right Right Brackets "); // right right square brackets
	right_right_brackets.draw(40, 23, canvas, ']');// Draw right right square brackets

	Rectangle lef_tleft_brackets(2, 22, "Left Left Brackets "); // left left square brackets
	lef_tleft_brackets.draw(1, 23, canvas, '[');// Draw left left square brackets

	Rectangle leftDoors(7, 10, "Front Left Door"); // A rectangle left door
	leftDoors.draw(22, 33, canvas, 'd');// Draw left door

	Rectangle rightDoors(7, 10, "Front Right Door"); // A rectangle right door
	rightDoors.draw(30, 33, canvas, 'b');// Draw right door

										 // visually split the two doors
	Rectangle doorsMiddle(1, 10, "Vertical center panel between front doors");
	doorsMiddle.draw(29, 33, canvas, '='); // draw the middle vertical rectangle

										   // Triagle windows above front door
	IsoTriangle Triagle_above_front_door(8, "Triagle Door Top"); // triagle above front door
	Triagle_above_front_door.draw(22, 24, canvas, '*');

	Rectangle doggyDoor = Rectangle(4, 2, "A rectangle  doggy door");//  A rectangle  doggy door 
	doggyDoor.draw(13, 41, canvas, 'D');// Draw doggy door

	Rhombus diamond_shape_window_on_front_wall(7, "Diamond shape window on front wall"); // A rhombus window on front wall
	diamond_shape_window_on_front_wall.draw(4, 25, canvas, 'O');// Draw rhombus window

	Rectangle StairSlash(40, 1, "Stair Slash"); // A row of 40 slashes
	StairSlash.draw(1, 45, canvas, '/'); // Draw row of 40 slashes
	StairSlash.draw(1, 46, canvas, '/'); // Draw row of 40 slashes
	StairSlash.draw(1, 47, canvas, '/'); // Draw row of 40 slashes
	StairSlash.draw(1, 48, canvas, '/'); // Draw row of 40 slashes

	RightAngle rightAngle(4, "RightAngle "); // right angle at bottom left of hous
	rightAngle.draw(3, 40, canvas, '\\');

	cout << canvas;
	cout << endl;
	cout << chimney << endl;
	cout << roof << endl;
	cout << skylightFrame << endl;
	cout << skylight << endl;
	cout << front << endl;
	cout << top_left_brackets << endl;
	cout << bottom_left_brackets << endl;
	cout << top_right_brackets << endl;
	cout << bottom_right_brackets << endl;
	cout << right_right_brackets << endl;
	system("pause");
	cout << lef_tleft_brackets << endl;
	cout << leftDoors << endl;
	cout << rightDoors << endl;
	cout << doorsMiddle << endl;
	cout << Triagle_above_front_door << endl;
	cout << doggyDoor << endl;
	cout << diamond_shape_window_on_front_wall << endl;
	cout << StairSlash << endl;
	cout << rightAngle << endl;

	return 0;
}