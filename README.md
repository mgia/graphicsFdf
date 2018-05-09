# fdf: Creating a projection of a 3D map

![image](https://raw.githubusercontent.com/mgia/fdf/master/image.gif)
Screenshot of projection

## Line-drawing algorithm: DDA
The Digital Differential Analyzer (DDA) is a line-drawing technique that uses floating points to calculate pixel positions within a given window. While it is proven to be less efficient than Bresenham's algorithm in terms of cost and accuracy, DDA has proven effective to comprehend and and implement.

### How it works
DDA uses the absolute difference between the x-coordinate and y-coordinate of two points to draw a line. Based on the larger difference, steps are created and x and y are both incremented sequentially until the entire line is drawn.

### Limitations
Real arithmetic using floating point multiplication is relatively expensive to compute. Also, as the floating points are being explicitly cast to integers, rounding off reduces the accuracy of the line to a certain extent.
