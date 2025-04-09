#include "emp/web/Animate.hpp"
#include "emp/web/web.hpp"

emp::web::Document doc{"target"};

class NFAnimator : public emp::web::Animate
{
    // My code goes here
    emp::web::Canvas canvas{500, 500, "canvas"}; //{width, heigh, HTML id}

    // Definte a constructor for the class and have the canvas placed in the doc:
public:
    NFAnimator()
    {
        doc << canvas;
        // We use << to send things to standard output. To add things to the website, use this syntax
        doc << "Goodmorning";
        // Drawing a gid:
        for (int x = 0; x < 10; x++)
        {
            for (int y = 0; y < 10; y++)
            {
                int z = 50; // z = size of squares
                // Drawing a rectangle:
                canvas.Rect(z * x, z * y, z, z, "white", "Black");
            }
        }

        FindNeighbors(5, 5); // Find neighbors of the first square
    }

    void FindNeighbors(int x, int y)
    {
        int z = 50;
        canvas.Rect(x, y, z, z, "black", "black");

        // Calculate neighbors and set them to red
        canvas.Rect(x + 1, y, z, z, "red", "black"); // right
        canvas.Rect(x - 1, y, z, z, "red", "black"); // left
        canvas.Rect(x, y + 1, z, z, "red", "black"); // up
        canvas.Rect(x, y - 1, z, z, "red", "black"); // down
    }
};

NFAnimator animator;

int main()
{
    animator.Step();
}