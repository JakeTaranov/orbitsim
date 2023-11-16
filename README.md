In an continued effort to learn C++ I created a program using SFML to simulate orbits of celestial bodies.

## Input

The program reads in a json file with the attributes of N bodies in the form of:

```json
{
  "bodies": [
    {
      "mass": 10000,
      "radius": 10,
      "pos_x": 600,
      "pos_y": 400,
      "vel_x": 0.5,
      "vel_y": 1.5,
      "drawline": true
    },
    {
      "mass": 10000,
      "radius": 10,
      "pos_x": 1000,
      "pos_y": 450,
      "vel_x": -0.5,
      "vel_y": -1.5,
      "drawline": true
    }
  ],
  "stay_in_bounds": true
}
```
Above is an example taken from ```stable_orbit.json``` 

<ul>
  <li> <strong> mass </strong>: mass of body n (int) </li>
  <li> <strong> radius </strong>: radius of body n (int) </li>
  <li> <strong> pos_x </strong>: initial x position of body n (int) </li>
  <li> <strong> pos_y </strong>: initial y position of body n (int)</li>
  <li> <strong> vel_x </strong>: initial x velocity of body n (int) </li>
  <li> <strong> vel_y </strong>: initial y velocity of body n (int) </li>
  <li> <strong> drawline </strong>: determines if the program will draw a trailing line of the body n's previous movement (bool) </li>
  <li> <strong> stay_in_bounds </strong>: determines wether all the bodies will stay in the screen bounds by boncing off the edges (bool)</li>
</ul>

## Examples


https://github.com/JakeTaranov/oribtsim/assets/48743548/d2bebb0d-5fa8-48c4-8a27-990027b54648



https://github.com/JakeTaranov/oribtsim/assets/48743548/2843d010-d044-4db5-bc4a-9183b39a1251






