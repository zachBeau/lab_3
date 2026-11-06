#include <iostream>
#include <string>

using namespace std;

/**
 * Create the Vector2D Class (Character's Position)
 * Define a class Vector2D to represent a 2D vector with x and y components.
 * The class should have the following private attributes:
 * x (double): The x-coordinate of the vector.
 * y (double): The y-coordinate of the vector.
 * Implement a constructor to initialize these attributes.
 */
class Vector2D
{
    double x;
    double y;

public:
    Vector2D();
    Vector2D(double, double); 
    ~Vector2D();
    Vector2D operator+(const Vector2D&);
    Vector2D operator-(const Vector2D&);
    Vector2D operator*(double);
    bool operator==(const Vector2D&); 
    bool operator!=(const Vector2D&);
    void print();
    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);
};

//default constructor
Vector2D::Vector2D() {
    x = 0;
    y = 0;  
}
//overloaded constructor
Vector2D::Vector2D(double x, double y) {
    this->x = x;
    this->y = y; 
}
//destructor
Vector2D::~Vector2D() {
}

/**
* Overload the + Operator (Movement)
* Overload the + operator to add two vectors.
* This represents moving the character by combining the current position with a movement vector.
*/
Vector2D Vector2D::operator+(const Vector2D& right) {
    Vector2D temp;
    temp.x = this->x + right.x;
    temp.y = this->y + right.y;
    return temp;
}

/**
* Overload the - Operator (Undo Movement)
* Overload the - operator to subtract one vector from another.
* This represents undoing a movement, returning the character to a previous position.
*/
Vector2D Vector2D::operator-(const Vector2D& right){
    return Vector2D(this->x - right.x, this->y - right.y);
}

/**
* Overload the * Operator (Scaling Movement)
* Overload the * operator to scale a vector by a scalar (a double).
* This represents moving the character faster or slower by scaling the movement vector.
*/
Vector2D Vector2D::operator*(double fast) {
    return Vector2D(this->x * fast, this->y * fast);
}

/**
* Overload the == Operator (Position Comparison)
* Overload the == operator to compare two vectors.
* This represents checking if the character has reached a specific position on the map
*/
bool Vector2D::operator==(const Vector2D& right) {
    return (this->x == right.x && this->y == right.y);
}

bool Vector2D::operator!=(const Vector2D& right) {
    return (this->x != right.x || this->y != right.y); 
}

void Vector2D::print() {
    cout << "position: (" << this->x << ", " << this->y << ")" << endl; 
}

double Vector2D::getX() const {
    return x;
}

double Vector2D::getY() const {
    return y;
}
void Vector2D::setX(double x) {
    this->x = x;
}
void Vector2D::setY(double y) {
    this->y = y;
}

int main()
{
    /**
     * Create Vector2D Objects (Initial Position and Movements)
     * Create a "position" Vector2D object to represent the character's initial position at 0,0 on the map.
     * Create a "moveUp" (0,1) and "moveRight" (1,0) Vector2D object to represent different movement vectors.
    */

    Vector2D pos;
    Vector2D moveUp(0, 1);
    Vector2D moveRight(1, 0);

    /**
     * Simulate Movements (Navigating the Map)
     * Use the overloaded + operator to move the character on the map by adding movement vectors to the current position.
     * Print the character's new position after each move.
    */

    cout << "Simulate Movements:\nStarting ";
    pos.print();
    cout << "Move up\n";
    pos = pos + moveUp;
    pos.print();
    cout << "Move right\n";
    pos = pos + moveRight;
    pos.print();
    cout << "Move up 1 and right 2\n";
    pos = pos + moveUp + moveRight + moveRight;
    pos.print(); 

    /**
     * Undo Movements (Retracing Steps)
     * Use the overloaded - operator to undo movements, returning the character to a previous position.
     * Print the character's position after undoing a move.
     */
    cout << "Undo movements:\nMove back\n";
    pos = pos - moveUp;
    pos.print();
    cout << "Move left\n";
    pos = pos - moveRight;
    pos.print(); 

    /**
     * Scaling Movements (Fast Travel)
     * Use the overloaded * operator to scale a movement vector, simulating faster or slower movement.
     * Print the character's new position after scaling a move
     */
    cout << "Scaling movements:\nFast travel moveRight * 3 \n";
    pos = (pos + moveRight * 3); 
    pos.print();
    cout << "Fast travel moveUp * 3\n";
    pos = pos + (moveUp * 3); 
    pos.print(); 

    /**
     * Position Comparison (Reaching the Destination)
     * Use the overloaded == operator to check if the character has reached a specific position on the map.
     * Print a message to indicate whether the character has reached the "destination".
     */
    Vector2D comPos(5, 4);
    cout << "Position Comparison: " << endl;
    if (pos == comPos) {
        cout << "Reached the destination!";
    } else {
        cout << "Goal not reached.";
    }

}
